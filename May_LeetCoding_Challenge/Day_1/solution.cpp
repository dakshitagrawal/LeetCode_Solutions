// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

/* 
    ---------------------------------------------------------------------------------------------------

    First try, brute force.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int firstBadVersion(int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (isBadVersion(i + 1))
            {
                return i + 1;
            }
        }
        return -1;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try, optimized using binary search.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int start = 1;
        int end = n;
        int pointer;

        while (start < end)
        {
            pointer = (end - start) / 2 + start;

            if (isBadVersion(pointer))
            {
                end = pointer;
            }
            else
            {
                start = pointer + 1;
            }
        }

        return end;
    }
};
