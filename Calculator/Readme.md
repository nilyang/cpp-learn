## Calculator

## <a name="index"/> 目录

* [问题列表](#question)
* [题解及运行结果](#workresult)


<a name="question"/>
### 1. 问题列表

> 假设有个计算类 Calculator ，它要处理int, long, float, 
> double等数值类型。用模板实现GetLimit()方法，获得每种类型的数值的上限LIMIT，比如int的上限是100，
> long的上限是1000，float的上限是999.99，double的上限是888.8888888等等。


```C++
 //碰到模板模板参数编译问题 VS2015 C4305，类型向下转换精度丢失的问题
 //浮点型字面值，默认是double的需要显示指定为0.1`F` 
 //e.g.
 double d = 1.0; //默认`double`，无需指明
 float  f = 1.0F;//必须指明`F`，单精度
 long   l = 100L;//默认`int`，需要指明`L`
 int    i = 100;

 //另外，如果需要指定精度输出，则需要包含<iomanip>标准库头文件，使用std::fixed来固定输出精度
 
 std::cout << std::fixed ;
 Calculator<float> CalFloat;
 std::cout << "float limit: " << std::setprecision(CalFloat.getPrecision()) 
                              << CalFloat.GetLimit() << std::endl;
 

```

<a name="workresult"/>
### 2.解题及运行结果

代码在VS2015下编译通过

![GetLimit-Result](GetLimit-Result.png)
