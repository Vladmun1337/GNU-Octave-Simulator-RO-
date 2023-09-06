// Muntean Vlad-Andrei 315CA
#include <stdio.h>
#include <stdlib.h>
#include "Struct-matrice.h"
#include "alocari_dezalocari.h"
#include "matematici.h"
#include "modificari.h"

int main(void)
{
	int d = 0, ok = 1, k1, k2, n;
	char comanda, copie;
	matrice *v = NULL;
	while (ok) {
		scanf("\n%c", &comanda);
		copie = comanda;
		//in cazul unui caracter invalid pe linie, sarim la urmatoarea comanda
		while ((copie >= '0' && copie <= '9') || copie == ' ')
			scanf("%c", &copie);
		switch (comanda) {
		case 'L':
		citire(&d, &v);
		break;

		case 'C':
		//citim indicele matricei dorite
		scanf("%d", &k1);
		redimensionare(d, k1, v);
		break;

		case 'D':
		scanf("%d", &k1);
		dimensiuni(d, k1, v);
		break;

		case 'P':
		scanf("%d", &k1);
		if (verificare(k1, d))
			afisare(k1, v);
		break;

		case 'M':
		scanf("%d %d", &k1, &k2);
		//ambii indici trebuie sa verifice conditia
		if (verificare(k1, d) && verificare(k2, d))
			multip(&d, k1, k2, &v);
		break;

		case 'T':
		scanf("%d", &k1);
		if (verificare(k1, d))
			transpune(k1, v);
		break;

		case 'O':
		sortare(d, v);
		break;

		case 'R':
		//citim indicele si puterea
		scanf("%d %d", &k1, &n);
		if (verificare(k1, d))
			putere_log(k1, n, v);
		break;

		case 'F':
		scanf("%d", &k1);
		sterge(&d, k1, &v);
		break;

		case 'Q':
		liber(d, &v);
		//eliberam resursele si iesim din while
		ok = 0;
		break;

		default:
		printf("Unrecognized command\n");
		}
	}

	return 0;
}
