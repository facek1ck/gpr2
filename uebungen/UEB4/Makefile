all: fight-club

fight-club: *.cpp
	g++ -std=c++11 -ggdb -o fight-club *.cpp
	
tests: *.cpp
	g++ -std=c++11 -DTESTS -I../gtest/include ../gtest/lib/gtest_main.a -lpthread -ggdb -o UEB4_tests *.cpp

run: fight-club
	drmemory -- fight-club
	
run_tests: tests
	drmemory -- UEB4_tests
	
clean:
	rm -f fight-club.exe fight-club UEB*_tests.exe UEB*_tests *.o