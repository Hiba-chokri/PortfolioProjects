#define the functions add,sub,mul,div
#print options to user
#ask for values
#call the functions
#while looop until the user wants to excit
def add(a, b):
    answer = a + b
    print(a,"+",b,"=",answer)

def sub(a, b):
    answer = a - b
    print(a,"-",b,"=",answer)

def mul(a, b):
    answer = a * b
    print(a,"*",b,"=",answer)

def div(a, b):
    answer = a / b
    print(a,"/",b,"=",answer)


while True:
    print("A.Addition")
    print("S. Subtraction")
    print("M. Multiplication")
    print("D. Division")
    print("E. Exit")

    choice = input("Enter your choice: ")

    if choice == "a" or choice =="A":
        print("A.Addition")
        a = int(input("Enter first number: "))
        b = int(input("Enter second number: "))
        add(a, b)
    elif choice =="s" or choice =="S":
        print("S.Subtraction")
        a = int(input("Enter first number: "))
        b = int(input("Enter second number: "))
        sub(a, b)
    elif choice=="m" or choice=="M":
        print("M.Multiplication")
        a = int(input("Enter first number: "))
        b = int(input("Enter second number: "))
        mul(a ,b)
    elif choice=="d" or choice=="D":
        print("D.Division")
        a = int(input("Enter first number: "))
        b = int(input("Enter second number: "))
        div(a, b)
    elif choice=="e" or choice=="E":
        print("Exit")
        quit()


