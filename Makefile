Shop.o:Shop.cpp Shop.h
	g++ -std=c++11 -c Shop.cpp
	
Commodity.o:Commodity.cpp Commodity.h
	g++ -std=c++11 -c Commodity.cpp

main:main.cpp Commodity.o Shop.o
	g++ -std=c++11 main.cpp Commodity.o Shop.o -o main
