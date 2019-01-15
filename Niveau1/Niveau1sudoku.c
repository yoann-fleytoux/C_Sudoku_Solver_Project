#include <stdio.h>
#include <stdbool.h>

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

void saisie (T_sudoku p)
{
  
	int val,cas;
	val=0;
	for (cas=0;cas<82;cas++)
	{
		printf("Veuillez entrez une valeur(dans l'ordre du tableau)");
		scanf("%d",&val);
		p.grille[cas].val=val;
	}
}

void affichecand(T_case d, int cas)
{
	printf("%d",d.candidats[cas]);
}

void afficheligne (T_sudoku p, int cas)
{
	int i,j;
	for (i=0;i<10;i++)
	{
		for (j=0;j<3;j++)
		{
			printf("|");
			affichecand(p.grille[cas+i], j);
		}
	}
	printf("|\n");
	for (i=0;i<10;i++)
	{
		for (j=3;j<6;j++)
		{
			printf("|");
			affichecand(p.grille[cas+i], j);
		}
	}
	printf("|\n");
	for (i=0;i<10;i++)
	{
		for (j=6;j<9;j++)
		{
			printf("|");
			affichecand(p.grille[cas+i], j);
		}
	}
	printf("|\n");
}

void affiche (T_sudoku p)
{
	int i;
	for (i=0;i<10;i++)
	{
		afficheligne(p, i*9);
		if (i==2)
		{
			printf("-----------------------------------------------------------------\n");
		}
	}
}

void R1 (T_sudoku p, int o)
{
	int i;
	if (p.grille[o].n_candidats==1)
	{
		for (i=0;i<10;i++)
		{
			if (p.grille[o].candidats[i]!=' ')
			{
				p.grille[o].val=p.grille[o].candidats[i];
			}
		}
	}
}

void castrans (int d,int col, int lig)
{
	col=d%9;
	lig=(d-col)/9;
}

int R2hori (T_sudoku p, int d)
{
	int can[9] = {1,2,3,4,5,6,7,8,9};
	int cas,i,col,lig;
	castrans(d,col,lig);
	for (i=0;i<10;i++)
	{
		cas=9*lig+i;
		if (cas!=d)
		{
			if (p.grille[cas].val!=0)  
			{	
				can[(p.grille[cas].val)-1]=' ';    
			}
		}  
	} 	
	return(can[9]);
}

int R2verti (T_sudoku p, int d)
{
	int can2[9]={1,2,3,4,5,6,7,8,9};
	int cas,i,col,lig;
	castrans(d,col,lig);
	for (i=0;i<10;i++)
	{
		cas=i*9+col;
		if (cas!=d)
		{
			if (p.grille[cas].val!=0)
			{
				can2[(p.grille[cas].val)-1]=' ';
			}
    
		}
  
	}
	return(can2[9]);
}

int lboite (int a)
{
  
	if (a<3)
	{
    
		a=1;
  
	}
	else if (a<6)
	{
    
		a=4;
  
	}
	else
	{

    		a=7;
  
	}
	return(a);

}

int cboite (int a)
{
  
	if (a%3==1)
	{
    
		a=1;
  
	}
	else if (a%3==2)
	{
    
		a=4;
  
	}
	else
	{
    
		a=7;
  
	}
	return(a);

}

int R2boite (T_sudoku p, int d)
{
  
	int can3[9]={1,2,3,4,5,6,7,8,9};
	int cas,col,lig,i,j;
	castrans(d,col,lig);
	lig=lboite(lig);
	col=cboite(col);
	for (i=0;i<4;i++)
	{
		for (j=0;j<4;j++)
		{
      
			cas=(lig+j)*9+(col+i);
      
			if (cas!=d)
			{
	
				if (p.grille[cas].val!=0)
				{
	  
					can3[(p.grille[cas].val)-1]=' ';
	
				}
      
			}
    
		}
  
	}

	return(can3[9]);
}

int R2 (T_sudoku p, int d)
{
	int i;
	int can[9], can2[9], can3[9]; 
	can[9]=R2verti(p,d);
	can2[9]=R2hori(p,d);
	can3[9]=R2boite(p,d);
	for (i=0;i<10;i++)
	{
    
		if (can[i]==can2[i] && can2[i]==can3[i])
		{
      
			p.grille[d].candidats[i]=can[i];
    
		}
		else
		{
      
			p.grille[d].candidats[i]=' ';
    
		}
  
	}
  
	return(p.grille[d].candidats[9]);

}

int valacas (T_sudoku p, int i, int cas)
{
	if (p.grille[cas].val==i)
	{
		return (cas);
	}
	return (81);
}

int cherch (T_sudoku p, int i, int loca)
{
	int j,n;
	for (j=1;j<loca+1;j++)
	{
		n=valacas(p,i,j);
		if (n!=81)
		{
			return(n);
		}
	}
return(81);
}

void gestioncandidats (T_sudoku p, int i)
{
	int n;
	if (p.grille[i].val==0)
	{
		if (p.grille[i].n_candidats==1)
		{
			if ( p.grille[i].candidats[5]==' ')
			{
				n=cherch(p,p.grille[i].val,p.grille[i].candidats[9]);
				p.grille[i].candidats[5]=p.grille[i].candidats[n];
				p.grille[i].candidats[n]=' ';
			}
		}
	}
}	

void initialise (T_sudoku p)
{
  
	int i,j;
  
	for (i=0;i<81;i++)
	{
      
		p.grille[i].val=0;
      
		p.grille[i].n_candidats=0;
      
		for (j=1;j<10;j++)
		{
	
			p.grille[j].candidats[j-1]=' ';
      
		}
  
	}

}

int supp(int cand, T_case a)
{
	
	int i;
	for (i=0;i<10;i++)
	{
		if (a.candidats[i]==cand)
		{
			a.candidats[i]=' ';
		}
	}
	return(a.candidats[9]);
}

bool  verif (T_sudoku p)
{
	int i;
	for (i=0;i<82;i++)
	{
		if (p.grille[i].val==0)
		{
			return (false);
		}
	}
	return (true);
}