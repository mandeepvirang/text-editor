This is a terminal-based text editor for Linux.
\
\
Requirements:\
This programm requires an external library called Ncurses, to install it copy paste the command below in your terminal and hit enter(ignore if already present.)"\
"sudo apt install libncurses5-dev libncursesw5-lib"

Getting Started:\
	1. Clone the git repo into any directory\
	2. Install the requirements\
	3. open terminal and type "cd /path/to/directory"\
	4. entre "make" command, it will generate a object file named "run"\
	5. to run the text editor, type "./run" and type the file name\
	6. initially you will entre the command mode, to goto the insert mode, press i\
	7. to go back to the command mode, press "esc"\


Commands supported:\
	1. 'i' : to entre the insert mode\
	2. 'esc' : to entre command mode\
	3. ':w' : to save the file\
	4. ':q' : to quit the programm\
	5. ':q!' : to quit the programm without saving the file\
	6. ':wq' : to save the file and quit the programm\

