all: postfix

postfix: *.cpp
	g++ -std=c++11 -ggdb -o postfix *.cpp
	
tests: *.cpp
	g++ -std=c++11 -DTESTS -I ../gtest/include ../gtest/lib/gtest_main.a -lpthread -ggdb -o UEB1_tests *.cpp

run: postfix
	drmemory -- postfix
	
run_tests: tests
	drmemory -- UEB1_tests
	
clean:
	rm -f postfix.exe postfix UEB*_tests.exe UEB*_tests *.o