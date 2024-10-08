#include "WorkManager.h"
#include"PostAndRes.h"
WorkManager::WorkManager()
{
}
WorkManager::~WorkManager()
{
}
void WorkManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void WorkManager::AddWorkerInformation(BaseWorker* b_W, string Name, int Id, int Type, int& lenList)
{
	/*
	* @brief:该函数是用来增加职工信息，一次只能增加一个职工，每次往职工表的最后面增加
	* @param:{
	* BaseWorker * b_w:该参数传入一个职工表的指针，从而让整个程序只需要维护一张职工表
	* int &lenList:该参数传入职工表的长度，同样可以让整个程序只维护一个长度
	* int type:用户在输入时只需要输入这个职工的工种，具体的实现通过类内直接实现
	}
	*/
	string Post;
	string Responsibility;
	BaseWorker* bb;
	if (Type == 1)
	{
		Post = PostCommonWorker;
		Responsibility = ResponsibilityCommonWorker;
		bb = new CommonWorker();
	}
	else if (Type == 2)
	{
		Post = PostManage;
		Responsibility = ResponsibilityManage;
		bb = new Manage();
	}
	else if (Type == 3)
	{
		Post = PostBoss;
		Responsibility = ResponsibilityBoss;
		bb = new Boss();
	}
	else
	{
		cout << "输入的职工类型有误，请重新输入" << endl;
		return;
	}
	lenList++;
	bb->SetWorkerAttribution(Name, Id, Post, Responsibility);
	b_W[lenList - 1] = *bb;
}
void WorkManager::ShowWorkerInformation(BaseWorker* b_W, int& lenList)
{
	for (int i = 0; i < lenList; i++)
	{
		b_W[i].ShowWorkerAttribution();
		cout << "------------------------------------------------------------" << endl;
	}
	if (lenList == 0)
	{
		cout << "职工表为空！" << endl;
	}
}
void WorkManager::DeleteWorkerInformation(BaseWorker* b_W, int& lenList, int Id)
{
	int flag = 1001;
	for (int i = 0; i < lenList; i++)
	{
		if (b_W[i].id == Id)
		{
			flag = i;
		}
	}
	if (flag == 1001)
	{
		cout << "error:职工表中没有你要删除的联系人！" << endl;
		return;
	}
	//通过类似冒泡的方式，填充需要删除的位置
	for (int i = flag; i <= lenList - flag; i++)
	{
		b_W[i] = b_W[i + 1];
	}
	lenList--;
}
void WorkManager::ChangeWorkerInformation(BaseWorker* b_W, int& lenList, int Id)
{
	/*
	* @brief:这个函数可以根据输入的姓名来找到通讯录中的联系人并修改
	* @param
	*/
	int flag = 1001;
	for (int i = 0; i < lenList; i++)
	{
		if (b_W[i].id == Id)
		{
			flag = i;
		}
	}
	if (flag == 1001)
	{
		cout << "职工表中没有你要修改的职工!" << endl;
		return;
	}
	else
	{
		cout << "你要修改的职工id:" << Id << '\t' << "如下:" << endl;
		cout << "姓名:" << b_W[flag].name << '\t' << "编号:" << b_W[flag].id << '\t' << "岗位:" << b_W[flag].post << '\t' << "职责:"
			<< b_W[flag].responsibility << endl;
		cout << "请输入你要修改的职工的信息:" << endl;
		cout << "修改后的姓名为:" << '\t';
		cin >> b_W[flag].name;
		cout << endl;
		//修改编号
		cout << "修改后的编号为:" << '\t';
		cin >> b_W[flag].id;
		cout << endl;
		//修改岗位和职责
		cout << "修改后的岗位职责类型为" << '\t';
		int Type;
		cin >> Type;
		string Post;
		string Responsibility;
		if (Type == 1)
		{
			Post = PostCommonWorker;
			Responsibility = ResponsibilityCommonWorker;
		}
		else if (Type == 2)
		{
			Post = PostManage;
			Responsibility = ResponsibilityManage;
		}
		else if (Type == 3)
		{
			Post = PostBoss;
			Responsibility = ResponsibilityBoss;
		}
		else
		{
			cout << "输入的职工类型有误，请重新输入" << endl;
			return;
		}
		b_W[flag].post = Post;
		b_W[flag].responsibility = Responsibility;
		cout << endl;
	}
}
void WorkManager::FindWorkerInformation(BaseWorker* b_W, int& lenList, int Id)
{
	/*
	* @brief:这个函数可以根据输入的姓名来找到通讯录中的联系人并修改
	* @param
	*/
	int flag = 1001;
	for (int i = 0; i < lenList; i++)
	{
		if (b_W[i].id == Id)
		{
			flag = i;
		}
	}
	if (flag == 1001)
	{
		cout << "职工表中没有你要查找的职工!" << endl;
		return;
	}
	else
	{
		cout << "你要查找的职工id:" << Id << '\t' << "如下:" << endl;
		cout << "姓名:" << b_W[flag].name << '\t' << "编号:" << b_W[flag].id << '\t' << "岗位:" << b_W[flag].post << '\t' << "职责:"
			<< b_W[flag].responsibility << endl;
		cout << "------------------------------------------------------------" << endl;
		cout << endl;
	}
}
void WorkManager::SortWorkerInformation(BaseWorker* b_W, int& lenList)
{
	int type;
	cout << "请选择要排序的方式:" << endl;
	cout << "1.升序排序" << endl;
	cout << "2.降序排序" << endl;
	cin >> type;
	if (type == 2)//降排序
	{
		for (int i = 0; i < lenList; i++)
		{
			for (int j = i; j < lenList; j++)
			{
				if (b_W[j].id <= b_W[j + 1].id)
				{
					BaseWorker temp;
					temp = b_W[j];
					b_W[j] = b_W[j + 1];
					b_W[j + 1] = temp;
				}
			}
		}
	}
	//生排序先不做了
	//else if (type == 1)//升排序
	//{
	//	for (int i = 0; i < lenList; i++)
	//	{
	//		for (int j = i; j < lenList; j++)
	//		{
	//			if (b_W[j].id <= b_W[j + 1].id)
	//			{
	//				BaseWorker temp;
	//				temp = b_W[j];
	//				b_W[j] = b_W[j + 1];
	//				b_W[j + 1] = temp;
	//			}
	//		}
	//	}
	//	//数组倒置
	//	BaseWorker *b_w_New=new BaseWorker[lenList];

	//}
}
void WorkManager::ClearWorkerInformation(BaseWorker* b_W, int& lenList)
{
	BaseWorker workerList[1000];
	b_W = workerList;
	lenList = 0;
}