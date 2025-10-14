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
    TreeNode ans;
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        judge(root, p, q);
        return ans;
    }

    private Boolean judge(TreeNode node, TreeNode p, TreeNode q) {
        if(node == null)
            return false;
        Boolean left = judge(node.left, p, q);
        Boolean right = judge(node.right, p, q);
        if((left && right) || ((node == p || node == q) && (left || right)))
            ans = node;
        return node == p || node == q || left || right;
    }
}