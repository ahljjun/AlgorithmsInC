#include "BinaryTree.h"
#include <vector>

int main()
{
	BinaryTree<char> tree;
	tree.insert('E');
	tree.insert('D');
	tree.insert('H');
	tree.insert('B');
	tree.insert('F');
	tree.insert('A');
	tree.insert('C');
	tree.insert('G');

	/*
	    E
	 D     H
  B      F		 	 
A   C       G   

	*/

	tree.traverse();

	std::vector<char> preOrderVec;
	tree.toPreOrderSequence(preOrderVec);

	std::vector<char> inOrderVec;
	tree.toInOrderSequence(inOrderVec);	

	std::vector<char> postOrderVec;
	tree.toPostOrderSequence(postOrderVec);	

	std::vector<char> levelOrderVec;
	tree.toLevelOrderSequence(levelOrderVec);	

	tree.printTree();	
}