class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        return isBST(sequence, INT_MIN, INT_MAX);
        
    }
    
    bool isBST(vector<int> sequence, int min_val, int max_val)
    {
        if(sequence.empty()) return true;
        int maxVal = *max_element(sequence.begin(), sequence.end());
        int minVal = *min_element(sequence.begin(), sequence.end());
        if(maxVal >= max_val) return false;
        if(minVal <= min_val) return false;
        bool flag = true;
        vector<int> left_seq, right_seq;
        while(!sequence.empty())
        {
            int root = sequence.back();
            decltype(sequence.size()) index_of_right = -1;
            for(decltype(sequence.size()) i = 0; i < sequence.size(); ++i)
            {
                if(sequence[i] >= root) 
                {
                    index_of_right = i;
                    break;
                }
            }
            if(index_of_right > 0) left_seq.assign(sequence.begin(), sequence.begin() + index_of_right - 1);
            if(index_of_right < sequence.size() - 1) right_seq.assign(sequence.begin() + index_of_right, sequence.end() - 1);
            return isBST(left_seq, min_val, root) && isBST(right_seq, root, max_val);
        }
        return true;
    }
};

// 运行时间：4ms
// 占用内存：480k