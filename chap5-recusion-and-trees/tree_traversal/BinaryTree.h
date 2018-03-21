#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

#include <iostream>
#include <stack>
#include <utility>
#include <functional>
#include <vector>

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

	void toPreOrderSequence(std::vector<T>& seq)
	{
		auto f = [&seq](TreeNode* x) { seq.push_back(x->data); };
		traverse_preorder(root, f);

#ifdef DEBUG
		std::cout<< "toPreOrderSequence: "<<std::endl;
		for (auto v : seq) {
			std::cout<< v <<", ";
		}
#endif
	}

	void traverse()
	{
		auto f = [](TreeNode* x) { std::cout<< x->data<<", "; };
		traverse_preorder(root, f);
	}



private:

	void traverse_preorder(TreeNode* root, std::function<void(TreeNode*)> processFunc)
	{
		if ( root == nullptr ) return;
		//std::cout<< root->data << ", " ;
		processFunc(root);
		traverse_preorder(root->left, processFunc);
		traverse_preorder(root->right, processFunc);
	}

	void traverse_preorder_nonrecursive(TreeNode *root)
	{
		if ( root == nullptr )
			return;

		std::stack<TreeNode*> nodeStack;
		TreeNode *node = root;
		nodeStack.push(node);

		while(!nodeStack.empty()){
			node = nodeStack.top();
			nodeStack.pop();

			std::cout<< node->data <<", ";
			if ( node->right ) 
				nodeStack.push(node->right);
			if (node->left)
				nodeStack.push(node->left);
		}
	}

	void traverse_inorder_nonrecursive(TreeNode *root)
	{
		if ( root == nullptr )
			return;

		std::stack<std::pair<TreeNode*, bool> > nodeStack;
		TreeNode *node = nullptr;
		bool visited = false;
		nodeStack.push(std::make_pair(root, false));

		while(!nodeStack.empty()){
			node = nodeStack.top().first;
			visited = nodeStack.top().second; 	
			nodeStack.pop();

			if ( visited ){
				std::cout<<node->data<<", ";
			}
			else{
				if ( node->right ) 
					nodeStack.push(std::make_pair(node->right, false));

				nodeStack.push(std::make_pair(node, true));

				if (node->left)
					nodeStack.push(std::make_pair(node->left, false));

			}

		}
	}

	void traverse_postorder_nonrecursive(TreeNode *root)
	{
		if ( root == nullptr )
			return;

		std::stack<std::pair<TreeNode*, bool> > nodeStack;
		TreeNode *node = nullptr;
		bool visited = false;
		nodeStack.push(std::make_pair(root, false));

		while(!nodeStack.empty()){
			node = nodeStack.top().first;
			visited = nodeStack.top().second; 	
			nodeStack.pop();

			if ( visited ){
				std::cout<<node->data<<", ";
			}
			else{
				nodeStack.push(std::make_pair(node, true));
				if ( node->right ) 
					nodeStack.push(std::make_pair(node->right, false));
				if (node->left)
					nodeStack.push(std::make_pair(node->left, false));
			}

		}
	}

	void traverse_inorder(TreeNode* root)
	{
		if ( root == nullptr ) return;

		traverse_inorder(root->left);
		std::cout<< root->data << ", ";
		traverse_inorder(root->right);
	}

	void traverse_postorder(TreeNode* root)
	{
		if ( root == nullptr ) return;

		traverse_postorder(root->left);
		traverse_postorder(root->right);
		std::cout<< root->data << ", ";
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
