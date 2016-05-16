#include<iostream>
using namespace std;

//判断浮点数是否等于0
bool equal(double d1, double d2)
{
	if ((d1 - d2 < 0.000000001) && (d1 - d2 > -0.00000001))
		return true;
	else
		return false;
}

double Power(double base, int expo)
{
	if (expo == 1)
		return base;
	double result = Power(base, expo >> 1); //用右移一位来代替除以2
	result *= result;
	if ((expo & 1) == 1) //用按位与运算判断expo是奇数还是偶数，代替%运算
		result *= base;
	return result;
}

double MyPower(double base, int expo)
{
	//非法输入
	if (equal(base, 0.0) && expo < 0)
		return 0.0;
	if (expo == 0) //任何数的0次方都为1
		return 1.0;
	int absExpo = expo;
	if (expo < 0) //指数为负数
		absExpo = -expo;
	double result = Power(base, absExpo);
	if (expo < 0) //2^(-3) = 1/(2^3)
		result = 1.0 / result;
	return result;
}


int main()
{
	double base = -2; //基数
	int expo = -3; //指数
	double ret = MyPower(base, expo);
	cout << base << "^" << expo << " = " << ret << endl;
	getchar();
	return 0;
}