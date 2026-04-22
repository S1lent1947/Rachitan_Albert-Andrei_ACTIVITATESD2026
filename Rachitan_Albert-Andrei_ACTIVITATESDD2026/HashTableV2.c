#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StructuraMasina 
{
		int id;
		int nrUsi;
		float pret;
		char* model;
		char* numeSofer;
		unsigned char serie;
};
typedef struct StructuraMasina Masina;
typedef struct Nod Nod;
typedef struct HashTable HashTable;
struct Nod
{
	Nod* next;
	Masina info;
};

struct HashTable
{
	int dimensiune;
	Nod** vector;
};

Masina citireFisier(FILE* file)
{
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	Masina m1;
	char* aux;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret = atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m1.model = (char*)malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);
	aux = strtok(NULL, sep);
	m1.numeSofer = (char*)malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
	m1.serie = *strtok(NULL, sep);
	return m1;
}
void afisareMasina(Masina masina)
{
	printf("ID: %d\n", masina.id);
	printf("Numar usi: %d\n", masina.nrUsi);
	printf("Pret: %4.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n", masina.serie);
}
void afisareListaMasini(Nod* cap)
{
	while (cap != NULL)
	{
		afisareMasina(cap->info);
		cap = cap->next;
	}
}
void afisareHashTable(HashTable ht)
{
	for (int i = 0; i < ht.dimensiune; i++)
	{
		if (ht.vector[i] != NULL)
		{
			afisareListaMasini(ht.vector[i]);
		}
	}
}
void adaugareInLista(Nod** cap, Masina masinaNoua)
{
	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
	nodNou->info = masinaNoua;
	nodNou->next = *cap;
	*cap = nodNou;
}

int calculareHash(int id, int dimensiune)
{
	id = id * 14 + 87;
	return id % dimensiune;
}

HashTable initializareHashTable(int dimensiune)
{
	HashTable ht;
	ht.dimensiune = dimensiune;
	ht.vector = (Nod**)malloc(dimensiune * sizeof(Nod*));
	for (int i = 0; i < dimensiune; i++)
	{
		ht.vector[i] = NULL;
	}
	return ht;
}

void adaugareInHashTable(HashTable ht, Masina info, int *coliziuni)
{
	int poz = calculareHash(info.id, ht.dimensiune);
	if (ht.vector[poz] == NULL)
	{
		adaugareInLista(&(ht.vector[poz]), info);
	}
	else
	{
		(*coliziuni)++;
		adaugareInLista(&(ht.vector[poz]), info);
	}
}
HashTable citireFisierHashTable(const char* numeFisier, int dimensiune, int* coliziuni)
{
	HashTable ht = initializareHashTable(dimensiune);
	FILE* f = fopen(numeFisier, "r");
	if (f == NULL)
	{
		printf("Fisierul nu s a putut deschide cu succes!");
		return ht;
	}
	while (!feof(f))
	{
		adaugareInHashTable(ht, citireFisier(f), coliziuni);
	}
	return ht;
}
void dezalocareHashTable(HashTable* ht)
{
	for (int i = 0; i < ht->dimensiune; i++)
	{
		if (ht->vector[i] != NULL)
		{
			Nod* temp1 = ht->vector[i];
			while (temp1 != NULL)
			{
				Nod* temp2 = temp1;
				temp1 = temp1->next;
				free(temp2->info.model);
				free(temp2->info.numeSofer);
				free(temp2);
				temp2 = NULL;
			}
		}
		ht->vector[i] = NULL;
	}
}

int main()
{
	int coliziuni = 0;
	HashTable ht = citireFisierHashTable("masini.txt", 7, &coliziuni);
	printf("Numarul de coliziuni este: %d\n", coliziuni);
	afisareHashTable(ht);
	dezalocareHashTable(&ht);
	printf("Dupa dezalocare -------------------------------------\n\n\n\n\n");
	afisareHashTable(ht);
}