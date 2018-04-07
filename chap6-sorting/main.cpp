#include "utility.h"
#include <array>
#include <thread> // for std::this_thread:sleep_for
#include <chrono> //



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

void merge_test()
{
    std::array<int, 10> a;
    std::array<int, 20> b;
    std::array<int, 30> c;

    generateRandomDataSet(a);
    std::cout<<"\ndump a:"<<std::endl; 
    dumpData(a);
    quick_sort(a);
    std::cout<<"\ndump a after sorted:"<<std::endl; 
    dumpData(a);

    // delay 1 second to get different random set
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    generateRandomDataSet(b);
    std::cout<<"\ndump b:"<<std::endl; 
    dumpData(b);
    quick_sort(b);
    std::cout<<"\ndump b after sorted:"<<std::endl; 
    dumpData(b);

    // merge here
    //merge_1(a, b, c);

    // 
    std::array<int, 30> d;
    for(int i=0; i<10; i++)
        d[i] = a[i];
    for(int j=0; j<20; j++)
        d[10+j] = b[j];
    std::cout<<"\ndump d contents:"<<std::endl; 
    dumpData(d);
    merge(d,0,9,29);


    std::cout<<"\ndump the merge result of a & b"<<std::endl; 
    dumpData(d);

}

template<class T, size_t N>
void mergesort_test_1()
{
    std::array<T, N> a;
    std::array<T, N> b;
    std::array<T, N> c;
    std::array<T, N> d;

    generateRandomDataSet(a);
    std::copy(a.begin(), a.end(), b.begin());
    std::copy(a.begin(), a.end(), c.begin());
    std::copy(a.begin(), a.end(), d.begin());

    quick_sort(a);
    std::cout<<"\ndump the quick sort result of a"<<std::endl; 
    dumpData(a);

    mergesort(b, 0, N-1);
    std::cout<<"\ndump the merge result of b"<<std::endl;
    dumpData(b);

    mergesortBU(c, 0, N-1);
    std::cout<<"\ndump the bottom up merge result of c"<<std::endl;
    dumpData(c);

    improved_mergesortBU(d, 0, N-1);
    std::cout<<"\ndump the bottom up merge result of d"<<std::endl;
    dumpData(d);
}

void mergesort_test()
{
    mergesort_test_1<int, 32>();
    mergesort_test_1<int, 33>();
}

template <size_t N>
void heap_test_1()
{
    std::array<int, N> a;
    generateRandomDataSet(a); 

    std::vector<int> intVec(20);
    std::copy(a.begin(), a.end(), intVec.begin());

    heapsort(intVec);
    std::copy(intVec.begin(), intVec.end(), std::ostream_iterator<int>(std::cout, ",")); 

}

void heap_test()
{
    std::cout<<"\nheap sort for 20 elements"<<std::endl;
    heap_test_1<20>();

    std::cout<<"\nheap sort for 21 elements"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    heap_test_1<21>();
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

    std::cout<<"\n==== test for merge_test "<<std::endl;
    merge_test();

    std::cout<<"\n==== test for mergesort_test "<<std::endl;
    mergesort_test();

    std::cout<<"\n==== test for heap_test "<<std::endl;
    heap_test();
}
