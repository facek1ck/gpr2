all: connect4

connect4: ../*.cpp
	g++ -std=c++11 -ggdb -o ../connect4 ../*.cpp
	
tests: ../*.cpp
	g++ -std=c++11 -DTESTS -I ../../gtest/include ../../gtest/lib/gtest_main.a -lgtest -lpthread -ggdb -o ../UEB3_tests ../*.cpp

run: connect4
	drmemory -- connect4
	
run_tests: tests
	drmemory -- UEB3_tests
	
clean:
	rm -f ../connect4.exe ../connect4 ../UEB*_tests.exe ../UEB*_tests *.o