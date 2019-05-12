// 后序遍历和中序遍历求得--层序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
	int data;
	node* lchild;
	node* rchild;
};

vector<int> pre;//先序
vector<int> in;//中序
vector<int> post;//后序
int n;//节点个数

//当前二叉树的后序序列区间为[postL,postR],中序序列区间为[inL,inR]
//create函数返回构建出的二叉树的根节点地址
node* create(int postL, int postR, int inL, int inR)
{
	if (postL > postR)
	{
		return NULL;//后续序列长度小于等于0时，直接返回
	}
	node* root = new node;//新建一个节点，用来存放当前二叉树的根节点
	root->data = post[postR];//新节点的数据域为根节点的值
	int k;
	for (k = inL; k <= inR; k++)
	{
		if (in[k] == post[postR])
		{
			break;//在中序序列中找到 in[k] == pre[L] 的节点
		}
	}
	int numLeft = k - inL;//左子树的节点个数
	//返回左子树的根节点地址，赋值给root的左指针
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
	return root;

}
int num = 0;//已经输出的节点个数
void BFS(node* root)//层序遍历
{
	queue<node*> q;//注意这里的队列存放的地址
	q.push(root);
	while (!q.empty())
	{
		node* now = q.front();
		q.pop();
		cout << now->data;
		num++;
		if (num < n); cout << " ";
		if (now->lchild != NULL) q.push(now->lchild);
		if (now->rchild != NULL) q.push(now->rchild);
	}
}

int main()
{
	cin >> n;
	pre.resize(n);
	in.resize(n);
	post.resize(n);
	for (int i = 0; i < n; i++)
		cin >> post[i];
	for (int i = 0; i < n; i++)
		cin >> in[i];
	node *root = create(0, n - 1, 0, n - 1);
	BFS(root);
	return 0;
}

