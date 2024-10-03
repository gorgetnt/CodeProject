// arrayLearn_bubbleSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
	int a[9] = { 4, 2, 8, 0, 5, 7, 1, 3, 9 };
	int interNumber;
	//下面是冒泡排序
	for (int i = 0; i < 9; i++)
	{
		for (int j = i; j < 9; j++)
		{
			if (a[i] < a[j])
			{
				interNumber = a[i];
				a[i] = a[j];
				a[j] = interNumber;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		cout << a[i] << '\t';
	}
	/*
	int main() {
	int arr[9] = { 4,2,8,0,5,7,1,3,9 };

	for (int i = 0; i < 9 - 1; i++)
	{
		for (int j = 0; j < 9 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << endl;
	}

	system("pause");

	return 0;
}
	*/
	return 0;
}