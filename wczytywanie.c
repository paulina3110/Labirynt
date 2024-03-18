#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wczytywanie.h"


labirynt* wczytajlabirynt(const char *nazwa_pliku, int c, int r) {
    FILE *fp = fopen(nazwa_pliku, "r");
    if (fp == NULL) {
        fprintf(stderr, "Nie można otworzyć pliku %s\n", nazwa_pliku);
        return NULL;
    }

    labirynt *lab = malloc(sizeof(labirynt));
    if (lab == NULL) {
        fprintf(stderr, "Błąd alokacji pamięci dla labiryntu.\n");
        fclose(fp);
        return NULL;
    }

    lab->c = c;
    lab->r = 0;
    lab->tab = NULL;

    char buf[1024];
    int j = 0;
    int l = 2;

    lab->tab = malloc(sizeof(char *) * l);
    if (lab->tab == NULL) {
        fprintf(stderr, "Błąd alokacji pamięci dla labiryntu.\n");
        fclose(fp);
        free(lab);
        return NULL;
    }

    while (fgets(buf, 1024, fp) != NULL && j < r) {
        if (j == l) {
            l *= 2;
            lab->tab = realloc(lab->tab, l * sizeof(char *));

            if (lab->tab == NULL) {
                fprintf(stderr, "Błąd alokacji pamięci dla labiryntu.\n");
                fclose(fp);
                zwolnijLabirynt(lab, j);
                return NULL;
            }
        }

        lab->tab[j] = strdup(buf);
        if (lab->tab[j] == NULL) {
            fprintf(stderr, "Błąd alokacji pamięci dla labiryntu.\n");
            fclose(fp);
            zwolnijLabirynt(lab, j);
            return NULL;
        }

        j++;

        if (j % 2 == 0) {
            printf("%s", lab->tab[j-2]);
            printf("%s", lab->tab[j-1]);


            free(lab->tab[j-2]);
            free(lab->tab[j-1]);
        }
    }

    lab->r = j;

    fclose(fp);
    return lab;
}

void zwolnijLabirynt(labirynt *lab, int r) {
    if (lab == NULL) {
        return;
    }

    for (int i = 0; i < r; i++) {
        free(lab->tab[i]);
    }
    free(lab->tab);
    free(lab);
}

