#include<iostream>
using namespace std;
class Cube
{
public:
	Cube(int a)
	{
		cout << "Cube�Ĺ���Ϊ" << a << endl;
	}
	void CaculateArea()
	{
		double area = 2 * m_H * m_L + 2 * m_H * m_W + 2 * m_L * m_W;
		cout << "���Ϊ:" << area << endl;
	}
	void CaculateVolume()
	{
		double volume = m_H * m_L * m_W;
		cout << "���Ϊ:" << volume << endl;
	}
	double m_H;
	double m_L;
	double m_W;
};
int main()
{
	Cube c1(10);//���ŷ�
	Cube c2 = Cube(20);//��ʽ��
	Cube c3 = 20;//��ʽ��
	return 0;
}