#include <stdio.h>

typedef struct
{

  	int val;

  	int n_candidats;
 
	int candidats[9];

}T_case;



typedef struct
{	
  
	T_case grille[81];

}T_sudoku;

void saisie2 (T_sudoku p);

void affichecand2 (T_sudoku p);

void afficheligne2 (T_sudoku p, int cas);

void affiche2 (T_sudoku p);

void R1 (T_sudoku p, int o);

void castrans (int d,int col, int lig);

int R2hori (T_sudoku p, int d);

int R2verti (T_sudoku p, int d);

int lboite (int a);

int cboite (int a);

int R2boite (T_sudoku p, int d);

int R2 (T_sudoku p, int d);

int valacas (T_sudoku p, int i, int cas);

int cherch (T_sudoku p, int i, int loca);

void gestioncandidats (T_sudoku p);

void initialise (T_sudoku p);

int supp(int cand, T_case a);

bool verif (T_sudoku p);

int dif (int can[9], int can2[9]);

int nbval (int j[9]);

void R3 (T_sudoku p, int group, int pos);

int add (int can[9], int can2[9]);

int dif1 (int can[9], int can2[9]);

int ligtrans (int col, int lig);

int candligb (int lig, int col, T_sudoku p);

int cand_lig (T_sudoku p, int boit);

int cancolb (int lig, int col, T_sudoku p);

int cand_col (T_sudoku p, int boit);

int ordre (int j[9]);

int R4col (T_sudoku p, int pos);

int R4lig (T_sudoku p, int pos);

void R4 (T_sudoku p, int pos);
