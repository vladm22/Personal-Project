#include <allegro.h>
#include <stack>
#include <time.h>
#include <iostream>
#include "header.h"
#include "classes.cpp"
#include "sous-prg.cpp"
#include "menu.cpp"
#include "perso.cpp"
#include "cartes.cpp"
#include "chambre.cpp"
#include "blocNote.cpp"
#include <vector>

int main()
{
    // Déclaration du pointeur sur BITMAP devant recevoir l'image
    BITMAP *accueil;
    BITMAP *page;

    int fin=0;

    // Il y aura un peu de hasard...
    srand(time(NULL));

    // Lancer allegro et le mode graphique
    allegro_init();
    install_keyboard();
    install_mouse();
    show_mouse(screen);

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1200,650,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // Chargement de l'image (l'allocation a lieu en même temps)
    accueil=load_bitmap("accueil.bmp",NULL);

    page=create_bitmap(SCREEN_W,SCREEN_H);

    // Vérification que l'image est bien chargée (dans le cas contraire image vaut NULL)
    // TOUJOURS LE FAIRE CAR ON N'EST JAMAIS CERTAIN DE BIEN TROUVER L'IMAGE
    if (!accueil)
    {
        allegro_message("pas pu trouver/charger mon_image.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // Affichage de l'image sur l'écran au milieu
    blit(accueil,page,0,0, (SCREEN_W-accueil->w)/2, (SCREEN_H-accueil->h)/2, accueil->w, accueil->h);

    // Boucle interactive
    while (!fin)
    {
        clear_bitmap(page);

        // Affichage de l'image sur l'écran au milieu
        blit(accueil,page,0,0, (SCREEN_W-accueil->w)/2, (SCREEN_H-accueil->h)/2, accueil->w, accueil->h);

        // afficher coordonnées de la souris (%4d = format numérique largeur fixe sur 4 caractères)
        textprintf_ex(page,font,60,10,makecol(0,255,0),makecol(0,0,0),"%4d %4d",mouse_x,mouse_y);


        // prise en compte effective de la zone cliquable MENU :
        if (mouse_b&1)
        {
            menu(page);
        }

        show_mouse(page);

        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        //sortie de la boucle si on appui sur echape
        if (key[KEY_ESC])
        {
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    destroy_bitmap(accueil);
    destroy_bitmap(page);

    return 0;
}
END_OF_MAIN();
