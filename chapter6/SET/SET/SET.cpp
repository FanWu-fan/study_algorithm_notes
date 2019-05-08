#include "pch.h"
#include <iostream>
#include <set>
#include <string>

using namespace std;



int main()
{
	//set<int> st;
	//st.insert(3);
	//st.insert(5);
	//st.insert(-5);
	//st.insert(3);//自动排序，自动去除重复的元素

	//for (set<int>::iterator it = st.begin(); it != st.end(); it++)
	//{
	//	cout << *it<<" ";
	//}

	//set<int>::iterator it = st.find(5);
	//cout << *it;

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

}


