CXX = g++
CXXFLAGS = -Wall -g -I/usr/local/include -I/usr/include
LDFLAGS = -L/usr/local/lib -L/usr/lib -lSDL -lpthread -lboost_system
SOURCES = src/EngineManager.cpp src/Babble.cpp src/BaseObject.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = ./game

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS) $(LDFLAGS) -o $@
