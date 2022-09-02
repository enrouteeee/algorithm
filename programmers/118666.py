def solution(survey, choices):
    answer = ''

    point_dict = {"R":0, "T": 0, "C":0, "F":0, "J":0, "M":0, "A":0, "N":0}

    for i in range(0, len(survey)):
        point = choices[i] - 4

        if point < 0:
            point_dict[survey[i][0]] += abs(point)
        else:
            point_dict[survey[i][1]] += abs(point)

    answer += "R" if point_dict["R"] >= point_dict["T"] else "T"
    answer += "C" if point_dict["C"] >= point_dict["F"] else "F"
    answer += "J" if point_dict["J"] >= point_dict["M"] else "M"
    answer += "A" if point_dict["A"] >= point_dict["N"] else "N"

    return answer