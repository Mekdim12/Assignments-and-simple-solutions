if __name__ == "__main__":
    while True:
        try:
            user_input = eval(input("Enter your desired number please : "))
            if user_input < 0:
                break
            result = user_input * 2
            print("The result is:", result)
        except Exception:
            print("Invalid input, please enter a number")
            break

