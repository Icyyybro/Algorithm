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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        TreeNode node = root;
        if(node == null) {
            TreeNode newNode = new TreeNode(val);
            return newNode;
        }
        while(node != null) {
            if(node.val < val) {
                if(node.right == null) {
                    TreeNode newNode = new TreeNode(val);
                    node.right = newNode;
                    return root;
                }
                else {
                    node = node.right;    
                }
            }
            else {
                if(node.left == null) {
                    TreeNode newNode = new TreeNode(val);
                    node.left = newNode;
                    return root;
                }
                else {
                    node = node.left;    
                }
            }
        }
        return root;
    }
}