# ex1_06
> 解释下面的程序片段是否合法
```
std::cout << "The sum of" << v1;
          << " and " << v2;
          << " is " << v1 + v2 << std::endl;
```

> 答: 不合法，因为分号代表单独的语句，所以5，6句左侧缺少ostream对象，应改成:
```
std::cout << "The sum of" << v1;
std::cout << " and " << v2;
std::cout << " is << v1 + v2 << std::endl;
```
>或者将分号去除:
```
std::cout << "The sum of" << v1
          << " and " << v2
          << " is " << v1 + v2 << std::endl;
```

# ex1_07
>编译如下程序
```
/*
 * 注释对/* */不能嵌套
 *"不能嵌套",几个字会被认为是源码，
 *像剩余程序一样处理
*/
int main()
{
    return 0;
}
```
>返回下列错误信息
```
xxx.cpp:3:26:error: stray '/xxx' in program
xxx.cpp:3:3: error: expected unqualified-id before string constant
xxx.cpp:3:3: error: expected constructor, destructor,or type conversion before string constant
```
# ex1_08

## 第一条
>合法，输出:
```
/*
```
## 第二条
>合法，输出:
```
*/
```
## 第三条
>不合法，因为前一对/**/把“注释掉了，所以导致后面的”没有匹配对象，可改成:
```
std::cout<</* "*/"*/";
```
## 第四条
>合法，无嵌套，输出:
```
/*
```
# ex1_12
>完成了从-100到100这一区间内所有整数的累加，sum的终值是0。

# ex1_14
>for定义与修改变量都在句头，而while定义在上文，修改在语句中。
>for相较与while更加轻便，while则适合应对复杂情况。
>两者在功能上是等价的，可以互换。

# ex1_15
## 将main的参数列表漏掉
```
int main({
```
>报错:
```
error;cannot declare '::main' to be a global variable
```
## endl后使用了冒号而非分号
```
std::cout<<"Read each file."<<std::endl:
```
>报错:
```
error:expected';'before':'token
```
## 字符串字面常量的两侧漏掉了引号
```
std::cout << Update master. << std::endl;
```
>报错:
```
error:'Update master' was not declared in this scope'
```
## 漏掉了第二个输出运算符
```
std::cout << "Write new master." std::endl;
```
>报错:
```
error: expected ';'before 'std'
```
## return语句漏掉了分号
```
return 0
```
>报错:
```
error expected ';' before '}' token
```
## 类型错误
```
int v1 = "ok";
```
>报错:
```
error:invalid conversion from 'const char*' to 'int' [-fpermissive]
```
## 声明错误
```
#include<iostream>
int main()
{
    int v1 = 0,v2 =0;
    std::cin >> v >> v2;
    cout<< v1+v2 << std::endl;
    return 0;
}
```
>1.使用了"v"而非”v1",报错:
```
'v' was not declared in this scope
```
>2.未定义cout，报错:
```
note: 'std::cout'
extern ostream cout: ///Linked to standard output
```
# ex1_17 & ex1_18
>输入 2 2 2 2 2 ，返回:
```
2 occurs 5 times
```
>输入 2 3 4 ， 返回:
```
2 occurs 1 times
3 occurs 1 times
4 occurs 1 times
```
