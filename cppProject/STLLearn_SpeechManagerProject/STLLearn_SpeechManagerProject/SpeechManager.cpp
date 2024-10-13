#include "SpeechManager.h"
#include <random>
void PrinSpeeker(const Speeker& s_Speeker)
{
	cout << "��ţ�" << s_Speeker.m_Number << '\t' << "������" << s_Speeker.m_Name << '\t' << "������" << s_Speeker.m_Score << endl;
	//�����˷����ſ����������ӡ�Ĵ��룬����ᱨ��
}
bool SortSpeeker(const  Speeker& s1, const Speeker& s2)//��������
{
	return s1.m_Score >= s2.m_Score;
}
SpeechManager::SpeechManager()
{
}
void SpeechManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void SpeechManager::SetFirstRace(vector<Speeker>& v_Speeker, vector<Speeker>& Group1, vector<Speeker>& Group2)
{
	//��һ�ֱ���Ҫ���������У�
	for_each(v_Speeker.begin(), v_Speeker.end(), PrinSpeeker);
	system("pause");
	//��ǩ�����飨��������������vector�ֵ�����vector����ȥ�������֣����ַ�������Ϊ����������ֵ��
	random_shuffle(v_Speeker.begin(), v_Speeker.end());//����˳��
	for_each(v_Speeker.begin(), v_Speeker.end(), PrinSpeeker);
	system("pause");
	//2.���飬Ҳ������copy����
	int size = v_Speeker.size();
	for (int i = 0; i < size / 2; i++)//ÿ��forѭ��������
	{
		Speeker s = v_Speeker.back();
		v_Speeker.pop_back();
		Group1.push_back(s);
	}
	for (int i = 0; i < size / 2; i++)
	{
		Speeker s = v_Speeker.back();
		v_Speeker.pop_back();
		Group2.push_back(s);
	}
	//3.���֣����ֶ���д����������
	//3.1 ��Ϊ����
	//HandSetSpeekerScore(Group1, Group2);
	//3.2 �������
	AutoSetSpeekerScore(Group1, Group2);
	cout << "��һ�飺" << endl;
	for_each(Group1.begin(), Group1.end(), PrinSpeeker);
	cout << "�ڶ��飺" << endl;
	for_each(Group2.begin(), Group2.end(), PrinSpeeker);
	system("pause");
	//4.ѡ��ÿһ�������ߵ�������
	cout << "��һ���ʤ���ǣ�" << endl;
	sort(Group1.begin(), Group1.end(), SortSpeeker);
	Group1.pop_back();
	Group1.pop_back();
	Group1.pop_back();
	for_each(Group1.begin(), Group1.end(), PrinSpeeker);//��������ߵ�����������
	cout << "�ڶ����ʤ���ǣ�" << endl;
	sort(Group2.begin(), Group2.end(), SortSpeeker);
	Group2.pop_back();
	Group2.pop_back();
	Group2.pop_back();
	for_each(Group2.begin(), Group2.end(), PrinSpeeker);//��������ߵ�����������
	//����֮�󣬵�һ���vector�����˵�һ���ǰ�������ڶ����vector�����˵ڶ����ǰ����
}
void SpeechManager::HandSetSpeekerScore(vector<Speeker>& Group1, vector<Speeker>& Group2)
{
	int i = 0;
	int j = 0;
	cout << "���õ�һ�����:" << endl;
	for (vector<Speeker>::iterator it = Group1.begin(); it != Group1.end(); it++)
	{
		double score;
		cout << "������" << it->m_Name << '\t' << "��ţ�" << it->m_Number << '\t' << "�����Ϊ" << endl;
		cin >> score;
		it->m_Score = score;
	}
	cout << "���õڶ������:" << endl;
	for (vector<Speeker>::iterator it = Group2.begin(); it != Group2.end(); it++)
	{
		double score;
		cout << "������" << it->m_Name << '\t' << "��ţ�" << it->m_Number << '\t' << "�����Ϊ" << endl;
		cin >> score;
		it->m_Score = score;
	}
}
void SpeechManager::AutoSetSpeekerScore(vector<Speeker>& Group1, vector<Speeker>& Group2)
{
	for (vector<Speeker>::iterator it = Group1.begin(); it != Group1.end(); it++)
	{
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;  // 600 ~ 1000
			//cout << score << " ";
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());				//����
		d.pop_front();												//ȥ����߷�
		d.pop_back();												//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);				//��ȡ�ܷ�
		double avg = sum / (double)d.size();									//��ȡƽ����
		it->m_Score = avg;
		//ÿ����ƽ����
		//cout << "��ţ� " << *it  << " ѡ�֣� " << this->m_Speaker[*it].m_Name << " ��ȡƽ����Ϊ�� " << avg << endl;  //��ӡ����
	}

	for (vector<Speeker>::iterator it = Group2.begin(); it != Group2.end(); it++)
	{
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;  // 600 ~ 1000
			//cout << score << " ";
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());				//����
		d.pop_front();												//ȥ����߷�
		d.pop_back();												//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);				//��ȡ�ܷ�
		double avg = sum / (double)d.size();									//��ȡƽ����
		it->m_Score = avg;
	}
}
class TransformSpeeker
{
public:
	Speeker operator()(const Speeker& s)
	{
		return s;
	}
};
void SpeechManager::SetSecondRace(vector<Speeker>& v_Speeker, vector<Speeker>& Group1, vector<Speeker>& Group2)
{
	cout << "merge����" << endl;
	//��ǩ�����֣����ַ�������Ϊ����������ֵ�����ó��ھ�
	for_each(v_Speeker.begin(), v_Speeker.end(), PrinSpeeker);
	system("pause");
	//��ǩ
	random_shuffle(v_Speeker.begin(), v_Speeker.end());//����˳��
	//
	cout << "�ڶ��ֱ�����ǩ�Ľ��Ϊ��" << endl;
	for_each(v_Speeker.begin(), v_Speeker.end(), PrinSpeeker);
	system("pause");
	//����
	for (vector<Speeker>::iterator it = v_Speeker.begin(); it != v_Speeker.end(); it++)
	{
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;  // 600 ~ 1000
			//cout << score << " ";
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());				//����
		d.pop_front();												//ȥ����߷�
		d.pop_back();												//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);				//��ȡ�ܷ�
		double avg = sum / (double)d.size();									//��ȡƽ����
		it->m_Score = avg;
		//ÿ����ƽ����
		//cout << "��ţ� " << *it  << " ѡ�֣� " << this->m_Speaker[*it].m_Name << " ��ȡƽ����Ϊ�� " << avg << endl;  //��ӡ����
	}
	//����
	cout << "�ڶ��ֱ�����ί��ֵĽ��Ϊ��" << endl;
	for_each(v_Speeker.begin(), v_Speeker.end(), PrinSpeeker);
	system("pause");
	cout << "�ڶ��ֱ����Ľ��Ϊ��" << endl;
	sort(v_Speeker.begin(), v_Speeker.end(), SortSpeeker);
	for_each(v_Speeker.begin(), v_Speeker.end(), PrinSpeeker);
	//������
	v_Speeker.pop_back();
	v_Speeker.pop_back();
	v_Speeker.pop_back();
	this->Winner.resize(v_Speeker.size());
	transform(v_Speeker.begin(), v_Speeker.end(), this->Winner.begin(), TransformSpeeker());
}
void SpeechManager::SaveSpeech()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<Speeker>::iterator it = this->Winner.begin(); it != this->Winner.end(); it++)
	{
		ofs << it->m_Number << ',' << it->m_Score << ',';
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();

	cout << "��¼�Ѿ�����" << endl;
}
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in); //���������� ��ȡ�ļ�

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��!" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;

	ifs.putback(ch); //��ȡ�ĵ����ַ��Ż�ȥ

	string data;
	int index = 0;
	while (ifs >> data)
	{
		//cout << data << endl;
		vector<string>v;

		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start); //��0��ʼ���� ','
			if (pos == -1)
			{
				break; //�Ҳ���break����
			}
			string tmp = data.substr(start, pos - start); //�ҵ���,���зָ� ����1 ��ʼλ�ã�����2 ��ȡ����
			v.push_back(tmp);
			start = pos + 1;
		}

		this->m_Record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();
}
void SpeechManager::showRecord()
{
	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "��" << i + 1 << "�� " <<
			"�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
			"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
			"������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
	}
	system("pause");
	system("cls");
}
SpeechManager::~SpeechManager()
{
}