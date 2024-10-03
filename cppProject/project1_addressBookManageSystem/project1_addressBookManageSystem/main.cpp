// project1_addressBookManageSystem.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*1.添加联系人：每次添加往数组的最后面添加
   2.删除联系人：每次删除之后，要把所有联系人往前推，类似冒泡算法*/
#include <iostream>
using namespace std;
#include"StruckPeople.h"
#include"DisplayPeople.h"
#include"AppendPeople.h"
#include"DeletePeople.h"
#include"FindPeople.h"
#include"ModifyPeople.h"
#include"ClearPeople.h"
int main()
{
	//People p1 = { "卡密尔","女",18,"13131","皮尔特沃夫" };
	//People p2 = { "鳄鱼","男",30,"13111","恕瑞玛" };
	//People p3 = { "石头人","男",40,"13011","恕瑞玛" };
	//People p4 = { "诺手","男",34,"11111","诺克萨斯" };
	//People p[1000] = { p1,p2,p3 };//c+=初始化的数组长度要等于1000
	//int flag = 3;//flag记录现在通讯录中有多少个联系人
	//int& lenBook = flag;
	//cout << lenBook << endl;
	//Display(p, lenBook);
	//Append(p, lenBook, p4);
	//Display(p, lenBook);
	//cout << flag << endl;
	////测试删除功能
	////Delete(p, lenBook, "鳄鱼");
	////Display(p, lenBook);
	////测试查找功能
	//Find(p, lenBook, "刀妹");
	////测试修改功能
	///*Modify(p, lenBook, "鳄鱼");
	//Display(p, lenBook);*/
	////测试清空功能
	//Clear(p, lenBook);
	//Display(p, lenBook);
	int choose;
	People contactBook[1000] = {};
	int len = 0;
	int& lenBook = len;
	People p;//p存储需要增加的联系人
	string name;//name存储需要查找的联系人,需要删除的联系人,需要修改的联系人
	cout << "请输入你要进行的功能:" << endl;
	cout << "1.添加联系人" << '\t' << '\t' << '\t' << "2.显示联系人" << endl;
	cout << "3.删除联系人" << '\t' << '\t' << '\t' << "4.查找联系人" << endl;
	cout << "5.修改联系人" << '\t' << '\t' << '\t' << "6.清空联系人" << endl;
	cout << "7.退出系统" << endl;

	while (1)
	{
		cout << "输入你的选择:" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1://添加联系人
			cout << "请输入你要增加的联系人的信息:" << endl;
			cout << "姓名为:" << '\t';
			cin >> p.name;
			cout << endl;
			//修改性别
			cout << "性别为:" << '\t';
			cin >> p.gender;
			cout << endl;
			//修改年龄
			cout << "年龄为:" << '\t';
			cin >> p.age;
			cout << endl;
			//修改联系电话
			cout << "联系电话为:" << '\t';
			cin >> p.contackNumber;
			cout << endl;
			//修改家庭住址
			cout << "家庭住址为:" << '\t';
			cin >> p.address;
			cout << endl;
			Append(contactBook, lenBook, p);
			break;
		case 2://显示联系人
			Display(contactBook, lenBook);
			break;
		case 3://删除联系人
			cout << "请输入你要删除的联系人:" << endl;
			cin >> name;
			Delete(contactBook, lenBook, name);
			break;
		case 4://查找联系人
			cout << "请输入你要查找的联系人:" << endl;
			cin >> name;
			Find(contactBook, lenBook, name);
			break;
		case 5://修改联系人
			cout << "请输入你要修改的联系人:" << endl;
			cin >> name;
			Modify(contactBook, lenBook, name);
			break;
		case 6://清空联系人
			Clear(contactBook, lenBook);
			break;
		case 7://退出系统
			cout << "是否退出系统:" << endl;
			cin >> name;
			if (name == "是")
			{
				goto FLAG;
			}
			break;
		default:
			break;
		}
	}
FLAG:
	system("pause");
	return 0;
}