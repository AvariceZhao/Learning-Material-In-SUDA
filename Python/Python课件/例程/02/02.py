#验证大整数

large_int = 12345**67890
int_str = str(large_int)
print("length =", len(int_str))

count = 0
while len(int_str) > 0:
    print(int_str[0:50])
    count += len(int_str[0:50])
    int_str = int_str[50:]

print("length =", count)
