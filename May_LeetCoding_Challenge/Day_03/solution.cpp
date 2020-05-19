
/* 
    ---------------------------------------------------------------------------------------------------

    First try, used Maps. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.length() > magazine.length())
        {
            return false;
        }

        map<char, int> count;

        for (char letter : magazine)
        {
            count[letter]++;
        }

        for (char letter : ransomNote)
        {
            count[letter]--;
            if (count[letter] == -1)
            {
                return false;
            }
        }

        return true;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try, used Arrays instead of Maps. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.length() > magazine.length())
        {
            return false;
        }

        int count[26] = {0};

        for (char letter : magazine)
        {
            count[int(letter) - 97]++;
        }

        for (char letter : ransomNote)
        {
            count[int(letter) - 97]--;
            if (count[int(letter) - 97] == -1)
            {
                return false;
            }
        }

        return true;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third try, removed redundant int conversion of 
    character. C++ does it internally. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.length() > magazine.length())
        {
            return false;
        }

        int count[26] = {0};

        for (char letter : magazine)
        {
            count[letter - 97]++;
        }

        for (char letter : ransomNote)
        {
            count[letter - 97]--;
            if (count[letter - 97] == -1)
            {
                return false;
            }
        }

        return true;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fourth try, looked at the solutions to understand
    how the runtimes could be faster. Turns out the
    following two lines result in significant speedup.

    `ios_base::sync_with_stdio(false);`
    `cin.tie(0);`

    Read this for further details:
    https://www.geeksforgeeks.org/fast-io-for-competitive-programming/

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    bool canConstruct(string r, string mag)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        vector<int> vr(26, 0), vm(26, 0);

        for (char c : r)
        {
            vr[c - 'a']++;
        }

        for (char c : mag)
        {
            vm[c - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (vm[i] < vr[i])
            {
                return false;
            }
        }

        return true;
    }
};
