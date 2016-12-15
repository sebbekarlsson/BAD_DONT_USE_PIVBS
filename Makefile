FLAGZ="-std=c++11"


output:\
        Memory.o\
    	Token.o\
	Else.o\
	If.o\
	Define.o\
	Declare.o\
	Print.o\
	Echo.o\
	main.o
	    g++\
		$(FLAGZ)\
		Memory.o\
		Token.o\
		Else.o\
		If.o\
		Define.o\
		Declare.o\
		Print.o\
		Echo.o\
		main.o\
		-o vbs

main.o: src/main.cpp
	g++ -std=c++11 -c src/main.cpp

Memory.o: src/Memory.cpp src/Memory.h
	g++ -std=c++11 -c src/Memory.cpp

Token.o: src/expressions/Token.cpp src/expressions/Token.h
	g++ -std=c++11 -c src/expressions/Token.cpp

If.o: src/expressions/If.cpp src/expressions/If.h
	g++ -std=c++11 -c src/expressions/If.cpp

Else.o: src/expressions/Else.cpp src/expressions/Else.h
	g++ -std=c++11 -c src/expressions/Else.cpp

Define.o: src/expressions/Define.cpp src/expressions/Define.h
	g++ -std=c++11 -c src/expressions/Define.cpp

Declare.o: src/expressions/Declare.cpp src/expressions/Declare.h
	g++ -std=c++11 -c src/expressions/Declare.cpp

Print.o: src/expressions/Print.cpp src/expressions/Print.h
	g++ -std=c++11 -c src/expressions/Print.cpp

Echo.o: src/expressions/Echo.cpp src/expressions/Echo.h
	g++ -std=c++11 -c src/expressions/Echo.cpp

clean:
	rm *.o
