#include "bst.h"
#include <iostream>
using namespace std;

void insertNode(node*& root, int key)
{
	if(root == nullptr)
	{
		root = new node;
		root->data = key;
		root->right = nullptr;
		root->left = nullptr;
	}
	else
	{
		if(root->data > key)
		{
			insertNode(root->left, key);
		}
		else
		{
			insertNode(root->right, key);
		}
	}
}
	

void deleteNode(node*& root, int key)
{
	if(root == nullptr)
	{
		cout << key << " was not found in the tree.\n\n";
		return;
	}
	else
	{
		if(key < root->data)
		{
			deleteNode(root->left, key);
		}
		else if(key > root->data)
		{
			deleteNode(root->right, key);
		}
		else // Key == root->data
		{
			if(root->left == nullptr)
			{
				// Both children are null
				if(root->right == nullptr)
				{
						delete root;
						root = nullptr;
				}
				// Second situation: left is null, right is NOT null
				else
				{
					node* dltPtr = root;
					root = root->right;
					delete dltPtr;
				}
			}
			// Third situation, left is NOT null, right is null
			else
			{
				if(root->right == nullptr)
				{
					node* dltPtr = root;
					root = root->left;
					delete dltPtr;
				}
				else // Fourth situation, Node has two children
				// Find largest child in left subtree
				{
					node* largestLeft = root->left; // Taking step left
					while(largestLeft->right != nullptr)
					{
						largestLeft = largestLeft->right;	
					}
					root->data = largestLeft->data;
					deleteNode(root->left, largestLeft->data);
				}
			}
		}
	}
}

//void printAscending(node* root); // Ascending order


//void printParenthetical(node* root); // Parenthetical Notation
//node* searchNode(node* root, int key);
//int findSmallest(node* root);
//int findLargest(node* root);
