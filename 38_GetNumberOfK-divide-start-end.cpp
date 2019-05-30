class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0) return 0;
        int start = -1, end = data.size() + 1;
        find(data, k, 0, data.size(), start, end);
        if(start == -1 || end == data.size() + 1) return 0;
        return end - start + 1;
    }
    
    void find(vector<int> data, int k, int l, int r, int &start, int &end)
    {
        if(l == r) return;
        int mid = (l + r) / 2;
        if(data[mid] == k)
        {
            // is the end
            if(mid + 1 >= data.size() || data[mid + 1] != data[mid]) end = mid;
            // is the first
            if(mid - 1 < 0 || data[mid - 1] != data[mid]) start = mid;
            // first not found
            if(start == -1) find(data, k, l, mid, start, end);
            // end not found
            if(end == data.size() + 1) find(data, k, mid + 1, r, start, end);
        }
        if(data[mid] > k) 
        {
            find(data, k, l, mid, start, end);
        }
        else find(data, k, mid + 1, r, start, end);
    }
};
