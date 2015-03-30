/*
Gary 码是一个长度为2^n的序列
序列中无相同元素，每个元素都是长度为n位的串，相邻元素恰好只有一位不同，
用分治法策略设计一个算法对任意n构造相应的Gray码
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
		//如果最前面两个
		re[0][length - 1] = '0';
		re[1][length - 1] = '1';
	}
	else
	{
		//否则的话
		//最高位前半部为0后半部为1
		//其他位以n/2位反射轴，反射前n/2
		//注意这里最高位的定义
		for (int i = 0; i < n / 2; i++)
		{
			re[i][length - log2(n)] = '0';
		}
		for (int j = n / 2; j < n; j++)
		{
			re[j][length - log2(n)] = '1';
		}
		bin(length, n / 2);//生成前n/2
		//反射前n/2
		//利用已构造的来反射构造
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
	//输出：
	for (int i = 0; i < p; i++)
	{
		std::cout << re[i] << std::endl;
	}
	return 0;
}