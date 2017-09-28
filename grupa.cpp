#include "grupa.h"
using namespace std;
Grupa::Grupa()
{
    next = 0;
}

Grupa::~Grupa()
{
	for (int i = 0; i < counter; i++)
		delete[] names[i];
	delete names;
	delete[] name;
}

void Grupa::define_members(int counter)
{
	std::string str;
	for (int i = 0; i < counter; i++)
	{
		std::cout<< i << ". name: " << std::endl;
		getline(std::cin, str);
		names[i] = new char[str.length() + 1];
		strcpy(names[i], str.c_str());
		

		//std::cin.clear();
		//std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	display_members(counter);
	
}

void Grupa::display_members(int counter)
{
	std::cout << "MEMBERS: " << std::endl;
	for (int i = 0; i < counter; i++)
	{
		std::cout << i << ". "<< names[i] << std::endl;
	}
}
