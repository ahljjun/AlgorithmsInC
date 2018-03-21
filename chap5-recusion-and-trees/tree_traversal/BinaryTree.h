#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

#include <iostream>
#include <stack>
#include <utility>
#include <functional>
#include <vector>
#include <queue>

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
		seq.clear();
		auto f = [&seq](TreeNode* x) { seq.push_back(x->data); };
		traverse_preorder(root, f);

#ifdef DEBUG
		std::cout<< "toPreOrderSequence: ";
		for (auto v : seq) {
			std::cout<< v <<", ";
		}
		std::cout<<"\n";
#endif
	}

	void toInOrderSequence(std::vector<T>& seq)
	{
		seq.clear();
		auto f = [&seq](TreeNode* x) { seq.push_back(x->data); };
		traverse_inorder(root, f);

#ifdef DEBUG
		std::cout<< "toInOrderSequence: ";
		for (auto v : seq) {
			std::cout<< v <<", ";
		}
		std::cout<<"\n";
#endif
	}

	void toPostOrderSequence(std::vector<T>& seq)
	{
		seq.clear();
		auto f = [&seq](TreeNode* x) { seq.push_back(x->data); };
		traverse_postorder(root, f);

#ifdef DEBUG
		std::cout<< "toPostOrderSequence: ";
		for (auto v : seq) {
			std::cout<< v <<", ";
		}
		std::cout<<"\n";
#endif
	}

	void toLevelOrderSequence(std::vector<T>& seq)
	{
		seq.clear();
		auto f = [&seq](TreeNode* x) { seq.push_back(x->data); };
		traverse_level_order(root, f);

#ifdef DEBUG
		std::cout<< "toLevelOrderSequence: ";
		for (auto v : seq) {
			std::cout<< v <<", ";
		}
		std::cout<<"\n";
#endif
	}	

	void traverse()
	{
		auto f = [](TreeNode* x) { std::cout<< x->data <<", "; };
		traverse_preorder(root, f);
		std::cout<<"\n";
	}

private:

	void traverse_level_order(TreeNode* root, std::function<void(TreeNode*)> processFunc)
	{
		if ( root == nullptr )
			return;
		std::queue<TreeNode*> nodeQ;
		nodeQ.push(root);

		while(!nodeQ.empty()){
			TreeNode *node = nodeQ.front();
			processFunc(node);
			nodeQ.pop();

			if(node->left) nodeQ.push(node->left);
			if(node->right) nodeQ.push(node->right);
		}
	}

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

	void traverse_inorder(TreeNode* root, std::function<void (TreeNode*)> processFunc)
	{
		if ( root == nullptr ) return;

		traverse_inorder(root->left, processFunc);
		processFunc(root);
		traverse_inorder(root->right, processFunc);
	}

	void traverse_postorder(TreeNode* root, std::function<void(TreeNode*)> processFunc)
	{
		if ( root == nullptr ) return;

		traverse_postorder(root->left, processFunc);
		traverse_postorder(root->right, processFunc);

		processFunc(root);
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
