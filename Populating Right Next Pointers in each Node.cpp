/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// With extra space. O(n) space. Iterative solution
class Solution {
public:
    void connect(TreeLinkNode *root) {

        if(root == NULL)
            return;

        queue<TreeLinkNode *> q;

        q.push(root);

        while(!q.empty()) {
            int num = q.size();
            while(num) {
                TreeLinkNode *cur = q.front();
                q.pop();
                num--;

                if(num > 0)
                    cur->next = q.front();
                else
                    cur->next = NULL;

                // assign next value

                if(cur->left != NULL)
                    q.push(cur->left);

                if(cur->right != NULL)
                    q.push(cur->right);
            }
        }


    }
};


------

// Recursive solution. Still uses extra space (extra space used to accomodate recursion stack)
class Solution {
public:
    void connect(TreeLinkNode *root) {

        if(!root)
            return;

        if(root->left) {
            root->left->next = root->right;
            if(root->next) {
                root->right->next = root->next->left;
            }

        }
        connect(root->left);
        connect(root->right);
    }
};

-----

// Two pointer method without any extra space
class Solution {
public:
    void connect(TreeLinkNode *root) {

        TreeLinkNode *pre = root;
        TreeLinkNode *cur = NULL;

        if(root == NULL)
            return;

        while(pre && pre->left) {
            cur = pre;
            while (cur) {
                cur->left->next = cur->right;
                if(cur->next) {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            pre = pre->left;
        }
    }

};
