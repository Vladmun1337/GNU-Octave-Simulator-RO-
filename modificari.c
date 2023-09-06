// Muntean Vlad-Andrei 315CA
#include <stdio.h>
#include <stdlib.h>
#include "Struct-matrice.h"
#include "alocari_dezalocari.h"
#define MOD 10007

void redimensionare(int d, int k, matrice *v)
{
	int m, n, *l = NULL, *c = NULL, **aux = NULL, s = 0;
	//citim dimensiunea si elementele primului sir
	scanf("%d", &m);
	l = malloc(m * sizeof(int));
	if (!l) {
		fprintf(stderr, "alocarea a esuat\n");
		exit(-1);
	}
	for (int i = 0; i < m; i++)
		scanf("%d", &l[i]);

	scanf("%d", &n);
	c = malloc(n * sizeof(int));
	if (!c) {
		fprintf(stderr, "alocarea a esuat\n");
		exit(-1);
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);

	if (verificare(k, d)) {
		aux = malloc(m * sizeof(int *));
		if (!aux) {
			fprintf(stderr, "alocarea a esuat\n");
			exit(-1);
		}
		for (int i = 0; i < m; i++) {
			aux[i] = malloc(n * sizeof(int));
			if (!aux[i]) {
				fprintf(stderr, "alocarea a esuat\n");
				exit(-1);
			}
			for (int j = 0; j < n; j++) {
				//mutam elemente in matricea auxiliara
				aux[i][j] = v[k].a[l[i]][c[j]];
				s = (s + aux[i][j]) % MOD;
			}
		}
		//verificarea sumei la iesire
		if (s >= 0)
			s = s % MOD;
		else
			s = s % MOD + MOD;
		//eliberam matricea veche si o inlocuim
		for (int i = 0; i < v[k].lin; i++)
			free(v[k].a[i]);
		free(v[k].a);
		v[k].lin = m;
		v[k].col = n;
		v[k].a = aux;
		v[k].sum = s;
	}
	free(l);
	free(c);
}

void transpune(int k, matrice *v)
{
	int **aux = NULL, i, j, swap;
	//coloanele devin linii, vice-verso
	aux = malloc(v[k].col * sizeof(int *));
	if (!aux) {
		fprintf(stderr, "alocarea a esuat\n");
		exit(-1);
	}
	for (i = 0; i < v[k].col; i++) {
		aux[i] = malloc(v[k].lin * sizeof(int));
		if (!aux[i]) {
			fprintf(stderr, "alocarea a esuat\n");
			exit(-1);
		}

		for (j = 0; j < v[k].lin; j++)
			aux[i][j] = v[k].a[j][i];
	}
	//eliberam vechea matrice
	for (i = 0; i < v[k].lin; i++)
		free(v[k].a[i]);
	free(v[k].a);

	swap = v[k].lin;
	v[k].lin = v[k].col;
	v[k].col = swap;
	v[k].a = aux;
}

void sortare(int d, matrice *v)
{
	int i, j;
	//folosim auxiliarul pentru interschimbari
	matrice *swap = malloc(sizeof(matrice));
	if (!swap) {
		fprintf(stderr, "alocarea a esuat\n");
		exit(-1);
	}
	for (i = 0; i < d - 1; i++) {
		//verificam inca o data fiecare suma
		if (v[i].sum >= 0)
			v[i].sum = v[i].sum % MOD;
		else
			v[i].sum = v[i].sum % MOD + MOD;

		for (j = i + 1; j < d; j++) {
			if (v[j].sum >= 0)
				v[j].sum = v[j].sum % MOD;
			else
				v[i].sum = v[i].sum % MOD + MOD;

			if (v[i].sum > v[j].sum) {
				*swap = v[i];
				v[i] = v[j];
				v[j] = *swap;
			}
		}
	}
	free(swap);
}

void sterge(int *d, int k, matrice **v)
{
	if (verificare(k, *d)) {
		//elementul trebuie eliberat pana la stergere
		for (int i = 0; i < (*v)[k].lin; i++)
			free((*v)[k].a[i]);
		free((*v)[k].a);

		for (int i = k + 1; i < *d; i++)
			(*v)[i - 1] = (*v)[i];
		//lungimea sirului de matrici scade
		(*d)--;
		//ultimul element este eliberat
		*v = realloc(*v, (*d) * sizeof(matrice));
		if (!v) {
			fprintf(stderr, "alocarea a esuat\n");
			exit(-1);
		}
	}
}
