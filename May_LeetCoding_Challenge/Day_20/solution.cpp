
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

    First try. Store inorder and return kth element.
    Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
private:
    vector<int> values;

public:
    void inorder(TreeNode *root, vector<int> &x)
    {
        if (root->left)
        {
            inorder(root->left, x);
        }

        x.push_back(root->val);

        if (root->right)
        {
            inorder(root->right, x);
        }

        return;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, values);

        return values[k - 1];
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try. Stop further recursive calls once 
    the kth smallest element has been found. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    void inorder(TreeNode *root, int &x, int &count)
    {
        if (root->left)
        {
            inorder(root->left, x, count);
        }

        if (count == 0)
        {
            return;
        }

        x = root->val;
        count--;

        if (count == 0)
        {
            return;
        }

        if (root->right)
        {
            inorder(root->right, x, count);
        }

        if (count == 0)
        {
            return;
        }

        return;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int value;

        inorder(root, value, k);

        return value;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third try. Removed redundant count checks. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    void inorder(TreeNode *root, int &x, int &count)
    {

        if (root->left && count)
        {
            inorder(root->left, x, count);
        }

        if (count)
        {
            x = root->val;
            count--;
        }

        if (root->right && count)
        {
            inorder(root->right, x, count);
        }

        return;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int value;

        inorder(root, value, k);

        return value;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fourth try. Turns out that you can go to the 
    left and right nodes. If the node doesn't exist,
    its NULL. Removed redundant left and right child
    checks. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    void inorder(TreeNode *root, int &x, int &count)
    {
        if (count == 0 || root == NULL)
        {
            return;
        }

        inorder(root->left, x, count);

        if (count)
        {
            x = root->val;
            count--;
        }

        inorder(root->right, x, count);

        return;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int value;

        inorder(root, value, k);

        return value;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fifth try. Turned recursion into iteration after
    checking the solution. Accepted.

    Note: `--variable` first subtracts 1, then checks.
          `variable--` first checks, then subtracts 1.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        vector<TreeNode *> nodes;

        while (k > 0)
        {
            while (root)
            {
                nodes.push_back(root);
                root = root->left;
            }

            root = nodes.back();
            nodes.pop_back();

            if (!--k)
            {
                return root->val;
            }

            root = root->right;
        }

        return -1;
    }
};
