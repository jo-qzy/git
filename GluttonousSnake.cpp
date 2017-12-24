#include "stdio.h"
#include "stdlib.h"
#include "windows.h"//包含Sleep函数，来控制运行速度
#include "conio.h"//测试时用到了getch()来获取按键，最后完成改了获取方式没用到，不过还是放着吧
#include "time.h"//设置食物时随机生成坐标用到time做种子

typedef struct SNAKE//包含坐标及尾指针，为什么用typedef因为可以直接snake定义指针，方便
{
	int x;
	int y;
	struct SNAKE *next;
}snake;//typedef的用法http://blog.csdn.net/wangqiulin123456/article/details/8284939

void POS();//移动光标函数
void StayAwayFromWall();//判断撞墙函数
void DonnotBiteYouself();//判断咬到自己的函数
void drawmap();//画地图函数
void initsnake();//初始化蛇函数
void createfood();//创建食物函数
void gamecircle();//游戏移动循环函数
void move();//移动函数
void pause();//暂停函数
void welcome();//欢迎界面
void game();//游戏界面

snake *head,*end;//定义蛇头、蛇尾
snake *p;//移动时用到的遍历蛇的指针
int i,speed=300;//循环变量i、速度
int levelup,score=0;//达到一定分数变快、分数
int foodx,foody;//食物的（x，y）坐标
char key;//定义按键获取

int main()
{
    welcome();
	game();
	getch();
    return 0;
}

void POS(int x,int y)//设置光标位置，参考网址https://baike.so.com/doc/1283395-1357065.html
{
	COORD pos;
	HANDLE output;
    pos.X=x;
    pos.Y=y;
    output=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output,pos);
}

void StayAwayFromWall()
{
	if (head->x==0||head->x==58||head->y==0||head->y==29)
	{
		POS(28,14);
		printf("游戏结束你撞墙了\n");
		POS(28,15);
		system("pause");
		exit(0);
	}
}

void DonnotBiteYouself()
{
	while(p->next!=NULL)
	{
		p=p->next;
		if (head->x==p->x&&head->y==p->y)
		{
			POS(28,14);
		    printf("游戏结束你咬到自己了\n");
			POS(28,15);
		    system("pause");
		    exit(0);
		}
	}
}

void drawmap()//画棋盘
{
	for(i=0;i<60;i+=2)//打印上下边框
    {
        POS(i,0);
        printf("■");
        POS(i,28);
        printf("■");
    }
    for(i=1;i<28;i++)//打印左右边框
    {
        POS(0,i);
        printf("■"); 
        POS(58,i);
        printf("■"); 
    }
}

void initsnake()//初始化蛇身	
{
	end=(snake*)malloc(sizeof(snake));
	end->x=28;
	end->y=14;
	end->next=NULL;
	for (i=1;i<=3;i++)
	{
		head=(snake*)malloc(sizeof(snake));
		head->next=end;
		head->x=28+2*i;
		head->y=15;
		end=head;
	}
	while (end->next!=NULL)
	{
		POS(end->x,end->y);
		printf("■");
		end=end->next;
	}
}

void createfood()
{
	srand(time(0));//配合rand使用
	flag:
	while(1)//由于food的x坐标必须为偶数，所以设置循环判断是否为偶数
	{
		foody=rand()%27+1;//先生成y坐标，不能先生成x，x有判断，先生成x会退出while不生成y
		foodx=rand()%55+2;//rand产生范围数公式rand()%(m-n+1)+n……其中n<=要生成数的范围<=m
		if (foodx%2==0)
	    {
		    break;
	    }
	}
	p=head;
	while(1)
	{
		if(p->x==foodx&&p->y==foody)//若生成坐标和蛇重叠了，回到生成坐标循环
		{
			goto flag;
		}
		if(p->next==NULL)
		{
			break;
		}
		p=p->next;
	}
	POS(foodx,foody);
	printf("■");
}

void gamecircle()//游戏循环，包含移动，暂停功能
{
	key='d';
	while (1)
	{	
		if (GetAsyncKeyState(VK_UP)&&key!='s')
		{
			key='w';
		}
		else if (GetAsyncKeyState(VK_DOWN)&&key!='w')
		{
			key='s';
		}
		else if (GetAsyncKeyState(VK_RIGHT)&&key!='a')
		{
			key='d';
		}
		else if (GetAsyncKeyState(VK_LEFT)&&key!='d')
		{
			key='a';
		}
		else if (GetAsyncKeyState(VK_SPACE))
		{
			pause();
		}
		if (score==levelup&&speed>=10)//判断成绩，每累积30分速度变快
		{
			speed-=10;
			levelup+=30;
			POS(75,12);
			printf("当前速度：每隔%d毫秒移动向前移动",speed);
		}
		move();
	}
}

