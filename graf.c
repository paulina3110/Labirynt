#include <stdio.h>
#include <stdlib.h>
#include "graf.h"

wierz* tworzwierz(int nr, int x, int y) {
	wierz* nowywierz = (wierz*)malloc(sizeof(wierz));
	nowywierz->nr = nr;
	nowywierz->x = x;
	nowywierz->y = y;
	nowywierz->next = NULL;
	return nowywierz;
}

Graf* tworzgraf() {
	Graf* graf = (Graf*)malloc(sizeof(Graf));
	graf->lbwierz = 0;
	graf->ls = NULL;
}

void dodajwierz(Graf* graf, int x, int y) {
	wierz* nowywierz = tworzwierz(graf->lbwierz, x, y);
	
	graf->ls = (wierz**)realloc(graf->ls, (graf->lbwierz + 1) * sizeof(wierz*));

	
	graf->ls[graf->lbwierz] = nowywierz;
	graf->lbwierz++;
}

void dodajkraw(Graf* graf, int x1, int y1, int x2, int y2) {
	//szukamy numeru wierzchołków o podanych współrzędnych P1(x1, y1) i P2(x2, y2), a potem dodajemy połączenie między tymi wierzchołkami
	int s1 = -1;
	int s2 = -1;
    	for (int i = 0; i < graf->lbwierz; i++) {
        	if (graf->ls[i]->x == x1 && graf->ls[i]->y == y1) {
            		s1 = i;
        	}
        	if (graf->ls[i]->x == x2 && graf->ls[i]->y == y2) {
            		s2 = i;
        	}
    	}

    	if (s1 != -1 && s2 != -1) {
               	wierz* pom = graf->ls[s1]->next;
        	while (pom != NULL) {
            		if (pom->nr == s2) {
                		printf("Krawędź już istnieje.\n");
                		return;
            		}
            		pom = pom->next;
        	}

        	wierz* nowywierz = tworzwierz(s2, x2, y2);
        	nowywierz->next = graf->ls[s1]->next;
        	graf->ls[s1]->next = nowywierz;
		
    	} else {
        	printf("Nie znaleziono wierzchołków o podanych współrzędnych.\n");
    	}
}
