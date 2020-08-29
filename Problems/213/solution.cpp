/*
   ---------------------------------------------------------------------------

   First try. Used DP to solve the problem. Had a loop for including either
   first element, or last element, or neither of the two. Accepted.

   ---------------------------------------------------------------------------
   */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int sol(vector<int> &nums)
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

        vector<int> a(length);

        a[0] = nums[0];
        a[1] = max(nums[0], nums[1]);

        for (int i = 2; i < length; i++)
        {
            a[i] = max(a[i - 1], a[i - 2] + nums[i]);
        }
        return a[length - 1];
    }

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

        if (length == 2)
        {
            return max(nums[1], nums[0]);
        }

        if (length == 3)
        {
            return max(nums[0], max(nums[1], nums[2]));
        }

        vector<int> withFirst(length - 3);
        for (int i = 0; i < length - 3; i++)
        {
            withFirst[i] = nums[i + 2];
        }

        vector<int> withLast(length - 3);
        for (int i = 0; i < length - 3; i++)
        {
            withLast[i] = nums[i + 1];
        }

        vector<int> withNeither(length - 2);
        for (int i = 0; i < length - 2; i++)
        {
            withNeither[i] = nums[i + 1];
        }

        int x = nums[0] + sol(withFirst);
        int y = nums[length - 1] + sol(withLast);
        int z = sol(withNeither);

        return max(x, max(y, z));
    }
};

/*
   ---------------------------------------------------------------------------

   Second try. Above solution contains one unnecessary check. Accepted.

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

        vector<int> a(length);

        a[0] = nums[0];
        a[1] = max(nums[0], nums[1]);

        for (int i = 2; i < length - 1; i++)
        {
            a[i] = max(a[i - 1], a[i - 2] + nums[i]);
        }

        int robbed = a[length - 2];

        a[0] = 0;
        a[1] = nums[1];

        for (int i = 2; i < length; i++)
        {
            a[i] = max(a[i - 1], a[i - 2] + nums[i]);
        }

        return max(robbed, a[length - 1]);
    }
};
