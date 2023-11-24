/**
 * @brief LinkedStack 链栈（栈顶在头）
 * @author slience
 * @date 2023/11/24 15:09
 **/
#include "iostream"
using namespace std;

typedef struct LinkedStack
{
    int data;
    LinkedStack* next;
} Stack;

/*
 * 初始化
 */
Stack* init(){
    auto* s = (Stack*)malloc(sizeof(Stack));
    s->next = nullptr;
    return s;
}

/**
 * 入栈
 * @param top 头节点
 * @param element 入栈元素
 * @return 入栈结果
 */
bool push(Stack* top, int element){
    auto* temp = (Stack*) malloc(sizeof(Stack));
    temp->data = element;
    temp->next = top->next;
    top->next = temp;
    return true;
}

/**
 * 出栈
 * @param top 头节点
 * @return 出栈元素
 */
int pop(Stack* top){
    if(top->next == nullptr){
        return -1;
    }
    Stack* temp = top->next;
    top->next = temp->next;
    return temp->data;
}

/**
 * 栈是否为空
 * @param top 头节点
 * @return 是否为空标记
 */
bool isEmpty(Stack *top){
    if(top->next == nullptr){
        return true;
    }
    return false;
}

/**
 * 打印栈
 * @param top 头节点
 */
void printStack(Stack *top){
    int index = 1;
    Stack* temp = top->next;
    while(temp != nullptr){
        printf("%d序号：%d\n", index, temp->data);
        index++;
        temp = temp->next;
    }

}

int main(){
    Stack* stack = init();
    cout<<"是否为空："<<isEmpty(stack)<<endl;
    for(int i = 10;i>0;i--){
        push(stack, i);
    }
    pop(stack);
    printStack(stack);
}


