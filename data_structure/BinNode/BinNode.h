#define BinNodePosi(T) BinNode<T>*  // 节点位置
#define stature(p) ((p) ? (p)->height : -1) // 节点高度（与”空树高度为-1“的约定相统一）
typedef enum { RB_RED, RED_BLACK } RBColor; // 节点颜色

// 二叉树节点模板类
template<typename T> struct BinNode {
// 成员，为简化描述统一开放（public）
T data;
BinNodePosi(T)  parent; // 父节点
BinNodePosi(T)  lChild; // 左孩子
BinNodePosi(T)  rChild; // 右孩子
int height;
int npl;    // Null Path Length（左式堆，也可以直接用height代替）
RBColor color;  // 颜色（红黑树）

// 构造函数
BinNode(): parent(nullptr), lChild(nullptr), rChild(nullptr), height(0), npl(1), color(RB_RED) {}
BinNode(T e, BinNodePosi(T) p = nullptr, BinNodePosi(T) lc = nullptr, BinNodePosi(T) rc = nullptr, 
                int h = 0, int l = 1, RBColor c = RB_RED)
                : data(e), parent(p), lChild(lc), rChild(rc), height(h), npl(l), color(c) {}

// 操作接口
int size(); // 当前节点后代节点的总数
BinNodePosi(T)  insertAsLC(T const&);   // 作为当前节点的左孩子插入新节点
BinNodePosi(T)  insertAsRC(T const&);   // 作为当前节点的右孩子插入新节点
BinNodePosi(T)  succ(); // 取当前节点的直接后继
template<typename VST> void travLevel(VST&);    // 子树层次遍历
template<typename VST> void travPre(VST&);    // 子树先序遍历
template<typename VST> void travIn(VST&);    // 子树中序遍历
template<typename VST> void travPost(VST&);    // 子树后序遍历

// 比较器、判等器
bool operator<(BinNode const& bn) { return data < bn.data; }
bool operator==(BinNode const& bn) { return data == bn.data; }
};