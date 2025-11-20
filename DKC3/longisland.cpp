#include <bits\stdc++.h>
using namespace std;

int n,m;
vector<vector<char>> grid;
vector<vector<bool>> visited;

int dr[8] = {-1,-1,-1,0,0,1,1,1};
int dc[8] = {-1,0,1,-1,1,-1,0,1};

void dfs(int r, int c) {
    visited[r][c] = true;
    for (int d = 0; d<8; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m
            && !visited[nr][nc] && grid[nr][nc] == 'L') {
                dfs(nr,nc);
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    int islandCount = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[i][j]=='L' && !visited[i][j]){
                islandCount++;
                dfs(i,j);
            }
        }
    }

    cout << islandCount << "\n";
    return 0;
}