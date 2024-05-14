# algorithm_everyday

## 算法思路_记录

### 线性表

#### 顺序表
- todo

#### 单链表

#### 需注意
- 删除节点时，记得使用 `free(node)` 释放节点空间
- 公共元素与公共节点不是同一概念，公共元素是指节点元素值相等，公共节点是指节点指针指向同一节点（即节点指针值相等）
- 对于有关2个元素值有序的线性表的问题，可以使用**归并**的思想

#### 查找2个单链表的公共节点
- 由于是单链表，所以每个node只有1个next指针，从第一个公共节点开始的所有节点都是公共节点
- 若只需判断是否有公共节点，只需分别遍历到2个单链表的最后一个节点并判断是否相同
- 若需求第一个公共节点，可以先分别求两个单链表的长度并求差值，对较长的单链表先遍历这个差值，再同步遍历同时判断next指针是否相等

#### 2个单链表元素值的匹配
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
#### 层序遍历
- 使用队列辅助存储
- 处理每一层之前，使用int size记录当前层的节点数目
#### 翻转二叉树
- 递归法、统一迭代法（前中后序）、广度优先搜索（层序遍历）都可以
#### 对称二叉树
- 可以使用递归法或迭代法
- 关键在于每次处理2个对称位置的节点，按对称顺序处理子节点（左左与右右、左右与右左）
#### 二叉树的最大深度
- 首先，想到的是递归法(深度优先搜索)
- 还可以使用层序遍历，深度显然与层数直接相关
#### 二叉树的最小深度
- 需要注意的是，最小深度是根节点到最近的叶子节点的路径的节点数，若左子树为空，则最小深度=1+右子树的最小深度
- 可以使用DFS（递归法）
- 也可以使用BFS（层序遍历），当第一次遇到叶子节点，就返回
#### 完全二叉树的节点数
- 若只当作普通二叉树，可以使用递归法：1+左子树节点数+右子树节点数，也可以使用迭代法，如层序遍历
- 若利用完全二叉树的性质，通过一直向左子树遍历、向右子树遍历来判断是不是满二叉树，如果是，则按照公式计算，如果不是，则使用递归：1+f(left)+f(right)
#### 平衡二叉树
- 总体思路是自顶向下或自底向上
- 自顶向下若不记录已经计算过的值，则复杂度较高
- 自底向上可以使用后序遍历递归法
#### 二叉树的所有路径
- 根节点到所有节点的路径：首先想到的是DFS，由于要记录经过路径的节点，所以使用前序遍历
- 可以使用递归法或迭代法。关键在于回溯，处理一个叶节点后需要回溯到父节点的路径。迭代法需要使用辅助栈记录每个节点的路径。
#### 左叶子之和
- 左叶子节点的判断需要从父节点开始判断，也可以通过引入应该bool参数判断该节点是否为左叶子节点
- dfs可以使用迭代法实现
- bfs可以使用迭代法实现
#### 找树左下角的值
- 对于找最下一层最左边的值，首先想到的是层序遍历，可以每次记录一层中最左边的值，遍历结束后最后一个即为所求
- 也可以使用递归法，参数需要包含节点指针、当前深度，同时还要设置全局性的变量存储已知最大深度和最大深度最左边的节点值，需要保证优先搜索左边节点，前、中、后序都行
#### 路径总和
- 寻找是否存在一条由根节点到叶子节点的路径，使得节点值之和等于目标值
- 可以借助[二叉树的所有路径](#二叉树的所有路径)部分，依次遍历所有路径并且节点值之和
#### 从中序与后序遍历序列构造二叉树
- 中序遍历的顺序为：左中右，后序遍历的顺序为左右中，可以想象出，后序遍历的最后一个节点一定是根节点，由于没有重复元素，因此可以在中序遍历的数组中找到根节点，从而确定左子树和右子树的数组部分和大小，从而可以进行递归处理
#### 最大二叉树
- 此最大二叉树是递归定义的：找到数组中最大值作为根节点，然后左右子树分别使用根节点左右两边的数组递归构造
- 那么，如何寻找最大值很重要，由于原数组未排序，所以不能使用二分法，那么似乎只能一个一个比较
#### 合并二叉树
- 关键点在于如何同时同步遍历两个树
- 使用递归法较为简便，前中后序都可以
#### 二叉搜索树中的搜索
- 需要注意二叉搜索树BST的性质，左子树的值<根节点的值<右子树的值，递归定义
- 可以直接使用递归法
- 由于BST的性质导致节点值的顺序性，我们在确定搜索方向后就不需要再改变了（因为左子树的值<根节点的值<右子树的值），即不需要再回溯了，因此也可以使用迭代法通过while循环知道找到节点或nullptr
#### 验证二叉搜索树
- 显然，根据BST的递归定义，可通过暴力搜索左子树最大值和右子树最小值进行判断并递归调用
- 进一步优化，暴力求最大最小的方法会重复遍历节点，递归时每次都求最大和最小，效率低，可以将递归函数设置为判断子树的值是不是在指定范围内，同时每次递归只比较一次根节点的值
- 根据BST的性质，则中序遍历的值一定是严格升序的，只需判断当前值是否大于之前的节点值
#### 二叉搜索树的最小绝对差
- 注意树是二叉搜索树，所以可以求 当前节点值-左子树最大值 和 右子树最小值-当前节点值 进行比较，并递归调用
- 还是可以利用中序遍历，先求出递增序列，然后遍历求最小绝对差就行
#### 二叉搜索树中的众数
- 可以先中序遍历转换为升序数组 O(n)，再遍历 O(n)
- 优化：无需转换为升序数组，直接在中序遍历时计数，再将map转换为vector，进行排序
- 优化：根据二叉搜索树的性质，中序遍历为非递减序列，我们只需在遍历时记录上一次的值，相等时计数+1，不等时结束上一个计数并与最大计数比较，开始当前计数
#### 二叉树的最近公共祖先
- 如果2个节点分别在当前节点的左右子树中，那么最近公共祖先就是当前节点；如果都在一个子树中，则可以递归判断该子树
- 如果先判断是否在子树中，再递归地在子树中搜索，复杂度太高
- 可以通过递归返回指针指示是否在子树中，同时通过后序遍历实现所谓的回溯（自底向上查找）
- 还可以先遍历一遍记录所有节点的父节点，从而实现像我们自己查找最近公共祖先那样自底向上查找
#### 二叉搜索树的最近公共祖先
- 根据二叉搜索树的性质，只需当前节点值在p和q值之间就可以确定是最近公共祖先
#### 二叉树的插入操作
- 递归比较大小进行插入
- 或者使用迭代法进行模拟
#### 删除二叉搜索树中的节点
- 递归地找到要删除的节点，再将以此节点为根节点的树删除根节点后重构为二叉搜索树
#### 修剪二叉搜索树
- 递归法，遇到空节点直接返回nullptr；若当前节点值不在控制区间内，则返回对可能符合范围的左子树或右子树的递归调用；若当前节点值在控制区间内，则继续对左右儿子递归调用
- 由于二叉搜索树的有效性，可以直接使用迭代法进行处理
#### 将有序数组转换为二叉搜索树
- 数组为升序，二叉搜索树要求为平衡
- 可以使用递归，每次选中间节点作为根节点，再对左右子树和左右子数组递归调用
#### 把二叉搜索树转换为累加树
- 累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
- 根据二叉搜索树的性质，可以按照由大到小的顺序即右、中、左的顺便遍历

![二叉树汇总表](https://code-thinking-1253855093.file.myqcloud.com/pics/20211030125421.png)

### 回溯算法
#### 模板
```
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
```