#pragma once
#include <iostream>
#include "Student.h"

class DataManager
{
public:
	DataManager();
	~DataManager();

	void InitStudentsData();

	// getter
	const Student* GetStudents() const 		{ return mStudents; }
	int GetStudentsCount() const 			{ return mStudentsCount; }
private:
	Student* mStudents;
	int mStudentsCount;
};