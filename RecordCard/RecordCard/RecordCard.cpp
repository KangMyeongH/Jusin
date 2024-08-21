#include "pch.h"
#include "RecordCard.h"

RecordCard::RecordCard()
{
	mDataManager = new DataManager;
}

RecordCard::~RecordCard()
{
	delete mDataManager;
}

using namespace std;
void RecordCard::MainMenu() const
{
    int inputNumber = 0;
    bool isInit = false;

    while (true)
    {
        system("cls");
        cout << "학생 성적표 프로그램\n";
        cout << "========================\n";
        cout << "1.입력 2.출력 3.종료\n";
        cout << "메뉴를 선택하세요.: ";
        cin >> inputNumber;

        system("cls");
        switch (inputNumber)
        {
        case 1:
            mDataManager->InitStudentsData();
            isInit = true;
            system("pause");
            break;

        case 2:
            if (isInit)
            {
                PrintData();
            }
            else
            {
                cout << "학생 정보를 먼저 입력해주세요.\n";
            }
            system("pause");
            break;

        case 3:
            cout << "프로그램을 종료합니다.\n";
            return;

        default:
            cout << "잘못된 입력입니다. 1 ~ 4 사이의 숫자로 다시 입력해주세요.\n";
            system("pause");
            break;
        }
    }
}

void RecordCard::PrintData() const
{
    for(int i = 0; i < mDataManager->GetStudentsCount(); i++)
    {
        cout << "이름: " << mDataManager->GetStudents()[i].GetName() << '\n';
        cout << "국어: " << mDataManager->GetStudents()[i].GetKorScore() << '\n';
        cout << "영어: " << mDataManager->GetStudents()[i].GetEngScore() << '\n';
        cout << "수학: " << mDataManager->GetStudents()[i].GetMathScore() << '\n';
        // cout << "총점: " << studentInfo->TotalScore << '\n';
        // cout << "평균: " << studentInfo->AvgScore << '\n';
        cout << "========================\n";
    }
}
