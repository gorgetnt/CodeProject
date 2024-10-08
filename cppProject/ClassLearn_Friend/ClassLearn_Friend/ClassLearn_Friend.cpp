// ClassLearn_Friend.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Building
{
	friend void SetBuilding();
public:
	string livingRoom;
private:
	string bedRoom;
	int numberBedRoon;
};
void SetBuilding()
{
	Building b;
	b.bedRoom = "汤臣一品";
	b.numberBedRoon = 4;
	cout << b.bedRoom << "的卧室个数为" << b.numberBedRoon << endl;
}
int main()
{
	SetBuilding();
}