typedef struct ListNode node;
extern int QUEUE_EMPTY;
typedef struct queue queue;
void init_queue(queue *);
void enqueue(queue *, int);
int dequeue(queue *);
void printQueue(queue *);