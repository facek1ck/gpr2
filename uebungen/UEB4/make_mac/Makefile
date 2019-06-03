all: fightclub

fightclub: ../*.cpp
	g++ -std=c++11 -ggdb -o ../fightclub ../*.cpp
	
tests: ../*.cpp
	g++ -std=c++11 -DTESTS -I ../../gtest/include ../../gtest/lib/gtest_main.a -lgtest -lpthread -ggdb -o ../UEB4_tests ../*.cpp

run: fightclub
	drmemory -- fightclub
	
run_tests: tests
	drmemory -- UEB4_tests
	
clean:
	rm -f ../fightclub.exe ../fightclub ../UEB*_tests.exe ../UEB*_tests *.o