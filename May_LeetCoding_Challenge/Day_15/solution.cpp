
/* 
    ---------------------------------------------------------------------------------------------------

    First try. Accounted for just the last element
    being at the front. The whole array can be at the
    front in a circular array.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        int len = A.size();

        vector<int> cirA;

        for (int i = 0; i < len; i++)
        {
            cirA.push_back(A[i]);
        }

        for (int i = 0; i < len - 1; i++)
        {
            cirA.push_back(A[i]);
        }

        vector<int> sumForward(len + 1);
        vector<int> sumBackward(len + 1);

        sumForward[0] = 0;
        sumBackward[0] = 0;

        sumBackward[1] = A[len - 1];
        sumForward[1] = A[0];

        for (int i = 2; i < len + 1; i++)
        {
            sumForward[i] = sumForward[i - 1] + A[i - 1];
            sumBackward[i] = sumBackward[i - 1] + A[i - 2];
        }

        int maxiSum = sumForward[1];

        for (int i = 0; i < len + 1; i++)
        {
            for (int j = i + 1; j < len + 1; j++)
            {
                if (sumForward[j] - sumForward[i] > maxiSum)
                {
                    maxiSum = sumForward[j] - sumForward[i];
                }

                if (sumBackward[j] - sumBackward[i] > maxiSum)
                {
                    maxiSum = sumBackward[j] - sumBackward[i];
                }
            }
        }

        return maxiSum;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try. Wrote brute force solution. The complexity 
    is at O(n^2), resulting in TLE. Keeping a separate array
    `sumForward`, in which `sumForward[i] = sum from first 
    element to ith element`.  

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        int len = A.size();

        vector<int> sumForward(2 * len);
        sumForward[0] = 0;

        for (int i = 1; i < 2 * len; i++)
        {
            if (i > len)
            {
                sumForward[i] = sumForward[i - 1] + A[i - 1 - len];
            }
            else
            {
                sumForward[i] = sumForward[i - 1] + A[i - 1];
            }
        }

        int maxiSum = sumForward[1];

        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j <= i + len; j++)
            {
                if (sumForward[j] - sumForward[i] > maxiSum)
                {
                    maxiSum = sumForward[j] - sumForward[i];
                }
            }
        }

        return maxiSum;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third try. Hypothesized that the max sum would either
    be the current element, or it's addition with the previous
    best sum. Turned out to be wrong, it's not necessary the 
    best sum always contains the current last element. 
    Added some more code to deal with the circular array constraints.
    Not accepted. 

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        int len = A.size();

        vector<int> cirA(2 * len - 1);

        for (int i = 0; i < 2 * len - 1; i++)
        {
            if (i >= len)
            {
                cirA[i] = A[i - len];
            }
            else
            {
                cirA[i] = A[i];
            }
        }

        int start = 0;
        int end = 0;
        int sum = cirA[start];

        int startSum = cirA[start];

        for (int i = 1; i < 2 * len - 1; i++)
        {

            int pseudoStart = start;
            startSum += cirA[i];
            int pseudoStartSum = startSum;
            int pseudoStartSumMax = startSum;

            if (i - start >= len)
            {
                startSum -= cirA[i - len];
                pseudoStart = i - len + 1;
                pseudoStartSum -= cirA[i - len];
                pseudoStartSumMax -= cirA[i - len];

                for (int j = pseudoStart; j < i; j++)
                {
                    pseudoStartSum -= cirA[j];

                    if (pseudoStartSum >= pseudoStartSumMax)
                    {
                        pseudoStart = j + 1;
                        pseudoStartSumMax = pseudoStartSum;
                    }
                }
            }

            if (pseudoStartSumMax >= sum)
            {
                start = pseudoStart;
                end = i;
                sum = pseudoStartSumMax;
                startSum = pseudoStartSumMax;
            }

            if (cirA[i] >= sum)
            {
                start = i;
                end = i;
                sum = cirA[i];
                startSum = cirA[i];
            }
        }

        return sum;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fourth try. Could not submit on time, or devise a 
    solution. So looked at LeetCode solutions. Turns out
    the above hypothesis was a part of Kadane's algorithm.
    The thing I didn't pick up was to take the max of all
    max sums containing the element 'j' as its last.

    The circular array could be thought of as two intervals,
    or the whole array with a continuous subarray cut out.
    Wrote this code after reading the solutions. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        int len = A.size();

        int ans = A[0];
        int cur = 0;
        int total_sum = 0;

        for (int num : A)
        {
            total_sum += num;
            cur = num + max(0, cur);
            ans = max(ans, cur);
        }

        cur = 0;
        int ans2 = 0;

        // last element always present in sum
        for (int i = 0; i < len - 1; i++)
        {
            cur = A[i] + min(0, cur);
            ans2 = min(cur, ans2);
        }

        // first element always present in sum
        cur = 0;
        int ans3 = 0;

        for (int i = 0; i < len - 1; i++)
        {
            cur = A[i] + min(0, cur);
            ans3 = min(cur, ans3);
        }

        ans = max(ans, total_sum - ans2);
        return max(ans, total_sum - ans3);
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fifth try. Removed the unncessary calculation of the circular
    array always containing the first element, since that was
    calculated in the normal Kadane's algorithm. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        int ans = A[0];
        int cur = 0;
        int total_sum = 0;

        for (int num : A)
        {
            total_sum += num;
            cur = num + max(0, cur);
            ans = max(ans, cur);
        }

        cur = 0;
        int ans2 = 0;

        // last element always present in sum
        for (int i = 1; i < A.size() - 1; i++)
        {
            cur = A[i] + min(0, cur);
            ans2 = min(cur, ans2);
        }

        return max(ans, total_sum - ans2);
    }
};
