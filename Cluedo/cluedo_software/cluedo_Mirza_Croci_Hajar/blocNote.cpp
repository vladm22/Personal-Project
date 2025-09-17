#include "header.h"
#include <vector>



BlocNote::BlocNote()
{
    for(int i=0;i<6;i++)
    {
        m_perso[i]=0;
    }

    for(int i=0;i<9;i++)
    {
        m_lieu[i]=0;
        m_arme[i]=0;
    }
}
BlocNote::~BlocNote()
{

}

int BlocNote::getBN_perso(int num)const
{
    return m_perso[num];
}
int BlocNote::getBN_lieu(int num)const
{
    return m_lieu[num];
}
int BlocNote::getBN_arme(int num)const
{
    return m_arme[num];
}
void BlocNote::setBN_perso(int num, int perso)
{
    m_perso[num]=perso;
}
void BlocNote::setBN_lieu(int num, int lieu)
{
    m_lieu[num]=lieu;
}
void BlocNote::setBN_arme(int num, int arme)
{
    m_arme[num]=arme;
}



void BlocNote::affichage(BITMAP *page,BITMAP *fond, BITMAP * croix, BITMAP *blocknote2,std::vector<Perso*> tab, int k,BITMAP *perso[6], BITMAP *arme[9], BITMAP *lieux[9], BITMAP *valide)
{
    int fin=0;

    while(fin==0)
    {
        clear_bitmap(page);
        blit(fond,page,0,0,(SCREEN_W-fond->w)/2, (SCREEN_H-fond->h)/2,fond->w,fond->h);
        masked_blit(valide,page,0,0, 0, 0, valide->w, valide->h);
        masked_blit(blocknote2,page,0,0,(SCREEN_W-blocknote2->w)/2, (SCREEN_H-blocknote2->h)/2, blocknote2->w, blocknote2->h);
        textprintf_ex(page,font,60,10,makecol(0,255,0),makecol(0,0,0),"%4d %4d",mouse_x,mouse_y);

        if(mouse_b&1 && mouse_x<540 && mouse_x>490 && mouse_y<160 && mouse_y>80)
        {
            //perso1
            m_perso[0]=1;
        }
        if(mouse_b&1 && mouse_x<610 && mouse_x>560 && mouse_y<160 && mouse_y>80)
        {
            //perso2
            m_perso[1]=1;
        }
        if(mouse_b&1 && mouse_x<725 && mouse_x>645 && mouse_y<160 && mouse_y>80)
        {
            //perso3
            m_perso[2]=1;
        }
        if(mouse_b&1 && mouse_x<540 && mouse_x>490 && mouse_y<250 && mouse_y>170)
        {
            //perso4
            m_perso[3]=1;
        }
        if(mouse_b&1 && mouse_x<610 && mouse_x>560 && mouse_y<250 && mouse_y>170)
        {
            //perso5
            m_perso[4]=1;
        }
        if(mouse_b&1 && mouse_x<725 && mouse_x>645 && mouse_y<250 && mouse_y>170)
        {
            //perso6
            m_perso[5]=1;
        }


        if(mouse_b&1 && mouse_x<510 && mouse_x>460 && mouse_y<330 && mouse_y>260)
        {
            //perso1
            m_arme[0]=1;
        }
        if(mouse_b&1 && mouse_x<590 && mouse_x>540 && mouse_y<330 && mouse_y>260)
        {
            //perso2
            m_arme[1]=1;
        }
        if(mouse_b&1 && mouse_x<670 && mouse_x>620 && mouse_y<330 && mouse_y>260)
        {
            //perso3
            m_arme[2]=1;
        }
        if(mouse_b&1 && mouse_x<750 && mouse_x>700 && mouse_y<330 && mouse_y>260)
        {
            //perso4
            m_arme[3]=1;
        }
        if(mouse_b&1 && mouse_x<495 && mouse_x>445 && mouse_y<410 && mouse_y>340)
        {
            //perso5
            m_arme[4]=1;
        }
        if(mouse_b&1 && mouse_x<560 && mouse_x>510 && mouse_y<410 && mouse_y>340)
        {
            //perso6
            m_arme[5]=1;
        }
        if(mouse_b&1 && mouse_x<625 && mouse_x>575 && mouse_y<410 && mouse_y>340)
        {
            //perso5
            m_arme[6]=1;
        }
        if(mouse_b&1 && mouse_x<690 && mouse_x>640 && mouse_y<410 && mouse_y>340)
        {
            //perso6
            m_arme[7]=1;
        }
        if(mouse_b&1 && mouse_x<755 && mouse_x>705 && mouse_y<410 && mouse_y>340)
        {
            //perso5
            m_arme[8]=1;
        }



        if(mouse_b&1 && mouse_x<510 && mouse_x>460 && mouse_y<495 && mouse_y>420)
        {
            //perso1
            m_lieu[0]=1;
        }
        if(mouse_b&1 && mouse_x<590 && mouse_x>540 && mouse_y<495 && mouse_y>420)
        {
            //perso2
            m_lieu[1]=1;
        }
        if(mouse_b&1 && mouse_x<670 && mouse_x>620 && mouse_y<495 && mouse_y>420)
        {
            //perso3
            m_lieu[2]=1;
        }
        if(mouse_b&1 && mouse_x<745 && mouse_x>695 && mouse_y<495 && mouse_y>420)
        {
            //perso4
            m_lieu[3]=1;
        }
        if(mouse_b&1 && mouse_x<495 && mouse_x>445 && mouse_y<575 && mouse_y>500)
        {
            //perso5
            m_lieu[4]=1;
        }
        if(mouse_b&1 && mouse_x<560 && mouse_x>510 && mouse_y<575 && mouse_y>500)
        {
            //perso6
            m_lieu[5]=1;
        }
        if(mouse_b&1 && mouse_x<625 && mouse_x>575 && mouse_y<575 && mouse_y>500)
        {
            //perso5
            m_lieu[6]=1;
        }
        if(mouse_b&1 && mouse_x<690 && mouse_x>640 && mouse_y<575 && mouse_y>500)
        {
            //perso6
            m_lieu[7]=1;
        }
        if(mouse_b&1 && mouse_x<755 && mouse_x>705 && mouse_y<575 && mouse_y>500)
        {
            //perso5
            m_lieu[8]=1;
        }


        textprintf_ex(page,font,890,150,makecol(0,255,0),makecol(0,0,0),"VOS CARTE :");

        int X=790;
        int Y=200;

    for(int j=0; j<11; j++)
    {
        X=X+60;
        if(j==3 || j==6 || j==9)
        {
            Y=Y+80;
            X=850;
        }

        if(tab[k]->getMain(j)==1)
        {
            blit(lieux[0],page,0,0,X,Y, lieux[0]->w, lieux[0]->h);
        }
        if(tab[k]->getMain(j)==2)
        {
            blit(lieux[1],page,0,0,X,Y, lieux[1]->w, lieux[1]->h);
        }
        if(tab[k]->getMain(j)==3)
        {
            blit(lieux[2],page,0,0,X,Y, lieux[2]->w, lieux[2]->h);
        }
        if(tab[k]->getMain(j)==4)
        {
            blit(lieux[3],page,0,0,X,Y, lieux[3]->w, lieux[3]->h);
        }
        if(tab[k]->getMain(j)==5)
        {
            blit(lieux[4],page,0,0,X,Y, lieux[4]->w, lieux[4]->h);
        }
        if(tab[k]->getMain(j)==6)
        {
            blit(lieux[5],page,0,0,X,Y, lieux[5]->w, lieux[5]->h);
        }
        if(tab[k]->getMain(j)==7)
        {
            blit(lieux[6],page,0,0,X,Y, lieux[6]->w, lieux[6]->h);
        }
        if(tab[k]->getMain(j)==8)
        {
            blit(lieux[7],page,0,0,X,Y, lieux[7]->w, lieux[7]->h);
        }
        if(tab[k]->getMain(j)==9)
        {
            blit(lieux[8],page,0,0,X,Y, lieux[8]->w, lieux[8]->h);
        }
        if(tab[k]->getMain(j)==10)
        {
            blit(arme[0],page,0,0,X,Y, arme[0]->w, arme[0]->h);
        }
        if(tab[k]->getMain(j)==11)
        {
            blit(arme[1],page,0,0,X,Y, arme[1]->w, arme[1]->h);
        }
        if(tab[k]->getMain(j)==12)
        {
            blit(arme[2],page,0,0,X,Y, arme[2]->w, arme[2]->h);
        }
        if(tab[k]->getMain(j)==13)
        {
            blit(arme[3],page,0,0,X,Y, arme[3]->w, arme[3]->h);
        }
        if(tab[k]->getMain(j)==14)
        {
            blit(arme[4],page,0,0,X,Y, arme[4]->w, arme[4]->h);
        }
        if(tab[k]->getMain(j)==15)
        {
            blit(arme[5],page,0,0,X,Y, arme[5]->w, arme[5]->h);
        }
        if(tab[k]->getMain(j)==16)
        {
            blit(arme[6],page,0,0,X,Y, arme[6]->w, arme[6]->h);
        }
        if(tab[k]->getMain(j)==17)
        {
            blit(arme[7],page,0,0,X,Y, arme[7]->w, arme[7]->h);
        }
        if(tab[k]->getMain(j)==18)
        {
            blit(arme[8],page,0,0,X,Y, arme[8]->w, arme[8]->h);
        }
        if(tab[k]->getMain(j)==19)
        {
            blit(perso[0],page,0,0,X,Y, perso[0]->w, perso[0]->h);
        }
        if(tab[k]->getMain(j)==20)
        {
            blit(perso[1],page,0,0,X,Y, perso[1]->w, perso[1]->h);
        }
        if(tab[k]->getMain(j)==21)
        {
            blit(perso[2],page,0,0,X,Y, perso[2]->w, perso[2]->h);
        }
        if(tab[k]->getMain(j)==22)
        {
            blit(perso[3],page,0,0,X,Y, perso[3]->w, perso[3]->h);
        }
        if(tab[k]->getMain(j)==23)
        {
            blit(perso[4],page,0,0,X,Y, perso[4]->w, perso[4]->h);
        }
        if(tab[k]->getMain(j)==24)
        {
            blit(perso[5],page,0,0,X,Y, perso[5]->w, perso[5]->h);
        }
    }


        if((mouse_b&1 && mouse_x<200 && mouse_x>0 && mouse_y<200 && mouse_y>0 ))
        {
            fin=1;
        }

        for(int i=0;i<6;i++)
        {

            if(m_perso[i]==1 && i==0)
            {
                masked_blit(croix, page, 0,0,490,80,croix->w,croix->h);
            }
            if(m_perso[i]==1 && i==1)
            {
                masked_blit(croix, page, 0,0,560,80,croix->w,croix->h);
            }
            if(m_perso[i]==1 && i==2)
            {
                masked_blit(croix, page, 0,0,645,80,croix->w,croix->h);
            }
            if(m_perso[i]==1 && i==3)
            {
                masked_blit(croix, page, 0,0,490,170,croix->w,croix->h);
            }
            if(m_perso[i]==1 && i==4)
            {
                masked_blit(croix, page, 0,0,560,170,croix->w,croix->h);
            }
            if(m_perso[i]==1 && i==5)
            {
                masked_blit(croix, page, 0,0,645,170,croix->w,croix->h);
            }
        }
        for(int i=0;i<9;i++)
        {
            if(m_arme[i]==1 && i==0)
            {
                masked_blit(croix, page, 0,0,460,260,croix->w,croix->h);
            }
            if(m_arme[i]==1 && i==1)
            {
                masked_blit(croix, page, 0,0,540,260,croix->w,croix->h);
            }
            if(m_arme[i]==1 && i==2)
            {
                masked_blit(croix, page, 0,0,620,260,croix->w,croix->h);
            }
            if(m_arme[i]==1 && i==3)
            {
                masked_blit(croix, page, 0,0,700,260,croix->w,croix->h);
            }
            if(m_arme[i]==1 && i==4)
            {
                masked_blit(croix, page, 0,0,445,340,croix->w,croix->h);
            }
            if(m_arme[i]==1 && i==5)
            {
                masked_blit(croix, page, 0,0,510,340,croix->w,croix->h);
            }
            if(m_arme[i]==1 && i==6)
            {
                masked_blit(croix, page, 0,0,575,340,croix->w,croix->h);
            }
            if(m_arme[i]==1 && i==7)
            {
                masked_blit(croix, page, 0,0,640,340,croix->w,croix->h);
            }
            if(m_arme[i]==1 && i==8)
            {
                masked_blit(croix, page, 0,0,705,340,croix->w,croix->h);
            }


            if(m_lieu[i]==1 && i==0)
            {
                masked_blit(croix, page, 0,0,460,420,croix->w,croix->h);
            }
            if(m_lieu[i]==1 && i==1)
            {
                masked_blit(croix, page, 0,0,540,420,croix->w,croix->h);
            }
            if(m_lieu[i]==1 && i==2)
            {
                masked_blit(croix, page, 0,0,620,420,croix->w,croix->h);
            }
            if(m_lieu[i]==1 && i==3)
            {
                masked_blit(croix, page, 0,0,695,420,croix->w,croix->h);
            }
            if(m_lieu[i]==1 && i==4)
            {
                masked_blit(croix, page, 0,0,445,500,croix->w,croix->h);
            }
            if(m_lieu[i]==1 && i==5)
            {
                masked_blit(croix, page, 0,0,510,500,croix->w,croix->h);
            }
            if(m_lieu[i]==1 && i==6)
            {
                masked_blit(croix, page, 0,0,575,500,croix->w,croix->h);
            }
            if(m_lieu[i]==1 && i==7)
            {
                masked_blit(croix, page, 0,0,640,500,croix->w,croix->h);
            }
            if(m_lieu[i]==1 && i==8)
            {
                masked_blit(croix, page, 0,0,705,500,croix->w,croix->h);
            }
        }

        show_mouse(page);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(100);

        }
}





