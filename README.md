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


### 栈与队列
#### 用栈实现队列
- 队列是先进先出，栈是先进后出，可以通过2个栈1个负责进1个负责出来实现
- 进的时候就直接进，出的时候一开始将进的栈的元素全都push到另一个栈中，从而实现元素顺序反向，之后出的时候，若出的栈有元素，则直接出，否则将进的栈的元素全都push到出的栈之后再出元素
#### 用队列实现栈
- 初步想法：使用2个队列，1个负责进栈和出栈，另一个辅助，关键在于维护进栈和出栈的队列中只有队尾的1个元素，其他元素按队列顺序保存在辅助队列中，当pop一个元素后，需将辅助队列的元素全部重新pop到主队列中，同时维护只有一个元素
- 优化：只使用1个队列，出栈时将出末尾元素都pop并重新push进入队列，值得注意的是top()只需返回队尾的元素back()，不应该使用pop出队列并重新入队列，否则多次top()会打乱顺序