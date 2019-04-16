# include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int> tmp;
        dfs(root, expectNumber, tmp);
        return allRes;
    }
    
    void dfs(TreeNode *root, int target, vector<int> tmp)
    {
        if(root == NULL && target == 0)
        {
            allRes.push_back(tmp);      
        }
        
        else if(root != NULL && root -> val <= target)
        {
            tmp.push_back(root -> val);
            dfs(root -> left, target - root -> val, tmp);
            dfs(root -> right, target - root -> val, tmp);
        }
        if(!tmp.empty()) tmp.pop_back();
        
    }
private:
    vector<vector<int> > allRes;
    int cnt = 0;
};

int main()
{
    TreeNode *root = new TreeNode(10);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node12 = new TreeNode(12);

    root -> left = node5;
    root -> right = node12;
    node5 -> left = node4;
    node5 -> right = node7;

    Solution solution;

    vector<vector<int> > allRes;
    allRes = solution.FindPath(root, 22);
    for(int i = 0; i < allRes.size(); ++i)
    {
        for(int j = 0; j < allRes[i].size(); ++j)
        {
            cout << allRes[i][j] << " ";
        }
        cout << "; ";
    }

    return 0;

}

// This method is not correct:
// {10,5,12,4,7},22
// 10 5 7 ; 10 5 7 ; 10 12 ; 10 12 ;
// it will add the same path twice
// since: 
// if(root == NULL && target == 0)
// a leaf -> left == NULL and leaf -> right == NULL
// so it will be added twice.
