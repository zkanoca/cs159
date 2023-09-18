 #include <stdio.h>

// Constants
#define USD_TO_CAD 1.35  //1 USD = 1.35 CAD
#define GALLON_TO_LITERS 3.785 //1 gallon = 3.785 liters
#define GALLON_TO_BARREL 31.5  // 1 barrel = 31.5 gallons

int main()
{
    // Variable declarations
    int startingCurrency;  // Starting currency (1-USD, 2-CAD)
    int startingUnit;      // Starting unit (1-g, 2-l, 3-b)
    double price;             // Entered price
    double pricePerGallonUSD; // Price per gallon in USD
    double pricePerGallonCAD; // Price per gallon in CAD
    double pricePerLiterUSD;  // Price per liter in USD
    double pricePerLiterCAD;  // Price per liter in CAD
    double pricePerBarrelUSD; // Price per barrel in USD
    double pricePerBarrelCAD; // Price per barrel in CAD

    // User inputs
    printf("Enter starting currency (1-USD, 2-CAD) -> ");
    scanf("%lf", &startingCurrency);
    printf("Enter starting unit (1-g, 2-l, 3-b) -> ");
    scanf("%lf", &startingUnit);
    printf("Enter current price per %c (%s) -> ",
           (startingUnit == 1 ? 'g' : (startingUnit == 2 ? 'l' : 'b')),
           (startingCurrency == 1 ? "USD" : "CAD"));
    scanf("%lf", &price);

    // Convert to USD and gallons
    pricePerGallonUSD = price / (startingUnit == 1 ? 1 : (startingUnit == 2 ? GALLON_TO_LITERS : GALLON_TO_BARREL));
    pricePerGallonUSD /= (startingCurrency == 1 ? 1 : USD_TO_CAD);

    // Calculate other units and currencies
    pricePerGallonCAD = pricePerGallonUSD * USD_TO_CAD;
    pricePerLiterUSD = pricePerGallonUSD / GALLON_TO_LITERS;
    pricePerLiterCAD = pricePerGallonCAD / GALLON_TO_LITERS;
    pricePerBarrelUSD = pricePerGallonUSD * GALLON_TO_BARREL;
    pricePerBarrelCAD = pricePerGallonCAD * GALLON_TO_BARREL;

    // Formatted Output 
    printf("\n");
    printf("--- Unit --- USD ----- CAD ---\n");
    printf("Gallon:  $  %6.2lf   $  %6.2lf\n", pricePerGallonUSD, pricePerGallonCAD);
    printf("Liter:   $  %6.2lf   $  %6.2lf\n", pricePerLiterUSD, pricePerLiterCAD);
    printf("Barrel:  $  %6.2lf   $  %6.2lf\n", pricePerBarrelUSD, pricePerBarrelCAD);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    return 0;
}
