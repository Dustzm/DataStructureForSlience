/**
 * @brief SequentialStack 顺序栈
 * @author slience
 * @date 2023/11/24 10:40
 **/
#include "iostream"
using namespace std;

const int MAX = 10;

typedef struct SequentialStack{
    int data[MAX];
    int top;
} Stack;

/**
 * 初始化
 * @return 初始栈
 */
Stack* init(){
    auto* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

/**
 * 入栈
 * @param stack 栈
 * @param element 元素
 * @return 成功标记
 */
bool push(Stack* stack, int element){
    if(stack->top == MAX){
        return false;
    }
    stack->top++;
    stack->data[stack->top] = element;
    return true;
}
/**
 * 出栈
 * @param stack 栈
 * @return 出栈元素
 */
int pop(Stack* stack){
    if(stack->top == -1){
        return -1;
    }
    return stack->data[stack->top--];
}
/**
 * 是否为空
 * @param stack 栈
 * @return 是否为空标记
 */
bool isEmpty(Stack* stack){
    if(stack->top == -1){
        return true;
    }
    return false;
}
/**
 * 是否已满
 * @param stack 栈
 * @return 是否已满标记
 */
bool isFull(Stack* stack){
    if(stack->top == MAX-1){
        return true;
    }
    return false;
}

/**
 * 打印栈元素
 * @param stack 栈
 */
void printStack(Stack* stack){
    for(int i=0;i<=stack->top;i++){
        printf("%d:%d\n", i+1, stack->data[i]);
    }
}


int main(){
    Stack* stack = init();
    cout<<"是否为空："<<isEmpty(stack)<<endl;
    for(int i = 10;i>0;i--){
        push(stack, i);
    }
    printStack(stack);
    cout<<isFull(stack)<<endl;
    cout<<pop(stack)<<endl;
    cout<<isFull(stack)<<endl;
}

