#include "pch.h"
#include "SaveStudentData.h"

SaveStudentData::SaveStudentData()
{
	this->mStudent = nullptr;
	this->mCount = 0;
}

SaveStudentData::~SaveStudentData()
{
	delete[] mStudent;
	mStudent = nullptr;
}

void SaveStudentData::AddData(const int count)
{
	if (this->mCount != 0)
	{
		Student* tempData = new Student[this->mCount + count];

		for(int i = 0; i < this->mCount; i++)
		{
			tempData->SetName(mStudent->GetName());
			tempData->SetKorScore(mStudent->GetKorScore());
			tempData->SetEngScore(mStudent->GetEngScore());
			tempData->SetMathScore(mStudent->GetMathScore());
		}

		for(int i = this->mCount; i < count; i++)
		{
			
		}
		delete[] this->mStudent;
		mStudent = tempData;
	}
}
