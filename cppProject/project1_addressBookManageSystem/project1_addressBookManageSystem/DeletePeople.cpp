#include "DeletePeople.h"
void Delete(People* p, int& lenBook, string name)
{
	/*
	* @brief:这个函数可以根据输入的姓名来删除通讯录中的联系人
	* @param People *p:传入一个通讯录的指针（可以直接修改通讯录的内容）
	*		string name:需要删除的联系人的姓名
	*/
	//遍历整个通讯录,找到需要删除的联系人的索引,一次只能删除一个联系人
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
		cout << "error:通讯录中没有你要删除的联系人！" << endl;
		return;
	}
	//通过类似冒泡的方式，填充需要删除的位置
	for (int i = flag; i <= lenBook - flag; i++)
	{
		p[i] = p[i + 1];
	}
	lenBook--;
}