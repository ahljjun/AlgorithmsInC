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

	tree.traverse();

	std::vector<char> charVec;
	tree.toPreOrderSequence(charVec);
}