str = input("Tweet: ")

vowels = ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')
result = ''

for i in range(len(str)):
    if str[i] not in vowels:
        result = result + str[i]
print(result)




    for i in range(len(s)):
        if s[i].isdigit():
            if int(s[i]) == 0:
                return False
            elif s[i+1].isalpha == True:
                return False
            else:
                break