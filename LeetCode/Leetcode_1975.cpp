class Solution {

public:
	long long maxMatrixSum(vector<vector<int>>& matrix) {
		int neg = accumulate(
			matrix.begin(),
			matrix.end(),
			0,
			[](int acc, const vector<int> &vec) {
				return acc + accumulate(vec.begin(), vec.end(), 0,
						[](int acc2, const int val) {
							return acc2 + (val < 0);
						});
			});
		
		for (vector<int>& row : matrix) {
			transform(row.begin(), row.end(), row.begin(), [](int elem) {
				return abs(elem);
			});
    	}
		
		long long sum = accumulate(
			matrix.begin(),
			matrix.end(),
			0LL,
			[](long long acc, const vector<int> &vec) {
				return acc + accumulate(vec.begin(), vec.end(), 0LL);
			});

		if (neg%2 == 0) {
			return sum;
		}

		int mn = accumulate(
			matrix.begin(),
			matrix.end(),
			matrix.front().front(),
			[](int acc, const vector<int> &vec) {
				return min(acc, accumulate(
							vec.begin(),
							vec.end(),
							vec.front(),
							[] (int acc, const int val) {
								return min(acc, val);
							}));
			});
		
		return sum - 2*mn;
    }
};
