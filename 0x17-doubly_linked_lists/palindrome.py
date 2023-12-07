#!/usr/bin/python3

# largest palindrome made from the product of two 3-digit numbers
def is_palindrome(number):
    return str(number) == str(number)[::-1]

def find_largest_palindrome():
    max_palindrome = 0
    for i in range(100, 1000):
        for j in range(i, 1000):
            product = i * j
            if is_palindrome(product) and product > max_palindrome:
                max_palindrome = product
    return max_palindrome

# Find the largest palindrome
result = find_largest_palindrome()

# Save the result in the specified file
with open("102-result", "w") as file:
    file.write(str(result))
