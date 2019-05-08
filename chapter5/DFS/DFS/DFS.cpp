#include "pch.h"
#include <iostream>
using namespace std;

const int maxn = 30;
int n, V, maxvalue = 0;//物品件数n，背包容量 V，最大价值 maxvalue
int w[maxn], c[maxn];//w[i]为每件物品的重量，c[i]为每件物品的价值

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


