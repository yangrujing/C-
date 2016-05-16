#include<iostream>
using namespace std;

//�жϸ������Ƿ����0
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
	double result = Power(base, expo >> 1); //������һλ���������2
	result *= result;
	if ((expo & 1) == 1) //�ð�λ�������ж�expo����������ż��������%����
		result *= base;
	return result;
}

double MyPower(double base, int expo)
{
	//�Ƿ�����
	if (equal(base, 0.0) && expo < 0)
		return 0.0;
	if (expo == 0) //�κ�����0�η���Ϊ1
		return 1.0;
	int absExpo = expo;
	if (expo < 0) //ָ��Ϊ����
		absExpo = -expo;
	double result = Power(base, absExpo);
	if (expo < 0) //2^(-3) = 1/(2^3)
		result = 1.0 / result;
	return result;
}


int main()
{
	double base = -2; //����
	int expo = -3; //ָ��
	double ret = MyPower(base, expo);
	cout << base << "^" << expo << " = " << ret << endl;
	getchar();
	return 0;
}