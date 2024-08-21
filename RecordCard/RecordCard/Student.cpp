#include "pch.h"
#include "Student.h"

// constructor
Student::Student(const char* name, const int korScore, const int engScore, const int mathScore)
{
	strcpy_s(mName, name);
	mKorScore = korScore;
	mEngScore = engScore;
	mMathScore = mathScore;
}

// copy constructor
Student::Student(const Student& other)
{
	strcpy_s(mName, other.mName);
	mKorScore = other.mKorScore;
	mEngScore = other.mEngScore;
	mMathScore = other.mMathScore;
}
