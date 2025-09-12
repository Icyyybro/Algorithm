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
        judge(root, p, q);
        return ans;
    }

    private boolean judge(TreeNode node, TreeNode p, TreeNode q) {
        if(node == null)
            return false;
        boolean left = judge(node.left, p, q);
        boolean right = judge(node.right, p, q);
        if(left && right || ((left || right) && (p == node || q == node))) {
            ans = node;
        }
        if(left || right || p == node || q == node)
            return true;
        else
            return false;
    }
}