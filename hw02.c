#include <stdio.h>

#define USD_TO_CAD 1.35        // 1 USD = 1.35 CAD
#define GALLON_TO_LITERS 3.785 // 1 gallon = 3.785 liters
#define BARREL_TO_GALLON 31.5  // 1 barrel = 31.5 gallons

int main()
{
    int startingCurrency;
    int startingUnit;
    double price;
    double unitToGallonConversion;
    double currencyToUSDConversion;
    double pricePerGallonUSD; // Price per gallon in USD
    double pricePerGallonCAD; // Price per gallon in CAD
    double pricePerLiterUSD;  // Price per liter in USD
    double pricePerLiterCAD;  // Price per liter in CAD
    double pricePerBarrelUSD; // Price per barrel in USD
    double pricePerBarrelCAD; // Price per barrel in CAD

    printf("Enter starting currency (1-USD, 2-CAD) -> ");
    scanf("%d", &startingCurrency);

    printf("Enter starting unit (1-g, 2-l, 3-b) -> ");
    scanf("%d", &startingUnit);

    // Calculate the 1 or 0 indicators for currency and unit
    // without using relational or logical operators
    int currencyUSDIndicator = 1 - (startingCurrency - 1); // 1 for 1;  0 for 2
    int currencyCADIndicator = (startingCurrency - 1);     // 1 for 2;  0 for 1

    int unitGallonIndicator = ((startingUnit - 2) * (startingUnit - 3)) / 2;
    int unitLiterIndicator = ((startingUnit - 1) * (startingUnit - 3)) / (-1);
    int unitBarrelIndicator = ((startingUnit - 1) * (startingUnit - 2)) / 2;

    // Selection by calculation for currency and unit symbols
    char currencyFirstLetter = 'U' * currencyUSDIndicator + 'C' * currencyCADIndicator;
    char currencySecondLetter = 'S' * currencyUSDIndicator + 'A' * currencyCADIndicator;

    char unitSymbol = 'g' * unitGallonIndicator + 'l' * unitLiterIndicator + 'b' * unitBarrelIndicator;

    printf("Enter current price per %c (%c%cD) -> ", unitSymbol, currencyFirstLetter, currencySecondLetter);
    scanf("%lf", &price);

    // Calculations for unit conversion to gallon
    unitToGallonConversion = 1 * unitGallonIndicator + GALLON_TO_LITERS * unitLiterIndicator + BARREL_TO_GALLON * unitBarrelIndicator;

    // Calculations for currency conversion to USD
    currencyToUSDConversion = 1 * currencyUSDIndicator + USD_TO_CAD * currencyCADIndicator;

    // Calculate the price per gallon in USD
    pricePerGallonUSD = price / unitToGallonConversion;
    pricePerGallonUSD /= currencyToUSDConversion;

    // Calculate other units and currencies
    pricePerGallonCAD = pricePerGallonUSD * USD_TO_CAD;
    pricePerLiterUSD = pricePerGallonUSD / GALLON_TO_LITERS;
    pricePerLiterCAD = pricePerGallonCAD / GALLON_TO_LITERS;
    pricePerBarrelUSD = pricePerGallonUSD * BARREL_TO_GALLON;
    pricePerBarrelCAD = pricePerGallonCAD * BARREL_TO_GALLON;

    // Formatted Output
    printf("\n");
    printf("--- Unit --- USD ----- CAD ---\n");
    printf("Gallon:  $  %6.2lf   $  %6.2lf\n", pricePerGallonUSD, pricePerGallonCAD);
    printf("Liter:   $  %6.2lf   $  %6.2lf\n", pricePerLiterUSD, pricePerLiterCAD);
    printf("Barrel:  $  %6.2lf   $  %6.2lf\n", pricePerBarrelUSD, pricePerBarrelCAD);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    return 0;
}
