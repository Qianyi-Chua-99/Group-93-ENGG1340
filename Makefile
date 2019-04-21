Shop.o:Shop.cpp Shop.h
	g++ -c Shop.cpp
	
Commodity.o:Commodity.cpp Commodity.h
	g++ -c Commodity.cpp

test:test.cpp Commodity.o Shop.o
	g++ test.cpp Commodity.o Shop.o -o test

main:main.cpp Commodity.o Shop.o
	g++ main.cpp Commodity.o Shop.o -o main
