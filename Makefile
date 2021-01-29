CXX=g++
CXXFLAGS=-g
RM=rm -f

#L'executable principal
rogue : main.o board.h game.h pers.h
	$(CXX) $(CXXFLAGS) $^ -o $@

#Creation des .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<