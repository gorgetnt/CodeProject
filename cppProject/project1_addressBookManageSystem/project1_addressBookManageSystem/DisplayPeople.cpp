#include<iostream>
using namespace std;
#include"DisplayPeople.h"
#include"StruckPeople.h"
void Display(People* p, int& lenBook)
{
	/*
	* @brief �ú�����Ϊ��չʾ���е���ϵ��
	* @param People p ����һ��People�ṹ�������
	*/
	if (lenBook == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
		return;
	}
	for (int i = 0; i < lenBook; i++)
	{
		cout << "����:" << p[i].name << '\t' << "�Ա�:" << p[i].gender << '\t' << "����:" << p[i].age << '\t' << "��ϵ�绰:" << p[i].contackNumber
			<< '\t' << "��ͥסַ:" << p[i].address << endl;
	}
}