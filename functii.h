//Copyright Lebada Daria-Cristiana 313CAa 2021-2022
#ifndef _FUNCTII_H_
#define _FUNCTII_H_
#define INC 2
#define MOD 10007

//functie de alocare a unei matrice
int **alocare_matrice(int nr_linii, int nr_coloane)
{
	//alocarea vectorului de pointeri
	int **matrice = (int **)malloc(nr_linii * sizeof(int *));
	if (!matrice) {
		fprintf(stderr, "Eroare alocare malloc()\n");
		return NULL;
	}
	//alocarea fiecarei linii
	for (int i = 0; i < nr_linii; i++) {
		matrice[i] = malloc(nr_coloane * sizeof(int));

		if (!matrice[i]) {
			fprintf(stderr, "Eroare alocare malloc()\n");
			//eliberarea memoriei liniilor anterior alocate
			for (int j = 0; j < i; j++)
				free(matrice[j]);

			free(matrice);
			return NULL;
		}
	}
	return matrice;
}

//functie pentru citirea valorilor unei matrice de la tastatura
void citire_matrice(int nr_linii, int nr_coloane, int ***matrice)
{
	*matrice = alocare_matrice(nr_linii, nr_coloane);

	for (int i = 0; i < nr_linii; i++)
		for (int j = 0; j < nr_coloane; j++)
			scanf("%d", &(*matrice)[i][j]);
}

//functie pentru incarcarea in memorie a unei matrice
void adaugare_matrice(int *numar, int ***dimensiuni, int ****vector_matrice)
{
	//se citeste numarul de linii, respectiv de coloane
	int nr_linii, nr_coloane;
	scanf("%d%d", &nr_linii, &nr_coloane);

	//se verifica daca mai exista matrice stocate in memorie
	if (!(*vector_matrice)) {
		//se aloca vectorul de dimensiuni si cel de matrice
		*dimensiuni = (int **)malloc(sizeof(int *));
		*vector_matrice = (int ***)malloc(sizeof(int **));

	} else {
		//se realoca vectorul de dimensiuni si cel de matrice
		//pentru a se putea stoca o noua matrice in memorie
		*dimensiuni = (int **)realloc(*dimensiuni,
					(*numar + 1) * sizeof(int *));
		*vector_matrice = (int ***)realloc(*vector_matrice,
					(*numar + 1) * sizeof(int **));
	}
	//se retin noile dimensiuni
	(*dimensiuni)[*numar] = (int *)malloc(INC * sizeof(int));
	(*dimensiuni)[*numar][0] = nr_linii;
	(*dimensiuni)[*numar][1] = nr_coloane;
	//se citeste noua matrice
	citire_matrice(nr_linii, nr_coloane, &(*vector_matrice)[*numar]);
	(*numar)++;
}

//functie pentru afisarea indicilor matricei cautate
void afisare_indici(int numar, int **dimensiuni)
{
	int indice;
	scanf("%d", &indice);

	//se verifica daca exista o matrice cu indicele cautat
	if (indice < numar && indice >= 0)
		printf("%d %d\n", dimensiuni[indice][0], dimensiuni[indice][1]);
	else
		printf("No matrix with the given index\n");
}

//functie pentru afisarea unei matrice
void afisare_matrice(int numar, int **dimensiuni, int ***vector_matrice)
{
	int indice;
	scanf("%d", &indice);

	if (indice < numar && indice >= 0) {
		for (int i = 0; i < dimensiuni[indice][0]; i++) {
			for (int j = 0; j < dimensiuni[indice][1]; j++)
				printf("%d ", vector_matrice[indice][i][j]);
			printf("\n");
		}

	} else {
		printf("No matrix with the given index\n");
	}
}

//functie pentru alocarea si citirea unui vector
int *citire_vector(int n)
{
	//alocarea vectorul
	int *v = malloc(n * sizeof(int));
	if (!v) {
		fprintf(stderr, "Eroare alocare malloc()\n");
		free(v);
		return NULL;
	}
	//citirea valorilor din vector
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	return v;
}

//functie pentru eliberarea memoriei unei matrice
void eliberare(int n, int **matrice)
{
	for (int i = 0; i < n; i++)
		free(matrice[i]);

	free(matrice);
}

