def solution(name, yearning, photo):
    total_yearn = [0] * len(photo)
    
    for i in range(len(photo)):
        for j in range(photo[i]):
            for k in range(len(name)):
                if name[k] == photo[i][j]:
                    total_yearn[i] += yearning[k]

    return list(total_yearn)
