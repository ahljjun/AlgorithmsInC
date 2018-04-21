#include "../sorting/utility.h"
#include "utility.h"

#include <memory>
#include <cassert>

void BinarySearch_test()
{
    std::array<int, 100> arr;
    generateRandomDataSet(arr);
    std::cout<<"\ndata for select: "<<std::endl;

    quick_sort(arr);
    dumpData(arr);

    auto it = BinarySearch(arr.begin(), arr.end(), 50);

    if (it == arr.end())
        std::cout<<"\nNot found"<<std::endl;
    else
        std::cout<<"\nFound it: "<<std::endl;
}

//ex12.44
void BSTree_ex12_45()
{
    BSTree<char> tree;
    tree.insert('E');
    tree.insert('A');
    tree.insert('S');
    tree.insert('Y');
    tree.insert('Q');    
    tree.insert('U');
    tree.insert('E');
    tree.insert('S');
    tree.insert('T');
    tree.insert('I');
    tree.insert('O');
    tree.insert('N');

    tree.inorder();

    int cnt = tree.search('S');
    assert(cnt == 2);

    cnt = tree.search('I');
    assert(cnt == 1);  

    cnt = tree.search('Z');
    assert(cnt == 0);    
}


int main()
{
    // test
    BinarySearch_test();

    BSTree_ex12_45();

}