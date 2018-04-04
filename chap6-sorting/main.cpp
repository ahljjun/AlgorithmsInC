#include "utility.h"
#include <array>




void quick_sort_test()
{
    std::array<int, 10> arr;

    generateRandomDataSet(arr);
    std::cout<<"data to be sorted by quicksort: "<<std::endl;
    dumpData(arr);
    quick_sort(arr);
    std::cout<<"data after sorted by quicksort: "<<std::endl;
    dumpData(arr);
}

void non_recursive_quick_sort_test()
{
    std::array<int, 10> arr;
    generateRandomDataSet(arr);
    std::cout<<"\ndata to be sorted by non_recursive_quicksort_by_stack: "<<std::endl;
    dumpData(arr);
    non_recursive_quick_sort_by_stack(arr);
    std::cout<<"\ndata after sorted by non_recursive_quicksort_by_stack: "<<std::endl;
    dumpData(arr);

    std::array<int, 10> arr1;
    generateRandomDataSet(arr1);
    std::cout<<"\ndata to be sorted by non_recursive_quicksort_by_queue: "<<std::endl;
    dumpData(arr1);
    non_recursive_quick_sort_by_stack(arr1);
    std::cout<<"\ndata after sorted by non_recursive_quicksort_by_queue: "<<std::endl;
    dumpData(arr1);
}

void generateBestDataSetForQSort_test()
{

    std::array<int, 20> arr;
    generateBestDataSetForQSort(arr);
    std::cout<<"\ndata for QSort: "<<std::endl;
    dumpData(arr);

    quick_sort(arr);
}

void improved_quick_sort_test()
{
    std::array<int, 100> arr;
    generateRandomDataSet(arr);
    std::cout<<"\ndata for QSort: "<<std::endl;
    dumpData(arr);

    improved_quick_sort(arr);
    std::cout<<"\nafter sorted: "<<std::endl;
    dumpData(arr);
}


void select_test()
{
    std::array<int, 100> arr;
    generateRandomDataSet(arr);
    std::cout<<"\ndata for select: "<<std::endl;
    dumpData(arr);

    int val = select(arr, 21);
    std::cout<<"\n21 key value is:"<<val<<std::endl;
    dumpData(arr);
}


int main()
{
    std::cout<<"\n==== test for quick_sort_test "<<std::endl;
    quick_sort_test();

    std::cout<<"\n==== test for generateBestDataSetForQSort "<<std::endl;
    generateBestDataSetForQSort_test();

    std::cout<<"\n==== test for non_recursive_quick_sort_test "<<std::endl;
    non_recursive_quick_sort_test();

    std::cout<<"\n==== test for improved_quick_sort_test "<<std::endl;
    improved_quick_sort_test();

    std::cout<<"\n==== test for select_test "<<std::endl;
    select_test();  
}
