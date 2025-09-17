#include "header.h"
#include <vector>

Menu::Menu()
{
    m_menu=0;
}
Menu::~Menu()
{

}

void menu(BITMAP *page)
{
    BITMAP *valide;
    BITMAP *intro;
    BITMAP *defaite;
    BITMAP *aide;
    BITMAP *menu;
    BITMAP *fond;
    BITMAP *blocknote2;
    BITMAP *croix;
    BITMAP *croix1;
    BITMAP *plateau;
    BITMAP *blocnote;
    BITMAP *parametre;
    BITMAP *de[6];
    BITMAP *logo[6];
    BITMAP *perso[6];
    BITMAP *arme[9];
    BITMAP *lieux[9];
    BITMAP *victoire;

    aide=load_bitmap("aide.bmp",NULL);
    parametre=load_bitmap("parametre.bmp",NULL);
    blocknote2=load_bitmap("blocnote2.bmp",NULL);
    croix1=load_bitmap("croixpp.bmp",NULL);
    croix=load_bitmap("croixp.bmp",NULL);
    victoire=load_bitmap("victoire.bmp",NULL);
    valide=load_bitmap("valide.bmp",NULL);
    intro=load_bitmap("intro.bmp",NULL);
    defaite=load_bitmap("defaite.bmp",NULL);

    perso[0]=load_bitmap("luffyp.bmp",NULL);
    perso[1]=load_bitmap("namip.bmp",NULL);
    perso[2]=load_bitmap("zorop.bmp",NULL);
    perso[3]=load_bitmap("sanjip.bmp",NULL);
    perso[4]=load_bitmap("usoppp.bmp",NULL);
    perso[5]=load_bitmap("robinp.bmp",NULL);


    arme[0]=load_bitmap("arme1p.bmp",NULL);
    arme[1]=load_bitmap("arme2p.bmp",NULL);
    arme[2]=load_bitmap("arme3p.bmp",NULL);
    arme[3]=load_bitmap("arme4p.bmp",NULL);
    arme[4]=load_bitmap("arme5p.bmp",NULL);
    arme[5]=load_bitmap("arme6p.bmp",NULL);
    arme[6]=load_bitmap("arme7p.bmp",NULL);
    arme[7]=load_bitmap("arme8p.bmp",NULL);
    arme[8]=load_bitmap("arme9p.bmp",NULL);

    lieux[0]=load_bitmap("armeriep.bmp",NULL);
    lieux[1]=load_bitmap("barp.bmp",NULL);
    lieux[2]=load_bitmap("biblothequep.bmp",NULL);
    lieux[3]=load_bitmap("bureaup.bmp",NULL);
    lieux[4]=load_bitmap("dortoir_fillep.bmp",NULL);
    lieux[5]=load_bitmap("dortoir_garconp.bmp",NULL);
    lieux[6]=load_bitmap("salle_de_bainp.bmp",NULL);
    lieux[7]=load_bitmap("salonp.bmp",NULL);
    lieux[8]=load_bitmap("usinep.bmp",NULL);

    de[0]=load_bitmap("de(1).bmp",NULL);
    de[1]=load_bitmap("de(2).bmp",NULL);
    de[2]=load_bitmap("de(3).bmp",NULL);
    de[3]=load_bitmap("de(4).bmp",NULL);
    de[4]=load_bitmap("de(5).bmp",NULL);
    de[5]=load_bitmap("de(6).bmp",NULL);

    //page2=create_bitmap(SCREEN_W,SCREEN_H);
    plateau=load_bitmap("plateau.bmp",NULL);
    blocnote=load_bitmap("blocnote.bmp",NULL);



    if ( !aide || !defaite || !intro || !victoire|| ! valide || !parametre || !blocknote2 || !croix1 || !croix || !plateau || !blocnote || !de[0] || !de[1] || !de[2] || !de[3] || !de[4] || !de[5] ||!arme[0] || !arme[1] || !arme[2] || !arme[3] || !arme[4] || !arme[5] || !arme[6] || !arme[7] || !arme[8] || !perso[0] || !perso[1] || !perso[2] || !perso[3] || !perso[4] || !perso[5]|| !lieux[0] || !lieux[1] || !lieux[2] || !lieux[3] || !lieux[4] || !lieux[5] || !lieux[6] || !lieux[7] || !lieux[8])
    {
        allegro_message("pas pu trouver/charger image23.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    int fin=0;

    Menu M;

    //page=create_bitmap(SCREEN_W,SCREEN_H);
    menu=load_bitmap("menu.bmp",NULL);
    fond=load_bitmap("fond.bmp",NULL);

    if (!menu || !fond)
    {
        allegro_message("pas pu trouver/charger menu.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


    while (!fin)
    {
        clear_bitmap(page);
        blit(fond,page,0,0, (SCREEN_W-fond->w)/2, (SCREEN_H-fond->h)/2, fond->w, fond->h);
        masked_blit(menu,page,0,0, (SCREEN_W-menu->w)/2, (SCREEN_H-menu->h)/2, menu->w, menu->h);
        show_mouse(page);

        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=255&& mouse_x<=755 && mouse_y<=285)
        {
            M.Intro(intro, page);
            M.NouvellePartie(page,fond,defaite,parametre, menu, blocknote2,croix,croix1,plateau,blocnote,de,perso,arme,lieux,logo,victoire, valide, aide);
        }
        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=301&& mouse_x<=755 && mouse_y<=331)
        {
            M.ReprendreLaPartie();
        }
        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=350&& mouse_x<=755 && mouse_y<=380)
        {
            M.Aide(page, fond, aide);
        }
        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=398&& mouse_x<=755 && mouse_y<=428)
        {
            M.Sauvegarder();
        }
        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=446&& mouse_x<=755 && mouse_y<=476)
        {
            M.Regles(page,fond);
        }
        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=497&& mouse_x<=755 && mouse_y<=527)
        {
            allegro_exit();
            exit(EXIT_FAILURE);
        }

        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }

    destroy_bitmap(victoire);
    destroy_bitmap(valide);
    destroy_bitmap(aide);
    destroy_bitmap(menu);
    destroy_bitmap(fond);
    destroy_bitmap(parametre);
    destroy_bitmap(blocknote2);
    destroy_bitmap(croix);
    destroy_bitmap(croix1);
    destroy_bitmap(plateau);
    destroy_bitmap(blocnote);
    destroy_bitmap(page);
    destroy_bitmap(de[0]);
    destroy_bitmap(de[1]);
    destroy_bitmap(de[2]);
    destroy_bitmap(de[3]);
    destroy_bitmap(de[4]);
    destroy_bitmap(de[5]);
    destroy_bitmap(perso[0]);
    destroy_bitmap(perso[1]);
    destroy_bitmap(perso[2]);
    destroy_bitmap(perso[3]);
    destroy_bitmap(perso[4]);
    destroy_bitmap(perso[5]);
    destroy_bitmap(arme[0]);
    destroy_bitmap(arme[1]);
    destroy_bitmap(arme[2]);
    destroy_bitmap(arme[3]);
    destroy_bitmap(arme[4]);
    destroy_bitmap(arme[5]);
    destroy_bitmap(arme[6]);
    destroy_bitmap(arme[7]);
    destroy_bitmap(arme[8]);
    destroy_bitmap(lieux[0]);
    destroy_bitmap(lieux[1]);
    destroy_bitmap(lieux[2]);
    destroy_bitmap(lieux[3]);
    destroy_bitmap(lieux[4]);
    destroy_bitmap(lieux[5]);
    destroy_bitmap(lieux[6]);
    destroy_bitmap(lieux[7]);
    destroy_bitmap(lieux[8]);
    destroy_bitmap(logo[0]);
    destroy_bitmap(logo[1]);
    destroy_bitmap(logo[2]);
    destroy_bitmap(logo[3]);
    destroy_bitmap(logo[4]);
    destroy_bitmap(logo[5]);

}

