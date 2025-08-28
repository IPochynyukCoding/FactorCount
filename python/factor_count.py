from math import isqrt
def main():
    potential = ""
    while potential != "q":
        potential = input("Please input a number to check for prime or press 'q' to quit: ")
        factors = []
        if potential.lower() == "q":
            quit()
        try:
            potential_num =int(potential)
        except:
            print("Please input your number in integer form.")
        else:
            if potential_num < 1:
                print("This number is not prime.")
            else:
                for number in range(1,isqrt(potential_num)+1):
                    if potential_num % number == 0:
                        factors.append(number)
                        factors.append(potential_num//number)
                factors = list(set(factors))
                factors.sort()
                print(f"The factors of {potential_num} are: {factors}")
                if len(factors) == 2:
                    print(f"The number is prime, because it has {len(factors)} factors.")
                else:
                    print(f"The number is not prime, because it has {len(factors)} factors.")
if __name__ == "__main__":
    main()