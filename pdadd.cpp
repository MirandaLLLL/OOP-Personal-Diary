#include"diary.h"

void pdadd() {
	string da;
	PersonalDiary temp_D;  //to store the temp Diary;
	vector<PersonalDiary> P_Diary;//to store all the existed diary;
	string line;
	ifstream in("Diary.txt");//read the diary;
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
	in.close();


	temp_D.Update();//clear the temp Diary ;


	getline(cin, da);//input the new diary's date 
	temp_D.CreateDate(da);
	getline(cin, line);//input the new diary's text;
	while (line != ".")
	{
		temp_D.AddLine(line);
		getline(cin, line);
	}
	int i;
	int size;
	size = P_Diary.size();
	int judge = 0;
	int d= atoi(da.c_str()); //transfer the type to compare the date and put the diaries in order;
	for (i = 0; i < size; i++) {
		if (P_Diary[i].GetDate() == d) {  //if the date has existed
			judge = 1;
			break;
		}
		if (P_Diary[i].GetDate() > d) {   //if the date has not existed but earlier than some existed diaries's dates
			judge = 2;
			break;
		}
	}
	if (judge == 0) {
		P_Diary.push_back(temp_D);  //if the date is later than any existed diary's date;

	}
	if(judge==1) {

		P_Diary[i] = temp_D;  //if the date has  existed,replace the old one;
	}
	if (judge == 2) {    //if the date is earlier than some existed diaries's dates, put the new one into the P_Diary  in the right order;
		PersonalDiary T;
		for (i; i < size; i++) {
			T = P_Diary[i];
			P_Diary[i] = temp_D;
			temp_D = T;
		}
		P_Diary.push_back(temp_D) ;
	}
	

	ofstream out("Diary.txt", ios::trunc);  
	int j;
	for (i = 0; i <P_Diary.size(); i++)  //put all the diaries' data into the file;
	{
		out << P_Diary[i].GetDate() << endl;

		for (j = 0; j < P_Diary[i].TextSize(); j++)
			out << P_Diary[i].GetText(j) << endl;
		out << "." << endl;
	}
	out.close();
	return ;
}
	