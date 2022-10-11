#include"diary.h"

void pdshow() {
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
	int D;
	cin >> D;
	int i,j;
	for (i = 0; i < P_Diary.size(); i++) {  //find the diary whose date is equal with the input date;
		if (D == P_Diary[i].GetDate()) {
			for (j = 0; j < P_Diary[i].TextSize(); j++) {//output the diary;
				cout << P_Diary[i].GetText(j) << endl;
			}
			break;
		}
	}

	return;
}