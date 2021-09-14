#include "global.h"
#include "command_mode.h"
#include "print.h"
#include "insert_mode.h"
	
void command_mode(vector<string> v,int &x,int &y,string file){//this function is for the command mode of the editor
	 int ascii;
	 while(1){
		ascii = getch();
		switch(ascii){
			case 'l'://if l or right key is pressed, move to right
                        case KEY_RIGHT :
                                                if(y<v[x].size()){
                                                        y++;
                                                }
                                                break;

			case 'h'://if h or left key is pressed, move to left
                        case KEY_LEFT :
                                                if(y>0){
                                                        y--;
                                                }
                                                break;

			case 'k'://if l or mo key is pressed, move to up
                        case KEY_UP :
                                                if(x>0){
                                                        x--;
                                                }
                                                if(y>v[x].size())
                                                        y=v[x].size();
                                                break;

			case 'j'://if l or right key is pressed, move to right
                        case KEY_DOWN :
                                                if(x<v.size()-1){
                                                        x++;
                                                }
                                                if(y>v[x].size())
                                                        y=v[x].size();

                                                break; 
			case 'i' :		{
							insert_mode(v,x,y,file);//if i is pressed, entre the insert mode
						}
						break;

			case ':' :		{//if colon is pressed, start taking inputs as a command
							int mx,my;
        						getmaxyx(stdscr,mx,my);
							string s="";
							char c = ':';
							move(mx,my);
							int t;
							while(c!='\n'){
								if(t==KEY_BACKSPACE){
									s.pop_back();
								}
								else s.push_back(c);
								print_footer(s,x,y);
								t = getch();
								c=t;
							}
							if(commands(s,v,file))return;//run the commands corresponding to the input
						}
						
					       break;	
		}
		print_page(v,x,y);//print the page

	}
}

bool commands(string s,vector<string> v,string file){//commands after : are executed here
	string line;
	int mx,my;
        getmaxyx(stdscr,mx,my);//get max value of x and y on the screen
	if(s==":w"){//if :w is pressed, update the file
		ofstream fout;
                                                fout.open(file);//open the the file
                                                for(int i=0;i<v.size();i++){
                                                        line = v[i];
                                                        fout << line <<endl;//write int the file
                                                }
                                                return false;//stay in the programm
	}
	if(s==":q"){//if :q is pressed
			ifstream fin(file);
                                                int  i =0;
                                                string err = "No write since last change (add ! to override)";//if there is no write from last change, dont do anyting
                                                while(getline(fin,line)){
                                                        if(v[i]!=line){
                                                                print_footer(err,mx-1,err.size());
                                                                getch();
								return false;
                                                        }
                                                        i++;
                                                }
                                                if(i!=v.size()){
                                                                print_footer(err,mx-1,err.size());
                                                                getch();
								return false;
                                                        }
                                                return true;//else exit the programm
	}
	if(s==":q!"){//exit the programm without changing the file
			return true;
        }
	if(s==":wq"){//write and exit the programm
                                                ofstream fout;
                                                fout.open(file);//open file
                                                for(int i=0;i<v.size();i++){
                                                        line = v[i];
                                                        fout << line <<endl;//write to file
                                                }
                                   
                     	                       return true;//exit the programm

        }
	
	string err = "Not an editor command: ";//rest of the commands are invalid here
                                                err.append(s);
                                                print_footer(err,mx-1,err.size());
                                                getch();
						return false;
}


