# N-Queens Problem using Backtracking + Branch and Bound

def print_board(board, n):
    for i in range(n):
        for j in range(n):
            if board[i] == j:
                print("Q", end=" ")
            else:
                print(".", end=" ")
        print()
    print()

def is_safe(row, col, board):
    for i in range(row):
        # Check column and diagonals
        if board[i] == col or abs(board[i] - col) == abs(i - row):
            return False
    return True

def solve_n_queens(n, row, board, solutions):
    # If all queens are placed
    if row == n:
        solutions.append(board[:])
        return
    
    for col in range(n):
        if is_safe(row, col, board):
            board[row] = col
            solve_n_queens(n, row + 1, board, solutions)
            # backtrack
            board[row] = -1

def n_queens(n):
    board = [-1] * n
    solutions = []
    solve_n_queens(n, 0, board, solutions)
    
    print(f"Total solutions for {n}-Queens: {len(solutions)}\n")
    if solutions:
        print("One possible solution:\n")
        print_board(solutions[0], n)

# Main
if __name__ == "__main__":
    n = int(input("Enter number of queens: "))
    n_queens(n)
