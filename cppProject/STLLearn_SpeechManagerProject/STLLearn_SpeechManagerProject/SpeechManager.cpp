#include "SpeechManager.h"
#include <random>
void PrinSpeeker(const Speeker& s_Speeker)
{
	cout << "编号：" << s_Speeker.m_Number << '\t' << "姓名：" << s_Speeker.m_Name << '\t' << "分数：" << s_Speeker.m_Score << endl;
	//设置了分数才可以用这个打印的代码，否则会报错
}
bool SortSpeeker(const  Speeker& s1, const Speeker& s2)//降序排序
{
	return s1.m_Score >= s2.m_Score;
}
SpeechManager::SpeechManager()
{
}
void SpeechManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void SpeechManager::SetFirstRace(vector<Speeker>& v_Speeker, vector<Speeker>& Group1, vector<Speeker>& Group2)
{
	//第一轮比赛要做的事情有：
	for_each(v_Speeker.begin(), v_Speeker.end(), PrinSpeeker);
	system("pause");
	//抽签、分组（将主函数创建的vector分到两个vector里面去）、赋分（两种方法：人为输入和随机赋值）
	random_shuffle(v_Speeker.begin(), v_Speeker.end());//打乱顺序
	for_each(v_Speeker.begin(), v_Speeker.end(), PrinSpeeker);
	system("pause");
	//2.分组，也就是用copy函数
	int size = v_Speeker.size();
	for (int i = 0; i < size / 2; i++)//每个for循环跑六遍
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
	//3.赋分（赋分额外写两个函数）
	//3.1 人为赋分
	//HandSetSpeekerScore(Group1, Group2);
	//3.2 随机赋分
	AutoSetSpeekerScore(Group1, Group2);
	cout << "第一组：" << endl;
	for_each(Group1.begin(), Group1.end(), PrinSpeeker);
	cout << "第二组：" << endl;
	for_each(Group2.begin(), Group2.end(), PrinSpeeker);
	system("pause");
	//4.选出每一组分数最高的三个人
	cout << "第一组获胜的是：" << endl;
	sort(Group1.begin(), Group1.end(), SortSpeeker);
	Group1.pop_back();
	Group1.pop_back();
	Group1.pop_back();
	for_each(Group1.begin(), Group1.end(), PrinSpeeker);//将分数最高的三个人排序
	cout << "第二组获胜的是：" << endl;
	sort(Group2.begin(), Group2.end(), SortSpeeker);
	Group2.pop_back();
	Group2.pop_back();
	Group2.pop_back();
	for_each(Group2.begin(), Group2.end(), PrinSpeeker);//将分数最高的三个人排序
	//做完之后，第一组的vector保存了第一组的前三名，第二组的vector保存了第二组的前三名
}
void SpeechManager::HandSetSpeekerScore(vector<Speeker>& Group1, vector<Speeker>& Group2)
{
	int i = 0;
	int j = 0;
	cout << "设置第一组分组:" << endl;
	for (vector<Speeker>::iterator it = Group1.begin(); it != Group1.end(); it++)
	{
		double score;
		cout << "姓名：" << it->m_Name << '\t' << "编号：" << it->m_Number << '\t' << "其分数为" << endl;
		cin >> score;
		it->m_Score = score;
	}
	cout << "设置第二组分组:" << endl;
	for (vector<Speeker>::iterator it = Group2.begin(); it != Group2.end(); it++)
	{
		double score;
		cout << "姓名：" << it->m_Name << '\t' << "编号：" << it->m_Number << '\t' << "其分数为" << endl;
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

		sort(d.begin(), d.end(), greater<double>());				//排序
		d.pop_front();												//去掉最高分
		d.pop_back();												//去掉最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f);				//获取总分
		double avg = sum / (double)d.size();									//获取平均分
		it->m_Score = avg;
		//每个人平均分
		//cout << "编号： " << *it  << " 选手： " << this->m_Speaker[*it].m_Name << " 获取平均分为： " << avg << endl;  //打印分数
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

		sort(d.begin(), d.end(), greater<double>());				//排序
		d.pop_front();												//去掉最高分
		d.pop_back();												//去掉最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f);				//获取总分
		double avg = sum / (double)d.size();									//获取平均分
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
	cout << "merge无误" << endl;
	//抽签、赋分（两种方法：人为输入和随机赋值）、得出冠军
	for_each(v_Speeker.begin(), v_Speeker.end(), PrinSpeeker);
	system("pause");
	//抽签
	random_shuffle(v_Speeker.begin(), v_Speeker.end());//打乱顺序
	//
	cout << "第二轮比赛抽签的结果为：" << endl;
	for_each(v_Speeker.begin(), v_Speeker.end(), PrinSpeeker);
	system("pause");
	//赋分
	for (vector<Speeker>::iterator it = v_Speeker.begin(); it != v_Speeker.end(); it++)
	{
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;  // 600 ~ 1000
			//cout << score << " ";
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());				//排序
		d.pop_front();												//去掉最高分
		d.pop_back();												//去掉最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f);				//获取总分
		double avg = sum / (double)d.size();									//获取平均分
		it->m_Score = avg;
		//每个人平均分
		//cout << "编号： " << *it  << " 选手： " << this->m_Speaker[*it].m_Name << " 获取平均分为： " << avg << endl;  //打印分数
	}
	//排序
	cout << "第二轮比赛评委打分的结果为：" << endl;
	for_each(v_Speeker.begin(), v_Speeker.end(), PrinSpeeker);
	system("pause");
	cout << "第二轮比赛的结果为：" << endl;
	sort(v_Speeker.begin(), v_Speeker.end(), SortSpeeker);
	for_each(v_Speeker.begin(), v_Speeker.end(), PrinSpeeker);
	//保存结果
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

	//关闭文件
	ofs.close();

	cout << "记录已经保存" << endl;
}
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in); //输入流对象 读取文件

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;

	ifs.putback(ch); //读取的单个字符放回去

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
			pos = data.find(",", start); //从0开始查找 ','
			if (pos == -1)
			{
				break; //找不到break返回
			}
			string tmp = data.substr(start, pos - start); //找到了,进行分割 参数1 起始位置，参数2 截取长度
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
		cout << "第" << i + 1 << "届 " <<
			"冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
			"亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
			"季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
	}
	system("pause");
	system("cls");
}
SpeechManager::~SpeechManager()
{
}