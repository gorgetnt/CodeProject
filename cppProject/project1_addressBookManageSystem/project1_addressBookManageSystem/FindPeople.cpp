#include "FindPeople.h"
void Find(People* p, int& lenBook, string name)
{
	/*
	* @brief:����������Ը���������������ҵ�ͨѶ¼�е���ϵ�˲���ӡ
	* @param
	*/
	int flag = 1001;
	for (int i = 0; i < lenBook; i++)
	{
		if (p[i].name == name)
		{
			flag = i;
		}
	}
	if (flag == 1001)
	{
		cout << "ͨѶ¼��û����Ҫ���ҵ���ϵ��!" << endl;
		return;
	}
	else
	{
		cout << "��Ҫ���ҵ���ϵ��:" << name << '\t' << "����:" << endl;
		cout << "����:" << p[flag].name << '\t' << "�Ա�:" << p[flag].gender << '\t' << "����:" << p[flag].age << '\t' << "��ϵ�绰:"
			<< p[flag].contackNumber
			<< '\t' << "��ͥסַ:" << p[flag].address << endl;
	}
}