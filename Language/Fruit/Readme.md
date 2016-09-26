
## 题目

```C++
class Fruit{
   int no;
   double weight;
   char key;
public:
   void print() {   }
   virtual void process(){   }
};
   
class Apple: public Fruit{
   int size;
   char type;
public:
   void save() {   }
   virtual void process(){   }
};

```

### 1. 题一
> 分别给出下面的类型Fruit和Apple的类型大小（即对象size），并通过画出二者对象模型图以及你的测试来解释该size的构成原因。




### 2. 题二

> 为上述类型 Fruit和Apple 添加 构造函数与 析构函数， 并在构造函数与析构函数中打印控制台信息，观察构造和析枸调用过程。然后为Apple类重载::operator new和 ::operator delete，在控制台打印信息，并观察调用结果。
