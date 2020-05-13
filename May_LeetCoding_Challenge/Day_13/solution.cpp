
/* 
    ---------------------------------------------------------------------------------------------------

    First try, num was 10000 digit long, so stoi overflow.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {

        if (num.length() == k)
        {
            return "0";
        }

        int low = stoi(num);

        for (int j = 0; j < k; j++)
        {

            for (int i = 0; i < num.length(); i++)
            {
                string new_num = num;

                new_num.erase(new_num.begin() + i);

                if (stoi(new_num) < low)
                {
                    low = stoi(new_num);
                }
            }
            num = to_string(low);
        }

        return num;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try, attempt to remove stoi overflow.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {

        if (num.length() == k)
        {
            return "0";
        }

        for (int j = 0; j < k; j++)
        {
            int index = 0;
            double less = stoi(num.substr(0, 1));

            for (int i = 1; i < num.length(); i++)
            {
                less *= 10.0;

                double now_less = stod(num.substr(index, i - index)) * 9.0 + stod(num.substr(i, 1));

                if (now_less > less)
                {
                    index = i;
                    less = num[i];
                }
            }
            num.erase(num.begin() + index);
        }

        while (num[0] == '0' && num.length() != 1)
        {
            num.erase(num.begin());
        }

        return num;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third try, finally understood that the first element which is greater 
    than either of its neighbors needs to be removed.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {

        if (num.length() == k)
        {
            return "0";
        }

        for (int j = 0; j < k; j++)
        {
            bool found = true;
            int i = 0;
            int len = num.length();

            while (found && i < len)
            {
                if (num[i] <= num[i + 1])
                {
                    i += 1;
                }
                else
                {
                    found = false;
                    num.erase(num.begin() + i);
                }
            }
        }

        while (num[0] == '0' && num.length() != 1)
        {
            num.erase(num.begin());
        }

        return num;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fourth try, optimized above code, removed the for-loop.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {

        if (num.length() == k)
        {
            return "0";
        }

        int i = 0;
        int len = num.length();

        while (k && i < len)
        {
            if (num[i] <= num[i + 1])
            {
                i++;
            }
            else
            {
                k--;
                num.erase(num.begin() + i);
                i -= (i != 0) ? 1 : 0;
                len--;
            }
        }

        while (num[0] == '0' && num.length() != 1)
        {
            num.erase(num.begin());
        }

        return num;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fifth try, had a look at the solution, removed the .erase() function.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {

        int len = num.length();

        if (len == k)
        {
            return "0";
        }

        string res = "";

        for (char d : num)
        {
            while (k && res.length() && res.back() > d)
            {
                res.pop_back();
                k--;
            }

            res.push_back(d);
        }

        int zeros = 0;

        while (res[zeros] == '0' && zeros < res.length() - 1)
        {
            zeros++;
        }

        return res.substr(zeros, res.length() - k);
    }
};
