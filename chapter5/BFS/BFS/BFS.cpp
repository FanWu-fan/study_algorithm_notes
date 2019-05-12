#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int m, n;//矩阵的行列 y列- x行|
//vector<vector<int>> matrix(m, vector<int>(n)); //矩阵matrix
//vector<vector<bool>> inq(m, vector<bool>(n, false));//记录是否入队

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

void BFS(int x, int y)
{
	queue<node> Q;
	Node.x = x;
	Node.y = y;
	Q.push(Node);
	inq[x][y] = true;
	while (!Q.empty())
	{
		node top = Q.front();
		Q.pop();
		for(int i =0;i<4;i++)
		{
			int newx = top.x + X[i];
			int newy = top.y + Y[i];
			if (judge(newx, newy))
			{
				Node.x = newx;
				Node.y = newy;
				Q.push(Node);
				inq[newx][newy] = true;
			}
		}
	}

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

	for(int x=0;x<m;x++)
		for (int y=0;y<n;y++)
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
				BFS(x, y);
			}
		}
	cout << ans << endl;

}