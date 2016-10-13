class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() <2 || k==0)  return false;
        set<int> windows;
        int l = 0;
        for(int i = 0;i<nums.size();i++) {
            if(i-l>k) {
                windows.erase(nums[l]);
                l++;
            }

            auto it = windows.lower_bound(nums[i]-t);
            if(it!=windows.end() && *it-t<=nums[i])
                return true;

            windows.insert(nums[i]);
        }

        return false;

    }
};


--------------------------------

Alternate solution which requires building a Binary Search

Referenced from here:
https://discuss.leetcode.com/topic/55821/c-bst-o-nlogk-84-64/2

// class TreeNode {
//     int val;
//     TreeNode *left, *right;
// public:
//     TreeNode(int x): val(x), left (NULL), right(NULL) {};
// };

class BST {
    TreeNode *root;

public:
    BST () {
        root = NULL;
    }

    TreeNode* insert(int key) {
        root = insert(root,key);
        return root;

    }

    TreeNode *remove(int key) {
        root = remove(root, key);
        return root;
    }

    TreeNode *insert(TreeNode *root, int key) {
        if(root == NULL) {
            return new TreeNode(key);
        }

        if(root->val > key) {
            root->left = insert(root->left, key);
        }
        else if(root->val < key)
            root->right = insert(root->right, key);

        return root;
    }

    TreeNode *remove(TreeNode *root, int key) {
        if(root == NULL)
            return NULL;

        if(root->val > key) {
            root->left = remove(root->left, key);
        }
        else if(root->val < key)
            root->right = remove(root->right,key);
        else {
            if(!root->left && !root->right) {
                delete(root);
                return NULL;
            }

            if(!root->left) {
                TreeNode *temp = root->right;
                delete (root);
                return temp;
            }

            else if(!root->right) {
                TreeNode *temp = root->left;
                delete (root);
                return temp;
            }

            else {
                TreeNode *cur = root->right;
                while(cur->left)
                    cur = cur->left;

                root->val = cur->val;
                root->right = remove(root->right, root->val);
            }


        }
         return root;
    }

    bool search(int val, int t) {
        return search(root,val,t);
    }

    bool search(TreeNode *root, long val, int t) {
        if(root == NULL)
            return false;

        if(abs(root->val - val) <=t)
            return true;
        else if(root->val - t > val)
            return search(root->left, val, t);
        else
            return search(root->right, val, t);
    }
};


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        if(nums.empty() || k == 0)
            return false;

        BST b;

        for(int i = 1 ; i<nums.size() ; ++i) {
            cout << i << endl;
            b.insert(nums[i-1]);

            if(i>k)
                b.remove(nums[i-k-1]);


            if(b.search(long(nums[i]),t))
                return true;

        }
        return false;
    }
};
