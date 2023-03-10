###### // Copyright Lebada Daria-Cristiana 313CAa 2021-2022

#### PCLP1

## Tema 2 - Simulator de Octave (alocare dinamica)

In rezolvarea temei am utilizat un vector de matrice (vector_matrice) alocat
dinamic in care stochez fiecare matrice citita/ prelucrata, o matrice (dimensiuni)
in care salvez dimensiunile fiecarei matrice (pe cate o linie) si o variabila int
(numar) in care retin numarul de matrice stocate in memorie.
De asemenea, am definit o constanta MOD = 10007 pentru a calcula valorile numerice
obtinute ca urmare a operatiilor aritmetice in modulo 10^4 + 7.

### Incarcarea in memorie a unei matrice - L:
Se aloca o matrice auxiliara in care se citesc elementele de la tastatura.
Se realoca vectorul de matrice si se copiaza matricea auxiliara la finalul acestuia.

### Determinarea dimensiunilor unei matrice - D:
Se verifica daca indicele cautat este valid si se afiseaza linia din matricea de
dimensiuni corespunzatoare indicelui.

### Afisarea unei matrice - P:
Se afiseaza matricea cautata (din vectorul de matrice).

### Redimensionarea unei matrice - C:
Se aloca dinamic 2 vectori in care se vor retine liniile, respectiv coloanele care
vor fi folosite in constructia noii matrice. Matricea va fi contruita in functie de
valorile aflate in matricea initiala (inainte de modificare) aflate pe pozitiile din
cei doi vectori definiti anterior.

### Inmultirea a doua matrice - M:
Doua matrice se pot inmulti doar daca numarul de coloane ale primei matricei este
egal cu numarul de linii ale celei de-a doua matrice. Daca aceasta conditie este
indeplinita, se va realiza inmultirea celor doua matrice conform regulilor matematice.
La suma se va aduna de fiecare data MOD * MOD, pentru a evita cazurile de rezultate
negative la calculul in modulo 10^4 + 7.

### Sortarea matricelor - O:
Se calculeaza suma elementelor fiecare matrice si se salveaza intr-un vector de
sume pe pozitia indicelui fiecarei matrice. Se sorteaza vectorul de matrice in
functie de sume; de fiecare data cand se gasesc 2 elemente nesortate, se interschimba
matricele, dimensiunile si sumele lor.

### Transpunerea unei matrice - T:
Transpusa se calculeaza interschimbandu-se linii din matrice cu coloane.

### Eliberarea din memorie a unei matrice - F:
Se elibereaza memoria matricei care urmeaza a fi stearsa si se muta fiecare
matrice cu o pozitie spre stanga.

### Eliberarea tuturor resurselor - Q:
Se elibereaza memoria alocata vectorului de matrice si a matricei de dimensiuni.
