/*Finding Island*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isSafe(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited){
    int row = grid.size();
    int col = grid[0].size();

    return (r>=0) && (r<row) && (c>=0) && (c<col && (grid[r][c] == 'L' && !visited[r][c]));
}

void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited){
    vector<int> rNbr = {-1,-1,-1,0,0,1,1,1};
    vector<int> cNbr = {-1,0,1,-1,1,-1,0,1};

    visited[r][c]=true;

    for(int k=0; k<8; ++k){
        int newR = r + rNbr[k];
        int newC = c + cNbr[k];
        if (isSafe(grid, newR, newC, visited)){
            dfs(grid,newR,newC,visited);
        }
    }
}

int countIslands(vector<vector<char>>& grid){
    int row=grid.size();
    int col=grid[0].size();

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int count=0;
    for(int r=0; r<row; r++){
        for(int c=0; c<col;c++){
            if (grid[r][c] == 'L' && !visited[r][c]){
                dfs(grid, r, c, visited);

                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<vector<char>>grid={   { 'L', 'W', 'W', 'W', 'W' },
                                 { 'W', 'L', 'W', 'W', 'L' },
                                 { 'L', 'W', 'W', 'L', 'L' },
                                 { 'W', 'W', 'W', 'W', 'W' },
                                 { 'L', 'W', 'L', 'L', 'W' } };
   
    cout<<countIslands(grid)<<endl;

    return 0;
}