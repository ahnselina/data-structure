/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    cur := head
    var pre *ListNode
    var tmp *ListNode
    for cur != nil {
        tmp = cur.Next
        cur.Next = pre
        pre = cur
        cur = tmp
    }
    
    return pre
}