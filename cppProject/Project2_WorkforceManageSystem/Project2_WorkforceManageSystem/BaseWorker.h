#pragma once
#include<iostream>
using namespace std;
#include<string>
class BaseWorker
{
public:
	virtual void SetWorkerAttribution(string n, int i, string p, string r);
	void ShowWorkerAttribution();
	int id;
	string name;
	string post;
	string responsibility;
};
