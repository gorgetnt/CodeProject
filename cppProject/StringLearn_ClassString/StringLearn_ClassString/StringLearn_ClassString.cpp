// StringLearn_ClassString.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
using namespace std;

int main()
{
	string s1("hello world");//string构造函数
	cout << s1 << endl;
	string s2 = s1;//string拷贝构造
	s1.append(s2);
	cout << s1 << endl;
	cout << s1.substr(0, 3) << endl;
}