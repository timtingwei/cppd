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

## ex9.19

`ss` .... `sss`...
