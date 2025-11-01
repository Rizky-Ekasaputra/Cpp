class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t idx = 0;                          // idx = posisi tulis untuk elemen yang bukan 'val'
        for(size_t i = 0; i<nums.size(); i++) {  // i = posisi baca, iterasi seluruh array
            if(nums[i] != val)                   // kalau elemen sekarang bukan 'val'
                nums[idx++]=nums[i];             // salin ke depan (posisi idx), lalu geser idx
        }                                        // kalau sama dengan 'val', kita lewati saja
        return static_cast<int>(idx);            // k = banyaknya elemen yang bukan 'val'
    }
};