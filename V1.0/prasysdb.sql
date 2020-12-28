/*
 Navicat Premium Data Transfer

 Source Server         : mysql
 Source Server Type    : MySQL
 Source Server Version : 50730
 Source Host           : localhost:3306
 Source Schema         : test

 Target Server Type    : MySQL
 Target Server Version : 50730
 File Encoding         : 65001

 Date: 27/12/2020 18:30:12
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for paper
-- ----------------------------
DROP TABLE IF EXISTS `paper`;
CREATE TABLE `paper`  (
  `id` int(9) NOT NULL,
  `qus` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `ans` varchar(500) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `myans` varchar(500) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `isright` int(1) NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of paper
-- ----------------------------
INSERT INTO `paper` VALUES (126, '算法的计算量的大小称为计算的（    ） A．效率   B. 复杂性  C. 现实性  D. 难度', 'B', NULL, 0);
INSERT INTO `paper` VALUES (128, '一个算法应该是（     ）。A．程序 B．问题求解步骤的描述 C．要满足五个基本特性 D．A和C', 'B', '0', 0);
INSERT INTO `paper` VALUES (129, '下面关于算法说法错误的是（    ）A．算法最终必须由计算机程序实现 B.为解决某问题的算法同为该问题编写的程序含义是相同的 C. 算法的可行性是指指令不能有二义性 D. 以上几个都是错误的', 'D', '0', 0);
INSERT INTO `paper` VALUES (130, '下面说法错误的是（    ）\r\n\r\n    (1）算法原地工作的含义是指不需要任何额外的辅助空间\r\n\r\n   （2）在相同的规模n下，复杂度O(n)的算法在时间上总是优于复杂度O(2n)的算法\r\n\r\n   （3）所谓时间复杂度是指最坏情况下，估算算法执行时间的一个上界\r\n\r\n   （4）同一个算法，实现语言的级别越高，执行效率就越低 A．(1) B.(1),(2） C.(1),(4) D.(3)', 'C', '0', 0);
INSERT INTO `paper` VALUES (134, '1以下那一个术语与数据的存储结构无关？（    ）\r\n\r\nA．栈 B. 哈希表 C. 线索树  D.  双向链表', 'A', '0', 0);
INSERT INTO `paper` VALUES (137, '记录是数据处理的最小单位。 (    ) ', '错', '0', 0);
INSERT INTO `paper` VALUES (138, '数据的逻辑结构是指数据的各数据项之间的逻辑关系；(   )', '错', '0', 0);
INSERT INTO `paper` VALUES (139, '算法的优劣与算法描述语言无关，但与所用计算机有关。(    )', '错', '0', 0);
INSERT INTO `paper` VALUES (141, '算法可以用不同的语言描述，如果用C 语言或PASCAL语言等高级语言来描述，则算法实际上就是程序了。(    )', '错', '0', 0);
INSERT INTO `paper` VALUES (142, '程序一定是算法。(    )', '错', '0', 0);
INSERT INTO `paper` VALUES (149, '评价一个好的算法，您是从哪几方面来考虑的？', '评价好的算法有四个方面。一是算法的正确性；二是算法的易读性；三是算法的健壮性；四是算法的时空效率（运行）。', '0', 0);

-- ----------------------------
-- Table structure for qsbank
-- ----------------------------
DROP TABLE IF EXISTS `qsbank`;
CREATE TABLE `qsbank`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `chap` int(1) NULL DEFAULT NULL,
  `type` int(1) NULL DEFAULT NULL,
  `grade` int(1) NULL DEFAULT NULL,
  `qus` varchar(500) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `ans` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 151 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of qsbank
-- ----------------------------
INSERT INTO `qsbank` VALUES (1, 2, 0, 1, '链式存储结构的最大优点是（  ）。\r\nA.便于随机存取	B.存储密度高 \r\nC.无需预分配空间	D.便于进行插入和删除操作 \r\n', 'C');
INSERT INTO `qsbank` VALUES (2, 2, 0, 1, '假设在顺序表{a0,a1,……,an－1}中，每一个数据元素所占的存储单元的数目为4，且第0个数据元素的存储地址为100，则第7个数据元素的存储地址是（ ）。\r\nA.106         B. 107          C.124      D.128\r\n', 'D');
INSERT INTO `qsbank` VALUES (3, 2, 0, 1, '在线性表中若经常要存取第i个数据元素及其前趋，则宜采用（  ）存储方式。\r\nA.顺序表			B. 带头结点的单链表\r\nC.不带头结点的单链表			D. 循环单链表\r\n', 'A');
INSERT INTO `qsbank` VALUES (4, 2, 0, 2, '在链表中若经常要删除表中最后一个结点或在最后一个结点之后插入一个新结点，则宜采用（  ）存储方式。\r\nA.顺序表						B. 用头指针标识的循环单链表\r\nC. 用尾指针标识的循环单链表		D. 双向链表\r\n', 'C');
INSERT INTO `qsbank` VALUES (5, 2, 0, 2, '在一个单链表中的p和q两个结点之间插入一个新结点，假设新结点为S,则修改链的java语句序列是（  ）。\r\nA.s.setNext(p); q.setNext(s);      B. p.setNext(s.getNext()); s.setNext(p);\r\nC. q.setNext(s.getNext()); s.setNext(p);   D. p.setNext(s); s.setNext(q);\r\n', 'D');
INSERT INTO `qsbank` VALUES (6, 2, 0, 2, '在一个含有n个结点的有序单链表中插入一个新结点，使单链表仍然保持有序的算法的时间复杂度是（  ）。\r\nA.O(1)    B. O(log2n)   C. O(n)     D. O(n2)\r\n', 'C');
INSERT INTO `qsbank` VALUES (7, 2, 0, 3, '要将一个顺序表{a0,a1,……,an-1}中第i个数据元素ai(0≤i≤n-1)删除，需要移动（  ）个数据元素。\r\nA.i        B. n-i-1        C. n-i       D. n-i+1\r\n', 'B');
INSERT INTO `qsbank` VALUES (8, 2, 0, 3, '在带头结点的双向循环链表中的p结点之后插入一个新结点s，其修改链的java语句序列是（  ）。\r\nA.p.setNext(s); s.setPrior(p); p.getNext().setPrior(s);\r\n s.setNext(p.getPrior());\r\nB.p.setNext(s); p.getNext().setPrior(s); s.setPrior(p);\r\n s.setNext(p.getNext());\r\nC.s.setPrior(p); s.setNext(p.getNext()); p.setNext(s);\r\n p.getNext().setPrior(s);\r\nD.s.setNext(p.getNext()); s.setPrior(p); p.getNext().setPrior(s); \r\np.setNext(s);\r\n', 'D');
INSERT INTO `qsbank` VALUES (9, 2, 0, 3, '顺序表的存储密度是（  ）\r\nA．小于1     B. 等于1     C. 大于1      D. 不能确定\r\n', 'B');
INSERT INTO `qsbank` VALUES (10, 2, 0, 3, '单链表的存储密度是（  ）。\r\nA．小于1     B. 等于1     C. 大于1      D. 不能确定\r\n', 'A');
INSERT INTO `qsbank` VALUES (11, 2, 1, 1, '线性表的逻辑顺序总是与其物理顺序一致。 （ ）', '错');
INSERT INTO `qsbank` VALUES (12, 2, 1, 1, '线性表的顺序存储优于链式存储。 （ ）', '错');
INSERT INTO `qsbank` VALUES (13, 2, 1, 1, '在长度为 n的顺序表中， 求第 i个元素的直接前驱算\r\n法的时间复杂度为 0（ 1）。 （ ）', '对');
INSERT INTO `qsbank` VALUES (14, 2, 1, 2, '顺序表和一维数组一样， 都可以按下标随机\r\n（或直接）访问。 （ ）', '对');
INSERT INTO `qsbank` VALUES (15, 2, 1, 2, '顺序表的空间利用率高于链表。 （ ）', '对');
INSERT INTO `qsbank` VALUES (16, 2, 1, 2, '单链表可以实现随机存取。 （ ）', '错');
INSERT INTO `qsbank` VALUES (17, 2, 1, 3, '顺序查找法适用于存储结构为顺序或链接存储\r\n的线性表。 （ ）', '对');
INSERT INTO `qsbank` VALUES (18, 2, 1, 3, '在线性链表中删除中间的结点时，只需将\r\n被删结点释放。 （ ）', '错');
INSERT INTO `qsbank` VALUES (19, 2, 1, 3, '线性表若采用链式存储表示 , 在删除时不\r\n需要移动元素。 （ ）', '对');
INSERT INTO `qsbank` VALUES (20, 2, 1, 3, '循环链表的结点与单链表的结点结构完全相同，\r\n只是结点间的连接方式不同。 （ ）', '对');
INSERT INTO `qsbank` VALUES (21, 2, 2, 1, '编写一个顺序表类的成员函数，实现对顺序表就地逆置的操作。所谓逆置，就是把（a1,a2,…,an）变成（an,an-1,…,a1）；所谓就地，就是指逆置后的数据元素仍存储在原来顺序表的存储空间中，即不为逆置后的顺序表另外分配存储空间。', '参考答案:\r\npublic void reverse() {\r\n		for (int i = 0,j=curLen-1; i < j; i++,j--) {\r\n			Object temp = listElem[i];\r\n			listElem[i] = listElem[j];\r\n			listElem[j] = temp;\r\n		}\r\n	}\r\n');
INSERT INTO `qsbank` VALUES (22, 2, 2, 1, '编写一个顺序表类的成员函数，实现对顺序表循环右移k位的操作。即原来顺序表为（a1,a2,…,an-k,an-k+1,…, an），循环向右移动k位后变成（an-k+1,…, an ,a1,a2,…,an-k）。要求时间复杂度为O（n）。', '参考答案:\r\npublic void shit(int k) {\r\n		int n=curLen,p=0,i,j,l;\r\n        Object temp;\r\n     	for(i=1;i<=k;i++)\r\n          if(n%i==0&&k%i==0) //求n和k的最大公约数p\r\n              p=i;\r\n        for(i=0;i<p;i++){\r\n           j=i;\r\n           l=(i+n-k)%n;\r\n           temp=listElem[i];\r\n           while(l!=i){\r\n             listElem[j]=listElem[l];\r\n             j=l;\r\n             l=(j+n-k)%n;\r\n           }// 循环右移一步\r\n        listElem[j]=temp;\r\n        }\r\n }\r\n');
INSERT INTO `qsbank` VALUES (23, 2, 2, 2, '编写一个单链表类的成员函数，实现在非递减的有序单链表中插入一个值为x的数据元素，并使单链表仍保持有序的操作。', '参考答案(方法一):\r\npublic void insert(int  x) {\r\n		Node p = head.getNext();//p指向首结点\r\n		Node q = head;// q用来记录p的前驱结点\r\n		int temp;\r\n		while (p != null) {\r\n			temp = ((Integer) p.getData()).intValue();\r\n			if (temp < x) {\r\n				q = p;\r\n				p = p.getNext();\r\n			} else\r\n				break;\r\n		}\r\n\r\n		Node s = new Node(x); // 生成新结点\r\n		s.setNext(p);// 将s结点插入到单链表的q结点与p结点之间\r\n		q.setNext(s);\r\n	}\r\n');
INSERT INTO `qsbank` VALUES (24, 2, 2, 2, '编写一个单链表类的成员函数，实现对带头结点的单链表就地逆置的操作。所谓逆置，就是把（a1,a2,…,an）变成（an,an-1,…,a1）；所谓就地，就是指逆置后的结点仍存储在原来单链表的存储空间中，只不过通过修改链来改变单链表中每一个结点之间的逻辑位置关系。', '参考答案:\r\npublic void reverse() { //实现对单链表就地逆置(采用的是头插法)\r\n		Node p = head.getNext();\r\n		head.setNext(null);\r\n		Node q;\r\n		while (p != null) {\r\n			q = p.getNext();\r\n			p.setNext(head.getNext());\r\n			head.setNext(p);\r\n			p = q;\r\n		}\r\n	}\r\n\r\n');
INSERT INTO `qsbank` VALUES (25, 2, 2, 3, '编写一个单链表类的成员函数，实现删除不带头结点的单链表中数据域值等于x的第一个结点的操作。若删除成功，则返回被删除结点的位置；否则，返回-1。', '参考答案:\r\n     public int remove(Object x) {\r\n		Node p = head;// 初始化,p指向首结点\r\n		Node q=null;  //q用来记录p的前驱结点\r\n     int j = 0; //j为计数器\r\n// 从单链表中的首结点元素开始查找，直到p.getData()指向元素x或到达单链表的表尾\r\n		while (p != null && !p.getData().equals(x)) {\r\n			 q=p;\r\n             p = p.getNext();// 指向下一个元素\r\n			 ++j;// 计数器的值增1\r\n		 }\r\n		if (p!=null&&q==null) //删除的是单链表中的首结点\r\n          head=p.getNext();\r\n      else if (p != null) {// 删除的是单链表中的非首结点\r\n			 q.setNext(p.getNext());\r\n		      }\r\n      else\r\n			 return -1;//值为x的结点在单链表中不存在\r\n	     return j;\r\n      }\r\n');
INSERT INTO `qsbank` VALUES (26, 3, 0, 1, '在栈中存取数据的原则是（ ）。A．先进先出   B. 先进后出  C. 后进后出   D. 没有限制', 'B');
INSERT INTO `qsbank` VALUES (27, 3, 0, 1, '若将整数1、2、3、4依次进栈，则不可能得到的出栈序列是（  ）。A．1234    B. 1324  C. 4321   D. 1423', 'D');
INSERT INTO `qsbank` VALUES (28, 3, 0, 1, '在顺序栈中，若栈顶指针top指向栈顶元素的下一个存储单元，且顺序栈的最大容量是maxSize，则顺序栈的判空条件是（  ）。A．top==0  B.top==-1  C. top==maxSize  D.top==maxSize-1', 'A');
INSERT INTO `qsbank` VALUES (29, 3, 0, 2, '在顺序栈中，若栈顶指针top指向栈顶元素的下一个存储单元，且顺序栈的最大容量是maxSize。则顺序栈的判满的条件是（ ）。 A．top==0   B.top==-1   C. top==maxSize  D.top==maxSize-1', 'C');
INSERT INTO `qsbank` VALUES (30, 3, 0, 2, '在循环顺序队列中，假设以少用一个存储单元的方法来区分队列判满和判空的条件，front和rear分别为队首和队尾指针，它们分别指向队首元素和队尾元素的下一个存储单元，队列的最大存储容量为maxSize，则队列的判空条件是（ ）。A．front==rear  B. front!=rear  C. front==rear+1  D. front==(rear+1)% maxSize ', 'A');
INSERT INTO `qsbank` VALUES (31, 3, 0, 2, '在循环顺序队列中，假设以少用一个存储单元的方法来区分队列判满和判空的条件，front和rear分别为队首和队尾指针，它们分别指向队首元素和队尾元素的下一个存储单元，队列的最大存储容量为maxSize，则队列的长度是（  ）。A．rear-front  B. rear-front+1  C. (rear-front+maxSize)%maxSize   D. (rear-front+1)%maxSize', 'C');
INSERT INTO `qsbank` VALUES (32, 3, 0, 3, '设长度为n的链队列采用单循环链表加以表示，若只设一个头指针指向队首元素，则入队操作的时间复杂度为（ ）。A．O(1)   B．O(n)  C．O(log2n)   D．O(n2)', 'B');
INSERT INTO `qsbank` VALUES (33, 3, 0, 3, '在队列中存取数据元素的原则是（  ）。A．先进先出  B. 先进后出  C. 后进先出  D. 没有限制', 'A');
INSERT INTO `qsbank` VALUES (34, 3, 0, 3, '在链栈中，进行出栈操作时（ ）。A．需要判断栈是否满   B. 需要判断栈是否为空  C. 需要判断栈元素的类型  D. 无需对栈作任何差别', 'B');
INSERT INTO `qsbank` VALUES (35, 3, 0, 3, '在循环顺序队列中，假设以少用一个存储单元的方法来区分队列判满和判空的条件，front和rear分别为队首和队尾指针，它们分别指向队首元素和队尾元素的下一个存储单元，队列的最大存储容量为maxSize，则队列的判满条件是（ ）。 A．front==rear  B. front!=rear  C. front==rear+1  D. front==(rear+1)% maxSize', 'D');
INSERT INTO `qsbank` VALUES (36, 3, 1, 1, '两个栈共享一片连续内存空间时， 为提高内存利用率，减少溢出机会，应把两个栈的栈底分别设在这片内存空间的两端。（ ）', '对');
INSERT INTO `qsbank` VALUES (37, 3, 1, 1, '链式栈与顺序栈相比, 一个明显的优点是通常不会出现栈满的情况。（ ）', '对');
INSERT INTO `qsbank` VALUES (38, 3, 1, 1, '链队列的出队操作总是需要修改尾指针。（ ）', '错');
INSERT INTO `qsbank` VALUES (39, 3, 1, 2, '栈和队列都是顺序存取的线性表, 但它们对存取位置的限制不同。（ ）', '对');
INSERT INTO `qsbank` VALUES (40, 3, 1, 2, '消除递归不一定需要使用栈，此说法（ ）', '对');
INSERT INTO `qsbank` VALUES (41, 3, 1, 2, '栈是实现过程和函数等子程序所必需的结构。（ ）', '对');
INSERT INTO `qsbank` VALUES (42, 3, 1, 3, '若输入序列为1，2，3，4，5，6，则通过一个栈可以输出序列1，5，4，6，2，3。（ ）', '错');
INSERT INTO `qsbank` VALUES (43, 3, 1, 3, '通常使用队列来处理函数或过程的调用。（ ）', '错');
INSERT INTO `qsbank` VALUES (44, 3, 1, 3, '队列和栈都是运算受限的线性表，只允许在表的两端进行运算。（ ）', '错');
INSERT INTO `qsbank` VALUES (45, 3, 1, 3, '即使对不含相同元素的同一输入序列进行两组不同的合法的入栈和出栈组合操作，所得的输出序列也一定相同。（ ）', '错');
INSERT INTO `qsbank` VALUES (46, 3, 2, 1, '编写一个函数，要求借助一个栈把一个数组中的数据元素逆置。', '参考答案://借助一个顺序栈将已知一个数组中的数据元素逆置   public  reverse(Object [] a) throws Exception   SqStack S=new SqStack(a.length); //构造一个容量为a.length的顺序栈  for(int i=0;i<a.length;i++  S.push(a[i]);   for( int i=0;i<a.length;i++) a[i]=S.pop();\r\n    }');
INSERT INTO `qsbank` VALUES (47, 3, 2, 1, '编写一个函数判断一个字符序列是否为回文序列，所谓回文序列就是正读与反读都相同的字符序列，例如：abba和abdba均是回文序列。要求只使用栈来实现。', '参考答案:\r\n//判断字符序列是否为回文序列,若是则返回true值,否则返回false。public boolean isPalindSeq(String str) {  LinkStack S = new LinkStack(); int i = 0; for (; i < str.length(); i++) S.push(str.charAt(i)); for (i = 0; i < str.length(); i++) { char c = ((Character) S.pop()).charValue(); if (c != str.charAt(i)) return false; }return true;}');
INSERT INTO `qsbank` VALUES (48, 3, 2, 2, '假设以一个数组实现两个栈：一个栈以数组的第一个存储单元作为栈底，另一个栈以数组的最后一个存储单元作为栈底,这种栈称为顺序双向栈。试编写一个顺序双向栈类DuSqStack，类中要求编写3个方法。一个是构造方法DuDuSqStack(int maxSize),此方法实现构造一个容量为maxSize的顺序双向空栈；一个是实现入栈操作的方法push(Object X,int i),此方法完成将数据元素X压入到第i(i=0或1)号栈中的操作；一个是实现出栈操作的方法pop（int i),此方法完成将第i号栈的栈顶元素出栈的操作。', '参考答案:\r\nclass DuSqStack{\r\n	   private Object[] stackElem; // 栈存储空间\r\n	   private int top0; //栈顶指针,指示第0号的栈顶元素的下一个位置\r\n    private int top1; //栈顶指针,指示第1号的栈顶元素的下一个位置\r\n    private int base0;//栈尾指针,指示第0号的栈底元素\r\n    private int base1;//栈尾指针,指示第1号的栈底元素');
INSERT INTO `qsbank` VALUES (49, 3, 2, 2, '循环顺序队列类采用设置一个计数器的方法来区分循环队列的判空和判满。试分别编写顺序循环队列中入队和出队操作的函数。', '参考答案:\r\n//循环顺序队列存储结构类描述如下:\r\nclass CircleSqQueue_num  {\r\nprivate Object[] queueElem; // 队列存储空间\r\nprivate int front;// 队首的引用，若队列不空，指向队首元素，初值为0\r\n   private int rear;// 队尾的引用，若队列不空，指向队尾元素的下一个位置,初值为0\r\n	  private int num; // 计数器用来记录队列中的数据元素个数\r\n\r\n……\r\n\r\n}  // CircleSqQueue_num类结束');
INSERT INTO `qsbank` VALUES (50, 3, 2, 3, '假设采用带头结点的循环链表来表示队列，并且只设一个指向队尾元素的指针（不设队首指针），试编写相应的队列置空、队列判空、入队和出队操作的函数。', '参考答案:\r\n用队尾指针标识的循环链队列的类描述如下:\r\nclass CircleLinkQueue {\r\n	     private Node rear;// 循环链队列的尾指针\r\n……\r\n}');
INSERT INTO `qsbank` VALUES (51, 4, 0, 1, '对一棵树进行后根遍历操作与对这棵树所对应的二叉树进行（ ）遍历操作相同。A．先根    B. 中根   C. 后根    D. 层次', 'B');
INSERT INTO `qsbank` VALUES (52, 4, 0, 1, '在哈夫曼树中，任何一个结点它的度都是（  ）。A．0或1    B. 1或2    C. 0或2    D. 0或1或2', 'C');
INSERT INTO `qsbank` VALUES (53, 4, 0, 1, '对一棵深度为h的二叉树，其结点的个数最多为（  ）。A．2h      B. 2h-1    C. 2h-1      D. 2h-1', 'D');
INSERT INTO `qsbank` VALUES (54, 4, 0, 2, '一棵非空二叉树的先根遍历与中根遍历正好相同，则该二叉树满足（ ）A．所有结点无左孩子    B. 所有结点无右孩子     C. 只有一个根结点    D. 任意一棵二叉树', 'A');
INSERT INTO `qsbank` VALUES (55, 4, 0, 2, '一棵非空二叉树的先根遍历与中根遍历正好相反，则该二叉树满足（  ）A．所有结点无左孩子    B. 所有结点无右孩子     C. 只有一个根结点     D. 任意一棵二叉树', 'B');
INSERT INTO `qsbank` VALUES (56, 4, 0, 2, '假设一棵二叉树中度为1的结点个数为5，度为2的结点个数为3，则这棵二叉树的叶结点的个数是（  ）A．2     B. 3      C. 4     D. 5', 'C');
INSERT INTO `qsbank` VALUES (57, 4, 0, 3, '若某棵二叉树的先根遍历序列为ABCDEF，中根遍历序列为CBDAEF，则这棵二叉树的后根遍历序列为（ ）。A．FEDCBA     B. CDBFEA      C. CDBEFA       D. DCBEFA', 'B');
INSERT INTO `qsbank` VALUES (58, 4, 0, 3, '若某棵二叉树的后根遍历序列为DBEFCA，中根遍历序列为DBAECF，则这棵二叉树的先根遍历序列为（  ）。A．ABCDEF      B. ABDCEF    C. ABCDFE    D. ABDECF', 'B');
INSERT INTO `qsbank` VALUES (59, 4, 0, 3, '根据以权值为{2，5，7，9，12}构造的哈夫曼树所构造的哈夫曼编码中最大的长度为（  ）A．2        B. 3       C. 4       D. 5', 'B');
INSERT INTO `qsbank` VALUES (60, 4, 0, 3, '在有n个结点的二叉树的二叉链表存储结构中有（  ）个空的指针域。A．n-1     B. n     C. n+1     D. 0', 'C');
INSERT INTO `qsbank` VALUES (61, 4, 1, 1, '若一棵二叉树中的结点均无右孩子，则该二叉树的中根遍历和后根遍历序列正好相反。（ ）', '错');
INSERT INTO `qsbank` VALUES (62, 4, 1, 1, '任何一棵二叉树的叶结点在三种遍历中的相对次序是不变的。（ ）', '对');
INSERT INTO `qsbank` VALUES (63, 4, 1, 1, '对二叉排序树进行中根遍历， 可得到结点的有序排列。（ ）', '对');
INSERT INTO `qsbank` VALUES (64, 4, 1, 2, '在一棵二叉树中，假定每个结点只有左子女，没有右子女，对它分别进行前序遍历和中根遍历，则具有相同的结果。( )', '错');
INSERT INTO `qsbank` VALUES (65, 4, 1, 2, '存在这样的二叉树，对它采用任何次序的遍历，\r\n结果相同。( )', '对');
INSERT INTO `qsbank` VALUES (66, 4, 1, 2, '对于同一组关键码互不相同的记录，若生成二叉搜索树时插入记录的次序不同则得到不同形态的二叉搜索树。( )', '对');
INSERT INTO `qsbank` VALUES (67, 4, 1, 3, '若一棵二叉树中的结点均无右孩子， 则该二叉树的中根遍历和后根遍历序列正好相同。（ ）', '对');
INSERT INTO `qsbank` VALUES (68, 4, 1, 3, '折半查找所对应的判定树，既是一棵二叉查找树，又是一棵理想平衡二叉树。( )', '对');
INSERT INTO `qsbank` VALUES (69, 4, 1, 3, '向一棵B树插入关键码的过程中， 若最终引起树根结点的分裂， 则新树比原树的高度减少1。( )', '错');
INSERT INTO `qsbank` VALUES (70, 4, 1, 3, '二叉树中不存在度大于2的结点， 当某个结点只有一棵子树时无所谓左、右子树。( )', '错');
INSERT INTO `qsbank` VALUES (71, 4, 2, 1, '编写一个基于二叉树类的统计叶结点数目的成员函数。', '参考答案：public int countLeafNode(BiTreeNode T) {// 统计叶结点数目\r\n		int count = 0;\r\n		if (T != null) {\r\n			if (T.getLchild() == null && T.getRchild() == null) {\r\n				++count;// 叶结点数增1\r\n			} else {\r\n				count += countLeafNode(T.getLchild()); // 加上左子树上叶结点数\r\n				count += countLeafNode(T.getRchild());// 加上右子树上的叶结点数}}return count;}');
INSERT INTO `qsbank` VALUES (72, 4, 2, 1, '编写一个基于二叉树类的查找二叉树结点的成员函数。', '参考答案：public BiTreeNode searchNode(BiTreeNode T,Object x) {  // 在以T为根结点的二叉树中查找值为x的结点,若找到,则返回该结点,否则返回空值 if (T != null) { if (T.getData().equals(x) return T; else {BiTreeNode lresult= searchNode(T.getLchild(),x); // 在左子树上查找 return (lresult!=null?lresult:searchNode(T.getRchild(),x)) ;// 若左子树上没找到,则到右子树上找}}return null;}');
INSERT INTO `qsbank` VALUES (73, 4, 2, 2, '编写算法求一棵二叉树的根结点root到一个指定结点p之间的路径并输出。', '参考答案：\r\n// 求根结点到指定结点的路径过程中，采用了后跟遍历的思想，最终求得的路径保存在一个链栈中，其中根结点处于栈顶位置，指定结点处于栈底位置。\r\n//下面用到的二叉树结点类BiTreeNode在书中第5章中已给出\r\npublic LinkStack getPath(BiTreeNode root, BiTreeNode p) {\r\n		BiTreeNode T = root;\r\n		LinkStack S = new LinkStack();// 构造链栈\r\n		if (T != null) {\r\n			S.push(T); // 根结点进栈\r\n			Boolean flag;// 访问标记\r\n			BiTreeNode q = null;// q指向刚被访问的结点\r\n			while (!S.isEmpty()) {\r\n				while (S.peek() != null				// 将栈顶结点的所有左孩子结点入栈\r\nS.push(((BiTreeNode) S.peek()).getLchild());S.pop(); // 空结点退栈\r\nwhile (!S.isEmpty()) {\r\nT = (BiTreeNode) S.peek();// 查看栈顶元素	if (T.getRchild() == null || T.getRchild() == q) {\r\nif (T.equals(p)) { // 对栈S进行倒置，以保证根结点处于栈顶位置LinkStack S2 = new LinkStack(); while (!S.isEmpty())S2.push(S.pop());return S2;					}S.pop();// 移除栈顶元素q = T;// q指向刚被访问的结点\r\nflag = true;// 设置访问标记} else {			S.push(T.getRchild());// 右孩子结点入栈flag = false;// 设置未被访问标记	}if (!flag)break}}}returnnull;}');
INSERT INTO `qsbank` VALUES (74, 4, 2, 2, '编写算法统计树(基于孩子兄弟链表存储结构)的叶子数目。', '参考答案：//下面用到的孩子兄弟链表结构中的结点类CSTreeNode在书中第5章中已给出\r\npublic int countLeafNode(CSTreeNode T) {\r\n		int count = 0;\r\n		if (T != null) {\r\nif (T.getFirstchild() == null)		   ++count;// 叶结点数增1else	  count += countLeafNode(T.getFirstchild()); // 加上孩子上叶结点数  count += countLeafNode(T.getNextsibling());// 加上兄弟上叶结点数	}return count;}');
INSERT INTO `qsbank` VALUES (75, 4, 2, 3, '编写算法计算树', '参考答案：public int treeDepth(CSTreeNode T) {if (T != null) {int h1= treeDepth(T.getFirstchild());\r\nint h2= treeDepth(T.getNextsibling()) return h1+1>h2?h1+1:h2	}return 0;}');
INSERT INTO `qsbank` VALUES (76, 5, 0, 1, '内部排序算法的稳定性是指(   )。A．该排序算法不允许有相同的关键字记录 B．该排序算法允许有相同的关键字记录 C．平均时间为0（n log n）的排序方法 D．以上都不对', 'D');
INSERT INTO `qsbank` VALUES (77, 5, 0, 1, '下面给出的四种排序算法中，(   )是不稳定的排序。 A．插入排序 B．堆排序 C．二路归并排序 D．冒泡排序', 'B');
INSERT INTO `qsbank` VALUES (78, 5, 0, 1, '在下列排序算法中，哪一种算法的时间复杂度与初始排序序列无关（   ）。A．直接插入排序 B．冒泡排序 C．快速排序  D．直接选择排序', 'D');
INSERT INTO `qsbank` VALUES (79, 5, 0, 2, '关键字序列（8，9，10，4，5，6，20，1，2）只能是下列排序算法中(   )的两趟排序后的结果。 A．选择排序  B.冒泡排序  C.插入排序  D.堆排序', 'C');
INSERT INTO `qsbank` VALUES (80, 5, 0, 2, '下列排序方法中，(     )所需的辅助空间最大。 A．选择排序  B．希尔排序  C．快速排序  D．归并排序', 'D');
INSERT INTO `qsbank` VALUES (81, 5, 0, 2, '一组记录的关键字为（46，79，56，38，40，84），则利用快速排序的方法，以第一个记录为支点得到的一次划分结果为（    ）　A．(38,40,46,56,79,84)  B．(40,38,46,79,56,84)　C．(40,38,46,56,79,84)  D．(40,38,46,84,56,79)', 'C');
INSERT INTO `qsbank` VALUES (82, 5, 0, 3, '在对一组关键字序列{70，55，100，15，33，65，50，40，95}，进行直接插入排序时，把65插入，需要比较(     )次。\r\nA. 3  B. 4  C. 6  D. 8', 'A');
INSERT INTO `qsbank` VALUES (83, 5, 0, 3, '从待排序的序列中选出关键字值最大的记录放到有序序列中，该排序方法称为(     )。  A. 希尔排序  B. 直接选择排序  C. 冒泡排序  D. 快速排序', 'B');
INSERT INTO `qsbank` VALUES (84, 5, 0, 3, '当待排序序列基本有序时，以下排序方法中，(   )最不利于其优势的发挥。   A. 直接选择排序   B. 快速排序  C.冒泡排序  D.直接插入排序', 'B');
INSERT INTO `qsbank` VALUES (85, 5, 0, 3, '在待排序序列局部有序时，效率最高的排序算法是(     )。 A. 直接选择排序   B. 直接插入排序   C. 快速排序  D.归并排序', 'B');
INSERT INTO `qsbank` VALUES (86, 5, 1, 1, '当待排序的元素很大时，为了交换元素的位置，移动元素要占用较多的时间，这是影响时间复杂度的主要因素。（    ）', '对');
INSERT INTO `qsbank` VALUES (87, 5, 1, 1, '内排序要求数据一定要以顺序方式存储。 （    ）', '错');
INSERT INTO `qsbank` VALUES (88, 5, 1, 1, '排序算法中的比较次数与初始元素序列的排列无关。（    ）', '错');
INSERT INTO `qsbank` VALUES (89, 5, 1, 2, '排序的稳定性是指排序算法中的比较次数保持不变，且算法能够终止。（    ）', '错');
INSERT INTO `qsbank` VALUES (90, 5, 1, 2, '在执行某个排序算法过程中，出现了排序码朝着最终排序序列位置相反方向移动，则该算法是不稳定的。（ ）', '错');
INSERT INTO `qsbank` VALUES (91, 5, 1, 2, '直接选择排序算法在最好情况下的时间复杂度为O（N）。（    ）', '错');
INSERT INTO `qsbank` VALUES (92, 5, 1, 3, '两分法插入排序所需比较次数与待排序记录的初始排列状态相关。（）', '错');
INSERT INTO `qsbank` VALUES (93, 5, 1, 3, '在初始数据表已经有序时，快速排序算法的时间复杂度为O(nlog2n )。（    ）', '错');
INSERT INTO `qsbank` VALUES (94, 5, 1, 3, '在待排数据基本有序的情况下，快速排序效果最好。（    ）', '错');
INSERT INTO `qsbank` VALUES (95, 5, 1, 3, '当待排序记录已经从小到大排序或者已经从大到小排序时，快速排序的执行时间最省。（    ）', '错');
INSERT INTO `qsbank` VALUES (96, 5, 2, 1, '试设计算法，用插入排序方法对单链表进行排序。', '参考答案:  public static void insertSort(LinkList L) {  Node p, q, r, u;  p = L.getHead().getNext();  L.getHead().setNext(null);  //置空表，然后将原链表结点逐个插入到有序表中  while (p != null) {  //当链表尚未到尾，p为工作指针 r = L.getHead();  q = L.getHead().getNext();  while (q != null && (Integer.parseInt((String) q.getData())) <= (Integer.parseInt((String) p.getData()))) ');
INSERT INTO `qsbank` VALUES (97, 5, 2, 1, '试设计算法，用选择排序方法对单链表进行排序。', '参考答案:  //单链表选择排序算法  public static void selectSort(LinkList L) {  //p为当前最小,r为此过程中最小,q为当前扫描接点  Node p, r, q;  Node newNode = new Node();  newNode.setNext(L.getHead());  L.setHead(newNode);  //制造一个最前面的节点newNode，解决第一个节点的没有前续节点需要单独语句的问题 p = L.getHead(  while (p.getNext().getNext() != null) {  r = p.getNext();');
INSERT INTO `qsbank` VALUES (98, 5, 2, 2, '试设计算法，实现双向冒泡排序(即相邻两遍向相反方向冒泡)。', '参考答案:  //产生随机数方法 public static int[] random(int n) { if (n > 0){   int table[] = new int[n];  for (int i = 0; i < n; i++)   table[i] = (int) (Math.random() * 100); //产生一个0~100之间的随机数  } return table;  }  return null; }');
INSERT INTO `qsbank` VALUES (99, 5, 2, 2, '试设计算法，使用非递归方法实现快速排序。', '参考答案:  public static void NonrecursiveQuickSort(int[] ary) {  if (ary.length < 2) {  return;  }  //数组栈：记录着高位和低位的值  int[][] stack = new int[2][ary.length];  //栈顶部位置   int top = 0;  //低位，高位，循环变量，基准点  //将数组的高位和低位位置入  stack[1][top] = ary.length - 1;  stack[0][top] = 0;   top++;  //要是栈顶不空，那么继续  while (top != 0)');
INSERT INTO `qsbank` VALUES (100, 5, 2, 3, '试设计算法，判断完全二叉树是否为大顶堆。', '参考答案:  boolean checkmax(BiTreeNode t)  //判断完全二叉树是否为大顶堆  {  BiTreeNode p = t;  if (p.getLchild() == null && p.getRchild() == null) {  return true;  } else{   if (p.getLchild() != null && p.getRchild() != null) {  if ((((RecordNode) p.getLchild().getData()).getKey()).compareTo(((RecordNode)  p.getData()).getKey()) <= 0 && (((RecordNode) p.getRchild().getData()).getKey()).compareTo(((RecordNode) p.getData()).getKey()) <= 0) {   return checkmax(p.getLchild()) && checkmax(p.getRchild());  }');
INSERT INTO `qsbank` VALUES (101, 6, 0, 1, '对线性表进行二分查找时，要求线性表必须(     )  A.以顺序方式存储  B.以顺序方式存储，且结点按关键字值有序排列  C.以链接方式存储  D.以链接方式存储，且结点按关键字值有序排列', 'B');
INSERT INTO `qsbank` VALUES (102, 6, 0, 1, '用二分查找法查找具有n个结点的顺序表时，查找每个结点的平均比较次数是(    )  A.O(n2)   B.O(nlog2n)   C.O(n)   D.O(log2n)', 'D');
INSERT INTO `qsbank` VALUES (103, 6, 0, 1, '对长度为4的顺序表进行查找，若查找第一个记录的概率为1/24, 查找第二个记录的概率为1/6, 查找第三个记录的概率为2/3, 查找第四个记录的概率为1/8,则查找任意一个记录的平均查找长度为(     )  A.23/8  B.20/8  C.17/8  D.14/8', 'A');
INSERT INTO `qsbank` VALUES (104, 6, 0, 2, '若有一个长度为64的有序表，现用二分查找方法查找某一记录，则查找不成功，最多需要比较(      )次。  A.9    B.7   C.5    D.3', 'B');
INSERT INTO `qsbank` VALUES (105, 6, 0, 2, '当采用分块查找时，数据的组织方式为(     )  A.数据必须有序  B.数据不必有序  C.数据分成若干块，每块内数据不必有序，但块间必须有序  D.数据分成若干块，每块内数据必须有序，但块间不必有序', 'C');
INSERT INTO `qsbank` VALUES (106, 6, 0, 2, '一棵深度为k的平衡二叉树，其每个非终端结点的平衡因子均为0，则该平衡二叉树共有(    )个结点。  A.2k-1-1  B.2k-1+1  C.2k-1  D.2k+1', 'C');
INSERT INTO `qsbank` VALUES (107, 6, 0, 3, '具有5层结点的平衡二叉树至少有(      )个结点。 A.10   B.12   C.15   D.17', 'B');
INSERT INTO `qsbank` VALUES (108, 6, 0, 3, '若结点的存储地址与其关键字之间存在某种映射关系，则称这种存储结构为(     )\r\n   A.顺序存储结构   B.链式存储结构   C.索引存储结构   D.散列存储结构', 'D');
INSERT INTO `qsbank` VALUES (109, 6, 0, 3, '以下有关m阶B-树的叙述中，错误的是(     )。  A.根结点至多有m棵子树    B.每个结点至少有棵子树  C.所有叶子结点都在同一层上    D.每个结点至多有m-1个关键字', 'B');
INSERT INTO `qsbank` VALUES (110, 6, 0, 3, '哈希表的地址区间为0～17，哈希函数为h(key)=K%17。采用线性探测法处理冲突，并将关键字序列{26，25，72，38，8，18,59}依次存储到哈希表中，则在哈希表中查找元素59需要搜索的次数为(     )。\r\n   A.2    B.3     C.4    D.5', 'C');
INSERT INTO `qsbank` VALUES (111, 6, 1, 1, '.二叉搜索树的任意一棵子树中，关键字最小的结点必无左孩子，关键字最大的结点必无\r\n\r\n右孩子。', '对');
INSERT INTO `qsbank` VALUES (112, 6, 1, 1, '二叉搜索树中每个结点的关键字值大于其左非空子树（若存在的话）所有结点的关键字\r\n\r\n值，且小于其右非空子树（若存在的话）所有结点的关键字值。', '对');
INSERT INTO `qsbank` VALUES (113, 6, 1, 1, '二叉搜索树按照中序遍历将各结点打印出将各结点打印出来，将得到按照由小到大的排\r\n\r\n列', '对');
INSERT INTO `qsbank` VALUES (114, 6, 1, 2, '若二叉搜索树的根结点没有左儿子，则根结点一定是值最小的结点。', '对');
INSERT INTO `qsbank` VALUES (115, 6, 1, 2, '二叉搜索树一定是满二叉树。', '错');
INSERT INTO `qsbank` VALUES (116, 6, 1, 2, '从二叉搜索树的根结点一直沿右儿子向下找不一定能找到树中值最大的结点。', '错');
INSERT INTO `qsbank` VALUES (117, 6, 1, 3, '二叉搜索树的充要条件是任一结点的值均大于其左孩子的值，小于其右孩子的值。', '错');
INSERT INTO `qsbank` VALUES (118, 6, 1, 3, '若二叉搜索树中关键码互不相同，则其中最小元素和最大元素一定是叶子结点', '错');
INSERT INTO `qsbank` VALUES (119, 6, 1, 3, '在任意一棵非空二叉搜索树中，删除某结点后又将其插入，则所得二叉搜索树与原二叉\r\n\r\n搜索树相同。', '错');
INSERT INTO `qsbank` VALUES (120, 6, 1, 3, '当向二叉搜索树中插入一个结点，则该结点一定成为叶子结点。', '对');
INSERT INTO `qsbank` VALUES (121, 6, 2, 1, '基于SeqList类，设计带监视哨的顺序查找算法，要求把监视哨设置在n号单元。', '参考答案：public int seqSearchWithGuard(Comparable key) ；  int i = length() - 1;  getRecord()[i].setKey(key);   //哨兵设置在第n号单元  i = 0;  while ((getRecord()[i].getKey()).compareTo(key) != 0) {   i++;   }   if (i < length() - 1) {   return i;   } else {  return -1;   }   }');
INSERT INTO `qsbank` VALUES (122, 6, 2, 1, '基于SeqList类，设计一个递归算法，实现二分查找。', '参考答案：public int binarySearchRecursively(int low, int high, Comparable key) { int mid, result; if (low <= high) {  mid = (low + high) / 2;  //中间位置，当前比较元素位置  result = getRecord()[mid].getKey().compareTo(key);  if (result > 0) {  return binarySearchRecursively(low, mid - 1, key);   //查找成功  } else if (result < 0) {  return binarySearchRecursively(mid + 1, high, key);  } else {  return mid; }  return -1;  //查找不成功   }');
INSERT INTO `qsbank` VALUES (123, 6, 2, 2, '基于BSTree类，设计一个算法，判断所给的二叉树是否为二叉排序树', '参考答案：public class Exercise8_3_3 extends BSTree {  boolean flag = true;  Comparable lastkey = new KeyType(0);  //判断二叉树T是否二叉排序树,是则返回true,否则返回false  boolean Is_BSTree(BiTreeNode T) {  if (T.getLchild() != null && flag) {  Is_BSTree(T.getLchild());  }  if (lastkey.compareTo(((RecordNode) T.getData()).getKey()) > 0) {flag = false;  //与其中序前驱相比较  }  ((KeyType) lastkey).setKey(((KeyType) (((RecordNode) T.getData()).getKey())).getKey());  if (T.getRchild() != null && flag)');
INSERT INTO `qsbank` VALUES (124, 6, 2, 2, '基于BSTree类，设计一个算法，输出给定二叉排序树中值最大的结点。', '参考答案：BiTreeNode maxNode(BiTreeNode T) {  if (T == null) {  System.out.println(\"这是一颗空树.\");  return null;  } else {  BiTreeNode q = T;  while (q.getRchild() != null) {  q = q.getRchild();  }  return q; } }');
INSERT INTO `qsbank` VALUES (125, 6, 2, 3, '基于BSTree类，设计一个算法，求出指定结点在给定的二叉排序树中所在的层数。', '参考答案：public class Exercise8_3_5 extends BSTree { static int level = 0;  //层数 static boolean found = false;   public static int levelOfNode(BiTreeNode p, Comparable key) {   if (p != null && !found) {  level++; if (key.compareTo(((RecordNode) p.getData()).getKey()) == 0) {  found = true;  ;  } else { levelOfNode(p.getLchild(), key);    //在左子树中查找  levelOfNode(p.getRchild(), key);    //在右子树中查找  if (!found) {  level--;   }');
INSERT INTO `qsbank` VALUES (126, 1, 0, 1, '算法的计算量的大小称为计算的（    ） A．效率   B. 复杂性  C. 现实性  D. 难度', 'B');
INSERT INTO `qsbank` VALUES (127, 1, 0, 1, '算法的时间复杂度取决于（ ）A．问题的规模 B. 待处理数据的初态  C. A和B', 'C');
INSERT INTO `qsbank` VALUES (128, 1, 0, 1, '一个算法应该是（     ）。A．程序 B．问题求解步骤的描述 C．要满足五个基本特性 D．A和C', 'B');
INSERT INTO `qsbank` VALUES (129, 1, 0, 2, '下面关于算法说法错误的是（    ）A．算法最终必须由计算机程序实现 B.为解决某问题的算法同为该问题编写的程序含义是相同的 C. 算法的可行性是指指令不能有二义性 D. 以上几个都是错误的', 'D');
INSERT INTO `qsbank` VALUES (130, 1, 0, 2, '下面说法错误的是（    ）\r\n\r\n    (1）算法原地工作的含义是指不需要任何额外的辅助空间\r\n\r\n   （2）在相同的规模n下，复杂度O(n)的算法在时间上总是优于复杂度O(2n)的算法\r\n\r\n   （3）所谓时间复杂度是指最坏情况下，估算算法执行时间的一个上界\r\n\r\n   （4）同一个算法，实现语言的级别越高，执行效率就越低 A．(1) B.(1),(2） C.(1),(4) D.(3)', 'C');
INSERT INTO `qsbank` VALUES (131, 1, 0, 2, '从逻辑上可以把数据结构分为（    ）两大类。\r\n\r\nA．动态结构、静态结构 B．顺序结构、链式结构 C．线性结构、非线性结构 D．初等结构、构造型结构', 'C');
INSERT INTO `qsbank` VALUES (132, 1, 0, 3, '以下与数据的存储结构无关的术语是（   ）。\r\n\r\nA．循环队列  B. 链表  C. 哈希表  D.  栈', 'D');
INSERT INTO `qsbank` VALUES (133, 1, 0, 3, '以下数据结构中，哪一个是线性结构（    ）\r\n\r\nA．广义表 B. 二叉树  C. 稀疏矩阵  D.  串', 'D');
INSERT INTO `qsbank` VALUES (134, 1, 0, 3, '1以下那一个术语与数据的存储结构无关？（    ）\r\n\r\nA．栈 B. 哈希表 C. 线索树  D.  双向链表', 'A');
INSERT INTO `qsbank` VALUES (135, 1, 0, 3, '在下面的程序段中，对x的赋值语句的频度为（    ）\r\n\r\nFOR i:=1  TO  n  DO\r\n\r\n    FOR j:=1  TO  n  DO  \r\n\r\n      x:=x+1;\r\n\r\nA． O(2n) B．O(n) C．O(n2) D．O(log2n)  ', 'C');
INSERT INTO `qsbank` VALUES (136, 1, 1, 1, ' 数据元素是数据的最小单位。(    )', '错');
INSERT INTO `qsbank` VALUES (137, 1, 1, 1, '记录是数据处理的最小单位。 (    ) ', '错');
INSERT INTO `qsbank` VALUES (138, 1, 1, 1, '数据的逻辑结构是指数据的各数据项之间的逻辑关系；(   )', '错');
INSERT INTO `qsbank` VALUES (139, 1, 1, 2, '算法的优劣与算法描述语言无关，但与所用计算机有关。(    )', '错');
INSERT INTO `qsbank` VALUES (140, 1, 1, 2, '健壮的算法不会因非法的输入数据而出现莫名其妙的状态。(    )', '对');
INSERT INTO `qsbank` VALUES (141, 1, 1, 2, '算法可以用不同的语言描述，如果用C 语言或PASCAL语言等高级语言来描述，则算法实际上就是程序了。(    )', '错');
INSERT INTO `qsbank` VALUES (142, 1, 1, 3, '程序一定是算法。(    )', '错');
INSERT INTO `qsbank` VALUES (143, 1, 1, 3, '数据的物理结构是指数据在计算机内的实际存储形式。(   )', '对');
INSERT INTO `qsbank` VALUES (144, 1, 1, 3, '数据结构的抽象操作的定义与具体实现有关。(    )', '错');
INSERT INTO `qsbank` VALUES (145, 1, 1, 3, '在顺序存储结构中，有时也存储数据结构中元素之间的关系。(    )', '错');
INSERT INTO `qsbank` VALUES (146, 1, 2, 1, '数据结构是一门研究什么内容的学科？', '数据结构是一门研究在非数值计算的程序设计问题中，计算机的操作对象及对象间的关系和施加于对象的操作等的学科。');
INSERT INTO `qsbank` VALUES (147, 1, 2, 1, '数据元素之间的关系在计算机中有几种表示方法？各有什么特点？', '（1）顺序存储方式。 （2）链式存储方式。（3）索引存储方式。（4）散列存储方式。');
INSERT INTO `qsbank` VALUES (148, 1, 2, 2, '数据类型和抽象数据类型是如何定义的。二者有何相同和不同之处，抽象数据类型的主要特点是什么？使用抽象数据类型的主要好处是什么？', '数据类型是程序设计语言中的一个概念，它是一个值的集合和操作的集合。如C语言中的整型、实型、字符型等。整型值的范围（对具体机器都应有整数范围），其操作有加、减、乘、除、求余等。实际上数据类型是厂家提供给用户的已实现了的数据结构。');
INSERT INTO `qsbank` VALUES (149, 1, 2, 2, '评价一个好的算法，您是从哪几方面来考虑的？', '评价好的算法有四个方面。一是算法的正确性；二是算法的易读性；三是算法的健壮性；四是算法的时空效率（运行）。');
INSERT INTO `qsbank` VALUES (150, 1, 2, 3, '根据数据元素之间的逻辑关系，一般有哪几类基本的数据结构？', '合、线性结构、树形结构、图形或网状结构。');

-- ----------------------------
-- Table structure for resbank
-- ----------------------------
DROP TABLE IF EXISTS `resbank`;
CREATE TABLE `resbank`  (
  `id` int(5) NOT NULL AUTO_INCREMENT,
  `chap` int(1) NULL DEFAULT NULL,
  `grade` int(1) NULL DEFAULT NULL,
  `type` int(1) NULL DEFAULT NULL,
  `qes` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `ans` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 136 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of resbank
-- ----------------------------
INSERT INTO `resbank` VALUES (132, 1, 3, 0, '以下与数据的存储结构无关的术语是（   ）。\r\n\r\nA．循环队列  B. 链表  C. 哈希表  D.  栈', 'D');
INSERT INTO `resbank` VALUES (133, 1, 3, 0, '以下数据结构中，哪一个是线性结构（    ）\r\n\r\nA．广义表 B. 二叉树  C. 稀疏矩阵  D.  串', 'D');
INSERT INTO `resbank` VALUES (134, 1, 3, 0, '1以下那一个术语与数据的存储结构无关？（    ）\r\n\r\nA．栈 B. 哈希表 C. 线索树  D.  双向链表', 'A');
INSERT INTO `resbank` VALUES (135, 1, 3, 0, '在下面的程序段中，对x的赋值语句的频度为（    ）\r\n\r\nFOR i:=1  TO  n  DO\r\n\r\n    FOR j:=1  TO  n  DO  \r\n\r\n      x:=x+1;\r\n\r\nA． O(2n) B．O(n) C．O(n2) D．O(log2n)  ', 'C');

-- ----------------------------
-- Table structure for student
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student`  (
  `id` int(4) NOT NULL AUTO_INCREMENT,
  `user_name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `password` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `s_num` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`, `user_name`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 18 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO `student` VALUES (1, '张全蛋', '1234', NULL);
INSERT INTO `student` VALUES (1, '马保国', '1234', NULL);
INSERT INTO `student` VALUES (2, '蔡徐坤', '1234', NULL);
INSERT INTO `student` VALUES (12, 'kepler', '1024', '20202333');
INSERT INTO `student` VALUES (14, 'helio', '1122', NULL);
INSERT INTO `student` VALUES (15, 'kk', '123', NULL);
INSERT INTO `student` VALUES (16, '高天翔', '1234', '180350116');
INSERT INTO `student` VALUES (17, '朱寿豪', '1234', NULL);

SET FOREIGN_KEY_CHECKS = 1;
