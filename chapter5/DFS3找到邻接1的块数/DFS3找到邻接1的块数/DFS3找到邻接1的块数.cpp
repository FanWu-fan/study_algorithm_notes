// DFS3找到邻接1的块数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;
int m, n;//矩阵的行列 y列- x行|

vector<vector<int>> matrix; //矩阵matrix
vector<vector<bool>> inq;//记录是否入队

vector<int> X{ 0,0,1,-1 };
vector<int> Y{ 1,-1,0,0 };

struct node
{
	int x, y;
}Node;

bool judge(int x, int y)
{
	if (x >= m || y >= n || x < 0 || y < 0) return false;
	if (inq[x][y] == true || matrix[x][y] == 0) return false;
	return true;
}


//递归的写法
void DFS(int x, int y)
{
	if (judge(x, y))
	{
		inq[x][y] = true;
		for (int i = 0; i < 4; i++)
			DFS(x + X[i], y + Y[i]);
	}
	return;
}

int main()
{
	cin >> m >> n;
	matrix.resize(m);
	inq.resize(m);
	for (int x = 0; x < m; x++)
	{
		matrix[x].resize(n);
		inq[x].resize(n);
	}

	for (int x = 0; x < m; x++)
		for (int y = 0; y < n; y++)
		{
			cin >> matrix[x][y];
			inq[x][y] = false;
		}

	for (int x = 0; x < m; x++)
	{
		for (int y = 0; y < n; y++)
		{
			cout << matrix[x][y] << " ";
		}
		cout << endl;
	}

	int ans = 0;
	for (int x = 0; x < m; x++)
		for (int y = 0; y < n; y++)
		{
			if (matrix[x][y] == 1 && inq[x][y] == false)
			{
				ans++;
				DFS(x, y);
			}
		}
	cout << ans << endl;

}