//functie pentru modificarea valorilor unei matrice redimensionate
void redimensionare(int l, int c, int *linii, int *coloane,
					int ***matrice, int **mat)
{
	for (int i = 0; i < l; i++)
		for (int j = 0; j < c; j++)
			(*matrice)[i][j] = mat[linii[i]][coloane[j]];
}

//functie pentru modificarea matricei dorite in memorie
void redimensionare_matrice(int numar, int ***dimensiuni,
							int ****vector_matrice)
{
	int l, c, indice, *linii, *coloane, **matrice;
	scanf("%d", &indice);

	//se citesc noile dimensiuni ale matricei
	scanf("%d", &l);
	linii = citire_vector(l);

	scanf("%d", &c);
	coloane = citire_vector(c);

	if (indice < numar && indice >= 0) {
		matrice = alocare_matrice(l, c);

		redimensionare(l, c, linii, coloane,
					   &matrice, (*vector_matrice)[indice]);
		//se elibereaza memoria matricei inainte de redimensionare
		eliberare((*dimensiuni)[indice][0], (*vector_matrice)[indice]);
		//se stocheaza in memorie noile dimensiuni
		(*dimensiuni)[indice][0] = l;
		(*dimensiuni)[indice][1] = c;
		//se copiaza matricea redimensionata in vectorul de matrice
		(*vector_matrice)[indice] = matrice;

		} else {
			printf("No matrix with the given index\n");
		}
	//se elibereaza memoria alocata in vectori
	free(linii);
	free(coloane);
}

//functie pentru inmultirea a doua matrice
void inmultire_matrice(int *numar, int ***dimensiuni, int ****vector_matrice)
{
	int indice1, indice2;
	scanf("%d%d", &indice1, &indice2);

	if (indice1 >= (*numar) || indice2 >= (*numar) ||
		indice1 < 0 || indice2 < 0) {
		printf("No matrix with the given index\n");

	} else if ((*dimensiuni)[indice1][1] != (*dimensiuni)[indice2][0]) {
		//doua matrice se pot inmulti doar daca numarul de coloane ale
		//matricei 1 este egal cu numarul de linii ale matricei 2
		printf("Cannot perform matrix multiplication\n");

	} else {
		//se realizeaza inmultirea
		int nr_linii = (*dimensiuni)[indice1][0];
		int nr_coloane = (*dimensiuni)[indice2][1];
		int p = (*dimensiuni)[indice1][1];
		int sum = 0;

		//se aloca noile dimensiuni
		(*dimensiuni) = (int **)realloc((*dimensiuni),
						(*numar + 1) * sizeof(int *));

		(*dimensiuni)[*numar] = (int *)malloc(INC * sizeof(int));
		(*dimensiuni)[*numar][0] = nr_linii;
		(*dimensiuni)[*numar][1] = nr_coloane;

		(*vector_matrice) = (int ***)realloc((*vector_matrice),
							(*numar + 1) * sizeof(int **));

		(*vector_matrice)[*numar] = alocare_matrice(nr_linii, nr_coloane);

		//se calculeaza produsul
		for (int i = 0; i < nr_linii; i++) {
			for (int j = 0; j < nr_coloane; j++) {
				sum = 0;
				for (int k = 0; k < p; k++) {
					//se aduna de fiecare data MOD * MOD pentru a rezola
					//cazurile in care sumele sunt negative
					sum = (sum + ((*vector_matrice)[indice1][i][k] *
						(*vector_matrice)[indice2][k][j]) + MOD * MOD)
						% MOD;
				}
				(*vector_matrice)[*numar][i][j] = sum;
			}
		}
		(*numar)++;
	}
}

