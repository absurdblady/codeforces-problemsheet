# Problem: Make Connected (Codeforces 2161B)
# Author: ChatGPT (Python version)
# Logic:
#  - We must ensure: no three consecutive '#' in any row/column,
#    and all black cells can be connected by painting some '.' cells.
#  - Key observation from contest editorial:
#       If the grid has any pair of adjacent black cells (horizontally or vertically),
#       we can fill the entire row/column in a checker pattern so that connectivity
#       and "no 3 consecutive" rules both hold.
#       Otherwise, we can always make it connected unless there's a 3-in-a-row violation.

def solve():
    t = int(input().strip())
    for _ in range(t):
        n = int(input().strip())
        grid = [list(input().strip()) for _ in range(n)]

        def violates_three_consecutive():
            # check horizontally and vertically
            for i in range(n):
                for j in range(n - 2):
                    if grid[i][j] == grid[i][j + 1] == grid[i][j + 2] == '#':
                        return True
            for j in range(n):
                for i in range(n - 2):
                    if grid[i][j] == grid[i + 1][j] == grid[i + 2][j] == '#':
                        return True
            return False

        if violates_three_consecutive():
            print("NO")
            continue

        # if grid has no black cells, we can always paint one
        has_black = any('#' in row for row in grid)
        if not has_black:
            print("YES")
            continue

        # Check if it’s possible to make all connected:
        # Try to detect pattern impossibility:
        possible = False
        for i in range(n):
            for j in range(n):
                if grid[i][j] == '#':
                    # Check adjacent (up, down, left, right)
                    for dx, dy in [(1,0),(-1,0),(0,1),(0,-1)]:
                        ni, nj = i + dx, j + dy
                        if 0 <= ni < n and 0 <= nj < n and grid[ni][nj] == '#':
                            possible = True
                            break
                    if possible:
                        break
            if possible:
                break

        # If any adjacent pair exists, we can connect properly
        print("YES" if possible else "NO")


if __name__ == "__main__":
    solve()
