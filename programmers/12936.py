def solution(n, k):
    answer = []

    dp = []
    dp.append(1)

    tmp = [i for i in range(1,n+1)]

    for i in range(1, n-1):
        dp.insert(0, dp[0]*(i+1))

    k = k-1
    for i in dp:
        answer.append(tmp[k//i])
        del tmp[k//i]
        k = k % i

    answer = answer + tmp

    return answer