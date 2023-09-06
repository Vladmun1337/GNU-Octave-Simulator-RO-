#### Muntean Vlad-andrei 315CA 2022-2023

# Simulator Octave (RO)

## Implementare

Pentru rezolvarea acestei teme, am impartit problema in 10 sub-probleme,
in functie de cele 10 comenzi:

- **Alocarea si citirea**: Pentru a usura lucrul cu un numar mare de matrici,
am folosit un tablou de tip structura ce continea un pointer dublu
(matricea citita), dimensiunea matricii reprezentata de linii si coloane,
dar si suma elementelor din matrice (lucru ce va servi la 
operatia de ordonare).

Am realocat dimensiunea tabloului structura cu dimensiunea initiala
(variabila 'd') la care a fost adunata inca o unitate. Apoi a fost
alocat spatiul necesar pentru citirea matricii. In timpul citirii, a fost
calculata suma, l afiecare pas folosind operatia de modulo si verificarea
sa nu avem o suma negativa.

- **redimensionarea**: operatia are la baza facerea unei matrici auxiliare cu
dimensiunile si elementele citite in sirurile date. Este calculata suma
noii matrici. Apoi, matricea initiala este eliberata si toate informatiile
auxiliarei sunt mutate pe pozitia ceruta.

- **afisarea dimensiunilor**: sunt afisate numarul de linii si de coloane a
matricii date, cestea fiind salvate in structura.

- **afisarea matricii**: operatie clasica de afisare a unei matrici.

- **inmultirea a doua matrici**: inmultirea efectiva urmareste algoritmul
matematic, ce a fost pus in functia separata 'prod()', pentru a fi
utilizata la alte comenzi. Aceasta functie este apelata in subprogramul
'multip()', care aloca un nou spatiu pentru matricea rezultata si
calculeaza suma elementelor.

- **transpunerea unei matrici**: folosim o matrice auxiliara pentru care ii
alocam dimensiunile matricii initiale interschimbate (liniile devin
coloane si 'vice-verso'), iar elementele sunt copiate conform operatiei de
transpunere. Matricea initiala este eliberata, iar auxiliara ii ia locul in
tabloul de structuri.

- **Sortarea matricilor**: sortarea se foloseste de un element structura
auxiliar pentru a face interschimbarea a doua elemente din tabloul 
structura. Sortarea efectiva foloseste un algoritm de tip 'selection sort',
comparandu-se suma fiecarei matrici (sumele sunt reverificate inaintea 
comparatiei).

- **Ridicarea la putere in timp logaritmic**: algoritmul de ridicare la putere
clasic este ineficient pentru lucrul cu matrici de dimensiuni mari. Pentru
a reduce timpul de lucru, injumatatim la fiecare pas valoarea puterii date
(variaila 'n'), iar matricea propriu-zisa este calculata in tabloul '**p',
initializat cu toate elementele nule, mai putin diagonala cu valoarea 1
(matricea "identitate", elementul neutru al inmultirii matricilor). Pentru
 o valoare para a lui n, matricea initiala este ridicata la patrat, in cazul
unei valori impare, reultatul ridicarii la patrat este inmultit 
matricii '**p'. Matricea initiala este eliberata, iar rezultatul ridicarii
la putere este mutat pe locul sau in tablou.

- **stergerea din memorie a unei matrici**: zona de memorie a matricii alese
este eliberata, apoi toate elementele din tabloul structura sunt mutate cu
o pozitie in spate si tabloul este redimensionat cu o unitate mai putin.

- **eliberarea resurselor**: tabloul structura elibereaza toata memoria, iar
valorile sale sunt sterse.

## Utilizare

Programul citeste o litera specifica fiecarei comenzi, apoi informatiile
necesare efectuarii operatiei (dimensiunea 'd', tabloul '*v', indicii
matricilor 'k1' si 'k2', etc.) . Citirea este oprita odata ce apelam comanda
'Q' (stergere), in care variabila de control a structurii repetitive ('ok')
primeste valoarea nula.
