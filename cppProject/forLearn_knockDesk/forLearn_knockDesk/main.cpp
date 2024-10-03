#include<iostream>
using namespace std;
int main()
{
	int firstNumber, secondNumber;
	for (int i = 1; i < 101; i++)
	{
		if (i >= 10)
		{
			firstNumber = i / 10;
			secondNumber = i % 10;
			if (i % 7 == 0)
			{
				cout << "ÇÃ×À×Ó:" << i << endl;
			}
			else if (secondNumber == 7)
			{
				cout << "ÇÃ×À×Ó:" << i << endl;
			}
			else if (firstNumber == 7)
			{
				cout << "ÇÃ×À×Ó:" << i << endl;
			}
			else
			{
				cout << "²»ÇÃ×À×Ó:" << i << endl;
			}
		}
		else if (i == 7)
		{
			cout << "ÇÃ×À×Ó:" << i << endl;
		}
	}
	return 0;
}