/**
 * @brief SequentialArrayTree 一维数组实现顺序树
 * @author slience
 * @date 2023/11/25 12:16
 **/
 #include "iostream"
 using namespace std;
 
 typedef struct SequentialArrayTree
 {
     int data;
     bool empty;
 } TreeNode;

 /**
  * 初始化
  * @param t 树数组
  * @param length 数组长度
  */
 void init(TreeNode t[], int length){
     for(int i = 0;i < length;i++){
         t[i].data = -1;
         t[i].empty = true;
     }
 }

/**
 * 节点是否为空
 * @param t 树
 * @param length 数组长度
 * @param index 下标
 * @return 是否为空
 */
 bool isEmpty(TreeNode t[], int length, int index){
    if(index < 0 || index >= length){
        return true;
    }
    return t[index].empty;
 }

 /**
  * 获取父节点下标
  * @param t 树
  * @param length 长度
  * @param index 下标
  * @return 父节点下标
  */
 int getFatherIndex(TreeNode t[], int length, int index){
     if(index == 0){
         return -1;
     }
     int father = index/2;
     if(isEmpty(t, length, father)){
         return -1;
     }
     return father;
 }

 /**
  * 获取左孩子下标
  * @param t 树
  * @param length 长度
  * @param index 下标
  * @return 左孩子下标
  */
 int getLeftChild(TreeNode t[], int length, int index){
     int leftChild = 2 * index + 1;
     if(isEmpty(t, length, leftChild)){
         return -1;
     }
     return leftChild;
 }

 /**
  * 获取右孩子下标
  * @param t 树
  * @param length 长度
  * @param index 下标
  * @return 右孩子下标
  */
 int getRightChild(TreeNode t[], int length, int index){
     int rightChild = 2 * index + 2;
     if(isEmpty(t, length, rightChild)){
         return -1;
     }
     return rightChild;
 }

 /**
  * 访问当前节点
  * @param t 树节点
  */
void visit(TreeNode t){
    cout<<t.data<<",";
}

/**
 * 先序遍历（根左右）
 * @param t 树
 * @param length 数组长度
 * @param index 开始下标
 */
 void preOrder(TreeNode t[], int length, int index){
    if(isEmpty(t, length, index)){
//        cout<<"node is empty,end";
        return;
    }
    visit(t[index]);
     preOrder(t, length, getLeftChild(t, length, index));
     preOrder(t, length, getRightChild(t, length, index));
}

/**
 * 中序遍历（左根右）
 * @param t 树
 * @param length 数组长度
 * @param index 开始下标
 */
void inOrder(TreeNode t[], int length, int index){
    if(isEmpty(t, length, index)){
//        cout<<"node is empty,end";
        return;
    }
    inOrder(t, length, getLeftChild(t, length, index));
    visit(t[index]);
    inOrder(t, length, getRightChild(t, length, index));
}

/**
 * 后序遍历（左右根）
 * @param t 树
 * @param length 数组长度
 * @param index 开始下标
 */
void postOrder(TreeNode t[], int length, int index){
    if(isEmpty(t, length, index)){
//        cout<<"node is empty,end";
        return;
    }
    postOrder(t, length, getLeftChild(t, length, index));
    postOrder(t, length, getRightChild(t, length, index));
    visit(t[index]);
}

/**
 * 生成测试树
 * @param t 树
 * @param length 数组长度
 */
void generateTestTree(TreeNode t[], int length){
    for(int i = 0;i < length;i++){
        t[i].data = i + 1;
        t[i].empty = false;
    }
}
 
 int main(){
     TreeNode t[10];
     generateTestTree(t, 10);
     preOrder(t, 10, 0);
     cout<<endl;
     inOrder(t, 10, 0);
     cout<<endl;
     postOrder(t, 10, 0);
 }
