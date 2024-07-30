#define STUDENT_COUNT (3)  // NOLINT(modernize-macro-to-enum)
#define NAME_SIZE (128)  // NOLINT(modernize-macro-to-enum)

#include <iostream>
using namespace std;

/*
- 1. 입력 2. 출력 3. 검색 4. 종료
- 입력을 눌렀을 경우, 3명의 학생의 이름, 국어, 영어, 수학, 총점, 평균을 입력 받음
- 출력시에는 모든 학생의 성적 정보를 출력
- 검색 시에는 이름 검색을 하여 이름이 일치하는 학생의 성적표만 출력
*/

struct StudentInfo
{
    char Name[NAME_SIZE];
    int KorScore;
    int EngScore;
    int MathScore;
    int TotalScore;
    float AvgScore;
};

void StudentInfoSystem();
StudentInfo* FindStudentInfo(StudentInfo[], int);
void InitAllStudentInfo(StudentInfo[], int);
void PrintAllStudentInfo(StudentInfo[], int);
void PrintStudentInfo(const StudentInfo*);

int main()
{
    StudentInfoSystem();
    return 0;
}

void StudentInfoSystem()
{
    StudentInfo studentInfo[STUDENT_COUNT];
    int inputNumber = 0;
    bool isInit = false;
    
    while(true)
    {
        system("cls");
        cout << "학생 성적표 프로그램\n";
        cout << "========================\n";
        cout << "1.입력 2.출력 3.검색 4.종료\n";
        cout << "메뉴를 선택하세요.: ";
        cin >> inputNumber;

        system("cls");
        switch (inputNumber)
        {
        case 1:
            InitAllStudentInfo(studentInfo, STUDENT_COUNT);
            isInit = true;
            system("pause");
            break;

        case 2:
            if(isInit)
            {
                PrintAllStudentInfo(studentInfo, STUDENT_COUNT);
            }
            else
            {
                cout << "학생 정보를 먼저 입력해주세요.\n";
            }
            system("pause");
            break;

        case 3:
            if(isInit)
            {
                PrintStudentInfo(FindStudentInfo(studentInfo, STUDENT_COUNT));
            }
            else
            {
                cout << "학생 정보를 먼저 입력해주세요.\n";
            }
            system("pause");
            break;

        case 4:
            cout << "프로그램을 종료합니다.\n";
            return;

        default:
            cout << "잘못된 입력입니다. 1 ~ 4 사이의 숫자로 다시 입력해주세요.\n";
            system("pause");
            break;
        }
    }    
}

StudentInfo* FindStudentInfo(StudentInfo studentsInfo[], const int count)
{
    char inputName[NAME_SIZE] = {};

    while(true)
    {
        cout << "검색할 학생의 이름을 입력하세요: ";
        cin >> inputName;
    
        for(int i = 0; i < count; i++)
        {
            if(strcmp(studentsInfo[i].Name, inputName) == 0)
            {
                return &studentsInfo[i];
            }
        }
        cout << "해당하는 학생이 없습니다. 다시 입력해주세요.\n";
        system("pause");
        system("cls");
    }
}

void InitAllStudentInfo(StudentInfo studentsInfo[], const int count)
{
    for(int i = 0; i < count; i++)
    {
        system("cls");
        cout << i + 1 << "번째 학생 이름을 입력하세요: ";
        cin >> studentsInfo[i].Name;
        cout << studentsInfo[i].Name << " 학생의 국어 점수를 입력하세요: ";
        cin >> studentsInfo[i].KorScore;
        cout << studentsInfo[i].Name << " 학생의 영어 점수를 입력하세요: ";
        cin >> studentsInfo[i].EngScore;
        cout << studentsInfo[i].Name << " 학생의 수학 점수를 입력하세요: ";
        cin >> studentsInfo[i].MathScore;
        studentsInfo[i].TotalScore = studentsInfo[i].KorScore + studentsInfo[i].EngScore + studentsInfo[i].MathScore;
        studentsInfo[i].AvgScore = static_cast<float>(studentsInfo[i].TotalScore) / 3.0f;
    }
}

void PrintAllStudentInfo(StudentInfo studentsInfo[], const int count)
{
    for(int i = 0; i < count; i++)
    {
        PrintStudentInfo(&studentsInfo[i]);
    }
}

void PrintStudentInfo(const StudentInfo* studentInfo)
{
    cout << "이름: " << studentInfo->Name << endl;
    cout << "국어: " << studentInfo->KorScore << endl;
    cout << "영어: " << studentInfo->EngScore << endl;
    cout << "수학: " << studentInfo->MathScore << endl;
    cout << "총점: " << studentInfo->TotalScore << endl;
    cout << "평균: " << studentInfo->AvgScore << endl;
    cout << "========================\n";
}
