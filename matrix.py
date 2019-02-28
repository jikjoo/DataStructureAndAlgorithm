# -*- coding: utf-8 -*-
"""
Created on Wed Sep 13 20:04:32 2017

@author: 이직주
"""

n=int(input("n을 입력하시오\n"))
a=[[0 for col in range(n)] for row in range(n)]
b=[[0 for col in range(n)] for row in range(n)]
c=[[0 for col in range(n)] for row in range(n)]
for i in range(n):
    for j in range(n):
        a[i][j] = int(input('a '))
        b[i][j] = int(input('b '))
        
for i in range(n):
    for j in range(n):
        Sum = 0;
        for k in range(n):
            Sum += a[i][k]*b[k][j]
        c[i][j] = Sum
print(c)

