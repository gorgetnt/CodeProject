#include "ClearPeople.h"
void Clear(People* p, int& lenBook)
{
	People p1[1000] = {};
	cout << "�Ƿ�ȷ��Ҫ���ͨѶ¼(���ɳ���)" << endl;
	string sure;
	cin >> sure;
	if (sure == "��")
	{
		p = p1;
		lenBook = 0;
		cout << "�����ͨѶ¼" << endl;
	}
	else
	{
		return;
	}
}