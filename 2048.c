
#include<stdio.h>
#include<stdlib.h>
#include "conio.h"
#include "Windows.h"


int a[4][4] = { { 0,0,0,0 },{ 0,0,0,0 } ,{ 0,0,0,0 } ,{ 0,0.0,0 } };
int p1, p2, r1, r2, x1, x2, i, j, n, m;
char q;
void main() {
	/*��ӡ��Ϸ����*/
	void print();
	void judge();
	void rands();
	print();
	system("pause");
	/*ȡ2���ֵ���ȷ���λ��*/
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
	/*ȡ2���ֵ���ȷ���λ��*/
	print();
	while (1) {
		q = getch();
		/*sΪ�����ƶ���wΪ���ϣ�aΪ����dΪ���ң��ƶ�˼·����*/
		if (q == 's')
		{
			m = 1;
			/*iΪ��*/
			for (i = 0; i < 4; i++)
			{
				/*jΪ��*/
				for (j = 3; j >(-1); j--)
				{
					/*��n������a[j][i]��ͬ�еĲ�ͬ�е����ֱȽϣ���ͬ��ǰһ�е���Ϊ0�������ǰ�Ƚ���ȥ������Ϊ�����ж��Ƿ���ȣ�����������������nѭ�����������ֱ������nѭ�� */
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
						/*��a[j][i]Ϊ0������Ѱ�Ҳ�Ϊ������ҵ��������ƶ�����ʱm=0��Ҳ������2�����������ȷλ��*/
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
			/*������ȫΪ��0��������ͬ�����Լ�ʱ����Ӻ���Ȼ��Ϊ2����������ڳ�λ�ã���rand����ǰ�����һ��print����*/
			print();
			/*��m�ж��Ƿ�Ӧ������ȷ�����λ�ò���һ��2,�����������ж�����judge�����ж���Ϸ��Ӯ*/
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
							//�ж��Ƿ����һ�������
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
							//�ж��Ƿ����һ�������
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
							//�ж��Ƿ����һ�������
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
				/*�ú����÷������ֱ�Ϊ��ɫ*/
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


/*���û����˲����������2�ĳ���*/
void rands() {
	srand((unsigned)time(NULL));
	/*�ҵ�һ����λ�ø�2*/
	do
	{
		x1 = rand() % 4;
		x2 = rand() % 4;
	} while (a[x1][x2] != 0);
	a[x1][x2] = 2;
}


void judge()
{
	/*iΪ��,jΪ��*/
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[j][i] == 2048)
			{
				printf("ͨ�أ�");
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
	printf("ʧ�ܣ�\n");
	system("pause");
}




