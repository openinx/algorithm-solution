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

```CPP
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
* [Binary Tree Maximum Path Sum](https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/)







* [Candy](https://oj.leetcode.com/problems/candy/)
算法1:每次选择低谷点，然后按照低谷点从小到大排序，一次发各上坡路线的糖果。O(N*logN)
算法2: 左扫上坡路，保存到Array里面，右扫上坡路，与左扫上坡路比较取较大值。
犯了个傻逼错误 (静态内存memset) 
int a[3] ; memset(a, 0, sizeof(a)) ; // OK 
int *a = new int(3) ; memset(a, 0, sizeof(a)) ; // ERROR 
int *a = new int(3) ; memset(a, 0, sizeof(int) * 3 ) ; // OK 

* [Insert Interval](https://oj.leetcode.com/problems/insert-interval/)
* [Wildcard Matching](https://oj.leetcode.com/problems/wildcard-matching/)
KMP + 贪心 假设*的个数为K, 复杂度O(K*N)

* [Surrounded Regions ](https://oj.leetcode.com/problems/surrounded-regions/)
走迷宫问题。有个优化是只要对O在边界上的情况做搜索拓展即可。另外此题卡了DFS的内存，只能用BFS水之。


