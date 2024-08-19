#pragma once

class SaveStudentData
{
public:
	SaveStudentData();
	~SaveStudentData();

	void AddData(int count);
private:
	Student* mStudent;
	int mCount;
};