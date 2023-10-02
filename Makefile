SRC=longest_palindromic_substring.cc
all :
	g++ -std=c++17 $(SRC) && ./a.out && rm -rf a.out*

dbg:
	g++ -std=c++17 $(SRC) -g
	lldb a.out

clean:
	rm -rf a.out*
