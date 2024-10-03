// dowhileLearn_caculateFlowers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int number, firstNumber, secondNumber, thirdNumber;
	number = 100;

	do
	{
		firstNumber = number / 100;
		secondNumber = (number / 10) % 10;
		thirdNumber = number % 10;
		if (pow(firstNumber, 3) + pow(secondNumber, 3) + pow(thirdNumber, 3) == number)
		{
			cout << "number=" << number << endl;
		}
		number++;
	} while (number < 999);
	return 0;
}