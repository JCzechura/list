#ifndef GRUPA_H
#define GRUPA_H
#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <stdio.h>

class Grupa
{
    public:
        int counter;
        char* name;
        char** names;
        Grupa* next;

        Grupa();
        virtual ~Grupa();
		void define_members(int counter);
		void display_members(int counter);
    protected:

    private:
};

#endif // GRUPA_H
