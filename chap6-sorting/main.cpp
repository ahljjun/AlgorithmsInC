#include "utility.h"
#include <array>




void quick_sort_test()
{
    std::array<int, 100> arr;

    generateRandomDataSet(arr);
    std::cout<<"data to be sorted by quicksort: "<<std::endl;
    dumpData(arr);
    quick_sort(arr);
    std::cout<<"data after sorted by quicksort: "<<std::endl;
    dumpData(arr);
}

void generateBestDataSetForQSort_test()
{

    std::array<int, 20> arr;
    generateBestDataSetForQSort(arr);
    std::cout<<"data for QSort: "<<std::endl;
    dumpData(arr);

    quick_sort(arr);
}
 


int main()
{
    quick_sort_test();

    std::cout<<"\n==== test for generateBestDataSetForQSort "<<std::endl;
    generateBestDataSetForQSort_test();
}