void BlocNote :: affPartie(BITMAP *croix1, BITMAP *page)
{
    for(int i=0;i<6;i++)
        {
            if(m_perso[i]==1 && i==0)
            {
                masked_blit(croix1, page, 0,0,50,155,croix1->w,croix1->h);
            }
            if(m_perso[i]==1 && i==1)
            {
                masked_blit(croix1, page, 0,0,100,155,croix1->w,croix1->h);
            }
            if(m_perso[i]==1 && i==2)
            {
                masked_blit(croix1, page, 0,0,150,155,croix1->w,croix1->h);
            }
            if(m_perso[i]==1 && i==3)
            {
                masked_blit(croix1, page, 0,0,50,215,croix1->w,croix1->h);
            }
            if(m_perso[i]==1 && i==4)
            {
                masked_blit(croix1, page, 0,0,100,215,croix1->w,croix1->h);
            }
            if(m_perso[i]==1 && i==5)
            {
                masked_blit(croix1, page, 0,0,150,215,croix1->w,croix1->h);
            }
        }
        for(int i=0;i<9;i++)
        {
            if(m_arme[i]==1 && i==0)
            {
                masked_blit(croix1, page, 0,0,30,270,croix1->w,croix1->h);
            }
            if(m_arme[i]==1 && i==1)
            {
                masked_blit(croix1, page, 0,0,85,270,croix1->w,croix1->h);
            }
            if(m_arme[i]==1 && i==2)
            {
                masked_blit(croix1, page, 0,0,140,270,croix1->w,croix1->h);
            }
            if(m_arme[i]==1 && i==3)
            {
                masked_blit(croix1, page, 0,0,190,270,croix1->w,croix1->h);
            }
            if(m_arme[i]==1 && i==4)
            {
                masked_blit(croix1, page, 0,0,20,325,croix1->w,croix1->h);
            }
            if(m_arme[i]==1 && i==5)
            {
                masked_blit(croix1, page, 0,0,65,325,croix1->w,croix1->h);
            }
            if(m_arme[i]==1 && i==6)
            {
                masked_blit(croix1, page, 0,0,110,325,croix1->w,croix1->h);
            }
            if(m_arme[i]==1 && i==7)
            {
                masked_blit(croix1, page, 0,0,155,325,croix1->w,croix1->h);
            }
            if(m_arme[i]==1 && i==8)
            {
                masked_blit(croix1, page, 0,0,200,325,croix1->w,croix1->h);
            }


            if(m_lieu[i]==1 && i==0)
            {
                masked_blit(croix1, page, 0,0,30,380,croix1->w,croix1->h);
            }
            if(m_lieu[i]==1 && i==1)
            {
                masked_blit(croix1, page, 0,0,85,380,croix1->w,croix1->h);
            }
            if(m_lieu[i]==1 && i==2)
            {
                masked_blit(croix1, page, 0,0,135,380,croix1->w,croix1->h);
            }
            if(m_lieu[i]==1 && i==3)
            {
                masked_blit(croix1, page, 0,0,190,380,croix1->w,croix1->h);
            }
            if(m_lieu[i]==1 && i==4)
            {
                masked_blit(croix1, page, 0,0,20,430,croix1->w,croix1->h);
            }
            if(m_lieu[i]==1 && i==5)
            {
                masked_blit(croix1, page, 0,0,65,430,croix1->w,croix1->h);
            }
            if(m_lieu[i]==1 && i==6)
            {
                masked_blit(croix1, page, 0,0,110,430,croix1->w,croix1->h);
            }
            if(m_lieu[i]==1 && i==7)
            {
                masked_blit(croix1, page, 0,0,155,430,croix1->w,croix1->h);
            }
            if(m_lieu[i]==1 && i==8)
            {
                masked_blit(croix1, page, 0,0,200,430,croix1->w,croix1->h);
            }
        }
}
