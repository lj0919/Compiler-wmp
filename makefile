all: parser

clean:
	rm parser.cpp parser.hpp parser lex.cpp

parser.cpp: parser.y
	bison -d -o $@ $^

parser.hpp: parser.cpp

lex.cpp: lex.l parser.hpp
	lex -o $@ $^

parser: parser.cpp main.cpp lex.cpp
	g++ -o parser parser.cpp lex.cpp main.cpp