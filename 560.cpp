#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> prefixMap;
        prefixMap[0] = 1;
        int result = 0;
        int sum = 0;

        for (int const& number : nums) {
            sum += number;
            int difference = sum - k;

            if (prefixMap.count(difference) == 0) {
                prefixMap[sum]++;
            }
            else {
                result += prefixMap[difference];
                prefixMap[sum]++;
            }
        }

        return result;
    }
};

int main() {
    vector<int> numbers({1,1,1});
    int total = Solution::subarraySum(numbers, 2);
    cout << total << '\n';
    return 0;
}