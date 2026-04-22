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
//typedef struct Nod Nod;
//typedef struct ListaDubla ListaDubla;
////creare structura pentru un nod dintr-o lista dublu inlantuita
//struct Nod
//{
//	Masina info;
//	Nod* next;
//	Nod* prev;
//};
////creare structura pentru Lista Dubla 
//struct ListaDubla
//{
//	Nod* prim;
//	Nod* ultim;
//};
//
//Masina citireMasinaDinFisier(FILE* file) {
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
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
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
//	Nod* p = lista.prim;
//	while (p != NULL)
//	{
//		afisareMasina(p->info);
//		p = p->next;
//	}
//}
//
//void adaugaMasinaInLista(ListaDubla* lista, Masina masinaNoua) {
//	//adauga la final in lista primita o noua masina pe care o primim ca parametru
//	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
//	nodNou->info = masinaNoua;
//	nodNou->next = NULL;
//	nodNou->prev = lista->ultim;
//	if (lista->ultim != NULL)
//	{
//		lista->ultim->next = nodNou;
//	}
//	else
//	{
//		lista->prim = nodNou;
//	}
//	lista->ultim = nodNou;
//}
//
//void adaugaLaInceputInLista(ListaDubla* lista, Masina masinaNoua) {
//	//adauga la inceputul listei dublu inlantuite o noua masina pe care o primim ca parametru
//	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
//	nodNou->info = masinaNoua;
//	nodNou->next = lista->prim;
//	nodNou->prev = NULL;
//	if(lista->prim != NULL )
//	{
//		lista->prim->prev = nodNou;
//	}
//	else
//	{
//		lista->ultim = nodNou;
//	}
//	lista->prim = nodNou;
//
//}
//
//ListaDubla citireLDMasiniDinFisier(const char* numeFisier) {
//	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
//	//prin apelul repetat al functiei citireMasinaDinFisier()
//	//ATENTIE - la final inchidem fisierul/stream-ul
//	FILE* f;
//	f = fopen(numeFisier, "r");
//	ListaDubla lista;
//	lista.prim = NULL;
//	lista.ultim = NULL;
//	if (f == NULL)
//	{
//		printf("Fisierul nu s a putut deschide cu succes!");
//		return;
//	}
//	while (!feof(f))
//	{
//		adaugaMasinaInLista(&lista, citireMasinaDinFisier(f));
//	}
//	fclose(f);
//	return lista;
//}
//
//void dezalocareLDMasini(ListaDubla* lista) {
//	//sunt dezalocate toate masinile si lista dublu inlantuita de elemente
//	Nod* p = lista->prim;
//	while (p != NULL)
//	{
//		Nod* temp = p;
//		p = p->next;
//		free(temp->info.model);
//		free(temp->info.numeSofer);
//		free(temp);
//	}
//	lista->prim = NULL;
//	lista->ultim = NULL;
//}
//
//float calculeazaPretMediu(ListaDubla lista) {
//	//calculeaza pretul mediu al masinilor din lista.
//	Nod* prim = lista.prim;
//	float pret = 0;
//	int index = 0;
//	while (prim != NULL)
//	{
//		pret += prim->info.pret;
//		index++;
//	}
//	return pret/index;
//}
//
//void stergeMasinaDupaID(ListaDubla* lista, int id) {
//	//sterge masina cu id-ul primit.
//	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
//	//prima pozitie
//	if (lista == NULL || lista->prim == NULL) {
//		return;
//	}
//	Nod* nod = lista->prim;
//	while (nod != NULL) {
//		if (nod->info.id == id) {
//			Nod* aux = nod;
//			if (nod->prev == NULL) {
//				lista->prim = nod->next;
//			}
//			else {
//				nod->prev->next = nod->next;
//			}
//			if (nod->next == NULL) {
//				lista->ultim = nod->prev;
//			}
//			else {
//				nod->next->prev = nod->prev;
//			}
//			nod = nod->next;
//			free(aux->info.model);
//			free(aux->info.numeSofer);
//			free(aux);
//		}
//		else {
//			nod = nod->next;
//		}
//	}
//}
//
//char* getNumeSoferMasinaScumpa(ListaDubla lista) {
//	//cauta masina cea mai scumpa si 
//	//returneaza numele soferului acestei maasini.
//	Nod* ultim = lista.ultim;
//	float maxim = 0;
//	char* numeSofer = NULL;
//	while (ultim != NULL)
//	{
//		if (maxim < ultim->info.pret)
//		{
//			maxim = ultim->info.pret;
//			free(numeSofer);
//			numeSofer = NULL;
//			numeSofer = malloc(strlen(ultim->info.numeSofer) + 1);
//			strcpy(numeSofer, ultim->info.numeSofer);
//		}
//		ultim = ultim->prev;
//	}
//	return numeSofer;
//}
//int main() {
//	ListaDubla lista = citireLDMasiniDinFisier("masini.txt");
//	afisareListaMasini(lista);
//
//	char* nume = getNumeSoferMasinaScumpa(lista);
//	printf("Nume sofer: %s\n", nume);
//	free(nume);
//	stergeMasinaDupaID(&lista, 5);
//	afisareListaMasini(lista);
//	dezalocareLDMasini(&lista);
//	afisareListaMasini(lista);
//	return 0;
//}