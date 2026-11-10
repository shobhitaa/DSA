/*
 * Problem : Remove Duplicates from Sorted Array
 * Link    : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * Pattern : Two pointers
 * Time    : O(N)
 * Space   : O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = left + 1;
        for (; right < n; right++) {
            if (nums[right] != nums[left]) {
                left++;
                nums[left] = nums[right];
            }
        }

        return left + 1;
    }
};

// ---- test harness: do not edit the logic above from here ----
static bool runTest(vector<int> nums, const vector<int>& expected) {
    Solution s;
    int k = s.removeDuplicates(nums);

    bool ok = (k == (int)expected.size());
    for (int i = 0; ok && i < k; i++) {
        if (nums[i] != expected[i]) ok = false;
    }

    cout << (ok ? "PASS" : "FAIL") << "  k=" << k << "  first k: [";
    for (int i = 0; i < k && i < (int)nums.size(); i++) {
        cout << nums[i] << (i + 1 < k ? "," : "");
    }
    cout << "]  expected k=" << expected.size() << "\n";
    return ok;
}

int main() {
    runTest({1, 1, 2}, {1, 2});
    runTest({0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, {0, 1, 2, 3, 4});
    runTest({5}, {5});
    runTest({1, 1, 1, 1, 1}, {1});
    runTest({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5});
    runTest({-2, -2, 0, 2, 2, 6, 7}, {-2, 0, 2, 6, 7});
    runTest({3, 4, 5, 5, 5, 5}, {3, 4, 5});
    runTest({4, 5}, {4, 5});
    runTest({4, 4}, {4});

    return 0;
}
