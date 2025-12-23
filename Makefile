all: ; g++ -std=c++23 -DZAP -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG sol.cpp -o sol

