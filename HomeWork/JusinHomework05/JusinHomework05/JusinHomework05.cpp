#include <iostream>
#include <random>

using namespace std;

void ArrayRender(const int(*)[5],int);

void Lotto();
void SetLottoNumber(int(*)[6],int);

void SetBaseBallNumber(int*);
void BaseBallGame();

void RotateArray();
void CopyArray(int(*)[5], int(*)[5]);

void Menu();

int main()
{
    Menu();
    return 0;
}

void ArrayRender(const int (*pArray)[5],int iSize)
{
    for(int i = 0; i < iSize; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << (*(pArray + i))[j] << "\t";
        }
        cout << '\n';
    }
}

/*
- 배열을 이용하여 1~45 사이의 숫자 중 무작위로 6개씩 총 5회 출력하기
- 같은 회차에서 중복된 숫자가 존재 할 수 없음
- 출력 시, 오름차순으로 정렬하여 출력할 것(버블 정렬을 사용할 것)
 */
void Lotto()
{
    int iLottoNumber[5][6];
    SetLottoNumber(iLottoNumber,5);
    for(int i = 0; i < 5; i++)
    {
        cout << i + 1 << "회차 | ";
        for(int j= 0; j < 6; j++)
        {
            cout << iLottoNumber[i][j] << "\t";
        }
        cout << "|\n";
    }
    system("pause");
}

void SetLottoNumber(int(*pLottoNumber)[6], int iSize)
{
    random_device randomDevice;
    mt19937 mt(randomDevice());
    uniform_int_distribution<int> dist(1,45);
    int randNum = 0;
    // 같은 회차에 동일한 숫자가 없이 랜덤한 값을 넣어준다.
    for(int i = 0; i < iSize; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            randNum = dist(mt);
            if(j == 0) pLottoNumber[i][j] = randNum;
            
            else
            {
                for(int k = 0; k < j; k++)
                {
                    if(pLottoNumber[i][k] == randNum)
                    {
                        j--;
                        break;
                    }
                    
                    if(k == j - 1) pLottoNumber[i][j] = randNum;
                }
            }
        }
    }
    // 버블 정렬을 이용하여 오름차순으로 정렬
    for(int i = 0; i < iSize; i++)
    {
        for(int j = 5; j > 0; j--)
        {
            for(int k = 0; k < j; k++)
            {
                if(pLottoNumber[i][k] > pLottoNumber[i][k + 1])
                {
                    int temp = pLottoNumber[i][k];
                    pLottoNumber[i][k] = pLottoNumber[i][k + 1];
                    pLottoNumber[i][k + 1] = temp;
                }
            }
        }
    }
}

/*
- 1~9까지의 숫자 중 무작위로 3개 추출하여 화면 출력
- 정렬은 하지 않는다.
- 숫자를 세 개 입력
- 입력한 수와 무작위 숫자의 위치와 값 모두 일치하면 스트라이트, 값만 일치할 경우 볼
- 매회 몇 스트라이크 몇 볼인지 출력
- 총 9회까지 진행하는데, 9라운드 중 3 스트라이크 발생 시, 승리 출력 후 종료
- 총 9회까지 진행했는데 결국 3스트라이크 못만들 경우, 패배 출력 후 종료
 */

void SetBaseBallNumber(int* pBaseballNumber, int iSize)
{
    random_device randomDevice;
    mt19937 mt(randomDevice());
    uniform_int_distribution<int> dist(1,9);
    int iRandNum = 0;
    for(int i = 0; i < iSize; i++)
    {
        iRandNum = dist(mt);
        if(i == 0) pBaseballNumber[i] = iRandNum;
        else
        {
            for(int j = 0; j < i; j++)
            {
                if(pBaseballNumber[j] == iRandNum)
                {
                    i--;
                    break;
                }
                if(j == i - 1) pBaseballNumber[i] = iRandNum;
            }
        }
    }
}

void BaseBallGame()
{
    int iBaseballNumber[3];
    int iInputNumber[3];
    int iStrike = 0;
    int iBall = 0;
    
    SetBaseBallNumber(iBaseballNumber,3);
    cout << "정답 : " << iBaseballNumber[0] << '\t' << iBaseballNumber[1] << '\t' << iBaseballNumber[2] << '\n';
    cout << "=============================================\n";

    for(int i = 0; i < 9; i++)
    {
        cout << i + 1 << "회차\n";
        cout << "서로 다른 숫자 3개 입력 : ";
        cin >> iInputNumber[0] >> iInputNumber[1] >> iInputNumber[2];
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(iBaseballNumber[j] == iInputNumber[k])
                {
                    if(j == k) iStrike++;
                    else iBall++;
                }
            }
        }        
        cout << "스트라이크 : " << iStrike << " 볼 : " << iBall << '\n';

        if(iStrike == 3)
        {
            cout << "승리\n";
            break;
        }
        
        else if(i == 8)
        {
            cout << "패배\n";
            break;
        }

        else
        {
            iStrike = 0;
            iBall = 0;
        }
    }

    system("pause");
}

//2차원 배열을 이용하여 90도 시계 방향으로 4회전 출력하기
void RotateArray()
{
    int iArray[5][5] = {{1,2,3,4,5},
                         {6,7,8,9,10},
                         {11,12,13,14,15},
                         {16,17,18,19,20},
                         {21,22,23,24,25}};

    int iTempArray[5][5];
    cout << "원본\n";
    cout << "=============================================\n";
    ArrayRender(iArray,5);

    for(int i = 0; i < 4; i++)
    {
        cout << i + 1 << "번째 90도 시계방향 회전\n";
        cout << "=============================================\n";
        CopyArray(iTempArray,iArray);
    
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                iArray[k][4 - j] = iTempArray[j][k];
            }
        }
        ArrayRender(iArray,5);
        cout << "=============================================\n";
    }

    system("pause");
}

void CopyArray(int(*pTemp)[5], int(*pOriginal)[5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            pTemp[i][j] = pOriginal[i][j];
        }
    }
}

void Menu()
{
    int iInput = 0;
    while(true)
    {
        system("cls");
        cout << "1. 로또\n";
        cout << "2. 야구게임\n";
        cout << "3. 2차원 배열 회전\n";
        cout << "4. 종료\n";
        cout << "입력 : ";
        cin >> iInput;
        switch(iInput)
        {
            case 1:
                system("cls");
                Lotto();
                break;
            case 2:
                system("cls");
                BaseBallGame();
                break;
            case 3:
                system("cls");
                RotateArray();
                break;
            case 4:
                return;
            default:
                cout << "잘못된 입력입니다.\n";
                break;
        }
    }
}
