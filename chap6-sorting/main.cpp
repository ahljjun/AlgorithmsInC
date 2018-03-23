#include "utility.h"
#include <array>

int main()
{
	std::array<int, 10> arr;
	generateRandomDataSet(arr);

	selection_sort(arr);

	std::cout<<"after selection sort: "<<"\n";

	std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, ", "));
}