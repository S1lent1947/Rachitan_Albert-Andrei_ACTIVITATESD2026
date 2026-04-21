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
//	
//		printf("ID: %d\n", masina.id);
//		printf("Numar usi: %d\n", masina.nrUsi);
//		printf("Pret: %4.2f\n", masina.pret);
//		printf("Model: %s\n", masina.model);
//		printf("Nume sofer: %s\n", masina.numeSofer);
//		printf("Serie: %c\n\n\n", masina.serie);
//
//}
//
//void afisareVectorMasini(Masina* masini, int nrMasini) {
//	//afiseaza toate elemente de tip masina din vector
//	//prin apelarea functiei afisareMasina()
//}
//
//void adaugaMasinaInVector(Masina** masini, int * nrMasini, Masina masinaNoua) {
//	//adauga in vectorul primit o noua masina pe care o primim ca parametru
//	//ATENTIE - se modifica numarul de masini din vector;
//}
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(NULL, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret = atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model =(char*)malloc(strlen(aux) + 1);
//	strcpy(m1.model, aux);
//	aux = strtok(NULL, sep);
//	m1.numeSofer = (char*)malloc(strlen(aux) + 1);
//	strcpy(m1.numeSofer, aux);
//	m1.serie = (char)strtok(NULL, sep);
//	return m1;
//}
//
//Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
//
//	
//}
//
//void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
//	//este dezalocat intreg vectorul de masini
//}
//
//int main() {
//
//
//	return 0;
//}
//
////Masina citireMasinaDinFisier(FILE* file) {
////	char buffer[100];
////	char sep[3] = ",\n";
////	fgets(buffer, 100, file);
////	char* aux;
////	Masina m1;
////	aux = strtok(buffer, sep);
////	m1.id = atoi(aux); // ascii to int <3
////	m1.nrUsi = atoi(strtok(NULL, sep));
////	m1.pret = atof(strtok(NULL, sep)); //ascii to float <3
////	aux = strtok(NULL, sep);
////	m1.model = (char*)malloc(strlen(aux) + 1);
////	strcpy(m1.model, aux);
////	aux = strtok(NULL, sep); //string to token <3
////	m1.numeSofer = (char*)malloc(strlen(aux) + 1);
////	strcpy(m1.numeSofer, aux);
////	m1.serie = *strtok(NULL, sep);
////	return m1;
////
////}