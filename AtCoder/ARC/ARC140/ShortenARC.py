# coding:utf-8

n, k = map(int, input().split(' '))
s = input()

def f(t):
    str_dist = set()
    str_dist.add(t)
    for i in range(len(t)):
        t = t[-1] + t[0:-1]
        if t not in str_dist:
            str_dist.add(t)
    return len(str_dist)
