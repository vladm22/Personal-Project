#include "header.h"
#include <vector>

Carte::Carte(int num,std::string nom)
{
    m_num=num;
    m_nom=nom;
}
Carte::~Carte()
{

}
int Carte::getNum()const
{
    return m_num;
}
std::string Carte::getNom()const
{
    return m_nom;
}
void Carte::setNum(int num)
{
    m_num=num;
}
void Carte::setNom(std::string nom)
{
    m_nom=nom;
}


Carte_Lieu::Carte_Lieu(int num, std::string nom,int tab[9])
    :Carte(num, nom)
{
    for(int i=0; i<9 ; i++)
    {
        m_lieu.push(tab[i]);
        std::cout<< m_lieu.top()<<std::endl;
    }
}
Carte_Lieu::~Carte_Lieu()
{

}
 int Carte_Lieu::tirerUneCarte()
 {
     int a;
     a=m_lieu.top();
     m_lieu.pop();
     return a;
 }
 int Carte_Arme::tirerUneCarte()
 {
     int a;
     a=m_arme.top();
     m_arme.pop();
     return a;
 }
 int Carte_Personnage::tirerUneCarte()
 {
     int a;
     a=m_personnage.top();
     m_personnage.pop();
     return a;
 }
Carte_Arme::Carte_Arme(int num, std::string nom,int tab[9])
    :Carte(num, nom)
{
    for(int i=0; i<9 ; i++)
    {
        m_arme.push(tab[i]);
        std::cout<< m_arme.top()<<std::endl;
    }
}
Carte_Arme::~Carte_Arme()
{

}

Carte_Personnage::Carte_Personnage(int num, std::string nom,int tab[6])
    :Carte(num, nom)
{
    for(int i=0; i<6 ; i++)
    {
        m_personnage.push(tab[i]);
        std::cout<< m_personnage.top()<<std::endl;
    }
}
Carte_Personnage::~Carte_Personnage()
{

}
