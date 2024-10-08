// ClassLearn_Caculator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
//1.普通方法实现计算器
class Aaculator
{
public:
	double AddOperate(double a, double b)
	{
		m_A = a;
		m_B = b;
		cout << "结果为:" << m_A + m_B << endl;
		return m_A + m_B;
	}
private:
	double m_A;
	double m_B;
}add, sub, mul, divi;
int main()
{
	double firstNumber;
	double secondNumber;
	int choose;
	cout << "输入第一个数:" << endl;
	cin >> firstNumber;
	cout << "输入第二个数:" << endl;
	cin >> secondNumber;
	cout << "请输入选择:" << endl;

	cout << "1.加法" << '\t' << "2.减法" << endl;
	cout << "3.乘法" << '\t' << "4.除法法" << endl;
	cin >> choose;
	switch (choose)
	{
	case 1:
		add.AddOperate(firstNumber, secondNumber);
		break;
	default:
		break;
	}
}