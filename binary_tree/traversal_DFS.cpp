/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 二叉树的遍历算法
// C++实现二叉树的三种深度优先遍历(DFS)
// 前序遍历、中序遍历、后序遍历

#include <iostream>

using namespace std;

/* 二叉树节点的定义 */
struct TreeNode
{
	int val;
	TreeNode *left, *right;
};

/* 创建新的节点并返回指针 */
TreeNode* newNode(int value)
{
	TreeNode *temp = new TreeNode;
	temp->val = value;
	temp->left = temp->right = nullptr;
	return temp;
}

/* 前序遍历 */
void preorder(TreeNode *root)
{
	if (!root)
		return;

	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

/* 中序遍历 */
void inorder(TreeNode *root)
{
	if (!root)
		return;

	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

/* 后序遍历 */
void postorder(TreeNode *root)
{
	if (!root)
		return;

	postorder(root->left);
	postorder(root->right);
	cout << root->val << " ";
}

// 测试代码
int main(int argc, char const *argv[])
{
// 遍历如下二叉树
//      1
//    /   \
//   2     3  
//  / \
// 4   5
	TreeNode *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	// 前序遍历
	cout << "Preorder traversal:" << endl;
	preorder(root);
	cout << endl;

	// 中序遍历
	cout << "Inorder traversal:" << endl;
	inorder(root);
	cout << endl;

	// 后序遍历
	cout << "Postorder traversal:" << endl;
	postorder(root);
	cout <<endl;

	return 0;
}