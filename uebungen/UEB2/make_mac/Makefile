all: mandelbrot

mandelbrot: ../*.cpp
	g++ -std=c++11 -ggdb -o ../mandelbrot ../*.cpp

tests: ../*.cpp
	g++ -std=c++11 -DTESTS -I ../../gtest/include ../../gtest/lib/gtest_main.a -lgtest -lpthread -ggdb -o ../UEB2_tests ../*.cpp

run: mandelbrot
	drmemory -- postfix

run_tests: tests
	drmemory -- UEB2_tests

clean:
	rm -f ../mandelbrot.exe ../mandelbrot ../UEB*_tests.exe ../UEB*_tests *.o