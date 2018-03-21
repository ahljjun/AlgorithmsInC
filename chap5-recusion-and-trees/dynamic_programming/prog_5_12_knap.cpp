#include <iostream>

struct Item{
	int size;
	int val;
};

const int ItemKinds = 5;
Item Items[ItemKinds] = {
	{3, 4},
	{4, 5},
	{7, 10},
	{8, 11},
	{9, 13}
};

// this is 0/1 knap
// how to get the item kinds? backtrace?
int knap(int cap)
{
	int max = 0;
	int t = 0;
	int space = 0;
	for(int i=0; i < ItemKinds; i++){
		if ((space = (cap - Items[i].size)) >= 0){
			if ( space >0 && (t = knap(space) + Items[i].val) > max){
				max = t;
			}
		}
	}

	return max;
}


int main()
{
	for(int i=0; i < ItemKinds; i++)
		std::cout<< Items[i].size <<", "<< Items[i].val <<std::endl;

	std::cout<< "knap: "<< knap(17) << std::endl;
}

