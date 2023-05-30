// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function rangeSumBST(root: TreeNode | null, low: number, high: number): number {
    return rangeSumBSTHelp(root, low, high)
};

function rangeSumBSTHelp(root: TreeNode | null, low: number, high: number, sum: number = 0) {
    if (!root) {
        return sum;
    }

    if (root.val >= low && root.val <= high) {
        sum += root.val;
    }

    if (root.val < high) {
        sum += rangeSumBSTHelp(root.right, low, high)
    }

    if (root.val > low) {
        sum += rangeSumBSTHelp(root.left, low, high)
    }


    return sum;
}
