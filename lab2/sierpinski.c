#include <stdio.h>
#include <stdlib.h>

int sort_get_index(float tab[], int top, float val) {
    int i = 0;
    while (tab[i] < val) {
        i++;
        if (i == top) {
            return top;
        }
    }
    return i;
}

void sort_insert_at(float tab[], int i, int top, float val) {
    for (int j = top-1; j>=i; j--) {
        tab[j+1] = tab[j];
    }
    tab[i] = val;
}

void sort_insert(float tab[], int top, float val) {
    int i = sort_get_index(tab, top, val);
    sort_insert_at(tab, i, top, val);
}

int nb_columns() {
    return 32;
}

int nb_lines() {
    return 16;
}

void grid_init(char grid[], char pixel) {
    for (int i=0; i<(nb_columns()*nb_lines()); i++) {
        grid[i] = pixel;
    }
}

void grid_display(char grid[]) {
    for (int i = 0; i<(nb_columns()*nb_lines()); i++) {
        if (i%32 == 31) {
            printf("%c\n", grid[i]);
        } else {
            printf("%c", grid[i]);
        }
    }
}

void plot_point(char grid[], int x, int y, char pixel) {
    int index = (nb_lines()-y-1)*(nb_columns())+x;
    if (x < 0 || y < 0 || x >= nb_columns() || y >= nb_lines()) {
        printf("Error, coordinates not included in the grid.\n");
        exit(EXIT_FAILURE);
    } else {
        grid[index] = pixel;
    }
}

void plot_vline(char grid[], int x, float fy0, float fy1, char pixel) {
    int y0 = fy0+0.5;
    if (fy0 == y0 - 0.5) {
        y0--;
    }
    int y1 = fy1+0.5;
    for (int y = y0; y <= y1; y++) {
        plot_point(grid, x, y, pixel);
    }
}

struct point {
    float x;
    float y;
};

void plot_poly_sweep(char grid[], struct point points[], int nb_points, int x, char pixel) {
    printf("sweep %i:", x);
    int j = nb_points-1;
    for (int i = 0; i < nb_points; i++) {
        if ((points[i].x <= x && x <= points[j].x) || (points[j].x <= x && x <= points[i].x)) {
            printf(" %f", points[i].y + (x - points[i].x) * (points[j].y - points[i].y) / (points[j].x - points[i].x));
        }
        j = i;
    }
    printf("\n");
}

void plot_poly(char grid[], struct point points[], int nb_points, char pixel) {
    for (int x = 0; x < nb_columns(); x++) {
        plot_poly_sweep(grid, points, nb_points, x, pixel);
    }
}

int main(int argc, char* argv[]) {    
    char grid[nb_columns()*nb_lines()];
    grid_init(grid, ' ');
    struct point p[] = {{ 2, 13 }, { 10, 13 }, { 30, 7 }, { 10, 1 }, { 2, 1 }, { 18, 7 }};
    plot_poly(grid, p, 6, '|');
    grid_display(grid);
}