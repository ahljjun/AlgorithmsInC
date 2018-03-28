#include "utility.h"
#include <array>

int main()
{
	std::array<int, 10> arr;
	generateRandomDataSet(arr);

	bubble_sort(arr);
	//insertion_sort_1(arr);

	std::cout<<"after non-adaptive selection sort: "<<"\n";

	std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, ", "));
}