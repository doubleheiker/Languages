/**
 *输入稀疏矩阵，建立稀疏矩阵三元组顺序结构，实现转置（1、2）
 *转置1
 */
#include <stdio.h>
#define MAXSIZE 12500
typedef struct 
{
	int i, j;//该非零元的下标
	int e;
}Triple;//三元组类型
typedef	struct 
{
	Triple data[MAXSIZE+1]; //data[0]未使用
	int mu, nu, tu;         //矩阵的行数，列数，非零元个数
}TSMatrix;

void TransposeSMatrix(TSMatrix M, TSMatrix &T)
{
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu)
	{
		int q = 1;
		for (int col = 1; col <= M.nu; ++col)
		{
			for (int p = 1; p <= M.tu; ++p)
			{
				if (M.data[p].j == col)
				{
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].e = M.data[p].e;
					++q;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	TSMatrix M, T;
	M.mu = 3; M.nu = 3, M.tu = 3;//行数：3 列数：3 非零元个数：3
	//输入非零元信息
	for (int i = 1; i <= M.tu; ++i)
	{
		scanf("%d%d%d", &M.data[i].i, &M.data[i].j, &M.data[i].e);
	}
	TransposeSMatrix(M, T);//转置
	for (int i = 1; i <= T.tu; ++i)
	{
		printf("%d %d %d\n", T.data[i].i, T.data[i].j, T.data[i].e);
	}//输出转置结果
	return 0;
}