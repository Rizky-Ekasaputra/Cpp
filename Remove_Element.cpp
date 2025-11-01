#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int removeElement(vector<int>& nums, int val){
    int k = 0;
    for (int x : nums) if (x != val) nums[k++] = x;
    return k;
}

int main() {

    int n;
    cout << "Masukkan jumlah elemen (n): ";
    while (!(cin >> n) || n < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input n tidak valid. Masukkan n (>= 0): ";
    }

    vector<int> nums(n);
    cout << "Masukkan " << n << " angka dipisah spasi/enter:\n";
    for (int i = 0; i < n; ++i) {
        cout << "  angka ke-" << (i+1) << ": ";
        while (!(cin >> nums[i])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Ulangi angka ke-" << (i+1) << ": ";
        }
    }

    int val;
    cout << "Masukkan nilai val yang ingin dihapus: ";
    while (!(cin >> val)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukkan val: ";
    }

    int k = removeElement(nums, val);

    cout << "\nHasil:\n";
    cout << "k = " << k << "\nnums = [";
    for (int i = 0; i < n; ++i) cout << (i ? "," : "") << (i < k ? to_string(nums[i]) : "_");
    cout << "]\n";
}
