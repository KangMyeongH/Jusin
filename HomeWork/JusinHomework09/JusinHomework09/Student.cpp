#include "pch.h"
#include "Student.h"

Student::Student()
{
	this->mName = nullptr;
	this->mKorScore = 0;
	this->mEngScore = 0;
	this->mMathScore = 0;
}

// 생성자
Student::Student(const std::string& name, const int korScore, const int engScore, const int mathScore)
{
	mName = name;
	mKorScore = korScore;
	mEngScore = engScore;
	mMathScore = mathScore;
}
// 복사 생성자
Student::Student(const Student& student)
{
	mName = student.mName;
	mKorScore = student.mKorScore;
	mEngScore = student.mEngScore;
	mMathScore = student.mMathScore;
}

// 소멸자
Student::~Student() = default;

// getter
std::string Student::GetName()					{ return mName; }
int Student::GetKorScore() const				{ return mKorScore; }
int Student::GetEngScore() const				{ return mEngScore; }
int Student::GetMathScore() const				{ return mMathScore; }
// setter
void Student::SetName(const std::string& name)	{ mName = name; }
void Student::SetKorScore(const int score)		{ mKorScore = score; }
void Student::SetEngScore(const int score)		{ mEngScore = score; }
void Student::SetMathScore(const int score)		{ mMathScore = score; }
