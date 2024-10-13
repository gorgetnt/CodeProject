// STLAlgorithmLearn.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
#define vb v_Person.begin()
#define ve v_Person.end()
//1.内置数据类型
vector<int> MakeIntData()//创建数据
{
	vector<int>* v_Int = new vector<int>;
	for (int i = 0; i < 10; i++)
	{
		v_Int->push_back(i);
	}
	return *v_Int;
}
void ShuffleIntData(vector<int>& v)//打乱数据
{
	random_shuffle(v.begin(), v.end());
}
void PrintIntData(int a)
{
	cout << a << '\t';
}
//2.自定义数据类型
class Person
{
public:
	Person()
	{
	}
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
	bool operator==(const Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
vector<Person> MakePersonData()
{
	vector<Person>* v_Person = new vector<Person>;//容器的本质是对象不是数组,如果要在函数中创建全局对象，必须要开辟到堆区，或者使用静态对象
	Person p1("张飞", 20);
	Person p2("刘备", 25);
	Person p3("关羽", 31);
	Person p4("赵云", 45);
	Person p5("黄忠", 22);
	Person p6("姜维", 31);
	v_Person->push_back(p1);
	v_Person->push_back(p2);
	v_Person->push_back(p3);
	v_Person->push_back(p4);
	v_Person->push_back(p5);
	v_Person->push_back(p6);
	return *v_Person;
}
void PrintPersonData(const Person& p)
{
	cout << "姓名:  " << p.m_Name << '\t' << "年龄:  " << p.m_Age << endl;
}
class TransformPred
{
public:
	Person operator()(const Person& p)
	{
		return p;
	}
};
class FindIfPred
{
public:
	bool operator()(const Person& p)
	{
		if (p.m_Age >= 20)
		{
			return true;
		}
	}
};
class SortPred
{
public:
	bool operator()(const Person& p1, const Person& p2)
	{
		if (p1.m_Name == p2.m_Name)
		{
			return p1.m_Age > p2.m_Age;
		}
		else
		{
			return p1.m_Age > p2.m_Age;
		}
	}
};
int main()
{
	Person p3("关羽", 31);
	Person p4("赵云", 45);
	//1.1.遍历算法
	vector<Person>v_Person = MakePersonData();
	cout << "以下是for_each算法的测试:" << endl;
	for_each(v_Person.begin(), v_Person.end(), PrintPersonData);//for_each算法是取每个元素，放入func中执行
	//1.2.搬运算法transform
	cout << "以下是transform算法的测试:" << endl;
	vector<Person>v_Person_New;
	v_Person_New.resize(v_Person.size());//resize时需要默认构造函数

	transform(vb, ve, v_Person_New.begin(), TransformPred());//transform算法调用fuc函数，输入v_Person
	for_each(v_Person_New.begin(), v_Person_New.end(), PrintPersonData);
	//的元素，返回值赋值给v_Person_New
	//2.查找算法：
	//2.1 find算法
	cout << "以下是find算法的测试:" << endl;
	vector<Person>::iterator it = find(vb, ve, p3);//find算法是用==运算符来判断，因此自定数据类型需要重载==运算符
	cout << it->m_Name << it->m_Age << endl;
	//2.2 find_if算法
	cout << "以下是find_if算法的测试:" << endl;
	vector<Person>::iterator it1 = find_if(vb, ve, FindIfPred());//find_if算法用pred谓词来判断数据类型是否符合情况，返回一个bool值用于if函数判断
	cout << it1->m_Name << it1->m_Age << endl;
	//2.3 cout算法
	cout << "以下是cout算法的测试:" << endl;
	vector<Person>::iterator it2 = find(vb, ve, p3);//find算法是用==运算符来判断，因此自定数据类型需要重载==运算符
	cout << it2->m_Name << it2->m_Age << endl;
	//2.3 cout_if算法
	//cout_if、cout和find，find_if算法很像
	//3. 排序算法
	//3.1 sort算法
	cout << "以下是sort算法的测试:" << endl;
	sort(vb, ve, SortPred());//sort算法也要传入一个谓词，返回值是bool，参数有两个，是相同类型的数据
	for_each(vb, ve, PrintPersonData);
	//3.2 random_shffule
	cout << "以下是random_shffule算法的测试:" << endl;
	random_shuffle(vb, ve);//random_shuffle算法传入两个迭代器即可
	for_each(vb, ve, PrintPersonData);
	//3.2 merge算法
	//3.3 reverse算法
	//4. 拷贝和替换算法
	//4.1 copy算法
	cout << "以下是copy算法的测试:" << endl;
	vector<Person>v_Copy;
	v_Copy.resize(v_Person.size());
	copy(vb, ve, v_Copy.begin());
	for_each(v_Copy.begin(), v_Copy.end(), PrintPersonData);
	//4.2 repalce算法
	cout << "以下是repalce算法的测试:" << endl;
	replace(vb, ve, p3, p4);
	for_each(vb, ve, PrintPersonData); //replace和replace_if和find、find_if算法都很相似
}