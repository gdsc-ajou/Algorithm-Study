def solution(board, moves):
    removed_count = 0
    basket = []
    
    for i in range(len(moves)):
        temp = moves[i] - 1
        for j in range(len(board)):
            if board[j][temp] > 0:
                basket.append(board[j][temp])
                board[j][temp] = 0
                if len(basket) >= 2 and basket[-1] == basket[-2]:
                    removed_count += 2
                    basket.pop()
                    basket.pop()
                break  
    
    return removed_count
