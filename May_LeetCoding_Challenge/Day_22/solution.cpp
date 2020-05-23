
/* 
    ---------------------------------------------------------------------------------------------------

    First try. Overcomplicated. Tried figuring
    out a way to count the characters, and then
    sorting them according to frequency. However,
    this did not print all of the same characters
    together in an answer, rather it printed them 
    in the order they appeared.

    e.g. for "loveleetcode" the output was "eeeelolovtcd"
    instead of "eeeeoollvtdc".

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> counter;
        vector<char> result;
        vector<char> leftover;

        for (char a : s)
        {
            counter[a]++;
        }

        for (char a : s)
        {

            for (int i = result.size() - 1; i >= 0; i--)
            {
                char b = result[i];
                if (counter[b] < counter[a])
                {
                    leftover.push_back(result.back());
                    result.pop_back();
                }
            }

            result.push_back(a);

            for (int i = leftover.size() - 1; i >= 0; i--)
            {
                char c = leftover[i];
                result.push_back(c);
                leftover.pop_back();
            }
        }

        string finalRes = "";

        for (char a : result)
        {
            finalRes.push_back(a);
        }

        return finalRes;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try. Maintained vector to keep count.
    Searched vector each time to check if character
    existed or not, and increased count. Searched 
    online on making a custom sort function. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    string frequencySort(string s)
    {
        vector<pair<char, int>> counter;
        string result = "";

        for (char a : s)
        {
            bool found = false;

            for (int i = 0; i < counter.size(); i++)
            {
                if (counter[i].first == a)
                {
                    found = true;
                    counter[i].second += 1;
                    break;
                }
            }

            if (!found)
            {
                counter.push_back({a, 1});
            }
        }

        sort(counter.begin(), counter.end(), [](const pair<char, int> &l, const pair<char, int> &r) {
            if (r.second != l.second)
            {
                return r.second < l.second;
            }
            return r.first < l.first;
        });

        for (auto a : counter)
        {
            for (int i = 0; i < a.second; i++)
            {
                result += a.first;
            }
        }

        return result;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third try. Saw solution, turns out vector can 
    be sorted in reverse using `rbegin` and `rend`,
    if the first element in pair is an integer.
    Also, strings can be concatenated directly, using
    their constructor instead of looping `count` times.
    Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    string frequencySort(string s)
    {
        vector<pair<int, char>> counter;
        string result = "";

        for (char a : s)
        {
            int found = -1;

            for (int i = 0; i < counter.size(); i++)
            {
                if (counter[i].second == a)
                {
                    found = i;
                    break;
                }
            }

            if (found != -1)
            {
                counter[found].first += 1;
            }
            else
            {
                counter.push_back({1, a});
            }
        }

        sort(counter.rbegin(), counter.rend());

        for (auto a : counter)
        {
            result += string(a.first, a.second);
        }

        return result;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fourth try. Saw solution, leverage fact
    that there can be only 2^8 characters. 
    Complexity reduced from O(n^2) to O(nlog(n)).
    Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    string frequencySort(string s)
    {
        int count[256] = {0};
        vector<pair<int, char>> characters;
        string result = "";

        for (char a : s)
        {
            count[a]++;
        }

        for (int i = 0; i < 256; i++)
        {
            if (count[i])
            {
                characters.push_back({count[i], i});
            }
        }

        sort(characters.rbegin(), characters.rend());

        for (auto a : characters)
        {
            result += string(a.first, a.second);
        }

        return result;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fifth try. Saw solution, priority queues 
    are perfect for this task. Accepted.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    string frequencySort(string s)
    {
        int count[256] = {0};
        priority_queue<pair<int, char>> characters;
        string result = "";

        for (char a : s)
        {
            count[a]++;
        }

        for (int i = 0; i < 256; i++)
        {
            if (count[i])
            {
                characters.push({count[i], i});
            }
        }

        while (!characters.empty())
        {
            result += string(characters.top().first, characters.top().second);
            characters.pop();
        }

        return result;
    }
};
