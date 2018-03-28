#include "utility.h"
#include <array>

int main()
{
    std::array<int, 1000> arr;
    generateRandomDataSet(arr);

    shaker_sort(arr);
    //insertion_sort_1(arr);

    std::cout<<"after non-adaptive bubble sort: "<<"\n";

    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, ", "));
}
