// pointerLearn.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
	//1、指针的定义
	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
	int* pOuter;
	int* pInter;
	int interNumber;
	for (int i = 0; i < 10; i++)
	{
		pOuter = &arr[i];
		for (int j = i; j < 10; j++)
		{
			pInter = &arr[j];
			if (*pOuter < *pInter)
			{
				interNumber = *pInter;
				*pInter = *pOuter;
				*pOuter = interNumber;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << '\t';
	}
	system("pause");

	return 0;
}