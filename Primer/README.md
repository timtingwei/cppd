<<C++ Primer>> 第五版中文版答案
----
## 说明
// 在第九章之前的学习方法是对着书中代码敲， 章节内容和练习都是一样对待，有时更偏重章节一些。

// 但这样自己思考的比较少，学习效率不高, 因此该用main.cpp作为章节知识的test, 头文件来实现练习, 更注重练习的思考和实现, 减少进入细节漩涡的可能, 反馈也好一些。

## 目录
* ch1 开始
* ch2 变量和基本类型
* ch3 字符串, 向量, 数组
* ch4 表达式
* ch5 语句
* ch6 函数
* ch7 [类](https://github.com/timtingwei/cppd/tree/master/Primer/7_class)
* ch8 IO库
* ch9 [顺序容器](https://github.com/timtingwei/cppd/tree/master/Primer/9_seq_containers)
* ch10 泛型算法
* ch11 关联容器
* ch12 动态内存
* ch13 拷贝控制
* ch14 操作重载和类型转换
* ch15 [面向对象程序设计](https://github.com/timtingwei/cppd/tree/master/Primer/15_oop)
* ch16 模版与泛型编程


## 样式
> 每一章节需要记录的类型分成三种
* 1, 章节正文中, 自己搞不懂的代码  -> chapter_n / main.cpp
* 2, 练习中需要实现代码的题       -> chapter_n / CP5_exn(章节序号)_00(练习序号).h
* 3, 练习中的简答, 思考题        -> cpater_n / README.md


1中main.cpp, 不必要add  [示例 - 1](https://github.com/timtingwei/cppd/blob/master/Primer/9_seq_containers/main.cpp) <br>
2中的代码实现头文件, 在main.cpp中编译测试, 通过后再 git add CP5_ex9_24.h && git commit -m ".." [示例 - 2](https://github.com/timtingwei/cppd/blob/master/Primer/9_seq_containers/CP5_ex9_26.h)<br>
3中每次进行修改可add, commit一次 [示例 - 3](https://github.com/timtingwei/cppd/blob/master/Primer/9_seq_containers/README.md)<br>


> 另外, 以下是我cpp文件的签名
```cpp
/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com
   ------------------------------
   File:main.cpp
   Date:Wed Jun 20 02:03:46 CST 2018
   -----------------------------
*/
```

> 欢迎request!
