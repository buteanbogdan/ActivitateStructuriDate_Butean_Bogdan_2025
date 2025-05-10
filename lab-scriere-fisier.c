#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StructuraCarte {
	int id;
	int anPublicare;
	float pret;
	char* titlu;
	char* autor;
	char genLiterar;
};
typedef struct StructuraCarte Carte;

void afisareCarte(Carte carte) {
	printf("ID: %d\n", carte.id);
	printf("An publicare: %d\n", carte.anPublicare);
	printf("Pret: %.2f\n", carte.pret);
	printf("Titlu: %s\n", carte.titlu);
	printf("Autor: %s\n", carte.autor);
	printf("Gen: %c\n\n", carte.genLiterar);
}

void afisareVectorCarti(Carte* carti, int nrCarti) {
	for (int i = 0; i < nrCarti; i++) {
		afisareCarte(carti[i]);
	}
}

void adaugaCarteInVector(Carte** carti, int* nrCarti, Carte carteNoua) {
	Carte* aux = (Carte*)malloc(sizeof(Carte) * ((*nrCarti) + 1));
	for (int i = 0; i < *nrCarti; i++) {
		aux[i] = (*carti)[i];
	}
	aux[*nrCarti] = carteNoua;
	free(*carti);
	*carti = aux;
	(*nrCarti)++;
}

Carte citireCarteFisier(FILE* file) {
	Carte c;
	char buffer[100];
	char sep[4] = ",;\n";
	fgets(buffer, 100, file);
	c.id = atoi(strtok(buffer, sep));
	c.anPublicare = atoi(strtok(NULL, sep));
	c.pret = atof(strtok(NULL, sep));
	char* aux;
	aux = strtok(NULL, sep);
	c.titlu = (char*)malloc(strlen(aux) + 1);
	strcpy(c.titlu, aux);
	aux = strtok(NULL, sep);
	c.autor = (char*)malloc(strlen(aux) + 1);
	strcpy(c.autor, aux);
	c.genLiterar = strtok(NULL, sep)[0];
	return c;
}

Carte* citireVectorCartiFisier(const char* numeFisier, int* nrCartiCitite) {
	FILE* file = fopen(numeFisier, "r");
	if (!file) {
		printf("Eroare la deschiderea fisierului!\n");
		return NULL;
	}
	Carte* carti = NULL;
	*nrCartiCitite = 0;
	while (!feof(file)) {
		adaugaCarteInVector(&carti, nrCartiCitite, citireCarteFisier(file));
	}
	fclose(file);
	return carti;
}

void dezalocareVectorCarti(Carte** vector, int* nrCarti) {
	for (int i = 0; i < *nrCarti; i++) {
		free((*vector)[i].titlu);
		free((*vector)[i].autor);
	}
	free(*vector);
	*vector = NULL;
	*nrCarti = 0;
}

int main() {
	int nrCarti = 0;
	Carte* carti = citireVectorCartiFisier("carti.txt", &nrCarti);
	if (carti) {
		afisareVectorCarti(carti, nrCarti);
		dezalocareVectorCarti(&carti, &nrCarti);
	}
	return 0;
}
