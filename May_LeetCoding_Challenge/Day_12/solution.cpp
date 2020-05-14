
/* 
    ---------------------------------------------------------------------------------------------------

    First try, already knew that the optimized solution for 
    unsorted array is to take the XOR of each number. However, 
    this is O(n) solution.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int xor_pr = 0;

        for (int number : nums)
        {
            xor_pr = xor_pr ^ number;
        }

        return xor_pr;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try, sorted array with O(log n) approach hinted at 
    binary search. It took many tries to get it right. Next time,
    make sure the base condition remains same in every iteration.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0;
        int h = nums.size();

        while (l < h)
        {
            int mid = (l + h) / 2;

            if ((l == h - 1) || (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid]))
            {
                return nums[mid];
            }

            if (nums[mid] == nums[mid - 1] && (mid - l) % 2 != 0)
            {
                l = mid + 1;
            }
            else if (nums[mid] == nums[mid + 1] && (h - mid) % 2 != 0)
            {
                l = mid + 2;
            }
            else if (nums[mid] == nums[mid - 1] && (mid - l) % 2 == 0)
            {
                h = mid - 1;
            }
            else
            {
                h = mid;
            }
        }

        return -1;
    }
};
