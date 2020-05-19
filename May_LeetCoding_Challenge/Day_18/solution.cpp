
/* 
    ---------------------------------------------------------------------------------------------------

    Similar to Day 17. So directly wrote the optimal solution.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();

        if (len1 > len2)
        {
            return false;
        }

        vector<int> s1_letters(26, 0);

        for (char letter : s1)
        {
            s1_letters[letter - 'a']++;
        }

        vector<int> s2_letters(26, 0);
        int matches = 0;

        for (int i = 0; i < len2; i++)
        {
            int newLetter = s2[i] - 'a';
            s2_letters[newLetter]++;

            if (s2_letters[newLetter] <= s1_letters[newLetter])
            {
                matches++;
            }

            if (i >= len1)
            {
                int outLetter = s2[i - len1] - 'a';
                s2_letters[outLetter]--;

                if (s2_letters[outLetter] < s1_letters[outLetter])
                {
                    matches--;
                }
            }

            if (matches == len1)
            {
                return true;
            }
        }

        return false;
    }
};
