class Node
{
public:
    int data;
    Node *next;
};

/* given a reference (pointer-to-pointer) to the head of a list and
an int, push a new node on the front of the list
*/
void push(Node **head_ref, int new_data);

/* counts of nodes given a linked-list */
int getCount(Node *head);

/* counts the number of occurrences of a node (search_for) in a linked list (head)* */
int count(Node *head, int search_for);

/* delete all nodes */
void deleteList(Node **head_ref);

/* delete selected nodes based on the data/key/search_for */
void deleteSomeList(Node **head_ref, int key);

/* print a linked list */
void printList(Node *head);

// test
void wrapper_test_push();
void wrapper_test_count();
void wrapper_test_delete();