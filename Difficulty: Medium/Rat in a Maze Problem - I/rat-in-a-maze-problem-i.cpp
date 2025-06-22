class Solution {
  public:
    void solve(int i, int j, vector<vector<int>> &maze, vector<string> &result, int n, string &path){
        if(i < 0 || i >= n || j < 0 || j >= n || maze[i][j] == 0){
            return;
        }
        
        if(i == n-1 && j == n-1){
            result.push_back(path);
            return;
        }
        
        maze[i][j] = 0;
        
        path.push_back('D');
        solve(i+1, j, maze, result, n, path);
        path.pop_back();
        
        path.push_back('L');
        solve(i, j-1, maze, result, n, path);
        path.pop_back();
        
        path.push_back('R');
        solve(i, j+1, maze, result, n, path);
        path.pop_back();
        
        path.push_back('U');
        solve(i-1, j, maze, result, n, path);
        path.pop_back();
        
        maze[i][j] = 1;
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> result;
        int n = maze.size();
        string path = "";
        
        if (maze[0][0] == 1)
            solve(0, 0, maze, result, n, path);
        
        return result;
    }
};
