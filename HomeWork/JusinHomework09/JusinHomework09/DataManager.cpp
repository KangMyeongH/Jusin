#include "pch.h"
#include "DataManager.h"

DataManager::DataManager()
{
	mStudents = nullptr;
	mStudentCount = 0;
}

DataManager::~DataManager()
{
	delete[] mStudents;
}
