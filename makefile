all: palindrome vertical selectionSort pheaders.h sheaders.h

vertical: vertical.cpp
	g++ vertical.cpp -o vertical -std=c++17 -Wall

palindrome: palindrome.cpp
	g++ palindrome.cpp pfunctions.cpp -o palindrome -std=c++17 -Wall

selectionSort: selectionSort.cpp
	g++ selectionSort.cpp sfunctions.cpp -o selectionSort -std=c++17 -Wall

clean:
	rm *.o vertical palindrome selectionSort
