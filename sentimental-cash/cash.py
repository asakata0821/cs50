from cs50 import get_float
import math


def main():
    cents = get_cents()

    quarters = calculate_quarters(cents)

    dimes = calculate_dimes(cents, quarters)

    nickels = calculate_nickels(cents, quarters, dimes)

    pennies = calculate_pennies(cents, quarters, dimes, nickels)

    print("Total: ", quarters + dimes + nickels + pennies)


def get_cents():
    while True:
        cents = get_float("Change owed: ")
        if cents > 0:
            break
    cents = round(cents * 100)
    return cents


def calculate_quarters(cents):
    quarters = cents / 25
    return math.floor(quarters)


def calculate_dimes(cents, quarters):
    dimes = (cents - (quarters*25)) / 10
    return math.floor(dimes)


def calculate_nickels(cents, quarters, dimes):
    nickels = (cents - (quarters * 25) - (dimes * 10)) / 5
    return math.floor(nickels)


def calculate_pennies(cents, quarters, dimes, nickels):
    pennies = (cents - (quarters * 25) - (dimes * 10) - (nickels * 5)) / 1
    return math.floor(pennies)


main()