//Copyright Lebada Daria-Cristiana 313CAa 2021-2022
#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

int main(void)
{
	//declarari variabile
	char comanda;
	scanf("%c", &comanda);

	int numar = 0;
	int **dimensiuni = NULL, ***vector_matrice = NULL;

	while (comanda != 'Q') {
		if (comanda >= 'A' && comanda <= 'Z') {
			if (comanda == 'L') {
				//Incarcarea in memorie a unei matrice
				adaugare_matrice(&numar, &dimensiuni, &vector_matrice);
			} else if (comanda == 'D') {
				//Determinarea dimensiunilor de matrice
				afisare_indici(numar, dimensiuni);
			} else if (comanda == 'P') {
				//Afisarea unei matrice
				afisare_matrice(numar, dimensiuni, vector_matrice);
			} else if (comanda == 'C') {
				//Redimensionarea unei matrice
				redimensionare_matrice(numar, &dimensiuni, &vector_matrice);
			} else if (comanda == 'M') {
				//Inmultirea a doua matrice
				inmultire_matrice(&numar, &dimensiuni, &vector_matrice);
			} else if (comanda == 'O') {
				//Sortarea matricelor
				sortare_matrice(numar, &dimensiuni, &vector_matrice);
			} else if (comanda == 'T') {
				//Transpunerea unei matrice
				transpunere_matrice(numar, &dimensiuni, &vector_matrice);
			} else if (comanda == 'F') {
				//Eliberarea memoriei unei matrice
				eliberare_matrice(&numar, &dimensiuni, &vector_matrice);
			} else {
				//Alte situatii
				printf("Unrecognized command\n");
			}
		}
		scanf("%c", &comanda);
	}
	//Eliberarea tuturor resurselor
	eliberare_memorie(numar, dimensiuni, vector_matrice);
	return 0;
}
