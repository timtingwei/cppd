# ex1_06
> 解释下面程序片段是否合法
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