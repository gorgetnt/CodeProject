#include "BaseWorker.h"
void BaseWorker::SetWorkerAttribution(string n, int i, string p, string r)
{
}
void BaseWorker::ShowWorkerAttribution()
{
	cout << "编号:" << this->id << '\t' << "姓名：" << this->name << '\t' << "岗位:" << this->post << '\t' << "职责：" << this->responsibility << endl;
}