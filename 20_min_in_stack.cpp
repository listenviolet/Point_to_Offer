class Solution {
public:
    void push(int value) {
        origin.push(value);
        if(tmp_min.empty()) 
        {
            Min = value;
        }
        else
        {
            Min = tmp_min.top() < value ? tmp_min.top() : value;
        }
        tmp_min.push(Min);
    }
    void pop() {
        if(!origin.empty()) origin.pop();
        if(!tmp_min.empty()) tmp_min.pop();
    }
    int top() {
        return origin.top();
    }
    int min() {
        return tmp_min.top();
    }
private:
    stack<int> origin;
    stack<int> tmp_min;
    int Min;
};

// 定义栈的数据结构，
// 请在该类型中实现一个能够得到栈中所含最小元素的min函数（
// 时间复杂度应为O（1））。

// 运行时间：3ms

// 占用内存：488k