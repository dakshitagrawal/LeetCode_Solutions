
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/* 
    ---------------------------------------------------------------------------------------------------

    First try. Created separate functions for finding
    the node and finding the parent. Passing by value 
    gave lots of problems in the return value. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int find(TreeNode *root, int x, int level, int outcome)
    {

        if (root->val == x)
        {
            return level;
        }

        if (root->left)
        {
            outcome = find(root->left, x, level + 1, outcome);
        }

        if (root->right)
        {
            outcome = find(root->right, x, level + 1, outcome);
        }

        return outcome;
    }

    int parent(TreeNode *root, int x, int par)
    {
        if (root->left == 0 && root->right == 0)
        {
            return par;
        }

        if (root->left)
        {
            if (root->left->val == x)
            {
                return root->val;
            }
            par = parent(root->left, x, par);
        }

        if (root->right)
        {
            if (root->right->val == x)
            {
                return root->val;
            }
            par = parent(root->right, x, par);
        }

        return par;
    }

    bool isCousins(TreeNode *root, int x, int y)
    {

        int levelx = find(root, x, 0, 0);
        int parx = parent(root, x, 0);

        int levely = find(root, y, 0, 0);
        int pary = parent(root, y, 0);

        if (levelx == levely && parx != pary)
        {
            return true;
        }

        return false;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try. Clubbed four function calls into one. 
    Also used pass by reference. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    void find(TreeNode *root, int x, int y, int level, int par, int &parx, int &pary, int &outcomex, int &outcomey)
    {

        if (root->val == x)
        {
            outcomex = level;
            parx = par;
        }

        if (root->val == y)
        {
            outcomey = level;
            pary = par;
        }

        if (root->left)
        {
            find(root->left, x, y, level + 1, root->val, parx, pary, outcomex, outcomey);
        }

        if (root->right)
        {
            find(root->right, x, y, level + 1, root->val, parx, pary, outcomex, outcomey);
        }
    }

    bool isCousins(TreeNode *root, int x, int y)
    {
        int parx = -1;
        int pary = -1;
        int outcomex = -1;
        int outcomey = -1;

        find(root, x, y, 0, -1, parx, pary, outcomex, outcomey);

        if (outcomex == outcomey && parx != pary)
        {
            return true;
        }

        return false;
    }
};
