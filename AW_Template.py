import atexit, io, sys

buffer = io.BytesIO()
sys.stdout = buffer

@atexit.register
def write(): sys.__stdout__.write(buffer.getvalue())
# def get_ints(): return map(int, sys.stdin.readline().strip().split())
# def get_string(): return sys.stdin.readline().strip()

input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

# Just paste this template at the beginning of your Code.

# It comprises of 4 functions :-

# 1) inp — For taking integer inputs.

# 2) inlt — For taking List inputs.

# 3) insr — For taking string inputs. Actually it returns a List of Characters, instead of a string, which is easier to use in Python, because in Python, Strings are Immutable.

# 4) invr — For taking space seperated integer variable inputs.

# The input = sys.stdin.readline is actually for Faster Inputs, because line reading through System STDIN (Standard Input) is faster in Python.
