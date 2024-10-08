// ClassLearn_DeepCopyAndLowCopy.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Person
{
public:
	//默认构造函数
	Person(int a, int h)
	{
		m_age = a;
		m_height = new int(h);//在堆区开辟一个int类型的数据
	}
	Person(const Person& p)//拷贝构造函数
	{
		m_age = p.m_age;
		m_height = new int(*p.m_height);//在拷贝构造函数中额外为需要赋值的对象开辟一个空间
	}
	~Person()//析构函数
	{
		if (m_height != NULL)
		{
			delete m_height;
		}
		m_height = NULL;
	}
	int m_age;
	int* m_height;
};
int main()
{
	Person p1(18, 160);
}