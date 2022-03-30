#include <stdlib.h>
#include <math.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }

    // loop to the end of the both lists
    // at end every node, add both numbers, and take note of any carryovers

    int carryover = 0;
    int sum = 0;
    int iteration = 0;
    struct ListNode *new_head = malloc(sizeof(struct ListNode));
    struct ListNode *temp = new_head;

    while (1) {
        // checks if this is
        if (iteration > 0) {
            // iterate to the next loop
            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }

            if ((l1 == NULL) && (l2 == NULL)) {
                // check for any remaining carryover
                if (carryover) {
                    // create a new node and point there
                    struct ListNode *new_node = malloc(sizeof(struct ListNode));
                    if (new_node != NULL) {
                        temp->next = new_node;
                        temp = temp->next;
                    }

                    // set value to carryover
                    temp->val = carryover;
                }

                // null terminate the new LL
                temp->next = NULL;

                break;
            }


            // create a new node and point there
            struct ListNode *new_node = malloc(sizeof(struct ListNode));
            if (new_node != NULL) {
                temp->next = new_node;
                temp = temp->next;
            }
        }

        // check if either l1 or l2 are finished and calculate sum accordingly
        if (l1 == NULL) {
            sum = l2->val + carryover;
        }
        else if (l2 == NULL) {
            sum = l1->val + carryover;
        }
        else {
            sum = l1->val + l2->val + carryover;
        }

        // check if the sum requires carryover
        if (sum >= 10) {
            carryover = 1;
            sum %= 10;
        }
        else {
            carryover = 0;
        }

        // add values to current node
        temp->val = sum;

        //printf("digit: %d\n", temp->val);

        iteration++;

        //printf("iteration: %d\n", iteration);

    }

    return new_head;
}