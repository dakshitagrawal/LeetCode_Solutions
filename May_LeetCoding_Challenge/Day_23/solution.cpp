
/* 
    ---------------------------------------------------------------------------------------------------

    First try and optimal complexity. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int lengthA = A.size();
        int lengthB = B.size();
        int j = 0;
        int i = 0;

        vector<vector<int>> intervals;

        while (i < lengthA && j < lengthB)
        {
            int begin = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);

            if (A[i][1] <= B[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }

            if (begin <= end)
            {
                intervals.push_back(vector<int>({begin, end}));
            }
        }

        return intervals;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try. Looked at the solution, added some 
    checks to reduce unnecessary caluclations. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int lengthA = A.size();
        int lengthB = B.size();
        int j = 0;
        int i = 0;

        vector<vector<int>> intervals;

        while (i < lengthA && j < lengthB)
        {
            if (A[i][0] > B[j][1])
            {
                j++;
            }
            else if (B[j][0] > A[i][1])
            {
                i++;
            }
            else
            {
                int begin = max(A[i][0], B[j][0]);
                int end = min(A[i][1], B[j][1]);

                if (A[i][1] < B[j][1])
                {
                    i++;
                }
                else if (B[j][1] < A[i][1])
                {
                    j++;
                }
                else
                {
                    i++;
                    j++;
                }

                intervals.push_back(vector<int>({begin, end}));
            }
        }

        return intervals;
    }
};
