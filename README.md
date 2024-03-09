# algorithm_everyday

## 算法思路_记录

### 线性表

#### 顺序表
- todo

#### 单链表

##### 需注意
- 删除节点时，记得使用 `free(node)` 释放节点空间
- 公共元素与公共节点不是同一概念，公共元素是指节点元素值相等，公共节点是指节点指针指向同一节点（即节点指针值相等）
- 对于有关2个元素值有序的线性表的问题，可以使用**归并**的思想

##### 查找2个单链表的公共节点
- 由于是单链表，所以每个node只有1个next指针，从第一个公共节点开始的所有节点都是公共节点
- 若只需判断是否有公共节点，只需分别遍历到2个单链表的最后一个节点并判断是否相同
- 若需求第一个公共节点，可以先分别求两个单链表的长度并求差值，对较长的单链表先遍历这个差值，再同步遍历同时判断next指针是否相等

##### 2个单链表元素值的匹配
- 不需要使用2个循环，只需记录两个链表的开始节点，每次匹配失败，通过开始节点恢复