class Solution {
public:
    // Main function to merge k sorted linked lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Check if the input vector of linked lists is empty
        if (lists.empty()) {
            return nullptr;
        }
        // Call the helper function with the entire vector and indices of first and last linked lists
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
    
    // Helper function for recursive merge
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int startIndex, int endIndex) {
        // Base case: If there's only one linked list, return that list
        if (startIndex == endIndex) {
            return lists[startIndex];
        }
        // Base case: If there are two linked lists, merge them using mergeTwoLists function
        if (startIndex + 1 == endIndex) {
            return mergeTwoLists(lists[startIndex], lists[endIndex]);
        }
        // Calculate the middle index
        int midIndex = startIndex + (endIndex - startIndex) / 2;
        // Recursively call mergeKListsHelper on the left and right halves
        ListNode* leftMerged = mergeKListsHelper(lists, startIndex, midIndex);
        ListNode* rightMerged = mergeKListsHelper(lists, midIndex + 1, endIndex);
        // Merge the results obtained from left and right halves
        return mergeTwoLists(leftMerged, rightMerged);
    }
    
    // Function to merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify the code
        ListNode* dummy = new ListNode(0);
        // Pointer to the current node in the merged list
        ListNode* current = dummy;
        
        // Iterate while both lists are not empty
        while (list1 && list2) {
            // Compare values and link the smaller node to the merged list
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            // Move the current pointer to the last added node
            current = current->next;
        }
        
        // If one of the lists is not empty, link the remaining nodes
        current->next = list1 ? list1 : list2;
        
        // Return the merged list starting from the next of the dummy node
        return dummy->next;
    }
};
