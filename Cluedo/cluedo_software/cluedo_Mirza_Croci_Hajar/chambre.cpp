#include "header.h"
#include <vector>


Chambre ::Chambre(int passage_x,int passage_y)
{
    m_passage_x=passage_x;
    m_passage_y=passage_y;
}
Chambre ::~Chambre()
{

}

void Chambre ::affichage (BITMAP *page,BITMAP *fond, BITMAP *perso[6], BITMAP *arme[9], BITMAP *lieux[9], int n, int J, int nbJ, std::vector<Perso*> tab,BITMAP *valide)
{
    // Déclaration du pointeur sur BITMAP devant recevoir l'image
    BITMAP *action[6];

    int joueur=J+1;

    int reponse=0;

    int fin=0;
    int choix1=0;
    int choix2=0;
    int choix3=0;

    int valid=0;

    int lieu=36;
    int arm=36;
    int pers=36;
    int armes=0;
    int personnages=0;
    int chambre=n+1;

    // Chargement de l'image (l'allocation a lieu en même temps)

    action[0]=load_bitmap("action1.bmp",NULL);
    action[1]=load_bitmap("action2.bmp",NULL);
    action[2]=load_bitmap("action3.bmp",NULL);
    action[3]=load_bitmap("action4.bmp",NULL);
    action[4]=load_bitmap("action5.bmp",NULL);
    action[5]=load_bitmap("action6.bmp",NULL);

    // Vérification que l'image est bien chargée (dans le cas contraire image vaut NULL)
    // TOUJOURS LE FAIRE CAR ON N'EST JAMAIS CERTAIN DE BIEN TROUVER L'IMAGE
    if (!action[0] || !action[1] || !action[2] || !action[3]|| !action[4] || !action[5])
    {
        allegro_message("pas pu trouver/charger mon_image1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


    // Boucle interactive
    while (!fin)
    {
        clear_bitmap(page);

        blit(fond,page,0,0, (SCREEN_W-fond->w)/2, (SCREEN_H-fond->h)/2, fond->w, fond->h);


        if(joueur>=nbJ)
        {
            joueur=0;
            valid=0;
        }
        if(joueur==J)
        {
            // message : pas de carte retour au plateau
            rest(2000);
            fin=1;
        }

        if(choix1==0)
        {
            masked_blit(action[0],page,0,0, (SCREEN_W-action[0]->w)/2, (SCREEN_H-action[0]->h)/2, action[0]->w, action[0]->h);

            blit(perso[0],page,0,0,300,150, perso[0]->w, perso[0]->h);
            blit(perso[1],page,0,0,400,150, perso[1]->w, perso[1]->h);
            blit(perso[2],page,0,0,500,150, perso[2]->w, perso[2]->h);
            blit(perso[3],page,0,0,600,150, perso[3]->w, perso[3]->h);
            blit(perso[4],page,0,0,700,150, perso[4]->w, perso[4]->h);
            blit(perso[5],page,0,0,800,150, perso[5]->w, perso[5]->h);

            int X=125;
            int Y=400;

            for(int j=0; j<11; j++)
            {
                X=X+75;

                if(tab[J]->getMain(j)==1)
                {
                    blit(lieux[0],page,0,0,X,Y, lieux[0]->w, lieux[0]->h);
                }
                if(tab[J]->getMain(j)==2)
                {
                    blit(lieux[1],page,0,0,X,Y, lieux[1]->w, lieux[1]->h);
                }
                if(tab[J]->getMain(j)==3)
                {
                    blit(lieux[2],page,0,0,X,Y, lieux[2]->w, lieux[2]->h);
                }
                if(tab[J]->getMain(j)==4)
                {
                    blit(lieux[3],page,0,0,X,Y, lieux[3]->w, lieux[3]->h);
                }
                if(tab[J]->getMain(j)==5)
                {
                    blit(lieux[4],page,0,0,X,Y, lieux[4]->w, lieux[4]->h);
                }
                if(tab[J]->getMain(j)==6)
                {
                    blit(lieux[5],page,0,0,X,Y, lieux[5]->w, lieux[5]->h);
                }
                if(tab[J]->getMain(j)==7)
                {
                    blit(lieux[6],page,0,0,X,Y, lieux[6]->w, lieux[6]->h);
                }
                if(tab[J]->getMain(j)==8)
                {
                    blit(lieux[7],page,0,0,X,Y, lieux[7]->w, lieux[7]->h);
                }
                if(tab[J]->getMain(j)==9)
                {
                    blit(lieux[8],page,0,0,X,Y, lieux[8]->w, lieux[8]->h);
                }
                if(tab[J]->getMain(j)==10)
                {
                    blit(arme[0],page,0,0,X,Y, arme[0]->w, arme[0]->h);
                }
                if(tab[J]->getMain(j)==11)
                {
                    blit(arme[1],page,0,0,X,Y, arme[1]->w, arme[1]->h);
                }
                if(tab[J]->getMain(j)==12)
                {
                    blit(arme[2],page,0,0,X,Y, arme[2]->w, arme[2]->h);
                }
                if(tab[J]->getMain(j)==13)
                {
                    blit(arme[3],page,0,0,X,Y, arme[3]->w, arme[3]->h);
                }
                if(tab[J]->getMain(j)==14)
                {
                    blit(arme[4],page,0,0,X,Y, arme[4]->w, arme[4]->h);
                }
                if(tab[J]->getMain(j)==15)
                {
                    blit(arme[5],page,0,0,X,Y, arme[5]->w, arme[5]->h);
                }
                if(tab[J]->getMain(j)==16)
                {
                    blit(arme[6],page,0,0,X,Y, arme[6]->w, arme[6]->h);
                }
                if(tab[J]->getMain(j)==17)
                {
                    blit(arme[7],page,0,0,X,Y, arme[7]->w, arme[7]->h);
                }
                if(tab[J]->getMain(j)==18)
                {
                    blit(arme[8],page,0,0,X,Y, arme[8]->w, arme[8]->h);
                }
                if(tab[J]->getMain(j)==19)
                {
                    blit(perso[0],page,0,0,X,Y, perso[0]->w, perso[0]->h);
                }
                if(tab[J]->getMain(j)==20)
                {
                    blit(perso[1],page,0,0,X,Y, perso[1]->w, perso[1]->h);
                }
                if(tab[J]->getMain(j)==21)
                {
                    blit(perso[2],page,0,0,X,Y, perso[2]->w, perso[2]->h);
                }
                if(tab[J]->getMain(j)==22)
                {
                    blit(perso[3],page,0,0,X,Y, perso[3]->w, perso[3]->h);
                }
                if(tab[J]->getMain(j)==23)
                {
                    blit(perso[4],page,0,0,X,Y, perso[4]->w, perso[4]->h);
                }
                if(tab[J]->getMain(j)==24)
                {
                    blit(perso[5],page,0,0,X,Y, perso[5]->w, perso[5]->h);
                }
            }

            if ( mouse_b&1 && mouse_x>=300 && mouse_y>=150&& mouse_x<=360 && mouse_y<=230)
            {
                personnages=19;
                choix1=1;
            }
            if ( mouse_b&1 && mouse_x>=400 && mouse_y>=150&& mouse_x<=460 && mouse_y<=230)
            {
                personnages=20;
                choix1=1;
            }
            if ( mouse_b&1 && mouse_x>=500 && mouse_y>=150&& mouse_x<=560 && mouse_y<=230)
            {
                personnages=21;
                choix1=1;
            }
            if ( mouse_b&1 && mouse_x>=600 && mouse_y>=150&& mouse_x<=660 && mouse_y<=230)
            {
                personnages=22;
                choix1=1;
            }
            if ( mouse_b&1 && mouse_x>=700 && mouse_y>=150&& mouse_x<=760 && mouse_y<=230)
            {
                personnages=23;
                choix1=1;
            }
            if ( mouse_b&1 && mouse_x>=800 && mouse_y>=150&& mouse_x<=860 && mouse_y<=230)
            {
                personnages=24;
                choix1=1;
            }

            mouse_b=0;
        }


        if(choix1==1 && choix2==0)
        {
            masked_blit(action[1],page,0,0, (SCREEN_W-action[1]->w)/2, (SCREEN_H-action[1]->h)/2, action[1]->w, action[1]->h);

            blit(arme[0],page,0,0,400,150, arme[0]->w, arme[0]->h);
            blit(arme[1],page,0,0,500,150, arme[1]->w, arme[1]->h);
            blit(arme[2],page,0,0,600,150, arme[2]->w, arme[2]->h);
            blit(arme[3],page,0,0,700,150, arme[3]->w, arme[3]->h);
            blit(arme[4],page,0,0,350,245, arme[4]->w, arme[4]->h);
            blit(arme[5],page,0,0,450,245, arme[5]->w, arme[5]->h);
            blit(arme[6],page,0,0,550,245, arme[6]->w, arme[6]->h);
            blit(arme[7],page,0,0,650,245, arme[7]->w, arme[7]->h);
            blit(arme[8],page,0,0,750,245, arme[8]->w, arme[8]->h);

            int X=125;
            int Y=400;

            for(int j=0; j<11; j++)
            {
                X=X+75;

                if(tab[J]->getMain(j)==1)
                {
                    blit(lieux[0],page,0,0,X,Y, lieux[0]->w, lieux[0]->h);
                }
                if(tab[J]->getMain(j)==2)
                {
                    blit(lieux[1],page,0,0,X,Y, lieux[1]->w, lieux[1]->h);
                }
                if(tab[J]->getMain(j)==3)
                {
                    blit(lieux[2],page,0,0,X,Y, lieux[2]->w, lieux[2]->h);
                }
                if(tab[J]->getMain(j)==4)
                {
                    blit(lieux[3],page,0,0,X,Y, lieux[3]->w, lieux[3]->h);
                }
                if(tab[J]->getMain(j)==5)
                {
                    blit(lieux[4],page,0,0,X,Y, lieux[4]->w, lieux[4]->h);
                }
                if(tab[J]->getMain(j)==6)
                {
                    blit(lieux[5],page,0,0,X,Y, lieux[5]->w, lieux[5]->h);
                }
                if(tab[J]->getMain(j)==7)
                {
                    blit(lieux[6],page,0,0,X,Y, lieux[6]->w, lieux[6]->h);
                }
                if(tab[J]->getMain(j)==8)
                {
                    blit(lieux[7],page,0,0,X,Y, lieux[7]->w, lieux[7]->h);
                }
                if(tab[J]->getMain(j)==9)
                {
                    blit(lieux[8],page,0,0,X,Y, lieux[8]->w, lieux[8]->h);
                }
                if(tab[J]->getMain(j)==10)
                {
                    blit(arme[0],page,0,0,X,Y, arme[0]->w, arme[0]->h);
                }
                if(tab[J]->getMain(j)==11)
                {
                    blit(arme[1],page,0,0,X,Y, arme[1]->w, arme[1]->h);
                }
                if(tab[J]->getMain(j)==12)
                {
                    blit(arme[2],page,0,0,X,Y, arme[2]->w, arme[2]->h);
                }
                if(tab[J]->getMain(j)==13)
                {
                    blit(arme[3],page,0,0,X,Y, arme[3]->w, arme[3]->h);
                }
                if(tab[J]->getMain(j)==14)
                {
                    blit(arme[4],page,0,0,X,Y, arme[4]->w, arme[4]->h);
                }
                if(tab[J]->getMain(j)==15)
                {
                    blit(arme[5],page,0,0,X,Y, arme[5]->w, arme[5]->h);
                }
                if(tab[J]->getMain(j)==16)
                {
                    blit(arme[6],page,0,0,X,Y, arme[6]->w, arme[6]->h);
                }
                if(tab[J]->getMain(j)==17)
                {
                    blit(arme[7],page,0,0,X,Y, arme[7]->w, arme[7]->h);
                }
                if(tab[J]->getMain(j)==18)
                {
                    blit(arme[8],page,0,0,X,Y, arme[8]->w, arme[8]->h);
                }
                if(tab[J]->getMain(j)==19)
                {
                    blit(perso[0],page,0,0,X,Y, perso[0]->w, perso[0]->h);
                }
                if(tab[J]->getMain(j)==20)
                {
                    blit(perso[1],page,0,0,X,Y, perso[1]->w, perso[1]->h);
                }
                if(tab[J]->getMain(j)==21)
                {
                    blit(perso[2],page,0,0,X,Y, perso[2]->w, perso[2]->h);
                }
                if(tab[J]->getMain(j)==22)
                {
                    blit(perso[3],page,0,0,X,Y, perso[3]->w, perso[3]->h);
                }
                if(tab[J]->getMain(j)==23)
                {
                    blit(perso[4],page,0,0,X,Y, perso[4]->w, perso[4]->h);
                }
                if(tab[J]->getMain(j)==24)
                {
                    blit(perso[5],page,0,0,X,Y, perso[5]->w, perso[5]->h);
                }
            }

            if ( mouse_b&1 && mouse_x>=400 && mouse_y>=150&& mouse_x<=460 && mouse_y<=230)
            {
                armes=10;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=500 && mouse_y>=150&& mouse_x<=560 && mouse_y<=230)
            {
                armes=11;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=600 && mouse_y>=150&& mouse_x<=660 && mouse_y<=230)
            {
                armes=12;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=700 && mouse_y>=150&& mouse_x<=760 && mouse_y<=230)
            {
                armes=13;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=350 && mouse_y>=245&& mouse_x<=410 && mouse_y<=325)
            {
                armes=14;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=450 && mouse_y>=245&& mouse_x<=510 && mouse_y<=325)
            {
                armes=15;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=550 && mouse_y>=245&& mouse_x<=610 && mouse_y<=325)
            {
                armes=16;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=650 && mouse_y>=245&& mouse_x<=710 && mouse_y<=325)
            {
                armes=17;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=750 && mouse_y>=245&& mouse_x<=810 && mouse_y<=325)
            {
                armes=18;
                choix2=1;
            }

        }

        if(choix1==1 && choix2==1 && choix3==0)
        {
             masked_blit(action[2],page,0,0, (SCREEN_W-action[2]->w)/2, (SCREEN_H-action[2]->h)/2, action[2]->w, action[2]->h);

             for(int i=19;i<25;i++)
             {
                    if(personnages==i)
                    {
                        blit(perso[i-19],page,0,0,800,200, perso[i-19]->w, perso[i-19]->h);
                    }
             }
             for(int j=10;j<19;j++)
             {
                    if(armes==j)
                    {
                        blit(arme[j-10],page,0,0,800,350, arme[j-10]->w, arme[j-10]->h);
                    }
             }

             blit(lieux[n],page,0,0,800,100, lieux[n]->w, lieux[n]->h);

             masked_blit(valide,page,0,0, 950, 50, valide->w, valide->h);

            if ( mouse_b&1 && mouse_x>=950 && mouse_y>=70&& mouse_x<=1150 && mouse_y<=270)
            {
                choix3=1;
            }
        }

        if(choix1==1 && choix2==1 && choix3==1 && valid==0)
        {
            valid=1;

            //on regarde dans la main du joueur suivant quelle cartes correspondent a lhyothese

            for(int j=0; j<11; j++)
            {

                if(tab[joueur]->getMain(j)==1)
                {
                    if(chambre==1)
                    {
                        lieu=0;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==2)
                {
                    if(chambre==2)
                    {
                        lieu=1;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==3)
                {
                    if(chambre==3)
                    {
                        lieu=2;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==4)
                {
                    if(chambre==4)
                    {
                        lieu=3;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==5)
                {
                    if(chambre==5)
                    {
                        lieu=4;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==6)
                {
                    if(chambre==6)
                    {
                        lieu=5;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==7)
                {
                    if(chambre==7)
                    {
                        lieu=6;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==8)
                {
                    if(chambre==8)
                    {
                        lieu=7;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==9)
                {
                    if(chambre==9)
                    {
                        lieu=8;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==10)
                {
                    if(armes==10)
                    {
                        arm=0;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==11)
                {
                    if(armes==11)
                    {
                        arm=1;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==12)
                {
                    if(armes==12)
                    {
                        arm=2;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==13)
                {
                    if(armes==13)
                    {
                        arm=3;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==14)
                {
                    if(armes==14)
                    {
                        arm=4;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==15)
                {
                    if(armes==15)
                    {
                        arm=5;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==16)
                {
                    if(armes==16)
                    {
                        arm=6;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==17)
                {
                    if(armes==17)
                    {
                        arm=7;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==18)
                {
                    if(armes==18)
                    {
                        arm=8;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==19)
                {
                    if(personnages==19)
                    {
                        pers=0;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==20)
                {
                    if(personnages==20)
                    {
                        pers=1;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==21)
                {
                    if(personnages==21)
                    {
                        pers=2;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==22)
                {
                    if(personnages==22)
                    {
                        pers=3;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==23)
                {
                    if(personnages==23)
                    {
                        pers=4;
                        valid=valid+1;
                    }
                }
                if(tab[joueur]->getMain(j)==24)
                {
                    if(personnages==24)
                    {
                        pers=5;
                        valid=valid+1;
                    }
                }
            }
        }

        if(choix1==1 && choix2==1 && choix3==1 && valid==1)
        {
            masked_blit(action[4],page,0,0, (SCREEN_W-action[4]->w)/2, (SCREEN_H-action[4]->h)/2, action[4]->w, action[4]->h);

            for(int i=19;i<25;i++)
             {
                    if(personnages==i)
                    {
                        blit(perso[i-19],page,0,0,500,200, perso[i-19]->w, perso[i-19]->h);
                    }
             }
             for(int j=10;j<19;j++)
             {
                    if(armes==j)
                    {
                        blit(arme[j-10],page,0,0,580,200, arme[j-10]->w, arme[j-10]->h);
                    }
             }

            blit(lieux[n],page,0,0,650,200, lieux[n]->w, lieux[n]->h);

            valid=0;

            joueur=joueur+1;

            // afficher un message pour le passage au joueur suivant
        }

        if(choix1==1 && choix2==1 && choix3==1 && (valid==2 || valid==3 || valid==4 ))
        {
            masked_blit(action[3],page,0,0, (SCREEN_W-action[3]->w)/2, (SCREEN_H-action[3]->h)/2, action[3]->w, action[3]->h);
            textprintf_ex(page,font,700,20,makecol(0,255,0),makecol(0,0,0)," Joueur %d choisissez une carte a montrer au joueur %d ",joueur+1,J+1);
            for(int i=19;i<25;i++)
             {
                    if(personnages==i)
                    {
                        blit(perso[i-19],page,0,0,500,200, perso[i-19]->w, perso[i-19]->h);
                    }
             }
             for(int j=10;j<19;j++)
             {
                    if(armes==j)
                    {
                        blit(arme[j-10],page,0,0,580,200, arme[j-10]->w, arme[j-10]->h);
                    }
             }

            blit(lieux[n],page,0,0,650,200, lieux[n]->w, lieux[n]->h);


            if(pers==36)
            {

            }
            else
            {
                blit(perso[pers],page,0,0,500,400, perso[pers]->w, perso[pers]->h);
            }
            if(arm==36)
            {

            }
            else
            {
                blit(arme[arm],page,0,0,575,400, arme[arm]->w, arme[arm]->h);
            }
            if(lieu==36)
            {

            }
            else
            {
                blit(lieux[lieu],page,0,0,665,400, lieux[lieu]->w, lieux[lieu]->h);
            }

            if ( mouse_b&1 && mouse_x>=500 && mouse_y>=400 && mouse_x<=560 && mouse_y<=500 && (pers<30))
            {
                // message : valider le fait denvoyer
                reponse=1;
            }
            if ( mouse_b&1 && mouse_x>=575 && mouse_y>=400 && mouse_x<=650 && mouse_y<=500 && (arm<30))
            {
                // message : valider le fait denvoyer
                reponse=2;
            }
            if ( mouse_b&1 && mouse_x>=665 && mouse_y>=400 && mouse_x<=750 && mouse_y<=500 && (lieu<30))
            {
                // message : valider le fait denvoyer
                reponse =3;
            }
        }

        if(reponse==1)
        {
            masked_blit(action[5],page,0,0, (SCREEN_W-action[5]->w)/2, (SCREEN_H-action[5]->h)/2, action[5]->w, action[5]->h);
            blit(perso[pers],page,0,0,500,400, perso[pers]->w, perso[pers]->h);

            masked_blit(valide,page,0,0, 950, 50, valide->w, valide->h);

            if ( mouse_b&1 && mouse_x>=950 && mouse_y>=70&& mouse_x<=1150 && mouse_y<=270)
            {
                fin=1;
            }
        }
        if(reponse==2)
        {
            masked_blit(action[5],page,0,0, (SCREEN_W-action[5]->w)/2, (SCREEN_H-action[5]->h)/2, action[5]->w, action[5]->h);
            blit(arme[arm],page,0,0,575,400, arme[arm]->w, arme[arm]->h);

            masked_blit(valide,page,0,0, 950, 50, valide->w, valide->h);

            if ( mouse_b&1 && mouse_x>=950 && mouse_y>=70&& mouse_x<=1150 && mouse_y<=270)
            {
                fin=1;
            }
        }
        if(reponse==3)
        {
            masked_blit(action[5],page,0,0, (SCREEN_W-action[5]->w)/2, (SCREEN_H-action[5]->h)/2, action[5]->w, action[5]->h);
            blit(lieux[lieu],page,0,0,665,400, lieux[lieu]->w, lieux[lieu]->h);

            masked_blit(valide,page,0,0, 950, 50, valide->w, valide->h);

            if ( mouse_b&1 && mouse_x>=950 && mouse_y>=70&& mouse_x<=1150 && mouse_y<=270)
            {
                fin=1;
            }
        }

        show_mouse(page);

        textprintf_ex(page,font,60,10,makecol(0,255,0),makecol(0,0,0),"%4d %4d",mouse_x,mouse_y);

        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }

    destroy_bitmap(action[0]);
    destroy_bitmap(action[1]);
    destroy_bitmap(action[2]);
    destroy_bitmap(action[3]);
    destroy_bitmap(action[4]);
}


int Chambre ::hypothese(BITMAP *page,BITMAP *fond, BITMAP *perso[6], BITMAP *arme[9], BITMAP *lieux[9], int nbJ, std::vector<Perso*> tab,BITMAP *victoire,BITMAP *valide)
{
    // Déclaration du pointeur sur BITMAP devant recevoir l'image
    BITMAP *action[5];

    int bonne_rep=0;

    int finPartie=0;

    int fin=0;
    int choix1=0;
    int choix2=0;
    int choix3=0;

    int valid=0;

    int lieu=0;
    int armes=0;
    int personnages=0;


    // Chargement de l'image (l'allocation a lieu en même temps)

    action[0]=load_bitmap("action1.bmp",NULL);
    action[1]=load_bitmap("action2.bmp",NULL);
    action[2]=load_bitmap("action7.bmp",NULL);
    action[3]=load_bitmap("action3.bmp",NULL);
    action[4]=load_bitmap("action8.bmp",NULL);

    // Vérification que l'image est bien chargée (dans le cas contraire image vaut NULL)
    // TOUJOURS LE FAIRE CAR ON N'EST JAMAIS CERTAIN DE BIEN TROUVER L'IMAGE
    if (!action[0] || !action[1] || !action[2] || !action[3] || !action[4])
    {
        allegro_message("pas pu trouver/charger mon_image1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


    // Boucle interactive
    while (!fin)
    {
        clear_bitmap(page);

        blit(fond,page,0,0, (SCREEN_W-fond->w)/2, (SCREEN_H-fond->h)/2, fond->w, fond->h);

        if(choix1==0)
        {
            masked_blit(action[0],page,0,0, (SCREEN_W-action[0]->w)/2, (SCREEN_H-action[0]->h)/2, action[0]->w, action[0]->h);

            blit(perso[0],page,0,0,300,200, perso[0]->w, perso[0]->h);
            blit(perso[1],page,0,0,400,200, perso[1]->w, perso[1]->h);
            blit(perso[2],page,0,0,500,200, perso[2]->w, perso[2]->h);
            blit(perso[3],page,0,0,600,200, perso[3]->w, perso[3]->h);
            blit(perso[4],page,0,0,700,200, perso[4]->w, perso[4]->h);
            blit(perso[5],page,0,0,800,200, perso[5]->w, perso[5]->h);

            if ( mouse_b&1 && mouse_x>=300 && mouse_y>=200&& mouse_x<=360 && mouse_y<=280)
            {
                personnages=19;
                choix1=1;
            }
            if ( mouse_b&1 && mouse_x>=400 && mouse_y>=200&& mouse_x<=460 && mouse_y<=280)
            {
                personnages=20;
                choix1=1;
            }
            if ( mouse_b&1 && mouse_x>=500 && mouse_y>=200&& mouse_x<=560 && mouse_y<=280)
            {
                personnages=21;
                choix1=1;
            }
            if ( mouse_b&1 && mouse_x>=600 && mouse_y>=200&& mouse_x<=660 && mouse_y<=280)
            {
                personnages=22;
                choix1=1;
            }
            if ( mouse_b&1 && mouse_x>=700 && mouse_y>=200&& mouse_x<=760 && mouse_y<=280)
            {
                personnages=23;
                choix1=1;
            }
            if ( mouse_b&1 && mouse_x>=800 && mouse_y>=200&& mouse_x<=860 && mouse_y<=280)
            {
                personnages=24;
                choix1=1;
            }

            mouse_b=0;
        }


        if(choix1==1 && choix2==0)
        {
            masked_blit(action[1],page,0,0, (SCREEN_W-action[1]->w)/2, (SCREEN_H-action[1]->h)/2, action[1]->w, action[1]->h);

            blit(arme[0],page,0,0,400,250, arme[0]->w, arme[0]->h);
            blit(arme[1],page,0,0,500,250, arme[1]->w, arme[1]->h);
            blit(arme[2],page,0,0,600,250, arme[2]->w, arme[2]->h);
            blit(arme[3],page,0,0,700,250, arme[3]->w, arme[3]->h);
            blit(arme[4],page,0,0,350,400, arme[4]->w, arme[4]->h);
            blit(arme[5],page,0,0,450,400, arme[5]->w, arme[5]->h);
            blit(arme[6],page,0,0,550,400, arme[6]->w, arme[6]->h);
            blit(arme[7],page,0,0,650,400, arme[7]->w, arme[7]->h);
            blit(arme[8],page,0,0,750,400, arme[8]->w, arme[8]->h);

            if ( mouse_b&1 && mouse_x>=400 && mouse_y>=250&& mouse_x<=480 && mouse_y<=330)
            {
                armes=10;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=500 && mouse_y>=250&& mouse_x<=580 && mouse_y<=330)
            {
                armes=11;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=600 && mouse_y>=250&& mouse_x<=680 && mouse_y<=330)
            {
                armes=12;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=700 && mouse_y>=250&& mouse_x<=780 && mouse_y<=330)
            {
                armes=13;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=350 && mouse_y>=400&& mouse_x<=420 && mouse_y<=480)
            {
                armes=14;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=450 && mouse_y>=400&& mouse_x<=520 && mouse_y<=480)
            {
                armes=15;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=550 && mouse_y>=400&& mouse_x<=620 && mouse_y<=480)
            {
                armes=16;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=650 && mouse_y>=400&& mouse_x<=720 && mouse_y<=480)
            {
                armes=17;
                choix2=1;
            }
            if ( mouse_b&1 && mouse_x>=750 && mouse_y>=400&& mouse_x<=820 && mouse_y<=480)
            {
                armes=18;
                choix2=1;
            }

            mouse_b=0;
        }

        if(choix1==1 && choix2==1 && choix3==0)
        {
            masked_blit(action[2],page,0,0, (SCREEN_W-action[2]->w)/2, (SCREEN_H-action[2]->h)/2, action[2]->w, action[2]->h);

            blit(lieux[0],page,0,0,400,250, lieux[0]->w, lieux[0]->h);
            blit(lieux[1],page,0,0,500,250, lieux[1]->w, lieux[1]->h);
            blit(lieux[2],page,0,0,600,250, lieux[2]->w, lieux[2]->h);
            blit(lieux[3],page,0,0,700,250, lieux[3]->w, lieux[3]->h);
            blit(lieux[4],page,0,0,350,400, lieux[4]->w, lieux[4]->h);
            blit(lieux[5],page,0,0,450,400, lieux[5]->w, lieux[5]->h);
            blit(lieux[6],page,0,0,550,400, lieux[6]->w, lieux[6]->h);
            blit(lieux[7],page,0,0,650,400, lieux[7]->w, lieux[7]->h);
            blit(lieux[8],page,0,0,750,400, lieux[8]->w, lieux[8]->h);

            if ( mouse_b&1 && mouse_x>=400 && mouse_y>=250&& mouse_x<=460 && mouse_y<=330)
            {
                lieu=1;
                choix3=1;
            }
            if ( mouse_b&1 && mouse_x>=500 && mouse_y>=250&& mouse_x<=560 && mouse_y<=330)
            {
                lieu=2;
                choix3=1;
            }
            if ( mouse_b&1 && mouse_x>=600 && mouse_y>=250&& mouse_x<=660 && mouse_y<=330)
            {
                lieu=3;
                choix3=1;
            }
            if ( mouse_b&1 && mouse_x>=700 && mouse_y>=250&& mouse_x<=760 && mouse_y<=330)
            {
                lieu=4;
                choix3=1;
            }
            if ( mouse_b&1 && mouse_x>=350 && mouse_y>=400&& mouse_x<=410 && mouse_y<=480)
            {
                lieu=5;
                choix3=1;
            }
            if ( mouse_b&1 && mouse_x>=450 && mouse_y>=400&& mouse_x<=510 && mouse_y<=480)
            {
                lieu=6;
                choix3=1;
            }
            if ( mouse_b&1 && mouse_x>=550 && mouse_y>=400&& mouse_x<=610 && mouse_y<=480)
            {
                lieu=7;
                choix3=1;
            }
            if ( mouse_b&1 && mouse_x>=650 && mouse_y>=400&& mouse_x<=710 && mouse_y<=480)
            {
                lieu=8;
                choix3=1;
            }
            if ( mouse_b&1 && mouse_x>=750 && mouse_y>=400&& mouse_x<=810 && mouse_y<=480)
            {
                lieu=9;
                choix3=1;
            }

            mouse_b=0;
        }

        if(choix1==1 && choix2==1 && choix3==1 && valid==0)
        {
             masked_blit(action[3],page,0,0, (SCREEN_W-action[3]->w)/2, (SCREEN_H-action[3]->h)/2, action[3]->w, action[3]->h);

             for(int i=19;i<25;i++)
             {
                    if(personnages==i)
                    {
                        blit(perso[i-19],page,0,0,800,200, perso[i-19]->w, perso[i-19]->h);
                    }
             }
             for(int j=10;j<19;j++)
             {
                    if(armes==j)
                    {
                        blit(arme[j-10],page,0,0,800,350, arme[j-10]->w, arme[j-10]->h);
                    }
             }
             for(int j=1;j<10;j++)
             {
                    if(lieu==j)
                    {
                        blit(lieux[j-1],page,0,0,800,100, lieux[j-1]->w, lieux[j-1]->h);
                    }
             }

             masked_blit(valide,page,0,0, 950, 50, valide->w, valide->h);

            if ( mouse_b&1 && mouse_x>=950 && mouse_y>=70&& mouse_x<=1150 && mouse_y<=270)
            {
                valid=1;
            }
        }

        if(choix1==1 && choix2==1 && choix3==1 && valid==1 && bonne_rep==0)
        {
            bonne_rep=2;

            for(int i=0;i<nbJ;i++)
            {
                for(int j=0;j<11;j++)
                {
                    if(personnages==tab[i]->getMain(j))
                    {
                        bonne_rep=1;
                    }
                    if(armes==tab[i]->getMain(j))
                    {
                        bonne_rep=1;
                    }
                    if(lieu==tab[i]->getMain(j))
                    {
                        bonne_rep=1;
                    }
                }
            }
            std::cout<<"bonne rep :"<<bonne_rep<<std::endl;

            if(bonne_rep==2)
            {
                int part=0;

                key[KEY_SPACE]=0;

                while (part==0)
                {
                    clear_bitmap(page);
                    blit(victoire,page,0,0, (SCREEN_W-victoire->w)/2, (SCREEN_H-victoire->h)/2, victoire->w, victoire->h);

                    for(int i=19;i<25;i++)
                     {
                            if(personnages==i)
                            {
                                blit(perso[i-19],page,0,0,500,500, perso[i-19]->w, perso[i-19]->h);
                            }
                     }
                     for(int j=10;j<19;j++)
                     {
                            if(armes==j)
                            {
                                blit(arme[j-10],page,0,0,600,500, arme[j-10]->w, arme[j-10]->h);
                            }
                     }
                     for(int j=1;j<10;j++)
                     {
                            if(lieu==j)
                            {
                                blit(lieux[j-1],page,0,0,700,500, lieux[j-1]->w, lieux[j-1]->h);
                            }
                     }

                     if(key[KEY_SPACE])
                    {
                        finPartie=1;
                        fin=1;
                        part=1;
                    }

                    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                }

            }

            if(bonne_rep==1)
            {
                //message de hypothese fausse
                masked_blit(action[4],page,0,0, (SCREEN_W-action[4]->w)/2, (SCREEN_H-action[4]->h)/2, action[4]->w, action[4]->h);
                fin=1;
            }
        }

        show_mouse(page);

        //textprintf_ex(page,font,60,10,makecol(0,255,0),makecol(0,0,0),"%4d %4d",mouse_x,mouse_y);

        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        if(bonne_rep==1)
        {
            rest(3000);
        }
    }

    destroy_bitmap(action[0]);
    destroy_bitmap(action[1]);
    destroy_bitmap(action[2]);
    destroy_bitmap(action[3]);
    destroy_bitmap(action[4]);

    return finPartie;
}
