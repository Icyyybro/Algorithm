class Solution {
    Deque<int[]> queue = new ArrayDeque<>();
    int n, m;
    int last = 0;
    int ans = 0;
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};

    public int orangesRotting(int[][] grid) {
        n = grid.length;
        m = grid[0].length;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    int[] temp = {i, j};
                    queue.offer(temp);
                }
                if(grid[i][j] == 1)
                    last++;
            }
        }
        
        while(!queue.isEmpty()) {
            if(last == 0)
                break;
            int num = queue.size();
            for(int i = 0; i < num; i++) {
                int[] temp = queue.poll();
                int x = temp[0];
                int y = temp[1];
                for(int j = 0; j < 4; j++) {
                    int posx = x + dx[j];
                    int posy = y + dy[j];
                    if(isLegal(posx, posy, grid)) {
                        queue.offer(new int[]{posx, posy});
                        grid[posx][posy] = 2;
                        last--;
                    }
                }
            }
            ans++;
        }
        if(last == 0)
            return ans;
        else
            return -1;
    }

    private Boolean isLegal(int x, int y, int[][] grid) {
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)
            return true;
        return false;
    }
}