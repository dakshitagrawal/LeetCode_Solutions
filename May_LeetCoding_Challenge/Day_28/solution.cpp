
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
    
    Further Explanation:
    When the next even number comes, all bits 
    beyond the common part are changed to zero, 
    and the bit `1` is added just after the 
    common part.

    e.g. - 11 is 1011
           12 is 1100

           Basically there is a flip of all bits 
           beyond the common part between a 
           number and its predecessor, or in
           other terms, an addition of 1 to the 
           count of bits of the common part.

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
