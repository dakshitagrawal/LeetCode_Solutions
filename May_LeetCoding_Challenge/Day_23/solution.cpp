
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
/*
    ---------------------------------------------------------------------------------------------------
    Algorithm:
 * consider two intervals [s1,e1], [s2,e2]
 * for intersection s2<=e1 and s1<=e2
 * intersecting interval = [max(s1,s2),min(e1,e2)]
 * for iteration in the list 
 * if A.second > B.second then bptr++ else aptr++
 
    ---------------------------------------------------------------------------------------------------
    */
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int sizeA = A.size();
        int sizeB = B.size();
        int aptr = 0;
        int bptr = 0;
		vector<vector<int>> res;
        vector<vector<int>> temp(2); //A variable to store intermidiate results

        while (Aptr < sizeA && j < sizeB)
        {	
			if(B[bptr][0]<=A[aptr][1] && A[aptr][0]<=B[bptr][1]) //check for intersection
			{
					temp[0]=max(A[aptr][0],B[bptr][0]);
					temp[1]=min(A[aptr][1],B[bptr][1]);
					res.push_back(temp); //pushing values in the result vector
			}
            //for iteration in the given list
					if(A[aptr][1]>B[bptr][1])
					{
						bptr++;
					}else{
						aptr++;
					}
		}
        return res;
    }
