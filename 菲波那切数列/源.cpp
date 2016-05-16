#include<iostream>
using namespace std;

int fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int a = 0, b = 1;
	int c;
	for (int i = 2; i <= n; i++)
	{
		c = a + b;
		a = b, b = c;
	}
	return c;
}

int fib1(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib1(n - 1) + fib1(n - 2);
}

int main()
{
	int n = 4;
	int ret = fib1(n);
	cout << ret << endl;
	getchar();
	return 0;
}