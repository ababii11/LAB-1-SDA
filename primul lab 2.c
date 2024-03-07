#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char brand[20];
    char model[20];
    char colour[20];
    char country_of_origin[20];
    int range;
    int price;
} cars;

void read_car_data( int n, cars *c ) {
    for ( int i=0; i<n; i++) {
        printf("For car nr  %d introduce\n: ", i+1);
        printf("Brand "); scanf("%s", c[i].brand);
        printf("Model "); scanf("%s", c[i].model);
        printf("Colour "); scanf("%s", c[i].colour);
        printf("Country_of_origin "); scanf("%s", c[i].country_of_origin);
        printf("Range "); scanf("%d", &c[i].range);
        printf("Price "); scanf("%d", &c[i].price);
    }
}

void display_car_data( int n, cars *c) {
    for ( int i=0; i<n; i++) {
        printf("Cars:              %d\n", i+1);
        printf("Brand:             %s\n", c[i].brand);
        printf("Model:             %s\n", c[i].model);
        printf("Colour:            %s\n", c[i].colour);
        printf("Country_of_origin: %s\n", c[i].country_of_origin);
        printf("Range:             %d\n", c[i].range);
        printf("Price:             %d\n", c[i].price);
        printf("\n");
    }
}

void Searchword( int n, cars *c, char m[20]) {
    for (int i=0; i<n; i++) {
        if (strcmp(c[i].brand, m)==0  || strcmp(c[i].model, m)==0 || strcmp(c[i].colour, m)==0 || strcmp(c[i].country_of_origin, m)==0 ) {
            printf("The car with this characteristichs has the index %d", i+1);
            break;
        }
    }
}

int Searchnumber( int n, cars *c, int m) {
    for (int i=0; i<n; i++) {
        if (m == c[i].range || m == c[i].price ) {
            printf("The car with this characteristichs has the index %d", i+1);
            break;
        }
    }
}

void Freememory(cars *c) {
    free(c);
}

int SortRange(int n, cars *c) {
    int t;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
           if(c[i].range > c[j].range) {
               t = c[i].range;
               c[i].range = c[j].range;
               c[j].range = t;
           }
        }
    }
    display_car_data(n, c);
}

int SortPrice(int n, cars *c) {
    int t;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
           if(c[i].price > c[j].price) {
               t = c[i].price;
               c[i].price = c[j].price;
               c[j].price = t;
           }
        }
    }
    display_car_data(n, c);
}

void SortBrand(int n, cars *c) {
    char t[20];
    for (int i = 0; i < n - 1; i++) {
            if (strcmp(c[i].brand, c[i + 1].brand) > 0) {
                strcpy(c[i].brand, t);
                strcpy(c[i + 1].brand, c[i].brand);
                strcpy(t, c[i + 1].brand);
            }
        }
    display_car_data(n, c);
}

void SortColour(int n, cars *c) {
    char t[20];
    for (int i = 0; i < n - 1; i++) {
            if (strcmp(c[i].colour, c[i + 1].colour) > 0) {
                strcpy(c[i].colour, t);
                strcpy(c[i + 1].colour, c[i].colour);
                strcpy(t, c[i + 1].colour);
            }
        }
    display_car_data(n, c);
}

void SortCountry_of_origin(int n, cars *c) {
    char t[20];
    for (int i = 0; i < n - 1; i++) {
            if (strcmp(c[i].country_of_origin, c[i + 1].country_of_origin) > 0) {
                strcpy(c[i].country_of_origin, t);
                strcpy(c[i + 1].country_of_origin, c[i].country_of_origin);
                strcpy(t, c[i + 1].country_of_origin);
            }
        }
    display_car_data(n, c);
}

cars *InsertBack(int *n, cars *c) {
    (*n)++;
    c = realloc(c, (*n + 1) * sizeof(cars));
    printf("For a new position introduce: ");
    printf("Brand ");
    scanf("%s", c[*n].brand);
    printf("Model ");
    scanf("%s", c[*n].model);
    printf("Colour ");
    scanf("%s", c[*n].colour);
    printf("Country_of_origin. ");
    scanf("%s", c[*n].country_of_origin);
    printf("Range ");
    scanf("%d", &c[*n].range);
    printf("Price ");
    scanf("%d", &c[*n].price);
    return c;
}

