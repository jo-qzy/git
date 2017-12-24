#include "stdio.h"
#include "stdlib.h"
#include "windows.h"//����Sleep�����������������ٶ�
#include "conio.h"//����ʱ�õ���getch()����ȡ�����������ɸ��˻�ȡ��ʽû�õ����������Ƿ��Ű�
#include "time.h"//����ʳ��ʱ������������õ�time������

typedef struct SNAKE//�������꼰βָ�룬Ϊʲô��typedef��Ϊ����ֱ��snake����ָ�룬����
{
	int x;
	int y;
	struct SNAKE *next;
}snake;//typedef���÷�http://blog.csdn.net/wangqiulin123456/article/details/8284939

void POS();//�ƶ���꺯��
void StayAwayFromWall();//�ж�ײǽ����
void DonnotBiteYouself();//�ж�ҧ���Լ��ĺ���
void drawmap();//����ͼ����
void initsnake();//��ʼ���ߺ���
void createfood();//����ʳ�ﺯ��
void gamecircle();//��Ϸ�ƶ�ѭ������
void move();//�ƶ�����
void pause();//��ͣ����
void welcome();//��ӭ����
void game();//��Ϸ����

snake *head,*end;//������ͷ����β
snake *p;//�ƶ�ʱ�õ��ı����ߵ�ָ��
int i,speed=300;//ѭ������i���ٶ�
int levelup,score=0;//�ﵽһ��������졢����
int foodx,foody;//ʳ��ģ�x��y������
char key;//���尴����ȡ

int main()
{
    welcome();
	game();
	getch();
    return 0;
}

void POS(int x,int y)//���ù��λ�ã��ο���ַhttps://baike.so.com/doc/1283395-1357065.html
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
		printf("��Ϸ������ײǽ��\n");
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
		    printf("��Ϸ������ҧ���Լ���\n");
			POS(28,15);
		    system("pause");
		    exit(0);
		}
	}
}

void drawmap()//������
{
	for(i=0;i<60;i+=2)//��ӡ���±߿�
    {
        POS(i,0);
        printf("��");
        POS(i,28);
        printf("��");
    }
    for(i=1;i<28;i++)//��ӡ���ұ߿�
    {
        POS(0,i);
        printf("��"); 
        POS(58,i);
        printf("��"); 
    }
}

void initsnake()//��ʼ������	
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
		printf("��");
		end=end->next;
	}
}

void createfood()
{
	srand(time(0));//���randʹ��
	flag:
	while(1)//����food��x�������Ϊż������������ѭ���ж��Ƿ�Ϊż��
	{
		foody=rand()%27+1;//������y���꣬����������x��x���жϣ�������x���˳�while������y
		foodx=rand()%55+2;//rand������Χ����ʽrand()%(m-n+1)+n��������n<=Ҫ�������ķ�Χ<=m
		if (foodx%2==0)
	    {
		    break;
	    }
	}
	p=head;
	while(1)
	{
		if(p->x==foodx&&p->y==foody)//��������������ص��ˣ��ص���������ѭ��
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
	printf("��");
}

void gamecircle()//��Ϸѭ���������ƶ�����ͣ����
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
		if (score==levelup&&speed>=10)//�жϳɼ���ÿ�ۻ�30���ٶȱ��
		{
			speed-=10;
			levelup+=30;
			POS(75,12);
			printf("��ǰ�ٶȣ�ÿ��%d�����ƶ���ǰ�ƶ�",speed);
		}
		move();
	}
}

void move()//�ƶ��������������Ҽ�ͷ������wǰs��a��d�ң�����˵����������������ʳ��Ʒֹ���
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
	    printf("��");
	    head=p;
	    Sleep(speed);
		if (p->x==foodx&&p->y==foody)
		{
			createfood();
			score+=10;
			POS(75,11);
			printf("�÷֣�%d",score);
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
	    printf("��");
	    head=p;
	    Sleep(speed);
		if (p->x==foodx&&p->y==foody)
		{
			createfood();
			score+=10;
			POS(75,11);
			printf("�÷֣�%d",score);
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
	    printf("��");
		head=p;
		Sleep(speed);
		if (p->x==foodx&&p->y==foody)
		{
			createfood();
			score+=10;
			POS(75,11);
			printf("�÷֣�%d",score);
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
	    printf("��");
		head=p;
		Sleep(speed);
		if (p->x==foodx&&p->y==foody)
		{
			createfood();
			score+=10;
			POS(75,11);
			printf("�÷֣�%d",score);
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

void pause()//��ͣ����,bug:��֮ͣ�������߶�һ�񡣡���������ָ�������������
{
	do//�������ӵ���䣬�������˵��bug����֪����ͣ�������˻᲻������������������ǽ���˵�
	{
		p=p->next;
	}while(p->next!=NULL);
	POS(p->x,p->y);
	printf("��");
	while(1)//��ͣ���
	{
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}
	}//������system("pause");����ְ��������������
	POS(p->x,p->y);
    printf(" ");
}

void welcome()
{
	POS(28,10);
	printf("��ӭ����̰����");
	POS(28,11);
	printf("��Ϸ����");
	POS(28,12);
	printf("1������ײǽ");
	POS(28,13);
	printf("2������ײ�Լ�");
	POS(28,14);
	printf("3���ո������ͣ���ٴΰ��¼�����Ϸ");
	POS(28,15);
	printf("4��Ҫ��Ŀ���");
	POS(28,16);
	printf("5���𰴿ո�ʼ��Ϸ�������㰴��ļ������Լ��������Ǳ𰴿ո�");
	POS(28,17);
	printf("���ߣ�������");
	POS(28,18);
	printf("������Ϊʲô��c�������ϵ�̰������ô��");
	POS(28,19);
	printf("��Ϊ�ṹ��͵�ͼ���������ʹ�ö��ǲ���������");
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
	printf("�÷֣�%d",score);
	POS(75,12);
	printf("��ǰ�ƶ��ٶȣ�ÿ��%d�����ƶ���ǰ�ƶ�",speed);
	POS(75,13);
	printf("ÿ���30���ٶȻ�ӿ�");
	POS(75,14);
	printf("����ײǽ����ײ�Լ�");
	POS(75,15);
	printf("���ո������ͣ����");
	gamecircle();
}