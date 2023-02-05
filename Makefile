CC = clang++
CFLAGS = -std=c++20 -Wall -Wextra

SRC = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
OBJ = $(SRC:.cpp=.o)

NAME = THTML

all: exe

run: all
	./$(NAME).exe

exe: $(OBJ)
	$(CC) -o $(NAME).exe $^

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	del /Q /S *.o
