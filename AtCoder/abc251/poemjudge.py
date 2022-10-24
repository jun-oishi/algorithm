n = int(input())
existing_s = []
max_t = -1
for i in range(n):
    new_s, new_t = input().split(' ')
    if new_s in existing_s:
        continue
    existing_s.append(new_s)
    if int(new_t) > max_t:
        ans = i+1
        max_t = int(new_t)

print(ans)
