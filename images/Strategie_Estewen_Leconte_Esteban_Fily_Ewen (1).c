#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIGNE 6
#define COLONNE 7

typedef int t_grille[LIGNE][COLONNE];

int main(int argc, char** argv);
void chargerGrille(char** argv, t_grille grille);
int chercherLigne(t_grille grille, int col);
bool estVainqueur(t_grille grille, int lig, int col);
bool estVainqueurB(t_grille grille, int lig, int col);
bool estVainqueurB4(t_grille grille, int lig, int col);
bool estVainqueurG(t_grille grille, int lig, int col);
bool estVainqueurGG(t_grille grille, int lig, int col);
int choisirColonneStrategie3(t_grille grille);

const int VIDE = 0;
const int JOUEUR = 1;
const int ADVERSAIRE = 2;

/*
* VOTRE STRATEGIE
*/
int maStrategie(t_grille grille)
{
    int  pion_adverse,pion;
    int l,c,i;
    bool bq3=false;
    bool bq4=false;
    bool gg=false;
    bool ggez=false;
    pion =JOUEUR;
    pion_adverse = ADVERSAIRE;
    for (i=0;i<=6;i++) {   //parcours la t_grille
        c = i;
        l = chercherLigne(grille, c);
            if(l!=-1){

                grille[l][c] = pion_adverse;
                bq3=estVainqueurB(grille,l,c); //savoir si il faut bloquer l'adversaire
                grille[l][c] = VIDE;

                grille[l][c] = pion_adverse;
                bq4=estVainqueurB4(grille,l,c); //savoir si il faut bloquer l'adversaire où il y a 3 pions adversee alignés contre les peussance 4
                grille[l][c] = VIDE;

                grille[l][c] = pion;
                gg=estVainqueurG(grille,l,c); //savoir ou il y a 2 pions alliés alignés
                grille[l][c] = VIDE;
                
                grille[l][c] = pion;
                ggez=estVainqueurGG(grille,l,c); //savoir là où l'on peut gagner
                grille[l][c] = VIDE;

                if (ggez != false){
                    return c;       //mettre en priorité le pion là où l'on peut gagner
                }
                else if (bq4 != false){
                    return c;       //mettre le pion où 3 pions adversee alignés
                }
                else if (bq3 != false){
                    return c;       //mettre le pion là où il y a 2 pions alliés alignés
                }
                else if (gg != false){
                    return c;   //mettre le pion où 2 pions adversee alignés
                }
                else{
                    c = choisirColonneStrategie3(grille);   //sinon mettre  le pion le plus au milieu possible
                }
            }
    }
    return c;
}

int choisirColonneStrategie3(t_grille grille){
    int col=3;
    if(chercherLigne(grille,col)==-1){
        col=2;
        if(chercherLigne(grille,col)==-1){
            col=4;
            if(chercherLigne(grille,col)==-1){
                col=1;
                if(chercherLigne(grille,col)==-1){
                    col=5;
                    if(chercherLigne(grille,col)==-1){
                        col=0;
                        if(chercherLigne(grille,col)==-1){
                            col=6;
                        }
                    }
                }
            }
        }
    }
    return col;
}

int chercherLigne(t_grille grille, int col){
    int ligne = -1;

    while (ligne<LIGNE-1 && grille[ligne+1][col]==VIDE){
        ligne++;
    }
    return ligne;
}

// La fonction principale reçoit la grille du tour et retourne le coup choisi
// Vous n'avez pas à modifier cette fonction
int main(int argc, char** argv) 
{
    t_grille grille;

    chargerGrille(argv, grille);

    return maStrategie(grille);
}

// Charge la grille du tour actuel
// Vous n'avez pas à modifier cette fonction
void chargerGrille(char** argv, t_grille grille) 
{
    for(int i = 0; i < LIGNE; i++)
        for(int j = 0; j < COLONNE; j++)
            grille[i][j] = atoi(argv[i * COLONNE + j + 1]);
}


