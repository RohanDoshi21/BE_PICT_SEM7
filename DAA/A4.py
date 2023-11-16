# N-QUEENS when 1st queen is placed
N = 4
board = [[0]* N for _ in range(N)]
placed = (2, 3)
board[placed[0]][placed[1]] = 1


def printBoard(board):
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 0:
                print('.', end=' ')
            elif board[i][j] == 1:
                print('Q', end=' ')
            else:
                print('P', end=' ')
        print()

print("Initial Board")
printBoard(board)
print("*"*8)

def is_safe(board, pos_x, pos_y):
    for i in range(N):
        if board[i][pos_y] == 1:
            return False

    for i in range(N):
        if board[pos_x][i] == 1:
            return False

    i, j = pos_x, pos_y
    while i>=0 and j>=0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1

    i, j = pos_x, pos_y
    while i < N and j >= 0:
        if board[i][j] == 1:
            return False
        i += 1
        j -= 1

    i, j = pos_x, pos_y
    while i >= 0 and j < N:
        if board[i][j] == 1:
            return False
        i -= 1
        j += 1

    i, j = pos_x, pos_y
    while i < N and j < N:
        if board[i][j] == 1:
            return False
        i += 1
        j += 1


    return True

def NQueens(board, col):
    if col >= N:
        return True

    if col == placed[1]:
        return NQueens(board, col+1)

    for i in range(N):
        if i == placed[0]:
            continue

        if is_safe(board, i, col):

            board[i][col] = 1

            if NQueens(board, col+1):
                return True

            board[i][col] = 0

    return False


if NQueens(board, 0):
    print("Solution")
    printBoard(board)
    print("*"*8)
else:
    print("No Solution")