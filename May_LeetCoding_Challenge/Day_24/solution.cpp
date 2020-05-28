
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

    First try and incorrect. Too many conditions,
    trying to be solved through if-else. While 
    recursing, focus on just the current node, not
    on the next ones.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    TreeNode *build(vector<int> &preorder, int &count, int pos, int &max)
    {
        TreeNode *node = new TreeNode(preorder[count]);
        if (preorder[count] > max)
        {
            max = preorder[count];
        }

        if (count == preorder.size() - 1)
        {
            return node;
        }

        if (preorder[count + 1] < node->val)
        {
            count++;
            node->left = build(preorder, count, pos + 1, max);
        }

        if (count == preorder.size() - 1)
        {
            return node;
        }

        if (preorder[count + 1] > node->val)
        {
            if (pos == 0)
            {
                count++;
                node->right = build(preorder, count, pos + 1, max);
            }
            else if (preorder[count + 1] < preorder[pos - 1])
            {
                count++;
                node->right = build(preorder, count, pos + 1, max);
            }
            else if (preorder[count + 1] > max && node->val == max)
            {
                count++;
                node->right = build(preorder, count, pos + 1, max);
            }
        }

        return node;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int count = 0;
        int max = -1;

        TreeNode *node = build(preorder, count, 0, max);

        return node;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try. Got the above try correct, although
    it's still looking at the current and next values.
    Gives rise to some unnecessary checks.
    Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    TreeNode *build(vector<int> &preorder, int &count, int max, int min)
    {
        count++;

        if (count == preorder.size())
        {
            return NULL;
        }

        TreeNode *node = new TreeNode(preorder[count]);

        if (count + 1 < preorder.size() && preorder[count + 1] < node->val && preorder[count + 1] > min)
        {
            node->left = build(preorder, count, node->val, min);
        }

        if (count + 1 < preorder.size() && preorder[count + 1] > node->val && preorder[count + 1] < max)
        {
            node->right = build(preorder, count, max, node->val);
        }

        return node;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int count = -1;

        return build(preorder, count, 100000001, 0);
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third try. Saw submitted solutions, and 
    accordingly optimized the second try, removing
    unnecessary checks and increasing the count
    only after the node was created. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    TreeNode *build(vector<int> &preorder, int &count, int max, int min)
    {
        if (count == preorder.size())
        {
            return NULL;
        }

        if (preorder[count] < min || preorder[count] > max)
        {
            return NULL;
        }

        TreeNode *node = new TreeNode(preorder[count]);
        count++;

        node->left = build(preorder, count, node->val, min);
        node->right = build(preorder, count, max, node->val);

        return node;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int count = 0;

        return build(preorder, count, 100000001, 0);
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fourth try. Tried changing from recursive to
    iterative approach. Used stacks, however incorrect
    solution. Tried fitting the max variable from 
    above solution, but couldn't find a way to do so.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        stack<TreeNode *> nodes;
        TreeNode *root = new TreeNode(preorder[0]);
        int max = preorder[0];

        nodes.push(root);

        TreeNode *inter;

        for (int i = 1; i < preorder.size(); i++)
        {
            TreeNode *node = new TreeNode(preorder[i]);

            if (nodes.empty())
            {
                inter->right = node;
                max = node->val;
                nodes.push(node);
            }
            else
            {
                if (node->val < nodes.top()->val)
                {
                    max = node->val;
                    nodes.top()->left = node;
                    nodes.push(node);
                }
                else
                {
                    while (node->val > max)
                    {
                        inter = nodes.top();
                        max = inter->val;
                        nodes.pop();
                    }

                    inter->right = node;
                    nodes.push(node);
                }
            }
        }

        return root;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fifth try. Saw submitted solutions, the maximum
    variable could be stored as the nodes present in
    the stack, i.e. remove all nodes with values less
    than `preorder[i]`. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        stack<TreeNode *> nodes;
        TreeNode *root = new TreeNode(preorder[0]);
        nodes.push(root);

        for (int i = 1; i < preorder.size(); i++)
        {
            TreeNode *temp = NULL;

            while (!nodes.empty() && nodes.top()->val < preorder[i])
            {
                temp = nodes.top();
                nodes.pop();
            }

            if (temp)
            {
                temp->right = new TreeNode(preorder[i]);
                nodes.push(temp->right);
            }
            else
            {
                nodes.top()->left = new TreeNode(preorder[i]);
                nodes.push(nodes.top()->left);
            }
        }

        return root;
    }
};
