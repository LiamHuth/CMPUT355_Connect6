MODULES = main
OBJ = $(patsubst %, obj/%.o, $(MODULES))
TARGET = program

CXX = g++
CXXFLAGS = -O2 -Wall

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
