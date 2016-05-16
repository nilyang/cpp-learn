# GeekBand 设计模式 第三周

## <a name="index"/> 目录

* [问题](#question)
* [题解及运行结果](#answer)

## <a name="question"/> 问题
>  针对DrawingSystem中的基类Shape和各个子类Line、Rec、Circle，
   请使用某种模式来支持更复杂的形状，该复杂形状是各个形状的自由组合。
   使用松耦合面向对象设计方法和思想,可使用伪码表示设计。



## <a name="answer"/> 题解

### 思路
 
* 题目说，**更复杂的形状**，且该复杂形状是“各个形状的自由组合”。各种形状的组合，就牵扯到解决“新系列”的问题
* 而`抽象工厂模式`就是为解决“新系列”关联对象的问题而诞生的，所以此问题可以用“抽象工厂模式”来解决。 

### 解答

* 具体代码参考源码部分
* 设计模式[图解](#AbstractFactory.png)

### 附录：<a name="AbstractFactory.png"/> 抽象工厂方法图解 

* 参考链接: [维基百科](https://zh.wikipedia.org/zh-cn/%E6%8A%BD%E8%B1%A1%E5%B7%A5%E5%8E%82)

![工厂方法](AbstractFactory.png)


