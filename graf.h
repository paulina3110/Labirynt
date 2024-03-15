#ifndef GRAF_H
#define GRAF_H

typedef struct wierz {
    int nr;
    int x;
    int y;
    struct wierz* next;
} wierz;

typedef struct Graf {
    int lbwierz;
    wierz** ls;
} Graf;

wierz* tworzwierz(int nr, int x, int y);
Graf* tworzgraf();
void dodajwierz(Graf* graf, int x, int y);
void dodajkraw(Graf* graf, int x1, int y1, int x2, int y2);

#endif
