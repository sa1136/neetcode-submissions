class Solution {
public:

    void dfs(vector<vector<char>>& grid , int r , int c){
        int rows= grid.size();
        int cols =grid[0].size();

        vector<int> dr ={1,0,-1,0};
        vector<int> dc={0,1,0,-1};

        grid[r][c]='0';

        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc= c +dc[i];

            if(nr>=0 && nc>=0 && nr<rows && nc<cols &&grid[nr][nc]=='1'){
                dfs(grid,nr,nc);
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int rows=grid.size();
        int cols =grid[0].size();

        int count =0;

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]=='1'){
                    count++;
                    dfs(grid,r,c);
                }
            }
        }
        return count;
        
    }
};


// Time Complexity: O(rows × cols) — every cell is visited at most once.

// Space Complexity: O(rows × cols) — recursion stack can go up to rows × cols in the worst case.
