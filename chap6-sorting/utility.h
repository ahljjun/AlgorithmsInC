#ifndef __SORT_UTILITY
#define __SORT_UTILITY

#include <cstdlib>
#include <array>
#include <iostream>

template <size_t N>
void generateRandomDataSet(std::array<int, N>& arr)
{
	for (int i=0; i < N; i++)
		arr[i] = 1000 * (1.0 * rand()/RAND_MAX);

#ifdef DEBUG
	for (auto v : arr)
		std::cout<<v<<", ";

	std::cout<<"\n";
#endif
}



#endif
