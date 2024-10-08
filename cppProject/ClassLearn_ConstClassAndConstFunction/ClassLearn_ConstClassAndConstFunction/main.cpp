#include<iostream>
using namespace std;
class Person
{
public:
	void Display() const//创建了一个常函数
		//相当于const person * const this，this指针的指向不可变，指向的值不可变
	{
		m_Age = 10;
	}
	mutable int m_Age;//添加muteble之后可以改变
	int m_Height;
};
int main()
{
	const Person p;//常对象只能调用常函数
}