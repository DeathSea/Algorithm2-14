/*
Gary ����һ������Ϊ2^n������
����������ͬԪ�أ�ÿ��Ԫ�ض��ǳ���Ϊnλ�Ĵ�������Ԫ��ǡ��ֻ��һλ��ͬ��
�÷��η��������һ���㷨������n������Ӧ��Gray��
*/
#include <iostream>
char re[100][20];
int log2(int num)
{
	int r = 0;
	while (num != 1)
	{
		num = num >> 1;
		r++;
	}
	return r;
}
void bin(int length,int n)
{
	if (n == 2)
	{
		//�����ǰ������
		re[0][length - 1] = '0';
		re[1][length - 1] = '1';
	}
	else
	{
		//����Ļ�
		//���λǰ�벿Ϊ0��벿Ϊ1
		//����λ��n/2λ�����ᣬ����ǰn/2
		//ע���������λ�Ķ���
		for (int i = 0; i < n / 2; i++)
		{
			re[i][length - log2(n)] = '0';
		}
		for (int j = n / 2; j < n; j++)
		{
			re[j][length - log2(n)] = '1';
		}
		bin(length, n / 2);//����ǰn/2
		//����ǰn/2
		//�����ѹ���������乹��
		for (int i = n/2; i < n; i++)
		{
			for (int j = length - 1; j>length - log2(n); j--)
			{
				re[i][j] = re[n - 1 - i][j];
			}
		}

	}
}
int main()
{
	int n = 4;
	int p = pow(2.0, n);
	bin(n,p);
	//�����
	for (int i = 0; i < p; i++)
	{
		std::cout << re[i] << std::endl;
	}
	return 0;
}