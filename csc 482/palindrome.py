def palindrome(name, length):
    
    if length < 1:
        return ""
    
    if length == 1:
        return name[0]

    return name[length - 1] + palindrome(name, length - 1)

name = input("")
length = len(name)
reverse = palindrome(name, length)
if name == reverse:
    print("Yes Palindrome")
else:
    print("Not Palindrome")