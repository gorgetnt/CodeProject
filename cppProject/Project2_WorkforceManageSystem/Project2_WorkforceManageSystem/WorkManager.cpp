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
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void WorkManager::AddWorkerInformation(BaseWorker* b_W, string Name, int Id, int Type, int& lenList)
{
	/*
	* @brief:�ú�������������ְ����Ϣ��һ��ֻ������һ��ְ����ÿ����ְ��������������
	* @param:{
	* BaseWorker * b_w:�ò�������һ��ְ�����ָ�룬�Ӷ�����������ֻ��Ҫά��һ��ְ����
	* int &lenList:�ò�������ְ����ĳ��ȣ�ͬ����������������ֻά��һ������
	* int type:�û�������ʱֻ��Ҫ�������ְ���Ĺ��֣������ʵ��ͨ������ֱ��ʵ��
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
		cout << "�����ְ��������������������" << endl;
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
		cout << "ְ����Ϊ�գ�" << endl;
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
		cout << "error:ְ������û����Ҫɾ������ϵ�ˣ�" << endl;
		return;
	}
	//ͨ������ð�ݵķ�ʽ�������Ҫɾ����λ��
	for (int i = flag; i <= lenList - flag; i++)
	{
		b_W[i] = b_W[i + 1];
	}
	lenList--;
}
void WorkManager::ChangeWorkerInformation(BaseWorker* b_W, int& lenList, int Id)
{
	/*
	* @brief:����������Ը���������������ҵ�ͨѶ¼�е���ϵ�˲��޸�
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
		cout << "ְ������û����Ҫ�޸ĵ�ְ��!" << endl;
		return;
	}
	else
	{
		cout << "��Ҫ�޸ĵ�ְ��id:" << Id << '\t' << "����:" << endl;
		cout << "����:" << b_W[flag].name << '\t' << "���:" << b_W[flag].id << '\t' << "��λ:" << b_W[flag].post << '\t' << "ְ��:"
			<< b_W[flag].responsibility << endl;
		cout << "��������Ҫ�޸ĵ�ְ������Ϣ:" << endl;
		cout << "�޸ĺ������Ϊ:" << '\t';
		cin >> b_W[flag].name;
		cout << endl;
		//�޸ı��
		cout << "�޸ĺ�ı��Ϊ:" << '\t';
		cin >> b_W[flag].id;
		cout << endl;
		//�޸ĸ�λ��ְ��
		cout << "�޸ĺ�ĸ�λְ������Ϊ" << '\t';
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
			cout << "�����ְ��������������������" << endl;
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
	* @brief:����������Ը���������������ҵ�ͨѶ¼�е���ϵ�˲��޸�
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
		cout << "ְ������û����Ҫ���ҵ�ְ��!" << endl;
		return;
	}
	else
	{
		cout << "��Ҫ���ҵ�ְ��id:" << Id << '\t' << "����:" << endl;
		cout << "����:" << b_W[flag].name << '\t' << "���:" << b_W[flag].id << '\t' << "��λ:" << b_W[flag].post << '\t' << "ְ��:"
			<< b_W[flag].responsibility << endl;
		cout << "------------------------------------------------------------" << endl;
		cout << endl;
	}
}
void WorkManager::SortWorkerInformation(BaseWorker* b_W, int& lenList)
{
	int type;
	cout << "��ѡ��Ҫ����ķ�ʽ:" << endl;
	cout << "1.��������" << endl;
	cout << "2.��������" << endl;
	cin >> type;
	if (type == 2)//������
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
	//�������Ȳ�����
	//else if (type == 1)//������
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
	//	//���鵹��
	//	BaseWorker *b_w_New=new BaseWorker[lenList];

	//}
}
void WorkManager::ClearWorkerInformation(BaseWorker* b_W, int& lenList)
{
	BaseWorker workerList[1000];
	b_W = workerList;
	lenList = 0;
}