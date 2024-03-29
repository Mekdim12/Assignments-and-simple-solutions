# Differentiate between mutable and immutable objects in Python language with example.

'''
Immutable objects: These are of types that cannot be changed after they are created. If you try to change their state, you would be creating a new object instead. Examples of immutable objects include:


int
float
bool
str
tuple

'''
# Immutable object (string)
name = "John"
print("Before modification:", name)

# Attempt to modify the string
name[0] = "M"  # This will raise an error


'''
Mutable objects: These are of types that can be changed after they are created. Examples of mutable objects include:
list
dict
set

'''
# Mutable object (list)
numbers = [1, 2, 3, 4, 5]
print("Before modification:", numbers)

# Modify the list
numbers[0] = 10
print("After modification:", numbers)