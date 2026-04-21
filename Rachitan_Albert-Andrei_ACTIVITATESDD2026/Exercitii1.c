//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////trebuie sa folositi fisierul masini.txt
////sau va creati un alt fisier cu alte date
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
//void afisareMasina(Masina masina) {
//	printf("ID: %d\n", masina.id);
//	printf("Nr. usi: %d\n", masina.nrUsi);
//	printf("Pret: %4.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %d\n", masina.serie);
//}
//
//void afisareVectorMasini(Masina* masini, int nrMasini) {
//	for (int i = 0; i < nrMasini; i++)
//		afisareMasina(masini[i]);
//}
//
//void adaugaMasinaInVector(Masina** masini, int * nrMasini, Masina masinaNoua) {
//	Masina* copie = (Masina*)malloc(sizeof(Masina) * ((*nrMasini) + 1));
//	for (int i = 0; i < *nrMasini; i++)
//	{
//		copie[i] = (*masini)[i];
//	}
//	copie[*nrMasini] = masinaNoua;
//	free(*masini);
//	(*masini) = copie;
//	(*nrMasini)++;
//}
//
//Masina citireMasinaFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret = atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy(m1.model, aux);
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy(m1.numeSofer, aux);
//	m1.serie = strtok(NULL, aux);
//	return m1;
//}
//
//Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
//	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
//	//prin apelul repetat al functiei citireMasinaFisier()
//	//numarul de masini este determinat prin numarul de citiri din fisier
//	//ATENTIE - la final inchidem fisierul/stream-ul
//	FILE* f = fopen(numeFisier, "r");
//	if (f == NULL)
//	{
//		printf("Fisierul nu a putut fi deschis cu succes!");
//		return -1;
//	}
//	Masina* vector = NULL;
//	*nrMasiniCitite = 0;
//	while (!feof(f))
//	{
//		Masina m1 = citireMasinaFisier(f);
//		Masina* copie = (Masina*)malloc(sizeof(Masina) * ((*nrMasiniCitite) + 1));
//		for (int i = 0; i < *nrMasiniCitite; i++)
//		{
//			copie[i] = vector[i];
//		}
//		copie[*nrMasiniCitite] = m1;
//		free(vector);
//		vector = copie;
//		(*nrMasiniCitite)++;
//	}
//	fclose(f);
//	return vector;
//}
//
//void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
//	for (int i = 0; i < *nrMasini; i++)
//	{
//		free((*vector)[i].model);
//		free((*vector)[i].numeSofer);
//	}
//	free(*vector);
//	*vector = NULL;
//	*nrMasini = 0;
//}
//
//int main() {
//	FILE* f = fopen("Masini.txt", "r");
//
//	if (f == NULL)
//	{
//		printf("Fisierul nu a putut fi deschis cu succes!");
//		return -1;
//	}
//	Masina m = citireMasinaFisier(f);
//	fclose(f);
//	afisareMasina(m);
//	int nrMasiniCitite = 0;
//	Masina* vectorMasini = citireVectorMasiniFisier("Masini.txt", &nrMasiniCitite);
//	/*afisareVectorMasini(vectorMasini, nrMasiniCitite);*/
//	adaugaMasinaInVector(&vectorMasini, &nrMasiniCitite, m);
//	afisareVectorMasini(vectorMasini, nrMasiniCitite);
//	dezalocareVectorMasini(&vectorMasini, &nrMasiniCitite);
//	return 0;
//}