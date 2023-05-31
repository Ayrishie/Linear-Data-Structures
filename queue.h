/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

typedef struct {
	int n;
	int nCount;
	sNode *pHead;
	sNode *pTail;
} queue;

queue* createQueue(int n) {
 	queue* q = (queue*)malloc(sizeof(queue));
    q->n = n;
    q->nCount = 0;
    q->pHead = NULL;
    q->pTail = NULL;
    return q;
}

// Function to check if the queue is empty
int queueEmpty(queue* q) {
    return q->nCount == 0;
}

// Function to check if the queue is full
int queueFull(queue* q) {
    return q->nCount == q->n;
}

// Function to add an element to the tail of the queue
void enqueue(queue* q, char* data) {
    if (queueFull(q)) {
        printf("Error: Queue is full!\n");
        return;
    }
    sNode* newNode = (sNode*)malloc(sizeof(sNode));
    newNode->data = (char*)malloc(strlen(data) + 1);
    strcpy(newNode->data, data);
    newNode->pLink = NULL;
    if (queueEmpty(q)) {
        q->pHead = newNode;
        q->pTail = newNode;
    }
    else {
        q->pTail->pLink = newNode;
        q->pTail = newNode;
    }
    q->nCount++;
}

// Function to remove and return the element at the head of the queue
char* dequeue(queue* q) {
    if (queueEmpty(q)) {
        printf("Error: Queue is empty!\n");
        return NULL;
    }
    sNode* headNode = q->pHead;
    char* data = headNode->data;
    if (q->nCount == 1) {
        q->pHead = NULL;
        q->pTail = NULL;
    }
    else {
        q->pHead = headNode->pLink;
    }
    free(headNode);
    q->nCount--;
    return data;
}

// Function to display the contents of the queue
void displayQueue(queue* q) {
    if (queueEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    sNode* pNode = q->pHead;
    printf("Queue: ");
    while (pNode != NULL) {
        printf("%s ", pNode->data);
        pNode = pNode->pLink;
    }
    printf("\n");
}

char* head(queue *q) {
    if (q->pHead == NULL) {
        // Queue is empty
        return NULL;
    }
    return q->pHead->data;
}

char* tail(queue *q) {
    if (q->pTail == NULL) {
        // Queue is empty
        return NULL;
    }
    return q->pTail->data;
}



