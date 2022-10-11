#include"diary.h"

void pdlist() {
	int start_Date;   
	int over_Date;
	ifstream in("Diary.txt");
	string da;
	PersonalDiary temp_D;
	string line;
	vector<PersonalDiary> P_Diary;
	getline(in, da);
	while (!in.eof())    //put the exited diaries into the P_Diary;
	{
		temp_D.CreateDate(da);

		temp_D.Update();
		getline(in, line);
		while (line != ".")
		{
			temp_D.AddLine(line);
			getline(in, line);
		}
		P_Diary.push_back(temp_D);
		getline(in, da);
	}
	string fengexian = "-------------------------";
	cin >> start_Date;   //input the date of start;
	int i,j;
	if (start_Date == 0) {  //if the start_Date is 0, output all the existed diaries;
		for (i = 0; i < P_Diary.size(); i++) {
			cout << P_Diary[i].GetDate() << endl;
			for (j = 0; j < P_Diary[i].TextSize();j++) {
				cout << P_Diary[i].GetText(j) << endl;
			}
		}
	}
	else { 
		cin >> over_Date;   //input the terminated date;
		for (i = 0; i < P_Diary.size(); i++) {  //find out all the diaries whose date is between the start and terminated date;
			if (start_Date <= P_Diary[i].GetDate() && (over_Date >= P_Diary[i].GetDate())) {
				cout << P_Diary[i].GetDate() << endl;
				for (j = 0; j < P_Diary[i].TextSize(); j++) {
					cout << P_Diary[i].GetText(j) << endl;
				}
				
			}
			if (over_Date < P_Diary[i].GetDate())
				break;
		}
	}
	return;
}