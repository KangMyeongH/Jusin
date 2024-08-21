#pragma once
#include <string.h>

class Student
{
public:
	Student();
	Student(const char* name, int korScore, int engScore, int mathScore);
	Student(const Student& other);
	~Student() = default;

	void SetName(const char* name) 			{ strcpy_s(mName, name); }
	void SetKorScore(const int korScore) 	{ mKorScore = korScore; }
	void SetEngScore(const int engScore) 	{ mEngScore = engScore; }
	void SetMathScore(const int mathScore) 	{ mMathScore = mathScore; }

	const char* GetName() const 			{ return mName; }
	int GetKorScore() const 				{ return mKorScore; }
	int GetEngScore() const 				{ return mEngScore; }
	int GetMathScore() const 				{ return mMathScore; }

private:
	int test;
	char mName[ 128 ];
	int mKorScore;
	int mEngScore;
	int mMathScore;
};

