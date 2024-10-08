// Project2_WorkforceManageSystem.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#include"WorkManager.h"
#include"PostAndRes.h"
#include"CommonWorker.h"
#include"Manage.h"
#include"Boss.h"
void TestWorkMagenaer()
{
	WorkManager w_M;
	w_M.ShowMenu();
}
void TestPostAndRes()
{
	cout << ResponsibilityBoss << endl;
}
void TestWorkerClass()
{
	BaseWorker* b1 = new CommonWorker();
	b1->SetWorkerAttribution("张三", 1, PostCommonWorker, ResponsibilityCommonWorker);
	cout << b1->name << b1->responsibility << endl;
}
void TestAddWorker()
{
	//基类的数组可以存储其子类
	int len = 0;
	BaseWorker workerList[1000];
	WorkManager wm;
	wm.AddWorkerInformation(workerList, "张三", 2, 1, len);
	cout << workerList[len].name << endl;
	wm.AddWorkerInformation(workerList, "李四", 2, 2, len);
	cout << workerList[len].responsibility << endl;
}
void TestShowWorker()
{
	int len = 0;
	BaseWorker workerList[1000];
	WorkManager wm;
	wm.AddWorkerInformation(workerList, "张三", 2, 1, len);
	wm.AddWorkerInformation(workerList, "李四", 3, 2, len);
	wm.ShowWorkerInformation(workerList, len);
}
void TestDeleteWorker()
{
	int len = 0;
	BaseWorker workerList[1000];
	WorkManager wm;
	wm.AddWorkerInformation(workerList, "张三", 2, 1, len);
	wm.AddWorkerInformation(workerList, "李四", 3, 2, len);
	wm.ShowWorkerInformation(workerList, len);
	cout << "-------------------" << endl;
	wm.DeleteWorkerInformation(workerList, len, 2);
	wm.ShowWorkerInformation(workerList, len);
}
void TestChangeWorker()
{
	int len = 0;
	BaseWorker workerList[1000];
	WorkManager wm;
	wm.AddWorkerInformation(workerList, "张三", 2, 1, len);
	wm.AddWorkerInformation(workerList, "李四", 3, 2, len);
	wm.ShowWorkerInformation(workerList, len);
	cout << "-------------------" << endl;
	wm.ChangeWorkerInformation(workerList, len, 2);
	wm.ShowWorkerInformation(workerList, len);
}
void TestFindWorker()
{
	int len = 0;
	BaseWorker workerList[1000];
	WorkManager wm;
	wm.AddWorkerInformation(workerList, "张三", 2, 1, len);
	wm.AddWorkerInformation(workerList, "李四", 3, 2, len);
	wm.ShowWorkerInformation(workerList, len);
	wm.FindWorkerInformation(workerList, len, 3);
}
void TestSortWorker()
{
	int len = 0;
	BaseWorker workerList[1000];
	WorkManager wm;
	wm.AddWorkerInformation(workerList, "张三", 5, 1, len);
	wm.AddWorkerInformation(workerList, "李四", 2, 2, len);
	wm.AddWorkerInformation(workerList, "王五", 1, 3, len);
	wm.AddWorkerInformation(workerList, "赵六", 3, 1, len);
	wm.ShowWorkerInformation(workerList, len);
	wm.SortWorkerInformation(workerList, len);
	wm.ShowWorkerInformation(workerList, len);
	wm.ClearWorkerInformation(workerList, len);
	wm.ShowWorkerInformation(workerList, len);
}
int main()
{
	int choice;
	while (1)
	{
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			cout << "是否确认退出系统:" << endl;
			cout << "1.退出" << endl;
			cout << "2.取消" << endl;
			int c;
			cin >> c;
			if (c == 1)
			{
				exit(0);
			}
			break;
		case 1://添加职工
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}