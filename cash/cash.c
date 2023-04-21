#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
int quarters, dimes, nickels, pennies;

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();


    // Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents);
    printf("Quarters: %d\n", quarters);

    // Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents);
    printf("Dimes: %d\n", dimes);

    // Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents);

    printf("Nickels: %d\n", nickels);

    // Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents);

    printf("Pennies: %d\n", pennies);

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("Total: %i\n", coins);
}

int get_cents()
{
    // TODO
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    return cents;


}

int calculate_quarters(int cents)
{
    // TODO
    quarters = cents / 25;
    return quarters;
}

int calculate_dimes(int cents)
{
    // TODO
    dimes = (cents - quarters * 25) / 10;
    return dimes;
}

int calculate_nickels(int cents)
{
    // TODO
    nickels = (cents - (quarters * 25) - (dimes * 10)) / 5;
    return nickels;
}

int calculate_pennies(int cents)
{
    // TODO
    pennies = cents - (quarters * 25) - (dimes * 10) - (nickels * 5);
    return pennies ;
}