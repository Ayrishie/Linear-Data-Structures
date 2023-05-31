/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

typedef struct {
	int n;
	int nCount;
	sNode *pTop;
} stack;

stack* createStack(int n) {
    stack* s = (stack*)malloc(sizeof(stack));
    s->n = n;
    s->nCount = 0;
    s->pTop = NULL;
    return s;
}

int stackEmpty(stack* s) {
    return s->pTop == NULL;
}

int stackFull(stack* s) {
    return s->nCount == s->n;
}

void push(stack** s, char* data) {
    if (stackFull(*s)) {
        printf("Stack is full.\n");
        return;
    }
    sNode* pNew = (sNode*)malloc(sizeof(sNode));
    pNew->data = (char*)malloc(strlen(data) + 1);
    strcpy(pNew->data, data);
    pNew->pLink = (*s)->pTop;
    (*s)->pTop = pNew;
    (*s)->nCount++;
}

char* pop(stack** s) {
    if (stackEmpty(*s)) {
        printf("Stack is empty.\n");
        return NULL;
    }
    sNode* pTemp = (*s)->pTop;
    char* data = pTemp->data;
    (*s)->pTop = pTemp->pLink;
    (*s)->nCount--;
    free(pTemp);
    return data;
}

void displayStack(stack* s) {
    if (stackEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    sNode* pTemp = s->pTop;
    printf("Stack: ");
    while (pTemp != NULL) {
        printf("%s ", pTemp->data);
        pTemp = pTemp->pLink;
    }
    printf("\n");
}

char* top(stack* s) {
    if (stackEmpty(s)) {
        printf("Stack is empty.\n");
        return NULL;
    }
    return s->pTop->data;
}

