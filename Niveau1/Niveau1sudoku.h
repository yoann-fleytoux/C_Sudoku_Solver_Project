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

void saisie (T_sudoku p);

void affichecand(T_case d, int cas);

void afficheligne (T_sudoku p, int cas);

void affiche (T_sudoku p);

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

void gestioncandidats (T_sudoku p, int i);

void initialise (T_sudoku p);

int valacas (T_sudoku p, int i, int cas);

int cherch (T_sudoku p, int i, int loca);

int supp(int cand,T_case a);

bool  verif (T_sudoku p);