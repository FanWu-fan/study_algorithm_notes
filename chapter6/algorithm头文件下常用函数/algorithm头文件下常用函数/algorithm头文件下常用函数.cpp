#include "pch.h"
#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;



int main()
{
	int x = 1, y = -2;
	cout << max(x, y) << endl;//输出较大值

	vector<int> a = { 10,11,12,13,14,15 };

	reverse(a.begin(), a.begin() + 4);
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
		cout << *it << endl;

	string str = "adcdefghi";
	reverse(str.begin() + 2, str.begin() + 6);//reverse逆序输出
	cout << str;

	vector<int> sa(10);
	fill(sa.begin(), sa.begin() + 10, 5);
	for (vector<int>::iterator it = sa.begin(); it != sa.end(); it++)
		cout << *it << endl;

}


