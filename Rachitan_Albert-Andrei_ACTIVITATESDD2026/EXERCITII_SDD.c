//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct StructuraMasina {
//    int id;
//    int nrUsi;
//    float pret;
//    char* model;
//    char* numeSofer;
//    unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
//void afisareMasina(Masina masina) {
//    printf("ID: %d\n", masina.id);
//    printf("Numar usi: %d\n", masina.nrUsi);
//    printf("Pret: %4.2f\n", masina.pret);
//    printf("Model: %s\n", masina.model);
//    printf("Nume sofer: %s\n", masina.numeSofer);
//    printf("Serie: %c\n\n", masina.serie);
//}
//
//void afisareVectorMasini(Masina* masini, int nrMasini) {
//    if (masini == NULL)
//        return;
//    for (int i = 0; i < nrMasini; i++) {
//        afisareMasina(masini[i]);
//    }
//}
//
//void adaugaMasinaInVector(Masina** masini, int* nrMasini, Masina masinaNoua) {
//    Masina* temp = (Masina*)realloc(*masini, sizeof(Masina) * ((*nrMasini) + 1));
//    if (temp != NULL) {
//        *masini = temp;
//        (*masini)[*nrMasini] = masinaNoua;
//    }
//}
//
//Masina citireMasinaFisier(FILE* file) {
//    char buffer[100];
//    char sep[] = ",\n";
//    Masina m1;
//
//    fgets(buffer, 100, file);
//
//    char* aux = strtok(buffer, sep);
//    m1.id = atoi(aux);
//
//    aux = strtok(NULL, sep);
//    m1.nrUsi = atoi(aux);
//
//    aux = strtok(NULL, sep);
//    m1.pret = (float)atof(aux);
//
//    aux = strtok(NULL, sep);
//    m1.model = (char*)malloc(strlen(aux) + 1);
//    strcpy(m1.model, aux);
//
//    aux = strtok(NULL, sep);
//    m1.numeSofer = (char*)malloc(strlen(aux) + 1);
//    strcpy(m1.numeSofer, aux);
//
//    aux = strtok(NULL, sep);
//    m1.serie = aux[0];
//
//    return m1;
//}
//
//Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
//    FILE* f = fopen(numeFisier, "r");
//    if (f == NULL)
//        return NULL;
//
//    Masina* masini = NULL;
//
//    while (!feof(f)) {
//        long poz = ftell(f);
//        char test[100];
//        if (fgets(test, 100, f) == NULL)
//            break;
//        fseek(f, poz, SEEK_SET);
//
//        adaugaMasinaInVector(&masini, nrMasiniCitite, citireMasinaFisier(f));
//        (*nrMasiniCitite)++;
//    }
//
//    fclose(f);
//    return masini;
//}
//
//void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
//    if (*vector != NULL) {
//        for (int i = 0; i < *nrMasini; i++) {
//            free((*vector)[i].model);
//            free((*vector)[i].numeSofer);
//        }
//        free(*vector);
//        *vector = NULL;
//        *nrMasini = 0;
//    }
//}
//
//int main() {
//    int nrMasiniCitite = 0;
//    Masina* masini = citireVectorMasiniFisier("masini.txt", &nrMasiniCitite);
//    afisareVectorMasini(masini, nrMasiniCitite);
//    dezalocareVectorMasini(&masini, &nrMasiniCitite);
//    return 0;
//}