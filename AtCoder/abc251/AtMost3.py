# coding:utf-8

n, w = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
b = [0]*w
for i in range(n-2):
    for j in range(i+1, n-1):
        for k in range(j+1, n):
            sums = [
                a[i], a[j], a[k],
                a[i]+a[j], a[j]+a[k], a[k]+a[i],
                a[i]+a[j]+a[k]
            ]
            for s in sums:
                if s <= w:
                    b[s-1] = 1
print(sum(b))
