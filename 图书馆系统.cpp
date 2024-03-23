#include <iostream>
#include <string>

// 2
using namespace std;
#define MAX 1000
struct Person {
    string name;
    int price;
    string number;
};

struct Arraybooks {
    struct Person book[MAX];
    int length;
};

void mean();
int  outSystem();
void addBooks(Arraybooks* abs);
void dalateBooks(Arraybooks* abs);
int  isExist(Arraybooks* abs, string name);
void CheckBook(Arraybooks* abs);
void cleanbooks(Arraybooks* abs);
void showbooks(Arraybooks* abs);
void changebooks(Arraybooks* abs);

int main() {
    int x;
    Arraybooks abs;
    abs.length = 0;

    while (true) {
        mean();
        cin >> x;
        switch (x) {
        case 1:
            addBooks(&abs);
            break;
        case 2:
            dalateBooks(&abs);
            break;
        case 3:
            CheckBook(&abs);
            break;
        case 4:
            cleanbooks(&abs);
            break;
        case 5:
            changebooks(&abs);
            break;
        case 6:
            showbooks(&abs);
            break;
        case 7:
            outSystem();
            break;
        }
    }
    return 0;
}
void addBooks(Arraybooks* abs) {
    if (abs->length >= MAX) {
        cout << "�鼮����" << endl;
    }
    else {
        string name;
        cout << "�������鼮������: " << endl;
        cin >> name;
        abs->book[abs->length].name = name;
        int price;
        cout << "��������ļ۸� " << endl;
        cin >> price;
        abs->book[abs->length].price = price;
        string num;
        cout << "��������ı�ţ� " << endl;
        cin >> num;
        abs->book[abs->length].number = num;
        abs->length++;
        cout << "���ӳɹ�" << endl;
    }
}
int isExist(Arraybooks* abs, string name) {
    for (int i = 0; i < abs->length; ++i) {
        if (abs->book[i].name == name) {
            return i;
        }
    }
    return -1;
}
void dalateBooks(Arraybooks* abs) {
    cout << "��������Ҫɾ�����鼮" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1 && ret != abs->length - 1) {
        abs->book[ret].name = abs->book[ret + 1].name;
        abs->book[ret].number = abs->book[ret + 1].number;
        abs->book[ret].price = abs->book[ret + 1].price;
        for (int i = ret + 2; i < abs->length; ++i) {
            abs->book[i - 1].name = abs->book[i].name;
            abs->book[i - 1].number = abs->book[i].number;
            abs->book[i - 1].price = abs->book[i].price;
            abs->length--;
        }
        cout << "ɾ���ɹ�" << endl;
    }
    else if (ret != 1 && ret == abs->length - 1) {
        abs->length--;
    }
    else {
        cout << "���޴���" << endl;
    }
}
void CheckBook(Arraybooks* abs) {
    cout << "������Ҫ���ҵ��鼮" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1) {
        cout << "����Ϊ��" << abs->book[ret].name << "\t";
        cout << "��۸�Ϊ��" << abs->book[ret].price << "\t";
        cout << "����Ϊ��" << abs->book[ret].number << endl;
    }
    else {
        cout << "���޴���" << endl;
    }
}
void cleanbooks(Arraybooks* abs) {
    abs->length = 0;
    cout << "�������" << endl;
}
void changebooks(Arraybooks* abs) {
    cout << "������Ҫ�޸ĵ�ͼ��" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1) {
        cout << "���������֣� " << endl;
        string name;
        cin >> name;
        abs->book[ret].name = name;

        cout << "������۸� " << endl;
        int price;
        cin >> price;
        abs->book[ret].price = price;

        cout << "��������: " << endl;
        string num;
        cin >> num;
        abs->book[ret].number = num;
    }
    else {
        cout << "���޴���" << endl;
    }
}
void showbooks(Arraybooks* abs) {
    if (abs->length == 0) {
        cout << "���Ϊ��" << endl;
    }
    else {
        for (int i = 0; i < abs->length; ++i) {
            cout << "�鼮���� �� " << abs->book[i].name << "\t";
            cout << "�鼮�۸� �� " << abs->book[i].price << "\t";
            cout << "�鼮��� �� " << abs->book[i].number << endl;
        }
    }
}
int outSystem() {
    cout << "��ӭ�´�ʹ��" << endl;
    return 0;
}
void mean() {
    cout << "**************************" << endl;
    cout << "*******1������ͼ��********" << endl; 
    cout << "*******2������ɾ��ͼ��****" << endl;
    cout << "*******3����������ͼ��****" << endl;
    cout << "*******4�����ͼ���******" << endl;
    cout << "*******5���޸�ͼ����******" << endl;
    cout << "*******6����ʾͼ���******" << endl;
    cout << "*******7���˳�ϵͳ********" << endl; 
    cout << "**************************" << endl;
}
