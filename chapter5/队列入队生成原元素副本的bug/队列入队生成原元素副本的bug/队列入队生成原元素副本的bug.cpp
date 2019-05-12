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
	//queue<node> q;
	//for (int i = 0; i <= 3; i++)
	//{
	//	a[i].data = i;
	//	q.push(a[i]);
	//}

	////尝试直接把队首元素(即a[1])的数据域改为100
	//q.front().data = 100;
	////事实上对队列元素的修改无法改变原元素
	//cout << a[1].data << " " << a[2].data << " " << a[3].data << endl;
	////然后尝试直接修改a[i]的数据为200；此时队列中为 100
	//a[1].data = 200;
	////实际上对原元素的修改，也无法改变队列中的元素
	//cout << q.front().data;
	//return 0;

	queue<int> q;
	for (int i = 0; i < 4; i++)
	{
		a[i].data = i;
		q.push(i);
	}
	a[q.front()].data = 10;
	cout << a[0].data;
}