bool estVainqueur(t_grille grille, int lig, int col){
    // consiste Ã  regarder si une ligne de 4 pions s'est formÃ©e autour du pion qui vient de tomber en (lig, col)
    char lePion = grille[lig][col];
    int cpt,i,j;

    // regarder la verticale, en comptant le nombre de pions au Sud (inutile de regarder au Nord du pion qui vient de tomber)
    i = lig;
    cpt = 0;
    while (i<LIGNE && grille[i][col]==lePion){
        cpt++;
        i++;
    }
    if (cpt>=4){
        return true;
    }
    // regarder l'horizontale, en comptant le nombre de pions Ã  l'Est et Ã  l'Ouest
    j = col;
    cpt = 0;
    // on regarde Ã  l'est
    while (j>=0 && grille[lig][j]==lePion){
        cpt++;
        j--;
    }
    j = col+1;
    // on regarde Ã  l'ouest
    while (j<COLONNE && grille[lig][j]==lePion){
        cpt++;
        j++;
    }
    if (cpt>=4 ){
        return true;
    }
    // regarder la diagonale descendante, en comptant le nombre de pions au Nord Ouest et au Sud Est
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Ouest
    while (j>=0 && i>=0 && grille[i][j]==lePion){
        cpt++;
        i--;
        j--;
    }
    i = lig+1;
    j = col+1;
    // on regarde au Sud Est
    while (i<LIGNE && j<COLONNE && grille[i][j]==lePion){
        cpt++;
        i++;
        j++;
    }
    if (cpt>=4 ){
        return true;
    }
    // regarder la diagonale descendante, en comptant le nombre de pions au Nord Est et au Sud Ouest
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Est
    while (j<COLONNE && i>=0 && grille[i][j]==lePion){
        cpt++;
        i--;
        j++;
    }
    i = lig+1;
    j = col-1;
    // on regarde au Sud Ouest
    while (i<LIGNE && j>=0 && grille[i][j]==lePion){
        cpt++;
        i++;
        j--;
    }
    if (cpt>=4 ){
        return true;
    }
    return false;
}

//contre les puissance 3 adverse
bool estVainqueurB(t_grille grille, int lig, int col){
    char lePion = grille[lig][col];
    int cpt,i,j;

    // regarder la verticale
    i = lig;
    cpt = 0;
    while (i<LIGNE && grille[i][col]==lePion){
        cpt++;
        i++;
    }
    if (cpt>=3){
        return true;
    }
     // regarder l'horizontale
    j = col;
    cpt = 0;
    // on regarde Ã  l'est
    while (j>=0 && grille[lig][j]==lePion){
        cpt++;
        j--;
    }
    j = col+1;
    // on regarde Ã  l'ouest
    while (j<COLONNE && grille[lig][j]==lePion){
        cpt++;
        j++;
    }
    if (cpt>=3 ){ //pour ne pas ce faire avoir par "une fourchette" = un puissance 4 sur la première ligne
        return true;
    }
    // regarder la diagonale descendante
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Ouest
    while (j>=0 && i>=0 && grille[i][j]==lePion){
        cpt++;
        i--;
        j--;
    }
    i = lig+1;
    j = col+1;
    // on regarde au Sud Est
    while (i<LIGNE && j<COLONNE && grille[i][j]==lePion){
        cpt++;
        i++;
        j++;
    }
    if (cpt>=3 ){
        return true;
    }
    // regarder la diagonale descendante
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Est
    while (j<COLONNE && i>=0 && grille[i][j]==lePion){
        cpt++;
        i--;
        j++;
    }
    i = lig+1;
    j = col-1;
    // on regarde au Sud Ouest
    while (i<LIGNE && j>=0 && grille[i][j]==lePion){
        cpt++;
        i++;
        j--;
    }
    if (cpt>=3 ){
        return true;
    }
    return false;
}

