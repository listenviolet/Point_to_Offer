class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0) return 0;
        int index = find(data, k, 0, data.size());
        if(index == -1) return 0;
        int cnt = 0;
        int i = index;
        while(i >= 0 && data[i--] == k)
            ++cnt;
        i = index + 1;
        while(i < data.size() && data[i++] == k) 
            ++cnt;
        return cnt;
    }
    
    int find(vector<int> data, int k, int l, int r)
    {
        if(l == r) return -1;
        int mid = (l + r) / 2;
        if(data[mid] == k) return mid;
        if(data[mid] > k) 
        {
            return find(data, k, l, mid);
        }
        else return find(data, k, mid + 1, r);
    }
};

