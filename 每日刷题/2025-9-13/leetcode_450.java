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
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null)
            return root;
        else if(root.val < key) {
            root.right = deleteNode(root.right, key);
            return root;
        }
        else if(root.val > key) {
            root.left = deleteNode(root.left, key);
            return root;
        }
        else {
            // 如果是叶子节点
            if(root.left == null && root.right == null)
                return null;
            // 如果右子树不为空
            else if(root.left == null) {
                return root.right;
            }
            // 如果左子树不为空
            else if(root.right == null) {
                return root.left;
            }
            // 如果都不为空
            else {
                TreeNode node = root.right;
                while(node.left != null) {
                    node = node.left;
                }
                root.right = deleteNode(root.right, node.val);
                node.left = root.left;
                node.right = root.right;
                return node;
            }
        }
    }
}