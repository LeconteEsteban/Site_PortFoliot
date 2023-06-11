//Esteban Leconte Groupe:1D2
/**
 * \file Leconte_Esteban_P4.c
 * \brief  Ce programme est un puissance 4 écrit en language C
 * \author Leconte Esteban
 * \version 1.0
 * \date 17/11/2022
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define colonnes 7
/**
 * \def colonnes 7
 * Permet de définir les 7 colonnes du puissance 4.
*/
#define lignes 6
/**
 * \def lignes 6
 * Permet de  définir les 6 lignes du puissance 4.
*/
typedef char t_grille[lignes][colonnes];
/**
 * \typedef char t_grille[lignes][colonnes]
 * \brief permet de créer un tableau de type t_grille avec 6 lignes et 7 colonnes.
*/
const char ROUGE = 'O';
/**
 * \def char ROUGE
 * \brief pour créer le jeton "Rouge" = 'O' pour pouvoir changer le jeton.
*/
const char JAUNE = 'X';
/**
 * \def char JAUNE
 * \brief pour créer le jeton "Jaune" = 'X' pour pouvoir changer le jeton.
*/

void initgrille(t_grille grille)
{
	int lig;
	int col;
	for (lig = 0; lig < lignes; lig++)
	{
		for (col = 0; col < colonnes; col++)
		{
			grille[lig][col] = ' ';
		}
	}
}
/**
 * \def void initgrille
 * \brief permet d'initialiser une grille vide de 6 lignes et 7 colonnes pour permettre d'afficher les jetons dans la grille. 
 *        Qui a en entrée le type de la grille utilisé.
*/

void affgrille(t_grille grille){
    int col;
    int lig;
    printf("|---------------------------|\n");
    for(lig=0;lig<lignes;lig++)
    {
        for(col=0;col<colonnes;col++)
        {
           printf("| %c ",grille[lig][col]); 
        }
        printf("|\n");
        printf("|---|---|---|---|---|---|---|\n");
    }
printf("| 1   2   3   4   5   6   7 |\n");
}
/**
 * \def void affgrille
 * \brief permet d'afficher :
            |---------------------------|
            |   |	|   |	|   |	|   |
            |---|---|---|---|---|---|---|
            |   |	|   |	|   |	|   |
            |---|---|---|---|---|---|---|
            |   |	|   |	|   |	|   |
            |---|---|---|---|---|---|---|
            |   |	|   |	|   |	|   |
            |---|---|---|---|---|---|---|
            |   |	|   |	|   |	|   |
            |---|---|---|---|---|---|---|
            |   |	|   |	|   |	|   |
            |---|---|---|---|---|---|---|
            | 1   2   3   4   5   6   7 |
        et de pouvoir afficher cette grille avec les jeton a l'interieur.
        Qui a en entrée le type de la grille utilisé.
*/

void changejoueur(char *jeton,int *joueur){
    if(*jeton == ROUGE){
        *jeton = JAUNE;
        *joueur = 2;
    }
    else{
        *jeton = ROUGE;
        *joueur = 1;
    }
}
/**
 * \def void changejoueur
 * \brief permet de changer de joueur et donc de changer de jeton entre joueur 1 = 'O' et joueur 2 = 'X'.
 *        Qui a en entrée/sortie jeton qui est une chaine de caractère jeton = 'O' et jeton = 'X',
 *        et en entrée/sortie joueur qui est un entier joueur 1 ou joueur 2.
*/

void jetonou(int joueur, int *cases){
    printf("Où voulez-vous mettre votre jeton joueur %d ?\t", joueur);
    scanf("%d",&*cases);
    while((*cases <= 0) || (*cases > 7)){
        printf("Veillez resaisir une valeur joueur %d \t",joueur);
        scanf("%d",&*cases);
    printf("\n");
}
}
/**
 * \def void jetonou
 * \brief permet demander au joueur où mettre le jeton et vérifier si il est bien entre 1 et 7.
 *        Qui a en entrée/sortie joueur qui est un entier joueur 1 ou joueur 2,
 *        et en entrée/sortie cases qui est un entier c'est la colonnes choisie.
*/

