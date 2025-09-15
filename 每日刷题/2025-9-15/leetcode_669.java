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
// 递归
class Solution {
    public TreeNode trimBST(TreeNode root, int low, int high) {
        if(root == null)
            return null;
        if(root.val >= low && root.val <= high) {
            root.left = trimBST(root.left, low, high);
            root.right = trimBST(root.right, low, high);
            return root;
        }
        else if (root.val < low) {
            root.left = null;
            return trimBST(root.right, low, high);
        }
        else {
            root.right = null;
            return trimBST(root.left, low, high);
        }
    }
}

// 迭代
class Solution {
    public TreeNode trimBST(TreeNode root, int low, int high) {
        while(root != null && (root.val < low || root.val > high)) {
            if(root.val < low)
                root = root.right;
            else
                root = root.left;
        }
        if(root == null)
            return null;
        // 修建左子树
        for(TreeNode node = root; node.left != null; ) {
            if(node.left.val < low)
                node.left = node.left.right;
            else
                node = node.left;
        }
        // 修剪右子树
        for(TreeNode node = root; node.right != null; ) {
            if(node.right.val > high)
                node.right = node.right.left;
            else
                node = node.right;
        }
        return root;
    }
}