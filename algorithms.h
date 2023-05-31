/*****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
*****************************************************/

int precedence(char c) {
	if (c == '|')
        return 1;
    if (c == '&') 
        return 2;
    if (c == '>' || c == '<' || c == '=')
        return 3;
    if (c == '+' || c == '-')
        return 4;
    if (c == '*' || c == '/')
        return 5;
    if (c == '!')
        return 6;
    return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    int i = 0;
	int j = 0;
	int top = 0;
    char stack[256], c;
    
    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if (c == ' ') {
            continue; // ignore spaces
        }

        if (c == '(') {
            stack[++top] = c;
        }
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
                postfix[j++] = ' '; // add space after each operator
            }
            if (top >= 0 && stack[top] == '(') {
                top--;
            }
        }
        else if (isdigit(c)) {
            postfix[j++] = c;
            while (isdigit(infix[i+1])) {
                postfix[j++] = infix[++i];
            }
            postfix[j++] = ' '; // add space after each operand
        }
        else {
            while (top >= 0 && precedence(stack[top]) > precedence(c)) {
                postfix[j++] = stack[top--];
                postfix[j++] = ' '; // add space after each operator
            }
            if(infix[i+1] == '=' && (precedence(c) == 3 || precedence(c) == 6) && c != '='){
				stack[++top] = infix[i+1];
            	stack[++top] = c;
            	++i;
            }
            else{
            	stack[++top] = c;
            }
        }
    }
    while (top > 0){

        postfix[j++] = stack[top--];
        if(stack[top] == postfix[j-1]){
        	postfix[j++] = stack[top--];
        }else if(stack[top] == '=' && (postfix[j-1] == '<' || postfix[j-1] == '>' || postfix[j-1] == '!')){
        	postfix[j++] = stack[top--];
		}
		else{
			postfix[j++] = ' '; // add space after each operator
		}
        
    }
    postfix[j] = '\0';
    j = 0;
}


int evaluatePostfix(char *postfix) {
    int i, j, top = -1;
    int stack[256];
	int val1 = 0;
	int val2 = 0;
	int result = 0;
	int num = 0;

	for(i = 0; i<256; i++)
	{
		stack[i] = 0;
	}

    for (i = 0; postfix[i] != '\0'; i++) 
	{
        char c = postfix[i];
        if (isdigit(c)) 
		{
            num = 0;
            while (isdigit(c)) 
			{
                num = (num * 10) + (c - '0');
                c = postfix[++i];
            }
            stack[++top] = num;
        }
    
        else if(c != ' ') {
            val2 = stack[top--];
            val1 = stack[top--];
            switch(c) {
                case '+':
                    result = val1 + val2;
                    break;
                case '-':
                    result = val1 - val2;
                    break;
                case '*':
                    result = val1 * val2;
                    break;
                case '/':
                    if (val2 == 0) {
                    	printf("Division by zero error!\n");
                    	return '0';
                    }
                    	result = val1 / val2;
						 
                    break;
                case '^':
                    result = 1;
                    for (j = 0; j < val2; j++) {
                        result *= val1;
                    }
                    break;
                case '>':
                    if(postfix[i+1] == '='){
                    	++i;
                    	if(val1 >= val2)
                		{
                			result = 1;
						}
						else
						{
							result = 0;
						}
					}
					else{
						if(val1 > val2)
	                	{
	                		result = 1;
						}
						else
						{
							result = 0;
						}
					}
                    break;
                case '<':
                    if(postfix[i+1] == '='){
                    	++i;
                    	if(val1 <= val2)
                		{
                			result = 1;
						}
						else
						{
							result = 0;
						}
					}
					else{
						if(val1 < val2)
	                	{
	                		result = 1;
						}
						else
						{
							result = 0;
						}
					}
                    break;
                case '=':
                    if(postfix[i+1] == '='){
                    	++i;
	                    if(val1 == val2)
	                	{
	                		result = 1;
						}
						else
						{
							result = 0;
						}
					}
					else{
						if(val1 == val2)
	                	{
	                		result = 1;
						}
						else
						{
							result = 0;
						}
					}
                    break;
                case '!':
                	if(postfix[i+1] == '='){
                		++i;
                		if(val1 != val2){
                			result = 1;
						}
						else
							result = 0;
					}
					else
                    	result = !val2;
                    break;
                case '&':
                	++i;
                    if(val1 == 1 && val2 == 1)
                    {
                    	result = 1;
					}
					else
					{
						result = 0;
					}
                    break;
                case '|':
                	++i;
                    if(val1 == 1 || val2 == 1)
                    {
                    	val1 = 1;
                    	val2 = 1;
                    	result = 1;
					}
					else
					{
						val1 = 0;
						val2 = 0;
						result = 0;
					}
                    break;
            }
           
            stack[++top] = result;
        }
    }

    return stack[top];
}
