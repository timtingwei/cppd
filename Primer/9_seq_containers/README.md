## ex9.17

> 假设是c1和c2两个容器, 下面的比较操作有何限制（如果有的话）?

```cpp
if (c1 < c2)
```

限制:
* (a)容器类型相同, 元素类型相同
* (b)元素类型已经定义操作符 < 运算 

## ex9.21

> 如果将308中使用中使用insert返回值将元素添加到list中的循环程序改写为将元素插入到vector中, 分析循环将如何工作

```cpp
vector<string> vec;
auto iter = vec.begin();
while (cin >> word) {
  iter = vec.insert(iter, word)
}
```

cin读入word之后, 将word插入到迭代器iter指向的int之前, insert函数返回的迭代器也恰好指向这个新（首）元素。
因此, 只要读入word, 每次都插入到首元素之前的位置。

## ex9.22

> 假定iv是一个int的vector, 下面程序存在什么错误, 你将如何修改

```cpp
vector<int>::iterator iter = iv.begin();
                      mid  = iter + iv.size() / 2;
while (iter != mid) {
  if (*iter == some_val)
    iv.insert(iter, some_val * 2);
}
```

错误:
* 1, 在while循环中, 循环条件变量iter没有发生改变, 循环终止的信号没出现, 对iter++, 推进迭代器
* 2, 即使iter++后, 向一个vector, string, deque使用insert函数会让现有的指向容器元素的迭代器失效
* 3, 即使更新了迭代器, mid也不能指向原来的中央位置的元素
修改：

```cpp
vector<int>::iterator iter = iv.begin();
int org_size = iv.size(), new_ele = 0;

while (iter != iv.begin() + org_size / 2 + new_ele) {
  if (*iter == some_val) {
    iter = iv.insert(iter, some_val * 2);
	new_ele++;             // 新元素个数增加
	iter++, iter++;        // 递增两次, 指向x元素之后
  } else {
    iter++;                // 正常推进迭代器
  }
}
```

## ex9.23

> 若P309本节第一个程序, c.size()为1, val1, val2, val3和val4值分别是什么?

假设 c[0] = a;
* val  = *c.begin();   // val为a
* val2 = c.front();    // val2为a
* val3 = *(--last);    // val3为a
* val4 = c.back();     // val4为a

## ex9.25

> 若P312中删除一个范围内的程序, elem1=elem2会发生什么? 若elem2为尾后迭代器, 或者elem1, elem2都为尾后迭代器又会发生什么？

我的想法:
* 当 elem1 = elem2, erase nothing, return elem1 + 1;
*    elem2 = iv.end(), erase elem1开始到末尾, 因为elem2是尾后迭代器, 因此返回也是尾后迭代器
*    elem1 = elem2 = iv.end(), 容器没改变, 返回的也是尾后迭代器;o

实际上:
* 当 elem1 = elem2, erase nothing, return elem1;
*    elem1 = iv.begin() + 1, elem2 = iv.end(), erase elem1开始到末尾, 因为elem2是尾后迭代器, 竟然返回elem1
*    elem1 = elem2 = iv.end(), 容器没改变, 返回的也是尾后迭代器;

很明显CP5习题集里的答案错了。

`返回指向最后一个被删元素 之后的迭代器`

```cpp
vector<int> iv = {1, 2, 3};

  auto elem1 = iv.begin(), elem2 = elem1;          // 1, 2, 3   | *elem1 = 1
  auto elem1 = iv.begin() + 1, elem2 = iv.end();   // 1         | *elem1 = 2
  auto elem1 = iv.end(),   elem2 = iv.end();  // 1, 2, 3   | *elem1 -> undefined

  elem1 = iv.erase(elem1, elem2);

  for (auto it = iv.cbegin(); it != iv.cend(); it++) {
    std::cout << *it << std::endl;
  }
  std::cout << "*elem1 = " << *elem1 << std::endl;
```

## ex9.29

> 假定vec包含25个元素, 那么vec.resize(100)会做什么？ 如果接下来调用vec.resize(5)会做什么?

* vec.resize(100): 75个新元素被值初始化, 添加到vec尾部
* vec.resize(5): 95个多余元素被删除

# ex9.30

> 接受单个参数的resize版本对元素类型有什么限制？

* 单个参数, 新元素进行值初始化, 因此元素类型不能是类类型, 类类型必须提供初始值, 或者元素类型必须提供一个构造函数

# ex9.32

> P316页程序中, iter = iv.insert(iter, *iter++); 是否合法?如果不合法, 为什么?

