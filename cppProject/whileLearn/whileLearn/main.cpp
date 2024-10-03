#include <iostream>
#include <random> // 包含随机数库
using namespace std;
int main() {
    // 创建一个随机数引擎，使用std::random_device来播种
    std::random_device rd;   // 获取随机数种子
    std::mt19937 gen(rd());  // 使用Mersenne Twister引擎

    // 定义随机数分布范围，例如1到100
    std::uniform_int_distribution<> distr(1, 100);

    // 生成随机数
    int random_number = distr(gen);
    int inInt;
    // 输出随机数
    std::cout << "生成的随机整数是: " << random_number << std::endl;
    while (1)
    {
        cout << "请输入一个整数:" << endl;
        cin >> inInt;
        if (inInt == random_number)
        {
            cout << "猜对了！" << endl;
            break;
        }
        else
        {
            cout << "猜错了!" << endl;
            continue;
        }
    }
    return 0;
}
