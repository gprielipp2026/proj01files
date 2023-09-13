CXX=g++
CXXFLAGS=-Wall

all: readppm gray green rowshift shift

readppm: readppm.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

gray: gray.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

green: green.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

rowshift: rowshift.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

shift: shift.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@