/*
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/submissions/870052327/

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void runDFS(Node *lchild, Node *rchild) {
        lchild->next = rchild;
        rchild->next = NULL;
        if(lchild->left != NULL) {
            runDFS(lchild->left,lchild->right);
            runDFS(lchild->right,rchild->left);
            runDFS(rchild->left,rchild->right);
        }
    }
    Node* connect(Node* root) {
        if(root!= NULL && root->left != NULL) {
            runDFS(root->left, root->right);
        }
        return root;
    }
};
