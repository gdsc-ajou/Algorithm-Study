def solution(N, stages):
    stage_per_fail = [0] * N
    stage_dict = defaultdict[int]
    remain = len(stages)

    for elem in stages:
        stage_dict[elem] += 1
    
    for i in range(N):
        temp_success = 0
        temp_challenge = 0

        temp_challenge = stage_dict[i + 1]
        temp_success = remain - temp_challenge
        remain = temp_success
        for j in range(len(stages)):
            if (i + 1) < stages[j]:
                temp_challenge += 1
                temp_success += 1
            elif (i + 1) == stages[j]:
                temp_challenge += 1

        if temp_challenge == 0:
            stage_per_fail[i] = 0
            continue
        stage_per_fail[i] = 1 - (temp_success / temp_challenge)
    
    index_and_fail = list(enumerate(stage_per_fail))
    index_and_fail.sort(key=lambda x: -x[1])

    answer = [val[0] + 1 for val in index_and_fail]
    return answer
