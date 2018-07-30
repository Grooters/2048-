
#include<stdio.h>
#include<stdlib.h>
#include "conio.h"
#include "Windows.h"


int a[4][4] = { { 0,0,0,0 },{ 0,0,0,0 } ,{ 0,0,0,0 } ,{ 0,0.0,0 } };
int p1, p2, r1, r2, x1, x2, i, j, n, m;
char q;
void main() {
	/*打印游戏界面*/
	void print();
	void judge();
	void rands();
	print();
	system("pause");
	/*取2出现的正确随机位置*/
	srand((unsigned)time(NULL));
	do
	{
		p1 = rand() % 4;
		p2 = rand() % 4;
		r1 = rand() % 4;
		r2 = rand() % 4;
	} while (p1 == r1&&p2 == r2&&a[p1][p2] == 0 && a[r1][r2] == 0);
	a[p1][p2] = 2;
	a[r1][r2] = 2;
	/*取2出现的正确随机位置*/
	print();
	while (1) {
		q = getch();
		/*s为向下移动，w为向上，a为向左，d为向右，移动思路类似*/
		if (q == 's')
		{
			m = 1;
			/*i为列*/
			for (i = 0; i < 4; i++)
			{
				/*j为行*/
				for (j = 3; j >(-1); j--)
				{
					/*用n来控制a[j][i]与同列的不同行的数字比较，若同列前一行的数为0则继续向前比较下去，若不为零则判断是否相等，若相等则相加再跳出n循环，不相等则直接跳出n循环 */
					for (n = 1; n < j + 1; n++)
					{
						if (a[j][i] != 0)
						{
							if (a[j - n][i] == a[j][i])
							{
								a[j][i] = a[j - n][i] + a[j][i];
								a[j - n][i] = 0;
								m = 0;
								break;
							}
							else if (a[j - n][i] != 0)
								break;
						}
						/*若a[j][i]为0则向上寻找不为零的数找到则向下移动，此时m=0即也是允许2随机出现在正确位置*/
						else if (a[j][i] == 0)
						{
							if (a[j - n][i] != 0)
							{
								a[j][i] = a[j - n][i];
								a[j - n][i] = 0;
								m = 0;
							}
						}
					}
				}
			}
			/*当数字全为非0数但有相同数可以加时在相加后仍然能为2的随机出现腾出位置，故rand函数前后各用一个print函数*/
			print();
			/*用m判断是否应该在正确的随机位置产生一个2,若不生成则判断利用judge函数判断游戏输赢*/
			if (m == 0)
				rands();
			else
				judge();
			print();
		}
		else if (q == 'w')
		{
			m = 1;
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j <4; j++)
				{
					for (n = 1; n <(4 - j); n++)
					{
						if (a[j][i] != 0)
						{
							if (a[j + n][i] == a[j][i])
							{
								a[j][i] = a[j + n][i] + a[j][i];
								a[j + n][i] = 0;
								m = 0;
								break;
							}
							else if (a[j + n][i] != 0)
								break;
							//判断是否产生一个随机数
						}
						else if (a[j][i] == 0)
						{
							if (a[j + n][i] != 0)
							{
								a[j][i] = a[j + n][i];
								a[j + n][i] = 0;
								m = 0;
							}
						}
					}
				}
			}
			print();
			if (m == 0)
				rands();
			else
				judge();
			print();
		}
		else if (q == 'a')
		{
			m = 1;
			for (j = 0; j < 4; j++)
			{
				for (i = 0; i <4; i++)
				{
					for (n = 1; n < 4 - i; n++)
					{
						if (a[j][i] != 0)
						{
							if (a[j][i + n] == a[j][i])
							{
								a[j][i] = a[j][i + n] + a[j][i];
								a[j][i + n] = 0;
								m = 0;
								break;
							}
							else if (a[j][i + n] != 0)
								break;
							//判断是否产生一个随机数
						}
						else if (a[j][i] == 0)
						{
							if (a[j][i + n] != 0)
							{
								a[j][i] = a[j][i + n];
								a[j][i + n] = 0;
								m = 0;
							}
						}
					}
				}
			}
			print();
			if (m == 0)
				rands();
			else
				judge();
			print();
		}
		else if (q == 'd')
		{
			m = 1;
			for (j = 0; j < 4; j++)
			{
				for (i = 3; i >(-1); i--)
				{
					for (n = 1; n < i + 1; n++)
					{
						if (a[j][i] != 0)
						{
							if (a[j][i - n] == a[j][i])
							{
								a[j][i] = a[j][i - n] + a[j][i];
								a[j][i - n] = 0;
								m = 0;
								break;
							}
							else if (a[j][i - n] != 0)
								break;
							//判断是否产生一个随机数
						}
						else if (a[j][i] == 0)
						{
							if (a[j][i - n] != 0)
							{
								a[j][i] = a[j][i - n];
								a[j][i - n] = 0;
								m = 0;
							}
						}
					}
				}
			}
			print();
			if (m == 0)
				rands();
			else
				judge();
			print();
		}
	}
	return 0;
}


void print() {
	system("cls");
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf("\n2048: Please input 'w' 's' 'a' 'd' to control the game\n\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] != 0)
			{
				/*该函数让非零数字变为红色*/
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
				printf("    %-8d\t", a[i][j]);
			}
			else
			{
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
				printf("    %-8d\t", a[i][j]);
			}
		}
		printf("\n\n");
	}
}


/*在用户按了操作键后控制2的出现*/
void rands() {
	srand((unsigned)time(NULL));
	/*找到一个空位置给2*/
	do
	{
		x1 = rand() % 4;
		x2 = rand() % 4;
	} while (a[x1][x2] != 0);
	a[x1][x2] = 2;
}


void judge()
{
	/*i为列,j为行*/
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[j][i] == 2048)
			{
				printf("通关！");
				system("pause");
			}
			else if (a[j][i] == 0)
				return;
		}
	}
	int m, n;
	for (m = 0; m<4; m++)
		for (n = 0; n < 3; n++) {
			if (a[m][n] == a[m][n + 1]||a[m][n]==a[m+1][n])
				return;
		}
	printf("失败！\n");
	system("pause");
}