cars *InsertFront(int *n, cars *c) {
    (*n)++;
    c = realloc(c, (*n) * sizeof(cars));
    for (int i = *n - 1; i > 0; i--) {
        c[i] = c[i - 1];
    }
    printf("For a new car introduce: ");
    printf("Brand ");
    scanf("%s", c[0].brand);
    printf("Model ");
    scanf("%s", c[0].model);
    printf("Colour ");
    scanf("%s", c[0].colour);
    printf("Country_of_origin ");
    scanf("%s", c[0].country_of_origin);
    printf("Range ");
    scanf("%d", &c[0].range);
    printf("Price ");
    scanf("%d", &c[0].price);
    return c;
}

cars *InsertPosition(int *n, cars *c, int a) {
    (*n)++;
    c = realloc(c, (*n) * sizeof(cars));
    for (int i = *n - 1; i > a; i--) {
        c[i] = c[i - 1];
    }
    printf("For a new car introduce: ");
    printf("Brand ");
    scanf("%s", c[a].brand);
    printf("Model ");
    scanf("%s", c[a].model);
    printf("Colour ");
    scanf("%s", c[a].colour);
    printf("Country_of_origin");
    scanf("%s", c[a].country_of_origin);
    printf("Range ");
    scanf("%d", &c[a].range);
    printf("Price ");
    scanf("%d", &c[a].price);
    return c;
}

cars *DeletePosition(int *n, cars *c, int a) {
    for (int i = a; i < *n - 1; i++) {
        c[i] = c[i + 1];
    }
    (*n)--;
    c = realloc(c, (*n) * sizeof(cars));
    return c;
}

int main() {
    int n, k, t, p, a;
    char m[20];
    printf("Introduce the number of cars you want to record: ");
    scanf("%d", &n);
    cars *c = (cars *)malloc(n * sizeof(cars));
    read_car_data(n, c);
    display_car_data(n, c);
    printf("What is your move?\n");
    printf("1) Search for a car\n");
    printf("2) Free memory\n");
    printf("3) Sort by a characteristichs\n");
    printf("4) Insert at back\n");
    printf("5) Insert at front\n");
    printf("6) Insert at x position\n");
    printf("7) Delete at x position\n");
    scanf("%d", &p);
        switch (p) {
            case 1:
                printf("What do you want to search?\n");
                printf("For brand introduce 1\n");
                printf("for model introduce 2\n");
                printf("For colour introduce 3\n");
                printf("For country_of_origin introduce 4\n");
                printf("For range introduce  5\n");
                printf("For car introduce 6\n");
                scanf("%d", &k);
                if(k==5 || k==6) {
                    printf("Introduce number:  ");
                    scanf("%d", &t);
                    Searchnumber(n, c, t);}
                    else { printf("Introduce name:  ");
                           scanf("%s", m);
                           Searchword(n, c, m); }
                break;
            case 2:
                Freememory(c);
                break;
            case 3:
                printf("Sort after:\n");
                printf("1. Range\n");
                printf("2. Price\n");
                printf("3. Alphabetically by brand\n");
                printf("4. Alphabetically by colour\n");
                printf("5. Alphabetically by country_of_origin\n");
                scanf("%d", &k);
                    if (k == 1) SortRange(n, c);
                    else if (k == 2) SortPrice(n, c);
                    else if (k==3) SortBrand(n, c);
                    else if (k==4) SortColour(n, c);
                    else if (k==5) SortCountry_of_origin(n, c);
                    break;
            case 4:
                c = InsertBack(&n, c);
                read_car_data(n, c);
                break;
            case 5:
                c = InsertFront(&n, c);
                display_car_data(n, c);
                break;
            case 6:
                printf("Enter the index of the car you want to add: ");
                scanf("%d", &a);
                c = InsertPosition(&n, c, a - 1);
                display_car_data(n, c);
                break;
            case 7:
                printf("Enter the index of the car you want to delete: ");
                scanf("%d", &a);
                c = DeletePosition(&n, c, a - 1);
                display_car_data(n, c);
                break;
        }
    free(c);
}
