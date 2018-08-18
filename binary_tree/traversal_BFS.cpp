/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 二叉树的遍历算法
// C++实现二叉树广度优先遍历(BFS)又称层遍历
// 分别使用两种方法实现：1.使用输出某层的函数 2.使用队列
// 参考代码：https://www.geeksforgeeks.org/level-order-tree-traversal/

#include <iostream>
#include <queue>

using namespace std;

/* 二叉树节点的定义 */
struct TreeNode
{
	int val;
	TreeNode *left, *right;
};

/* 方法一函数声明 */
void printGivenLevel(TreeNode *node, int level);
int height(TreeNode *node);
TreeNode* newNode(int value);

/* 逐层遍历树：方法一 */
void printLevelOrder1(TreeNode *root)
{
	int h = height(root);
	for (int i = 0; i < h; ++i)
		printGivenLevel(root, i);
}

/* 打印指定层 */
void printGivenLevel(TreeNode *root, int level)
{
	if (root == nullptr)
		return;
	if (level == 0)
		cout << root->val << " ";
	else if (level > 0)
	{
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1);
	}
}

/* 计算树的高度 */
int height(TreeNode *root)
{
	if (root == nullptr)
		return 0;
	else
	{
		/* 计算左右子树的高度 */
		int lheight = height(root->left);
		int rheight = height(root->right);

		/* 返回较大者 */
		if (lheight > rheight)
			return lheight + 1;
		else
			return rheight + 1;
	}
}

/* 创建新的节点并返回指针 */
TreeNode* newNode(int value)
{
	TreeNode *temp = new TreeNode;
	temp->val = value;
	temp->left = temp->right = nullptr;
	return temp;
}

/* 层序遍历树：方法二 */
void printLevelOrder2(TreeNode *root)
{
	if (root == nullptr)
		return;

	// 创建空队列实现层序遍历
	queue<TreeNode *> q;

	// 根节点入队
	q.push(root);

	while (!q.empty())
	{
		// 打印队首节点并出队
		TreeNode *node = q.front();
		cout << node->val << " ";
		q.pop();

		// 左子节点入队
		if (node->left != nullptr)
			q.push(node->left);

		// 右子节点入队
		if (node->right != nullptr)
			q.push(node->right);
	}
}

// 测试代码
int main(int argc, char const *argv[])
{
	/*
	遍历如下二叉树：
	     1
	   /   \
	  2     3  
	 / \
	4   5
	*/

	TreeNode *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	// 树高
	cout << "The height of tree is " << height(root) << endl;

	// 层序遍历：方法一
	cout << "Method 1:" << endl;
	cout << "Level order traversal: ";
	printLevelOrder1(root);
	cout << endl;

	// 层序遍历：方法二
	cout << "Method 2:" << endl;
	cout << "Level order traversal: ";
	printLevelOrder2(root);
	cout <<endl;

	return 0;
}