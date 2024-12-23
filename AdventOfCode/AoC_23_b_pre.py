import sys

s = 0
for i in range(1, 100):
    print(i, s)
    if s > 3380:
        sys.exit(0) # Max for input is 83
    s += i
