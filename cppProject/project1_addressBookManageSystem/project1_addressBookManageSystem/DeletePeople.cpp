#include "DeletePeople.h"
void Delete(People* p, int& lenBook, string name)
{
	/*
	* @brief:����������Ը��������������ɾ��ͨѶ¼�е���ϵ��
	* @param People *p:����һ��ͨѶ¼��ָ�루����ֱ���޸�ͨѶ¼�����ݣ�
	*		string name:��Ҫɾ������ϵ�˵�����
	*/
	//��������ͨѶ¼,�ҵ���Ҫɾ������ϵ�˵�����,һ��ֻ��ɾ��һ����ϵ��
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
		cout << "error:ͨѶ¼��û����Ҫɾ������ϵ�ˣ�" << endl;
		return;
	}
	//ͨ������ð�ݵķ�ʽ�������Ҫɾ����λ��
	for (int i = flag; i <= lenBook - flag; i++)
	{
		p[i] = p[i + 1];
	}
	lenBook--;
}