#include<iostream>
using namespace std;

bool IsOdd(int n) //�ж��Ƿ�Ϊ����
{
	return (n & 1) == 1;
}

void ReOrder1(int *arr, int len, bool(*fun)(int))
{
	int begin = 0;
	int end = len - 1;
	while (begin <= end)
	{
		while (begin <= end && fun(arr[begin]))//���������++
			begin++;
		while (begin <= end && !fun(arr[end])) //�����ż��--
			end--;
		if (begin < end)
		{
			swap(arr[begin], arr[end]);
			begin++;
			end--;
		}
	}
}

void ReOrder(int *arr, int len)
{
	ReOrder1(arr, len, IsOdd);
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	ReOrder(arr, len);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	getchar();
	return 0;
}