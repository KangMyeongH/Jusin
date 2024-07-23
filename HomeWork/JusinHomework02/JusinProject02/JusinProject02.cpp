#include <iostream>

using namespace std;

enum ERockPaperScissors
{
    SCISSORS = 1,
    ROCK,
    PAPER
};

/*
*1. 난수를 생성 ( 0~2 사이 값)
2. 메뉴 | 1. 가위 2. 바위 3. 보 4. 종료
3. 사용자가 입력한 값과 발생한 난수를이용하여 컴퓨터와 가위바위보를 실행
4. 총 5라운드, 승, 무, 패를 최적적으로 출력
*/

bool RockPaperScissors()
{
    int iRound = 0;
    int iPlayer = 0;
    int iComputer = 0;
    int iWin = 0;
    int iLose = 0;
    int iTie = 0;
    
    srand(static_cast<unsigned>(time(nullptr)));
    while(true)
    {
        if(iRound >= 5)
        {
            system("cls");
            cout << "최종 결과 | 승 : " << iWin << " 무 : " << iTie << " 패 : " << iLose << '\n';
            break;
        }
        system("cls");
        cout << "라운드 : " << iRound + 1 << '\n';
        cout << "승 : " << iWin << " 무 : " << iTie << " 패 : " << iLose << '\n';
        cout << "1. 가위 2. 바위 3. 보 4. 종료" << '\n';
        cout << "선택 : ";
        cin >> iPlayer;
        if(iPlayer == 1 || iPlayer == 2 || iPlayer == 3)
        {
            iComputer = rand() % 3 + 1;
            
            system("cls");
            cout << "플레이어 : ";
            
            if(iPlayer == 1)
            {
                cout << "가위" << '\n';
            }
            
            else if(iPlayer == 2)
            {
                cout << "바위" << '\n';
            }
            
            else if(iPlayer == 3)
            {
                cout << "보" << '\n';
            }
            
            cout << "컴퓨터 : ";

            if(iComputer == 1)
            {
                cout << "가위" << '\n';
            }
            
            else if(iComputer == 2)
            {
                cout << "바위" << '\n';
            }
            
            else if(iComputer == 3)
            {
                cout << "보" << '\n';
            }
            
            if(iPlayer == iComputer)
            {
                cout << "비겼습니다." << '\n';
                iTie++;
                system("pause");
            }
            else if((iPlayer == 1 && iComputer == 3) || (iPlayer == 2 && iComputer == 1) || (iPlayer == 3 && iComputer == 2))
            {
                cout << "이겼습니다." << '\n';
                iWin++;
                system("pause");
            }
            else
            {
                cout << "졌습니다." << '\n';
                iLose++;
                system("pause");
            }
            iRound++;
        }

        else if(iPlayer == 4)
        {
            return true;
        }
        
        else
        {
            cout << "잘못된 입력입니다." << '\n';
            system("pause");
        }
    }

    return true;
}

bool CalcGUGUDAN()
{
    int iDan = 0;
    int iMultiple = 0;

    system("cls");
    
    cout << "단을 입력하세요 : ";
    cin >> iDan;
    cout << "곱을 입력하세요 : ";
    cin >> iMultiple;

    for(int i = 0; i < iDan; i++)
    {
        cout << i + 1 << "단" << '\n';
        for(int j = 0; j < iMultiple; j++)
        {
            cout << i + 1 << " * " << j + 1 << " = " << (i+ 1) * (j + 1) << '\n';
        }
        cout << "===========================" << '\n';
    }

    system("pause");
    return true;
}

// *
// **
// ***
// ****
// *****
// 
// *****
// ****
// ***
// **
// *
// 
//     *
//    **
//   ***
//  ****
// *****
// 
// *****
//  ****
//   ***
//    **
// 	   *

bool DrawStar()
{
    system("cls");

    int iInput = 0;
    cin >> iInput;
    for(int i=0; i< iInput; i++)
    {
        for(int j = 0; j < i +1; j++)
        {
            cout << '*';
        }
        cout << '\n';
    }

    cout << '\n';
    
    for(int i = 0; i < iInput; i++)
    {
        for(int j = i; j < iInput; j++)
        {
            cout << '*';
        }

        cout <<'\n';
    }

    cout << '\n';

    for(int i = 0; i < iInput; i++)
    {
        for(int j =0; j < iInput - i - 1; j++)
        {
            cout << ' ';
        }

        for(int j = 0; j < 1 + i; j++)
        {
            cout << '*';
        }
        cout << '\n';
    }

    cout << '\n';

    for(int i = 0; i < iInput; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout << ' ';
        }
        
        for(int j = i; j < iInput; j++)
        {
            cout << '*';
        }
        
        cout <<'\n';
    }

    system("pause");
    
    return true;
}

bool Menu()
{
    int iMenu = 0;

    while(true)
    {
        system("cls");
        cout << "1. 가위바위보" << '\n';
        cout << "2. 구구단" << '\n';
        cout << "3. 별찍기" << '\n';
        cout << "4. 종료" << '\n';
        cout << "메뉴를 선택하세요 : ";
        cin >> iMenu;

        switch(iMenu)
        {
            case 1:
                RockPaperScissors();
                break;
            case 2:
                CalcGUGUDAN();
                break;
            case 3:
                DrawStar();
                break;
            case 4:
                return true;
            default:
                cout << "잘못된 입력입니다." << '\n';
                system("pause");
                break;
        }
    }
}

int main(int argc, char* argv[])
{
    Menu();
    
    return 0;
}
