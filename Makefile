FLAGZ="-std=c++11"


output:\
    	Token.o\
	Else.o\
	If.o\
	main.o
	    g++\
		$(FLAGZ)\
		Token.o\
		Else.o\
		If.o\
		main.o\
		-o asp

main.o: src/main.cpp
	g++ -std=c++11 -c src/main.cpp

Token.o: src/expressions/Token.cpp src/expressions/Token.h
	g++ -std=c++11 -c src/expressions/Token.cpp

If.o: src/expressions/If.cpp src/expressions/If.h
	g++ -std=c++11 -c src/expressions/If.cpp

Else.o: src/expressions/Else.cpp src/expressions/Else.h
	g++ -std=c++11 -c src/expressions/Else.cpp

clean:
	rm *.o
