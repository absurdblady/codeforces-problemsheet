def reverse(name, length):
    
    if length < 1:
        return ""
    
    if length == 1:
        return name[0]

    return name[length - 1] + reverse(name, length - 1)

name = "APPLE"
length = len(name)
print(reverse(name, length))