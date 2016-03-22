#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
struct joueur
{
int color ;
bool Win ;
string name;

};

class plateau
{
    int nb_aligne;
    int petit_plateau;
    int m_size;
    int l_size;
    int ** m_plateau;
    FILE * m_log;
    joueur J[2];

    public :
        plateau(int n,int m,int, FILE * m_log = stderr);
        ~plateau();
        bool read(char * file_name);
        double get(int i, int j);
        void set(int i, int j, int value);
        void set2(int);
        void display(string plateau_name ,int &petit_plateau);
        void rotation(int, int ,char);
        bool test_colonne(int x, int y, int color);
        bool test_ligne(int x, int y, int color);
        bool test_diagonal_G(int x, int y, int color);
        bool test_diagonal_D(int x, int y, int color) ;
        bool Aligner();
        string Vainqueur();
        void name(string);
        string getname(int);

};


