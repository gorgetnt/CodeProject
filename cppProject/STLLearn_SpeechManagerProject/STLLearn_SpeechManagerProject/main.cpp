// STLLearn_SpeechManagerProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"SpeechManager.h"
#include"HeadFile.h"
void SetSpeekerVector(vector<Speeker>& v_Speeker)
{
	string nameSeed = "ABCDEFGHIJKL";
	string name;
	//创建十二个演讲者
	for (int i = 10001, j = 0; i < 10013; i++, j++)
	{
		name = "选手";
		name += nameSeed[j];
		Speeker s(name, i);
		v_Speeker.push_back(s);
	}
}
void PrintSpeeker(const Speeker& s_Speeker)
{
	cout << "编号：" << s_Speeker.m_Number << '\t' << "姓名：" << s_Speeker.m_Name << '\t' << "分数：" << s_Speeker.m_Score << endl;
	//设置了分数才可以用这个打印的代码，否则会报错
}
void TestSetSpeekerVector(vector<Speeker>& v_Speeker)
{
	for_each(v_Speeker.begin(), v_Speeker.end(), PrintSpeeker);
}
void MergeSpeeker(vector<Speeker>& v_Speeker, vector<Speeker>& Group1, vector<Speeker>& Group2)
{
	// 清空目标向量并重置大小
	v_Speeker.clear();
	v_Speeker.reserve(Group1.size() + Group2.size());
	//如果不遍历，最好用empty函数来转移
	// 将 Group1 的内容转移到 v_Speeker
	while (!Group1.empty()) {
		Speeker s = Group1.back();
		Group1.pop_back();
		v_Speeker.push_back(s);
	}

	// 将 Group2 的内容转移到 v_Speeker
	while (!Group2.empty()) {
		Speeker s = Group2.back();
		Group2.pop_back();
		v_Speeker.push_back(s);
	}
}
int main()
{
	vector<Speeker>v_Speeker;
	vector<Speeker>v_FirstGroup1;
	vector<Speeker>v_FirstGroup2;
	SpeechManager s;
	vector<Speeker>v_Speeker_second;
	s.loadRecord();
	s.showRecord();
	s.ShowMenu();
	int choice;
	while (1)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			SetSpeekerVector(v_Speeker);//用一个vector去接收会涉及到长度的设置问题
			s.SetFirstRace(v_Speeker, v_FirstGroup1, v_FirstGroup2);
			system("cls");
			MergeSpeeker(v_Speeker_second, v_FirstGroup1, v_FirstGroup2);
			s.SetSecondRace(v_Speeker_second, v_FirstGroup1, v_FirstGroup2);
			s.SaveSpeech();
			system("cls");
			s.ShowMenu();
			break;
		case 0:
			cout << "是否退出系统:" << endl;
			cout << "1.是" << endl;
			cout << "2.否" << endl;
			int c2;
			cin >> c2;
			if (c2 == 1)
			{
				exit(0);
			}
			cout << "未退出程序，请重新输入选择" << endl;
			break;
		default:
			break;
		}
	}
}