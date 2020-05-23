
/* 
    ---------------------------------------------------------------------------------------------------

    First try. Counted even number of factors. TLE.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int num = 0;

    bool isPerfectSquare(int num)
    {
        vector<bool> factors_list(num, true);
        map<int, int> count;
        count[1] = 0;
        int i = 2;

        for (i; i <= num; i++)
        {
            if (factors_list[i - 1] == true && count[i - 1] != 0)
            {
                return false;
            }

            if (factors_list[i] == false)
            {
            }
            else if (num % i == 0)
            {
                if (!count[i])
                {
                    count[i] = 0;
                }

                num = num / i;
                count[i] += (count[i] == 0) ? 1 : -1;
                i--;
            }
            else
            {
                for (int j = 2 * i; j < num; j = j + i)
                {
                    factors_list[j] = false;
                }
            }
        }

        if (factors_list[i] == true && count[i] != 0)
        {
            return false;
        }

        return true;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try. Couldn't think of ways to find prime factors
    without putting limit as sqrt(num). Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        bool double_term = true;

        while (num % 2 == 0)
        {
            num /= 2;
            double_term = !double_term;
        }

        if (!double_term)
        {
            return false;
        }

        for (int i = 3; i <= sqrt(num); i = i + 2)
        {
            while (num % i == 0)
            {
                num /= i;
                double_term = !double_term;
            }

            if (!double_term)
            {
                return false;
            }
        }

        if (num > 2)
        {
            return false;
        }

        return true;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third try. Looked at the solution. Simple binary search 
    for the square root. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int l = 0;
        int r = num;

        while (l <= r)
        {
            double mid = l + (r - l) / 2;

            if (mid == num / mid)
            {
                return true;
            }
            else if (mid > num / mid)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return false;
    }
};
