# Chapter6 数据结构专题
## 1.0 vector
```C++
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
```
## 1.1 set
set为集合，是一个内部自动有序且不含重复元素的容器。在考试中，可能出现需要去掉重复元素的情况，而且有可能因为这些元素比较大或者类型不是int型而不能直接开 **散列表**，在这种情况下，可以使用 **set** 来保留元素本身而不考虑它的个数。加入set以后实现自动排序。
```C++
	set<int> st;
	st.insert(3);
	st.insert(5);
	st.insert(-5);
	st.insert(3);//自动排序，自动去除重复的元素

	for (set<int>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout << *it<<" ";
	}

	set<int>::iterator it = st.find(5);
	cout << *it;
```
## 1.2 string
```c++

	string str;
	str = "woshiahahha";
	string str2 = "++pingjia";

	cout << str<<endl;//str重载了 << 。 可以直接输出

	//string str2;
	//cout << "输入str2: ";
	//cin >> str2;
	//cout << str2 << endl;//str重载了 << 。 可以直接输出

	cout << str[4];
	for (string::iterator it = str.begin(); it != str.end(); ++it)
	{
		cout << *it << endl;
	}

	//拼接两个字符串 opeator+=
	string str3;
	str3 = str + str2;
	cout << str3<<endl;
	str3 += str;
	cout << str3 << endl;

	//可以直接使用 == ！+ < <= > >=比较大小，比较规则是 字典序
	string str11 = "aab", str21 = "aaa", str31 = "aaa";
	if (str11 == str21) cout << "str11 == str21" << endl;
	if (str11 == str31) cout << "str11 == str31" << endl;
	if (str21 == str31) cout << "str21 == str31" << endl;

	cout << str.size()<<endl;
	cout << "str: " << str << endl;
	str.insert(3, "RAND");	//插入字符串
	cout << "str: " << str << endl;

	//删除字符串
	str.erase(str.begin() + 1);
	cout << "str: " << str << endl;

	//删除区间字符串
	str.erase(str.begin(), str.begin() + 4);
	cout << "str: " << str << endl;

	//删除一定长度的字符串,从1号位置开始
	str.erase(1, 3);
	cout << "str: " << str << endl;

	//返回子串
	string substr = str.substr(2, 3);
	cout << "substr: " << substr << endl;

	//find(str),如果没有找到，那么返回的是： string::npos,
	string s1 = "Thank you for your smile.";
	string s2 = "you";
	string s3 = "me";

	if (s1.find(s2) != string::npos)
	{
		cout << s1.find(s2) << endl;
	}
	if (s1.find(s2, 7) != string::npos)
	{
		cout << s1.find(s2, 7) << endl;
	}
	if (s1.find(s3) != string::npos)
	{
		cout << s1.find(s3) << endl;
	}

	//repalce(pos,len,str2)将str从pos号位置开始，长度为len的子串替换为 str2
	s1.replace(1, 5, s2);
	cout << s1 << endl;
	s1.replace(s1.begin(),s1.begin() + 7, s2);
	cout << s1 << endl;
```

## 1.3 map
map翻译为映射，也是常用的STL容器，在定义数组时，其实是定义了一个从int型到int型的映射，比如 array[0] = 25,array[4] = 36. 在数字很大的时候，可以将这些数字当作一些字符串，建立 string 到 int 的映射。

```C++
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
```
## 1.4 queue
队列，实现 **先进先出**的容器。

```C++
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
```
## 1.5 stack
栈，实现一个 后进先出的容器。
```C++
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
```

## algorithm头文件下常用的函数
```c++
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
```