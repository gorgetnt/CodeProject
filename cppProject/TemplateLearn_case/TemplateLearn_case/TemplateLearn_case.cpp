// TemplateLearn_case.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
template<typename T>
void Sort(T* a, int len)
{
	T temp;
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			if (a[j] >= a[i])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int main()
{
	/*int a[10] = { 3,2,5,1,6,7,4,9,8,10 };*/
	char a[10] = { '3','2','5','1','6','7','4','9','8','11' };
	int len = sizeof(a) / sizeof(a[0]);

	Sort(a, len);
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << endl;
	}
}