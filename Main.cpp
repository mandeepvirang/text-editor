#include "print.h"
#include "insert_mode.h"
#include "command_mode.h"
#include "global.h"


int main(int argc, char **argv){
	
	string file;
	if(argc<=1){//if file name is not given as arg, take it as a inp
		cout << "Entre the file name : "<<endl;
		cin >> file;
	}
	else file = argv[1];

	vector<string> v;//make a vector to store the buffer of text
	string line;
	
	ifstream fin(file);//open the file
	while(getline(fin,line)){
		v.push_back(line);//save file to the buffer
	}
	fin.close();//close the file

	ofstream fout;
	fout.open(file);//open the file again

	initscr();//initialize the screen for the editor
	raw();				// Line buffering disabled for the input text
	keypad(stdscr, TRUE);		// to recieve the keyboard keys directly like F1,F2 etc
	noecho();			// disables echo while we get character using getch 
	
	print_page(v,0,0);//print the initial page
	int x = 0,y = 0;
	move(y,x);//move cursor to the starting of the page
	string s;
	if(v.size()==0)v.push_back(s);//if file is empty, insert a empty line in th text buffer
	
	command_mode(v,x,y,file);//goto the command mode(from there we can go to insert mode by pressing i);
	
	endwin();//end the screen
	
	fout.close();//close the file
	return 0;
}

