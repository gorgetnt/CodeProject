#pragma once
#include<iostream>
using namespace std;
template<class T>
//�������˶������ݣ�һ��Ҫ�ǵ�����
//�ǵ���thisָ�룬�淶��̲���

class MyArray
{
public:
	MyArray(int m_L)
	{
		this->maxLen = m_L;
		this->len = 0;
		this->array = new T[this->maxLen];//����һ����СΪmaxLen�Ķ������ݿռ�
	}
	//���忽�����캯��
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
	void AddElement(T newElenment)//ÿ�ε��ú���ֻ�������һ��Ԫ��,û�з��أ�ֱ���޸�array����
	{
		this->len++;//������һ��Ԫ��
		if (this->len >= this->maxLen)
		{
			cout << "�����е�Ԫ�س���������,���Ԫ��ʧ�ܣ�" << endl;
			return;
		}
		this->array[len - 1] = newElenment;
	}
	void DeleteElement()//ÿ�ε��þ�ɾ����ĩλ��Ԫ��
	{
		this->array[len - 1] = this->array[len];
		len--;
	}
	//���ǳ��������,���ظ�ֵ�����
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
	//����[]�����
	T& operator[](int index)
	{
		if (index > this->len - 1)
		{
			cout << "����������Χ!" << endl;
			exit(0);
		}
		return this->array[index];//�û��Լ�ע�ⲻҪ��������
	}
	int maxLen;
	int len;
	T* array;
};