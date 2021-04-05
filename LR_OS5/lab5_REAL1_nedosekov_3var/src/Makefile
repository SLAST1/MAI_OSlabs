CC = gcc

CCFLAGS = -g3 -Wall -pedantic 

LIB_PATH = ./libs

all: program1 program2

program1: program1.c program1.h $(LIB_PATH)/libshared1.so
	$(CC) $(CCFLAGS)   -o program1 program1.c -L $(LIB_PATH)/ -l shared1 -Wl,-rpath,$(LIB_PATH) 

program2: program2.c program2.h $(LIB_PATH)/libshared1.so $(LIB_PATH)/libshared2.so
	$(CC) $(CCFLAGS)  -o program2 program2.c -l dl 

$(LIB_PATH)/libshared1.so: 
	make --directory=$(LIB_PATH) 

$(LIB_PATH)/libshared2.so: 
	make --directory=$(LIB_PATH)  
clean:
	make clean --directory=$(LIB_PATH) 
	rm  program1 program2

