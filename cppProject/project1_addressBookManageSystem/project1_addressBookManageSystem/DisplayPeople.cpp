#include<iostream>
using namespace std;
#include"DisplayPeople.h"
#include"StruckPeople.h"
void Display(People* p, int& lenBook)
{
	/*
	* @brief 该函数是为了展示所有的联系人
	* @param People p 传入一个People结构体的数组
	*/
	if (lenBook == 0)
	{
		cout << "通讯录为空" << endl;
		return;
	}
	for (int i = 0; i < lenBook; i++)
	{
		cout << "姓名:" << p[i].name << '\t' << "性别:" << p[i].gender << '\t' << "年龄:" << p[i].age << '\t' << "联系电话:" << p[i].contackNumber
			<< '\t' << "家庭住址:" << p[i].address << endl;
	}
}