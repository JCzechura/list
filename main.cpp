#include <iostream>
#include <cstdlib>
#include "grupa.h"
#include "Lista.h"
using namespace std;
//test comm
int main()
{
    Lista my_list;
    int i = 0;
	int n;
	cin >> n;
    while(1)
    {
        cout << "MENU" << endl;
        cout << "1 - add new group" << endl;
        cout << "2 - display names" << endl;
        cout << "3 - sort elements" << endl;
		cout << "4 - delete group" << endl;
        cout << "5 - exit" << endl;
        cin>> i;

        switch(i)
        {
            case 1:
                cout << "______________________" << endl;
                my_list.add_group();
                break;
            case 2:
                my_list.display_names();
                break;
            case 3:
                my_list.sort_elements();
				break;
            case 4:
				std::cout << "number of group: (0 to n)" << std::endl;
				std::cin >> n;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "Not a valid number. Please reenter: ";
					cin >> n;
				}
				my_list.delete_group(n);
				break;
			case 5:
				exit(0);
            default: 	
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
				break;

        }
        cin.clear();
        cin.sync();
        }

    return 0;
}
