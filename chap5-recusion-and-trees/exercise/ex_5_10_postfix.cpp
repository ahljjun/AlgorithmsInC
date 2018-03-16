#include <iostream>

//const char *a="((1 + 1) * ((2 + 2) + (3 + 3)))";
//char *a = "(5 + ((4 * 6) * (8 + 9)))";
char *a = "(7 + ((4 * 6) * (8 + 9)))";
int i=0; // this must be a global value 


/*
  post expression:  
  * + 7 * * 4 6 + 8 9 5
    (((8+9) * (6*4)) + 7 ) * 5

  infix:
    ((7+((4*6)*(8+9)))*5)
*/
int eval();

int get_elem()
{
	int x = 0;
	while(a[i] == ' ')
		i++;
	if ( a[i] == '(' )
		return eval();
    
    while((a[i] >= '0') && (a[i] <= '9'))
			x = 10*x + (a[i++]-'0');

	i++;
	while(a[i] == ' ')
		i++;
	return x;
}

int eval()
{
	int x, y;
	if ( a[i] == '(' )
	{
		i++;
		x = get_elem();
	}

	if (a[i] == '+')
	{
		i++;
		y = get_elem();
		return x + y;
	}

	if ( a[i] == '*' )
	{
		i++;
		y = get_elem();
		return x * y;
	}
}

int main()
{
	std::cout<< eval() <<std::endl;
}






