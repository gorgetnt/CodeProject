#pragma once
#include"HeadFile.h"
#include"Speeker.h"
class SpeechManager
{
public:
	SpeechManager();

	void ShowMenu();
	void SetFirstRace(vector<Speeker>& v_Speeker, vector<Speeker>& Group1, vector<Speeker>& Group2);
	void HandSetSpeekerScore(vector<Speeker>& Group1, vector<Speeker>& Group2);//这个函数要重载
	void AutoSetSpeekerScore(vector<Speeker>& Group1, vector<Speeker>& Group2);//这个函数要重载
	void SetSecondRace(vector<Speeker>& v_Speeker, vector<Speeker>& Group1, vector<Speeker>& Group2);
	void SaveSpeech();
	void loadRecord();
	vector<Speeker> Winner;
	bool fileIsEmpty;
	map<int, vector<string>> m_Record;
	void showRecord();
	~SpeechManager();
};
