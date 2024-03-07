#include <stdio.h>
#include <string.h>

#define MAX_CARS 5
typedef struct {
    char brand[20];
    char country_of_origin[20];
    int price;
    int max_speed;
    int range;
} Car;

Car cars[MAX_CARS];

int search_cars(char *brand) {
    for (int i = 0; i < MAX_CARS; i++) {
        if (strcmp(cars[i].brand, brand) == 0) {
            return i;
        }
    }
    return -1;
}

void read_car_data(Car *car) {
    printf("Enter the brand of the car: ");
    scanf("%s", car->brand);
    printf("Enter the country of origin of the car: ");
    scanf("%s", car->country_of_origin);
    printf("Enter the price of the car: ");
    scanf("%d", &car->price);
    printf("Enter the max speed of the car: ");
    scanf("%d", &car->max_speed);
    printf("Enter the fuel range of the car: ");
    scanf("%d", &car->range);
}

void display_car_data(Car *car) {
    printf("\nBrand: %s\n", car->brand);
    printf("Country of Origin: %s\n", car->country_of_origin);
    printf("Price: %d\n", car->price);
    printf("Max Speed: %d\n", car->max_speed);
    printf("Fuel Range: %d\n", car->range);
}

int main() {
    for (int i = 0; i < MAX_CARS; i++) {
        printf("\nEnter data for Car %d:\n", i + 1);
        read_car_data(&cars[i]);
    }

    printf("\nDisplaying Car Data:\n");
    for (int i = 0; i < MAX_CARS; i++) {
        printf("\nCar %d:\n", i + 1);
        display_car_data(&cars[i]);
    }

    char search_brand[20];
    printf("\nEnter the brand of the car you are searching for: ");
    scanf("%s", search_brand);

    int pos = search_cars(search_brand);
    if (pos != -1) {
        printf("Car with brand %s was found at position %d.\n", search_brand, pos + 1);
        printf("Details of the car:\n");
        display_car_data(&cars[pos]);
    } else {
        printf("Car with brand %s was not found in the array.\n", search_brand);
    }

    return 0;
}


