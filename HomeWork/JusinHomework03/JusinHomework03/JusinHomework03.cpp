#include <iostream>
using namespace std;

bool VendingMachine();
bool CalcMoney(int& _iMoney, int _iPrice);
int CalcFactorial(int _iNum);

int main()
{
    cout << CalcFactorial(5) << '\n';
    system("pause");
    VendingMachine();
    return 0;
}

bool VendingMachine()
{
    int iMoney = 0;
    int iNum = 0;
    int iCoke = 100;
    int iCider = 200;
    int iFanta = 300;
    
    // 소지금 입력
    while(iMoney <= 0)
    {
        system("cls");
        if(iMoney <= 0) cout << "0원 이상의 금액을 입력하세요." << '\n';
        cout << "소지금을 입력하세요: ";
        cin >> iMoney;
    }

    // 자판기 메뉴
    while(true)
    {
        system("cls");
        cout << "잔액 : " << iMoney << '\n';
        cout << "1. 콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 반환" << '\n';
        cout << "메뉴를 선택하세요: ";
        cin >> iNum;

        // 메뉴 선택
        switch (iNum)
        {
        case 1:
            if(CalcMoney(iMoney, iCoke)) cout << "콜라 구매 완료" << '\n';
            else cout << "소지금이 부족합니다." << '\n';
            
            system("pause");
            break;
            
        case 2:
            if(CalcMoney(iMoney, iCider)) cout << "사이다 구매 완료" << '\n';
            else cout << "소지금이 부족합니다." << '\n';
            
            system("pause");
            break;

        case 3:
            if(CalcMoney(iMoney, iFanta)) cout << "환타 구매 완료" << '\n';
            else cout << "소지금이 부족합니다." << '\n';

            system("pause");
            break;

        case 4:
            cout << "거스롬돈은 " << iMoney << "원 입니다." << '\n';
            return true;
            
        default:
            cout << "1~4까지의 숫자를 입력하세요." << '\n';
            system("pause");
            break;
        }
    }
}

bool CalcMoney(int& _iMoney, int _iPrice)
{
    if(_iMoney >= _iPrice)
    {
        _iMoney -= _iPrice;
        return true;
    }
    
    else return false;
}

int CalcFactorial(int _iNum)
{
    if(_iNum == 1) return 1;
    return _iNum * CalcFactorial(_iNum - 1);
}

