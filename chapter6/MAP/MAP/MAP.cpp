#include "pch.h"
#include <iostream>
#include <map>
#include<string>
#include<vector>
#include<set>

using namespace std;

int main()
{
	map<string, int> mstr_int;
	map<set<int>, int> ms_int;

	//访问方式有两种，1）通过下标访问,map的键是唯一的
	map<char, int> mpc_i;
	mpc_i['c'] = 20;
	mpc_i['c'] = 30;
	cout << mpc_i['c'] << endl;

	//2） 通过迭代器进行访问,map和set的内部都是红黑树实现的。按照从小到大的顺序排列映射
	map<string, int> mpst_i;
	mpst_i["love"] = 10;
	mpst_i["like"] = 5;
	for (map<string, int>::iterator it = mpst_i.begin(); it != mpst_i.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}



}
