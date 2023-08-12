#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#define FILENAME "./account_items.txt"
#define INCOME "收入"
#define EXPAND "支出"
using namespace std;
struct AccountItem{
    string itemType;
    int amount;
    string detail;
};
void showMainMenu();
char readMenuSelection(int options);
char readQuitConfirm();
void showAccountingMenu();
void income(vector<AccountItem> &items);
void expand(vector<AccountItem> &items);
void accounting(vector<AccountItem> &items);
int main(){
    cout << "justin 盖建明" << endl;
    vector<AccountItem> items;
    bool quit = false;
    while(!quit){
        showMainMenu();
        char key = readMenuSelection(3);
        switch (key)
        {
        case '1': // 1.记账
            /* code */
            showAccountingMenu();
            accounting(items);
            break;
        case '2': // 查看账单
            break;
        case '3':
            cout << "\n确认要退出：Y是,N不是(Y/N): ";
            if (readQuitConfirm()=='Y'){
                quit = true;
            }
            break;
        default:
            break;
        }
    }
    return 1;
}

void showMainMenu(){
    cout << "主菜单" <<endl;
    cout << "1. 记账" <<endl;
    cout << "2. 查看" << endl;
    cout << "3. 结束" << endl;
    cout << "请输入所需要的菜单！(1-3)" <<endl;
}
char readMenuSelection(int options){
    string str;
    while(true){
        cin>>str;
        if (str.size() !=1 ||str[0] - '0' <= 0 || str[0] - '0' > options){
            cout << "请输入所需要的菜单错误！";
        }else{
            break;
        }
    }
    return str[0];
}
char readQuitConfirm(){
    string str;
    while(true){
        cin>>str;
  
        if (str.size()!=1 || toupper((str[0]) != 'Y' && toupper(str[0])!= 'N')){
            cout << "请输入:Y or N！" << endl;
        }else{
            break;
        }
    }
    return str[0];
}

void showAccountingMenu(){
    cout << "-------------------------------------------------------" << endl;
	cout << "|===============   选择记账种类   ====================|" << endl;
	cout << "|                                                     |" << endl;
	cout << "|***************    1 收  入      ********************|" << endl;
	cout << "|***************    2 支  出      ********************|" << endl;
	cout << "|***************    3 返回主菜单  ********************|" << endl;
	cout << "|_____________________________________________________|" << endl;

	cout << "\n请选择(1 - 3)：";
}
void accounting(vector<AccountItem> &items){
    char key = readMenuSelection(3);
    switch (key)
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
void insertItemIntoFile(AccountItem item){
    ofstream output(FILENAME, ios::out | ios::app);
    output << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;
    output.close();
}
int readAmount(){
    string str;
    int amount;
    while(true){
        //cin>>str;
        getline(cin, str);
  
        try{
            amount = stoi(str);
            break;
        }catch(invalid_argument e){
            cout << "pls input int amount!" << endl;

        }
    }
    return str[0];
}
void income(vector<AccountItem> &items){
    AccountItem item;
    item.itemType = INCOME;
    cout << "请输入金额：" << endl;
    item.amount = readAmount();
    cout << "\n备注：";
    getline(cin,item.detail);
    cout << "-==--" << item.detail;
    items.push_back(item);
    insertItemIntoFile(item);
    // 显示成功信息
	cout << "\n------------------------记账成功！--------------------------\n" << endl;
	cout << "\n请按回车键返回主菜单..." << endl;
    string line;
	getline(cin, line);
}

void expand(vector<AccountItem> &items){
    AccountItem item;
    item.itemType = EXPAND;
    cout << "pls input aount" << endl;
    item.amount = readAmount();
    cout << "pls input detail" << endl;
    getline(cin,item.detail);
    items.push_back(item);
    insertItemIntoFile(item);
    // 显示成功信息
	cout << "\n------------------------记账成功！--------------------------\n" << endl;
	cout << "\n请按回车键返回主菜单..." << endl;
    string line;
	getline(cin, line);
}

