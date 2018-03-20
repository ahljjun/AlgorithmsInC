#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

#include <iostream>

template <class T>
class BinaryTree
{
	struct TreeNode
	{
		TreeNode(T val): data(val), left(0), right(0) {}
		T data;
		TreeNode *left;
		TreeNode *right;
	};

	TreeNode *root;
public:
	BinaryTree() : root(nullptr) {}
	// forbidden copy constructor and assignment currently
	BinaryTree(const BinaryTree& rhs) = delete; 
	BinaryTree& operator=(const BinaryTree& rhs) = delete;

	void insert(T data)
	{
		//insert_recursive(root, data);	
		insert_iteration(data);
	}

	void traverse()
	{
		traverse(root);
	}

private:

	void traverse(TreeNode* root)
	{
		if ( root == nullptr ) return;
		std::cout<< root->data << ", " ;
		traverse(root->left);
		traverse(root->right);
	}


	void insert_recursive(TreeNode* &root, T data)
	{
		if ( root == nullptr ){
			root = new TreeNode(data);
		}
		else if ( root->data > data ) {
			insert_recursive(root->left, data);
		}
		else {
			insert_recursive(root->right, data);
		}
	}

	void insert_iteration(T data)
	{
		if ( root == nullptr ){
			root = new TreeNode(data);
			return;
		}

		TreeNode *node = root;

		while( node ) {
			if ( node->data > data )
			{
				// insert to node->left ; 
				if ( node->left == nullptr ) {
					node->left = new TreeNode(data);
					break;
				}
				else{
					node = node->left;
				}
			}
			else
			{
				// insert to node->right;
				if ( node->right == nullptr ) {
					node->right = new TreeNode(data);
					break;
				}
				else{
					node = node->right;
				}
			}
		}
	}
};




#endif
