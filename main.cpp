#include <iostream>
#include <cstdio>
#include <windows.h>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>


int main()
{
    int task;
    do {
        SetConsoleOutputCP(CP_UTF8);
        int tasowanie = 100;
        int step=1000;
        printf("\nKarty: gra w wojne\n\n1.Wpisz ilość tasowań kart (aktualna: %d)\n2.Wpisz opóźnienie między rundami (aktualna: %dms)\n3.Rozpocznij gre\n4.Zakończ program\n\n",tasowanie,step);
        scanf("%d", &task);

        switch (task) {
            case 1:
                printf("Wpisz ilość tasowań kart:\n");
                scanf("%d", &tasowanie);
                break;

            case 2:
                printf("Wpisz opóźnienie między runfami (ms):\n");
                scanf("%d", &step);

                break;

            case 3:

                int x;
                int war_end;
                //TALIA CAŁA
                int talia[54];
                char nazwa1[54][6];
                char nazwa2[54][32];
                //TYMCZASOWA TALIA STOSOWANA W ZAMIENIANIU KART
                int taliatemp[2];
                char nazwa1temp[2][6];
                char nazwa2temp[2][32];
                //TALIA GRACZA 1
                int talia1[54]={};
                char nazwa11[54][6]={};
                char nazwa12[54][32]={};
                //TALIA GRACZA 2
                int talia2[54]={};
                char nazwa21[54][6]={};
                char nazwa22[54][32]={};


                //nadaj wartość liczbową karty (moc karty)
                int j=0;
                for (int i = 2; i <16 ; i++) {
                    talia[j]=i;
                    j++;
                    talia[j]=i;
                    j++;
                    talia[j]=i;
                    j++;
                    talia[j]=i;
                    j++;
                }
                // nadaj symbol karty: ♠♥♦♣
                for (int i=0;i<52;i=i+4) {
                    strcpy(nazwa2[i],"♠");
                    strcpy(nazwa2[i+1],"♥");
                    strcpy(nazwa2[i+2],"♦");
                    strcpy(nazwa2[i+3],"♣");
                }
                strcpy(nazwa2[52],"1");
                strcpy(nazwa2[53],"2");

                //nadaj nazwe słowną karty
                for (int i = 0; i <54 ; i++) {
                    if (i<4){strcpy(nazwa1[i],"2");}
                    if (i>3 && i<8){strcpy(nazwa1[i],"3");}
                    if (i>7 && i<12){strcpy(nazwa1[i],"4");}
                    if (i>11 && i<16){strcpy(nazwa1[i],"5");}
                    if (i>15 && i<20){strcpy(nazwa1[i],"6");}
                    if (i>19 && i<24){strcpy(nazwa1[i],"7");}
                    if (i>23 && i<28){strcpy(nazwa1[i],"8");}
                    if (i>27 && i<32){strcpy(nazwa1[i],"9");}
                    if (i>31 && i<36){strcpy(nazwa1[i],"10");}
                    if (i>35 && i<40){strcpy(nazwa1[i],"Jack");}
                    if (i>39 && i<44){strcpy(nazwa1[i],"Queen");}
                    if (i>43 && i<48){strcpy(nazwa1[i],"King");}
                    if (i>47 && i<52){strcpy(nazwa1[i],"Ace");}
                    if (i>51){strcpy(nazwa1[i],"Joker");}
                }

                // for (int n=0;n<54;n++) {
                //     printf("%d: %d - %s %s\n",n,talia[n],nazwa1[n],nazwa2[n]);
                // }
                srand(time(nullptr));
                int min = 0;
                int max = 53;
                int swap1;
                int swap2;

                //TASOWANIE TALI
                for (int i=0;i<tasowanie;i++) {

                    swap1 = rand() % (max - min + 1) + min;
                    taliatemp[0]=talia[swap1];
                    strcpy(nazwa1temp[0], nazwa1[swap1]);
                    strcpy(nazwa2temp[0], nazwa2[swap1]);

                    swap2 = rand() % (max - min + 1) + min;
                    taliatemp[1]=talia[swap2];
                    strcpy(nazwa1temp[1], nazwa1[swap2]);
                    strcpy(nazwa2temp[1], nazwa2[swap2]);

                    talia[swap2]=taliatemp[0];
                    talia[swap1]=taliatemp[1];
                    strcpy(nazwa1[swap1], nazwa1temp[1]);
                    strcpy(nazwa1[swap2], nazwa1temp[0]);
                    strcpy(nazwa2[swap1], nazwa2temp[1]);
                    strcpy(nazwa2[swap2], nazwa2temp[0]);

                }
                // printf("\n\n----------PO PRZETASOWANIU----------\n\n");
                //     for (int n=0;n<54;n++) {
                //         printf("%d: %d - %s %s\n",n,talia[n],nazwa1[n],nazwa2[n]);
                //     }

                //przydzielenie tali graczowi 1
                for (int i=0; i<27;i++) {
                    talia1[i]=talia[2*i];
                    strcpy(nazwa11[i],nazwa1[2*i]);
                    strcpy(nazwa21[i],nazwa2[2*i]);
                }
                //przydzielenie tali graczowi 2
                for (int i=0; i<27;i++) {
                    talia2[i]=talia[2*i+1];
                    strcpy(nazwa12[i],nazwa1[2*i+1]);
                    strcpy(nazwa22[i],nazwa2[2*i+1]);
                }

                // printf("\n\n----------Talia 1----------\n\n");
                // for (int n=0;n<54;n++) {
                //     printf("%d: %d - %s %s\n",n,talia1[n],nazwa11[n],nazwa21[n]);
                // }
                // printf("\n\n----------Talia 2----------\n\n");
                // for (int n=0;n<54;n++) {
                //     printf("%d:%d - %s %s\n",n,talia2[n],nazwa12[n],nazwa22[n]);
                // }


                //GRA
                int p1_start=0;
                int p1_end=26;
                int p2_start=0;
                int p2_end=26;
                int p1_count=27;
                int p2_count=27;
                int pole=0;
                int runda=1;
                do{
                    printf("\nRound %d!\n",runda);
                    printf("Player 1: %s %s\nPlayer 2: %s %s\n",nazwa11[pole],nazwa21[pole],nazwa12[pole],nazwa22[pole]);
                    if (talia1[pole]>talia2[pole]) {
                        //wygrywa gracz 1

                        talia1[(p1_end+1)%54]=talia2[pole];
                        talia2[pole]=0;
                        talia1[(p1_end+2)%54]=talia1[pole];
                        talia1[pole]=0;
                        strcpy(nazwa11[(p1_end+1)%54],nazwa12[pole]);
                        strcpy(nazwa12[pole],"");
                        strcpy(nazwa11[(p1_end+2)%54],nazwa11[pole]);
                        strcpy(nazwa11[pole],"");
                        strcpy(nazwa21[(p1_end+1)%54],nazwa22[pole]);
                        strcpy(nazwa22[pole],"");
                        strcpy(nazwa21[(p1_end+2)%54],nazwa21[pole]);
                        strcpy(nazwa21[pole],"");
                        p1_end=(p1_end+2)%54;
                        p1_count++;
                        p2_count--;
                        pole=(pole+1)%54;
                        printf("Player 1 wins.\n");
                    }
                    else if (talia1[pole]<talia2[pole]) {
                        //wygrywa gracz 2
                        talia2[(p2_end+1)%54]=talia1[pole];
                        talia1[pole]=0;
                        talia2[(p2_end+2)%54]=talia2[pole];
                        talia2[pole]=0;
                        strcpy(nazwa12[(p2_end+1)%54],nazwa11[pole]);
                        strcpy(nazwa11[pole],"");
                        strcpy(nazwa12[(p2_end+2)%54],nazwa12[pole]);
                        strcpy(nazwa12[pole],"");
                        strcpy(nazwa22[(p2_end+1)%54],nazwa21[pole]);
                        strcpy(nazwa21[pole],"");
                        strcpy(nazwa22[(p2_end+2)%54],nazwa22[pole]);
                        strcpy(nazwa22[pole],"");
                        p2_end=(p2_end+2)%54;
                        p2_count++;
                        p1_count--;
                        pole=(pole+1)%54;
                        printf("Player 2 wins.\n");
                    }
                    else {
                        //logika wojny
                        x=0;
                        do {
                            x=x+2;
                            printf("\nWar!\n\n");
                            std::this_thread::sleep_for(std::chrono::milliseconds(step));
                            printf("Player 1: %s %s\nPlayer 2: %s %s\n",nazwa11[(pole+x)%54],nazwa21[(pole+x)%54],nazwa12[(pole+x)%54],nazwa22[(pole+x)%54]);

                            if (x>53) {
                                //na wypadek gdy talie sa takie same (aby wojny nie byly dluzsze niz talia)
                                printf("\nDraw!");
                                return 0;
                            }
                        }while(talia1[(pole+x)%54]==talia2[(pole+x)%54]);
                        war_end=(pole+x)%54;
                        if (talia1[war_end]>talia2[war_end]) {
                            for (;pole!=(war_end+1)%54;pole=(pole+1)%54){

                                talia1[(p1_end+1)%54]=talia2[pole];
                                talia2[pole]=0;
                                talia1[(p1_end+2)%54]=talia1[pole];
                                talia1[pole]=0;
                                strcpy(nazwa11[(p1_end+1)%54],nazwa12[pole]);
                                strcpy(nazwa12[pole],"");
                                strcpy(nazwa11[(p1_end+2)%54],nazwa11[pole]);
                                strcpy(nazwa11[pole],"");
                                strcpy(nazwa21[(p1_end+1)%54],nazwa22[pole]);
                                strcpy(nazwa22[pole],"");
                                strcpy(nazwa21[(p1_end+2)%54],nazwa21[pole]);
                                strcpy(nazwa21[pole],"");
                                p1_end=(p1_end+2)%54;
                                p1_count++;
                                p2_count--;


                            }
                            printf("Player 1 wins the war.\n");
                        }
                        else if (talia1[war_end]<talia2[war_end]) {
                            for (;pole!=(war_end+1)%54;pole=(pole+1)%54) {
                                talia2[(p2_end+1)%54]=talia1[pole];
                                talia1[pole]=0;
                                talia2[(p2_end+2)%54]=talia2[pole];
                                talia2[pole]=0;
                                strcpy(nazwa12[(p2_end+1)%54],nazwa11[pole]);
                                strcpy(nazwa11[pole],"");
                                strcpy(nazwa12[(p2_end+2)%54],nazwa12[pole]);
                                strcpy(nazwa12[pole],"");
                                strcpy(nazwa22[(p2_end+1)%54],nazwa21[pole]);
                                strcpy(nazwa21[pole],"");
                                strcpy(nazwa22[(p2_end+2)%54],nazwa22[pole]);
                                strcpy(nazwa22[pole],"");
                                p2_end=(p2_end+2)%54;
                                p2_count++;
                                p1_count--;


                            }
                            printf("Player 2 wins the war.\n");
                        }
                    }

                    runda++;


                    if (talia1[pole]<2 && talia2[pole]<2) {
                        break;
                    }
                    if (talia1[pole]<2){
                        break;

                    }
                    if (talia2[pole]<2){
                        break;
                    }

                    std::this_thread::sleep_for(std::chrono::milliseconds(step));
                }while (1);


                // printf("\n\n----------Talia 1----------\n\n");
                // for (int n=0;n<54;n++) {
                //     printf("%d: %d - %s %s\n",n,talia1[n],nazwa11[n],nazwa21[n]);
                // }
                // printf("\n\n----------Talia 2----------\n\n");
                // for (int n=0;n<54;n++) {
                //     printf("%d:%d - %s %s\n",n,talia2[n],nazwa12[n],nazwa22[n]);
                // }
                if (p1_count>p2_count) {printf("Player 1 wins the game!\n");}
                if (p1_count<p2_count) {printf("Player 2 wins the game!\n");}
                if (x>53) {printf("Draw!\n");}
                break;


        }
    }while(task!=4);
    return 0;
}