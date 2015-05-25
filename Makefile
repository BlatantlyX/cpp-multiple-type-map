all: testexe

testexe: test.o
	$(CXX) -std=c++11 test.o -o testexe

test.o: test.cpp mtypemap.hpp
	$(CXX) -std=c++11 -g -c test.cpp -o test.o
