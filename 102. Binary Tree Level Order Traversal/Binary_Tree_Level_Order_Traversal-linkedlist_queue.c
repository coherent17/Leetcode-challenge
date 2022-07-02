#define QUEUE_EMPTY (Node *)0XFFFFFF

typedef struct Node{
    struct TreeNode *treeNode;
    struct Node *next;
    int level;
} Node;

typedef struct _Queue{
    Node *head;
    Node *tail;
} Queue;

void initQueue(Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

Node *createNode(struct TreeNode *treeNode, int level){
    Node *newnode = malloc(sizeof(Node));
    newnode->treeNode = treeNode;
    newnode->next = NULL;
    newnode->level = level;
    return newnode;
}

void enqueue(Queue *q, struct TreeNode *treeNode, int level){
    Node *newnode = createNode(treeNode, level);
    if(q->head == NULL){
        q->head = newnode;
        q->tail = newnode;
    }
    else{
        q->tail->next = newnode;
        q->tail = newnode;
    }
}

Node *dequeue(Queue *q){
    if(q->head == NULL) return QUEUE_EMPTY;
    Node *ret = q->head;
    Node *temp = q->head;
    q->head = q->head->next;
    if(q->head == NULL){
        q->tail = NULL;
    }
    return ret;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(!root){
        *returnSize = 0;
        return NULL;
    }
    int retIndex[800] = {0};
    int **ret = malloc(sizeof(int *) * 800);
    for(int i = 0; i < 800; i++){
        ret[i] = malloc(sizeof(int) * 129);
    }
    Queue q;
    initQueue(&q);
    int level = 0;
    ret[level][retIndex[level]] = root->val;
    retIndex[level]++;
    if(root->left) enqueue(&q, root->left, level+1);
    if(root->right) enqueue(&q, root->right, level+1);

    Node *temp;
    int MaxLevel = 0;
    while((temp = dequeue(&q)) != QUEUE_EMPTY){
        struct TreeNode *tempTNode = temp->treeNode;
        int val = tempTNode->val;
        int level = temp->level;
        ret[level][retIndex[temp->level]] = tempTNode->val;
        retIndex[level]++;
        MaxLevel = level;
        if(tempTNode->left) enqueue(&q, tempTNode->left, level+1);
        if(tempTNode->right) enqueue(&q, tempTNode->right, level+1);
        free(temp);
    }
    *returnColumnSizes = malloc(sizeof(int) * (MaxLevel + 1));
    for(int i = 0; i <= MaxLevel; i++){
        (*returnColumnSizes)[i] = retIndex[i];
    }
    *returnSize = MaxLevel + 1;
    return ret;
}