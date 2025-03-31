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
	printf("%d. Laptopul %s seria %c are %d GB RAM, costa %5.2f RON\n", l.id, l.producator, l.model, l.RAM, l.pret);
}

void modificaPret(struct Laptop l, float noulPret) {
	if (noulPret > 0) {
		l.pret = noulPret;
	}

}


void dezalocare(struct Laptop* l) {

}

int main() {
	struct Laptop l;
	l = initializare(1, 16, "Dell", 4000.5, 'S');
	afisare(l);
	return 0;
}