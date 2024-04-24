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
#### 有效的括号
- 显然使用栈实现，但有2种思路，将左括号入栈并将右括号与之匹配，或者将左括号对应的右括号入栈并看是否相等
- 字符都遍历完后，还需要判断栈是否为空
#### 逆波兰表达式求值
- 逆波兰表达式即后缀表达式，显然使用栈求解
- 需要注意的是，出栈2个操作数的顺序，后出栈的是左操作数
#### 滑动窗口最大值
- 首先想到的是用队列维护当前窗口元素，但是如何维护最大值？
- 暴力求解，每次遍历k的值，时间复杂度O(nk)
- 由于每次只有一个元素的变化，似乎可以维护最大值和第二大值及其下标index。如果最大值移除且移入值小于第二大值，则第二大值更新为最大值，再遍历查找新的第二大值；如果最大值移除且移入值大于第二大值，则为最大值；如果最大值移除且移入值等于第二大值，则移入值为第二大值，原第二大值为最大值；如果有2个最大值，则应该index小的为最大值
- 使用最大堆维护最大值，移除元素时需要更新
- 使用双端队列维护最大值，双端队列元素的index递增，元素的值必须严格单调递减，因为，若相邻2个元素的下标为i和j，显然 i < j，只要i还在窗口中，j也一定还在窗口中，若nums[i] <= nums[j]，则nums[i]必然不会为窗口中的最大值，应该删去
#### 前k高频元素
- 首先，记录不同元素的频率，O(n), O(n)
- 其次，使用排序算法对频率及其元素进行排序；似乎使用堆排序的复杂度较低，O(n log k), O(n);
- 也可以使用快排，不过我已经忘记什么是快排了🤣

### 二叉树
#### 前中后序遍历
##### 递归法
- 要确定递归函数的参数和返回值；
  要确定递归终止的条件；
  要确定单层递归的逻辑。
- 有时可能需要写一个内部递归函数作为辅助
##### 迭代遍历
- 前序：
  - 将当前节点（中节点）的值加入结果集中，依次加入不为空的右节点、左节点到栈中
- 中序：
  - 空节点可以入栈
  - 将当前节点（中节点，不为空）入栈，cur赋值为左节点，若当前节点为空，则cur赋值为栈弹出的节点，将值加入结果集，再cur赋值为右节点
  - 相当于只处理中节点（值入结果集），左叶节点相当于左节点为空的中节点
- 后序：
  - 法1：
    - 前序的中左右顺序，调整为中右左顺序，再将结果集反向，变为左右中顺序，即后序
  - 法2：
    - 先直接遍历到最左叶节点的左节点（空节点）
    - 用pre指针记录刚才处理的节点
    - 若右节点为空或pre指针（刚才处理的节点）正好等于右节点，则处理当前节点（中节点）
##### 统一迭代法
- 栈中只存放非空节点
- 相当于统一只处理中节点，当前节点（中节点）放入栈中后紧接着要放入nullptr空节点作为标记，标志当前节点已访问，下次出栈时就直接处理，左右非空节点按照前中后序的顺序相应的入栈
##### 层序遍历
- 使用队列辅助存储
- 处理每一层之前，使用int size记录当前层的节点数目
##### 翻转二叉树
- 递归法、统一迭代法（前中后序）、广度优先搜索（层序遍历）都可以
##### 对称
- 可以使用递归法或迭代法
- 关键在于每次处理2个对称位置的节点，按对称顺序处理子节点（左左与右右、左右与右左）