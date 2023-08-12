#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#define FILENAME "D:\\code\\cpp_project\\cpp_primer1\\AccountBook.txt"
#define INCOME "收入"
#define EXPAND "支出"
using namespace std;

// 绘制菜单的功能
void showMainMenu();
// 绘制记账种类
void showAccountingMenu();
void showQueryMenu();
// 读取键盘输入的菜单选择，参数为选项个数
char readMenuSelection(int options);
char readQuitConfirm();
int readAmount();


void showMainMenu(){
    cout << "hello, justin!" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "|=============欢迎使用小谷记账簿=================|" << endl;
    cout << "|                                               |" << endl;
    cout << "|***************** 1 记账 **********************|" << endl;
    cout << "|***************** 2 查询 **********************|" << endl;
    cout << "|***************** 3 退出 **********************|" << endl;
    cout << "------------------------------------------------"  << endl;
    cout << "\n 请选择(1-3):" << endl;
}
void showAccountingMenu(){
    cout << "------------------------------------------------" << endl;
    cout << "|================选择记账种类====================|" << endl;
    cout << "|                                               |" << endl;
    cout << "|***************** 1 收入 **********************|" << endl;
    cout << "|***************** 2 支出 **********************|" << endl;
    cout << "|***************** 3 返回主菜单 ********************|" << endl;
    cout << "------------------------------------------------"  << endl;
    cout << "\n 请选择(1-3):" << endl;
}

void showQueryMenu(){
    cout << "------------------------------------------------" << endl;
    cout << "|================选择查询条件====================|" << endl;
    cout << "|                                               |" << endl;
    cout << "|***************** 1 统计所有账 *****************|" << endl;
    cout << "|***************** 2 统计收入 *******************|" << endl;
    cout << "|***************** 3 统计支出 *******************|" << endl;
    cout << "|***************** 4 返回主菜单 *****************|" << endl;
    cout << "------------------------------------------------"  << endl;
    cout << "\n 请选择(1-4):" << endl;
}


char readMenuSelection(int options){
    string str;
    while(true){
        getline(cin, str);
        if(str.size() > 1 || str[0] - '0' <=0 || str[0] - '0' > options){
            cout << "输入错误, 请重新选择:";
        }else   
        break;
    }
    return str[0];
}

// 读取键盘输入的金额数
int readAmount()
{
    int amount;
    string str;
    while(true){
        getline(cin, str);
        try{
            amount = stoi(str);
            break;
        }catch(invalid_argument e){
            cout << "输入错误，请正确输入数字：";
        }
    }

    
    return amount;
}

char readQuitConfirm(){
    string str;
    while (true)
    {
        getline(cin, str);
        if(str.size()!=1||toupper(str[0])!='Y' && toupper(str[0]) != 'N')
            cout << "请输入 Y 或者 N";
        else
            break;    

    }
    return toupper(str[0]);
}
    