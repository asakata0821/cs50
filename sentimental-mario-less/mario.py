from cs50 import get_int

while True:
    try:
        n = int(input("Height: "))
        if (n >= 1 and n <= 8):
            break
    except ValueError:
        print("That's not an integer!")
    except (n < 1 and n > 8):
        exit()

for i in range(n):
    for j in range(n):
        if i + j >= n - 1:
            print("#", end="")
        else:
            print(" ", end="")
    print()