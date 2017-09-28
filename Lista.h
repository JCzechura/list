#ifndef LISTA_H
#define LISTA_H
#include "grupa.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
class Lista
{
    typedef int (*MyFunction)(const void * , const void * );
   public:
        Grupa *first;
		int members_counter;
        void add_group ();
        void delete_group (int nr);
        void display_names () const;
        void sort_elements();
        Lista();
        virtual ~Lista();

    protected:

    private:
};

#endif // LISTA_H
