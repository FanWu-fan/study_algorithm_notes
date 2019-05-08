#include "pch.h"
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<stack>

using namespace std;

int F(int n)
{
	if (n == 0) return 1;
	else
	{
		cout << n<<endl;
		return F(n - 1)*n;

	}

}

int Fs(int n)
{
	stack<int> num;
	int sum=1;
	for (int i = n; i >=1; i--)
	{
		num.push(i);
	}
	while (num.empty() != true)
	{
		sum *= num.top();
		num.pop();
	}

	return sum;
}



int main()
{
	int n;
	n = 10;
	cout << "F(N): " << F(n);

	cout << "F(N): " << Fs(n);

}

