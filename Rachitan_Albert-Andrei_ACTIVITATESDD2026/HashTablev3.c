//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//typedef struct Televizor Televizor;
//typedef struct Nod Nod;
//typedef struct ListaDubla ListaDubla;
//struct Televizor
//{
//	char* producator;
//	int greutate;
//	float diagonala; //inch
//};
//struct Nod
//{
//	Nod* next;
//	Nod* prev;
//	Televizor info;
//};
//
//struct ListaDubla
//{
//	Nod* prim;
//	Nod* ultim;
//};
//
//void inserareListaDublaLaInceput(ListaDubla* listaDubla, Televizor televizor)
//{
//	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
//	nodNou->info = televizor;
//	nodNou->next = listaDubla->prim;
//	nodNou->prev = NULL;
//	listaDubla->prim = nodNou;
//}
////void inserareListaDublaLaFinal(ListaDubla* listaDubla, Televizor televizor)
////{
////	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
////	nodNou->next = NULL;
////	nodNou->prev = listaDubla->ultim;
////	listaDubla->ultim = nodNou;
////}
//void afisareTelevizor(Televizor televizor)
//{
//	printf("Producator: %s\n", televizor.producator);
//	printf("Greutate: %d\n", televizor.greutate);
//	printf("Diagonala: %4.2f\n\n\n", televizor.diagonala);
//}
//void afisareListaMasini(ListaDubla listaDubla)
//{
//	Nod* temp = listaDubla.prim;
//	while (temp != NULL)
//	{
//		afisareTelevizor(temp->info);
//		temp = temp->next;
//	}
//}
//Televizor citireFisier(FILE* f)
//{
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, f);
//	char* aux;
//	Televizor t1;
//	aux = strtok(buffer, sep);
//	t1.producator = (char*)malloc(strlen(aux) + 1);
//	strcpy(t1.producator,aux);
//	t1.greutate = atoi(strtok(NULL, sep));
//	t1.diagonala = atof(strtok(NULL, sep));
//
//	return t1;
//}
//
//ListaDubla initializareListaDubla(const char* numeFisier)
//{
//	FILE* f = fopen(numeFisier, "r");
//	ListaDubla listaDubla;
//	listaDubla.prim = NULL;
//	listaDubla.ultim = NULL;
//	if (f == NULL)
//	{
//		printf("Fisierul nu s a putut deschide cu succes! ");
//		return listaDubla;
//	}
//	while(!feof(f))
//	{
//		inserareListaDublaLaInceput(&listaDubla, citireFisier(f));
//	}
//	fclose(f);
//	return listaDubla;
//}
//char* celMaiMicTelevizor(ListaDubla listaDubla)
//{
//
//
//	Nod* temp = listaDubla.prim;
//	float minim = temp->info.diagonala;
//	char* numeProducator = (char*)malloc(strlen(temp->info.producator) + 1);
//	strcpy(numeProducator, temp->info.producator);
//	while (temp != NULL)
//	{
//		if (minim > temp->info.diagonala)
//		{
//			minim = temp->info.diagonala;
//			free(numeProducator);
//			numeProducator = NULL;
//			numeProducator = (char*)malloc(strlen(temp->info.producator) + 1);
//			strcpy(numeProducator,temp->info.producator);
//		}
//		temp = temp->next;
//	}
//	return numeProducator;
//}
//Televizor cautaTelevizor(const char* producator, ListaDubla listaDubla)
//{
//	Nod* temp = listaDubla.prim;
//	Televizor t1;
//	t1.diagonala = 0;
//	t1.greutate = 0;
//	t1.producator = NULL;
//	while (temp != NULL)
//	{
//		if (strcmp(temp->info.producator, producator) == 0)
//		{
//			t1.diagonala = temp->info.diagonala;
//			t1.greutate = temp->info.greutate;
//			t1.producator = (char*)malloc(strlen(temp->info.producator) + 1);
//			strcpy(t1.producator, temp->info.producator);
//			return t1;
//		}
//		temp = temp->next;
//	}
//	return t1;
//}
//Televizor** deepCopyVector(ListaDubla listaDubla, int* nrTelevizoare)
//{
//	Nod* temp = listaDubla.prim;
//	while (temp != NULL)
//	{
//		(*nrTelevizoare)++;
//		temp = temp->next;
//	}
//	Televizor* vectorTelevizoare = malloc(sizeof(Televizor) * (*nrTelevizoare));
//	Nod* temp2 = listaDubla.prim;
//	int index = 0;
//	while (temp2 != NULL)
//	{
//		Televizor t1;
//		t1.diagonala = temp2->info.diagonala;
//		t1.greutate = temp2->info.greutate;
//		t1.producator = (char*)malloc(strlen(temp2->info.producator) + 1);
//		strcpy(t1.producator, temp2->info.producator);
//		vectorTelevizoare[index] = t1;
//		temp2 = temp2->next;
//		index++;
//	}
//	return &vectorTelevizoare;
//}
//void dezalocareVector(int* nrTelevizoare, Televizor** televizor)
//{
//	for (int i = 0; i < nrTelevizoare; i++)
//	{
//		free((*televizor)[i].producator);
//	}
//	free(*televizor);
//	nrTelevizoare = 0;
//}
//void dezalocareListaDubla(ListaDubla* listaDubla)
//{
//	Nod* temp = listaDubla->prim;
//	while (temp != NULL)
//	{
//		Nod* aux = temp;
//		temp = temp->next;
//		free(aux->info.producator);
//		free(aux);
//	}
//	listaDubla->prim = NULL;
//	listaDubla->ultim = NULL;
//}
//int main()
//{
//	ListaDubla listaDubla = initializareListaDubla("televizor.txt");
//	afisareListaMasini(listaDubla);
//	printf("Producatorul cu cel mai mic televizor este: %s\n\n\n\n", celMaiMicTelevizor(listaDubla));
//	afisareTelevizor(cautaTelevizor("Tataie", listaDubla));
//	int nrTelevizoare = 0;
//	Televizor** televizor = deepCopyVector(listaDubla, &nrTelevizoare);
//	for (int i = 0; i < nrTelevizoare; i++)
//	{
//		afisareTelevizor((*televizor)[i]);
//	}
//	dezalocareVector(nrTelevizoare, televizor);
//	for (int i = 0; i < nrTelevizoare; i++)
//	{
//		afisareTelevizor((*televizor)[i]);
//	}
//	dezalocareListaDubla(&listaDubla);
//	afisareListaMasini(listaDubla);
//	return 0;
//}
