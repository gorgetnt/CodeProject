#include<iostream>
using namespace std;
class Person
{
public:
	void Display() const//������һ��������
		//�൱��const person * const this��thisָ���ָ�򲻿ɱ䣬ָ���ֵ���ɱ�
	{
		m_Age = 10;
	}
	mutable int m_Age;//���muteble֮����Ըı�
	int m_Height;
};
int main()
{
	const Person p;//������ֻ�ܵ��ó�����
}