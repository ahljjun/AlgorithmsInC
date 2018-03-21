#include <iostream>

/*
* calc Euclid's algorithm:
*  两个整数，x>y, x和y的最大公因子
*  等同于 y 与 x mod y的最大公因子
*/

int i = 0;
int gcd(int m, int n)
{
	if ( n == 0 )
		return m;

	return gcd(n, m % n);
}

int gcd_non_recusive(int m, int n)
{
    while( n != 0 ) 
    {
    	int k = n;
    	n = m % n;
    	m = k;
    }

    return m;
}

int main()
{
	std::cout<<gcd(100, 5) << " "<< gcd_non_recusive(100, 5);
	return 0;
}

