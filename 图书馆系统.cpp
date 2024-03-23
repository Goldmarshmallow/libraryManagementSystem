#include <iostream>
#include <string>


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
        cout << "书籍已满" << endl;
    }
    else {
        string name;
        cout << "请输入书籍的名字: " << endl;
        cin >> name;
        abs->book[abs->length].name = name;
        int price;
        cout << "请输入书的价格： " << endl;
        cin >> price;
        abs->book[abs->length].price = price;
        string num;
        cout << "请输入书的编号： " << endl;
        cin >> num;
        abs->book[abs->length].number = num;
        abs->length++;
        cout << "添加成功" << endl;
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
    cout << "请输入你要删除的书籍" << endl;
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
        cout << "删除成功" << endl;
    }
    else if (ret != 1 && ret == abs->length - 1) {
        abs->length--;
    }
    else {
        cout << "查无此书" << endl;
    }
}
void CheckBook(Arraybooks* abs) {
    cout << "输入你要查找的书籍" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1) {
        cout << "书名为：" << abs->book[ret].name << "\t";
        cout << "书价格为：" << abs->book[ret].price << "\t";
        cout << "书编号为：" << abs->book[ret].number << endl;
    }
    else {
        cout << "查无此书" << endl;
    }
}
void cleanbooks(Arraybooks* abs) {
    abs->length = 0;
    cout << "清理完成" << endl;
}
void changebooks(Arraybooks* abs) {
    cout << "输入你要修改的图书" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1) {
        cout << "请输入名字： " << endl;
        string name;
        cin >> name;
        abs->book[ret].name = name;

        cout << "请输入价格： " << endl;
        int price;
        cin >> price;
        abs->book[ret].price = price;

        cout << "请输入编号: " << endl;
        string num;
        cin >> num;
        abs->book[ret].number = num;
    }
    else {
        cout << "查无此书" << endl;
    }
}
void showbooks(Arraybooks* abs) {
    if (abs->length == 0) {
        cout << "书架为空" << endl;
    }
    else {
        for (int i = 0; i < abs->length; ++i) {
            cout << "书籍名字 ： " << abs->book[i].name << "\t";
            cout << "书籍价格 ： " << abs->book[i].price << "\t";
            cout << "书籍编号 ： " << abs->book[i].number << endl;
        }
    }
}
int outSystem() {
    cout << "欢迎下次使用" << endl;
    return 0;
}
void mean() {
    cout << "**************************" << endl;
    cout << "*******1、加入图书********" << endl; 
    cout << "*******2、按名删除图书****" << endl;
    cout << "*******3、按名查找图书****" << endl;
    cout << "*******4、清空图书架******" << endl;
    cout << "*******5、修改图书名******" << endl;
    cout << "*******6、显示图书架******" << endl;
    cout << "*******7、退出系统********" << endl; 
    cout << "**************************" << endl;
}
