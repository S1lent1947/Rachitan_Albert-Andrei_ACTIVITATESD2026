#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Televizor Televizor;
typedef struct Nod Nod;
typedef struct ListaDubla ListaDubla;
struct Televizor
{
	char* producator;
	int greutate;
	float diagonala;
};

struct Nod
{
	Nod* next;
	Televizor info;
};

struct ListaDubla
{
	Nod* prim;
};

void adaugareInListaDubla(ListaDubla* listaDubla, Televizor televizorNou)
{
	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
	nodNou->info = televizorNou;
	nodNou->next = NULL;
	if (listaDubla->prim == NULL)
	{
		listaDubla->prim = nodNou;
	}
	else
	{
		Nod* aux = listaDubla->prim;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = nodNou;
	}

}

Televizor citireTelevizor(FILE* file)
{
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	Televizor t1;
	char* aux;
	aux = strtok(buffer, sep);
	t1.producator = (char*)malloc(strlen(aux) + 1);
	strcpy(t1.producator, aux);
	t1.greutate = atoi(strtok(NULL, sep));
	t1.diagonala = atof(strtok(NULL, sep));
	return t1;
}

void afisareTelevizor(Televizor televizor)
{
	printf("Producator: %s\n", televizor.producator);
	printf("Greutate: %d\n", televizor.greutate);
	printf("Diagonala: %4.2f\n\n", televizor.diagonala);
}

void afisareListaDubla(ListaDubla listaDubla)
{
	Nod* temp = listaDubla.prim;
	while (temp != NULL)
	{
		afisareTelevizor(temp->info);
		temp = temp->next;
	}
}
ListaDubla initializareListaDubla(const char* numeFisier)
{
	ListaDubla listaDubla;
	listaDubla.prim = NULL;
	FILE* f = fopen(numeFisier, "r");
	if (f == NULL)
	{
		printf("Fisierul nu s a putut deschide cu succes!");
		return listaDubla;
	}
	while (!feof(f))
	{
		adaugareInListaDubla(&listaDubla, citireTelevizor(f));
	}
	return listaDubla;
}

char* celMaiMicTelevizor(ListaDubla listaDubla)
{
	Nod* temp = listaDubla.prim;
	float minim = temp->info.diagonala;
	char* numeProducator = (char*)malloc(strlen(temp->info.producator));
	strcpy(numeProducator, temp->info.producator);
	while (temp != NULL)
	{
		if (minim > temp->info.diagonala)
		{
			float minim = temp->info.diagonala;
			free(numeProducator);
			numeProducator = NULL;
			char* numeProducator = (char*)malloc(strlen(temp->info.producator));
			strcpy(numeProducator, temp->info.producator);
		}
		temp = temp->next;
	}
	return numeProducator;
}
Televizor televizorulProducatorului(const char* numeProducator, ListaDubla listaDubla)
{
	Nod* temp = listaDubla.prim;
	Televizor t1;
	t1.producator = NULL;
	t1.greutate = 0;
	t1.diagonala = 0;
	while (temp != NULL)
	{
		if (strcmp(temp->info.producator, numeProducator) == 0)
		{
			t1.producator = (char*)malloc(strlen(temp->info.producator) + 1);
			strcpy(t1.producator, temp->info.producator);
			t1.greutate = temp->info.greutate;
			t1.diagonala = temp->info.diagonala;
			return t1;
		}
	}
	return t1;
}

Televizor* deepCopyTelevizoare(ListaDubla listaDubla, int *nrTelevizoare)
{
	Nod* temp = listaDubla.prim;
	while (temp != NULL)
	{
		(*nrTelevizoare)++;
		temp = temp->next;
	}
	Televizor* televizoare = (Televizor*)malloc(sizeof(Televizor) * (*nrTelevizoare));
	Nod* temp2 = listaDubla.prim;
	int index = 0;
	while (temp2 != NULL)
	{
		Televizor t1;
		t1.producator = (char*)malloc(strlen(temp2->info.producator) + 1);
		strcpy(t1.producator, temp2->info.producator);
		t1.greutate = temp2->info.greutate;
		t1.diagonala = temp2->info.diagonala;
		televizoare[index] = t1;
		index++;
		temp2 = temp2->next;
	}
	return televizoare;
}
int main()
{
	ListaDubla listaDubla = initializareListaDubla("televizor.txt");
	afisareListaDubla(listaDubla);
	printf("Producatorul cu cel mai mic televizor este: %s\n\n", celMaiMicTelevizor(listaDubla));
	afisareTelevizor(televizorulProducatorului("Tataie", listaDubla));
	int nrTelevizoare = 0;
	Televizor* televizoare = deepCopyTelevizoare(listaDubla, &nrTelevizoare);
	for (int i = 0; i < nrTelevizoare; i++)
	{
		afisareTelevizor(televizoare[i]);
	}
	return 0;
}