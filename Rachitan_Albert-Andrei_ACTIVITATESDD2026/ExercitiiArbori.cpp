#include <stdio.h>
#include <cstring>
#include <stdlib.h>

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

struct Nod {
	Masina info;
	Nod* stanga;
	Nod* dreapta;
};

Masina citireMasina(FILE* file)
{
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.pret = atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m1.model = (char*)malloc(strlen(aux) + 1);
	strcpy(m1.model, aux);
	aux = strtok(NULL, sep);
	m1.numeSofer = (char*)malloc(strlen(aux) + 1);
	strcpy(m1.numeSofer, aux);
	m1.serie = *strtok(NULL, sep);
	free(aux);
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
void adaugaMasinaInArbore(Nod** radacina, Masina masinaNoua)
{
	if (*radacina) {
		if ((*radacina)->info.id < masinaNoua.id) {
			adaugaMasinaInArbore(&(*radacina)->dreapta, masinaNoua);
		}
		if ((*radacina)->info.id > masinaNoua.id) {
			adaugaMasinaInArbore(&(*radacina)->stanga, masinaNoua);
		}
	}
	else
	{
		Nod* nodNou = (Nod*)malloc(sizeof(Nod));
		nodNou->info = masinaNoua;
		nodNou->dreapta = NULL;
		nodNou->stanga = NULL;
		*radacina = nodNou;
	}
}
int main()
{

}