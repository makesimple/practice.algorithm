#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

static std::vector<std::unordered_map<char, char>> rowset {
{{'1','1'},{'2','2'},{'3','3'},{'4','4'},{'5','5'},{'6','6'},{'7','7'},{'8','8'},{'9','9'}},
{{'1','1'},{'2','2'},{'3','3'},{'4','4'},{'5','5'},{'6','6'},{'7','7'},{'8','8'},{'9','9'}},
{{'1','1'},{'2','2'},{'3','3'},{'4','4'},{'5','5'},{'6','6'},{'7','7'},{'8','8'},{'9','9'}},
{{'1','1'},{'2','2'},{'3','3'},{'4','4'},{'5','5'},{'6','6'},{'7','7'},{'8','8'},{'9','9'}},
{{'1','1'},{'2','2'},{'3','3'},{'4','4'},{'5','5'},{'6','6'},{'7','7'},{'8','8'},{'9','9'}},
{{'1','1'},{'2','2'},{'3','3'},{'4','4'},{'5','5'},{'6','6'},{'7','7'},{'8','8'},{'9','9'}},
{{'1','1'},{'2','2'},{'3','3'},{'4','4'},{'5','5'},{'6','6'},{'7','7'},{'8','8'},{'9','9'}},
{{'1','1'},{'2','2'},{'3','3'},{'4','4'},{'5','5'},{'6','6'},{'7','7'},{'8','8'},{'9','9'}},
{{'1','1'},{'2','2'},{'3','3'},{'4','4'},{'5','5'},{'6','6'},{'7','7'},{'8','8'},{'9','9'}}};
static std::vector<std::unordered_map<char, char>> colset = rowset, blockset = rowset;

class Solution {
public:
    bool solveSudokuRec(vector<vector<char>>& board, int index) {
        if (index > 80) {
		mBoard = board;
		return true;
	}
	int row = index / 9;
	int col = index % 9;
	int blockIndex = row / 3 * 3 + col / 3;
	if (board[row][col] == '.') {
		auto &rs = rowset[row];
		auto &cs = colset[col];
		auto &blk = blockset[blockIndex];
		auto size = rs.size();
		unordered_map<char, char> mincopy(rs);
		bool result = false;
		for (auto it = mincopy.begin();it != mincopy.end(); it++) {
			if (cs.find(it->first) != cs.end() 
				&& blk.find(it->first) != blk.end()) {
				rs.erase(it->first);
				cs.erase(it->first);
				blk.erase(it->first);
				char tmp = board[row][col];
				board[row][col] = it->second;
				// how return the value if many solutions exist and found them ?
				if (solveSudokuRec(board, index + 1)) {
					result = true;
					break;
				}
				board[row][col] = tmp;	
				rs.insert({it->first, it->second});
				cs.insert({it->first, it->second});
				blk.insert({it->first, it->second});
			}
		}
		return result;
	} else {
		return solveSudokuRec(board, index + 1);
	}
    }
    void solveSudoku(vector<vector<char>>& board) {
		colset = rowset;
		blockset = rowset;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				int blockIndex = i / 3 * 3 + j / 3;
				if (board[i][j] != '.') {
					char k = board[i][j];
					rowset[i].erase(k);
					colset[j].erase(k);
					blockset[blockIndex].erase(k);
				}
			}
		}
        solveSudokuRec(board, 0);
    }
vector<vector<char>> mBoard;
};

int main() {
vector<vector<char>> board {
{'.','.','9','7','4','8','.','.','.'},
{'7','.','.','.','.','.','.','.','.'},
{'.','2','.','1','.','9','.','.','.'},
{'.','.','7','.','.','.','2','4','.'},
{'.','6','4','.','1','.','5','9','.'},
{'.','9','8','.','.','.','3','.','.'},
{'.','.','.','8','.','3','.','2','.'},
{'.','.','.','.','.','.','.','.','6'},
{'.','.','.','2','7','5','9','.','.'}
};
Solution solu;
solu.solveSudoku(board);
 for (int i = 0; i < 9; i++) {
	for(int j = 0; j < 9; j++)
		std::cout<<solu.mBoard[i][j];
	std::cout<<std::endl;
}

}



