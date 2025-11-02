// Integer to Roman - versi dengan prompt input yang jelas + loop
// Build: g++ -std=c++17 -O2 -Wall -Wextra -pedantic "%f" -o "%e"
// Run  : "%e"

#include <iostream>
#include <string>
#include <cctype>

std::string intToRoman(int num) {
    static const int   val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    static const char* sym[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    std::string ans;
    ans.reserve(15);
    for (int i = 0; i < 13; ++i) {
        int cnt = num / val[i];
        num %= val[i];
        while (cnt--) ans += sym[i];
        if (num == 0) break;
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << "=== Integer to Roman ===\n"
                 "Masukkan angka 1..3999 untuk dikonversi.\n"
                 "Ketik 'q' lalu Enter untuk keluar.\n\n";

    std::string line;
    while (true) {
        std::cout << "Input num (1..3999) atau 'q' untuk keluar: " << std::flush;

        if (!std::getline(std::cin, line)) {
            std::cerr << "\nInput tertutup. Keluar.\n";
            return 0;
        }
        // Trim spasi depan/belakang (simple)
        while (!line.empty() && std::isspace(static_cast<unsigned char>(line.front()))) line.erase(line.begin());
        while (!line.empty() && std::isspace(static_cast<unsigned char>(line.back())))  line.pop_back();

        if (line == "q" || line == "Q") {
            std::cout << "Bye!\n";
            break;
        }
        if (line.empty()) {
            std::cerr << "Error: input kosong. Coba lagi.\n";
            continue;
        }

        // Coba parse integer
        try {
            size_t pos = 0;
            int num = std::stoi(line, &pos);
            if (pos != line.size()) {
                std::cerr << "Error: ada karakter non-angka. Contoh valid: 3749\n";
                continue;
            }
            if (num < 1 || num > 3999) {
                std::cerr << "Error: harus 1..3999. Coba lagi.\n";
                continue;
            }
            std::string roman = intToRoman(num);
            std::cout << "Roman: " << roman << "\n\n";
        } catch (...) {
            std::cerr << "Error: input bukan angka valid. Contoh: 58, 1994, 3749\n";
        }
    }
    return 0;
}
