
/* 
    ---------------------------------------------------------------------------------------------------

    First try. Had separate condition when x coordinates
    were same. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {

        if (coordinates[0][0] == coordinates[1][0])
        {
            float val = coordinates[0][0];
            for (vector<int> point : coordinates)
            {
                if (point[0] != val)
                {
                    return false;
                }
            }
            return true;
        }

        float slope = (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        float intercept = coordinates[0][1] - slope * coordinates[0][0];

        for (vector<int> point : coordinates)
        {
            if (slope * point[0] + intercept != point[1])
            {
                return false;
            }
        }

        return true;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try. Got to know that division by zero is valid
    in variable type `double`. Added basic condition. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {

        if (coordinates.size() == 2)
        {
            return true;
        }

        double n = coordinates[1][1] - coordinates[0][1];
        double d = coordinates[1][0] - coordinates[0][0];
        double slope = n / d;
        double intercept = coordinates[0][1] - slope * coordinates[0][0];

        for (vector<int> point : coordinates)
        {
            if (slope * point[0] + intercept != point[1])
            {
                return false;
            }
        }

        return true;
    }
};
