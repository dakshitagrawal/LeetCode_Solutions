
/* 
    ---------------------------------------------------------------------------------------------------

    First try and optimal solution. Gave integer 
    overflow initially, changed to long. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int findComplement(int num)
    {
        long nearestTwo = 1;

        while (nearestTwo - 1 < num)
        {
            nearestTwo *= 2;
        }

        return nearestTwo - num - 1;
    }
};
