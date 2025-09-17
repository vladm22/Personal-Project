#include "header.h"
#include <vector>

Perso::Perso()
{

}
Perso::Perso(int posx,int posy, int logo,int main[11], std::string nom,std::string motdepasse, int NbParties)
{
    m_posx=posx;
    m_posy=posy;
    m_logo=logo;
    m_main[10]=main[10];
    m_main[9]=main[9];
    m_main[8]=main[8];
    m_main[7]=main[7];
    m_main[6]=main[6];
    m_main[5]=main[5];
    m_main[4]=main[4];
    m_main[3]=main[3];
    m_main[2]=main[2];
    m_main[1]=main[1];
    m_main[0]=main[0];
    m_nom=nom;
    m_motdepasse=motdepasse;
    m_NbParties=NbParties;
    m_hypothese=0;
}
Perso::~Perso()
{

}
int Perso::getposX()const
{
    return m_posx;
}
int Perso::getposY()const
{
    return m_posy;
}
int Perso::getLogo()const
{
    return m_logo;
}
int Perso::getNbParties()const
{
    return m_NbParties;
}
std::string Perso::getNom()const
{
    return m_nom;
}
std::string Perso::getMotDePasse()const
{
    return m_motdepasse;
}
int Perso::getMain(int i)const
{
    return m_main[i];
}
void Perso::setposX(int posx)
{
    m_posx=posx;
}
void Perso::setposY(int posy)
{
    m_posy=posy;
}
void Perso::setLogot (int logo)
{
    m_logo=logo;
}
void Perso::setMain(int main, int emplacement)
{
    m_main[emplacement]=main;
}
void Perso::setNom(std::string nom)
{
    m_nom=nom;
}
void Perso::setMotDePasse(std::string motdepasse)
{
    m_motdepasse=motdepasse;
}
void Perso::setNbParties(int NbParties)
{
    m_NbParties=NbParties;
}
void Perso::afficher()
{
    std::cout<<"Nom : "<<m_nom<<std::endl;
    for(int i=0;i<8;i++)
    {
       std::cout<<m_main[i]<<std::endl;
    }
}

int Perso::getHypothese()const
{
    return m_hypothese;
}
void Perso::setHypothse(int hypothese)
{
    m_hypothese=hypothese;
}


void Perso::afficher_main(BITMAP *page, BITMAP *perso[6], BITMAP *arme[9], BITMAP *lieux[9])
{
    int X=25;
    int Y=580;

    for(int j=0; j<11; j++)
    {
        X=X+75;

        if(m_main[j]==1)
        {
            blit(lieux[0],page,0,0,X,Y, lieux[0]->w, lieux[0]->h);
        }
        if(m_main[j]==2)
        {
            blit(lieux[1],page,0,0,X,Y, lieux[1]->w, lieux[1]->h);
        }
        if(m_main[j]==3)
        {
            blit(lieux[2],page,0,0,X,Y, lieux[2]->w, lieux[2]->h);
        }
        if(m_main[j]==4)
        {
            blit(lieux[3],page,0,0,X,Y, lieux[3]->w, lieux[3]->h);
        }
        if(m_main[j]==5)
        {
            blit(lieux[4],page,0,0,X,Y, lieux[4]->w, lieux[4]->h);
        }
        if(m_main[j]==6)
        {
            blit(lieux[5],page,0,0,X,Y, lieux[5]->w, lieux[5]->h);
        }
        if(m_main[j]==7)
        {
            blit(lieux[6],page,0,0,X,Y, lieux[6]->w, lieux[6]->h);
        }
        if(m_main[j]==8)
        {
            blit(lieux[7],page,0,0,X,Y, lieux[7]->w, lieux[7]->h);
        }
        if(m_main[j]==9)
        {
            blit(lieux[8],page,0,0,X,Y, lieux[8]->w, lieux[8]->h);
        }
        if(m_main[j]==10)
        {
            blit(arme[0],page,0,0,X,Y, arme[0]->w, arme[0]->h);
        }
        if(m_main[j]==11)
        {
            blit(arme[1],page,0,0,X,Y, arme[1]->w, arme[1]->h);
        }
        if(m_main[j]==12)
        {
            blit(arme[2],page,0,0,X,Y, arme[2]->w, arme[2]->h);
        }
        if(m_main[j]==13)
        {
            blit(arme[3],page,0,0,X,Y, arme[3]->w, arme[3]->h);
        }
        if(m_main[j]==14)
        {
            blit(arme[4],page,0,0,X,Y, arme[4]->w, arme[4]->h);
        }
        if(m_main[j]==15)
        {
            blit(arme[5],page,0,0,X,Y, arme[5]->w, arme[5]->h);
        }
        if(m_main[j]==16)
        {
            blit(arme[6],page,0,0,X,Y, arme[6]->w, arme[6]->h);
        }
        if(m_main[j]==17)
        {
            blit(arme[7],page,0,0,X,Y, arme[7]->w, arme[7]->h);
        }
        if(m_main[j]==18)
        {
            blit(arme[8],page,0,0,X,Y, arme[8]->w, arme[8]->h);
        }
        if(m_main[j]==19)
        {
            blit(perso[0],page,0,0,X,Y, perso[0]->w, perso[0]->h);
        }
        if(m_main[j]==20)
        {
            blit(perso[1],page,0,0,X,Y, perso[1]->w, perso[1]->h);
        }
        if(m_main[j]==21)
        {
            blit(perso[2],page,0,0,X,Y, perso[2]->w, perso[2]->h);
        }
        if(m_main[j]==22)
        {
            blit(perso[3],page,0,0,X,Y, perso[3]->w, perso[3]->h);
        }
        if(m_main[j]==23)
        {
            blit(perso[4],page,0,0,X,Y, perso[4]->w, perso[4]->h);
        }
        if(m_main[j]==24)
        {
            blit(perso[5],page,0,0,X,Y, perso[5]->w, perso[5]->h);
        }
    }

    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

}

int Perso:: Nombre_de_joueur(BITMAP *page,BITMAP *fond)
{
    int nbJ;
    // Nombre de perso
    BITMAP *choix;

    int fin=0;

    //page=create_bitmap(SCREEN_W,SCREEN_H);
    choix=load_bitmap("choix.bmp",NULL);

    if (!choix)
    {
        allegro_message("pas pu trouver/charger menu.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    mouse_b=0;

    while (!fin)
    {
        clear_bitmap(page);
        blit(fond,page,0,0, (SCREEN_W-fond->w)/2, (SCREEN_H-fond->h)/2, fond->w, fond->h);
        masked_blit(choix,page,0,0, (SCREEN_W-choix->w)/2, (SCREEN_H-choix->h)/2, choix->w, choix->h);
        show_mouse(page);

        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=301&& mouse_x<=755 && mouse_y<=331)
        {
            nbJ=2;
            fin=1;
        }
        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=350&& mouse_x<=755 && mouse_y<=380)
        {
            nbJ=3;
            fin=1;
        }
        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=398&& mouse_x<=755 && mouse_y<=428)
        {
            nbJ=4;
            fin=1;
        }
        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=446&& mouse_x<=755 && mouse_y<=476)
        {
            nbJ=5;
            fin=1;
        }
        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=497&& mouse_x<=755 && mouse_y<=527)
        {
            nbJ=6;
            fin=1;
        }

        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }

    destroy_bitmap(choix);

    return nbJ;
}
