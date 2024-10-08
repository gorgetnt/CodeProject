#pragma once
#include<iostream>
using namespace std;
template<class T>
//当开辟了堆区数据，一定要记得析构
//记得用this指针，规范编程步骤

class MyArray
{
public:
	MyArray(int m_L)
	{
		this->maxLen = m_L;
		this->len = 0;
		this->array = new T[this->maxLen];//开辟一个大小为maxLen的堆区数据空间
	}
	//定义拷贝构造函数
	MyArray(const MyArray& ar)
	{
		this->len = ar.len;
		this->maxLen = ar.maxLen;
		if (this->array != 0)
		{
			delete[]array;
			this->array = NULL;
		}
		this->array = new T[this->maxLen];
		for (int i = 0; i < this->len; i++)
		{
			this->array[i] = ar.array[i];
		}
	}
	void AddElement(T newElenment)//每次调用函数只允许添加一个元素,没有返回，直接修改array数据
	{
		this->len++;//增加了一个元素
		if (this->len >= this->maxLen)
		{
			cout << "数组中的元素超出其容量,添加元素失败！" << endl;
			return;
		}
		this->array[len - 1] = newElenment;
	}
	void DeleteElement()//每次调用就删除掉末位的元素
	{
		this->array[len - 1] = this->array[len];
		len--;
	}
	//解决浅拷贝问题,重载赋值运算符
	MyArray& operator=(MyArray& m_A)
	{
		this->len = m_A.len;
		this->maxLen = m_A.maxLen;
		if (this->array != 0)
		{
			delete[]array;
			this->array = NULL;
		}
		this->array = new T[this->maxLen];
		for (int i = 0; i < this->len; i++)
		{
			this->array[i] = m_A.array[i];
		}
		return *this;
	}
	int GetLen()
	{
		return len;
	}
	int GetMaxLen()
	{
		return maxLen;
	}
	//重载[]运算符
	T& operator[](int index)
	{
		if (index > this->len - 1)
		{
			cout << "超出索引范围!" << endl;
			exit(0);
		}
		return this->array[index];//用户自己注意不要超过索引
	}
	int maxLen;
	int len;
	T* array;
};