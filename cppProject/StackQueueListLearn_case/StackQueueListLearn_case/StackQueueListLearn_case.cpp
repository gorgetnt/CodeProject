#include <iostream>
#include<stack>
using namespace std;
#include<queue>
#include<string>
#include<list>
#include<set>
#include<map>
class Person
{
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	string m_Name;
	int m_Age;
	int m_Height;
};
class MyCompare
{
public:
	bool operator()(const Person& p1, const Person& p2)const
	{
		return p1.m_Age < p2.m_Age;
	}
};
void LearnStack()
{
	stack<Person> s1;
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);

	s1.push(p1);
	s1.push(p2);
	s1.push(p3);
	s1.push(p4);
	s1.push(p5);
	s1.push(p6);

	//遍历他
	while (s1.empty() == 0)
	{
		cout << "姓名:  " << s1.top().m_Name << "  年龄:  " << s1.top().m_Age << "  身高：  " << s1.top().m_Height << endl;
		s1.pop();
	}
}
void LearnList()
{
	list<Person> s1;
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);

	s1.push_back(p1);
	s1.push_back(p2);
	s1.push_back(p3);
	s1.push_back(p4);
	s1.push_back(p5);
	s1.push_back(p6);

	for (list<Person>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "姓名:  " << (*it).m_Name << "  年龄:  " << (*it).m_Age << "  身高：  " << (*it).m_Height << endl;
	}
	list<Person>s2;
	s2 = s1;

	for (list<Person>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << "姓名:  " << (*it).m_Name << "  年龄:  " << (*it).m_Age << "  身高：  " << (*it).m_Height << endl;
	}

	//插入和删除操作
	Person p7("青钢影", 400, 200);
	list<Person>::iterator it = s1.begin();
	it++;
	it++;
	s1.insert(it, p7);
	for (list<Person>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "姓名:  " << (*it).m_Name << "  年龄:  " << (*it).m_Age << "  身高：  " << (*it).m_Height << endl;
	}
}
bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_Age != p2.m_Age)
	{
		return p1.m_Age < p2.m_Age;
	}
	return p1.m_Height < p2.m_Height;
}
void ListSort()
{
	list<Person> s1;
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);

	s1.push_back(p1);
	s1.push_back(p2);
	s1.push_back(p3);
	s1.push_back(p4);
	s1.push_back(p5);
	s1.push_back(p6);

	s1.sort(myCompare);
	for (list<Person>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "姓名:  " << (*it).m_Name << "  年龄:  " << (*it).m_Age << "  身高：  " << (*it).m_Height << endl;
	}
}
void SetLearn()
{
	set<Person, MyCompare>s1;
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	s1.insert(p5);
	s1.insert(p6);

	for (set<Person>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << it->m_Name << it->m_Age << it->m_Height << endl;
	}
	//size,empty,swap
	cout << s1.size() << endl;
	cout << s1.empty() << endl;
	//find,count
	set<Person>::iterator it = s1.find(p5);
	if (it != s1.end())
	{
		cout << "--------------------------------------------------" << endl;
		cout << it->m_Name << it->m_Age << it->m_Height << endl;
	}
}
void PairLearn()
{
	pair<string, int>p1 = make_pair("你好", 11);
	cout << p1.first << p1.second << endl;
}
void MapLearn()
{
	map<int, int >m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(5, 50));

	cout << m1.size() << endl;
	for (map<int, int>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << it->first << endl;
	}
	cout << "--------------------------" << endl;
	cout << m1.count(2) << endl;
	cout << m1.find(4)->second << endl;
}
int main()
{
	MapLearn();
}