bool rechergrille(t_grille grille,int *nbligne, int n){ 
    bool plein = false;
    while ((grille[*nbligne][n]!= ' ')&&(*nbligne>=0)){
            *nbligne=*nbligne-1;
    }
    if(*nbligne == -1){
        plein = true;
    }
    return plein;
}
/**
 * \def void rechergrille
 * \brief permet de savoir si la colonne demmandé est pleine ou non et de retourner plein = true si elle est pleine ou plein = false si il reste des cases vides.
 *        Qui a en entrée le type de la grille utilisé.
 *        en entrée/sortie nblignes qui est un entier joueur le nombre de lignes pas utilisé dans la colonnes n,
 *        en entrée n qui et la colonnes qui est choisie,
*/

void placerjeton(t_grille grille,int cases, char jeton,int joueur){
    int nbligne=5;
    bool plein;
    plein=rechergrille(grille,&nbligne,cases-1);
    switch(cases){
        case 1 :if(plein != true){
                    printf("%c \n",grille[nbligne][cases-1]= jeton);
                }
                while(plein == true){
                    printf("Mauvaise valeur\n");
                    jetonou(joueur,&cases);
                    if(cases != 1){
                        plein = false;
                        placerjeton(grille,cases,jeton,joueur);
                    }
                }
                break;
        case 2 :if(plein != true){
                    printf("%c \n",grille[nbligne][cases-1]= jeton);
                }
                while(plein == true){
                    printf("Mauvaise valeur\n");
                    jetonou(joueur,&cases);
                    if(cases != 2){
                        plein = false;
                        placerjeton(grille,cases,jeton,joueur);
                    }
                }
                break;
        case 3 :if(plein != true){
                    printf("%c \n",grille[nbligne][cases-1]= jeton);
                }
                while(plein == true){
                    printf("Mauvaise valeur\n");
                    jetonou(joueur,&cases);
                    if(cases != 3){
                        plein = false;
                        placerjeton(grille,cases,jeton,joueur);
                    }
                }
                break;
        case 4 :if(plein != true){
                    printf("%c \n",grille[nbligne][cases-1]= jeton);
                }
                while(plein == true){
                    printf("Mauvaise valeur\n");
                    jetonou(joueur,&cases);
                    if(cases != 4){
                        plein = false;
                        placerjeton(grille,cases,jeton,joueur);
                    }
                }
                break;
        case 5 :if(plein != true){
                    printf("%c \n",grille[nbligne][cases-1]= jeton);
                }
                while(plein == true){
                    printf("Mauvaise valeur\n");
                    jetonou(joueur,&cases);
                    if(cases != 5){
                        plein = false;
                        placerjeton(grille,cases,jeton,joueur);
                    }
                }
                break;
        case 6 :if(plein != true){
                    printf("%c \n",grille[nbligne][cases-1]= jeton);
                }
                while(plein == true){
                    printf("Mauvaise valeur\n");
                    jetonou(joueur,&cases);
                    if(cases != 6){
                        plein = false;
                        placerjeton(grille,cases,jeton,joueur);
                    }
                }
                break;
        case 7 :if(plein != true){
                    printf("%c \n",grille[nbligne][cases-1]= jeton);
                }
                while(plein == true){
                    printf("Mauvaise valeur\n");
                    jetonou(joueur,&cases);
                    if(cases != 7){
                        plein = false;
                        placerjeton(grille,cases,jeton,joueur);
                    }
                }
                break;
        default : while(plein == true){
                    printf("Mauvaise valeur\n");
                    jetonou(joueur,&cases);
                    if(cases != 7){
                        plein = false;
                        placerjeton(grille,cases,jeton,joueur);
                    }
                }
                break;
    }
}
/**
 * \def void placerjeton
 * \brief permet placer le jeton dans la colonne demmandée 1,2,3,4,5,6 et 7.
 *        Qui a en entrée le type de la grille utilisé,
 *        en entrée cases qui est un entier colonnes choisie entre 1 et 7.
 *        en entrée jeton qui est une chaine de caractère jeton = 'O' et jeton = 'X',
 *        et en entrée joueur qui est un entier joueur 1 ou joueur 2.
*/

