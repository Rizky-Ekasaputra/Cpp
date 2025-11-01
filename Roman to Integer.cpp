#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<char,int> roman = {                  // peta simbol Romawi → nilai
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int romanToInt(const string& s) {                  // konversi string Romawi → integer | const reference
        int res = 0, i = 0;                            // res: akumulator hasil, i: indeks berjalan
        int n = (int)s.size();                         // n: panjang string (biar tak hitung ulang)

        while (i < n - 1) {                            // proses berpasangan: s[i] & s[i+1]
            int a = roman.at(s[i]);                    // a: nilai simbol saat ini
            int b = roman.at(s[i + 1]);                // b: nilai simbol berikutnya
            if (a < b) {                               // kasus subtractive (contoh: IV, IX, XL, CM)
                res += (b - a);                        // tambah selisih (besar - kecil)
                i += 2;                                // lompat 2 karena sepasang sudah dipakai
            } else {                                   
                res += a;                              // kasus normal: tambahkan nilai sekarang
                i += 1;                                // maju 1 karakter
            }
        }

        if (i < n) {                                   // jika tersisa 1 karakter di akhir
            res += roman.at(s[i]);                     // tambahkan nilai karakter terakhir
        }
        return res;                                    // kembalikan hasil akhir
    }
};
