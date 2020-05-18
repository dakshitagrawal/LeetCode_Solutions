
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/* 
    ---------------------------------------------------------------------------------------------------

    First try. Solve it in one pass of the linked list,
    concatenating at every two new nodes, i.e., the list
    should be connected after each iteration. 

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {

        if (!head || !head->next)
        {
            return head;
        }

        ListNode *lastOdd = head;
        ListNode *firstEven = head->next;

        ListNode *nextOdd;
        ListNode *nextEven;

        ListNode *pointer = firstEven;

        while (pointer && pointer->next)
        {
            nextOdd = pointer->next;
            nextEven = pointer->next->next;

            lastOdd->next = nextOdd;
            nextOdd->next = firstEven;
            pointer->next = nextEven;

            pointer = nextEven;
            lastOdd = nextOdd;
        }

        return head;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Second try. Solve it in one pass of the linked list,
    but have separate lists of odd and even numbered nodes, 
    going from one even node to another even node.
    Concatenate the two lists in the end. 

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {

        if (!head || !head->next)
        {
            return head;
        }

        ListNode *evenHead = head->next;
        ListNode *oddTail = head;

        ListNode *pointer = evenHead;

        while (pointer && pointer->next)
        {
            oddTail->next = pointer->next;
            oddTail = oddTail->next;
            pointer->next = oddTail->next;
            pointer = pointer->next;
        }

        oddTail->next = evenHead;

        return head;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Third try. Similar to the second try, but go 
    through each node one by one. Concatenate the 
    two lists in the end. 

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {

        if (!head || !head->next)
        {
            return head;
        }

        ListNode *evenHead = head->next;
        ListNode *current = head;

        ListNode *pointer = evenHead;

        while (pointer)
        {
            current->next = pointer->next;
            current = pointer;
            pointer = pointer->next;
        }

        current = head;

        while (current->next)
        {
            current = current->next;
        }

        current->next = evenHead;

        return head;
    }
};

/* 
    ---------------------------------------------------------------------------------------------------

    Fourth try. Similar to the second try, but remove
    the unnecessary initial condition. Reduces the 
    execution time by almost half.

    ---------------------------------------------------------------------------------------------------
*/

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {

        if (!head)
        {
            return head;
        }

        ListNode *evenHead = head->next;
        ListNode *oddTail = head;

        ListNode *pointer = evenHead;

        while (pointer && pointer->next)
        {
            oddTail->next = pointer->next;
            oddTail = oddTail->next;
            pointer->next = oddTail->next;
            pointer = pointer->next;
        }

        oddTail->next = evenHead;

        return head;
    }
};
