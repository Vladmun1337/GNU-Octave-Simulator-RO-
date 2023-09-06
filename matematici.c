// Muntean Vlad-Andrei 315CA
#include <stdio.h>
#include <stdlib.h>
#include "Struct-matrice.h"
#define MOD 10007

void prod(int m1, int **a, int m2, int n2, int **b, int **aux, int *suma)
{
	int i, j, k, s, p;
	//calculam simultan suma pentru a elimina cod duplicat
	*suma = 0;

	//produsul a doua matrici cu algoritmul matematic
	for (i = 0; i < m1; i++) {
		for (j = 0; j < n2; j++) {
			s = 0;
			for (k = 0; k < m2; k++) {
				//elementul rezultat produsului
				p = (a[i][k] * b[k][j]) % MOD;
				if (p < 0)
					p += MOD;
				s = (s + p) % MOD;
			}
			//suma produselor este atribuita elementului
			aux[i][j] = s;
			*suma = (*suma + s) % MOD;
			if (*suma < 0)
				*suma += MOD;
		}
	}
}

void putere_log(int k, int n, matrice *v)
{
	int **p = NULL, **aux = NULL, **var = NULL, i, j, dim, s, control;
	if (v[k].lin != v[k].col) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}
	if (n < 0) {
		printf("Power should be positive\n");
		return;
	}
	p = calloc(v[k].lin, sizeof(int *));
	if (!p) {
		fprintf(stderr, "alocarea a esuat\n");
		exit(-1);
		}
	dim = v[k].lin;
	aux = malloc(dim * sizeof(int *));
	if (!aux) {
		fprintf(stderr, "alocarea a esuat\n");
		exit(-1);
		}
	for (i = 0; i < dim; i++) {
		aux[i] = malloc(dim * sizeof(int));
		if (!aux[i]) {
			fprintf(stderr, "alocarea a esuat\n");
			exit(-1);
		}
	}
	var = malloc(dim * sizeof(int *));
	if (!var) {
		fprintf(stderr, "alocarea a esuat\n");
		exit(-1);
	}
	for (i = 0; i < dim; i++) {
		var[i] = malloc(dim * sizeof(int));
		if (!var[i]) {
			fprintf(stderr, "alocarea a esuat\n");
			exit(-1);
		}
	}
	//in p salvam matricea identitate
	for (i = 0; i < dim; i++) {
		p[i] = calloc(dim, sizeof(int));
		if (!p[i]) {
			fprintf(stderr, "alocarea a esuat\n");
			exit(-1);
		}
		p[i][i] = 1;
	}

	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
			aux[i][j] = v[k].a[i][j];
	while (n != 0) {
		if (n % 2 == 1) {
			prod(dim, p, dim, dim, v[k].a, var, &s);
			//mutam rezultatul inmultirii in matricea initiala
				for (i = 0; i < dim; i++)
					for (j = 0; j < dim; j++)
						p[i][j] = var[i][j];
		}
		//suma serveste drept variabila de control
		prod(dim, v[k].a, dim, dim, v[k].a, aux, &control);
		for (i = 0; i < dim; i++)
			for (j = 0; j < dim; j++)
				v[k].a[i][j] = aux[i][j];
		n = n / 2;
	}
	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
			v[k].a[i][j] = p[i][j];
	v[k].sum = s;
	for (i = 0; i < dim; i++) {
		free(aux[i]);
		free(p[i]);
		free(var[i]);
	}
	free(aux);
	free(p);
	free(var);
}

void multip(int *d, int k1, int k2, matrice **v)
{
	int **aux = NULL, i, suma, m1, m2, n2;
	if ((*v)[k1].col != (*v)[k2].lin) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}
	/*folosim doar 3 dimensiuni, numarul de coloane al
	primei matrici nu e necesar*/
	m1 = (*v)[k1].lin;
	m2 = (*v)[k2].lin;
	n2 = (*v)[k2].col;
	//matrice auxiliara pentru rezultatul inmultirii
	aux = malloc(m1 * sizeof(int *));
	if (!aux) {
		fprintf(stderr, "alocarea a esuat\n");
		exit(-1);
	}
	for (i = 0; i < m1; i++) {
		aux[i] = malloc(n2 * sizeof(int));
		if (!aux[i]) {
			fprintf(stderr, "alocarea a esuat\n");
			exit(-1);
	}
	}
	prod(m1, (*v)[k1].a, m2, n2, (*v)[k2].a, aux, &suma);

	//marim vectorul pentru a a dauga noua matrice
	(*v) = realloc((*v), (*d + 1) * sizeof(matrice));
	if (!v) {
		fprintf(stderr, "alocarea a esuat\n");
		exit(-1);
	}
	(*v)[*d].lin = (*v)[k1].lin;
	(*v)[*d].col = (*v)[k2].col;
	(*v)[*d].sum = suma;
	(*v)[*d].a = aux;
	(*d)++;
}
