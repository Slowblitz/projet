#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std ;

class plateau
{
    int petit_plateau;
    int m_size;
    int l_size;
    int ** m_plateau;
    FILE * m_log;

    public :
        plateau(int n,int m,int, FILE * m_log = stderr);
        ~plateau();
        bool read(char * file_name);
        double get(int i, int j);
        void set(int i, int j, int value);
        void set2();
        void display(string plateau_name ,int &petit_plateau);
        void rotationmoin90(int, int );

};
