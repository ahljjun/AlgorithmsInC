#ifndef __SORT_UTILITY
#define __SORT_UTILITY

#include <cstdlib>
#include <array>
#include <iostream>
#include <algorithm>

template <size_t N>
void generateRandomDataSet(std::array<int, N>& arr)
{
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

#endif
