
/* 
    ---------------------------------------------------------------------------------------------------

    First try. Brute force, resulted in TLE. 
    Complexity is O(splog(p)). 

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    bool isAnagram(string test, string p)
    {
        sort(test.begin(), test.end());
        sort(p.begin(), p.end());

        if (test == p)
        {
            return true;
        }

        return false;
    }

    vector<int> findAnagrams(string s, string p)
    {

        vector<int> indices;

        int plen = p.length();
        int slen = s.length();

        for (int i = 0; i < slen - plen + 1; i++)
        {

            if (isAnagram(s.substr(i, plen), p))
            {
                indices.push_back(i);
            }
        }

        return indices;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try. Used maps to count characters, reducing
    the complexity to O(sp). Still resulted in TLE. 

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    bool isAnagram(string test, map<char, int> p_letters)
    {
        for (char letter : test)
        {
            p_letters[letter]--;
        }

        for (auto &element : p_letters)
        {
            if (element.second != 0)
            {
                return false;
            }
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p)
    {

        vector<int> indices;

        int plen = p.length();
        int slen = s.length();

        map<char, int> p_letters;

        for (char letter : p)
        {
            p_letters[letter]++;
        }

        for (int i = 0; i < slen - plen + 1; i++)
        {

            if (isAnagram(s.substr(i, plen), p_letters))
            {
                indices.push_back(i);
            }
        }

        return indices;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third try. Used Vectors instead of Maps. Sometimes 
    accepted, sometimes not. When accepted, used too 
    much memory and time.

    Note: int array can't be passed by value, a pointer 
    is automatically passed. However, vectors can be passed
    by value. Hence, use vectors over arrays whenever possible.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    void printArr(vector<int> array)
    {
        for (int element : array)
        {
            cout << element;
            cout << " ";
        }
        cout << endl;
    }

    bool isAnagram(string test, vector<int> p_letters)
    {

        for (char letter : test)
        {
            p_letters[letter - 'a']--;
        }

        for (int element : p_letters)
        {
            if (element != 0)
            {
                return false;
            }
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p)
    {

        int plen = p.length();
        int slen = s.length();

        vector<int> indices;
        vector<int> p_letters(26, 0);

        for (char letter : p)
        {
            p_letters[letter - 'a']++;
        }

        for (int i = 0; i < slen - plen + 1; i++)
        {

            if (isAnagram(s.substr(i, plen), p_letters))
            {
                indices.push_back(i);
            }
        }

        return indices;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fourth try. Removed recursive calls, and updated
    the letter count of a substring of s only at the 
    necessary places. Accepted, significant memory and 
    time usage drop.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {

        int plen = p.length();
        int slen = s.length();

        vector<int> indices;
        vector<int> p_letters(26, 0);
        vector<int> test(26, 0);

        if (slen < plen)
        {
            return indices;
        }

        for (char letter : p)
        {
            p_letters[letter - 'a']++;
        }

        for (int i = 0; i < plen; i++)
        {
            test[s[i] - 'a']++;
        }

        for (int i = 0; i < slen - plen + 1; i++)
        {

            if (i > 0)
            {
                test[s[i - 1] - 'a']--;
                test[s[i + plen - 1] - 'a']++;
            }

            bool anagram = true;

            for (int j = 0; j < 26; j++)
            {
                if (p_letters[j] != test[j])
                {
                    anagram = false;
                    continue;
                }
            }

            if (anagram)
            {
                indices.push_back(i);
            }
        }

        return indices;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fifth try. Clubbed the iterating loops of s string 
    together. Also, learned that vectors can be compared
    directly. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {

        int plen = p.length();
        int slen = s.length();

        vector<int> indices;
        vector<int> p_letters(26, 0);
        vector<int> test(26, 0);

        if (slen < plen)
        {
            return indices;
        }

        for (char letter : p)
        {
            p_letters[letter - 'a']++;
        }

        for (int i = 0; i < slen; i++)
        {

            test[s[i] - 'a']++;

            if (i >= plen)
            {
                test[s[i - plen] - 'a']--;
            }

            if (p_letters == test)
            {
                indices.push_back(i - plen + 1);
            }
        }

        return indices;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Sixth try. Saw the solution, reduced the comparison betweeen 
    vectors by introducing an integer to count the number of 
    letters in the substring of s that matches with p. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {

        int plen = p.length();
        int slen = s.length();

        vector<int> indices;
        vector<int> p_letters(26, 0);
        vector<int> test(26, 0);

        if (slen < plen)
        {
            return indices;
        }

        for (char letter : p)
        {
            p_letters[letter - 'a']++;
        }

        int match = 0;

        for (int i = 0; i < slen; i++)
        {
            int inLetter = s[i] - 'a';

            test[inLetter]++;

            if (test[inLetter] <= p_letters[inLetter])
            {
                match++;
            }

            if (i >= plen)
            {
                int outLetter = s[i - plen] - 'a';
                test[outLetter]--;

                if (test[outLetter] < p_letters[outLetter])
                {
                    match--;
                }
            }

            if (match == plen)
            {
                indices.push_back(i - plen + 1);
            }
        }

        return indices;
    }
};
