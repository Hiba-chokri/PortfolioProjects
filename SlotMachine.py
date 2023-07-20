MAX_LINES = 3
MAX_BET = 100
MIN_BET =  1
def deposit():
    while True:
        amount = input("What would you like to enter ? ")
        if amount.isdigit():
            amount = int(amount)
            if amount > 0:
                break
            else:
                print("amount must be greater than 0")
        else:
            print("Please enter a digit,Thanks")
    
    return amount


def get_number_of_lines():
    while True:
        lines = input("Enter the number of lines to bet on (1-" + str(MAX_LINES) + ")? ")
        if lines.isdigit():
            lines = int(lines)
            if 1 <= lines <= MAX_LINES:
                break
            else:
                print("Enter a valid number of lines .")
        else:
            print("Please enter a digit")

    return lines


def get_bet():
    while True:
            amount = input("what woud you like to bet on each line ? ")
            if amount.isdigit():
                amount = int(amount)
                if MIN_BET <= amount <= MAX_BET:
                    break
                else:
                    print(f"amount must be between {MIN_BET} - {MAX_BET}")
            else:
                print("enter a valid amount please")

    return amount


def main():
    balance = deposit()
    lines =get_number_of_lines()
    while True:
        bet = get_bet()
        total_bet = bet * lines
        if total_bet > balance:
            print(f"your bet can't be greater than your current balance,your balance is {balance}")
        else:
            break
        
    print(f"you are bettig {bet} on each {lines} lines ,Total bet is equal to: {total_bet}")


main()