#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}

int getHeight(Node* root)
{
	if (root->left == NULL && root->right == NULL)
		return 0;

	int left = 0;
	if (root->left != NULL)
		left = getHeight(root->left);

	int right = 0;
	if (root->right != NULL)
		right = getHeight(root->right);

	return (max(left, right) + 1);
}

void calculateLevelSum(Node* node, int level, int sum[])
{
	if (node == NULL)
		return;

	sum[level] += node->data;

	calculateLevelSum(node->left, level + 1, sum);
	calculateLevelSum(node->right, level + 1, sum);
}

int main()
{

  Node* root = newNode(6);
	root->left = newNode(4);
	root->right = newNode(8);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(7);
	root->right->right = newNode(9);

	
	int levels = getHeight(root) + 1;

	int sum[levels] = { 0 };
	calculateLevelSum(root, 0, sum);

	printArr(sum, levels);

	return 0;
}
