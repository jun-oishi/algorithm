# coding:utf-8

n, q = map(int, input().split(' '))
jointsets = []
for i in range(n):
    flg, u, v = map(int, input().split(' '))
    if flg:
        for i in range(len(jointsets)):
            if (u in jointsets[i] and v in jointsets[i]):
                print(1)
                break
            continue
        continue

    for i in range(len(jointsets)):
        if (u in jointsets[i] and v not in jointsets[i]):
            for j in range(len(jointsets)):
                if (v in jointsets[j]):
                    for node in jointsets[j]:
                        jointsets[i].append(node)
                    del jointsets[j]
