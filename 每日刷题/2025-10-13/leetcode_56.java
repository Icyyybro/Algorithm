class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        List<int[]> list = new ArrayList<>();
        Arrays.sort(intervals, new Comparator<int[]>(){
            public int compare(int[] a, int[] b) {
                return a[0] - b[0];
            }
        });

        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] > right) {
                int[] temp = new int[]{left, right};
                list.add(temp);
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else {
                right = Math.max(intervals[i][1], right);
            }
        }
        int[] temp = new int[]{left, right};
        list.add(temp);
        return list.toArray(new int[list.size()][2]);
    }
}