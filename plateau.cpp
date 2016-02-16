#include "plateau.h"
#include "plateau.h"
#include <map>
#include <iostream>
#include "string.h"

/**
 * @brief [constructeur]
 * @details [constructeur avec argument]
 * @param n [nombre tablier en largeur]
 * @param m [nombre de tablier en longeur]
 * @param P_size [Taille dessous tableau]
 * @param m_log [pour construire avecrecopie]
 */
plateau::plateau(int n,int m, int P_size , FILE * m_log)
{
    m_size = n ;
    l_size=m ;
    petit_plateau=P_size;
    m_plateau = new int*[n];
    for(int i = 0;i < n; ++i) m_plateau[i] = new int[m];
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
void plateau::set2()
{ int i,j;
  std::cout << "Quelle ligne:" ;
  std::cin>>i;
  std::cout << "Quelle colonne:" ;
  std::cin>>j;
 if (m_plateau[i][j] == 1){
                          cout<<"deja utilisé !!"<<endl;
                          return;
                          }
  m_plateau[i][j] = 1;
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
    for(int i = 0;i < m_size;++i)
    {  if(i%petit_plateau==0 && i != 0)std::cout<<endl;
        for(int j = 0;j < l_size;++j)
        {   if(j%petit_plateau==0 && j != 0)std::cout <<"| ";
            double value = get(i,j);
            cout<< value;
            if(j != m_size - 1) cout<<" ";
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
        for(int i = 0;i < m_size && b;++i)
            for(int j = 0;j < m_size;++j)
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
 * @brief [destructeur]
 * @details [destructrion de l objet plateau]
 * @return [description]
 */
plateau::~plateau()
{
    for(int i = 0;i < m_size;++i) delete [] m_plateau[i];
    m_size = 0;
    delete [] m_plateau;
}


int main(int argc, char const *argv[]) {

int i,j,k,v,joueur;
char quitter;
std::cout<<endl<<" ----------------------- MENU -----------------------"<<endl<<endl;
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
    plateau p(k * v,j * v,v);
    p.display("tablier",v);

    while (quitter!='Q') {
                        quitter='v';
                        for (int h= 0;  h< joueur; ++h)
                        {

                        cout<<"joueur:"<<h<< endl;
                        p.set2();
                        p.display("tablier",v);
                      }
                        std::cout << "pour quitter : Q" << std::endl;
                        std::cout << "n'importe quelle touche pour continuer" << std::endl;
                        cin>> quitter;
                        
                      

                         }

        }

  return 0;
}
