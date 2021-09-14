#include "insert_mode.h"
#include "global.h"
#include "print.h"

void insert_mode(vector<string> &v,int &x,int &y,string file){//function for the insert mode
	while(1){
		string c;
		int ascii = getch();//takes the input
		if(ascii==27){//if escape is pressed, go back to the command mode
//			string line;
//			for(int i=0;i<v.size();i++){
//				line = v[i];
//				fout << line <<endl;
//			}
			break;
		}
		c=ascii;
		switch(ascii){//switch cases for insert mode

			case KEY_RIGHT ://if right key is detected, move courser to right
						if(y<v[x].size()){
							y++;
						}
						break;
					
			case KEY_LEFT ://if left key is detected, move courser to left
						if(y>0){
							y--;
						}
						break;
					
			case KEY_UP ://if up key is detected, move courser upwards
						if(x>0){
                                                        x--;
                                                }
						if(y>v[x].size())
							y=v[x].size();
						break;
				      
			case KEY_DOWN ://if down key is detected, move courser downwards
						if(x<v.size()-1){
                                                        x++;
                                                }
						if(y>v[x].size())
                                                        y=v[x].size();

						break;
					
			case KEY_DC ://if del key is pressed, delete a char to the right
						if(y<v[x].size()){
							v[x].erase(y,1);
						}
						else if(y==v[x].size()){//if cursor is at the end, join the next line to the current line
							if(x<v.size()-1){
								string next = v[x+1];
								v[x].insert(y,next);
								v.erase(v.begin()+x+1);
							}
						}	
						break;
					
			case KEY_BACKSPACE ://if backspace is pressed, delete the char to the left
						if(y>0){
							v[x].erase(y-1,1);
							y--;
						}
						else if(y==0){//if cursor is at the starting point, move current line to the back of previous line
							if(x>0){
								string curr = v[x];
								v.erase(v.begin()+x);
								x--;
								y=v[x].size();
								v[x].insert(y,curr);
							}
						}	
						break;
					     
			case '\t' ://if tab is pressed, insert 8 spaces
						v[x].insert(y,"        "); 
						y+=8;
						break;
				    
			case 10 :{//if entre is pressed 	
					   if(y<v[x].size()){//if cursour is not at the end, break the line from current position and make it a new line	   
						   v.insert(v.begin()+x+1,v[x].substr(y,v[x].size()));
						   v[x].erase(y,v[x].size()-y);
					   }
					   else if(y==v[x].size()){//if cursour is at the end, insert a new line after current line
						   string temp;
                                                   v.insert(v.begin()+x+1,temp);
					   }
                        		x++;
                        		y=0;
				   }	
					break;
				  

			default: 		
					v[x].insert(y,c);//if any other key is pressed, insert it at the back of current line
                        		y++;
					if(c=="(")v[x].insert(y,")");//match paranthesis automatically
					if(c=="{")v[x].insert(y,"}");
					if(c=="[")v[x].insert(y,"]");
					if(c=="\"")v[x].insert(y,"\"");
					if(c=="'")v[x].insert(y,"'");
					break;
				 
		}
		//print_line(v,x,y);
		print_page(v,x,y);//print the page
		print_footer("-- INSERT --",x,y);//print the footer with x and y cordinates
	}

}


