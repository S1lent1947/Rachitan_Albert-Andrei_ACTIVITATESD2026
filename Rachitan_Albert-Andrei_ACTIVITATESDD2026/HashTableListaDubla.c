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
////creare structura pentru un nod dintr-o lista simplu inlantuita
//typedef struct ListaDubla ListaDubla;
//typedef struct Nod Nod;
//typedef struct HashTable HashTable;
//struct Nod
//{
//	Nod* next;
//	Nod* prev;
//	Masina info;
//};
////creare structura pentru tabela de dispersie
//struct ListaDubla
//{
//	Nod* prim;
//	Nod* ultim;
//};
//// aceasta este un vector de liste
//struct HashTable {
//	int dim;
//	Nod** vector
//};
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	aux = strtok(buffer, sep);
//	Masina m1;
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret = atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model = (char*)malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//	aux = strtok(NULL, sep);
//	m1.numeSofer = (char*)malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//void afisareListaMasini(ListaDubla lista) {
//	//afiseaza toate elemente de tip masina din lista dublu inlantuita
//	//prin apelarea functiei afisareMasina()
//	Nod* capLista = lista.prim;
//	while (capLista != NULL)
//	{
//		afisareMasina(capLista->info);
//		capLista->next;
//	}
//}
//
//void adaugaMasinaInLista(ListaDubla* lista,Masina masinaNoua) {
//	//adauga la final in lista primita o noua masina pe care o primim ca parametru
//	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
//	nodNou->info = masinaNoua;
//	nodNou->next = NULL;
//	nodNou->prev = lista->ultim;
//	if (lista->prim == NULL)
//	{
//		lista->prim = nodNou;
//	}
//	else
//	{
//		lista->prim->next = nodNou;
//	}
//	lista->ultim = nodNou;
//}
//
//void adaugaMasinaLaInceput(ListaDubla* lista, Masina masina)
//{
//	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
//	nodNou->info = masina;
//	nodNou->next = lista->prim;
//	nodNou->prev = NULL;
//	if (lista->ultim == NULL)
//	{
//		lista->ultim = nodNou;
//	}
//	else
//	{
//		lista->prim->prev = nodNou;
//	}
//	lista->prim = nodNou;
//}
//
//
//HashTable initializareHashTable(int dimensiune) {
//	HashTable ht;
//	ht.dim = dimensiune;
//	ht.vector = (Nod**)malloc(dimensiune * sizeof(Nod*));
//	for (int i = 0; i < dimensiune; i++)
//	{
//		ht.vector[i] = NULL;
//	}
//	return ht;
//}
//
//int calculeazaHash(int id, int dimensiune) {
//	// este calculat hash-ul in functie de dimensiunea tabelei si un atribut al masinii
//	id = id * 14 + 87;
//	return id % dimensiune;
//}
//
//void inserareMasinaInTabela(HashTable hash, Masina galerie) {
//	//este folosit mecanismul CHAINING
//	//este determinata pozitia si se realizeaza inserarea pe pozitia respectiva
//	int pozitie = calculeazaHash(galerie.id, hash.dim);
//	if (hash.vector[pozitie] == NULL)
//	{
//		adaugaMasinaInLista(hash.vector, galerie)
//	}
//}
//
//HashTable citireMasiniDinFisier(const char* numeFisier) {
//	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
//	//prin apelul repetat al functiei citireMasinaDinFisier()
//	// aceste masini sunt inserate intr-o tabela de dispersie initializata aici
//	//ATENTIE - la final inchidem fisierul/stream-ul
//}
//
//void afisareTabelaDeMasini(HashTable ht) {
//	//sunt afisate toate masinile cu evidentierea clusterelor realizate
//}
//
//void dezalocareTabelaDeMasini(HashTable *ht) {
//	//sunt dezalocate toate masinile din tabela de dispersie
//}
//
//float* calculeazaPreturiMediiPerClustere(HashTable ht, int* nrClustere) {
//	//calculeaza pretul mediu al masinilor din fiecare cluster.
//	//trebuie sa returnam un vector cu valorile medii per cluster.
//	//lungimea vectorului este data de numarul de clustere care contin masini
//	return NULL;
//}
//
//Masina getMasinaDupaCheie(HashTable ht /*valoarea pentru masina cautata*/) {
//	Masina m;
//	//cauta masina dupa valoarea atributului cheie folosit in calcularea hash-ului
//	//trebuie sa modificam numele functiei 
//	return m;
//}
//
//int main() {
//
//
//	return 0;
//}