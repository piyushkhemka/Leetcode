In place Solution

http://articles.leetcode.com/convert-binary-search-tree-bst-to/

Converts BST to circular doubly linked list

void treeToDoublyList(Node *p, Node *& prev, Node *& head) {
  if (!p) return;
  treeToDoublyList(p->left, prev, head);
  p->left = prev;
  if (prev)
    prev->right = p;  // previous node's right points to current node
  else
    head = p;


  head->left = p; // If need to convert to doubly linked list & not circular doubly-linked
  p->right = head; // list then omit these two lines



  prev = p;
  treeToDoublyList(p->right, prev, head);
}

// Given an ordered binary tree, returns a sorted circular
// doubly-linked list. The conversion is done in-place.
Node* treeToDoublyList(Node *root) {
  Node *prev = NULL;
  Node *head = NULL;
  treeToDoublyList(root, prev, head);
  return head;
}



------------

BST to doubly linked list.

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct LinkedNode {
     int val;
     LinkedNode *prev;
     LinkedNode *next;
     LinkedNode(int x) : val(x), prev(NULL), next(NULL) {}
 };

void bsttodoublylinkedlist(TreeNode* root) {

    stack<TreeNode *> s;

    LinkedNode *head = nullptr;
    LinkedNode *prevnode = nullptr;

    if (!root)
        return nullptr;

    TreeNode *cur = root;

    while(!s.empty() || cur) {

        while(cur) {
            s.push(cur);
            cur = cur->left;
        }

        cur = s.top();
        s.pop();

        LinkedNode *curnode = new LinkedNode(cur->val);

        if (!head)
            head = curnode;

        curnode->prev = prevnode;

        if (prevnode)
            prevnode->next = curnode;

        prevnode = curnode;
        cur = cur->right;
    }
    return;
}