//contre les puissance 4 adverse
bool estVainqueurB4(t_grille grille, int lig, int col){
    char lePion = grille[lig][col];
    int cpt,i,j;

    // regarder la verticale
    i = lig;
    cpt = 0;
    while (i<LIGNE && grille[i][col]==lePion){
        cpt++;
        i++;
    }
    if (cpt>=4){
        return true;
    }
     // regarder l'horizontale
    j = col;
    cpt = 0;
    // on regarde Ã  l'est
    while (j>=0 && grille[lig][j]==lePion){
        cpt++;
        j--;
    }
    j = col+1;
    // on regarde Ã  l'ouest
    while (j<COLONNE && grille[lig][j]==lePion){
        cpt++;
        j++;
    }
    if (cpt>=4 ){ //pour ne pas ce faire avoir par "une fourchette" = un puissance 4 sur la première ligne
        return true;
    }
    // regarder la diagonale descendante
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Ouest
    while (j>=0 && i>=0 && grille[i][j]==lePion){
        cpt++;
        i--;
        j--;
    }
    i = lig+1;
    j = col+1;
    // on regarde au Sud Est
    while (i<LIGNE && j<COLONNE && grille[i][j]==lePion){
        cpt++;
        i++;
        j++;
    }
    if (cpt>=4 ){
        return true;
    }
    // regarder la diagonale descendante
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Est
    while (j<COLONNE && i>=0 && grille[i][j]==lePion){
        cpt++;
        i--;
        j++;
    }
    i = lig+1;
    j = col-1;
    // on regarde au Sud Ouest
    while (i<LIGNE && j>=0 && grille[i][j]==lePion){
        cpt++;
        i++;
        j--;
    }
    if (cpt>=4 ){
        return true;
    }
    return false;
}

//place un poin quand 2 pions alliés sont alignés
bool estVainqueurG(t_grille grille, int lig, int col){
    char lePion = grille[lig][col];
    int cpt,i,j;

    // regarder la verticale
    i = lig;
    cpt = 0;
    while (i<LIGNE && grille[i][col]==lePion){
        cpt++;
        i++;
    }
    if (cpt>=3){
        return true;
    }
    // regarder l'horizontale
    j = col;
    cpt = 0;
    // on regarde Ã  l'est
    while (j>=0 && grille[lig][j]==lePion){
        cpt++;
        j--;
    }
    j = col+1;
    // on regarde Ã  l'ouest
    while (j<COLONNE && grille[lig][j]==lePion){
        cpt++;
        j++;
    }
    if (cpt>=3){
        return true;
    }
    // regarder la diagonale descendante
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Ouest
    while (j>=0 && i>=0 && grille[i][j]==lePion){
        cpt++;
        i--;
        j--;
    }
    i = lig+1;
    j = col+1;
    // on regarde au Sud Est
    while (i<LIGNE && j<COLONNE && grille[i][j]==lePion){
        cpt++;
        i++;
        j++;
    }
    if (cpt>=3){
        return true;
    }
    // regarder la diagonale descendante
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Est
    while (j<COLONNE && i>=0 && grille[i][j]==lePion){
        cpt++;
        i--;
        j++;
    }
    i = lig+1;
    j = col-1;
    // on regarde au Sud Ouest
    while (i<LIGNE && j>=0 && grille[i][j]==lePion){
        cpt++;
        i++;
        j--;
    }
    if (cpt>=3){
        return true;
    }
    return false;
}


//place un poin la ou il y a déjà 3 poins alliés alignés pour gagner 
bool estVainqueurGG(t_grille grille, int lig, int col){

    char lePion = grille[lig][col];
    int cpt,i,j;

    // regarder la verticale
    i = lig;
    cpt = 0;
    while (i<LIGNE && grille[i][col]==lePion){
        cpt++;
        i++;
    }
    if (cpt>=4){
        return true;
    }
    // regarder l'horizontale
    j = col;
    cpt = 0;
    // on regarde Ã  l'est
    while (j>=0 && grille[lig][j]==lePion){
        cpt++;
        j--;
    }
    j = col+1;
    // on regarde Ã  l'ouest
    while (j<COLONNE && grille[lig][j]==lePion){
        cpt++;
        j++;
    }
    if (cpt>=4){
        return true;
    }
    // regarder la diagonale descendante
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Ouest
    while (j>=0 && i>=0 && grille[i][j]==lePion){
        cpt++;
        i--;
        j--;
    }
    i = lig+1;
    j = col+1;
    // on regarde au Sud Est
    while (i<LIGNE && j<COLONNE && grille[i][j]==lePion){
        cpt++;
        i++;
        j++;
    }
    if (cpt>=4){
        return true;
    }
    // regarder la diagonale descendante
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Est
    while (j<COLONNE && i>=0 && grille[i][j]==lePion){
        cpt++;
        i--;
        j++;
    }
    i = lig+1;
    j = col-1;
    // on regarde au Sud Ouest
    while (i<LIGNE && j>=0 && grille[i][j]==lePion){
        cpt++;
        i++;
        j--;
    }
    if (cpt>=4){
        return true;
    }
    return false;
}