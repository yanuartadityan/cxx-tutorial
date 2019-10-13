#include <iostream>
#include "linked_list_1.h"

using namespace std;

/* print a linked list */
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void push(Node **head_ref, int new_data)
{
    // allocate a node
    Node *new_node = new Node();

    // put in the data
    new_node->data = new_data;

    // link the old list off the new node
    new_node->next = (*head_ref);

    // move the head to point to the new node
    (*head_ref) = new_node;
}

/* count nodes given a linked-list */
int getCount(Node *head)
{
    int count = 0;
    Node *current = head;
    while(current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

/* counts the number of occurrences of a node (search_for) in a linked list given
a node
*/
int count(Node *head, int search_for, int curr_freq)
{
    if (head == NULL)
        return curr_freq;

    if (head->data == search_for)
        curr_freq++;
    
    return count(head->next, search_for, curr_freq);
}

/* delete all nodes */
void deleteList(Node **head_ref)
{
    Node *current = *head_ref;
    Node *next;

    /* while the current node is valid */
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    // dereference head_ref to affect the real head
    *head_ref = NULL;
}

/* delete selected nodes based on the data/key/search_for */
void deleteSomeList(Node **head_ref, int key)
{
    Node *current = *head_ref;
    Node *next;  

    // check if head is gonna be deleted
    if (((*head_ref)->data == key) && ((*head_ref) != NULL))
    {
        // yes, then copy of the next node to the head
        *head_ref = current->next;
        free(current);
    }
    
    // currently current is the head node
    while (current->next != NULL)
    {
        // check if next node is gonna be deleted
        next = current->next;

        if (next->data == key)
        {
            current->next = next->next;
            free(next);
            current = current->next;
        }
    }
}

void wrapper_test_push()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node(); 
    third = new Node();

    // link
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    push(&head, 0);
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 5);

    // count starts from 0
    cout << "count of 1 is " << count(head, 1, 0) << endl;
}

void wrapper_test_count()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node(); 
    third = new Node();

    // link
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    push(&head, 0);
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 5);

    // count all nodes
    cout << "there is (are) " << getCount(head) << " nodes" << endl;
}

void wrapper_test_delete()
{
    Node *head = NULL;

    push(&head, 0);
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 5);

    cout << "before deleting..." << endl;
    printList(head);

    // delete selected nodes
    deleteSomeList(&head, 1);
    cout << "after deleting node-id = " << 1 << endl;
    printList(head);

    // delete the rest (all)
    deleteList(&head);
    cout << "after deleting the rest = " << endl;
    printList(head);
}