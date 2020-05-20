
/* 
    ---------------------------------------------------------------------------------------------------

    First try. The majority element would be
    the middle element in sorted array. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        return nums[nums.size() / 2];
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try. Store count of each number in 
    Maps. Runs in O(n) time and O(n) space. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> counter;
        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            counter[nums[i]]++;
            if (counter[nums[i]] > len / 2)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third try. Looked at the solution. Majority
    element would outweigh every other element.
    Runs in O(n) time and O(1) space. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int majority = nums[0];
        int count = 0;

        for (int i : nums)
        {
            majority = (count == 0) ? i : majority;
            count += (i == majority) ? 1 : -1;
        }

        return majority;
    }
};
