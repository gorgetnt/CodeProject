// structLearn_teacherCase1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<ctime>
#include<string>
using namespace std;
struct Student
{
	string sName;
	float score;
};
struct  Teacher
{
	string tName;
	Student studentArr[5];
};
Teacher SetTeacherValue(Student* stu, string tNa)
{
	Teacher tea;
	tea.tName = tNa;
	for (int i = 0; i < 5; i++)
	{
		tea.studentArr[i] = *stu;
		stu++;
	}
	return tea;
}
Student SetStudentValue(string sNa, float s)
{
	Student stu;
	stu.sName = sNa;
	stu.score = s;
	return stu;
}
void PrintTeacherValue(Teacher* tea)
{
	for (int i = 0; i < 3; i++)
	{
		cout << tea->tName << "的学生有:" << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << '\t' << tea->studentArr[j].sName << '\t' << tea->studentArr->score
				<< endl;
		}
		tea++;
	}
}
int main()
{
	srand((unsigned int)time(NULL)); //随机数种子 头文件
	string studentName = "ABCDE";
	string teacherName[3] = { "张涛","巴才松","田运洪" };
	Student stu0 = SetStudentValue("学生A", rand() % 61 + 40);
	Student stu1 = SetStudentValue("学生B", rand() % 61 + 40);
	Student stu2 = SetStudentValue("学生C", rand() % 61 + 40);
	Student stu3 = SetStudentValue("学生D", rand() % 61 + 40);
	Student stu4 = SetStudentValue("学生E", rand() % 61 + 40);
	Student stuArray[5] = { stu0,stu1,stu2,stu3,stu4 };
	Teacher tea0 = SetTeacherValue(stuArray, "教师" + teacherName[0]);
	Teacher tea1 = SetTeacherValue(stuArray, "教师" + teacherName[1]);
	Teacher tea2 = SetTeacherValue(stuArray, "教师" + teacherName[2]);
	Teacher teaArray[3] = { tea0,tea1,tea2 };
	PrintTeacherValue(teaArray);
	return 0;
}