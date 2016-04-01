#include "plateau.h"
#include <iostream>




int main(int argc, char const *argv[]) {

int i,j,k,v,joueur,xrot,yrot,pions=0;
string nom,WIN;
char Srot;
char quitter;
std::cout<<std::endl<<" ----------------------- MENU -----------------------"<<std::endl<<std::endl;
std::cout << "1/ commencer une nouvelle partie" << std::endl;
std::cout << "2/ quitter" << std::endl<<std::endl;
std::cin >> i;

if (i==1) {


    std::cout << "Nombre de joueur: ";
    std::cin >> joueur;
    std::cout << "Longeur du tablier : ";
    std::cin >> j;
    std::cout<<"Largeurdu tablier : ";
    std::cin >> k;
    std::cout<<"case des petits plateaux :";
    std::cin >> v;
    std::cout<<"combien de pions pour gagner:";
    std::cin >> pions;
    plateau p(k * v,j * v,v,pions);
    p.display("tablier",v);
    int k(1);
    for (int i = 0; i < joueur; ++i)
    { std::cout<<"entrer les nom du joueur : "<<i+1<<std::endl ;
      std::cin>>nom;
      p.name(nom);
    }
    while (!p.Aligner()) {
                          system("clear");
                          p.display("tablier",v);
                          if (k%joueur == 1)
                            k-=joueur-1;
                          else 
                            k++;
                          std::cout<< "joueur : "<<p.getname(k)<<std::endl;
                          p.set2(k);
                          system("clear");
                          p.display("tablier",v);
                          std::cout<<"rotation :"<<std::endl;
                          std::cout<<"entrer les coordonées du petit plateau : "<<std::endl;
                          std::cin>>xrot;
                          std::cin>>yrot;
                          std::cout<<"Sens de la rotation </> : "<<std::endl;
                          std::cin>>Srot;
                          p.rotation(xrot,yrot,Srot);
      
                         }

                         cout<<"<"<<p.Vainqueur()<<">"<<endl;

  
  }


}
