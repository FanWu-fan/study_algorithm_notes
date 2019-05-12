# Chapter5 搜索专题

## 1.0 深度优先搜索(DFS)
DFS是一种枚举所有完整路径以遍历所有情况的一种搜索方式。
实际上使用的是 **栈**
```c++
#include "pch.h"
#include <iostream>
using namespace std;

const int maxn = 30;
int n, V, maxvalue = 0;//物品件数n，背包容量 V，最大价值 maxvalue
int w[maxn], c[maxn];//w[i]为每件物品的重量，c[i]为每件物品的价值

void DFS(int index, int sumW, int sumC)//index为当前处理物品的编号
{
	if (index == n)//已经完成对n件物品的选择（死胡同）
	{
		if (sumW <= V && sumC > maxvalue)
			maxvalue = sumC;//不超过背包容量时更新最大价值maxvalue
		return;
	}
	//岔路口
	DFS(index + 1, sumW, sumC);
	cout << "index :" << index << endl;//不选第index件物品
	DFS(index + 1, sumW + w[index], sumC + c[index]);//选择第index件物品
}

int main()
{
	cin >> n >> V;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	DFS(0, 0, 0);//初始时为第0件物品，当前总重量和总价值为0
	cout << maxvalue;
}

5 8
3 5 1 2 2
4 5 2 1 3
index :4
index :3
index :4
index :2
index :4
index :3
index :4
index :1
index :4
index :3
index :4
index :2
index :4
index :3
index :4
index :0
index :4
index :3
index :4
index :2
index :4
index :3
index :4
index :1
index :4
index :3
index :4
index :2
index :4
index :3
index :4
10
```
**减枝**，
```c++
void DFS(int index, int sumW, int sumC)//index为当前处理物品的编号
{
	//if (index == n)//已经完成对n件物品的选择（死胡同）
	//{
	//	if (sumW <= V && sumC > maxvalue)
	//		maxvalue = sumC;//不超过背包容量时更新最大价值maxvalue
	//	return;
	//}
	////岔路口
	//DFS(index + 1, sumW, sumC);
	//cout << "index :" << index << endl;//不选第index件物品
	//DFS(index + 1, sumW + w[index], sumC + c[index]);//选择第index件物品
	if (index == n)
		return;
	DFS(index + 1, sumW, sumC);
	if (sumW + w[index] <= V)
	{
		if (sumC + c[index] > maxvalue)
			maxvalue = sumC + c[index];
		DFS(index + 1, sumW + w[index], sumC + c[index]);
	}
}
```
```C++
#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

const int maxn = 50;
//从一个序列中选出k个数，使得这k个数之和等于X，且平方和最大
//序列A中n个数选k个数，使得平方和为x,最大平方和为 maxSumSqu
int n, k, x, maxSumSqu = -1, A[maxn];
vector<int> temp, ans;

//当前处理的 index号整数,当已选整数个数为nowK
//当前已选整数之和为 sum,当前已选整数平方和为 sumSqu
void DFS(int index, int nowk, int sum, int sumSqu)
{
	if (nowk == k && sum == x)
	{
		if (sumSqu > maxSumSqu)
			maxSumSqu = sumSqu;//更新最大平方和
		ans = temp;//更新解决方案
		return;
	}
	if (index == n || nowk > k || sum > x)
		return;

	DFS(index + 1, nowk, sum, sumSqu);

	temp.push_back(A[index]);
	DFS(index, nowk + 1, sum + A[index], sumSqu + A[index] * A[index]);//由于数组从0开始，因此不加1
	temp.pop_back();
}

int main()
{
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	DFS(0, 0, 0, 0);
	cout << "SUM: " << maxSumSqu << endl;
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
	{
		cout << *it << endl;
	}
}
```


## 1.1 BFS
广度优先(Breath First Search,BFS)，采用 **队列**实现，
```
void BFS(int s)
{
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		取出队首元素 top;
		访问队首元素 top;
		将队首元素出队；
		将 top的下一层节点中未曾入队的节点全部入队，并设置为已入队。
	}
}
```

```C++
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
```
```c++
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
```
## 1.2 BFS和DFS
```c++
// 用递归实现DFS和BFS的找邻接1的块数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> matrix; //矩阵matrix
vector<vector<bool>> inq;//记录是否入队
int m, n;//矩阵的行列 y列- x行|
vector<int> X{ 0,0,1,-1 };
vector<int> Y{ 1,-1,0,0 };

bool judge(int x, int y)
{
	if (x >= m || y >= n || x < 0 || y < 0) return false;
	if (inq[x][y] == true || matrix[x][y] == 0) return false;
	return true;
}

struct node
{
	int x, y;
}Node;

void BFS(int x, int y)
{
	queue<node> Q;
	Node.x = x;
	Node.y = y;
	Q.push(Node);
	inq[Node.x][Node.y] = true;
	while (!Q.empty())
	{
		node top;
		top = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
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

void DFS(int x, int y)
{

	stack<node> S;
	Node.x = x;
	Node.y = y;
	S.push(Node);
	inq[Node.x][Node.y] = true;
	while (!S.empty())
	{
		node top;
		top = S.top();
		S.pop();
		for (int i = 0; i < 4; i++)
		{
			int newx = top.x + X[i];
			int newy = top.y + Y[i];
			if (judge(newx, newy))
			{
				Node.x = newx;
				Node.y = newy;
				S.push(Node);
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
```
## 1.3 BSF走迷宫

```C++
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
```

## 1.4 要点
在BFS中，设置inq数组的含义是判断节点 **是否已入队**，而不是 节点是否已被访问，区别在于：如果设置成是否被访问，有可能在某个节点正在队列中(但还未被访问)时，由于其他节点可以到达它而将这个节点再次入队，导致很多节点反复入队，计算量大大增加，因此 BFS中只让每个节点只入队一次，故需要设置 inq数组的含义为 **节点是否已入队**，而非 **节点是否已经被访问**。
最后指出，当使用 STL 的queue时，元素入队的 push操作只是制造了该元素的一个 **副本**入队，因此在 入队后对原元素的修改不会影响队列中的 **副本**，而对队列中的副本的修改也 **不会改变** 原元素。需要注意由此可能引入的bug(一般由结构体产生)。例如下面：

```C++
// 队列入队生成原元素副本的bug.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node
{
	int data;
};

vector<node> a(10);


int main()
{
	queue<node> q;
	for (int i = 0; i <= 3; i++)
	{
		a[i].data = i;
		q.push(a[i]);
	}

	//尝试直接把队首元素(即a[1])的数据域改为100
	q.front().data = 100;
	//事实上对队列元素的修改无法改变原元素
	cout << a[1].data << " " << a[2].data << " " << a[3].data << endl;
	//然后尝试直接修改a[i]的数据为200；此时队列中为 100
	a[1].data = 200;
	//实际上对原元素的修改，也无法改变队列中的元素
	cout << q.front().data;
	return 0;
}
```
这就是说，当需要对队列中的元素进行修改而不仅仅时访问时，队列中存放的元素最好 **不要是元素本身**，而是它们的 **编号**(如果是数组的话则是 **下标**)

```C++
	queue<int> q;
	for (int i = 0; i < 4; i++)
	{
		a[i].data = i;
		q.push(i);
	}
	a[q.front()].data = 10;
	cout << a[0].data;
```
