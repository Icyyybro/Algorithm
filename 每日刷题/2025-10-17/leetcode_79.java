class Solution {
    int n,m;
    boolean[][] visited;
    List<int[]> list = new ArrayList<>();
    boolean ans = false;
    int[] dirx = {-1, 1, 0, 0};
    int[] diry = {0, 0, -1, 1};

    public boolean exist(char[][] board, String word) {
        n = board.length;
        m = board[0].length;
        visited = new boolean[n][m];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(word.charAt(0) == board[i][j])
                    list.add(new int[]{i, j});
            }
        }

        for(int i = 0; i < list.size(); i++) {
            dfs(board, word, list.get(i)[0], list.get(i)[1], 0);
            if(ans == true)
                return true;
        }
        return false;
    }

    private void dfs(char[][] board, String word, int x, int y,int idx) {
        if(idx == word.length() - 1) {
            ans = true;
            return;
        }
        visited[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int posx = x + dirx[i];
            int posy = y + diry[i];
            if(isLegal(board, word, posx, posy, idx + 1)) {
                dfs(board, word, posx, posy, idx + 1);
            }
        }
        visited[x][y] = false;
    }

    private boolean isLegal(char[][] board, String word, int x, int y, int idx) {
        if(x >= 0 && x < n && y >= 0 && y < m && idx < word.length() && board[x][y] == word.charAt(idx) && !visited[x][y])
            return true;
        return false;
    }
}