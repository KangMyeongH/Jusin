#include <iostream>
#include <Windows.h>
using namespace std;

/*
 * 구구단 1단부터 9단까지 출력
 */
bool ClacGUGUDAN()
{
    int j = 1;
    while(j < 10)
    {
        // 구구단 몇단인지 출력
        cout << j << "단" << '\n';

        // 구구단 출력을 위한 변수
        int i = 1;

        // 구구단 출력
        while(i < 10)
        {
            cout << j << " * " << i << " = " << j * i << '\n';
            ++i;
        }
        cout << "===========================================" << '\n';

        // 구구단 단수 증가
        ++j;
    }
    return true;
}

/*
 * 1. 소지금을 입력받는다.
 * 2. 매번 잔액을 출력해준다.
 * 3. 메뉴 1. 콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 반환
 * 4. 해당 목록 구매 시, ‘xx 구매 완료’ 출력 후, 잔액을 변경함
 * 5. 소지금 부족 시, “소지금이 부족합니다” 출력
 * 6. 4번을 누르면 ‘거스름 돈은 xx입니다.’ 출력 후 프로그램 종료
 */
bool VendingMachine()
{
    int iMoney = 0;
    int iNum = 0;

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
            if(iMoney >= 100)
            {
                iMoney -= 100;
                cout << "콜라 구매 완료" << '\n';
            }

            else
            {
                cout << "소지금이 부족합니다." << '\n';
            }
            system("pause");
            break;
            
        case 2:
            if(iMoney >= 200)
            {
                iMoney -= 200;
                cout << "사이다 구매 완료" << '\n';
            }

            else
            {
                cout << "소지금이 부족합니다." << '\n';
            }
            system("pause");
            break;

        case 3:
            if(iMoney >= 300)
            {
                iMoney -= 300;
                cout << "콜라 구매 완료" << '\n';
            }

            else
            {
                cout << "소지금이 부족합니다." << '\n';
            }

            system("pause");
            break;

        case 4:
            cout << "거스롬돈은 " << iMoney << "입니다." << '\n';
            return true;
            
        default:
            cout << "1~4까지의 숫자를 입력하세요." << '\n';
            system("pause");
            break;
        }
    }
}

/*
 * 1. rand함수를 이용하여 홀짝을 맞추는 게임
 * 2. 매 회 마다 새로운 난수를 뽑아서 화면에 출력해줌 ( 정답 : ??? )
 * 3. 메뉴 1. 홀 2. 짝 3. 종료
 * 4. 총  5라운드로 실행하여 마지막 라운드 종료 시, 몇 승 몇 패 출력
 */
bool OddOrEvenGame()
{
    int iQues = 0;
    int iNum = 0;
    int i = 0;
    int iWin = 0;
    int iLose = 0;
    
    while(i < 5)
    {
        system("cls");
        srand(static_cast<unsigned>(time(nullptr)));
        iQues = rand();
        cout << "정답: " << iQues << '\n';
        cout << "1.홀 2.짝 3.종료" << '\n';
        cout << "메뉴를 선택하세요: ";
        cin >> iNum;
        
        switch(iNum)
        {
        case 1:
            if(iQues & 1) ++iWin;
            else ++iLose;
            ++i;
            break;

        case 2:
            if(iQues & 1) ++iLose;
            else ++iWin;
            ++i;
            break;

        case 3:
            return true;

        default:
            cout << "1~3까지의 숫자를 입력하세요." << '\n';
            system("pause");
            break;
        }
    }

    // 게임 종료 시 결과 표시
    cout << iWin << "승, " << iLose << "패" << '\n';
    return true;
}

void Test()
{

}

int main()
{
    int iNum = 0;
    bool isEnd = false;
    
    while(!isEnd)
    {
        cout << "1. 구구단 출력" << '\n';
        cout << "2. 자판기 게임" << '\n';
        cout << "3. 홀짝 게임" << '\n';
        cout << "4. 종료" << '\n';
        cout << "메뉴를 선택하세요: ";
        cin >> iNum;
        system("cls");
    
        switch(iNum)
        {
        case 1:
            isEnd = ClacGUGUDAN();
            break;

        case 2:
            isEnd = VendingMachine();
            break;

        case 3:
            isEnd = OddOrEvenGame();
            break;

        case 4:
            isEnd = true;
            break;
            
        default:
            cout << "1~4까지의 숫자를 입력하세요." << '\n';
            break;
        }
    }
    
    return 0;
}