bool gagner(t_grille grille,char jeton,int cases){
    int i;
    int horizontal;
    int vertical;
    int diagnonaleD;
    bool bravo = 0;
    cases=cases-1;
    //vertical = colonnes
        for(vertical=5;vertical>0;vertical--){
            if((grille[vertical][cases] == jeton)&&(grille[vertical-1][cases] == jeton)&&(grille[vertical-2][cases] == jeton)&&(grille[vertical-3][cases] == jeton)){
                bravo = 1; 
            }
        }
        
    //horizontal = lignes
        for(i=0;i<=6;i++){
            for(horizontal=0;horizontal<=3;horizontal++){
                if((grille[i][horizontal] == jeton)&&(grille[i][horizontal+1] == jeton)&&(grille[i][horizontal+2] == jeton)&&(grille[i][horizontal+3] == jeton)){
                   bravo = 1; 
                }
            }  
        }
    //diagonales diagnonale vers droite
        for(i=0;i<=6;i++){
            for(diagnonaleD=5;diagnonaleD>0;diagnonaleD--){
                if((grille[diagnonaleD][i] == jeton)&&(grille[diagnonaleD-1][i+1] == jeton)&&(grille[diagnonaleD-2][i+2] == jeton)&&(grille[diagnonaleD-3][i+3] == jeton)){
                   bravo = 1; 
                }
            }  
        }
    //diagonales diagnonale vers gauche    
        for(i=6;i>0;i--){
            for(diagnonaleD=5;diagnonaleD>0;diagnonaleD--){
                if((grille[diagnonaleD][i] == jeton)&&(grille[diagnonaleD-1][i-1] == jeton)&&(grille[diagnonaleD-2][i-2] == jeton)&&(grille[diagnonaleD-3][i-3] == jeton)){
                   bravo = 1; 
                }
            }  
        }
    return bravo;
}
/**
 * \def void gagner
 * \brief permet de savoir si il y a 4 ou plus jetons alignés soit en horizontal soit en vertical soit en diagonale vers la droite ou vers la gauche et arrete le jeu quand c'est vrai.
 *        Qui a en entrée le type de la grille utilisé,
 *        en entrée jeton qui est une chaine de caractère jeton = 'O' et jeton = 'X',
 *        et en entrée cases qui est un entier colonnes choisie entre 1 et 7.
*/

void jouer(t_grille grille,char *jeton,int *joueur){
    int cases;
    int bravo=0;
    int grillepleine=0;
    while((grillepleine< 42)&&(bravo == 0)){
    jetonou(*joueur,&cases);
    placerjeton(grille,cases,*jeton,*joueur);
    affgrille(grille);
    bravo=gagner(grille,*jeton,cases);
    changejoueur(&*jeton,&*joueur);
    grillepleine=grillepleine+1;
    printf("%d\n",grillepleine);
    }
}
/**
 * \def void jouer
 * \brief permet d'afficher la grille en placant les jetons à l'interrieur jusqu'à que les 4 ou plus jetons donc jusqu'à qu'un joueur est gagné.
 *         Qui a en entrée le type de la grille utilisé,
 *         en entrée/sortie jeton qui est une chaine de caractère jeton = 'O' et jeton = 'X',
 *         et en entrée/sortie joueur qui est un entier joueur 1 ou joueur 2.
*/

int main(){
    char jeton= ROUGE;
    int joueur= 1;
    t_grille grille;
    initgrille(grille);
    affgrille(grille);
    jouer(grille,&jeton,&joueur);
    changejoueur(&jeton,&joueur);
    printf("Bravo au joueur %d qui a gagné\nLa grille était :\n",joueur);
    affgrille(grille);
   
}
/**
 * \def int main
 * \brief permet de lancer le jeu en initialisant la grille, en l'affichant, puis de lancer la procédure jouer et d'écrire à la fin quel joueur a gagner et comment était la grille.
*/