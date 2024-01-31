#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {

        vector<vector<int>> reint;
        sort(nums.begin(), nums.end());
        uint32_t len = nums.size();
        int64_t target_1 = target;

        if (len < 4)
        {
            return reint;
        }
        if ((target>=0&&(*(nums.end()-1)<0))|| (target<0&&(*(nums.begin())>=0)))
            return reint;

        int pre = nums[0] - 1;

        for (uint32_t i = 0; i < len - 3; i++)
        {
            if (target >= 0 && nums[i] > target)
                break;

            if (target < 0 && nums[i] >= 0)
                break;

            if (nums[i] == pre)
                continue;
            else
                pre = nums[i];

            int pre_2 = nums[i + 1] - 1;
            for (uint32_t j = i + 1; j < len - 2; j++)
            {
                if (nums[j] == pre_2)
                    continue;
                else
                    pre_2 = nums[j];
                int64_t target_2 = target_1 - nums[i] - nums[j];

                uint32_t left = j + 1, right = len - 1;

                while (left < right)
                {
                    if (target_2 > 0 && nums[left] > target_2)
                        break;

                    if (target_2 < 0 && nums[left] >= 0)
                        break;

                    if (nums[left] + nums[right] < target_2)
                    {
                        left++;
                        while (nums[left] == nums[left - 1]&& left < right)
                            left++;
                    }
                    else if (nums[left] + nums[right] > target_2)
                    {
                        right--;
                        while (nums[right] == nums[right + 1]&& left < right)
                            right--;
                    }
                    else if (nums[left] + nums[right] == target_2)
                    {
                        reint.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        while (nums[left] == nums[left - 1] && left < right)
                            left++;
                        right--;
                        while (nums[right] == nums[right + 1]&& left < right)
                            right--;
                    }
                }
            }
        }
        return reint;
    }
};

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    Solution sol;
    vector<vector<int>> reint = sol.fourSum(nums, 0);
    for (auto a : reint)
    {
        for (auto n : a)
        {
            cout << n << ' ';
        }
        cout << endl;
    }
    return 0;
}
