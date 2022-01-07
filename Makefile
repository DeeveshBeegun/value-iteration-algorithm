CC=g++
LIBS = -std=c++11
LIB = ./lib
DIR = ./src

value_iteration: value_iteration.o driver.o
	$(CC) -o value_iteration $(DIR)/Value_iteration.cpp $(DIR)/driver.cpp $(LIBS)

value_iteration.o: $(DIR)/Value_iteration.cpp $(DIR)/Value_iteration.h
	$(CC) -c -o $(DIR)/value_iteration.o $(DIR)/Value_iteration.cpp $(LIBS)

driver.o: $(DIR)/driver.cpp 
	$(CC) -c -o $(DIR)/driver.o $(DIR)/driver.cpp $(LIBS)

run:
	export LD_LIBRARY_PATH = ./value_iteration

clean:
	@rm $(DIR)/*.o
	@rm ./value_iteration