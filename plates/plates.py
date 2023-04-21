def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):

    for i in range(len(s)):
        if s[i] == ',' or s[i] == '.':
            return False

        if s[i].isdigit():

            if int(s[i]) == 0:
                return False
            elif s[i+1].isalpha == True:
                return False



    if len(s) < 2 or len(s) > 6:
        return False

    elif s[0].isdigit() or s[1].isdigit():
        return False

    elif s.isalnum() == False:
        return False

    else:
        return True


main()