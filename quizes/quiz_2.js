function ListNode(val) {
  this.val = val
  this.next = null
}

/**
 * Question 1
 * Given head, the head of a linked list, determines if the linked list has a cycle in it.
 * There is a cycle in a linked list if there is some node in the list that can be reached again
 * by continuously following the next pointer.
 * Internally, pos is used to denote the index of the node that tail's next pointer is connected to.
 * Note that pos is not passed as a parameter.
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 * */
function hasCycle(head) {
  let slow = head
  let fast = head

  while (fast && fast.next) {
    slow = slow.next // Moves one step at a time
    fast = fast.next.next // Moves two steps at a time

    if (slow === fast) {
      return true
    }
  }
  return false
}

/**
 * Question 2
 * Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously
 * following the next pointer. Internally, pos is used to denote the index of the node that tail's
 * next pointer is connected to (0-indexed). It is -1 if there is no cycle.
 * Note that pos is not passed as a parameter.
 **/
function detectCycle(head) {
  if (!head || !head.next) {
    return null
  }

  let slow = head,
    fast = head

  while (fast && fast.next) {
    slow = slow.next
    fast = fast.next.next

    if (slow === fast) {
      slow = head // Move slow to head and keep fast at the meeting point

      while (slow !== fast) {
        // Move slow and fast at the same speed until they meet
        // This is the start of the cycle
        slow = slow.next
        fast = fast.next
      }
      return slow
    }
  }
}

/**
 * Question 3
 * Write a function that takes a linked list and returns the reversed list.
 *
 */
function reverseList(head) {
  let prev = null
  let current = head

  while (current) {
    let temp = current.next // Store the next node
    current.next = prev // Reverse the link

    prev = current // Move prev and current one step forward
    current = temp // Move current one step forward
  }

  return prev
}
