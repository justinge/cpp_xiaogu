#include"common.h"
#include"account_item.h"

int main(){
    // 1. 加载文件中的账目数据
	vector<AccountItem> items;
	loadDataFromFile(items);

    bool quit = false;
    while(!quit){
        showMainMenu();
        char key = readMenuSelection(3);
    
        switch (key)
        {
            case '1':
                showAccountingMenu();
                accounting(items);
                break;
            case '2':
                showQueryMenu();
                query(items);
                break;
            case '3':
                cout << "\n确认退出?(Y/N):";
                if (readQuitConfirm() == 'Y')
                    quit = true;
                break;
            default:
                break;
            }
    }
}