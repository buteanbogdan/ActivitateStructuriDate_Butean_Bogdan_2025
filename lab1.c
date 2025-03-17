#include<stdio.h>
#include<stdlib.h>


struct Laptop {
	int id;
	int RAM;
	char* producator;
	float pret;
	char model;
};

struct Laptop initializare(int id, int ram,const char* producator, float pret, char model) {
	struct Laptop l;
	l.id = id;
	l.RAM = ram;
	l.producator = (char*)malloc(sizeof(char)*(strlen(producator)+1));
	strcpy_s(l.producator, strlen(producator) + 1, producator);
	l.pret = pret;
	l.model = model;
	return l;
}

void afisare(struct Laptop l) {
	
}

void modifica_Atribut(struct Laptop l) {

}


void dezalocare(struct Laptop* l) {

}

int main() {
	struct Laptop l;
	return 0;
}