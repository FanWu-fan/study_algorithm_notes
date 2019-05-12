// 哈夫曼树--合并果子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>	
#include <vector>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> q; //数字小的优先级越大
int main()
{
	int n;
	long long temp, x, y, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		q.push(temp);//将初始重量压入优先队列中
	}
	while (q.size() > 1)//只要优先队列中至少有两个元素
	{
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		q.push(x + y);//取出堆顶的两个元素，求和后压入优先队列
		ans += x + y;//累计求和的结果
		cout << "LLD: " << ans << endl;
	}
}

