#pragma once
#include "common.h"

struct AccountItem
{
    string itemType;
    int amount;
    string detail;
};
void insertIntoFile(const AccountItem& item);


void printAccountItem(AccountItem item){
    cout << item.itemType << "\t\t" << item.amount << "\t\t" << item.detail << endl;
} 
// 读取文件
void loadDataFromFile(vector<AccountItem>& items){
    ifstream input(FILENAME);
    // 逐行读取
    AccountItem item;
    while (input >> item.itemType && input >> item.amount && input >> item.detail){
        items.push_back(item);
    }
    input.close();
}
// 讲一条账目写入文件
void insertItemIntoFile(AccountItem item){
    // 如果没有文件，那么生成空文件；如果有文件，那么在文件尾追加。
    ofstream output(FILENAME, ios::out | ios::app);
    output << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;
    output.close();
}

// 记账操作-收入
void income(vector<AccountItem> &items){
    AccountItem item;
    item.itemType = INCOME;
    cout << "\n 本次收入金额：";
    item.amount = readAmount();
    cout << "\n备注：";
    getline(cin, item.detail);
    items.push_back(item);
    // 写入文件做持久化保存
	insertIntoFile(item);
    // 显示成功信息
	cout << "\n------------------------记账成功！--------------------------\n" << endl;
	cout << "\n请按回车键返回主菜单..." << endl;
    string line;
	getline(cin, line);
}
// 记录一笔支出
void expand(vector<AccountItem>& items)
{
	// 新构建一个AccountItem对象
	AccountItem item;

	// 类型已经确定，就是支出
	item.itemType = EXPAND;

	// 与用户交互，键盘输入金额和备注信息
	cout << "\n本次支出金额：";
	item.amount = - readAmount();
	
	cout << "\n备注：";
	getline(cin, item.detail);

	// 添加到vector中
	items.push_back(item);
	// 写入文件做持久化保存
	insertIntoFile(item);

	// 显示成功信息
	cout << "\n------------------------记账成功！--------------------------\n" << endl;
	cout << "\n请按回车键返回主菜单..." << endl;

	string line;
	getline(cin, line);
}

// ------------1. 记账操作------------//
void accounting(vector<AccountItem> &items){
    switch (readMenuSelection(3))
    {
    case '1':
        income(items);
        break;
    case '2':
        expand(items);
        break;
    default:
        break;
    }
}
void printItem(AccountItem item){
    cout << item.itemType << "\t\t" << item.amount << "\t\t" << item.detail << endl;
}
void queryItems(vector<AccountItem>& items){
    cout << "----------------查询结果------------" << endl;
    cout << "\n类型\t\t金额\t\t备注\n" << endl;
    int total = 0;
    for (auto item: items){
        printItem(item);
        total +=item.amount;
    }
    // 输出信息
	cout << "===================================================\n" << endl;
	cout << "总收支：" << total << endl;
	cout << "\n请按回车键返回主菜单..." << endl;
    string line;
	getline(cin, line);
}

void queryItems(vector<AccountItem> items,string itemType){
    cout << "----------------查询结果------------" << endl;
    cout << "\n类型\t\t金额\t\t备注\n" << endl;
    int total = 0;
    for (auto item: items){
        if (item.itemType == itemType){
            printItem(item);
            total +=item.amount;
        }
            
    }
    // 输出信息
	cout << "===================================================\n" << endl;
	cout << ((itemType == INCOME) ? "总收入:":"总支出:") << total << endl;
	cout << "\n请按回车键返回主菜单..." << endl;
    string line;
	getline(cin, line);
}

void query(vector<AccountItem> &items){
    char key = readMenuSelection(4);
    switch (key)
    {
    case '1':
        queryItems(items);
        break;
    case '2':
        queryItems(items,INCOME);
        break;
    case '3':
        queryItems(items,EXPAND);
        break;
     case '4':
        break;
    }
}


// 将一条账目写入文件中
void insertIntoFile(const AccountItem& item)
{
	// 创建一个ofstream对象，以追加方式进行写入
	ofstream output(FILENAME, ios::out | ios::app);

	output << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;

	output.close();
}
