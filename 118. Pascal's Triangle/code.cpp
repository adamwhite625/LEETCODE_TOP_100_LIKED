class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for(int i = 1; i < numRows; i++){
            vector<int> pre = res[i-1];
            vector<int> current;
            current.push_back(1);
            for(int j = 1; j < i; j++){
                current.push_back(pre[j - 1] + pre[j]);
            }
            current.push_back(1);
            res.push_back(current);
        }
        return res;
    }
};
