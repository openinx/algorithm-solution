* [Reverse Words in a String](https://oj.leetcode.com/problems/reverse-words-in-a-string/)
模拟 字符串

* [Evaluate Reverse Polish Notation](https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/)
模拟 后缀表达式求值

* [Max Points on a Line](https://oj.leetcode.com/problems/max-points-on-a-line/)
平面给出N个点，找一个直线，使得经过的点数最多。枚举每个点，以此为原点坐标，求出相对原点坐标，然后计算y/x，用hash表计数求出最大的重复值。O(N^2)

* [Sort List](https://oj.leetcode.com/problems/sort-list/)
QuickSort和MergeSort链表版本. O(NlogN) 值得注意的情况是所有元素都相同时，假设qsort分段从左到右的话，qsort会退化O(N^2).

* [Insertion Sort List ](https://oj.leetcode.com/problems/insertion-sort-list/)
插入排序链表实现. O(N^2)

* [LRU Cache ](https://oj.leetcode.com/problems/lru-cache/)
LRU-Cache算法。最有复杂度保证每次get,set操作都为O(1). 双向链表+Hash。 用C++10的STL的LIST和MAP的GET，SET复杂度O(logN)

* [Binary Tree Postorder Traversal ](https://oj.leetcode.com/problems/binary-tree-postorder-traversal/)
智商着急，写个栈模拟后序遍历都卡半天。 网上有很简洁的写法。

```cpp
void postOrderTraversalIterativeTwoStacks(BinaryTree *root) {
  if (!root) return;
  stack<BinaryTree*> s;
  stack<BinaryTree*> output;
  s.push(root);
  while (!s.empty()) {
    BinaryTree *curr = s.top();
    output.push(curr);
    s.pop();
    if (curr->left)
      s.push(curr->left);
    if (curr->right)
      s.push(curr->right);
  }
  while (!output.empty()) {
    cout << output.top()->data << " ";
    output.pop();
  }
}
```

* [Binary Tree Preorder Traversal](https://oj.leetcode.com/problems/binary-tree-preorder-traversal/)

* [Reorder List](https://oj.leetcode.com/problems/reorder-list/)
翻转后半段链表，然后间隔一个拼接。O(N)

* [Linked List Cycle II ](https://oj.leetcode.com/problems/linked-list-cycle-ii/)
设一个慢指针， 一个快指针。慢指针每次走一步，快指针每次走两步。假若有环，快指针必定和慢指针在某个环内点重合。然后证明找到重合点之后，再走相同的步数可以找到环的起始点。

* [Linked List Cycle](https://oj.leetcode.com/problems/linked-list-cycle/)
同上。

* [Word Break II ](https://oj.leetcode.com/problems/word-break-ii/)
给定一个单词集和一个字符串，判断字符串是否可以拆成多个单词，要求每个单词都是单词集里面的。很明显的DP， 问题是要回溯。我写了个递归回溯。复杂度O(N^3).

* [Word Break](https://oj.leetcode.com/problems/word-break/)
同上

* [Copy List with Random Pointer](https://oj.leetcode.com/problems/copy-list-with-random-pointer/)
这题答案很巧妙。a->b->c这样的链表，每个元素后面插入一个前一个元素。a->A->b->B->c->C . 然后再设置A，B,C的random指针，最后把A->B->C这个链表剥离出来即可。 

* [Binary Tree Maximum Path Sum](https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/) 
一颗树，每个节点都有一个数。求一条路径，使得路径上各点权值相加最大。动态规划 + 树遍历

* [Single Number II](https://oj.leetcode.com/problems/single-number-ii/)
32位二进制对齐，求N个数各BIT位之和MOD 3形成的二进制转10进制。即答案。

* [Single Number](https://oj.leetcode.com/problems/single-number/)
XOR运算满足交换律和结合律。直接XOR各数求和即答案。

* [Candy](https://oj.leetcode.com/problems/candy/)
算法1:每次选择低谷点，然后按照低谷点从小到大排序，一次发各上坡路线的糖果。O(N*logN)
算法2: 左扫上坡路，保存到Array里面，右扫上坡路，与左扫上坡路比较取较大值。O(N)
犯了个傻逼错误：

```cpp
int a[3] ; memset(a, 0, sizeof(a)) ; // OK 
int *a = new int(3) ; memset(a, 0, sizeof(a)) ; // ERROR 
int *a = new int(3) ; memset(a, 0, sizeof(int) * 3 ) ; // OK 
```

* [Gas Station ](https://oj.leetcode.com/problems/gas-station/)

* [Clone Graph](https://oj.leetcode.com/problems/clone-graph/) 
图广度优先遍历， 写个深度优先遍历的版本？

* [Palindrome Partitioning II](https://oj.leetcode.com/problems/palindrome-partitioning-ii/)
DP：将一个字符串切割成若干个回文串，求最小切割次数。O(N^2)

* [Palindrome Partitioning ](https://oj.leetcode.com/problems/palindrome-partitioning/)
DP

* [Surrounded Regions ](https://oj.leetcode.com/problems/surrounded-regions/)
走迷宫问题。有个优化是只要对O在边界上的情况做搜索拓展即可。另外此题卡了DFS的内存，只能用BFS水之。

* [Sum Root to Leaf Numbers ](https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/)
DP + 树遍历

* [Longest Consecutive Sequence ](https://oj.leetcode.com/problems/longest-consecutive-sequence/)
为什么直接排序，然后水过去了?

* [Word Ladder II](https://oj.leetcode.com/problems/word-ladder-ii/)
BFS 然后按照步数DFS回溯找路径。

* [Word Ladder ](https://oj.leetcode.com/problems/word-ladder/)
BFS

* [Insert Interval](https://oj.leetcode.com/problems/insert-interval/)
* [Wildcard Matching](https://oj.leetcode.com/problems/wildcard-matching/)
KMP + 贪心 假设*的个数为K, 复杂度O(K*N)




