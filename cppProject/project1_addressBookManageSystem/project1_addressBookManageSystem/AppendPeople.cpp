#include"AppendPeople.h"
void Append(People* p, int& lenBook, People newP)
{
	/*
	* @brief:���������Ϊ�������ϵ�˽���ͨѶ¼
	* @param People p:��������ͨѶ¼
	*		int lenBook:����ͨѶ¼���е���ϵ�˵���Ŀ
	*		People newP:����Ҫ���ӵ���ϵ��
	* @return:������������ϵ�˺��ͨѶ¼(ָ��)
	*
	*/
	lenBook++;
	p[lenBook - 1] = newP;
}