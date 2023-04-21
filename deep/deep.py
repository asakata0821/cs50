answer = input("The Answer to the Great Question: ").lower().strip()

match answer:
    case "42" | "forty two" | "forty-two":
        print("Yes")
    case _:
        print("No")