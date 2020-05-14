
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/* 
    ---------------------------------------------------------------------------------------------------

    First try. Used up lots of memory since the solution 
    is for a general trie with any input. 

    ---------------------------------------------------------------------------------------------------
*/

class Trie
{
public:
    /** Initialize your data structure here. */
    char data;
    vector<Trie *> children;

    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        if (word.length() == 0)
        {
            Trie *new_child = new Trie();
            new_child->data = '.';
            children.push_back(new_child);
            return;
        }

        for (auto child : children)
        {
            if (word[0] == child->data)
            {
                child->insert(word.substr(1));
                return;
            }
        }

        Trie *new_child = new Trie();
        new_child->data = word[0];
        children.push_back(new_child);
        new_child->insert(word.substr(1));

        return;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        if (word.length() == 0)
        {
            for (auto child : children)
            {
                if (child->data == '.')
                {
                    return true;
                }
            }

            return false;
        }

        bool found = false;

        for (auto child : children)
        {
            if (word[0] == child->data)
            {
                found = child->search(word.substr(1));
            }
        }

        return found;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        if (prefix.length() == 0)
        {
            return true;
        }

        bool found = false;

        for (auto child : children)
        {
            if (prefix[0] == child->data)
            {
                found = child->startsWith(prefix.substr(1));
            }
        }

        return found;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try. Replaced the addition of the character '.' 
    to denote end of word with a boolean variable.

    ---------------------------------------------------------------------------------------------------
*/

class Trie
{
public:
    /** Initialize your data structure here. */
    char data;
    vector<Trie *> children;
    bool isWord = false;

    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        if (word.length() == 0)
        {
            isWord = true;
            return;
        }

        for (auto child : children)
        {
            if (word[0] == child->data)
            {
                child->insert(word.substr(1));
                return;
            }
        }

        Trie *new_child = new Trie();
        new_child->data = word[0];
        children.push_back(new_child);
        new_child->insert(word.substr(1));

        return;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        if (word.length() == 0)
        {
            return isWord;
        }

        for (auto child : children)
        {
            if (word[0] == child->data)
            {
                return child->search(word.substr(1));
            }
        }

        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        if (prefix.length() == 0)
        {
            return true;
        }

        for (auto child : children)
        {
            if (prefix[0] == child->data)
            {
                return child->startsWith(prefix.substr(1));
            }
        }

        return false;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third try. Made it specific for this problem.

    ---------------------------------------------------------------------------------------------------
*/

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie *children[26] = {0};
    bool isWord = false;

    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        if (word.length() == 0)
        {
            isWord = true;
            return;
        }

        int pos = word[0] - 'a';

        if (children[pos] == 0)
        {
            Trie *new_child = new Trie();
            children[pos] = new_child;
        }

        children[pos]->insert(word.substr(1));

        return;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        if (word.length() == 0)
        {
            return isWord;
        }

        int pos = word[0] - 'a';

        if (children[pos] != 0)
        {
            return children[pos]->search(word.substr(1));
        }

        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        if (prefix.length() == 0)
        {
            return true;
        }

        int pos = prefix[0] - 'a';

        if (children[pos] != 0)
        {
            return children[pos]->startsWith(prefix.substr(1));
        }

        return false;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fourth try. Replaced the recursive calls with for loops
    after looking at the solution. Used up much fewer memory.

    Note: foreach stores a copy of the variable. Had problems
    assigning NULL to each pointer while initializing a Trie.

    ---------------------------------------------------------------------------------------------------
*/

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie *children[26];
    bool isWord;

    Trie()
    {
        isWord = false;
        for (auto &child : children)
        {
            child = NULL;
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {

        Trie *temp = this;

        for (char letter : word)
        {
            int pos = letter - 'a';

            if (!temp->children[pos])
            {
                Trie *new_child = new Trie();
                temp->children[pos] = new_child;
            }

            temp = temp->children[pos];
        }

        temp->isWord = true;
        return;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *temp = this;

        for (char letter : word)
        {
            if (temp->children[letter - 'a'])
            {
                temp = temp->children[letter - 'a'];
            }
            else
            {
                return false;
            }
        }

        return temp->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {

        Trie *temp = this;

        for (char letter : prefix)
        {
            if (temp->children[letter - 'a'])
            {
                temp = temp->children[letter - 'a'];
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
