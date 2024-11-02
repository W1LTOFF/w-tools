all: debug clean compile build run

CC = clang++ -std=c++23
PROJECT_NAME = wtools
COMPILER_FLAGS = -Wall -w
INCLUDE_FLAGS = -Iinclude 
LINKER_FLAGS = -Llib -lwtools
LIB_SRC = src/lib/*.cpp
SRC = src/main.cpp
ARGS = 

compile_lib:
	$(CC) $(EDITION_FLAGS) -c $(LIB_SRC) -Iinclude
	ar r $(PROJECT_NAME).lib *.o
	-rm lib/$(PROJECT_NAME).lib
	mv $(PROJECT_NAME).lib lib/
	rm *.o

compile:
	mkdir ./bin
	$(CC) $(EDITION_FLAGS) $(SRC) $(COMPILER_FLAGS) -o bin/$(PROJECT_NAME).exe $(INCLUDE_FLAGS) $(LINKER_FLAGS)

release:
	$(eval EDITION_FLAGS = -O3)
	$(eval EDITION = release)

debug:
	$(eval EDITION_FLAGS = --debug)
	$(eval EDITION = debug)

run:
	@echo "build/$(EDITION)/$(PROJECT_NAME).exe running..."
	@./build/$(EDITION)/$(PROJECT_NAME).exe $(ARGS)

build:
	mkdir -p ./build/$(EDITION)
	cp bin/$(PROJECT_NAME).exe build/$(EDITION)

clean:
	-rm -rf build
	-rm -rf bin
