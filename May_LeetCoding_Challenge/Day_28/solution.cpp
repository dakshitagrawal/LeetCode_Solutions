
/* 
    ---------------------------------------------------------------------------------------------------

    First try and optimal solution. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> counts;
        counts.push_back(0);
        int power = 1;

        for (int i = 1; i <= num; i++)
        {
            if (i == power * 2)
            {
                power *= 2;
                counts.push_back(1);
            }
            else
            {
                counts.push_back(1 + counts[i - power]);
            }
        }

        return counts;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try, this time taking into account
    that odd numbers just add a terminal '1' 
    bit to the previous number. Even numbers, 
    on the other hand, increase their `1` bit 
    count to the common part of their number 
    and previous number.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> counts(num + 1, 0);

        for (int i = 1; i <= num; i++)
        {
            counts[i] = counts[i & (i - 1)] + 1;
        }

        return counts;
    }
};