* 当iter = iter.end()时, *(iter++)未定义, insert()返回值为插入的第一个元素的迭代器, 未定义不合法

# ex9.33

> 本章最后一个例子, 如果不将insert的结果附值给begin, 会发生什么? 写代码验证

```cpp
while (begin != v.end()) {
  ++begin;        // 为了在begin之后添加元素
  begin = v.insert(begin, 42);    // 42插入begin之前, begin指向42
  ++begin;
}
```


```
          0, 1, 2, 3
begin        ^
begin++         ^
insert()  0, 1, 42, 2, 3
begin           ^
begin++   0, 1, 42, 2, 3
                    ^
```

```cpp
while (begin != v.end()) {
  ++begin;        // 为了在begin之后添加元素
  v.insert(begin, 42);    // 42插入begin之前, begin指向42
  ++begin;
}
```

```
          0, 1, 2, 3
begin        ^
begin++         ^
insert()  0, 1, 42, 2, 3
begin               ^ 
begin++   0, 1, 42, 2, 3
                       ^
```

* 可能出现insert导致迭代器失效的情况

实际代码
```cpp
void foo_33() {
  vector<int> v{2, 4, 6, 7, 8};
  auto begin = v.begin();
  while (begin != v.end()) {
    ++begin;        // 为了在begin之后添加元素
    v.insert(begin, 42);    // 42插入begin之前, begin指向42
    ++begin;
  }

  for (auto it = v.cbegin(); it != v.cend(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}

/*
  ./a.out
  a.out(44606,0x7fffa2810380) malloc: *** error for object 0x7f8602402838: incorrect checksum for freed object - object was probably modified after being freed.
*** set a breakpoint in malloc_error_break to debug
*/
```

# ex9.34

> v是一个保存int的vector容器, 有奇数也有偶数, 分析下列代码 

```cpp
vector<int> v{2, 4, 6, 7, 8, 1, 4, 5};
auto it = v.begin();
  while (it != v.end()) {
    if (*it % 2) {  // odd
      it = v.insert(it, *it);
      // it++;
    }
    it++;
  }
```

it从容器首位开始,
* 如果it指向偶数, it迭代器递增
* 如果it是奇数, 在it迭代器之前的位置插入it指向的元素, insert后it指向新增加的it元素, while循环不会结束,
<br>
改正的话, 在if语句中, insert后 添入it++;

# ex9.35

> 解释一个vector的capacity()和size()区别

* capacity():容器中能容纳的内存空间个数; 不分配新的内存空间的前提下最多可以保存多少元素

* size(): 容器中实际的元素个数; 已经保存的元素数目

# ex9.36

> 一个容器的capacity()能小于它的size()吗

* 不能, capacity代表着分配好当前内存空间的前提下, 可以保存的元素个数, 

# ex9.37

> 为什么list或者array没有capacity()成员？

* list和array所分配的内存空间不连续? // error

* list是链表, 新元素加入用个新节点保存, 删除后该节点也被删除, 因此capacity总是等于size

* array大小固定, 内存空间被一次性分配, 不会产生变化

* 因此, 他们都不需要capacity

# ex9.39

> 解释下面一段程序做了什么?

```cpp
vector<string> svec;                           // 创建一个未定义的svec容器
svec.reserve(1024);                            // 分配将要用到的内存空间1024
while (cin >> word) {                          // 标准输入word
  svec.push_back(word);                        // 每次将word添入svec尾部
}
svec.resize(svec.size() + svec.size() / 2);    // 容器中size()扩大1/2倍, 元素值初始化为空字符串
```

# ex9.40

> 如何上题中程序读入了256个单词, 在resize之后容器的capacity是多少？如果读入word 512 1000 1028呢？

预测:

* 512,  svec.size() = 512 + 512/2 = 768, svec.capacity = 1024;

* 1000, svec.size() = 1000 + 1000/2 = 1500, svec.capacity > 1500;

* 1028, svec.size() = 1028 + 1028/2 = 1542; svec.capacity > 1542;

实际情况:

* 512,   c = 1024, s = 768;

* 1000,  c = 2048, s = 1500;

* 1028,  c = 2048, s = 1542;

# ex9.48

> 假定name和numbers的定义如325所示, numbers.find(name)返回什么?

```cpp
string numbers("0123456789"), name("r2d2");
numbers.find(name);
```

* 返回18446744073709551615, 返回一个名为string::npos的静态成员, 标准库将其类型定义为 const string::size_type类型, string::npos等于任何string最大的可能大小
