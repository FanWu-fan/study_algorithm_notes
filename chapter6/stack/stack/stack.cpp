#include "pch.h"
#include <iostream>
#include <stack>
#include <map>
#include<string>

using namespace std;

int main()
{
	stack<int> st;
	for (int i = 0; i < 5; i++)
	{
		st.push(i);//实现压栈
	}
	cout << st.top()<< endl;//这个实现访问 栈顶的元素

	pair<string, int> p("haha", 5);
	cout << p.first << " " << p.second << endl;

}
