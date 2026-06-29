class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k ==1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;
        
        while (true) {
            // Step 1: Check if there are k nodes ahead
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break;  // Less than k nodes remain

            // Step 2: Reverse k nodes
            ListNode* groupNext = kth->next;
            ListNode* prev = groupNext;
            ListNode* curr = prevGroupEnd->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Step 3: Reconnect
            ListNode* temp = prevGroupEnd->next;
            prevGroupEnd->next = kth;
            prevGroupEnd = temp;
        }

        return dummy.next;
    }
};