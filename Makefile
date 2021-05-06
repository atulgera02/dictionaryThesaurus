CXX ?= g++
CXXFLAGS ?= --std=c++11 -Wall -Werror -pedantic -g

main.exe: Dictionary.cpp Thesaurus.cpp main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rvf *.out *.exe *.dSYM *.stackdump