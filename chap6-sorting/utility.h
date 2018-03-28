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
        arr[i] = 1000 * (1.0 * rand()/(double)RAND_MAX);

#ifdef DEBUG
    std::cout<<"random data set: "<<std::endl;
    for (auto v : arr)
        std::cout<<v<<", ";

    std::cout<<"\n";
#endif
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

#endif
