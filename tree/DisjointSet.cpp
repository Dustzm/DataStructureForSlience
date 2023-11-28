/**
 * @brief DisjointSet 并查集
 * @author slience
 * @date 2023/11/28 16:13
 **/
#include "iostream"
using namespace std;
const int SIZE = 10;
//并查集数组
int uSet[SIZE];
//并查集权值
int uRank[SIZE];

/**
 * 初始化并查集
 */
void makeSet(){
    for(int i=0;i<SIZE;i++){
        uSet[i] = i;
        uRank[i] = 0;
    }
}

/**
 * 查找根节点（压缩路径优化）
 * @param set 并查集
 * @param index 节点索引
 * @return 根节点索引
 */
int findIndex(int index){
    int root = index;
    //寻找根节点
    while(root != uSet[root]){
        root = uSet[root];
    }
    int temp = index;
    while(root != temp){
        //获取当前节点的父节点
        int next = uSet[index];
        //将root赋值给当前节点
        uSet[temp] = root;
        //前进至下个节点
        temp = next;
    }
    return root;
}

/**
 * 合并节点（小树合并优化）
 * @param set 并查集
 * @param index1 节点1
 * @param index2 节点2
 */
void unionIndex(int index1, int index2){
    int root1 = findIndex(index1);
    int root2 = findIndex(index2);
    if(root1 == root2){
        return;
    }
    if(uRank[root1] == uRank[root2]){
        uSet[root1] = root2;
        //高度增加
        uRank[root2]++;
    }
    if(uRank[root1] > uRank[root2]){
        uSet[root2] = root1;
    } else {
        uSet[root1] = root2;
    }
}

/**
 * 打印并查集
 * @param set 并查集
 */
void printSet(int set[]){
    for(int i=0;i<SIZE;i++){
        cout<<i<<"根节点:"<<findIndex(set[i])<<endl;
    }
}

int main(){
    makeSet();
    unionIndex(0,1);
    unionIndex(3,4);
    unionIndex(1,4);
//    cout<<findIndex(0);
    printSet(uSet);
}