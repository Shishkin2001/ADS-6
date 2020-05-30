#include "bst.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include <string>

BST<std::string> makeTree(char* filename)
{
	std::string word;
	std::ifstream F(filename);
	BST<std::string> *tree = new BST<std::string>;
	char str = ' ';
	while (!F.eof()) {
	
		while ( str < 65 && (!F.eof()) ) 
		{
			F.get(str);
		}

while (  str >= 65  && (!F.eof()))
{
	if (str >= 65 && str <= 90)
	{
	
		word += str;	
	}
	if (str >= 97 && str <= 122)
	{
		word += str;
	}
	
	F.get(str);	
}
for (int i = 0; i < word.length(); i++)
{
	if (word[i] >= 65 && word[i] <= 90)
		word[i] += 32;
}

(*tree).add(word);
word = "";
	}

		
	
	return *tree;
}








int main() {
	
	char* filename = "war_peace.txt";
	BST<std::string> tree = makeTree(filename);
	int depth = tree.depth();
	std::cout << depth << std::endl;
	if (depth == 35)
		std::cout << "depth = 35. It's true!!!" << std::endl;
	else { std::cout << "1.No!" << std::endl; }

	int PierreCount = tree.search("pierre");
	std::cout << PierreCount << std::endl;
	if (PierreCount == 1963)
		std::cout << "PierreCount = 1963" << std::endl;
	else { std::cout << "2.No!" << std::endl; }
	 
	

	int NatashaCount = tree.search("natasha");
	std::cout << NatashaCount << std::endl;
	if (NatashaCount == 1212)
		std::cout << "NatashaCount = 1212" << std::endl;
	else { std::cout << "3.No!" << std::endl; }


	int AndrewCount = tree.search("andrew");
	std::cout << AndrewCount << std::endl;

	if (AndrewCount == 1143)
		std::cout << "AndrewCount = 1143" << std::endl;
	else { std::cout << "4.No!" << std::endl; }
	

	system("pause");
	return 0;
}
