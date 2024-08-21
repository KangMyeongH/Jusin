#pragma once
class RecordCard
{
public:
	RecordCard();
	~RecordCard();
	void MainMenu() const;
	void PrintData() const;

private:
	DataManager* mDataManager;
};
