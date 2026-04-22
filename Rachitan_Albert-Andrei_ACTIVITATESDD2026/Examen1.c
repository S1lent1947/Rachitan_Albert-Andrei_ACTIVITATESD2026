#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Comanda
{
	unsigned int idComanda;
	char dataLansare[100]; //sunt scrise sub forma xx.xx.xxxx
	char dataLivrare[100]; //sunt scrie sub forma xx.xx.xxxx
	char numeClient[100];
	int statusComanda; //0 nu este livrat, 1 este livrat;
};
typedef struct Comanda Comanda;
typedef struct Nod Nod;
typedef struct ListaDubla ListaDubla;
typedef struct ListaSimpla ListaSimpla;
struct Nod
{
	Comanda info;
	Nod* next;
	Nod* prev;
};

struct ListaDubla
{
	Nod* ultim;
	Nod* prim;
};
struct ListaSimpla
{
	Nod* cap;
};
void adaugaInListaLaFinal(ListaDubla* lista, Comanda comanda)
{
	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
	nodNou->info = comanda;
	nodNou->next = NULL;
	nodNou->prev = lista->ultim;
	if (lista->prim == NULL)
	{
		lista->prim = nodNou;
	}
	else
	{
		lista->ultim->next = nodNou;
	}
	lista->ultim = nodNou;
}
void afisareComanda(Comanda comanda)
{
	printf("ID: %d\n", comanda.idComanda);
	printf("Data lansare: %s\n", comanda.dataLansare);
	printf("Data livrare: %s\n", comanda.dataLivrare);
	printf("Nume client: %s\n", comanda.numeClient);
	printf("Status comanda: %d\n", comanda.statusComanda);
}
void afisareListaComenzi(ListaDubla lista)
{
	Nod* temp = lista.prim;
	while (temp != NULL)
	{
		afisareComanda(temp->info);
		temp = temp->next;
	}
}
void afisareListaSimpla(ListaSimpla lista)
{
	Nod* temp = lista.cap;
	while (temp != NULL)
	{
		afisareComanda(temp->info);
		temp = temp->next;
	}
}
void adaugareListaSimpla(ListaSimpla* lista, Comanda comanda)
{
	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
	nodNou->info = comanda;
	nodNou->prev = NULL; //lista simpla nu are prev!
	nodNou->next = lista->cap; //adaugare la inceput!
	lista->cap = nodNou;
}
ListaDubla initializareListaDubla(ListaDubla lista)
{
	Comanda c1 = { 1,"16.87.2025", "19.87.2025", "Tataie", 0};
	Comanda c2 = { 2,"15.87.2025", "N/A", "Budesh Christian Anderson", 0};
	Comanda c3 = { 3,"14.87.2025", "20.87.2025", "Rachitan Albert Nepotu'", 1};
	Comanda c4 = { 4,"12.87.2025", "N/A", "Compot de caise", 0};
	Comanda c5 = { 5,"11.87.2025" ,"N/A" ,"Tataie", 0};
	adaugaInListaLaFinal(&lista, c1);
	adaugaInListaLaFinal(&lista, c2);
	adaugaInListaLaFinal(&lista, c3);
	adaugaInListaLaFinal(&lista, c4);
	adaugaInListaLaFinal(&lista, c5);
	return lista;
}
ListaSimpla initializareListaSimpla(ListaSimpla listaSimpla, int statusComanda, ListaDubla listaDubla)
{
	Nod* prim = listaDubla.prim;
	while (prim != NULL)
	{
		if (prim->info.statusComanda == statusComanda)
		{
			adaugareListaSimpla(&listaSimpla, prim->info);
		}
		prim = prim->next;
	}
	return listaSimpla;
}
int numarComenzi(ListaDubla lista, char numeClient[])
{
	int index = 0;
	Nod* temp = lista.prim;
	while (temp != NULL)
	{
		if (strcmp(temp->info.numeClient, numeClient) == 0)
		{
			index++;
		}
		temp = temp->next;
	}
	return index;
}
void modificareDataComanda(ListaDubla* lista, int statusComanda, char numeClient[], char dataLivrare[])
{
	Nod* tempPrim = lista->prim;
	while (tempPrim != NULL)
	{
		if (tempPrim->info.statusComanda == statusComanda && strcmp(tempPrim->info.numeClient, numeClient) == 0)
		{
			strcpy_s(tempPrim->info.dataLivrare, strlen(dataLivrare) + 1, dataLivrare);
		}
		tempPrim = tempPrim->next;
	}
}
int main()
{
	ListaDubla listaDubla;
	listaDubla.prim = NULL;
	listaDubla.ultim = NULL;
	listaDubla = initializareListaDubla(listaDubla);
	afisareListaComenzi(listaDubla);
	char numeClient[100];
	printf("Introduceti numele clientului: \n");
	fgets(numeClient, 100, stdin);
	numeClient[strcspn(numeClient, "\n")] = '\0';
	printf("Numar comenzi %d!", numarComenzi(listaDubla, numeClient));
	char dataLivrare[100];
	printf("Precizati noua data in care se va livra comanda:\n");
	fgets(dataLivrare, 100, stdin);
	dataLivrare[strcspn(dataLivrare, "\n")] = '\0';
	printf("Inainte de modificare: \n\n\n");
	afisareListaComenzi(listaDubla);
	modificareDataComanda(&listaDubla, 0, numeClient,dataLivrare);
	afisareListaComenzi(listaDubla);
	int statusComanda;
	printf("Introduceti status comanda: \n");
	scanf_s("%d", &statusComanda);
	ListaSimpla listaSimpla;
	listaSimpla.cap = NULL;
	listaSimpla = initializareListaSimpla(listaSimpla, statusComanda, listaDubla);
	afisareListaSimpla(listaSimpla);
}