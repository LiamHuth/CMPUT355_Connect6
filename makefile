MODULES = main ConnectGame Board userPlayer randomPlayer utils
OBJ = $(patsubst %, obj/%.o, $(MODULES))
TARGET = connect6

CXX = g++
CXXFLAGS = -O2 -Wall -std=c++11

compile: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	make compile
	./$(TARGET)

new:
	make clean
	make compile

clean:
	rm -f $(TARGET) obj/*.o