void Menu::Intro(BITMAP *intro, BITMAP *page)
{
    while (!key[KEY_SPACE])
    {
        clear_bitmap(page);
        blit(intro,page,0,0, (SCREEN_W-intro->w)/2, (SCREEN_H-intro->h)/2, intro->w, intro->h);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
}

void Menu::NouvellePartie(BITMAP *page, BITMAP *fond,BITMAP *defaite,BITMAP *parametre,BITMAP *menu, BITMAP *blocknote2,BITMAP *croix,BITMAP *croix1,BITMAP *plateau,BITMAP *blocnote,BITMAP *de[6],BITMAP *perso[6],BITMAP *arme[9],BITMAP *lieux[9],BITMAP *logo[6],BITMAP *victoire, BITMAP *valide,BITMAP *aide)
{
    int nbJ;

    Perso p;

    nbJ=p.Nombre_de_joueur(page, fond);

    std::vector<Perso*>tab(nbJ);

    tab=CreationPersonnage(nbJ, page, fond);

    for(int i=0;i<nbJ;i++)
    {
        if(tab[i]->getLogo()==1)
        {
            logo[i]=load_bitmap("pionLuffy.bmp",NULL);
        }
        if(tab[i]->getLogo()==2)
        {
            logo[i]=load_bitmap("pionNami.bmp",NULL);
        }
        if(tab[i]->getLogo()==3)
        {
            logo[i]=load_bitmap("pionZoro.bmp",NULL);
        }
        if(tab[i]->getLogo()==4)
        {
            logo[i]=load_bitmap("pionSanji.bmp",NULL);
        }
        if(tab[i]->getLogo()==5)
        {
            logo[i]=load_bitmap("pionRobin.bmp",NULL);
        }
        if(tab[i]->getLogo()==6)
        {
            logo[i]=load_bitmap("pionUsopp.bmp",NULL);
        }
        if (!logo[i])
            {
                allegro_message("pas pu trouver/charger image23.bmp");
                allegro_exit();
                exit(EXIT_FAILURE);
            }
    }

    std::cout<<"debut du tour"<<std::endl;

    Partie P;

    P.TourJoueur(nbJ, tab, page, fond,defaite,parametre, menu,blocknote2,croix,croix1,plateau,blocnote,logo,de,perso,arme,lieux,victoire, valide, aide);

    std::cout<<"*********fin*********"<<std::endl;

    P.Sauvegarde(nbJ,tab);
}

void Menu::ReprendreLaPartie()
{

}
void Menu::Aide(BITMAP *page,BITMAP *fond, BITMAP *aide)
{

    key[KEY_SPACE]=0;

    while (!key[KEY_SPACE])
    {
        clear_bitmap(page);
        blit(fond,page,0,0, (SCREEN_W-fond->w)/2, (SCREEN_H-fond->h)/2, fond->w, fond->h);
        masked_blit(aide,page,0,0, (SCREEN_W-aide->w)/2, (SCREEN_H-aide->h)/2, aide->w, aide->h);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
}

void Menu::Sauvegarder()
{

}
void Menu::Regles(BITMAP *page,BITMAP *fond)
{
    BITMAP *reglejeu;

    reglejeu=load_bitmap("regle2.bmp",NULL);

     if (!reglejeu)
    {
        allegro_message("pas pu trouver/charger menu.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    key[KEY_SPACE]=0;

    while (!key[KEY_SPACE])
    {
        clear_bitmap(page);
        blit(fond,page,0,0, (SCREEN_W-fond->w)/2, (SCREEN_H-fond->h)/2, fond->w, fond->h);
        masked_blit(reglejeu,page,0,0, (SCREEN_W-reglejeu->w)/2, (SCREEN_H-reglejeu->h)/2, reglejeu->w, reglejeu->h);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    destroy_bitmap(reglejeu);
}



void Menu::Parametre(BITMAP *page,BITMAP *fond,BITMAP *menu,BITMAP *aide)
{
    Menu H;

    int fin=0;

    while(fin==0)
    {
        clear_bitmap(page);
        blit(fond,page,0,0, (SCREEN_W-fond->w)/2, (SCREEN_H-fond->h)/2, fond->w, fond->h);
        masked_blit(menu,page,0,0, (SCREEN_W-menu->w)/2, (SCREEN_H-menu->h)/2, menu->w, menu->h);

        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=255&& mouse_x<=755 && mouse_y<=285)
        {
            fin=1;
        }
        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=301&& mouse_x<=755 && mouse_y<=331)
        {
            fin=1;
        }
        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=350&& mouse_x<=755 && mouse_y<=380)
        {
            H.Aide(page, fond, aide);
        }
        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=398&& mouse_x<=755 && mouse_y<=428)
        {
            H.Sauvegarder();
        }
        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=446&& mouse_x<=755 && mouse_y<=476)
        {
            H.Regles(page,fond);
        }
        if ( mouse_b&1 && mouse_x>=485 && mouse_y>=497&& mouse_x<=755 && mouse_y<=527)
        {
            allegro_exit();
            exit(EXIT_FAILURE);
        }

        show_mouse(page);

        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
}

