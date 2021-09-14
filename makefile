CPP = g++
FLAG = -O5 -Wall -W
RM = rm -f
EXEC = run 

OBJECTS = \
	  Main.o \
	  print.o \
	  insert_mode.o \
	  command_mode.o \

all: req $(OBJECTS) compile touch

Main.o : Main.cpp
	$(CPP) $(FLAGS) -c Main.cpp -lncurses
print.o : print.cpp
	$(CPP) $(FLAGS) -c print.cpp -lncurses
insert_mode.o : insert_mode.cpp
	$(CPP) $(FLAGS) -c insert_mode.cpp -lncurses
command_mode.o : command_mode.cpp
	$(CPP) $(FLAGS) -c command_mode.cpp -lncurses

clean :
	$(RM) $(OBJECTS) $(EXEC)
compile :
	$(CPP) $(FLAGS) $(OBJECTS) -o $(EXEC) -lncurses
touch :
	@echo " "
	@echo "Compilation done Successfully......"
	@echo " "
req :
	@echo "----------------------------------------------------------------------------------------------------------------------------------------------------------------"
	@echo "This programm requires an external library called Ncurses, to install it copy paste the command below in your terminal and hit enter(ignore if already present.)"
	@echo "sudo apt install libncurses5-dev libncursesw5-lib"
	@echo "----------------------------------------------------------------------------------------------------------------------------------------------------------------"	
