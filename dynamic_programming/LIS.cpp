/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// LIS (Longest Increasing Subsequence)
// For example:
// length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6
// and LIS is {10, 22, 33, 50, 60, 80}.
// Dynamic Programming(tabulation) can be implemented.

#include <iostream>

using namespace std;

/* lis()返回长度为n的数组arr[]的最长递增子序列长度 */
int lis(int arr[], int n)
{
	int lis[n];
	int max = 0;

	// 初始化所有位置LIS值
	for (int i = 0; i < n; ++i)
	{
		lis[i] = 1;
	}

	// 自下而上计算最优LIS值
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
			}
		}
	}

	// 选择LIS最大值
	for (int i = 0; i < n; ++i)
	{
		if (max < lis[i])
		{
			max = lis[i];
		}
	}

	return max;
}

int main(int argc, char const *argv[])
{
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Length of lis is " << lis(arr, n) << endl;
	return 0;
}