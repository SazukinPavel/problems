// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.


// Definition for a binary tree node.
class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}


function isValidBST(root: TreeNode | null): boolean {
    return validateBST(root)
};

function validateBST(root: TreeNode | null, min = undefined, max = undefined): boolean {
    if (root === null) {
        return true;
    }

    if ((min != undefined && root.val <= min) || (max != undefined && root.val >= max)) {
        return false
    }


    return validateBST(root.left, min, root.val) && validateBST(root.right, root.val, max)
}