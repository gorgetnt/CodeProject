#include <iostream>
#include <random> // �����������
using namespace std;
int main() {
    // ����һ����������棬ʹ��std::random_device������
    std::random_device rd;   // ��ȡ���������
    std::mt19937 gen(rd());  // ʹ��Mersenne Twister����

    // ����������ֲ���Χ������1��100
    std::uniform_int_distribution<> distr(1, 100);

    // ���������
    int random_number = distr(gen);
    int inInt;
    // ��������
    std::cout << "���ɵ����������: " << random_number << std::endl;
    while (1)
    {
        cout << "������һ������:" << endl;
        cin >> inInt;
        if (inInt == random_number)
        {
            cout << "�¶��ˣ�" << endl;
            break;
        }
        else
        {
            cout << "�´���!" << endl;
            continue;
        }
    }
    return 0;
}
