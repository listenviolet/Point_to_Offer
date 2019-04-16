class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;
        int id_push = -1;
        int id_pop = 0;
        // st.push_back(pushV[0]);
        while(id_pop < popV.size())
        {
            while((st.empty() || st.top() != popV[id_pop]))
            {
                id_push++;
                if(id_push >= pushV.size()) return false;
                st.push(pushV[id_push]);
                
            }
            if(st.top() == popV[id_pop])
            {
                st.pop();
                id_pop++;
            }
        }
        return true;
    }
};

// 1. 栈的压入、弹出序列

// 输入两个整数序列，第一个序列表示栈的压入顺序，
// 请判断第二个序列是否可能为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。
// 例如序列1,2,3,4,5是某栈的压入顺序，
// 序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
// 但4,3,5,1,2就不可能是该压栈序列的弹出序列。
// （注意：这两个序列的长度是相等的）

// Alg:
// when the st.top doesn't match the current popV,
// id_push++ and push the pushV[id_push] to stack
// if the id_push is exceed the size limit, return false;
// else the st.top would match the current popV,
// so do the while pop operations.

// if the id_pop come to the end of the popV,
// then return true.

// 运行时间：3ms
// 占用内存：476k