#include<iostream>
using namespace std;
class Cube
{
public:
	Cube(int a)
	{
		cout << "Cube的构造为" << a << endl;
	}
	void CaculateArea()
	{
		double area = 2 * m_H * m_L + 2 * m_H * m_W + 2 * m_L * m_W;
		cout << "面积为:" << area << endl;
	}
	void CaculateVolume()
	{
		double volume = m_H * m_L * m_W;
		cout << "体积为:" << volume << endl;
	}
	double m_H;
	double m_L;
	double m_W;
};
int main()
{
	Cube c1(10);//括号法
	Cube c2 = Cube(20);//显式法
	Cube c3 = 20;//隐式法
	return 0;
}