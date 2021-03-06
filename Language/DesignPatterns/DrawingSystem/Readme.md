# 设计模式第二周

## <a name="index"/> 目录

* [问题](#question)
* [题解及运行结果](#answer)

## <a name="question"/> 问题
>  针对`DrawingSystem`中的基类`Shape`和各个子类`Line`、`Rec`、`Circle`。
为支持更多的形状子类，请使用某种模式来支持灵活地创建它们。
使用松耦合面向对象设计方法和思想,可使用伪码表示设计。
(使用当周的设计模式,并且只使用1种设计模式)



## <a name="answer"/> 题解

### 思路
 
* 题目说，为支持更多的**形状子类**，注意到是子类，且都属于形状，那么可以确定的说，我们解决的是单一类型的需求变化。
* 根据“单一需求变化”的目标，我们可以发现，**工厂模式**即可解决该问题

### 解答

* 具体代码参考源码部分
* 设计模式[图解](#factorypng)

附录：<a name="factorypng"/> 工厂方法图解 

![工厂方法](factory.png)


