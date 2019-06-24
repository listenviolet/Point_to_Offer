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
    vector<vector<int> > Print(TreeNode* pRoot) {
        if(pRoot == NULL) return res;
        int index = 0;
        tmp_nodes.push_back(pRoot);
        nodes.push_back(tmp_nodes);
        while(index < nodes.size())
        {
            tmp_nodes.clear();
            for(int i = 0; i < nodes[index].size(); ++i)
            {
                if(nodes[index][i] -> left != NULL) tmp_nodes.push_back(nodes[index][i] -> left);
                if(nodes[index][i] -> right != NULL) tmp_nodes.push_back(nodes[index][i] -> right);
            }
            if(!tmp_nodes.empty()) 
            {
                nodes.push_back(tmp_nodes);
            }
            ++index;
        }
        
        for(int i = 0; i < nodes.size(); ++i)
        {
            level.clear();
            // left to right
            if(i % 2 == 0) 
            {
                for(int j = 0; j < nodes[i].size(); ++j)
                {
                    level.push_back(nodes[i][j] -> val);
                }
            }
            else
            {
                for(int j = nodes[i].size() - 1; j >= 0; --j)
                {
                    level.push_back(nodes[i][j] -> val);
                }
            }
            if(!level.empty()) res.push_back(level);
        }
        return res;
    }
private:
    vector<vector<int> > res;
    vector<int> level;
    vector<vector<TreeNode*> > nodes;
    vector<TreeNode*> tmp_nodes;

};


// 运行时间：4ms
// 占用内存：400k

// 题目描述
// 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
// 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。