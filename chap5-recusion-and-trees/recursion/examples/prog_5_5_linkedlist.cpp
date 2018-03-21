#include <iostream>
#include <vector>
#include <functional>
#include <cassert>
using std::vector;

struct Node
{
	Node(int value): data(value), next(nullptr) {}
	int data;
	struct Node *next;
};

using link = Node* ;

void create_list(const vector<int> &dataVec, Node* &list)
{
	assert(list == nullptr);
	for(auto value : dataVec)
	{
		std::cout<<value<<",";
		Node* node = new Node(value);
		node->next = list;
		list = node;
	}

	return;
}

int count(link x)
{
	if (x == nullptr)
		return 0;

	return 1 + count(x->next);
}

void printNode(link x)
{
	std::cout<<"visit: "<<x->data<<std::endl;
}

void traverse(link h, std::function<void (link)> visit)
{
	if ( h == nullptr ) return;
	visit(h);
	traverse(h->next, visit);
}

void traverseR(link h, std::function<void (link)> visit)
{
	if ( h == nullptr ) return;
	traverseR(h->next, visit);
	visit(h->next);
}

/*
 * For Ex5.14, delete the last node 
*/
void deleteLastNode(link x)
{
	if ( x == nullptr )
		return; 
	if ( x->next == nullptr )
	{
		delete x;
		x = nullptr;
		return;
	}

	if ( x->next->next == nullptr )
	{
		delete x->next;
		x->next = nullptr;
		return;
	}

	deleteLastNode(x->next);
}

int main()
{
	vector<int> dataVec;
	for(int i=1; i <= 10; i++)
		dataVec.push_back(i);

	Node* list = nullptr;
	create_list(dataVec, list);

	std::cout<< "list count: "<<count(list)<<std::endl;

	traverse(list, printNode);

	std::cout<<"delete last node"<<std::endl;

	deleteLastNode(list);
	std::cout<< "list count: "<<count(list)<<std::endl;
	traverse(list, printNode);
	deleteLastNode(list);
	std::cout<< "list count: "<<count(list)<<std::endl;
	traverse(list, printNode);
}


