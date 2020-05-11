T = int(input())

DP = [0] * 101
DP[1] = DP[2] = 1

for n in range(3, 101):
    DP[n] = DP[n - 3] + DP[n - 2]

for t in range(0, T):
    N = int(input())
    print(DP[N])
