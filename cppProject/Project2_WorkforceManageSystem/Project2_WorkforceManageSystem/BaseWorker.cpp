#include "BaseWorker.h"
void BaseWorker::SetWorkerAttribution(string n, int i, string p, string r)
{
}
void BaseWorker::ShowWorkerAttribution()
{
	cout << "���:" << this->id << '\t' << "������" << this->name << '\t' << "��λ:" << this->post << '\t' << "ְ��" << this->responsibility << endl;
}