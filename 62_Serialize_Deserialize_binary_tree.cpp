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
    vector<int> buf;
    void dfs1(TreeNode *root)
    {
        if(root == NULL) buf.push_back(0xFFFFFFFF);
        else{
            buf.push_back(root -> val);
            dfs1(root -> left);
            dfs1(root -> right);
        }
    }
    TreeNode* dfs2(int *&p)
    {
        if(*p == 0xFFFFFFFF)
        {
            ++p;
            return NULL;
        }
        TreeNode* res = new TreeNode(*p);
        p++;
        res -> left = dfs2(p);
        res -> right = dfs2(p);
        return res;
    }
    
    char* Serialize(TreeNode *root) {
        buf.clear();
        dfs1(root);
        int bufsize = buf.size();
        int *res = new int[bufsize];
        for(int i = 0; i < bufsize; ++i) res[i] = buf[i];
        return (char*)res;
    }
    TreeNode* Deserialize(char *str) {
        int *p = (int*) str;
        return dfs2(p);
    }
};

// 请实现两个函数，分别用来序列化和反序列化二叉树
// 运行时间：5ms
// 占用内存：516k