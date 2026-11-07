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
class Solution {
public:
    // Custom comparator for the priority queue to act as a min-heap
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store the current pointers of k lists
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // Initialize the heap with the head of each non-empty list
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }

        // Dummy node to simplify the creation of the merged linked list
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            // Extract the smallest node
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            // Append it to the merged list
            tail->next = smallest;
            tail = tail->next;

            // If there is a next node in the same list, push it into the heap
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        return dummy.next;
    }
};