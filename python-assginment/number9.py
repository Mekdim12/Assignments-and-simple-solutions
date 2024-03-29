# noqa
class Factorial:
    def calculate_factorial_using_function_only(self, number_to_calculate_factorial):
        # TODO: emlsbeshalhuegn
        pass


    def calculate_factorial_using_recursion(self, number_to_calculate_factorial):
        if number_to_calculate_factorial == 0:
            return 1
        else:
            return number_to_calculate_factorial * self.calculate_factorial_using_recursion(number_to_calculate_factorial - 1) 
    
    def calculate_factorial_from_two_number(self, n1, n2):
        factorial_list = []
        for num in range(n1, n2+1):
            factorial = 1
            for num in range(1, num + 1):
                factorial = factorial * num

            factorial_list.append(factorial)
        return factorial_list
    
    
if __name__ == '__main__':
    factorial_object = Factorial()
    user_input_number = eval(input("Enter the number to calculate factorial for N1: "))
    user_input_number2 = eval(input("Enter the number to calculate factorial for N2: "))

    factorial = 1
    '''
        5 4 3 2 1
        20 6 1
        120

        5! = 5 * 4 * 3 * 2 * 1 = 120 got it
    '''
    for num in range(1, user_input_number + 1):
        factorial = factorial * num
    print(f"A. Factorial of {user_input_number} is {factorial}")
    print(f"B. ")
    print(f"C. Factorial of {user_input_number} is {factorial_object.calculate_factorial_using_recursion(user_input_number)}")
    print(f"D. Factorial of number between is {factorial_object.calculate_factorial_from_two_number(user_input_number, user_input_number2)}")