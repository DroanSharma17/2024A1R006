bool isValid(char* str) {
    int len = strlen(str);
    char stack[len];
    int top = -1;
    for (int i = 0; i < len; i++){
        char ch = str[i];
        if (ch=='('||ch=='{'||ch=='['){
            stack[++top]=ch; //push if opening bracket is encountered
        }
        else if ((top==-1)||(ch == ')'&& stack[top]!='(')||
                (ch == ']'&& stack[top]!='[')||
                (ch =='}' && stack[top]!= '{')){
                    return false;
                }
        else{
                top--;
        }
    }
    if (top==-1){
        return true;
    }else   return false;
}
