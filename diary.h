#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<windows.h>

using namespace std;

typedef vector<string>::size_type VStringSize;


class PersonalDiary 
{
private:
	vector<string> text;
	int date;
public:
	void CreateDate(string);
	int GetDate();
	void Update();
	void AddLine(string);
	string GetText(VStringSize);
	VStringSize TextSize();
	void AddDiary(PersonalDiary);
};

void pdadd();
void pdlist();
void pdremove();
void pdshow();
