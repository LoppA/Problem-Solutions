class Solution {

	enum Cell {
		STONE = '#',
		OBS = '*',
		EMPTY = '.',
	};

	void go(vector<vector<char>> &res, int j) {
		int i = (int)res.size()-1;
		int k = i;

		while(i >= 0) {
			switch (res[i][j]) {
				case Cell::STONE:
					res[i][j] = EMPTY;
					res[k--][j] = Cell::STONE;
					break;
				case Cell::OBS:
					k = i-1;
					break;
				default:
					break;
			}
            i--;
		}
	}

public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
		if (box.empty()) {
			return box;
		}
		vector<vector<char>> res = vector<vector<char>>(box[0].size(), vector<char>(box.size()));

		int n = res.size(), m = res[0].size();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] = box[m-1-j][i];
			}
		}

		for (int j = 0; j < m; j++) {
			go(res, j);
		}

		return res;
    }
};
