teste = ./bin/teste

BIN_DIR = ./bin
OBJ_DIR = ./build
LIB_DIR = ./lib
INC_DIR = ./include
SRC_DIR = ./src
DOC_DIR = ./doc
TEST_DIR = ./test

CC = g++

CPPFLAGS = -Wall -pedantic -std=c++11 -ansi -I. -I$(INC_DIR)
ARCHIVE = ar


.PHONY: linux

linux: arielslib.a arielslib.so prog_estatico prog_dinamico

#LINUX

arielslib.a: $(SRC_DIR)/arielslib.cpp $(INC_DIR)/arielslib.h $(INC_DIR)/arielslib_list.h $(INC_DIR)/arielslib_stack.h $(INC_DIR)/arielslib_queue.h $(INC_DIR)/arielslib_merge_sort.h $(INC_DIR)/arielslib_quick_sort.h $(INC_DIR)/arielslib_bubble_sort.h $(INC_DIR)/arielslib_selection_sort.h $(INC_DIR)/arielslib_insertion_sort.h $(INC_DIR)/arielslib_binary_search.h
		$(CC) $(CPPFLAGS) -c $(SRC_DIR)/arielslib.cpp -o $(OBJ_DIR)/arielslib.o
		$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/arielslib.o 
		@echo "+++ [Biblioteca estatica criada em $(LIB_DIR)/$@] +++"

arielslib.so: $(SRC_DIR)/arielslib.cpp $(INC_DIR)/arielslib.h $(INC_DIR)/arielslib_list.h $(INC_DIR)/arielslib_stack.h $(INC_DIR)/arielslib_queue.h $(INC_DIR)/arielslib_merge_sort.h $(INC_DIR)/arielslib_quick_sort.h $(INC_DIR)/arielslib_bubble_sort.h $(INC_DIR)/arielslib_selection_sort.h $(INC_DIR)/arielslib_insertion_sort.h $(INC_DIR)/arielslib_binary_search.h
		$(CC) $(CPPFLAGS) -fPIC -c $(SRC_DIR)/arielslib.cpp -o $(OBJ_DIR)/arielslib.o
		$(CC) -shared -fPIC -o $(LIB_DIR)/$@ $(OBJ_DIR)/arielslib.o
		@echo "+++ [Biblioteca dinamica criada em $(LIB_DIR)/$@] +++"

prog_estatico: $(INC_DIR)/test_tools.h $(INC_DIR)/keyboard_input.h $(INC_DIR)/input_exception.h
	$(CC) $(CPPFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/arielslib.a -o $(OBJ_DIR)/$@

prog_dinamico: $(INC_DIR)/test_tools.h $(INC_DIR)/keyboard_input.h $(INC_DIR)/input_exception.h $(INC_DIR)/alloc_exception.h
	$(CC) $(CPPFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/arielslib.so -o $(OBJ_DIR)/$@


dir:
	mkdir -p bin
	mkdir -p build
	mkdir -p include
	mkdir -p src
	mkdir -p doc
	mkdir -p lib
	mkdir -p test
