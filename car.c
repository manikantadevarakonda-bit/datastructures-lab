#include <stdio.h>
struct Car {
    int carID;
    char model[50]; 
    float rentalRatePerDay;
};
int main() {
    struct Car cars[3];
    int rentalDays;
    for (int i = 0; i < 3; i++) {
        printf("Input details for Car %d:\n", i + 1);
        printf("Car ID: ");
        scanf("%d", &cars[i].carID);
        printf("Model: ");
        scanf("%s", cars[i].model);
        printf("Rental Rate per Day: ");
        scanf("%f", &cars[i].rentalRatePerDay);
        printf("\n");
    }
    printf("Enter the number of rental days: ");
    scanf("%d", &rentalDays);
    printf("\n--- Rental Cost Details for %d Days ---\n", rentalDays);
    for (int i = 0; i < 3; i++) {
        float totalCost = cars[i].rentalRatePerDay * rentalDays;
        printf("Car %d (Model: %s, ID: %d): Total Rental Cost = $%.2f\n",
               i + 1, cars[i].model, cars[i].carID, totalCost);
    }
    return 0;
}
