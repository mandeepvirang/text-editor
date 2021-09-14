#include "print.h"
#include "global.h"

void print_page(vector<string> v,int x,int y){//print the page on the screen
	clear();//clear the screen
	int mx,my;
	getmaxyx(stdscr,mx,my);//get max value of x and y on screen
	int scroll;//enables scrolling if page is full
	mx-=2;
	scroll = max(0,x-mx);//if page is full, scroll some lines
	int i=0;
	for(i=scroll;i<min((int)v.size(),mx+scroll+1);i++){//start from scroll and print till the end of the screen
        	        if(i!=v.size()-1)printw("%s\n",v[i].c_str());
			else printw("%s",v[i].c_str());//if at the endline, dont print \n
       	}
	if(i==0)i++;
	move(i,0);
	for(;i<mx;i++){
		printw("~\n");//if some lines are empty, print ~ (just like vim)
	}
	if(x<=mx)move(x,y);
	else move(mx,y);//move to the original position
	refresh();//refresh
}

void print_footer(string s,int x,int y){//print footer in insert mode
	int mx,my;
        getmaxyx(stdscr,mx,my);
	move(mx-1,0);
	clrtoeol();
	printw("%s",s.c_str());
	mvprintw(mx-1,my-10,"%d,%d",x,y);
	if(x<mx-1)move(x,y);
	else move(mx-2,y);
	refresh();
}

void print_line(vector<string> v, int x, int y){//given x and y, print a specific line
	move(x,0);//move cursor to starting
	clrtoeol();//clear till the end of the line
	printw("%s",v[x].c_str());//print the line
	move(x,y);//print cursor to the original position
	refresh();//refresh
}

