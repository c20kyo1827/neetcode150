class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    std::vector<std::vector<int>> commonBoard;
    int lenTxt1 = text1.size();
    int lenTxt2 = text2.size();
    commonBoard.resize(lenTxt1 + 1, vector<int>(lenTxt2 + 1, 0));

    for (int idx1 = 1; idx1 < lenTxt1 + 1; idx1++) {
      for (int idx2 = 1; idx2 < lenTxt2 + 1; idx2++) {
        if (text1[idx1 - 1] == text2[idx2 - 1])
          commonBoard[idx1][idx2] = commonBoard[idx1 - 1][idx2 - 1] + 1;
        else
          commonBoard[idx1][idx2] = std::max(commonBoard[idx1 - 1][idx2],
                                             commonBoard[idx1][idx2 - 1]);
      }
    }
    // showCommonBoard();
    return commonBoard[lenTxt1][lenTxt2];
  }
};
