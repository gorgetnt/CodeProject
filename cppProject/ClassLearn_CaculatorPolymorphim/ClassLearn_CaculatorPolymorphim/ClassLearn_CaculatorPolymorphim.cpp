// ClassLearn_CaculatorPolymorphim.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class AbstractCaculator
{
public:
	virtual void SetValue(double a, double b)//输入数据的操作可以直接继承
	{
		operatorNumber1 = a;
		operatorNumber2 = b;
	}
	virtual double Operate()//虚函数
	{
		double result = 0;
		return result;
	}
protected:
	double operatorNumber1;
	double operatorNumber2;
};
class AddCaculator :public AbstractCaculator
{
public:
	void SetValue(double a, double b)
	{
		this->operatorNumber1 = a;
		this->operatorNumber2 = b;
	}
	double Operate()
	{
		double result;
		result = this->operatorNumber1 + this->operatorNumber2;
		return result;
	}
};
class SubCaculator :public AbstractCaculator
{
public:
	void SetValue(double a, double b)
	{
		this->operatorNumber1 = a;
		this->operatorNumber2 = b;
	}
	double Operate()
	{
		double result;
		result = this->operatorNumber1 - this->operatorNumber2;
		return result;
	}
};
void Calulate(AbstractCaculator& absCaculator)
{
	double a;
	double b;
	cout << "请输入ab" << endl;
	cin >> a >> b;
	absCaculator.SetValue(a, b);
	double result = absCaculator.Operate();
	cout << "结果为:" << result << endl;
}
int main()
{
	AddCaculator addCaculator;
	Calulate(addCaculator);
}