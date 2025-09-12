/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    TreeNode ans = null;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        dfs(root, p, q);
        return ans;
    }

    private void dfs(TreeNode node, TreeNode p, TreeNode q) {
        if(node == null)
            return;
        if(p.val > node.val && q.val > node.val)
            dfs(node.right, p, q);
        else if(p.val < node.val && q.val < node.val)
            dfs(node.left, p, q);
        else
            ans = node;
    }
}