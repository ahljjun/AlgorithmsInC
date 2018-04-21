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

	void printTree()
	{
		printTree1(root, 0);
	}

	BinaryTree<T>* contructTree1(const std::vector<T>& preOrder, const std::vector<T>& inOrder)
	{
		//Unsupported yet
		return NULL;
	}

	BinaryTree<T>* contructTree2(const std::vector<T>& preOrder, const std::vector<T>& inOrder)
	{
		//unsupported yet
		return NULL;		
	}

	int count() const 
	{
		return count1(root);
		count2(root, 0);
	}

	int leafCount() // for ex 5.86
	{
#ifdef DEBUG
		return leafCount_non_recursive(root);
#endif
		return leafCount(root);
	}

private:
	int leafCount(TreeNode *node)
	{
		if (node ==nullptr) return 0;
		if ( !node->left && !node->right) return 1;

		return leafCount(node->left) + leafCount(node->right);
	}

	int leafCount_non_recursive(TreeNode *node)
	{
		if (node ==nullptr) return 0;
		if ( !node->left && !node->right) return 1;

		std::queue<TreeNode*> nodeQ;
		nodeQ.push(node);
		int cnt = 0;

		while(!nodeQ.empty())
		{
			TreeNode *tn = nodeQ.front();
			nodeQ.pop();

			if ( !tn->left && !tn->right ){
				cnt++;
				continue;
			}

			if ( tn->left )
				nodeQ.push(tn->left);
			
			if (tn->right)
				nodeQ.push(tn->right);
		}

		return cnt;
	}

	void printnode(TreeNode *node, int h)
	{
		for(int i=0; i < h; i++)
			std::cout<<" ";
		if (node)
			std::cout<<node->data<<"\n";
		else
			std::cout<<"*"<<"\n";
	}
	void printTree1(TreeNode* root, int height)
	{
		if ( root==nullptr ) { printnode(nullptr, height); return; }
		printTree1(root->left, height+1);
		printnode(root, height);
		printTree1(root->right, height+1);
	}

	int count1(TreeNode* root)
	{
		if ( root==nullptr ) return 0;
		return count1(root->left) + count1(root->right) + 1;
	}

	//TODO: is it possible using tail recursive for count?

	int height1(TreeNode* root)
	{
		if ( root==nullptr )
			return -1;

		int u, v;
		u = height1(root->left);
		v = height1(root->right);
		if ( u > v ) return u+1;
		else return v+1;
	}

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
