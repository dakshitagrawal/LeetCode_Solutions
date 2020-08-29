/*
   ---------------------------------------------------------------------------

   First try. Used DP to solve the problem. Accepted.

   ---------------------------------------------------------------------------
   */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int rob(vector<int> &nums)
    {

        if (nums.size() == 0)
        {
            return 0;
        }

        if (nums.size() == 1)
        {
            return nums[0];
        }

        vector<int> a(nums.size());
        a[0] = nums[0];
        a[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++)
        {
            a[i] = max(a[i - 1], a[i - 2] + nums[i]);
        }

        return a[nums.size() - 1];
    }
};

/*
   ---------------------------------------------------------------------------

   Second try. Removed unnecessary vector. Accepted.

   ---------------------------------------------------------------------------
   */

class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        int length = nums.size();

        if (length == 0)
        {
            return 0;
        }

        if (length == 1)
        {
            return nums[0];
        }

        int sec_prev = nums[0];
        int fir_prev = max(nums[0], nums[1]);

        for (int i = 2; i < length; i++)
        {
            int temp = fir_prev;
            fir_prev = max(fir_prev, sec_prev + nums[i]);
            sec_prev = temp;
        }

        return fir_prev;
    }
};
