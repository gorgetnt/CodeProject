#include "FindPeople.h"
void Find(People* p, int& lenBook, string name)
{
	/*
	* @brief:这个函数可以根据输入的姓名来找到通讯录中的联系人并打印
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
		cout << "通讯录中没有你要查找的联系人!" << endl;
		return;
	}
	else
	{
		cout << "你要查找的联系人:" << name << '\t' << "如下:" << endl;
		cout << "姓名:" << p[flag].name << '\t' << "性别:" << p[flag].gender << '\t' << "年龄:" << p[flag].age << '\t' << "联系电话:"
			<< p[flag].contackNumber
			<< '\t' << "家庭住址:" << p[flag].address << endl;
	}
}