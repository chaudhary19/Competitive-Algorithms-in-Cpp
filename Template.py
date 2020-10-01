# python program with fast I/O

#module contain stdin ,stdout
from sys import stdin, stdout 
from time import perf_counter

#integer input from user ,2 input in single line
n,m=map(int,input().split()) 

t1_start = perf_counter()

for i in range(n):
    t=int(stdin.readline()) # input using fast i/p method 
    if t%m == 0:
        stdout.write(str(t)+'\n') #input using fast o/p method

t1_stop = perf_counter()# Stop the stopwatch

print("Elapsed time:", t1_stop-t1_start) # Report results

