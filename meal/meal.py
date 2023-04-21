def main():
    time = input("What time is it now? ")
    convertedtime = convert(time)
    whichmeal(convertedtime)

def convert(time):
    time = time.split(":")
    hour = float(time[0])
    minute = (float(time[1]) / 60)
    time = round((hour + minute), 2)

    return time

def whichmeal(time):
    if time >= 7 and time <= 8:
        print("breakfast time")

    if time >= 12 and time <= 13:
        print("lunch time")

    if time >= 18 and time <= 19:
        print("dinner time")

if __name__ == "__main__":
    main()
