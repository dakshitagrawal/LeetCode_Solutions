
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/* 
    ---------------------------------------------------------------------------------------------------

    First try. Brute force. Initially TLE, later
    magically accepted. Took a long execution time 
    though.

    ---------------------------------------------------------------------------------------------------
*/

class StockSpanner
{
public:
    vector<int> quotes;

    StockSpanner()
    {
    }

    int next(int price)
    {
        quotes.push_back(price);
        int span = 0;

        for (int i = quotes.size() - 1; i > -1; i--)
        {

            if (quotes[i] <= price)
            {
                span++;
            }
            else
            {
                return span;
            }
        }

        return span;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try. Store the element if it is larger than
    the last element in vector. Again TLE, but magically 
    accepted later. Took half the time of first try.

    ---------------------------------------------------------------------------------------------------
*/

class StockSpanner
{
public:
    vector<int> maximums;
    vector<int> positions;
    int count;

    StockSpanner()
    {
        count = 0;
    }

    int next(int price)
    {
        count++;

        if (maximums.empty())
        {
            maximums.push_back(price);
            positions.push_back(count);
        }

        if (price < maximums.back())
        {
            maximums.push_back(price);
            positions.push_back(count);
        }

        if (maximums.back() < price && !maximums.empty())
        {

            maximums.pop_back();
            positions.pop_back();
            maximums.push_back(price);
            positions.push_back(count);
        }

        if (maximums.back() == price)
        {
            positions.pop_back();
            positions.push_back(count);
        }

        for (int i = maximums.size() - 1; i > -1; i--)
        {

            if (maximums[i] > price)
            {
                return count - positions[i];
            }
        }

        return count;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third try. Bug in previous code, incoming element may
    be greater than the second last element in vector and 
    so on. Again TLE, but then magically accepted. Took half
    the execution time of second try.

    ---------------------------------------------------------------------------------------------------
*/

class StockSpanner
{
public:
    vector<int> maximums;
    vector<int> positions;
    int count;

    StockSpanner()
    {
        maximums.push_back(1000000);
        positions.push_back(0);
        count = 0;
    }

    int next(int price)
    {
        count++;
        if (maximums.empty())
        {
            maximums.push_back(price);
            positions.push_back(count);
        }

        while (maximums.back() < price)
        {
            maximums.pop_back();
            positions.pop_back();
        }

        if (price < maximums.back())
        {
            maximums.push_back(price);
            positions.push_back(count);
        }

        if (maximums.back() == price)
        {
            positions.pop_back();
            positions.push_back(count);
        }

        return count - positions[positions.size() - 2];
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fourth try. Removed redundant code.

    ---------------------------------------------------------------------------------------------------
*/

class StockSpanner
{
public:
    vector<int> maximums;
    vector<int> positions;
    int count;

    StockSpanner()
    {
        maximums.push_back(1000000);
        positions.push_back(0);
        count = 0;
    }

    int next(int price)
    {
        count++;

        while (maximums.back() <= price)
        {
            maximums.pop_back();
            positions.pop_back();
        }

        maximums.push_back(price);
        positions.push_back(count);

        return count - positions[positions.size() - 2];
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fifth try. Saw solution, got to know the above was 
    basically a stack implemented using vectors. Implemented
    stacks with weights as the number of elements after the 
    last largest element.

    ---------------------------------------------------------------------------------------------------
*/

class StockSpanner
{
public:
    stack<pair<int, int>> maximums;

    StockSpanner()
    {
    }

    int next(int price)
    {
        pair<int, int> item = {price, 1};

        while (!maximums.empty() && maximums.top().first <= item.first)
        {
            item.second += maximums.top().second;
            maximums.pop();
        }

        maximums.push(item);

        return item.second;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Sixth try. Changed stacks to vectors with tuples. 
    Also untied and unsynced the iostream. Much faster
    execution time. 

    ---------------------------------------------------------------------------------------------------
*/

class StockSpanner
{
public:
    vector<tuple<int, int>> maximums;

    StockSpanner()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    int next(int price)
    {

        int span = 1;

        while (!maximums.empty() && get<0>(maximums.back()) <= price)
        {
            span += get<1>(maximums.back());
            maximums.pop_back();
        }

        maximums.emplace_back(price, span);

        return span;
    }
};
