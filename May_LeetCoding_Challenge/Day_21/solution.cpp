
/* 
    ---------------------------------------------------------------------------------------------------

    First try. Brute force. TLE.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int maxLenx = matrix.size();
        int maxLeny = matrix[0].size();

        int maxLen = min(maxLenx, maxLeny);

        int count = 0;

        for (int i = 0; i < maxLen; i++)
        {
            int length = i + 1;

            for (int j = 0; j < maxLenx - length + 1; j++)
            {
                for (int l = 0; l < maxLeny - length + 1; l++)
                {

                    int valid = 1;

                    for (int k = j; k < j + length; k++)
                    {
                        for (int m = l; m < l + length; m++)
                        {

                            if (matrix[k][m] != 1)
                            {
                                valid = 0;
                            }
                        }
                    }

                    count += valid;
                }
            }
        }

        return count;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try. Observed that we can check if the 
    (n+1)-size square is possible by checking if 
    (n)-size square is possible at the left, top,
    and diagonal left-top. Accepted, but too much 
    memory and time taken.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int maxLenx = matrix.size();
        int maxLeny = matrix[0].size();
        int maxLen = min(maxLenx, maxLeny);
        int count = 0;

        for (int i = 0; i < maxLenx; i++)
        {
            for (int j = 0; j < maxLeny; j++)
            {
                count += matrix[i][j];
            }
        }

        for (int k = 1; k < maxLen; k++)
        {
            vector<vector<int>> squares(matrix);

            for (int i = k; i < maxLenx; i++)
            {
                for (int j = k; j < maxLeny; j++)
                {
                    int val = squares[i][j] & squares[i - 1][j] & squares[i][j - 1] & squares[i - 1][j - 1];
                    matrix[i][j] = val;
                    count += val;
                }
            }
        }

        return count;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third try. Observed space can be reduced by
    starting from the bottom right corner and 
    moving towards the top left corner. Accepted,
    and memory reduced by 95%. Time also halved.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int maxLenx = matrix.size();
        int maxLeny = matrix[0].size();
        int maxLen = min(maxLenx, maxLeny);
        int count = 0;

        for (int i = 0; i < maxLenx; i++)
        {
            for (int j = 0; j < maxLeny; j++)
            {
                count += matrix[i][j];
            }
        }

        for (int k = 1; k < maxLen; k++)
        {
            for (int i = maxLenx - 1; i >= k; i--)
            {
                for (int j = maxLeny - 1; j >= k; j--)
                {
                    int val = matrix[i][j] & matrix[i - 1][j] & matrix[i][j - 1] & matrix[i - 1][j - 1];
                    matrix[i][j] = val;
                    count += val;
                }
            }
        }

        return count;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fourth try. Couldn't think of better approach,
    saw the submitted solutions. Turns out you could
    count the number of squares the particular element
    is a bottom right corner of. Accepted, and complexity
    reduced from O(n^3) to O(n^2).

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int maxLenx = matrix.size();
        int maxLeny = matrix[0].size();
        int count = 0;

        for (int i = 1; i < maxLenx; i++)
        {
            for (int j = 1; j < maxLeny; j++)
            {
                if (matrix[i][j] == 0)
                {
                    continue;
                }

                matrix[i][j] = min(min(matrix[i - 1][j],
                                       matrix[i - 1][j - 1]),
                                   matrix[i][j - 1]) +
                               1;
            }
        }

        for (int i = 0; i < maxLenx; i++)
        {
            for (int j = 0; j < maxLeny; j++)
            {
                count += matrix[i][j];
            }
        }

        return count;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fifth try. Looked at other solutions, optimized
    the fourth try. More quicker.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int maxLenx = matrix.size();
        int maxLeny = matrix[0].size();
        int count = 0;

        for (int i = 0; i < maxLenx; i++)
        {
            for (int j = 0; j < maxLeny; j++)
            {

                if (matrix[i][j] && i * j)
                {
                    matrix[i][j] = min(min(matrix[i - 1][j],
                                           matrix[i - 1][j - 1]),
                                       matrix[i][j - 1]) +
                                   1;
                }

                count += matrix[i][j];
            }
        }

        return count;
    }
};
