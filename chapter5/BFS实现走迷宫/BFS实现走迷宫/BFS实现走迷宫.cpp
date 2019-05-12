// BFS实现走迷宫.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int m, n;//m行n列

vector<vector<char>> maze;


vector<int> X{ 0,0,-1,1 };
vector<int> Y{ 1,-1,0,0 };

struct node
{
	int x, y;
	int step;
	node *parent;
}S,T,Node;

//struct fnode
//{
//	bool ifin;
//	node parent;
//};
//vector<vector<fnode>> inq;//这个是判定是否入过队列或者堆栈
vector<vector<bool>> inq;

bool judge(int x, int y)
{
	if (x >= m || y >= n || x < 0 || y < 0) return false;
	if (maze[x][y] == '*' || inq[x][y] == true)return false;
	return true;
}


int BFS()
{
	queue<node> Q;
	Q.push(S);
	
	while (!Q.empty())
	{
		node top = Q.front();
		Q.pop();
		if (maze[top.x][top.y] == 'T')
		{
			T.parent = &top;
			return top.step;
		}
			

		for (int i = 0; i < 4; i++)
		{
			int newx = top.x + X[i];
			int newy = top.y + Y[i];
			if (judge(newx,newy))
			{
				Node.step = top.step+1;
				Node.y = newy;
				Node.x = newx;
				Node.parent = &top;
				Q.push(Node);
				inq[newx][newy] = true;
			}
		}
	}
	return -1;
}



int main()
{
	cin >> m >> n;
	maze.resize(m);
	inq.resize(m);

	for (int x=0; x < m; x++)
	{
		maze[x].resize(n);
		inq[x].resize(n, false);
	}

	for (int x = 0; x < m; x++)
		for (int y = 0; y < n; y++)
		{
			cin >> maze[x][y];
			if (maze[x][y] == 'S')
			{
				S.x = x;
				S.y = y;
				
			}
			if (maze[x][y] == 'T')
			{
				T.x = x;
				T.y = y;
			}
		}

	for (int x = 0; x < m; x++)
	{
		for (int y = 0; y < n; y++)
		{
			cout << maze[x][y] << " ";
		}
		cout << endl;
	}

	cout << "走的步伐：" << BFS()<<endl;

	node top = T;
	while (top.parent != &S)
	{
		cout << top.parent->x << " "<<top.parent->y << endl;
		top = *top.parent;
	}
}

