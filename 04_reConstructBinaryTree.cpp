# include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()) return NULL;
        return helper(pre, vin, 0, pre.size(), 0, vin.size());
    }
    
    TreeNode *helper(vector<int> pre, vector<int> vin, int pre_start, int pre_last, int vin_start, int vin_last)
    {
        // cout << "root_val = " << root_val << endl;
        if(pre_start == pre_last) return NULL;
        int root_val = pre[pre_start];
        // cout << "root_val = " << root_val << endl;
        TreeNode *root = new TreeNode(root_val);
        int index = -1;
        index = indexOf(vin, root_val, vin_start, vin_last);
        
        TreeNode *left_child = nullptr;
        TreeNode *right_child = nullptr;
        
        left_child = helper(pre, vin, pre_start + 1, index + 1, vin_start, index);
        right_child = helper(pre, vin, index + 1, pre_last, index + 1, vin_last);
        
        root -> left = left_child;
        root -> right = right_child;
        
        return root;
    }
    
    int indexOf(vector<int> vin, int root_val, int vin_start, int vin_last)
    {
        vector<int>::iterator it;
        for(it = vin.begin() + vin_start; it != vin.begin() + vin_last; ++it)
        {
            if(*it == root_val)
            {
                break;
            }
        }
        
        int index = &*it - &vin[0];
        cout << "index of " << root_val << " = " << index << endl;
        return index;
    }
};

int main()
{
    Solution solution;
    int pre_nums[8] = {1,2,4,7,3,5,6,8};
    int vin_nums[8] = {4,7,2,1,5,3,8,6};
    int length = sizeof(pre_nums) / sizeof(pre_nums[0]);
    vector<int> pre(pre_nums, pre_nums + length);
    vector<int> vin(vin_nums, vin_nums + length);

    TreeNode *root = nullptr;
    root = solution.reConstructBinaryTree(pre, vin);
    cout << root -> val << endl;
}