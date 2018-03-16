#include <iostream>
#include <cstring>

const char *a="5 9 8 + 6 4 * * 7 + *" ;
int i = strlen(a)-1;

int eval()
{
	int x = 0;
	while(i>=0 && a[i]==' ')
		i--;

	if (i>=0 && a[i] == '+')
	{
		i--;
		return eval() + eval();
	}

	if (i >=0 && a[i] == '*')
	{
		i--;
		return eval() * eval();
	}

	while(i >=0 && (a[i] >= '0') && (a[i] <= '9'))
		x = 10*x + (a[i--]-'0');

	return x;
}


int main()
{
	std::cout<<"i: "<<i<<std::endl;
	std::cout<<eval()<<std::endl;
}