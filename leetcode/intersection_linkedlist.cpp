// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        size_t lenA = 0, lenB = 0;
        ListNode *nodeA = headA, nodeB = headB;

        while(nodeA != NULL) {
        	++lenA;
        	nodeA = nodeA.next;
        } 

        nodeB = headB;
        while(nodeB != NULL) {
        	++lenB;
        	nodeB = nodeB.next
        }

        size_t intersectionLen = 0;
        if(lenA > lenB) {
        	nodeA = headA; //longer
        	nodeB = headB; //shorter
        	intersectionLen = lenA - lenB;
        } else {
        	nodeA = headB;
        	nodeB = headA;
        	intersectionLen = lenB - lenA;
        }

        while(nodeA != NULL && nodeB != NULL) {
        	if(nodeA == nodeB) {
        		break;
        	}

    		if(intersectionLen == 0) {
    			nodeB = nodeB.next;
    		} else {	
    			--intersectionLen;
    		}
    		nodeA = nodeA.next;
    	}

    	return nodeA;
    }
};