#include "../sorting/utility.h"
#include "utility.h"

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



int main()
{
    // test
    BinarySearch_test();
}