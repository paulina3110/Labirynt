#ifndef WCZYTYWANIE_H
#define WCZYTYWANIE_H

typedef struct {
    int r;
    int c;
    char **tab;
} labirynt;

labirynt *wczytajlabirynt(const char *nazwa_pliku, int c, int r);
void zwolnijLabirynt(labirynt *labirynt, int r);


#endif

