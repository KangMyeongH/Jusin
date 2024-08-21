#include "pch.h"
#include "DataManager.h"

// default constructor
DataManager::DataManager()
{
	mStudents = nullptr;
	mStudentsCount = 0;
}

DataManager::~DataManager()
{
	delete[] mStudents;
}

using namespace std;
void DataManager::InitStudentsData()
{
	system("cls");
	int count = 0;
	if(!mStudents)
	{
		cout << "입력할 학생 수를 입력하세요. : ";
		cin >> count;
		mStudents = new Student[count];
	}
	
	else
	{
		cout << "추가할 학생 수를 입력하세요. : ";
		cin >> count;
		const Student* oldData = mStudents;
		mStudents = new Student[count + mStudentsCount];

		for(int i = 0; i < mStudentsCount; i++)
		{
			mStudents[i] = oldData[i];
		}
		delete[] oldData;
	}
	
	for(int i = mStudentsCount; i < count + mStudentsCount; i++)
	{
		char name[128]{};
		int korScore = 0;
		int engScore = 0;
		int mathScore = 0;

		cout << i + 1 << "번째 학생 이름을 입력하세요: ";
		cin >> name;
		mStudents[i].SetName(name);

		cout << mStudents[i].GetName() << " 학생의 국어 점수를 입력하세요: ";
		cin >> korScore;
		cout << mStudents[i].GetName() << " 학생의 영어 점수를 입력하세요: ";
		cin >> engScore;
		cout << mStudents[i].GetName() << " 학생의 수학 점수를 입력하세요: ";
		cin >> mathScore;

		mStudents[i].SetKorScore(korScore);
		mStudents[i].SetEngScore(engScore);
		mStudents[i].SetMathScore(mathScore);
	}
	
	mStudentsCount += count;
}