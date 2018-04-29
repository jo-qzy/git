#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

enum State
{
	NORMAL,
	FOUND_SLASH,
	C_COMMENT,
	CPP_COMMENT,
	FOUND_ASTERTISK
};

void CommentConvert(FILE* pIn, FILE* pOut)
{
	enum State state = NORMAL;
	while (1)
	{
		char ch = getc(pIn);
		if (ch == EOF)
		{
			break;
		}
		switch (state)
		{
		case NORMAL:
			if (ch == '/')
			{
				state = FOUND_SLASH;
			}
			else
			{
				fputc(ch, pOut);
				state = NORMAL;
			}
			break;
		case FOUND_SLASH:
			if (ch == '*')
			{
				fprintf(pOut, "//");
				state = C_COMMENT;
			}
			else if (ch == '/')
			{
				fprintf(pOut, "//");
				state = CPP_COMMENT;
			}
			else
			{
				fprintf(pOut, "/%c", ch);
				state = NORMAL;
			}
			break;
		case C_COMMENT:
			if (ch == '*')
			{
				state = FOUND_ASTERTISK;
			}
			else
			{
				if (ch == '\n')
				{
					fprintf(pOut, "\n//");
				}
				else
				{
					fputc(ch, pOut);
				}
				state = C_COMMENT;
			}
			break;
		case CPP_COMMENT:
			fputc(ch, pOut);
			if (ch == '\n')
			{
				state = NORMAL;
			}
			break;
		case FOUND_ASTERTISK:
			if (ch == '/')
			{
				char nextch = fgetc(pIn);
				if (nextch != '\n')
				{
					fputc('\n', pOut);
				}
				ungetc(nextch, pIn);
				state = NORMAL;
			}
			else if (ch == '*')
			{
				fputc('*', pOut);
				state = FOUND_ASTERTISK;
			}
			else
			{
				fputc('*', pOut);
				fputc(ch, pOut);
				state = C_COMMENT;
			}
			break;
		}
	}
}

int main()
{
	const char* INPUT = "input.c";
	const char* OUTPUT = "output.c";
	FILE* pIn = fopen(INPUT, "r");
	FILE* pOut = fopen(OUTPUT, "w");
	CommentConvert(pIn, pOut);
	fclose(pOut);//后打开的先关
	fclose(pIn);
}