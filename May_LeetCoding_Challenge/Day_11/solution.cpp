
/* 
    ---------------------------------------------------------------------------------------------------

    First try, code could be better.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int color;
    int lengthy;
    int lengthx;

    bool check(int coordinate, int length)
    {
        if (0 > coordinate || coordinate >= length)
        {
            return true;
        }
        return false;
    }

    void onceFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int up = check(sr - 1, lengthy) ? -1 : image[sr - 1][sc];
        int down = check(sr + 1, lengthy) ? -1 : image[sr + 1][sc];
        int left = check(sc - 1, lengthx) ? -1 : image[sr][sc - 1];
        int right = check(sc + 1, lengthx) ? -1 : image[sr][sc + 1];

        image[sr][sc] = newColor;

        if (up != color && left != color && down != color && right != color)
        {
            return;
        }

        if (up != -1 && up == color && up != newColor)
        {
            //cout << "up" << endl;

            image[sr - 1][sc] = newColor;
            onceFill(image, sr - 1, sc, newColor);
        }

        if (left != -1 && left == color && left != newColor)
        {
            //cout << "left" << endl;

            image[sr][sc - 1] = newColor;
            onceFill(image, sr, sc - 1, newColor);
        }

        if (down != -1 && down == color && down != newColor)
        {
            //cout << "down" << endl;

            image[sr + 1][sc] = newColor;
            onceFill(image, sr + 1, sc, newColor);
        }

        if (right != -1 && right == color && right != newColor)
        {
            //cout << "right" << endl;

            image[sr][sc + 1] = newColor;
            onceFill(image, sr, sc + 1, newColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        color = image[sr][sc];
        lengthy = image.size();
        lengthx = image[0].size();

        onceFill(image, sr, sc, newColor);

        return image;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try after checking solution. This applies DFS with a seperate visited boolean array.
    
    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int color;
    int lengthy;
    int lengthx;

    void onceFill(vector<vector<int>> &image, vector<vector<bool>> &visited, int sr, int sc, int newColor)
    {
        if (sr >= lengthy || sr < 0 || sc >= lengthx || sc < 0 || visited[sr][sc] == true || image[sr][sc] != color)
        {
            return;
        }

        visited[sr][sc] = true;
        image[sr][sc] = newColor;

        onceFill(image, visited, sr - 1, sc, newColor);
        onceFill(image, visited, sr, sc - 1, newColor);
        onceFill(image, visited, sr + 1, sc, newColor);
        onceFill(image, visited, sr, sc + 1, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        color = image[sr][sc];
        lengthy = image.size();
        lengthx = image[0].size();

        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));

        onceFill(image, visited, sr, sc, newColor);

        return image;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third and final try. This applies recursion in a clean way.
    
    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int color;
    int lengthy;
    int lengthx;

    void onceFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (sr >= lengthy || sr < 0 || sc >= lengthx || sc < 0 || image[sr][sc] != color)
        {
            return;
        }

        image[sr][sc] = newColor;

        onceFill(image, sr - 1, sc, newColor);
        onceFill(image, sr, sc - 1, newColor);
        onceFill(image, sr + 1, sc, newColor);
        onceFill(image, sr, sc + 1, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        color = image[sr][sc];
        lengthy = image.size();
        lengthx = image[0].size();

        if (image[sr][sc] != newColor)
        {
            onceFill(image, sr, sc, newColor);
        }

        return image;
    }
};