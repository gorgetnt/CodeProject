// DockerLearn_Case.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
class Sporter
{
public:
	Sporter(char n)
	{
		this->name = n;
	}
	char name;
	deque<double> score;
	double TotalScore()
	{
		double totalScore;
		for (deque<double>::iterator it = this->score.begin(); it != this->score.end(); it++)
		{
			totalScore += *it;
		}
		return totalScore;
	}
	void SortSore()
	{
		sort(score.begin(), score.end());
		score.pop_back();
		score.pop_front();
	}
	double CalcuMean()
	{
		double mean;
		mean = TotalScore() / score.size();
		return mean;
	}
	void PrintScore()
	{
		for (deque<double>::iterator it = this->score.begin(); it != this->score.end(); it++)
		{
			cout << *it << '\t';
		}
		cout << endl;
	}
};
void SetScore(Sporter& s)//传入一个sporter对象，然后设置他的分数，遍历设置
{
	double d_B = 10;
	for (int i = 0; i < 10; i++)
	{
		s.score.push_back(d_B);
		d_B /= 2;
	}
}
vector<Sporter> SetSporter()//返回一个sporter的容器
{
	string name = "ABCDEFGHIJ";
	vector<Sporter> sporters;
	for (int i = 0; i < 10; i++)
	{
		Sporter s(name[i]);
		SetScore(s);
		sporters.push_back(s);
	}
	//sporters[1].PrintScore();//vector是堆区数据，代码运行后，sporters被销毁，无法再返回引用，可以重新开辟一片空间
	return sporters;
}
int main()
{
	vector<Sporter> s;
	s = SetSporter();
	s[1].PrintScore();
	s[1].SortSore();
	s[1].PrintScore();
}