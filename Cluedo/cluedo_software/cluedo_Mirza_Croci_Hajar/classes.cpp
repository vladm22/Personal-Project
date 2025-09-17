#include "header.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>



Partie::Partie()
{
    m_sauvegarde=0;
}

Partie::~Partie()
{

}


int Partie::get_sauvegarde()const
{
    return m_sauvegarde;
}
void Partie::set_sauvegarde(std::string sauvegarde)
{

}

void Partie::TourJoueur(int nbJ, std::vector<Perso*> tab, BITMAP *page, BITMAP *fond,BITMAP *defaite,BITMAP *parametre,BITMAP *menu, BITMAP *blocknote2,BITMAP *croix,BITMAP *croix1,BITMAP *plateau,BITMAP *blocnote,BITMAP *logo[6],BITMAP *de[6],BITMAP *perso[6],BITMAP *arme[9],BITMAP *lieux[9],BITMAP *victoire,BITMAP *valide,BITMAP *aide)
{
    std::vector<BlocNote*> vec(nbJ);

    for(int i=0; i<nbJ; i++)
    {
        vec[i]=new BlocNote;
    }

    std::cout<<" initialsation tour"<<std::endl;

    int deplacement=0;
    int finPartie=0;
    int perdu[6]={0,0,0,0,0,0};
    int perd=0;
    int depSup=0;

    Chambre HG(100,100);
    Chambre HM(100,100);
    Chambre HD(100,100);
    Chambre DMH(100,100);
    Chambre DMB(100,100);
    Chambre DB(100,100);
    Chambre MB(100,100);
    Chambre GB(100,100);
    Chambre GM(100,100);
    Chambre Hy(100,100);

    while(finPartie==0)
    {

        for(int i=0;i<nbJ;i++)
        {

            int fin=0;
            int posx=0;
            int posy=0;

            deplacement=rand()%(6-1+1)+1;

            int deee=deplacement-1;

            //std::cout<<"tour du joueur num "<< i <<std::endl;
            //std::cout<<"de =  "<< deplacement <<std::endl;

            //std::cout<<"affichage du plateau"<<std::endl;

            while (!fin)
            {
                if(finPartie==1)
                {
                    fin=1;
                }

                if(tab[i]->getHypothese()==1)
                {
                    perdu[i]=1;
                    fin=1;
                }

                for(int j=0;j<nbJ;j++)
                {
                    if(perdu[j]==1)
                    {
                        perd=perd+1;
                    }
                }
                if(perd==nbJ)
                {
                    while (!key[KEY_SPACE])
                    {
                         blit(defaite,page,0,0, (SCREEN_W-defaite->w)/2, (SCREEN_H-defaite->h)/2, defaite->w, defaite->h);
                         blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                    }
                    finPartie=1;
                }
                else
                {
                    perd=0;
                }


                clear_bitmap(page);
                blit(fond,page,0,0, (SCREEN_W-fond->w)/2, (SCREEN_H-fond->h)/2, fond->w, fond->h);
                blit(plateau,page,0,0, (SCREEN_W-plateau->w)/2, (SCREEN_H-plateau->h)/2, plateau->w, plateau->h);//650 sur 494
                blit(blocnote,page,0,0,12,100, blocnote->w, blocnote->h);//250 sur 470
                blit(de[deee],page,0,0,1050,20, de[deee]->w, de[deee]->h);
                masked_blit(parametre,page,0,0,950,500, parametre->w, parametre->h);



               if ( mouse_b&1 && mouse_x>=950 && mouse_y>=500)
                {
                    Menu P;
                    P.Parametre(page,fond,menu,aide);
                }

                line(page,325,210,325,255,makecol(0,0,0));
                line(page,350,210,350,255,makecol(0,0,0));
                line(page,375,210,375,255,makecol(0,0,0));
                line(page,400,210,400,255,makecol(0,0,0));
                line(page,425,210,425,255,makecol(0,0,0));
                line(page,450,210,450,255,makecol(0,0,0));
                line(page,325,392,325,450,makecol(0,0,0));
                line(page,350,392,350,450,makecol(0,0,0));
                line(page,375,392,375,450,makecol(0,0,0));
                line(page,400,392,400,450,makecol(0,0,0));
                line(page,425,392,425,450,makecol(0,0,0));
                line(page,450,392,450,450,makecol(0,0,0));
                line(page,475,77,475,255,makecol(0,0,0));
                line(page,475,392,475,450,makecol(0,0,0));
                line(page,500,77,500,123,makecol(0,0,0));
                line(page,500,170,500,526,makecol(0,0,0));
                line(page,525,77,525,93,makecol(0,0,0));
                line(page,525,172,525,572,makecol(0,0,0));
                line(page,550,177,550,435,makecol(0,0,0));
                line(page,575,177,575,251,makecol(0,0,0));
                line(page,600,177,600,251,makecol(0,0,0));
                line(page,625,177,625,251,makecol(0,0,0));
                line(page,650,177,650,251,makecol(0,0,0));
                line(page,575,391,575,435,makecol(0,0,0));
                line(page,600,391,600,435,makecol(0,0,0));
                line(page,625,391,625,435,makecol(0,0,0));
                line(page,650,391,650,435,makecol(0,0,0));
                line(page,675,77,675,95,makecol(0,0,0));
                line(page,675,175,675,572,makecol(0,0,0));
                line(page,700,105,700,118,makecol(0,0,0));
                line(page,700,170,700,525,makecol(0,0,0));
                line(page,725,105,725,572,makecol(0,0,0));
                line(page,775,77,775,218,makecol(0,0,0));
                line(page,750,77,750,218,makecol(0,0,0));
                line(page,775,320,775,350,makecol(0,0,0));
                line(page,750,320,750,350,makecol(0,0,0));
                line(page,775,450,775,475,makecol(0,0,0));
                line(page,750,420,750,475,makecol(0,0,0));
                line(page,800,194,800,220,makecol(0,0,0));
                line(page,825,194,825,220,makecol(0,0,0));
                line(page,850,194,850,220,makecol(0,0,0));
                line(page,875,194,875,220,makecol(0,0,0));
                line(page,800,320,800,350,makecol(0,0,0));
                line(page,825,320,825,350,makecol(0,0,0));
                line(page,850,320,850,350,makecol(0,0,0));
                line(page,875,320,875,350,makecol(0,0,0));
                line(page,900,320,900,350,makecol(0,0,0));
                line(page,800,450,800,475,makecol(0,0,0));
                line(page,825,450,825,475,makecol(0,0,0));
                line(page,850,450,850,475,makecol(0,0,0));
                line(page,875,450,875,475,makecol(0,0,0));
                line(page,900,450,900,475,makecol(0,0,0));
                line(page,925,77,925,572,makecol(0,0,0));

                line(page,600,390,625,390,makecol(255,215,0));
                line(page,600,391,625,391,makecol(255,215,0));
                line(page,600,392,625,392,makecol(255,215,0));
                line(page,600,393,625,393,makecol(255,215,0));
                line(page,600,394,625,394,makecol(255,215,0));
                line(page,600,395,625,395,makecol(255,215,0));

                line(page,575,250,600,250,makecol(255,215,0));
                line(page,575,251,600,251,makecol(255,215,0));
                line(page,575,252,600,252,makecol(255,215,0));
                line(page,575,253,600,253,makecol(255,215,0));
                line(page,575,254,600,254,makecol(255,215,0));
                line(page,575,255,600,255,makecol(255,215,0));

                rectfill(page, 680, 251,696,266, makecol(85,215,221));
                rectfill(page, 505, 381,521,396, makecol(85,215,221));
                rectfill(page, 705, 431,721,446, makecol(255,0,0));
                rectfill(page, 530, 227,546,244, makecol(255,0,0));

                //std::cout<<"X : "<<tab[i]->getposX()<<"Y : "<<tab[i]->getposY()<<std::endl;

                vec[i]->affPartie(croix1, page);

                show_mouse(page);
                textprintf_ex(page,font,40,10,makecol(0,255,0),makecol(0,0,0),"Tour du Joueur %d: ", i+1);
                //std::cout<<"0"<<std::endl;

                for(int i=0;i<nbJ;i++)
                {
                     masked_blit(logo[i],page,0,0,tab[i]->getposX(),tab[i]->getposY(), logo[i]->w, logo[i]->h);
                }


                //std::cout<<"1"<<std::endl;

                if(tab[i]->getLogo()==1)//luffy
                {
                    blit(perso[0],page,0,0,90,20, perso[0]->w, perso[0]->h);
                }
                if(tab[i]->getLogo()==2)//nami
                {
                    blit(perso[1],page,0,0,90,20, perso[1]->w, perso[1]->h);
                }
                if(tab[i]->getLogo()==3)//zoro
                {
                    blit(perso[2],page,0,0,90,20, perso[2]->w, perso[2]->h);
                }
                if(tab[i]->getLogo()==4)//sanji
                {
                    blit(perso[3],page,0,0,90,20, perso[3]->w, perso[3]->h);
                }
                if(tab[i]->getLogo()==5)//robin
                {
                    blit(perso[5],page,0,0,90,20, perso[5]->w, perso[5]->h);
                }
                if(tab[i]->getLogo()==6)//usopp
                {
                    blit(perso[4],page,0,0,90,20, perso[4]->w, perso[4]->h);
                }


                tab[i]->afficher_main(page, perso, arme, lieux);


                //std::cout<<"2"<<std::endl;

                if(deplacement!=0)
                {
                    if(!(tab[i]->getposY()<395 && tab[i]->getposY()>225 && tab[i]->getposX()>525 && tab[i]->getposX()<650))
                    if(!(tab[i]->getposX()<450 && tab[i]->getposY()<220))
                    if(!(tab[i]->getposX()>770 && tab[i]->getposY()<200))
                    if(!(tab[i]->getposX()>720 && tab[i]->getposY()>470))
                    if(!(tab[i]->getposX()<475 && tab[i]->getposY()>425))
                    if(!(tab[i]->getposX()<700 && tab[i]->getposX()>500 && tab[i]->getposY()<170))
                    if(!(tab[i]->getposX()<675 && tab[i]->getposX()>520 && tab[i]->getposY()>420))
                    if(!(tab[i]->getposY()<390 && tab[i]->getposY()>240 && tab[i]->getposX()<500))
                    if(!(tab[i]->getposY()<325 && tab[i]->getposY()>215 && tab[i]->getposX()>725))
                    if(!(tab[i]->getposY()<450 && tab[i]->getposY()>340 && tab[i]->getposX()>745))
                    if((tab[i]->getposY()<570 && tab[i]->getposY()>80 && tab[i]->getposX()>275 && tab[i]->getposX()<925))
                    {
                        if ( key[KEY_LEFT])
                        {

                            posx=tab[i]->getposX()-25;
                            tab[i]->setposX(posx);

                            deplacement=deplacement-1;


                            // si on rentre dans une chambre pr la porte

                            if((tab[i]->getposY()<=510 && tab[i]->getposY()>=495 &&  tab[i]->getposX()<=470))
                            {
                                //chambre gauche bas

                                GB.affichage(page,fond, perso, arme, lieux, 4, i,nbJ, tab, valide);
                                tab[i]->setposX(tab[i]->getposX()+25);
                                deplacement = 0;
                            }


                            // blindage pour as etre dans la piece


                            if((tab[i]->getposY()<395 && tab[i]->getposY()>225 && tab[i]->getposX()>525 && tab[i]->getposX()<650))
                            {
                                posx=tab[i]->getposX()+25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()<450 && tab[i]->getposY()<220))
                            {
                                posx=tab[i]->getposX()+25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()>770 && tab[i]->getposY()<200))
                            {
                                posx=tab[i]->getposX()+25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()>720 && tab[i]->getposY()>470))
                            {
                                posx=tab[i]->getposX()+25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()<475 && tab[i]->getposY()>425))
                            {
                                posx=tab[i]->getposX()+25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()<700 && tab[i]->getposX()>500 && tab[i]->getposY()<170))
                            {
                                posx=tab[i]->getposX()+25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()<675 && tab[i]->getposX()>520 && tab[i]->getposY()>420))
                            {
                                posx=tab[i]->getposX()+25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposY()<390 && tab[i]->getposY()>240 && tab[i]->getposX()<500))
                            {
                                posx=tab[i]->getposX()+25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposY()<325 && tab[i]->getposY()>215 && tab[i]->getposX()>725))
                            {
                                posx=tab[i]->getposX()+25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposY()<450 && tab[i]->getposY()>340 && tab[i]->getposX()>745))
                            {
                                posx=tab[i]->getposX()+25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if(!(tab[i]->getposY()<570 && tab[i]->getposY()>80 && tab[i]->getposX()>275 && tab[i]->getposX()<925))
                            {
                                posx=tab[i]->getposX()+25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                        }
                        if ( key[KEY_RIGHT])
                        {
                            posx=tab[i]->getposX()+25;
                            tab[i]->setposX(posx);

                            deplacement=deplacement-1;


                            if((tab[i]->getposY()<=150 && tab[i]->getposY()>=140 && tab[i]->getposX()>=770 && tab[i]->getposX()<=780))
                            {
                                //chambre haut droite

                                HD.affichage(page,fond, perso, arme, lieux, 8, i,nbJ, tab, valide);
                                tab[i]->setposX(tab[i]->getposX()-25);
                                deplacement = 0;
                            }
                            if((tab[i]->getposY()<=275 && tab[i]->getposY()>=265 && tab[i]->getposX()>=720 && tab[i]->getposX()<=730))
                            {
                                //chambre droit milieu haut

                                DMH.affichage(page,fond, perso, arme, lieux, 3, i,nbJ, tab, valide);
                                tab[i]->setposX(tab[i]->getposX()-25);
                                deplacement = 0;
                            }
                            if((tab[i]->getposY()<=505 && tab[i]->getposY()>=495 && tab[i]->getposX()>=720 && tab[i]->getposX()<=730))
                            {
                                //chambre droit bas

                                DB.affichage(page,fond, perso, arme, lieux, 0, i,nbJ, tab, valide);
                                tab[i]->setposX(tab[i]->getposX()-25);
                                deplacement = 0;
                            }



                            if((tab[i]->getposY()<395 && tab[i]->getposY()>225 && tab[i]->getposX()>525 && tab[i]->getposX()<650))
                            {
                                posx=tab[i]->getposX()-25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()<450 && tab[i]->getposY()<220))
                            {
                                posx=tab[i]->getposX()-25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()>770 && tab[i]->getposY()<200))
                            {
                                posx=tab[i]->getposX()-25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()>720 && tab[i]->getposY()>470))
                            {
                                posx=tab[i]->getposX()-25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()<475 && tab[i]->getposY()>425))
                            {
                                posx=tab[i]->getposX()-25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()<700 && tab[i]->getposX()>500 && tab[i]->getposY()<170))
                            {
                                posx=tab[i]->getposX()-25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()<675 && tab[i]->getposX()>520 && tab[i]->getposY()>420))
                            {
                                posx=tab[i]->getposX()-25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposY()<390 && tab[i]->getposY()>240 && tab[i]->getposX()<500))
                            {
                                posx=tab[i]->getposX()-25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposY()<325 && tab[i]->getposY()>215 && tab[i]->getposX()>725))
                            {
                                posx=tab[i]->getposX()-25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposY()<450 && tab[i]->getposY()>340 && tab[i]->getposX()>745))
                            {
                                posx=tab[i]->getposX()-25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                            if(!(tab[i]->getposY()<570 && tab[i]->getposY()>80 && tab[i]->getposX()>275 && tab[i]->getposX()<925))
                            {
                                posx=tab[i]->getposX()-25;
                                tab[i]->setposX(posx);

                                deplacement=deplacement+1;
                            }
                        }


                        if ( key[KEY_UP])
                        {
                            posy=tab[i]->getposY()-25;
                            tab[i]->setposY(posy);

                            deplacement=deplacement-1;


                            if((tab[i]->getposY()>=190 && tab[i]->getposY()<=200 && tab[i]->getposX()>=395 && tab[i]->getposX()<=405))
                            {
                                //chambre haut gauche

                                HG.affichage(page,fond, perso, arme, lieux, 5, i,nbJ, tab, valide);
                                tab[i]->setposY(tab[i]->getposY()+25);
                                deplacement = 0;
                            }

                            if((tab[i]->getposY()>=100 && tab[i]->getposY()<=170 && tab[i]->getposX()>=545 && tab[i]->getposX()<=555))
                            {
                                //chambre milieu haut

                                HG.affichage(page,fond, perso, arme, lieux,6 , i,nbJ, tab, valide);
                                tab[i]->setposY(tab[i]->getposY()+25);
                                deplacement = 0;
                            }

                            if((tab[i]->getposY()<=430 && tab[i]->getposY()>=420 && tab[i]->getposX()>=870 && tab[i]->getposX()<=880))
                            {
                                //chambre droit milieu bas

                                DMB.affichage(page,fond, perso, arme, lieux, 1, i,nbJ, tab, valide);
                                tab[i]->setposX(tab[i]->getposX()+25);
                                deplacement = 0;
                            }
                            if((tab[i]->getposY()<=380 && tab[i]->getposY()>=370 && tab[i]->getposX()>=595 && tab[i]->getposX()<=605))
                            {
                                //chambre de lhypothese

                                finPartie=Hy.hypothese(page,fond, perso, arme, lieux,nbJ,tab,victoire, valide);
                                tab[i]->setposY(tab[i]->getposY()+25);
                                if(finPartie==1)
                                {
                                   tab[i]->setHypothse(2);
                                }
                                else
                                {
                                    tab[i]->setHypothse(1);

                                    tab[i]->setposY(300+i*5);
                                    tab[i]->setposX(580+i*5);
                                }

                                deplacement = 0;
                            }


                            if((tab[i]->getposY()<395 && tab[i]->getposY()>225 && tab[i]->getposX()>525 && tab[i]->getposX()<650))
                            {
                                posy=tab[i]->getposY()+25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()<450 && tab[i]->getposY()<220))
                            {
                                posy=tab[i]->getposY()+25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()>770 && tab[i]->getposY()<200))
                            {
                                posy=tab[i]->getposY()+25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()>720 && tab[i]->getposY()>470))
                            {
                                posy=tab[i]->getposY()+25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()<475 && tab[i]->getposY()>425))
                            {
                                posy=tab[i]->getposY()+25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()<700 && tab[i]->getposX()>500 && tab[i]->getposY()<170))
                            {
                                posy=tab[i]->getposY()+25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()<675 && tab[i]->getposX()>520 && tab[i]->getposY()>420))
                            {
                                posy=tab[i]->getposY()+25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposY()<390 && tab[i]->getposY()>240 && tab[i]->getposX()<500))
                            {
                                posy=tab[i]->getposY()+25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposY()<325 && tab[i]->getposY()>215 && tab[i]->getposX()>725))
                            {
                                posy=tab[i]->getposY()+25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposY()<450 && tab[i]->getposY()>340 && tab[i]->getposX()>745))
                            {
                                posy=tab[i]->getposY()+25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if(!(tab[i]->getposY()<570 && tab[i]->getposY()>80 && tab[i]->getposX()>275 && tab[i]->getposX()<925))
                            {
                                posy=tab[i]->getposY()+25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                        }

                        if ( key[KEY_DOWN])
                        {
                            posy=tab[i]->getposY()+25;
                            tab[i]->setposY(posy);

                            deplacement=deplacement-1;

                            if((tab[i]->getposY()<=250 && tab[i]->getposY()>=240 && tab[i]->getposX()>=420 && tab[i]->getposX()<=430))
                            {
                                //chambre gauche milieu

                                GM.affichage(page,fond, perso, arme, lieux, 2, i,nbJ, tab, valide);
                                tab[i]->setposY(tab[i]->getposY()-25);
                                deplacement = 0;
                            }

                            if((tab[i]->getposY()>=420 && tab[i]->getposY()<=430 && tab[i]->getposX()>=620 && tab[i]->getposX()<=630))
                            {
                                //chambre milieu bas

                                MB.affichage(page,fond, perso, arme, lieux , 7, i,nbJ, tab, valide);
                                tab[i]->setposY(tab[i]->getposY()-25);
                                deplacement = 0;
                            }

                            if((tab[i]->getposY()<=250 && tab[i]->getposY()>=240 && tab[i]->getposX()>=570 && tab[i]->getposX()<=580))
                            {
                                //chambre de lhypothese

                                finPartie=Hy.hypothese(page,fond, perso, arme, lieux,nbJ, tab,victoire, valide);
                                tab[i]->setposY(tab[i]->getposY()-25);
                                if(finPartie==1)
                                {
                                   tab[i]->setHypothse(2);
                                }
                                else
                                {
                                    tab[i]->setHypothse(1);

                                    tab[i]->setposY(300+i*5);
                                    tab[i]->setposX(580+i*5);
                                }

                                deplacement = 0;
                            }

                            if((tab[i]->getposY()<395 && tab[i]->getposY()>225 && tab[i]->getposX()>525 && tab[i]->getposX()<650))
                            {
                                posy=tab[i]->getposY()-25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()<450 && tab[i]->getposY()<220))
                            {
                                posy=tab[i]->getposY()-25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()>770 && tab[i]->getposY()<200))
                            {
                                posy=tab[i]->getposY()-25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()>720 && tab[i]->getposY()>470))
                            {
                                posy=tab[i]->getposY()-25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()<475 && tab[i]->getposY()>425))
                            {
                                posy=tab[i]->getposY()-25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposX()<700 && tab[i]->getposX()>500 && tab[i]->getposY()<170))
                            {
                                posy=tab[i]->getposY()-25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement-1;
                            }
                            if((tab[i]->getposX()<675 && tab[i]->getposX()>520 && tab[i]->getposY()>420))
                            {
                                posy=tab[i]->getposY()-25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposY()<390 && tab[i]->getposY()>240 && tab[i]->getposX()<500))
                            {
                                posy=tab[i]->getposY()-25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposY()<325 && tab[i]->getposY()>215 && tab[i]->getposX()>725))
                            {
                                posy=tab[i]->getposY()-25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if((tab[i]->getposY()<450 && tab[i]->getposY()>340 && tab[i]->getposX()>745))
                            {
                                posy=tab[i]->getposY()-25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }
                            if(!(tab[i]->getposY()<570 && tab[i]->getposY()>80 && tab[i]->getposX()>275 && tab[i]->getposX()<925))
                            {
                                posy=tab[i]->getposY()-25;
                                tab[i]->setposY(posy);

                                deplacement=deplacement+1;
                            }

                        }

                    }
                }
                else
                {
                    fin=1;
                }

                //std::cout<<"4"<<std::endl;
                if(tab[i]->getposX()==525 && tab[i]->getposY()==225 && depSup==0)
                {
                    deplacement=deplacement+3;
                    depSup=1;
                }
                if(tab[i]->getposX()==700 && tab[i]->getposY()==425 && depSup==0)
                {
                    deplacement=deplacement+3;
                    depSup=1;
                }

                if(tab[i]->getposX()==500 && tab[i]->getposY()==375)
                {
                    tab[i]->setposX(750);
                    tab[i]->setposY(150);
                }
                if(tab[i]->getposX()==675 && tab[i]->getposY()==250)
                {
                    tab[i]->setposX(875);
                    tab[i]->setposY(450);
                }


                if(deplacement==0 && finPartie==0)
                {
                    vec[i]->affichage(page, fond, croix, blocknote2,tab,i,perso, arme, lieux, valide);

                    fin=1;
                    depSup=0;
                }

                rest(100);

                //std::cout<<"6"<<std::endl;

                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            }
        }
    }

}


void Partie::Sauvegarde(int nbJ, std::vector<Perso*> tab)
{

    std::string const nomFichier("sauvegarde.txt");
    std::ofstream monFlux(nomFichier.c_str());

    if(monFlux)
    {
        for(int i=0;i<nbJ;i++)
        {
            if(tab[i]->getHypothese()==2)
            {
                monFlux << "le joueur : " << tab[i]->getNom() << " ayant pour mot de passe : " << tab[i]->getMotDePasse() << " a joue sa  : " << tab[i]->getNbParties() << "partie et a gagne" << std::endl;
            }
            else
            {
                monFlux << "le joueur : " << tab[i]->getNom() << " ayant pour mot de passe : " << tab[i]->getMotDePasse() << " a joue sa  : " << tab[i]->getNbParties() << "partie et a perdu" << std::endl;
            }

        }
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}
