// 236. Lowest Common Ancestor of a Binary Tree
//     Given a binary tree,
//     find the lowest common ancestor(LCA)
// of two given nodes in the tree.

//     According to the definition of LCA on Wikipedia : “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants(where we allow a node to be a descendant of itself)
//         .”

//     Example 1 :

//     Input : root = [ 3, 5, 1, 6, 2, 0, 8, null, null, 7, 4 ],
//             p = 5, q = 1 Output : 3 Explanation : The LCA of nodes 5 and 1 is 3. Example 2 :

//     Input : root = [ 3, 5, 1, 6, 2, 0, 8, null, null, 7, 4 ],
//             p = 5, q = 4 Output : 5 Explanation : The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.Example 3 :

//     Input : root = [ 1, 2 ],
//             p = 1, q = 2 Output : 1
#include <bits/stdc++.h>
                   using namespace std;
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int value)
    {
        key = value;
        left = NULL;
        right = NULL;
    }
};
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root->key == p->key || root->key == q->key)
    {
        return root;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return NULL;
    }
    Node *right = NULL, *left = NULL;
    if (root->left != NULL)
    {
        left = lowestCommonAncestor(root->left, p, q);
    }
    if (root->right != NULL)
    {
        right = lowestCommonAncestor(root->right, p, q);
    }
    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left == NULL)
    {
        return right;
    }
    return left;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);
    root->right->right = new Node(60);
    cout << lowestCommonAncestor(root, root->left->right->left, root->left->left)->key;
    return 0;
}