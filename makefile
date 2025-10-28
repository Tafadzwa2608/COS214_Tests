CXX = C:/Tools/mingw64/bin/g++.exe
CXXFLAGS = -Wall -Wextra -std=c++17 -g
TARGET = main.exe

# Automatically find all .cpp files in the folder
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -mconsole $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del $(OBJ) $(TARGET)
