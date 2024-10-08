#pragma once
#include "BaseWorker.h"
class Boss :
	public BaseWorker
{
	virtual void SetWorkerAttribution(string n, int i, string p, string r);
};
