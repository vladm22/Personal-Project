#include "header.h"
#include <vector>




std::vector<Perso*> CreationPersonnage(int nbJ, BITMAP *page,BITMAP *fond)
{
    std::vector<Perso*>tab(nbJ);

    int tabL[9];
    int tabA[9];
    int tabP[6];
    int tabEnveloppe[3];
    int tabFinal[21];
    int tailleL=9;
    int tailleA=9;
    int tailleP=6;
    int tailleF=21;


    for (int i=1; i<10; i++)
    {
        tabL[i-1]=i;
    }
    for (int i=10; i<19; i++)
    {
        tabA[i-10]=i;
    }
    for (int i=19; i<25; i++)
    {
        tabP[i-19]=i;
    }

    int tab2[tailleL];
    int tab3[tailleA];
    int tab4[tailleP];
    int tab5[tailleF];
    int taille2=tailleL;
    int j,k;

    for(int i=0; i<taille2; i++)
    {
        j=rand()%tailleL;

        tab2[i]=tabL[j];
        for(k=j; k<tailleL; k++)
        {
            tabL[k]=tabL[k+1];
        }
        tailleL=tailleL-1;
    }

    taille2=tailleA;

    for(int i=0; i<taille2; i++)
    {
        j=rand()%tailleA;

        tab3[i]=tabA[j];
        for(k=j; k<tailleA; k++)
        {
            tabA[k]=tabA[k+1];
        }
        tailleA=tailleA-1;
    }

    taille2=tailleP;
    for(int i=0; i<taille2; i++)
    {
        j=rand()%tailleP;

        tab4[i]=tabP[j];
        for(k=j; k<tailleP; k++)
        {
            tabP[k]=tabP[k+1];
        }
        tailleP=tailleP-1;
    }

    Carte_Lieu L(1,"dorian",tab2);
    std::cout<<"***************"<<std::endl;
    Carte_Arme A(2,"vlad",tab3);
    std::cout<<"***************"<<std::endl;
    Carte_Personnage P(3,"victoria",tab4);
    std::cout<<"***************"<<std::endl;

    tabEnveloppe[0]=L.tirerUneCarte();
    tabEnveloppe[1]=A.tirerUneCarte();
    tabEnveloppe[2]=P.tirerUneCarte();

    for(int i=0;i<3;i++)
    {
        std::cout<<tabEnveloppe[i]<<std::endl;
    }
    std::cout<<"***************"<<std::endl;
    for (int i=0; i<9; i++)
    {
        std::cout<<tab2[i]<<std::endl;
    }
    std::cout<<"***************"<<std::endl;
    for (int i=0; i<9; i++)
    {
        std::cout<<tab3[i]<<std::endl;
    }
    std::cout<<"***************"<<std::endl;
    for (int i=0; i<6; i++)
    {
        std::cout<<tab4[i]<<std::endl;
    }

    for (int i=0; i<8; i++)
    {
        tabFinal[i]=tab2[i];
    }
    for (int i=8; i<16; i++)
    {
        tabFinal[i]=tab3[i-8];
    }
    for (int i=16; i<21; i++)
    {
        tabFinal[i]=tab4[i-16];
    }

    for(int i=0;i<21;i++)
    {
        std::cout<<tabFinal[i]<<std::endl;
    }

    taille2=tailleF;

    for(int i=0; i<taille2; i++)
    {
        j=rand()%tailleF;

        tab5[i]=tabFinal[j];
        for(k=j; k<tailleF; k++)
        {
            tabFinal[k]=tabFinal[k+1];
        }
        tailleF=tailleF-1;
    }

    std::cout<<"*************************"<<std::endl;
    for(int i=0;i<21;i++)
    {
        std::cout<<tab5[i]<<std::endl;
    }

    std::cout<<"dans enveloppe"<<std::endl;




    // Nombre de perso
    BITMAP *croix;
    BITMAP *P1;
    BITMAP *P2;
    BITMAP *P3;
    BITMAP *P4;
    BITMAP *P5;
    BITMAP *P6;


    int choix1=0;
    int n=0;
    int val1=0,val2=0,val3=0,val4=0,val5=0,val6=0;

    //page=create_bitmap(SCREEN_W,SCREEN_H);
    croix=load_bitmap("croix.bmp",NULL);
    P1=load_bitmap("luffy.bmp",NULL);
    P2=load_bitmap("nami.bmp",NULL);
    P3=load_bitmap("zoro.bmp",NULL);
    P4=load_bitmap("Sanji.bmp",NULL);
    P5=load_bitmap("robin.bmp",NULL);
    P6=load_bitmap("usopp.bmp",NULL);

    if (!P1 &&!P2 &&!P3 &&!P4 &&!P5 &&!P6 &&!croix)
    {
        allegro_message("pas pu trouver/charger menu.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    /// saisie des noms
        std::string nom1;
        std::string nom2;
        std::string nom3;
        std::string nom4;
        std::string nom5;
        std::string nom6;
        std::string motdepasse1;
        std::string motdepasse2;
        std::string motdepasse3;
        std::string motdepasse4;
        std::string motdepasse5;
        std::string motdepasse6;
        std::vector<std::string> nom[6];
        std::string recep;
        std::string touche;
        std::string carac;



    for(int i=0;i<nbJ;i++)
    {
        std::cout<<"Saisir le nom du joueur numero "<<i+1<<std::endl;

        if(i==0)
        {
            std::cin>>nom1;
        }
        if(i==1)
        {
            std::cin>>nom2;
        }
        if(i==2)
        {
            std::cin>>nom3;
        }
        if(i==3)
        {
            std::cin>>nom4;
        }
        if(i==4)
        {
            std::cin>>nom5;
        }
        if(i==5)
        {
            std::cin>>nom6;
        }

        std::cout<<"Saisir le mot de passe du joueur numero "<<i+1<<std::endl;

        if(i==0)
        {
            std::cin>>motdepasse1;
        }
        if(i==1)
        {
            std::cin>>motdepasse2;
        }
        if(i==2)
        {
            std::cin>>motdepasse3;
        }
        if(i==3)
        {
            std::cin>>motdepasse4;
        }
        if(i==4)
        {
            std::cin>>motdepasse5;
        }
        if(i==5)
        {
            std::cin>>motdepasse6;
        }
    }

    /// choix du pion
    int logo[nbJ];
    choix1=nbJ;
    mouse_b=0;

    while (choix1!=0)
    {
        clear_bitmap(page);

        blit(fond,page,0,0, (SCREEN_W-fond->w)/2, (SCREEN_H-fond->h)/2, fond->w, fond->h);

        blit(P1,page,0,0,180 ,250 , P1->w, P1->h);
        blit(P2,page,0,0,330 ,250 , P2->w, P2->h);
        blit(P3,page,0,0, 480,250 , P3->w, P3->h);
        blit(P4,page,0,0,625 ,250 , P4->w, P4->h);
        blit(P5,page,0,0,775 ,250 , P5->w, P5->h);
        blit(P6,page,0,0,925 ,250 , P6->w, P6->h);

        if(val1==1)
        {
            masked_blit(croix, page, 0,0,180,250,croix->w,croix->h);
        }
        if(val2==1)
        {
            masked_blit(croix, page, 0,0,330,250,croix->w,croix->h);
        }
        if(val3==1)
        {
            masked_blit(croix, page, 0,0,480,250,croix->w,croix->h);
        }
        if(val4==1)
        {
            masked_blit(croix, page, 0,0,625,250,croix->w,croix->h);
        }
        if(val5==1)
        {
            masked_blit(croix, page, 0,0,775,250,croix->w,croix->h);
        }
        if(val6==1)
        {
            masked_blit(croix, page, 0,0,925,250,croix->w,croix->h);
        }


         if ( val1==0 && mouse_b&1 && mouse_x>=180 && mouse_y>=250&& mouse_x<=285 && mouse_y<=400 )
        {
            logo[n]=1;
            n++;
            masked_blit(croix, page, 0,0,180,250,croix->w,croix->h);
            choix1=choix1-1;
            val1=1;
            mouse_b=0;
        }
        if ( val2==0 && mouse_b&1 && mouse_x>=330 && mouse_y>=250&& mouse_x<=435 && mouse_y<=400 )
        {
            logo[n]=2;
            n++;
            masked_blit(croix, page, 0,0,330,250,croix->w,croix->h);
            choix1=choix1-1;
            val2=1;
            mouse_b=0;
        }
        if ( val3==0 &&mouse_b&1 && mouse_x>=480 && mouse_y>=250&& mouse_x<=585 && mouse_y<=400)
        {
            logo[n]=3;
            n++;
            masked_blit(croix, page, 0,0,480,250,croix->w,croix->h);
            choix1=choix1-1;
            val3=1;
            mouse_b=0;
        }
        if ( val4==0 &&mouse_b&1 && mouse_x>=625 && mouse_y>=250&& mouse_x<=730 && mouse_y<=400)
        {
            logo[n]=4;
            n++;
            masked_blit(croix, page, 0,0,625,250,croix->w,croix->h);
            choix1=choix1-1;
            val4=1;
            mouse_b=0;
        }
        if ( val5==0 &&mouse_b&1 && mouse_x>=775 && mouse_y>=250&& mouse_x<=880 && mouse_y<=400)
        {
            logo[n]=5;
            n++;
            masked_blit(croix, page, 0,0,775,250,croix->w,croix->h);
            choix1=choix1-1;
            val5=1;
            mouse_b=0;
        }
        if ( val6==0 &&mouse_b&1 && mouse_x>=925 && mouse_y>=250&& mouse_x<=1030 && mouse_y<=400)
        {
            logo[n]=6;
            n++;
            masked_blit(croix, page, 0,0,925,250,croix->w,croix->h);
            choix1=choix1-1;
            val6=1;
            mouse_b=0;
        }

        show_mouse(page);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    }

    if(nbJ==2)
    {
        int main1[11]={0,0,0,0,0,0,0,0,0,0,0};
        int main2[10]={0,0,0,0,0,0,0,0,0,0};

        main1[0]=tab5[0];
        main1[1]=tab5[1];
        main1[2]=tab5[2];
        main1[3]=tab5[3];
        main1[4]=tab5[4];
        main1[5]=tab5[5];
        main1[6]=tab5[6];
        main1[7]=tab5[7];
        main1[8]=tab5[8];
        main1[9]=tab5[9];
        main1[10]=tab5[10];

        main2[0]=tab5[11];
        main2[1]=tab5[12];
        main2[2]=tab5[13];
        main2[3]=tab5[14];
        main2[4]=tab5[15];
        main2[5]=tab5[16];
        main2[6]=tab5[17];
        main2[7]=tab5[18];
        main2[8]=tab5[19];
        main2[9]=tab5[20];

        tab[0]= new Perso(300,225,logo[0],main1,nom1,motdepasse1,1);
        tab[1]= new Perso(900,200,logo[1],main2,nom2,motdepasse2,1);
    }

    if(nbJ==3)
    {
        int main1[9]={0,0,0,0,0,0,0,0,0};
        int main2[9]={0,0,0,0,0,0,0,0,0};
        int main3[9]={0,0,0,0,0,0,0,0,0};

        main1[0]=tab5[0];
        main1[1]=tab5[1];
        main1[2]=tab5[2];
        main1[3]=tab5[3];
        main1[4]=tab5[4];
        main1[5]=tab5[5];
        main1[6]=tab5[6];

        main2[0]=tab5[7];
        main2[1]=tab5[8];
        main2[2]=tab5[9];
        main2[3]=tab5[10];
        main2[4]=tab5[11];
        main2[5]=tab5[12];
        main2[6]=tab5[13];

        main3[0]=tab5[14];
        main3[1]=tab5[15];
        main3[2]=tab5[16];
        main3[3]=tab5[17];
        main3[4]=tab5[18];
        main3[5]=tab5[19];
        main2[6]=tab5[20];

        tab[0]= new Perso(300,225,logo[0],main1,nom1,motdepasse1,1);
        tab[1]= new Perso(900,200,logo[1],main2,nom2,motdepasse2,1);
        tab[2]= new Perso(725,100,logo[2],main3,nom3,motdepasse3,1);
    }

    if(nbJ==4)
    {
        int main1[9]={0,0,0,0,0,0,0,0,0};
        int main2[9]={0,0,0,0,0,0,0,0,0};
        int main3[9]={0,0,0,0,0,0,0,0,0};
        int main4[9]={0,0,0,0,0,0,0,0,0};

        main1[0]=tab5[0];
        main1[1]=tab5[1];
        main1[2]=tab5[2];
        main1[3]=tab5[3];
        main1[4]=tab5[4];
        main1[5]=tab5[5];

        main2[0]=tab5[6];
        main2[1]=tab5[7];
        main2[2]=tab5[8];
        main2[3]=tab5[9];
        main2[4]=tab5[10];

        main3[0]=tab5[11];
        main3[1]=tab5[12];
        main3[2]=tab5[13];
        main3[3]=tab5[14];
        main3[4]=tab5[15];

        main4[0]=tab5[16];
        main4[1]=tab5[17];
        main4[2]=tab5[18];
        main4[3]=tab5[19];
        main4[4]=tab5[20];


        tab[0]= new Perso(300,225,logo[0],main1,nom1,motdepasse1,1);
        tab[1]= new Perso(900,200,logo[1],main2,nom2,motdepasse2,1);
        tab[2]= new Perso(725,100,logo[2],main3,nom3,motdepasse3,1);
        tab[3]= new Perso(500,525,logo[3],main4,nom4,motdepasse4,1);
    }
    if(nbJ==5)
    {
        int main1[9]={0,0,0,0,0,0,0,0,0};
        int main2[9]={0,0,0,0,0,0,0,0,0};
        int main3[9]={0,0,0,0,0,0,0,0,0};
        int main4[9]={0,0,0,0,0,0,0,0,0};
        int main5[9]={0,0,0,0,0,0,0,0,0};

        main1[0]=tab5[0];
        main1[1]=tab5[1];
        main1[2]=tab5[2];
        main1[3]=tab5[3];
        main1[4]=tab5[4];

        main2[0]=tab5[5];
        main2[1]=tab5[6];
        main2[2]=tab5[7];
        main2[3]=tab5[8];

        main3[0]=tab5[9];
        main3[1]=tab5[10];
        main3[2]=tab5[11];
        main3[3]=tab5[12];

        main4[0]=tab5[13];
        main4[1]=tab5[14];
        main4[2]=tab5[15];
        main4[3]=tab5[16];

        main5[0]=tab5[17];
        main5[1]=tab5[18];
        main5[2]=tab5[19];
        main5[3]=tab5[20];

        tab[0]= new Perso(300,225,logo[0],main1,nom1,motdepasse1,1);
        tab[1]= new Perso(900,200,logo[1],main2,nom2,motdepasse2,1);
        tab[2]= new Perso(725,100,logo[2],main3,nom3,motdepasse3,1);
        tab[3]= new Perso(500,525,logo[3],main4,nom4,motdepasse4,1);
        tab[4]= new Perso(300,400,logo[4],main5,nom5,motdepasse5,1);
    }
    if(nbJ==6)
    {
        int main1[9]={0,0,0,0,0,0,0,0,0};
        int main2[9]={0,0,0,0,0,0,0,0,0};
        int main3[9]={0,0,0,0,0,0,0,0,0};
        int main4[9]={0,0,0,0,0,0,0,0,0};
        int main5[9]={0,0,0,0,0,0,0,0,0};
        int main6[9]={0,0,0,0,0,0,0,0,0};

        main1[0]=tab5[0];
        main1[1]=tab5[1];
        main1[2]=tab5[2];
        main1[3]=tab5[3];

        main2[0]=tab5[4];
        main2[1]=tab5[5];
        main2[2]=tab5[6];
        main2[3]=tab5[7];

        main3[0]=tab5[8];
        main3[1]=tab5[9];
        main3[2]=tab5[10];
        main3[3]=tab5[11];

        main4[0]=tab5[12];
        main4[1]=tab5[13];
        main4[2]=tab5[14];

        main5[0]=tab5[15];
        main5[1]=tab5[16];
        main5[2]=tab5[17];

        main6[0]=tab5[18];
        main6[1]=tab5[19];
        main6[2]=tab5[20];

        tab[0]= new Perso(300,225,logo[0],main1,nom1,motdepasse1,1);
        tab[1]= new Perso(900,200,logo[1],main2,nom2,motdepasse2,1);
        tab[2]= new Perso(725,100,logo[2],main3,nom3,motdepasse3,1);
        tab[3]= new Perso(500,525,logo[3],main4,nom4,motdepasse4,1);
        tab[4]= new Perso(300,400,logo[4],main5,nom5,motdepasse5,1);
        tab[5]= new Perso(700,525,logo[5],main6,nom6,motdepasse6,1);
    }

    rest(1000);
    destroy_bitmap(P1);
    destroy_bitmap(P2);
    destroy_bitmap(P3);
    destroy_bitmap(P4);
    destroy_bitmap(P5);
    destroy_bitmap(P6);
    destroy_bitmap(croix);
    return tab;
}


