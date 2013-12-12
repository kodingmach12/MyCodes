def label(letters, n):
    result = ''
    while n > 0:
        n -= 1
        char = letters[n % len(letters)]
        result = char + result
        n = n / len(letters)
    return result
s = raw_input("Enter the working chars: ")
n = raw_input("Enter the number of boxes: ")
print label(s,int(n) )