// TemplateLearn_CommonArrayCase.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#include"myArray.hpp"
int main()
{
	MyArray<int>myArr(100);
	myArr.AddElement(10);
	cout << myArr.GetLen() << endl;
	cout << myArr[10] << endl;
	return 0;
}