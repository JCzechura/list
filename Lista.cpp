#include "Lista.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;
int compare (const void * , const void * );
Lista::Lista()
{
    first = 0;
	members_counter = 0;
}

Lista::~Lista()
{

}
void Lista::add_group ()
{
	std::cin.clear();
	std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Grupa *new_g = new Grupa();
    std::string str;
    int i = 0;

    std::cout << "name: "<<  std::endl;
    getline(std::cin,str);
    std::cout << "number of members: "<<  std::endl;
    std::cin >> i;
	while (cin.fail() || (i == 0))
	{
		cin.clear();
		cin.ignore();
		cout << "Not a valid number. Please reenter: ";
		cin >> i;
	}
	cin.clear();
	cin.sync();
	std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    new_g->name = new char[str.length() + 1];
    strcpy(new_g->name, str.c_str());
    new_g->counter = i;
    new_g->names = new char*[i];
	new_g->define_members( i );
    if (first==0)
    {
        first = new_g;
    }
    else
    {
        Grupa *temp = first;
        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = new_g;
        new_g->next = 0;
    }
	members_counter++;
}
void Lista::display_names() const
{
	std::cout << "NAMESSSS: " << std::endl;
    if (first==0)
    {
       std::cout<<"first = 0"<<std::endl;
    }
    else
    {
        Grupa *temp = first;
        do
        {
            std::cout<<temp->name<<endl;
			for (int i = 0; i < temp->counter; i++)
			{
				std::cout <<"- "<< i << ". " << temp->names[i] << std::endl;
			}
            std::cout<<std::endl<<"__________"<<std::endl;
            temp = temp->next;
        }while(temp);
    }
}
void Lista::sort_elements()
{
     int i = 0;
     Grupa *temp = first;

    std::cout<< members_counter <<" elements"<<std::endl;
    Grupa **sort_array = new Grupa*[i];
    temp = first;
    while (temp)
    {
        sort_array[i] = temp;
        temp = temp->next;
        i++;
    }
    qsort (sort_array, i, sizeof(Grupa*),compare);
	std::cout << "POSORTOWANA TABLICA :"<<std::endl;
    for(int j = 0; j<i; j++)
    {
        std::cout<<sort_array[j]->name;
        std::cout<<std::endl<<"__________"<<std::endl;
    }
	first = *sort_array;
	std::cout << "0: " << first->name<<std::endl;
	temp = first; 
	for (int j = 1; j<i; j++)
	{
		
		temp->next = *(sort_array + j);
		temp = temp->next;
	}
	temp->next = 0;
	display_names();
}
void Lista::delete_group (int nr)
{
	if ((nr > (members_counter-1)) || (first == 0))
		std::cout << "group not found" << std::endl;
	else
	{
		Grupa *temp = first;
		Grupa *temp1 = temp;
		if (nr == 0)
		{
			first = first->next;
			delete temp;
		}
		else
		{
			for (int i = 0; i < nr; i++)
			{
				temp1 = temp;
				temp = temp->next;
			}
			temp1->next = temp->next;
			delete temp;
		}
			display_names();
			members_counter--;
		
	}
}
int compare (const void * a, const void * b)
{
    Grupa ** aa =  (Grupa**) a;
    Grupa ** bb = (Grupa**) b;
    return (strcmp((*aa)->name, (*bb)->name));
}

