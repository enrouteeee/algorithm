def solution(queue1, queue2):
    answer = 0

    sum_1 = sum(queue1)
    sum_2 = sum(queue2)
    queue3 = queue1 + queue2

    full_sum = sum_1 + sum_2

    if full_sum % 2:
        return -1

    i = len(queue1)
    j = 0
    q_len = 2 * i

    while sum_1 != full_sum/2:
        if sum_1 < full_sum/2:
            if i == q_len:
                break
            sum_1 += queue3[i]
            i += 1
        else:
            if j == i:
                break
            sum_1 -= queue3[j]
            j += 1
        answer += 1

    return answer if sum_1 == full_sum/2 else -1