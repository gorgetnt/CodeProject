#pragma once
#include<iostream>
using namespace std;
#include"CommonWorker.h"
#include"Manage.h"
#include"Boss.h"
class WorkManager
{
public:
	WorkManager();
	void ShowMenu();
	void AddWorkerInformation(BaseWorker* b_W, string Name, int Id, int Type, int& lenList);
	void ShowWorkerInformation(BaseWorker* b_W, int& lenList);
	void DeleteWorkerInformation(BaseWorker* b_W, int& lenList, int Id);
	void ChangeWorkerInformation(BaseWorker* b_W, int& lenList, int Id);
	void FindWorkerInformation(BaseWorker* b_W, int& lenList, int Id);
	void SortWorkerInformation(BaseWorker* b_W, int& lenList);
	void ClearWorkerInformation(BaseWorker* b_W, int& lenList);
	~WorkManager();
};