void move()//移动函数，上下左右箭头操作，w前s后a左d右（符号说明），函数包含吃食物计分功能
{
	StayAwayFromWall();
	DonnotBiteYouself();
	p=(snake*)malloc(sizeof(snake));
	switch(key)
	{
	case 'd':
	{
		p->next=head;
	    p->x=head->x+2;
	    p->y=head->y;
	    POS(p->x,p->y);
	    printf("■");
	    head=p;
	    Sleep(speed);
		if (p->x==foodx&&p->y==foody)
		{
			createfood();
			score+=10;
			POS(75,11);
			printf("得分：%d",score);
			break;
		}
		while(p->next->next!=NULL)
	    {
		    p=p->next;
		    if(p->next->next==NULL)
		    {
			    POS(p->x,p->y);
			    printf(" ");
			    free(p->next);
			    p->next=NULL;
			    p=head;
			    break;
		    }
	    }
	    break;
	}
	case 'w':
	{
	    p->next=head;
	    p->x=head->x;
	    p->y=head->y-1;
	    POS(p->x,p->y);
	    printf("■");
	    head=p;
	    Sleep(speed);
		if (p->x==foodx&&p->y==foody)
		{
			createfood();
			score+=10;
			POS(75,11);
			printf("得分：%d",score);
			break;
		}
		while(p->next->next!=NULL)
	    {
		    p=p->next;
		    if(p->next->next==NULL)
		    {
			    POS(p->x,p->y);
			    printf(" ");
			    free(p->next);
			    p->next=NULL;
			    p=head;
			    break;
		    }
	    }
		break;
	}
	case 's':
	{
	    p->next=head;
        p->x=head->x;
		p->y=head->y+1;
        POS(p->x,p->y);
	    printf("■");
		head=p;
		Sleep(speed);
		if (p->x==foodx&&p->y==foody)
		{
			createfood();
			score+=10;
			POS(75,11);
			printf("得分：%d",score);
			break;
		}
		while(p->next->next!=NULL)
	    {
		    p=p->next;
		    if(p->next->next==NULL)
		    {
			    POS(p->x,p->y);
			    printf(" ");
			    free(p->next);
			    p->next=NULL;
			    p=head;
			    break;
		    }
	    }
		break;
	}
	case 'a':
	{
		p->next=head;
		p->x=head->x-2;
		p->y=head->y;
		POS(p->x,p->y);
	    printf("■");
		head=p;
		Sleep(speed);
		if (p->x==foodx&&p->y==foody)
		{
			createfood();
			score+=10;
			POS(75,11);
			printf("得分：%d",score);
			break;
		}
		while(p->next->next!=NULL)
	    {
		    p=p->next;
		    if(p->next->next==NULL)
		    {
			    POS(p->x,p->y);
			    printf(" ");
			    free(p->next);
			    p->next=NULL;
			    p=head;
			    break;
		    }
	    }
	    break;
	}
	}
}

void pause()//暂停函数,bug:暂停之后会出现蛇短一格。。继续蛇身恢复正常，不会解决
{
	do//额外增加的语句，解决上面说的bug，不知道暂停次数多了会不会崩溃，表面上问题是解决了的
	{
		p=p->next;
	}while(p->next!=NULL);
	POS(p->x,p->y);
	printf("■");
	while(1)//暂停语句
	{
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}
	}//不能用system("pause");会出现按任意键继续字样
	POS(p->x,p->y);
    printf(" ");
}

void welcome()
{
	POS(28,10);
	printf("欢迎来到贪吃蛇");
	POS(28,11);
	printf("游戏规则：");
	POS(28,12);
	printf("1、不能撞墙");
	POS(28,13);
	printf("2、不能撞自己");
	POS(28,14);
	printf("3、空格可以暂停，再次按下继续游戏");
	POS(28,15);
	printf("4、要玩的开心");
	POS(28,16);
	printf("5、别按空格开始游戏！！！你按别的键都可以继续，就是别按空格");
	POS(28,17);
	printf("作者：屈振宇");
	POS(28,18);
	printf("别问我为什么和c语言网上的贪吃蛇那么像");
	POS(28,19);
	printf("因为结构体和地图包括坐标的使用都是参照他做的");
	POS(28,20);
	system("pause");
	system("cls");
}

void game()
{
	drawmap();
	initsnake();
	createfood();
	POS(75,11);
	printf("得分：%d",score);
	POS(75,12);
	printf("当前移动速度：每隔%d毫秒移动向前移动",speed);
	POS(75,13);
	printf("每获得30分速度会加快");
	POS(75,14);
	printf("不能撞墙不能撞自己");
	POS(75,15);
	printf("按空格可以暂停……");
	gamecircle();
}