#include"diary.h"

void pdremove() {
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
	int i;
	int judge = 0;
	for (i = 0; i < P_Diary.size(); i++) {  //find the exact diary whose date is equal with the input date;
		if (D == P_Diary[i].GetDate()) {  //if the diary with input date exist;
			break;
		}
		if (D < P_Diary[i].GetDate()) {  //if the diary with input date does not exist;
			judge = -1;
			break;
		}
	}
	if (judge == 0) {        //if the diary with input date exist;
		for (i; i < P_Diary.size() - 1; i++) {   //remove this diary from the P_Diary;
			P_Diary[i] = P_Diary[i + 1];
		}
		P_Diary.pop_back();
	}
	ofstream out("Diary.txt", ios::trunc);   //put all the diaries' data after removement into the file;
	int j;
	for (i = 0; i < P_Diary.size(); i++)
	{
		out << P_Diary[i].GetDate() << endl;

		for (j = 0; j < P_Diary[i].TextSize(); j++)
			out << P_Diary[i].GetText(j) << endl;
		out << "." << endl;
	}
	out.close();
	cout << judge << endl;//if succeed ,output 0; if not output -1;
	return;
}