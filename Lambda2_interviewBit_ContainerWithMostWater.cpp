int Solution::maxArea(vector<int> &A) {
    const int n = A.size();
    if(n <= 1) {
        return 0;
    }
    
    vector<int> id;
    for(int i = 0; i < n; i++) {
        id.push_back(i);
    }
    sort(id.begin(), id.end(), [&A](const int i, const int j) -> bool {
        return A[i] > A[j];
    });
    
    int j = 0;
    int l = id[0], r = id[0];
    int ans = 0;
    for(int i : id) {
        while(j < (int)id.size() and A[id[j]] >= A[i]) {
            l = min(l, id[j]);
            r = max(r, id[j]);
            j++;
        }
        
        assert(r >= i and l <= i);
        
        int widthR = r-i, widthL = i-l;
        ans = max(ans, widthR * A[i]);
        ans = max(ans, widthL * A[i]);
    }
    
    return ans;
}
