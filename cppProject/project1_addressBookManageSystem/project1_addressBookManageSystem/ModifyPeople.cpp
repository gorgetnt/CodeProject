#include "ModifyPeople.h"
void Modify(People* p, int& lenBook, string name)
{
	/*
	* @brief:����������Ը���������������ҵ�ͨѶ¼�е���ϵ�˲��޸�
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
		cout << "ͨѶ¼��û����Ҫ�޸ĵ���ϵ��!" << endl;
		return;
	}
	else
	{
		cout << "��Ҫ�޸ĵ���ϵ��:" << name << '\t' << "����:" << endl;
		cout << "����:" << p[flag].name << '\t' << "�Ա�:" << p[flag].gender << '\t' << "����:" << p[flag].age << '\t' << "��ϵ�绰:"
			<< p[flag].contackNumber
			<< '\t' << "��ͥסַ:" << p[flag].address << endl;
		cout << "��������Ҫ�޸ĵ���ϵ�˵���Ϣ:" << endl;
		cout << "�޸ĺ������Ϊ:" << '\t';
		cin >> p[flag].name;
		cout << endl;
		//�޸��Ա�
		cout << "�޸ĺ���Ա�Ϊ:" << '\t';
		cin >> p[flag].gender;
		cout << endl;
		//�޸�����
		cout << "�޸ĺ������Ϊ:" << '\t';
		cin >> p[flag].age;
		cout << endl;
		//�޸���ϵ�绰
		cout << "�޸ĺ����ϵ�绰Ϊ:" << '\t';
		cin >> p[flag].contackNumber;
		cout << endl;
		//�޸ļ�ͥסַ
		cout << "�޸ĺ�ļ�ͥסַΪ:" << '\t';
		cin >> p[flag].address;
		cout << endl;
	}
}