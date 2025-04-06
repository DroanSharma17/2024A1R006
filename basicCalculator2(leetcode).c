int precedence(char operator){
    return (operator == '+' || operator == '-') ? 1 : (operator == '*' || operator == '/') ? 2 : (operator == '^') ? 3 : 0;
}
void doProcess(int *operand, char *operator,int *top1,int *top2)
{
    if (*top1 < 1 || *top2 < 0)
        return;
    int x = operand[(*top1)--];
    int y = operand[(*top1)--];
    char oper = operator[(*top2)--];
    int z;
    switch (oper)
    {
    case '+':
        z = y + x;
        break;
    case '-':
        z = y - x;
        break;
    case '*':
        z = y * x;
        break;
    case '/':
        z = y / x;
        break;
    case '^':
        z = (int)pow(y, x);
        break;
    }
    operand[++(*top1)] = z;
}
int calculate(char* exp) {
    int top1 = -1, top2 = -1;
    int operand[100];
    char operator[100];
    int size = strlen(exp);
    for (int i = 0; i < size; i++){
        char ch = exp[i];
        if (isspace(ch))  continue;
         if (isdigit(ch))
        {
            int num = 0;
            while (isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - 48);
                i++;
            }
            i--;
            operand[++top1] = num; // Push the number onto the operand stack
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            if (top2 == -1)
                operator[++top2] = ch;
            else
            {
                while (top2 != -1 && precedence(ch) <= precedence(operator[top2]))
                {
                    doProcess(operand, operator, &top1, &top2);
                }
                operator[++top2] = ch;
            }
        }
        else if (ch == '(')
        {
            operator[++top2] = '(';
        }
        else if (ch == ')')
        {
            while (operator[top2] != '(')
            {
                doProcess(operand, operator, &top1, &top2);
            }
            top2--;
        }
    }
    while (top2 >= 0)
    { // Process remaining operators until stack becomes empty
       doProcess(operand, operator, &top1, &top2);
    }
    return operand[top1];
    return 0;
    }
