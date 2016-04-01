start:
	reset
	g++ -std=c++11 -o main main.cpp  linkedList/linkedList.cpp 

clean:
	rm -rf main
