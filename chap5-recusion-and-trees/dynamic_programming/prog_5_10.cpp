#include <iostream>

// Fn = Fn-1 + Fn-2
int Fib(int i)
{
	if ( i < 1 ) return 0;

	if ( i == 1 )  return 1;

	return Fib(i-1) + Fib(i-2);
}

int F_bottom_up_dp(int i)
{
	int *F = new int[i+1];
	memset(F, 0, (i+1)*sizeof(int));

	F[0] = 0;
	F[1] = 1;
	for(int j = 2; j <= i; j++)
		F[j] = F[j-1]+F[j-2];

	return F[i];
}


const int unknown = -1;
const int N = 100;
int F[N];

int F_top_down_dp(int i)
{
	if ( i == 0 )
		return 0;
	if ( i== 1 )
		return 1;

	if ( F[i] != unknown )
		return F[i];

	return F_top_down_dp(i-1) + F_top_down_dp(i-2); 
}


int main()
{
	memset(F, -1, N*sizeof(int));
	for(int i=0; i<N; i++)
		std::cout<<F[i]<<std::endl;


	std::cout<<"recusive: "<< Fib(20)<<std::endl;
	std::cout<<"bottom up dp: "<< F_bottom_up_dp(20)<<std::endl;
	std::cout<<"top down dp: "<< F_top_down_dp(20)<<std::endl;

	return 0;
}