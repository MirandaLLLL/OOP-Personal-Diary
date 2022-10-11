#include"diary.h"



string PersonalDiary::GetText(VStringSize i) {   //get the text of an exact diary;
	return text[i];
}

void PersonalDiary::CreateDate(string Date) {   //set the date of a new diary
	date = atoi(Date.c_str());
}
int PersonalDiary::GetDate() {       //get the date of an exact diary;
	return date;
}

void PersonalDiary::Update() {   //clear the text of an exact diary;
	text.clear();
}

void PersonalDiary::AddLine(string Line)  //add things into an exact diary line by line;
{
	text.push_back(Line);
}
VStringSize PersonalDiary::TextSize() {  //get the size of an exact diary's text;
	return text.size();
}


