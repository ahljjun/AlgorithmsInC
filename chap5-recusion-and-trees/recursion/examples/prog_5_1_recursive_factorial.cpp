#include <iostream>
#include <chrono>

using namespace std::chrono;

/*
* calculation of N! 
*/
long factorial(long N)
{
	if ( N == 0 )
		return 1;

    // very easy to overflow 
	return N * factorial(N-1); 
}

int get_num()
{
	int num;
	std::cout<<"input one integer: "<<std::endl;
	std::cin >> num ;

	return num;
}

int main()
{
	auto num = get_num();

	auto start = system_clock::now();
	std::cout<< "factorial: "<< factorial(num) << std::endl;
	auto end   = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	std::cout <<  "cost " 
	 << double(duration.count()) * microseconds::period::num / microseconds::period::den 
	 << "seconds" << std::endl;

}