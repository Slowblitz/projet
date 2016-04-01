#include "plateau.h"
#include "plateau.h"
#include <map>
#include <iostream>
#include "string.h"
#include <stdlib.h>
/**
 * @brief [constructeur]
 * @details [constructeur avec argument]
 * @param n [nombre tablier en largeur]
 * @param m [nombre de tablier en longeur]
 * @param P_size [Taille dessous tableau]
 * @param m_log [pour construire avecrecopie]
 */
plateau::plateau(int n,int m, int P_size ,int pion, FILE * m_log)
{
  nb_aligne = pion;
    c_size = n ;
    l_size=m ;
    petit_plateau=P_size;
    m_plateau = new int*[n];
    for(int i = 0;i < c_size; ++i)
      m_plateau[i] = new int[l_size];

    for(int l=0 ; l < c_size; l++)
        for (int v = 0; v < l_size; v++)
        {
          m_plateau[l][v]=0;
        }

    for (int i = 0; i < 2; ++i)
    {
      J[i].color=i+1;
      J[i].Win=0;
    }
}

/**
 * @brief [getter]
 * @details [long description]
 * 
 * @param i [indice de ligne ]
 * @param j [indice de colone]
 * 
 * @return [retour]
 */

double plateau::get(int i, int j)
{
    return m_plateau[i][j];
}

/**
 * @brief [setter]
 * @details [set une valeur avec les indice]
 * 
 * @param i [indice de ligne]
 * @param j [indice de colone]
 * @param value [valeur assigner a la case]
 */
void plateau::set(int i, int j, int value)
{
  m_plateau[i][j] = value;
}

/**
 * @brief [setter]
 * @details [setter sans argument ]
 */
void plateau::set2(int value)
{ int i,j;
  std::cout << "Quelle ligne:" ;
  std::cin>>i;
  std::cout << "Quelle colonne:" ;
  std::cin>>j;
 if (m_plateau[i][j] != 0){
                          cout<<"deja utilisé !!"<<endl;
                          return set2(value);
                          }
  m_plateau[i][j] = J[value].color;
}

 /**
  * @brief [affichage]
  * @details [affichage]
  * 
  * @param plateau_name [nom du plateau]
  * @param petit_plateau [nombre de petits tableau]
  */
void plateau::display(string plateau_name,int &petit_plateau)
{
  std::cout << plateau_name << endl;
    for(int i = 0;i < c_size;++i)
    {  if(i%petit_plateau==0 && i != 0)std::cout<<endl;
        for(int j = 0;j < l_size;++j)
        {   if(j%petit_plateau==0 && j != 0)std::cout <<"| ";
            cout<<m_plateau[i][j];
        if(j != c_size - 1) cout<<" ";
        }
     cout<<endl;
    }

    cout<<endl;
}

/**
 * @brief [ecrire]
 * @details [lire une matrice a partir d'un fichier texte pour relancer une partie enregistré]
 * 
 * @param file_name [nom de la sauvgarde]
 * @return [retour]
 */
bool plateau::read(char * file_name)
{
    bool b = true;
    FILE * in = fopen(file_name, "r");

    if(in == NULL)
    {
        b = false;
    }
    else
    {
        for(int i = 0;i < c_size && b;++i)
            for(int j = 0;j < c_size;++j)
            {
                double value;
                b = (fscanf(in, "%lf", &value) == 1);
                if(b)
                {
                    set(i,j,value);
                }
                else
                {
                    break;
                }
                
              
              }
    }
return b;

}
/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param k [description]
 * @param l [description]
 * @param c [description]
 */

void plateau::rotation(int k, int l,char c)
{
  int tmp[petit_plateau][petit_plateau];
  for (int i = 0; i < petit_plateau; ++i)
  {
    for (int j = 0; j < petit_plateau; ++j)

    {
    if (c=='<')
      tmp[petit_plateau-1-j][i] = m_plateau[i+k][j+l];
  	else
  		tmp[j][petit_plateau-1-i] = m_plateau[i+k][j+l];
    }
  }

  for (int i = 0; i < petit_plateau; ++i)
  {
    for (int j = 0; j < petit_plateau; ++j)
    {
      m_plateau[i+k][j+l] = tmp[i][j];
    }
  }
}


/**
 * @brief [destructeur]
 * @details [destruction de l objet plateau]
 * @return [description]
 */
plateau::~plateau()
{
    for(int i = 0;i < c_size;++i) delete [] m_plateau[i];
    c_size = 0;
    delete [] m_plateau;
}




string plateau::Vainqueur() {
  if (J[0].Win == true){return J[0].name;}
  else {return J[0].name;}
} 

bool plateau::Aligner() {
  int tmp = 0;
  bool btmp = false;
  for (int i = 0; i < l_size; ++i)
  {
    for (int j = 0; j < c_size; ++j)
    {
      if (m_plateau[i][j] != 0)
      {
        tmp = m_plateau[i][j];
        

        if(((c_size-j)+(l_size-i) > nb_aligne) && ((j+nb_aligne-1) < l_size && (i+nb_aligne-1) < l_size)){
          btmp = test_diagonal_D(i,j,tmp);
          if (btmp == true) {J[tmp-2].Win = true; return true;}
        } //fonction diagonal >
        if (( (c_size-j)+(l_size-i) > nb_aligne) && ((j-nb_aligne+1) >= 0 ) && ((i+nb_aligne-1) < l_size)) {
          btmp = test_diagonal_G(i,j,tmp);
          if (btmp == true) {J[tmp-1].Win = true; return true;}  
        } //fonction diagonal <
        if ((c_size-i)>= nb_aligne) {
          btmp = test_ligne(i,j,tmp);
          if (btmp == true) {J[tmp-1].Win = true; return true;}
        }// on test la ligne
        if ((l_size-j)>= nb_aligne) {
          btmp = test_colonne(i,j,tmp);
          if (btmp == true) {J[tmp-1].Win = true; return true;}
        }// on test la colonne
      }
    }
  }
  return false;
}
bool plateau::test_diagonal_D(int x, int y, int color) {
  int compteur = 0;
  while(m_plateau[x][y] == color) {
    compteur++,x++,y++;
    if(compteur >= nb_aligne) return true;
  }
  return false;
}
bool plateau::test_diagonal_G(int x, int y, int color) {
  int compteur = 0;
  while(m_plateau[x][y] == color) {
    compteur++,x++,y--;
    if(compteur >= nb_aligne) return true;
  }
  return false;
}
bool plateau::test_ligne(int x, int y, int color) {
  int compteur = 0;
  while(m_plateau[x][y] == color) {
    compteur++,y++;
    if(compteur >= nb_aligne) return true;
  }
  return false;
}
bool plateau::test_colonne(int x, int y, int color) {
  int compteur = 0;
  while(m_plateau[x][y] == color) {
    compteur++,x++;
    if(compteur >= nb_aligne) return true;
  }
  return false;
}

void plateau::name(string s )
{
  if (J[0].name !="")
    J[1].name =s;
  else 
    J[0].name =s;

}
string plateau::getname(int x )
{
 return J[x].name;

}