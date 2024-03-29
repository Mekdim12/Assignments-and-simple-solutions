if __name__ == "__main__":
    try:
        user_input = eval(input("Enter an Integer: "))
        # TODO: just check if use incase press even number minus to make it odd probably not requested so ask bemnet later
        if user_input % 2 == 0:
            user_input -= 1

        for i in range(1, user_input, 2):
            print(i)

    except Exception:
        print("Invalid input, please enter a number")
        exit()
