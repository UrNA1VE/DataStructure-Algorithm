// https://leetcode.com/problems/decode-the-slanted-ciphertext/

class Solution {
public:

    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;
        
        
        int n = encodedText.length(), cols = n / rows;
        vector<vector<char>> text(rows, vector<char> (cols));
        int k = 0, i, j;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                text[i][j] = encodedText[k++];
            }
        }
        

        string res = "";
        for (k = 0; k < cols; k++) {
            i = 0;
            j = k;
            while (i < rows && j < cols) {
                res += text[i++][j++];
            }
        }
        while (res.back() == ' ') {
            res.pop_back();
        }
        
        return res;
    }
};
