#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
#define CEHUA 0;
#define MEISHU 1;
#define SHEJI 2;
class Worker
{
public:
	string m_Name;
	int m_Salary;
};
void SetWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];
		worker.m_Salary = rand() % 10000 + 10000;
		v.push_back(worker);
	}
}
void PrintWorker(vector<Worker>& v)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << it->m_Name << '\t' << "薪水:" << it->m_Salary << endl;
	}
}
void SetGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int code = rand() % 3;
		m.insert(pair<int, Worker>(code, *it));
	}
}
void ShowGroup(multimap<int, Worker>& m)
{
	cout << "美术部门:" << endl;
	int index = 0;
	for (multimap<int, Worker>::iterator Pos = m.find(1); Pos != m.end() && index < m.count(1); Pos++, index++)
	{
		cout << (*Pos).second.m_Name << '\t' << "薪水:" << (*Pos).second.m_Salary << endl;
	}
}
int main()
{
	vector<Worker>v;
	multimap<int, Worker>mm;
	SetWorker(v);
	PrintWorker(v);
	SetGroup(v, mm);
	ShowGroup(mm);
}