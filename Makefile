all: run_example

EXAMPLE = main

cmake_build:
	-mkdir build
	cmake -G "MinGW Makefiles" -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ -S . -B build
	cd build; make

run:
	.\build\w-example.exe

run_example:
	cmake -G "MinGW Makefiles" -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ -S . -B build
	cd build; make
	build\\examples\\${EXAMPLE}.exe
