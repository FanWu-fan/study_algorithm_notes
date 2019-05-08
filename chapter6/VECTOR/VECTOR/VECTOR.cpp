#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;



int main()
{
	vector<int> s1;
	vector<vector<int>> ss1;

	for (int i = 0; i < 10; i++)
	{
		s1.push_back(i);//push_back就是在vector后面添加一个元素
	}
	for (vector<int>::iterator it = s1.begin(); it != s1.end(); ++it) //end()是 尾元素地址的下一个地址
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << s1[1] << endl;

	cout << "SIZE: " << s1.size() << endl;
	s1.pop_back();//删除vector最后一个元素
	cout << "SIZE: " << s1.size() << endl;

	s1.clear();//清空所有的元素
	cout << "SIZE: " << s1.size() << endl;


	for (int i = 0; i < 10; i++)
	{
		s1.push_back(i);//push_back就是在vector后面添加一个元素
	}

	s1.insert(s1.begin()+5, -1); //插入元素

	for (vector<int>::iterator it = s1.begin(); it != s1.end(); ++it)
	{
		cout << *it << " ";
	}//0 1 2 3 4 -1 5 6 7 8 9

	cout << endl;
	s1.erase(s1.begin() + 3);//删除单个元素
	for (vector<int>::iterator it = s1.begin(); it != s1.end(); ++it)
	{
		cout << *it << " ";
	}//0 1 2 4 -1 5 6 7 8 9

	cout << endl;
	s1.erase(s1.begin(), s1.begin() + 3);//删去一个区间的元素
	for (vector<int>::iterator it = s1.begin(); it != s1.end(); ++it)
	{
		cout << *it << " ";
	}//4 -1 5 6 7 8 9 [) 左闭右开

	cout << endl;

}

