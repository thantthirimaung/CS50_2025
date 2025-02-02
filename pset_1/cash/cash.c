#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Calculate how many quarters you should give customer
    // Subtract the value of those quarters from cents
    int quarters = cents / 25;
    cents %= 25;

    // Calculate how many dimes you should give customer
    // Subtract the value of those dimes from remaining cents
    int dimes = cents / 10;
    cents %= 10;

    // Calculate how many nickels you should give customer
    // Subtract the value of those nickels from remaining cents
    int nickels = cents / 5;
    cents %= 5;

    // Calculate how many pennies you should give customer
    // Subtract the value of those pennies from remaining cents
    int pennies = cents;

    // Sum the number of quarters, dimes, nickels, and pennies used
    int total_coins = quarters + dimes + nickels + pennies;

    // Print that sum
    printf("%i\n", total_coins);
}