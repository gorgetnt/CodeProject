// arrayLearn_case.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
	//case1: 计算最终的小猪体重并输出
	int arr[5] = { 300,350,200,400,250 };
	int arrMax = arr[0];
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (arr[i] > arrMax)
		{
			arrMax = arr[i];
		}
	}
	cout << "最重的小猪体重是：" << arrMax << endl;
	//case2: 数组元素逆置
	int interNumber;
	for (int i = 0; i <= arrLen / 2; i++)
	{
		interNumber = arr[i + (arrLen / 2 - i) * 2];
		arr[i + (arrLen / 2 - i) * 2] = arr[i];
		arr[i] = interNumber;
	}
	for (int i = 0; i < arrLen; i++)
	{
		cout << arr[i] << '\t';
	}
	return 0;
}