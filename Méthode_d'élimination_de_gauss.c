#include<stdio.h>
#include<math.h>

/*
Fonction qui fait la substitution arrière de la matrice
Paramètres: lignes (m), a[m][m+1],second membre x[m]
*/
void Remontee(int m, double a[m][m+1], double x[m]){
    //Commencer la substitution arrière
	int i;
	int j;
    for(i=m-1;i>=0;i--){
        x[i]=a[i][m];
        for(j=i+1;j<m;j++){
            x[i]=x[i]-a[i][j]*x[j];
        }
        x[i]=x[i]/a[i][i];
    }
}

void GaussElimin(int m, double a[m][m+1], double x[m]){
    int i,j,k;
    for(i=0;i<m-1;i++){
        //Pivotement partiel
        for(k=i+1;k<m;k++){
            //Si la valeur absolue de l'élément diagonal est inférieur à l'un des termes au dessous
            if(fabs(a[i][i])<fabs(a[k][i])){
                //échanger les lignes
                for(j=0;j<=m;j++){
                    double t;
                    t=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=t;
                }
            }
        }
        //Commencer l'élimination de Gauss
        for(k=i+1;k<m;k++){
            double  terme=a[k][i]/ a[i][i];
            for(j=0;j<=m;j++){
                a[k][j]=a[k][j]-terme*a[i][j];
            }
        }    
    }
	Remontee(m,a,x); 
}

/*
Fonction qui lit les éléments de la matrice
Paramètres: lignes (m), colonnes (m+1), matrice[m][m+1]
*/
void lireMatrice(int m, double matrice[m][m+1]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<=m;j++){
            scanf("%lf",&matrice[i][j]);
        }
    } 
}
/*
Fonction qui afficher les éléments de la matrice
Paramètres: lignes (m), colonnes ([m+1), matrice[m][m+1]
*/
void printMatrix(int m, double matrice[m][m+1]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<=m;j++){
            printf("%lf\t",matrice[i][j]);
        }
        printf("\n");
    } 
}
/*
Fonction qui copie les éléments d'une matrice vers une autre matrice
Paramètres: lignes (m), colonnes (m+1), matrice1[m][m+1], matrice2[m][m+1]
*/
void copieMatrice(int m, double matrice1[m][m+1], double matrice2[m][m+1]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<=m;j++){
            matrice2[i][j]=matrice1[i][j];
        }
    } 
}
 
int main(){
    int m,i,j;
    printf("Entrez la dimension de la matrice :\n");
    scanf("%d",&m);
	
	if(m>0){
    //Déclarer une matrice pour stocker la matrice donnée par l'utilisateur
	double a[m][m];
	//Déclarer une autre matrice pour stocker la matrice résultante obtenue après élimination de Gauss
	double U[m][m];
	//Déclarer un tableau pour stocker la solution des équations
    double x[m];
    printf("\nEntrez les elements de la matrice :\n");
	lireMatrice(m,a);
	copieMatrice(m,a,U);
	//Effectuer l'élimination de Gauss
	GaussElimin(m,U,x);
	printf("\nLa matrice triangulaire superieure apres elimination de Gauss est :\n");
	printf("(La derniere colonne est le second membre) \n\n");
	printMatrix(m,U);
	printf("\nLa solution des equations lineaires est :\n\n");
		for(i=0;i<m;i++){
		printf("x[%d]=\t%lf\n",i+1,x[i]);
		}	
}else {
	printf("Le choix de la dimension de la matrice est incorrect !!\n");
}
}