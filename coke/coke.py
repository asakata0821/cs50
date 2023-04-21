paid = 0

while paid < 50:
    insert = int(input("Insert a coin: "))

    if insert != 25 and insert != 10 and insert != 5:
        paid = paid + 0
        due = 50 - paid
        print(f"Amount due: {due}")

    else:
        paid = paid + insert
        due = 50 - paid
        if paid >= 50:
            change = paid - 50
            print(f"Change owed: {change}")
        else:
            print(f"Amount due: {due}")









