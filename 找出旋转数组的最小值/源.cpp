#include<iostream>
using namespace std;

int LoopSearch(int *arr, int begin, int end);

int FindMin(int *arr, int len)
{
	if (arr == NULL || len < 1)
		return -1;
	int begin = 0, end = len - 1;
	//没有旋转的有序数组
	if (arr[begin] < arr[end])
		return arr[begin];

	while (begin < end)
	{
		int mid = begin + (end - begin) / 2; //防止溢出
		//最小值在右边
		if (arr[mid] > arr[begin])
			begin = mid;
		//最小值在左边
		else if (arr[mid] < arr[begin])
		{
			end = mid;
		}
		if (arr[begin] == arr[end] && arr[mid] == arr[end])
		{
			return LoopSearch(arr, begin, end);
		}
		if (end - begin == 1)
			return arr[end];
	}
}

int LoopSearch(int *arr, int begin, int end)
{
	int min = arr[begin];
	for (int i = begin + 1; i <= end; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

int main()
{
	int arr[] = { 4, 5, 6, 1, 2, 3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int min = FindMin(arr, len);
	cout << "最小值： " << min << endl;
	getchar();
	return 0;
}