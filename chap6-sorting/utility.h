#ifndef __SORT_UTILITY
#define __SORT_UTILITY

#include <cstdlib>
#include <array>
#include <iostream>
#include <algorithm>
#include <ctime>

template <size_t N>
void generateRandomDataSet(std::array<int, N>& arr)
{
    srand(time(0));
    for (int i=0; i < N; i++)
        arr[i] = N * (1.0 * rand()/(double)RAND_MAX);

#ifdef DEBUG
    std::cout<<"random data set: "<<std::endl;
    for (auto v : arr)
        std::cout<<v<<", ";

    std::cout<<"\n";
#endif
}

template <class T, size_t N>
void dumpData(const std::array<T, N>& arr){
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<T>(std::cout, ", "));
}

template<class T, size_t N>
void selection_sort(std::array<T, N>& arr)
{
    for(int i=0; i < N; i++){
        int min = i;
        for(int j=i+1; j < N; j++){
            if ( arr[j] < arr[i] ){
                min = j;
            }
        }
        std::swap(arr[i], arr[min]);
    }
}


// ex_6.19
// non-adaptive selection sort, with minimum key swapped each loop
template<class T, size_t N>
void selection_sort_1(std::array<T, N>& arr)
{
    for(int i=0; i < N; i++){
        int min = i;
        for(int j=i+1; j < N; j++){
            if ( arr[j] < arr[i] ){
                std::swap(arr[j], arr[i]);
            }
        }
        
    }
}

template <class T, size_t N>
void 
insertion_sort(std::array<T, N>& arr)
{
    //compare and swap to find the smallest key
    // to be the sentinel key and also as the first element
    for(int i=N-1; i>0; i--){
        if ( arr[i] < arr[i-1] )
            std::swap(arr[i-1], arr[i]);
    }

    // since arr[0], arr[1] are already sorted.
    for(int i=2; i<N; i++){
        int j = i;
        typename std::array<T, N>::value_type v = arr[i];
        while( v < arr[j-1] ){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = v;
    }
}

// ex6.16
template <class T, size_t N>
void 
insertion_sort_1(std::array<T, N>& arr)
{
    for(int i=0; i<N; i++){
        int j = i;
        typename std::array<T, N>::value_type v = arr[j];
        while( j>1 && (v < arr[j-1]) ){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = v;
    }
}


// example_6.1 
// non-adaptive insertion sort 
template <class T, size_t N>
void 
insertion_sort_2(std::array<T, N>& arr)
{
    int i, j;
    for(i=1; i<N; i++){
        for(j=i; j>0; j--){
            if (arr[j] < arr[j-1]){
                std::swap(arr[j], arr[j-1]);
            }
        }
    }
}

// example_6.4
template <class T, size_t N>
void 
bubble_sort(std::array<T, N>& arr)
{
    for(int i=0; i<N; i++){
        for(int j=N-1; j>i; j--){
            if (arr[j] < arr[j-1]){
                std::swap(arr[j], arr[j-1]);
            }
        }       
    }
}

//ex6.25, adaptive bubble sort
template <class T, size_t N>
void 
bubble_sort_1(std::array<T, N>& arr)
{
    int i,j;
    i=0;
    while( i<N ){
        int lastSwapped = -1;
        for(int j=N-1; j>i; j--){
            if (arr[j] < arr[j-1]){
                std::swap(arr[j], arr[j-1]);
                lastSwapped = j;
            }
        }
        if ( lastSwapped == -1 )
            break;
        else
            i = lastSwapped;        
    }
}

//ex6.30, shaker sort
template <class T, size_t N>
void
shaker_sort(std::array<T, N>& arr)
{
    int left = 0;
    int right = N;
    int shift;

    while(left < right){
        for(int i=left+1; i<right; i++){
            if ( arr[i-1] > arr[i] ){
                std::swap(arr[i-1], arr[i]);
                shift = i;
            }
        }
        right = shift;

        for(int i=right-1; i>left; i--){
            if (arr[i-1] > arr[i]){
                std::swap(arr[i-1], arr[i]);
                shift = i;
            }
        }
        left = shift;
    }
}

//ex6.75
template <class T, size_t N, size_t M>
void
small_key_range_sort(std::array<T, N>& arr)
{
    std::array<int, M+1> counts; 
    std::array<T, N> b;
    for(int i=0; i<M; i++) {
        counts[i] = 0;     
    }

    for(int j=0; j<N; j++) 
        counts[arr[j]+1]++; // valid key: from 1~M (0~M-1)

    for(int i=1; i<M; i++)
        counts[i] += counts[i-1];
#ifdef DEBUG
    std::cout<<"counts: "<<std::endl;
    std::copy(counts.begin(), counts.end(), std::ostream_iterator<int>(std::cout, ", "));
#endif    

    for(int j=0; j<N; j++)
        b[counts[arr[j]]++] = arr[j]; //

#ifdef DEBUG
    std::cout<<"\nb: "<<std::endl;
    std::copy(b.begin(), b.end(), std::ostream_iterator<int>(std::cout, ", "));
#endif

    for(int i=0; i<N; i++)
        arr[i] = b[i];
}



template <class T, size_t N>
void
quick_sort_1(std::array<T, N>& arr, int first, int last)
{
    if ( last <=first )
        return;

    typename std::array<T, N>::value_type v = arr[last];
    int i = first;
    int j = last-1;

    while( i<j ){
        while(arr[i] < v)
            i++;
        while(j>first && arr[j]>= v) // need to cover  == v case
            j--;

        if( i<j )
            std::swap(arr[i], arr[j]);
    }

    std::swap(arr[i], arr[last]);
#ifdef DEBUG
    std::cout<<"\ni, j "<<i<<", "<<j<<std::endl;
#endif
    quick_sort_1(arr, first, i-1);
    quick_sort_1(arr, i+1, last);
}

template <class T, size_t N>
void
quick_sort(std::array<T, N>& arr)
{
    quick_sort_1(arr, 0, N-1);
}


//ex7.10 
// generate N unique data set 
// which is best for quick sort
// when partition. 

template <size_t N>
void generateBestDataSetForQSort(std::array<int, N>& arr, int first ,int last)
{
    if ( last<=first+1 ){
        return;
    } 

    int mid = (first+last)/2;
    typename std::array<int, N>::value_type v = arr[mid];
    int j = mid+1;
    while( j <= last ) {
        arr[j-1] = arr[j]; 
        j++;        
    }
    arr[last] = v;

    generateBestDataSetForQSort(arr, first, mid-1);
    generateBestDataSetForQSort(arr, mid, last-1);
}

template <size_t N>
void generateBestDataSetForQSort(std::array<int, N>& arr)
{
    int n = 1;
    std::generate(arr.begin(), arr.end(), [&n]{return n++;});

    generateBestDataSetForQSort(arr, 0, N-1);
}


#endif
