https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/submissions/870082599/
/*
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
    Node* connect(Node* root) {
        if(root==NULL) {
            return root;
        }
        deque<Node *> de,de2;
        de.push_back(root);
        
        while(de.empty()!=true || de2.empty() != true) {
            while(de.empty()!=true) {
                Node *tmp  = de.front();
                de.pop_front();
                if(tmp->left!=NULL) {
                    de2.push_back(tmp->left);
                }
                if(tmp->right!=NULL) {
                    de2.push_back(tmp->right);
                }
                if(de.empty()==false) {
                    Node *tmp2 = de.front();
                    tmp->next = tmp2;
                }
            }
            while(de2.empty()==false ){
                Node *tmp  = de2.front();
                de2.pop_front();
                if(tmp->left!=NULL) {
                    de.push_back(tmp->left);
                }
                if(tmp->right!=NULL) {
                    de.push_back(tmp->right);
                }
                if(de2.empty()==false) {
                    Node *tmp2 = de2.front();
                    tmp->next = tmp2;
                }
            }
        }
        return root;
    }
};
