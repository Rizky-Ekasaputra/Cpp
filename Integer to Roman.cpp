class Solution {
public:
    string intToRoman(int num) {
        static const int    val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        static const char*  sym[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string ans;
        ans.reserve(15); // panjang maksimum output untuk 1..3999

        for (int i = 0; i < 13; ++i) {
            int cnt = num / val[i];
            num %= val[i];
            while (cnt--) ans += sym[i];
            if (num == 0) break;
        }
        return ans;
    }
};
