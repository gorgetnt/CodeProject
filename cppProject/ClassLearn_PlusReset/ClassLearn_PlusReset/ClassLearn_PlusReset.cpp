//// ClassLearn_PlusReset.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//
//#include <iostream>
//using namespace std;
//class Test
//{
//public:
//	Test()
//	{
//	}
//	Test(int a, int b)
//	{
//		A = a;
//		B = b;
//	}
//
//	int A;
//	int B;
//private:
//	int C;
//	int D;
//};
//Test operator+(Test& t1, Test& t2)
//{
//	Test t;
//	t.A = t1.A + t2.A;
//	t.B = t1.B + t2.B;
//	return t;
//}
//ostream& operator<<(ostream& cout, Test& t)//重载左移运算符
//{
//	cout << "t的A=" << t.A << "t的B=" << t.B;
//	return cout;
//}
//int main()
//{
//	Test t1(10, 10);
//	Test t2(20, 20);
//	Test t3 = t1 + t2;
//	cout << t3 << endl;
//	return 0;
//}
#include<iostream>
using namespace std;
class Solution
{
public:
	int nthUglyNumber(int n, int a, int b, int c) {
		int count = 0;
		int arr[1000];
		int i = 1;
		system("pause");
		while (count < n)
		{
			cout << "count" << count << endl;
			if (i % a == 0 || i % b == 0 || i % c == 0)
			{
				arr[count] = i;
				count++;
			}
			i++;
		}
		cout << "第n个丑数为" << arr[n - 1];
		return arr[n - 1];
	}
};
int main()
{
	Solution s;
	int ret = s.nthUglyNumber(3, 2, 3, 5);
	cout << ret << endl;
	system("pause");
	return 0;
}