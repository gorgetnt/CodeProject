#include"AppendPeople.h"
void Append(People* p, int& lenBook, People newP)
{
	/*
	* @brief:这个函数是为了添加联系人进入通讯录
	* @param People p:传入整个通讯录
	*		int lenBook:传入通讯录中有的联系人的数目
	*		People newP:传入要增加的联系人
	* @return:返回增加了联系人后的通讯录(指针)
	*
	*/
	lenBook++;
	p[lenBook - 1] = newP;
}