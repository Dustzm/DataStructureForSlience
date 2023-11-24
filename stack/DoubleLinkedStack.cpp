/**
 * @brief DoubleLinkedStack 双向链栈（栈顶在尾）
 * @author slience
 * @date 2023/11/24 15:55
 **/
#include "iostream"
using namespace std;

typedef struct DoubleLinkedNode
{
    int data;
    DoubleLinkedNode* next;
    DoubleLinkedNode* prev;
} Node;

//双向链栈需要头指针与尾指针
typedef struct DoubleLinkedStack
{
    //头指针
    Node* header;
    //尾指针
    Node* rear;
} Stack;

/**
 * 初始化
 * @return 双向链栈
 */
Stack* init(){
    auto* s = (Stack*)malloc(sizeof(Stack));
    auto* node = (Node*)malloc(sizeof(Node));
    node->next = nullptr;
    node->prev = nullptr;
    node->data = -1;
    s->header = node;
    s->rear = node;
    return s;
}

/**
 * 入栈
 * @param s 栈
 * @param element 元素
 * @return 入栈结果
 */
bool push(Stack* s, int element){
    auto* temp = (Node*)malloc(sizeof(Node));
    temp->data = element;
    temp->next = nullptr;
    temp->prev = s->rear;
    s->rear->next = temp;
    s->rear = temp;
    return true;
}

/**
 * 出栈
 * @param s 栈
 * @return 出栈元素
 */
int pop(Stack* s){
    Node* temp = s->rear;
    s->rear = temp->prev;
    s->rear->next = nullptr;
    return temp->data;
}

/**
 * 是否为空
 * @param s 栈
 * @return 是否为空标记
 */
bool isEmpty(Stack* s){
    if(s->rear == s->header){
        return true;
    }
    return false;
}

/**
 * 打印栈
 * @param s 栈
 */
void printStack(Stack* s){
    int index = 1;
    Node* temp = s->rear;
    while(temp != nullptr){
        printf("%d序号：%d\n", index, temp->data);
        index++;
        temp = temp->prev;
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