/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public void reverseLL(ListNode head)
    {
        if(head==null || head.next==null){
            return;
        } 
        reverseLL(head.next);
        ListNode temp= head.next;
        temp.next=head;
        head.next=null;
    }
    public ListNode reverseList(ListNode head) {
        ListNode temp=head;
        while(temp!=null && temp.next!=null)
        {
            temp=temp.next;
        }
        reverseLL(head);
        return temp;
    }
}