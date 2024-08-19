#pragma once
#include <string>

class Student
{
public:
	Student();
	Student(const std::string& name, int korScore, int engScore, int mathScore);
	Student(const Student& student);
	~Student();
	// getter
	std::string GetName();
	int GetKorScore() const;
	int GetEngScore() const;
	int GetMathScore() const;

	// setter
	void SetName(const std::string& name);
	void SetKorScore(const int score);
	void SetEngScore(const int score);
	void SetMathScore(const int score);

private:
	std::string mName;
	int mKorScore;
	int mEngScore;
	int mMathScore;
};
