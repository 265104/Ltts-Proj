# # Name of the project
# PROJECT_NAME = Employees Management System

# # Output directory
# BUILD = build

# # All source code files
# SRC = main.c\Emp.c
# src/Emp.c

# # All test source files
# TEST_SRC = src/Emp.c\main.c
# test/test_test.c

# TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).out

# # All include folders with header files
# INC	= -Iinc\Emp.h
OBJS	= main.o Emp.o
SOURCE	= main.c Emp.c
HEADER	= Emp.h
OUT	= main.exe
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

Emp.o: Emp.c
	$(CC) $(FLAGS) Emp.c 


clean:
	rm -f $(OBJS) $(OUT)


# # Project Output name
# PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out

# # Document files
# DOCUMENTATION_OUTPUT = documentation/html

# # Default target built
# $(PROJECT_NAME):all

# # Run the target even if the matching name exists
# .PHONY: run clean test doc all

# all: $(SRC) $(BUILD)
# 	gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT).out

# # Call `make run` to run the application
# run:$(PROJECT_NAME)
# 	./$(PROJECT_OUTPUT).out

# # Document the code using Doxygen
# #doc:
# #	make -C ./documentation

# # Build and run the unit tests
# test:$(BUILD)
# 	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
# 	./$(TEST_OUTPUT)
# #Coverage
# coverageCheck:$(BUILD)
# 	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
# 	./$(TEST_OUTPUT)

# # Remove all the built files, invoke by `make clean`
# clean:
# 	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)

# # Create new build folder if not present
# $(BUILD):
# 	mkdir build
