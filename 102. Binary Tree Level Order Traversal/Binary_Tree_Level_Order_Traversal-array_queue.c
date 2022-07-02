#define QUEUE_SIZE 2000
#define QUEUE_EMPTY (struct TreeNode *)0XFFFFFF

typedef struct _Queue{
	struct TreeNode *NodeAddress[QUEUE_SIZE];
	int levelArray[QUEUE_SIZE];
	int head;
	int tail;
} Queue;

void initQueue(Queue *q){
	q->head = -1;
	q->tail = -1;
}

void enqueue(Queue *q, struct TreeNode *element, int level){
	q->tail++;
	q->NodeAddress[q->tail] = element;
	q->levelArray[q->tail] = level;
	if(q->head == -1) q->head = 0;
}

struct TreeNode *dequeue(Queue *q, int *level){
	if(q->head == -1) return QUEUE_EMPTY;
	struct TreeNode *ret = q->NodeAddress[q->head];
	*level = q->levelArray[q->head];
	if(q->head == q->tail){
		q->head = -1;
		q->tail = -1;
	}
	else{
		q->head++;
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

    struct TreeNode *temp;
    int MaxLevel = 0;
    while((temp = dequeue(&q, &level)) != QUEUE_EMPTY){
    	ret[level][retIndex[level]] = temp->val;
    	retIndex[level]++;
    	MaxLevel = level;
    	if(temp->left){
            enqueue(&q, temp->left, level+1);
        }
    	if(temp->right){
            enqueue(&q, temp->right, level+1);
        }
    }
    *returnColumnSizes = malloc(sizeof(int) * (MaxLevel + 1));
    for(int i = 0; i <= MaxLevel; i++){
        (*returnColumnSizes)[i] = retIndex[i];
    }
    *returnSize = MaxLevel + 1;
    return ret;    
}