//functie pentru sortarea matricelor dupa suma
void sortare_matrice(int numar, int ***dimensiuni, int ****vector_matrice)
{
	int suma = 0, *vector_sume;
	//se defineste si aloca un vector de sume
	vector_sume = malloc(numar * sizeof(int));

	//se calculeaza suma elementelor fiecarei matrice
	//si se stocheaza valoarea in vectorul de sume
	for (int k = 0; k < numar; k++) {
		suma = 0;
		for (int i = 0; i < (*dimensiuni)[k][0]; i++)
			for (int j = 0; j < (*dimensiuni)[k][1]; j++)
				suma = (suma + (*vector_matrice)[k][i][j] + MOD) % MOD;

		vector_sume[k] = suma;
	}

	//se ordoneaza matricele in memorie
	for (int i = 0; i < numar - 1; i++) {
		for (int j = i + 1; j < numar; j++) {
			if (vector_sume[i] > vector_sume[j]) {
				//s-au gasit valori nesortate

				//se interschimba valorile din vectorul de sume
				int aux = vector_sume[i];
				vector_sume[i] = vector_sume[j];
				vector_sume[j] = aux;

				//se interschimba matricele cu sumele respective
				int **tmp = (*vector_matrice)[i];
				(*vector_matrice)[i] = (*vector_matrice)[j];
				(*vector_matrice)[j] = tmp;

				//se interschimba dimensiunile matricelor
				//linii
				aux = (*dimensiuni)[i][0];
				(*dimensiuni)[i][0] = (*dimensiuni)[j][0];
				(*dimensiuni)[j][0] = aux;
				//coloane
				aux = (*dimensiuni)[i][1];
				(*dimensiuni)[i][1] = (*dimensiuni)[j][1];
				(*dimensiuni)[j][1] = aux;
			}
		}
	}
	free(vector_sume);
}

//functie pentru calculul transpusei matricei
void transpusa(int nr_linii, int nr_coloane, int ***matrice,
			   int **vector_matrice)
{
	for (int i = 0; i < nr_linii; i++)
		for (int j = 0; j < nr_coloane; j++)
			(*matrice)[i][j] = vector_matrice[j][i];
}

//functie pentru stocarea transpusei in memorie
void transpunere_matrice(int numar, int ***dimensiuni,
						 int ****vector_matrice)
{
	int indice, nr_linii, nr_coloane;
	scanf("%d", &indice);

	if (indice < numar && indice >= 0) {
		nr_linii = (*dimensiuni)[indice][1];
		nr_coloane = (*dimensiuni)[indice][0];
		//se defineste o matrice auxiliara in care se
		//calculeaza transpusa
		int **matrice = alocare_matrice(nr_linii, nr_coloane);
		transpusa(nr_linii, nr_coloane, &matrice,
				  (*vector_matrice)[indice]);

		//se elibereaza memoria matricei inainte de transpunere
		eliberare((*dimensiuni)[indice][0], (*vector_matrice)[indice]);

		//se modifica dimensiunile
		(*dimensiuni)[indice][1] = nr_coloane;
		(*dimensiuni)[indice][0] = nr_linii;
		//se copiaza matricea auxiliara in vectorul de matrice
		(*vector_matrice)[indice] = matrice;

	} else {
		printf("No matrix with the given index\n");
	}
}

//functie pentru eliberarea memoriei unei matrice
void eliberare_matrice(int *numar, int ***dimensiuni, int ****vector_matrice)
{
	int indice;
	scanf("%d", &indice);

	if (indice < *numar && indice >= 0) {
		//se alibereaza memoria matricei cautate
		eliberare((*dimensiuni)[indice][0], (*vector_matrice)[indice]);

		//se muta cu o pozitie spre stanga fiecare matrice
		for (int i = indice + 1; i < *numar; i++) {
			(*vector_matrice)[i - 1] = (*vector_matrice)[i];
			(*dimensiuni)[i - 1][0] = (*dimensiuni)[i][0];
			(*dimensiuni)[i - 1][1] = (*dimensiuni)[i][1];
		}
		free((*dimensiuni)[(*numar) - 1]);

		(*numar)--;
	} else {
		printf("No matrix with the given index\n");
	}
}

//functe pentru eliberarea tuturor resurselor
void eliberare_memorie(int numar, int **dimensiuni, int ***vector_matrice)
{
	for (int i = 0; i < numar; i++) {
		for (int j = 0; j < dimensiuni[i][0]; j++)
			free(vector_matrice[i][j]);

		free(vector_matrice[i]);
		free(dimensiuni[i]);
	}
	free(vector_matrice);
	free(dimensiuni);
}

#endif
