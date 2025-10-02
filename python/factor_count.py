from math import isqrt
def main():
    while True:
        potential = input("Please input a number to check for prime or press 'q' to quit: ")
        factors = []
        if potential.lower() == "q":
            quit()
        try:
            potential_num =int(potential)
        except ValueError:
            print("Please input a valid positive integer (number > 0)")
        else:
            if potential_num < 1:
                print("This number cannot be calculated for factors due to being smaller than one.")
            else:
                for number in range(1,isqrt(potential_num)+1):
                    if potential_num % number == 0:
                        factors.append(number)
                        factors.append(potential_num//number)
                factors = sorted(list(set(factors)))
                print(f"The factors of {potential_num} are: {factors}")
                print(f"The number is {'not ' if len(factors) != 2 else ''}prime, because it has {len(factors)} factor(s).")
if __name__ == "__main__":
    main()