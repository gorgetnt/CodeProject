#include<iostream>
using namespace std;
int main()
{
	int pigA, pigB, pigC;
	cout << "请分别输入ABC小猪的重量：" << endl;
	cin >> pigA >> pigB >> pigC;
	int flag;
	if (pigA >= pigB && pigA >= pigC)//A最大 
	{
		flag = 1;
	}
	if (pigB >= pigA && pigB >= pigC)//B最大 
	{
		flag = 2;
	}
	if (pigC >= pigA && pigC >= pigB)//C最大 
	{
		flag = 3;
	}
	switch (flag)
	{
	case 1:
		if (pigB >= pigC)
		{
			cout << "A>B>C" << '\t' << pigA << '\t' << pigB << '\t' << pigC << '\t';
		}
		else
		{
			cout << "A>C>B" << '\t' << pigA << '\t' << pigC << '\t' << pigB << '\t';
		}
		break;
	case 2:
		if (pigA >= pigC)
		{
			cout << "B>A>C" << '\t' << pigB << '\t' << pigA << '\t' << pigC << '\t';
		}
		else
		{
			cout << "B>C>A" << '\t' << pigB << '\t' << pigC << '\t' << pigA << '\t';
		}
		break;
	case 3:
		if (pigA >= pigB)
		{
			cout << "C>A>B" << '\t' << pigC << '\t' << pigA << '\t' << pigB << '\t';
		}
		else
		{
			cout << "C>B>A" << '\t' << pigC << '\t' << pigB << '\t' << pigA << '\t';
		}
		break;

	}

	return 0;
}