#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <vector>


class Perso
{
private :
    int m_posx;
    int m_posy;
    int m_logo;
    int m_main[11];
    std::string m_nom;
    std::string m_motdepasse;
    int m_hypothese;
    int m_NbParties;

public :

    Perso(int posx,int posy, int logo, int m_main[11], std::string nom,std::string motdepasse , int NbParties);
    Perso();
    ~Perso();

    int getposX()const;
    int getposY()const;
    int getLogo()const;
    int getHypothese()const;
    int getMain(int i)const;
    int getNbParties()const;
    std::string getNom()const;
    std::string getMotDePasse()const;
    void setposX(int posx);
    void setposY(int posy);
    void setLogot(int logo);
    void setMain(int main, int emplacement);
    void setNom(std::string nom);
    void setMotDePasse(std::string motdepasse);
    void setNbParties(int NbParties);
    void setHypothse(int hypothese);
    void afficher();

    void afficher_main(BITMAP *page, BITMAP *perso[6], BITMAP *arme[9], BITMAP *lieux[9]);
    int Nombre_de_joueur(BITMAP *page,BITMAP *fond);
};



class Carte
{
protected :
    int m_num;
    std::string m_nom;

public :

    Carte(int num,std::string nom);
    ~Carte();

    int getNum()const;
    std::string getNom()const;
    void setNum(int num);
    void setNom(std::string nom);
};


class Carte_Lieu: public Carte
{
private :
    std::stack<int >m_lieu;

public :
    Carte_Lieu( int num, std::string nom,int tab[9]);
    ~Carte_Lieu();

    int tirerUneCarte();
};

class Carte_Arme: public Carte
{
private :
    std::stack<int >m_arme;

public :
    Carte_Arme( int num, std::string nom,int tab[6]);
    ~Carte_Arme();

    int tirerUneCarte();
};

class Carte_Personnage: public Carte
{
private :
    std::stack<int >m_personnage;

public :
    Carte_Personnage( int num, std::string nom,int tab[6]);
    ~Carte_Personnage();

    int tirerUneCarte();
};



class Chambre
{
protected :
    int m_passage_x;
    int m_passage_y;

public :

    Chambre(int passage_x,int passage_y);
    ~Chambre();

    void affichage(BITMAP *page,BITMAP *fond, BITMAP *perso[6], BITMAP *arme[9], BITMAP *lieux[9], int n, int J, int nbJ, std::vector<Perso*> tab,BITMAP *valide);
    int hypothese(BITMAP *page,BITMAP *fond, BITMAP *perso[6], BITMAP *arme[9], BITMAP *lieux[9], int nbJ,std::vector<Perso*> tab,BITMAP *victoire,BITMAP *valide);
};


class BlocNote
{
protected :
    int m_perso[6];
    int m_lieu[9];
    int m_arme[9];

public :

    BlocNote();
    ~BlocNote();

    int getBN_perso(int num)const;
    int getBN_lieu(int num)const;
    int getBN_arme(int num)const;
    void setBN_perso(int num, int perso);
    void setBN_lieu(int num, int lieu);
    void setBN_arme(int num, int arme);
    void affichage(BITMAP *page, BITMAP *fond, BITMAP *croix, BITMAP *blocnote2,std::vector<Perso*> tab,int j,BITMAP *perso[6], BITMAP *arme[9], BITMAP *lieux[9],BITMAP *valide);
    void affPartie(BITMAP *croix1, BITMAP *page);
};

class Partie
{
protected :
    int m_sauvegarde;

public :

    Partie();
    ~Partie();


    int get_sauvegarde()const;
    void set_sauvegarde(std::string sauvegarde);

    void Sauvegarde(int nbJ, std::vector<Perso*> tab);
    void TourJoueur(int nbJ, std::vector<Perso*> tab, BITMAP *page, BITMAP *fond, BITMAP *defaite,BITMAP *parametre,BITMAP *menu, BITMAP *blocknote2,BITMAP *croix,BITMAP *croix1,BITMAP *plateau,BITMAP *blocnote,BITMAP *logo[6],BITMAP *de[6],BITMAP *perso[6],BITMAP *arme[9],BITMAP *lieux[9],BITMAP *victoire,BITMAP *valide,BITMAP *aide);
};

class Menu
{
protected :
    int m_menu;


public :

    Menu();
    ~Menu();

    void NouvellePartie(BITMAP *page, BITMAP *fond, BITMAP *defaite,BITMAP *parametre,BITMAP *menu, BITMAP *blocknote2,BITMAP *croix,BITMAP *croix1,BITMAP *plateau,BITMAP *blocnote,BITMAP *de[6],BITMAP *perso[6],BITMAP *arme[9],BITMAP *lieux[9],BITMAP *logo[6],BITMAP *victoire,BITMAP *valide,BITMAP *aide);
    void Parametre(BITMAP *page,BITMAP *fond,BITMAP *menu,BITMAP *aide);
    void Intro(BITMAP *intro, BITMAP *page);
    void Aide(BITMAP *page,BITMAP *fond,BITMAP *aide);
    void ReprendreLaPartie();
    void Sauvegarder();
    void Regles(BITMAP *page,BITMAP *fond);
};



int Nombre_de_joueur(BITMAP *page, BITMAP *fond);
std::vector<Perso*> CreationPersonnage(int nbJ, BITMAP *page, BITMAP *fond);


#endif // HEADER_H_INCLUDED

