#ifndef __SORT_UTILITY
#define __SORT_UTILITY

#include <cstdlib>
#include <array>
#include <iostream>

template <size_t N>
void generateRandomData(std::array<int, N>& arr)
{
	for (int i=0; i < N; i++)
		arr[i] = 1000 * rand(); //(1.0 * rand()/RADN_MAX);

#ifdef DEBUG
	//for (auto it = arr.begin(); it != arr.end(); it++)
	for (auto v : arr)
		std::cout<<v<<", ";

	std::cout<<"\n";
#endif
}



#endif