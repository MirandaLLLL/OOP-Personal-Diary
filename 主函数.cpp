#include"diary.h"

int main() {
	
	string start_Type;  
	getline(cin, start_Type);//first input which operation you want to use;
	while (start_Type != "end") {  //if you input "end", than the process will be terminated;
		if (start_Type == "pdadd") //if you want to add an diary;
			pdadd();
		if (start_Type == "pdlist")// if you want to list some diaries;
			pdlist();
		if (start_Type == "pdshow")//if you want to see the exact diary's text;
			pdshow();
		if (start_Type == "pdremove") {// if you want to remove an exact diary;
			pdremove();
		}
		getline(cin, start_Type);
	}
	system("pause");
	return 0;
}