/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL) return NULL;
        inOrder(pRoot);
        if(list.size() < k || k < 1) return NULL;
        return list[k - 1];
    }
    void inOrder(TreeNode* node)
    {
        if(node == NULL) return;
        if(node -> left != NULL) inOrder(node -> left);
        list.push_back(node);
        if(node -> right != NULL) inOrder(node -> right);
    }
private:
    vector<TreeNode*> list;    
};

// 运行时间：4ms
// 占用内存：400k

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL) return NULL;
        if(k < 1) return NULL;
        inOrder(pRoot, k);
        if(list.size() < k) return NULL;
        return list[k - 1];
    }
    void inOrder(TreeNode* node, int k)
    {
        if(node == NULL) return;
        if(node -> left != NULL) inOrder(node -> left, k);
        list.push_back(node);
        if(list.size() >= k) return;
        if(node -> right != NULL) inOrder(node -> right, k);
    }
private:
    vector<TreeNode*> list;    
};

// 给定一棵二叉搜索树，请找出其中的第k小的结点。
// 例如，(5，3，7，2，4，6，8) 中，
// 按结点数值大小顺序第三小结点的值为4。

// truncated when list has >= k nodes