/*****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "node.h"
#include "algorithms.h"
#include "queue.h"
#include "stack.h"
#include <stddef.h>


int main() {
	
	char infix[256];
    char postfix[256];
    
    int i;

    while (1) {
        fgets(infix, 256, stdin);
        infix[strlen(infix) - 1] = '\0'; // remove trailing newline

        if (strcmp(infix, "QUIT") == 0) {
            break;
        }

        infixToPostfix(infix, postfix);
        printf("%s\n", postfix);
        if(evaluatePostfix(postfix) != '0')
        {
        	printf("%d\n", evaluatePostfix(postfix));
        	printf("\n");
		}
        memset(infix,0,strlen(infix));
        memset(postfix,0,strlen(postfix));
    }
	return 0;
}

