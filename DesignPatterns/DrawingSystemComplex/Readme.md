# GeekBand 设计模式 第三周

## <a name="index"/> 目录

* [问题](#question)
* [题解及运行结果](#answer)
  * [代码片段示例](#code)
  * [运行结果截图](#ComplexShape.png)
  * [设计模式图解](#Composite.png)

## <a name="question"/> 问题
>  针对DrawingSystem中的基类Shape和各个子类Line、Rec、Circle，
   请使用某种模式来支持更复杂的形状，该复杂形状是各个形状的自由组合。
   使用松耦合面向对象设计方法和思想,可使用伪码表示设计。



## <a name="answer"/> 题解

### 思路
 
* 题目说，**更复杂的形状**，且该复杂形状是“各个形状的自由组合”。
* ~~各种形状的组合，就牵扯到解决“新系列”的问题~~
  * ~~而`抽象工厂模式`就是为解决“新系列”关联对象的问题而诞生的，所以此问题可以用“抽象工厂模式”来解决~~
* 之前的分析解决方法有点问题，`AbstractFactory`并**`不能`**解决“`自由组合`”的问题，因为`抽象工厂`更多的是解决`系列`创建的问题。
  而系列创建需要稳定的抽象部分，如果把本问题的`自由组合`部分放在抽象工厂中作为稳定的部分，就显得完全不合理了。
* 综上所述，还是应该采用更为合理的`组合模式`来解决`自由组合`的问题。


### 解答

* 具体代码参考源码部分，本文只给出代码片段[代码片段示例](#code)
* 运行结果[运行结果](#ComplexShape.png)截图
* 设计模式[图解](#Composite.png)


### 附录1：<a name="code"/> 代码片段示例

* 代码片段

```C++
//we can use Composite Pattern to solve this problem
void Test_Drawing()
{
    //create Shapes
    ComplexShape *complexShape = new ComplexShape("complexRoot");
    Circle *circle = new Circle("Circle");
    Rec *rect = new Rec("Rectangle");
    Line *line = new Line("Line");
    ComplexShape *complexShape2 = new ComplexShape("complexChild");
    Line *line2 = new Line("Line2");

    //1. Composing Shapes in one Big "ComplexShape"
    //Big Complex Shape by three Leaf Shape
    complexShape->AddShape(circle);
    complexShape->AddShape(rect);
    complexShape->AddShape(line);
    
    //2. Sub Complex Shape composted by One Leaf Shape
    complexShape2->AddShape(line2);
    //Big Complex Shape include one Complex Shape.
    complexShape->AddShape(complexShape2);

    //3. You can remove one shape from ComplexShape
    complexShape->RemoveShape(rect);


    complexShape->Drawing();

    if (complexShape) {
        delete complexShape;
    }
}

```

### 附录2：<a name="ComplexShape.png">运行结果

>1. 组合全部图形及组合图形的复杂图形

![运行结果](ComplexShape.png)

>2. 去掉ComplexShape中的一个Rec实例的复杂图形

```C++
//注意这段删除方法
//You can remove one shape from ComplexShape
complexShape->RemoveShape(rect);

```
![运行结果2](ComplexShape2.png)

### 附录3：<a name="Composite.png"/> 组合模式图解 

* 参考链接: [维基百科](https://en.wikipedia.org/wiki/Composite_pattern)

![工厂方法](Composite.png)


