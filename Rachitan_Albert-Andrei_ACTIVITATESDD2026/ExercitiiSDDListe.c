#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//trebuie sa folositi fisierul masini.txt
//sau va creati un alt fisier cu alte date

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;
typedef struct Nod Nod;
struct Nod
{
	Masina info;
	Nod* next;
};

Masina citireMasinaDinFisier(FILE* file) {
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
	m1.model = malloc(strlen(aux) + 1);
	strcpy(m1.model, aux);
	aux = strtok(NULL, sep);
	m1.numeSofer = malloc(strlen(aux) + 1);
	strcpy(m1.numeSofer, aux);
	m1.serie = *strtok(NULL, aux);
	return m1;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

void afisareListaMasini(Nod* nod) {
	//afiseaza toate elemente de tip masina din lista simplu inlantuita
	//prin apelarea functiei afisareMasina()
	while (nod != NULL)
	{
		afisareMasina(nod->info);
		nod = nod->next;
	}
}

void adaugaMasinaInLista(Nod** cap, Masina masinaNoua) {
	//adauga la final in lista primita o noua masina pe care o primim ca parametru
	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
	nodNou->info = masinaNoua;
	nodNou->next = NULL;
	if (*cap == NULL)
	{
		*cap = nodNou;
		return;
	}
	Nod* aux = *cap;
	while (aux->next != NULL)
	{
		aux = aux->next;
	}
	aux->next = nodNou;

}

void adaugaLaInceputInLista(Nod** cap, Masina masinaNoua) {
	//adauga la inceputul listei o noua masina pe care o primim ca parametru
	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
	nodNou->info = masinaNoua;
	nodNou->next = *cap;
	*cap = nodNou;
}

void* citireListaMasiniDinFisier(const char* numeFisier) {
	FILE* f;
	f = fopen(numeFisier, "r");
	if (f == NULL)
	{
		printf("Fisierul nu s a putut deschide cu succes!");
		return NULL;
	}
	Nod* cap = NULL;
	while (!feof(f))
	{
		adaugaMasinaInLista(&cap, citireMasinaDinFisier(f));
	}
	fclose(f);
	return cap;
}

void dezalocareListaMasini(Nod** cap) {
	while (*cap != NULL)
	{
		Nod* temp = *cap;
		*cap = (*cap)->next;
		free(temp->info.model);
		free(temp->info.numeSofer);
		free(temp);
	}
}

float calculeazaPretMediu(Nod* cap) {
	//calculeaza pretul mediu al masinilor din lista.
	float pret = 0;
	int index = 0;
	while (cap != NULL)
	{
		pret += cap->info.pret;
		cap = cap->next;
		index++;
	}
	return pret/index; 
}

void stergeMasiniDinSeria(Nod** cap, char serieCautata) {
	//sterge toate masinile din lista care au seria primita ca parametru.
	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
	while (*cap != NULL && (*cap)->info.serie == serieCautata) {
		Nod* temp = *cap;
		*cap = (*cap)->next;

		free(temp->info.model);
		free(temp->info.numeSofer);
		free(temp);
	}
	Nod* curent = *cap;
	while (curent != NULL && curent->next != NULL) {
		if (curent->next->info.serie == serieCautata) {
			Nod* temp = curent->next;
			curent->next = temp->next;

			free(temp->info.model);
			free(temp->info.numeSofer);
			free(temp);
		}
		else {
			curent = curent->next;
		}
	}
}

float calculeazaPretulMasinilorUnuiSofer(Nod* cap,const char* numeSofer) {
	//calculeaza pretul tuturor masinilor unui sofer.
	float pret = 0;
	while (cap != NULL)
	{
		if (strcmp(numeSofer, cap->info.numeSofer))
		{
			pret += cap->info.pret;
		}
		cap = cap->next;
	}
	return 0;
}

int main() {
	Nod* cap = citireListaMasiniDinFisier("masini.txt");
	afisareListaMasini(cap);
	stergeMasiniDinSeria(&cap, 'A');
	printf("------------------------\n\n\n\n\n");
	afisareListaMasini(cap);
	dezalocareListaMasini(&cap);
	printf("------------------------\n\n\n\n\n");
	afisareListaMasini(cap);
	return 0;
}