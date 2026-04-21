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

void afisareMasina(Masina masina) {
	printf("ID: %d\n", masina.id);
	printf("Numar usi: %d\n", masina.nrUsi);
	printf("Pret: %4.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n\n", masina.serie);
}

void afisareVectorMasini(Masina* masini, int nrMasini) {
	if (masini == NULL)
		return;
	for (int i = 0; i < nrMasini; i++)
		afisareMasina(masini[i]);
}

void adaugaMasinaInVector(Masina** masini, int * nrMasini, Masina masinaNoua) {
	masini = (Masina**)realloc(masini, sizeof(Masina*) * ((*nrMasini) + 1)); //	Masina* copie = (Masina*)malloc(sizeof(Masina) * ((*nrMasini) + 1));
	masini[*nrMasini] = &masinaNoua;
}

Masina citireMasinaFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	Masina m1;
	m1.id = atoi(strtok(NULL, sep));
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret = atof(strtok(NULL, sep));
	char* aux;
	aux = strtok(NULL, sep);
	m1.model = (char*)malloc(strlen(aux) + 1);
	strcpy(m1.model, aux);
	m1.numeSofer = (char*)malloc(strlen(aux) + 1);
	strcpy(m1.numeSofer, aux);
	m1.serie = (char)strtok(NULL, sep);
	return m1;
}

Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
	FILE* f;
	f = fopen(numeFisier, "r");
	Masina* masini = NULL;
	while (!feof(f))
	{
		adaugaMasinaInVector(&masini, nrMasiniCitite, citireMasinaFisier(f));
		(*nrMasiniCitite)++;
	}
	return masini;
}

void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
	//este dezalocat intreg vectorul de masini
}

int main() {
	int nrMasiniCitite = 0;
	Masina* masini = citireVectorMasiniFisier("masini.txt", &nrMasiniCitite);
	afisareVectorMasini(masini, nrMasiniCitite);
	return 0;
}