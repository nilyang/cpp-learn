## STL相关问题及笔记

## <a name="index"/> 目录

* [坑](#keng)
* [问题列表](#question)
* [题解及运行结果](#workresult)
<a name="keng"/>
### 0.坑

> 碰到模板模板参数编译问题 VS2016 C4180，原来是不能实例化为对象只能实例化为模板 
> set第二个参数只能是 MyLess<MyType> 不能是 MyLess<MyType>() ，切忌。

<a name="question"/>
### 1.问题列表：

![question-1](question-1.png)
![question-1](question-2.png)

<a name="workresult"/>
### 2.解题及运行结果

代码在VS2015下编译通过

![STL-set-ordered](STL-set-ordered.png)