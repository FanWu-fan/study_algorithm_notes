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

