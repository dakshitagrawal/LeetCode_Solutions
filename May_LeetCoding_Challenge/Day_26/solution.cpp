
/* 
    ---------------------------------------------------------------------------------------------------

    First try, brute force. O(n^2), hence TLE.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        vector<int> counter;
        int count = 0;
        counter.push_back(count);

        for (int num : nums)
        {
            count += (num == 0) ? 1 : -1;

            counter.push_back(count);
        }

        int lastZero = 0;
        int maxLength = 0;

        for (int i = 0; i < counter.size(); i++)
        {
            for (int j = i + maxLength; j < counter.size(); j++)
            {
                if (counter[j] == counter[i] && maxLength < j - i)
                {
                    maxLength = j - i;
                }
            }
        }

        return maxLength;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try, thought of counting the net
    number of zeros and ones since beginning. 
    The solution would be largest difference in 
    index between same numbers. O(n^2), hence TLE.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int numSize = nums.size();

        vector<int> counter;

        int count = 0;
        counter.push_back(count);

        for (int num : nums)
        {
            count += (num == 0) ? 1 : -1;
            counter.push_back(count);
        }

        int maxLength = 0;

        for (int i = 0; i <= numSize - maxLength; i++)
        {
            for (int j = i + maxLength; j <= numSize; j++)
            {
                if (counter[j] == counter[i])
                {
                    maxLength = j - i;
                }
            }
        }

        return maxLength;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third try, thought of something along 
    Katane's algorithm. Futile attempt.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int numSize = nums.size();

        for (int i = 0; i < numSize; i++)
        {
            if (nums[i] == 0)
            {
                nums[i] = -1;
            }
        }

        int maxSize = 0;
        int curr = 0;
        int start = 0;
        int end = 0;

        for (int i = 0; i < numSize; i++)
        {
            int x = nums[i];

            if (abs(curr + x) <= abs(x))
            {
                curr = curr + x;
                end = i;
            }
            else
            {
                curr = x;
                start = i;
                end = i;
            }

            if (curr == 0 && maxSize <= end - start + 1)
            {
                maxSize = end - start + 1;
            }
        }

        return maxSize;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fourth try, looked at the solution. Turns
    out the second attempt was close, and an
    array or map could be used to store the 
    first occurance of a particular count, and
    calculate the maxLength on the basis of that.
    O(n) and hence accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int numSize = nums.size();

        vector<int> counter(2 * numSize + 1, -1);
        int maxLength = 0;
        int count = numSize;
        counter[count] = 0;

        for (int i = 0; i < numSize; i++)
        {
            count += (nums[i] == 0) ? 1 : -1;

            if (counter[count] == -1)
            {
                counter[count] = i + 1;
            }
            else
            {
                maxLength = max(i + 1 - counter[count], maxLength);
            }
        }

        return maxLength;
    }
};
