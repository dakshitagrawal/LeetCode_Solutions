
/* 
    ---------------------------------------------------------------------------------------------------

    First try, code could be optimized.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<bool> trusting(N, false);
        vector<int> trusted(N, N - 1);

        for (vector<int> point : trust)
        {
            trusting[point[0] - 1] = true;
            trusted[point[1] - 1] -= 1;
        }

        for (int i = 0; i < N; i++)
        {
            if (!trusting[i])
            {
                if (trusted[i] == 0)
                {
                    return i + 1;
                }
            }
        }

        return -1;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try, need only one vector now.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<int> trusted(N, 0);

        for (vector<int> point : trust)
        {
            trusted[point[0] - 1] -= 1;
            trusted[point[1] - 1] += 1;
        }

        for (int i = 0; i < N; i++)
        {
            if (trusted[i] == N - 1)
            {
                return i + 1;
            }
        }

        return -1;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third try, optimized by removing the subtraction by 1.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<int> trusted(N + 1, 0);

        for (vector<int> point : trust)
        {
            trusted[point[0]] -= 1;
            trusted[point[1]] += 1;
        }

        for (int i = 1; i < N + 1; i++)
        {
            if (trusted[i] == N - 1)
            {
                return i;
            }
        }

        return -1;
    }
};
