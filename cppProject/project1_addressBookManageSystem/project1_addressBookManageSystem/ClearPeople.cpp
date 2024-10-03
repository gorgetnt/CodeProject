#include "ClearPeople.h"
void Clear(People* p, int& lenBook)
{
	People p1[1000] = {};
	cout << "是否确认要清空通讯录(不可撤回)" << endl;
	string sure;
	cin >> sure;
	if (sure == "是")
	{
		p = p1;
		lenBook = 0;
		cout << "已清空通讯录" << endl;
	}
	else
	{
		return;
	}
}