#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q1;
	for (int i = 1; i <= 5; i++)
	{
		q1.push(i);//压入队列
	}
	cout << q1.front() << " " << q1.back()<<endl;//front是第一个元素
	for (int i = 1; i <= 3; i++)
	{
		q1.pop();//1，2，3弹出队列
	}
	cout << q1.front() << endl;

	queue<int> q;
	if (q.empty() == true) cout << "Empty!" << endl;//empty（）检查队列是否为空

	cout << q1.size() << endl;//返回的是 队列的长度，元素的个数


	//优先队列
	priority_queue <int> pri_q;

}
