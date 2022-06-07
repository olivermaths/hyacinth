CPPFLAGS=-Wall -Wextra -std=c++17 -pedantic `pkg-config --cflags glfw3 gl`

LIBS=`pkg-config --libs glfw3 gl`

compile:
	clang++ $(CPPFLAGS) hyacinth/*.cpp sandbox/*.cpp ${LIBS} -o build/engine 

test:
	build/engine 

clean:
	rm -r build/*

run: compile test

	

