// Given the root of a binary tree, return the inorder traversal of its nodes' values.

//  Definition for a binary tree node.
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

function inorderTraversal(root: TreeNode | null): number[] {
    const res: number[] = []

    console.log(root?.val, root?.left?.val, root?.right?.val)
    if (root?.right) {
        res.unshift(...inorderTraversal(root.right))
    }

    if (root?.val != undefined) {
        res.unshift(root.val)
    }
    if (root?.left) {
        res.unshift(...inorderTraversal(root.left))
    }

    return res
};