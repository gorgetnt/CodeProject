#include "ModifyPeople.h"
void Modify(People* p, int& lenBook, string name)
{
	/*
	* @brief:这个函数可以根据输入的姓名来找到通讯录中的联系人并修改
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
		cout << "通讯录中没有你要修改的联系人!" << endl;
		return;
	}
	else
	{
		cout << "你要修改的联系人:" << name << '\t' << "如下:" << endl;
		cout << "姓名:" << p[flag].name << '\t' << "性别:" << p[flag].gender << '\t' << "年龄:" << p[flag].age << '\t' << "联系电话:"
			<< p[flag].contackNumber
			<< '\t' << "家庭住址:" << p[flag].address << endl;
		cout << "请输入你要修改的联系人的信息:" << endl;
		cout << "修改后的姓名为:" << '\t';
		cin >> p[flag].name;
		cout << endl;
		//修改性别
		cout << "修改后的性别为:" << '\t';
		cin >> p[flag].gender;
		cout << endl;
		//修改年龄
		cout << "修改后的年龄为:" << '\t';
		cin >> p[flag].age;
		cout << endl;
		//修改联系电话
		cout << "修改后的联系电话为:" << '\t';
		cin >> p[flag].contackNumber;
		cout << endl;
		//修改家庭住址
		cout << "修改后的家庭住址为:" << '\t';
		cin >> p[flag].address;
		cout << endl;
	}
}