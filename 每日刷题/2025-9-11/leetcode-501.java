/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int base;
    int cnt;
    int max_cnt;
    List<Integer> list = new ArrayList<>();

    public int[] findMode(TreeNode root) {
        inorder(root);
        int n = list.size();
        int[] ans = new int[n];
        for(int i = 0; i < n; i++)
            ans[i] = list.get(i);
        return ans;
    }

    private void inorder(TreeNode node) {
        if(node == null)
            return;
        inorder(node.left);
        judge(node.val);
        inorder(node.right);
    }

    private void judge(int x) {
        if(x == base)
            cnt++;
        else {
            base = x;
            cnt = 1;
        }
        if(cnt > max_cnt) {
            list.clear();
            list.add(x);
            max_cnt = cnt;
        }
        else if(cnt == max_cnt) {
            list.add(x);
        }
    }
}