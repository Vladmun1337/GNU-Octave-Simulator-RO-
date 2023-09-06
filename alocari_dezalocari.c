// Muntean Vlad-Andrei 315CA
#include <stdio.h>
#include <stdlib.h>
#include "Struct-matrice.h"
#define MOD 10007

void citire(int *d, matrice **v)
{
	int m, n;
	//bloc nou de elemente pentru noua matrice
	(*v) = realloc(*v, (*d + 1) * sizeof(matrice));
	if (!v) {
		//progrmare defensiva
		fprintf(stderr, "alocarea a esuat\n");
		exit(-1);
	}
	//citire linii si coloane
	scanf("%d %d", &m, &n);
	(*v)[*d].lin = m;
	(*v)[*d].col = n;
	(*v)[*d].sum = 0;
	(*v)[*d].a = NULL;
	(*v)[*d].a = malloc(m * sizeof(int *));
	if (!(*v)[*d].a) {
		fprintf(stderr, "alocarea a esuat\n");
		exit(-1);
	}
	for (int i = 0; i < m; i++) {
		(*v)[*d].a[i] = malloc(n * sizeof(int));
		if (!(*v)[*d].a[i]) {
			fprintf(stderr, "alocarea a esuat\n");
			exit(-1);
		}
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &(*v)[*d].a[i][j]);

			//respectam marimea precizata pentru operatii
			(*v)[*d].sum = ((*v)[*d].sum + (*v)[*d].a[i][j]) % MOD;
			if ((*v)[*d].sum < 0)
				(*v)[*d].sum += MOD;
		}
	//numarul de matrici creste direct in functie
	(*d)++;
}

int verificare(int k, int d)
{
	if (k >= d || k < 0) {
		printf("No matrix with the given index\n");
		return 0;
	}
	return 1;
}

void afisare(int k, matrice *v)
{
	for (int i = 0; i < v[k].lin; i++) {
		for (int j = 0; j < v[k].col; j++)
			printf("%d ", v[k].a[i][j]);
		printf("\n");
	}
}

void dimensiuni(int d, int k, matrice *v)
{
	if (verificare(k, d))
		printf("%d %d\n", v[k].lin, v[k].col);
}

void liber(int d, matrice **v)
{
	//eliberam intregul tablou
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < (*v)[i].lin; j++)
			free((*v)[i].a[j]);
		free((*v)[i].a);
	}
	free(*v);
}
