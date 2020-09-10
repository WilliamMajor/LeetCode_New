// addTwoNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//Best solution here is to walk through the list and then recursively go back adding numbers as we go
class Solution
{
public:
    ListNode* returnValue = nullptr;
    ListNode* addTwoNumbers_Old(ListNode* l1, ListNode* l2)
    {
        AddNumbers(l1, l2);
        return returnValue;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* output = head;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int sum = (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0) + carry;
            output->next = new ListNode(sum % 10);
            output = output->next;
            carry = sum / 10;
            l1 = (l1 != NULL ? l1->next : NULL);
            l2 = (l2 != NULL ? l2->next : NULL);
        }
        if (carry == 1) {
            output->next = new ListNode(1);
        }
        return head->next;
    }

    void AddNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* uneven = new ListNode();
        int extra = 0;
        int valueToStore = 0;
        if (l1->next != nullptr || l2->next != nullptr)
        {
            if (l1->next == nullptr)
            {
                l1->next = uneven;
            }
            else if (l2->next == nullptr)
            {
                l2->next = uneven;
            }
            AddNumbers(l1->next, l2->next);
        }

        valueToStore = l1->val + l2->val + extra;
        if (valueToStore >= 10)
        {
            valueToStore = valueToStore % 10;
            insertValueFront(&returnValue, valueToStore);
            if (l1->next == nullptr || l2->next == nullptr)
            {
                append(&returnValue, 1);
            }
            else
            {
                increment(returnValue);
            }
        }
        else
        {
            insertValueFront(&returnValue, valueToStore);
        }

    }

    void increment(ListNode* input)
    {
        if (input->next == nullptr)
        {
            append(&input, 1);
            return;
        }
            
        if (input->next->val == 9)
        {
            input->next->val = 0;
            increment(input->next);
        }
        else
        {
            input->next->val++;
        }

    }

    void insertValueFront(ListNode** inputList, int newValueArg)
    {
        ListNode* newValue = new ListNode();

        newValue->val = newValueArg;
        newValue->next = (*inputList);
        (*inputList) = newValue;
    }
    void insertValue(ListNode* previousNode, int newData)
    {
        ListNode* newNode = new ListNode();
        newNode->val = newData;
        newNode->next = previousNode->next;
        previousNode->next = newNode;
    }
    void append(ListNode** inputList, int new_data)
    {

        ListNode* newNode = new ListNode();

        ListNode* last = *inputList;

        newNode->val = new_data;
        newNode->next = nullptr;
        if (*inputList == nullptr)
        {
            *inputList = newNode;
            return;
        }

        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = newNode;
        return;
    }
};


int main()
{
    Solution solution;
    ListNode test = ListNode(9, &ListNode(9, &ListNode(9)));
    ListNode test2 = ListNode(1);
    ListNode *test3 = solution.addTwoNumbers(&test, &test2);
}



