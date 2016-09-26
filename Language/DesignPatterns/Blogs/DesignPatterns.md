# GeekBand C++ 设计模式 (3)   

## <a name="index"/> 目录

* [“性能”模式](#Performance)
  * [单件模式](#Singleton)
  * [享元模式](#Flyweight)
* [“状态变化”模式](#Statechanges)
  * [状态模式](#State)
  * [备忘录模式](#Memento)
* [“数据结构”模式](#DataStructures)
  * [组合模式](#Composite)
  * [迭代器模式](#Iterator)
  * [职责链模式](#Chain Of Responsibility)
* [“行为变化”模式](#Behaviorchanges)
  * [命令模式](#Command)
  * [访问者模式](#Visitor)
* [“领域规则”模式](#Domain)
  * [解析器模式](#Interpreter)  
* [总结](#summery)


## <a name="Performance"/> 性能模式

这类模式主要是为了解决对象的性能问题而生，并非组织问题，主要是 `单件模式` 和 `享元模式`

### <a name="Singleton"/> 单件模式

* 动机
  - 在软件系统中，经常有这样一些特殊类，必须保证他们在系统中只存在一个实例才能确保逻辑正确、以及良好的效率。
  - 如何绕过常规的构造器，提供一种机制来保证一个类只有一个实例?
    - 应该是设计者的职责，而不是使用者的职责
* 定义
  - 保证一个类只有一个实例，并提供一个该实例的全局访问点。


* 注意要点

 - Singleton的构造器可以设为proected，只允许派生，但不能由外部直接创建对象
 - 一般不要支持拷贝构造和Clone接口，因为多个对象违背了该模式的设计初衷
 - 注意多线程环境下的线程安全问题，以及双检查锁的问题（不能用双检查锁）
 
```C++

class Singleton{
private://禁用构造器
    Singleton();
    Singleton(const Singleton& other);
public:
    static Singleton* getInstance();
    static Singleton* m_instance;
};

Singleton* Singleton::m_instance=nullptr;

//线程非安全版本
Singleton* Singleton::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}

//线程安全版本，但锁的代价过高
Singleton* Singleton::getInstance() {
    Lock lock;
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}

//双检查锁，但由于内存读写reorder不安全
Singleton* Singleton::getInstance() {
    
    if(m_instance==nullptr){
        Lock lock;
        if (m_instance == nullptr) {
            m_instance = new Singleton();
        }
    }
    return m_instance;
}

//C++ 11版本之后的跨平台实现 (volatile)
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance() {
    Singleton* tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);//获取内存fence
    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load(std::memory_order_relaxed);
        if (tmp == nullptr) {
            tmp = new Singleton;
            std::atomic_thread_fence(std::memory_order_release);//释放内存fence
            m_instance.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}
 
 ``` 

**UML结构关系图**

```bash

    .---------------------.
    |  Singleton          |    
    |---------------------|   .-----------------------.
    |static Instance() o--+-->| return uniqueInstance |
    |SingletonOperation() |   '-----------------------'
    |GetSingletonData()   |   
    |---------------------|
    |static uniqueInstance|
    |singletonData        |
    '---------------------'

```

### <a name="Flyweight"/> 享元模式

> 享元模式主要解决的问题是

- 在软件系统中采用纯粹对象方案时，大量粒度的对象会很快充斥在系统中，从而带来很高的运行代价（消耗内存）
- 如何避免大量细粒度对象问题的同时，让外部客户程序仍然能透明地使用面向对象方式来进行操作，享元模式应运而生。

> 模式定义

- 运用共享技术，有效地支持大量细粒度的对象。

> 自己的体会

平时在工作中，虽然没有使用C++，但是常常无意识的使用到了该模式，只不过由于语言的特性，将该模式应用起来更为平坦。

例如，由于我平时使用的是PHP，PHP在数据结构上非常方便的实现`享元模式`，因为map可以通过数组来实现。平时由于不想多次创建对象，都是使用的该方法来避免。

> PHP 的版本


```PHP
//作为对比，该方法和C++的实现具有异曲同工之妙，主要简化在于MAP结构的语言级别的支持
class FontFactory
{
  private static $fontPool = [];
  static function GetFont($key='srv1')
  {
    if (!isset($fontPool[$key]) || !($fontPool[$key] instanceof Font)){
        $fontPool[$key] = new Font($key);
    }

    return $fontPool[$key];
  }
}

```

> C++ 的版本

```C++

class FontFactory{
private:
    map<string,Font* > fontPool;
    
public:
    Font* GetFont(const string& key){

        map<string,Font*>::iterator item=fontPool.find(key);
        
        if(item!=footPool.end()){
            return fontPool[key];
        }
        else{
            Font* font = new Font(key);
            fontPool[key]= font;
            return font;
        }

    }
    
    void clear(){
        //...
    }
};

```

**UML结构关系图**

![Flyweight](Flyweight.png)


## <a name="Statechanges"/> “状态变化”模式

> 在组建构建过程中，某些对象的状态经常面临变化，如何对这些变化进行有效的管理？
同时又维持高层模块的稳定？“状态变化”模式为这一问题提供了一种解决方案。

### <a name="State"/> 状态模式

* 动机
  - 在软件构建过程中，某些对象的状态如果发生改变，其行为也会随之而发生变化，比如文档处于只读状态，其支持的行为和读写状态支持的行为可能完全不同。
  - 如何在运行时根据对象的状态来透明地更改对象的行为？而不会为对象操作和状态转化之间引入耦合？
    
* 定义
  - 允许一个对象在其内部状态改变时改变它的行为。从而使对象看起来似乎修改了其行为。

> 要点

- State模式将所有与一个特定状态相关的行为都放入一个State的子类对象中，在对象状态切换时，
  切换相应的对象；但同时维持State的接口，这样实现了具体操作与状态转换之间的解耦。
- 为不同状态引入不同的对象，使得状态转换变得更加明确，而且可以保证不会出现状态不一致的情况，
  因为转换是原子性的--即要么彻底转换过来，要么不转换。
- 如果State对象没有实例变量，那么各个上下文可以共享同一个State对象，从而节省对象开销。


**UML结构关系图**

![State](State.png)


### <a name="Memento"/> 备忘录模式

* 动机
  - 在软件构建过程中，某些对象的状态在转换过程中，可能由于某种需要，要求程序能够回溯到对象之前处于某个点的状态。
    如果使用一些共有接口来让其他对象得到对象的状态，便会暴露对象的细节实现。
  - 如何实现对象状态的良好保存与恢复？但同时又不会因此而破坏对象本身的封装性。
  
* 定义
  - 在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。这样以后就可以将该对象恢复到原生保存的状态。
  
* 要点

 - 备忘录(`Memento`)存储原发器(`Originator`)对象的内部状态，在需要时恢复原发器状态。
 - 备忘录模式核心是信息隐藏，即`Originator`需要向外界隐藏信息，保持其封装性，但同时又需要将状态保持到外界。
 - 由于现代语言运行时（如：C#、Java、PHP、Ruby等）都具有相当的对象序列化支持，
   因此往往采用效率更高、又容易正确实现的序列化方案来实现Memento模式。 


**UML结构关系图**

![Memento](Memento.png)


## <a name="summery"/> 设计模式总结

### 要点：

> 管理变化，提高复用

### 两个手段

> 分解 VS. 抽象


### 八大原则

* 依赖倒置原则 (DIP)
* 开放封闭原则 (OCP)
* 单一职责原则 (SRP)
* Liskov替换原则 (LSP)
* 接口隔离原则 (ISP)
* 对象组合优于类继承
* 封装变化点
* 面向接口编程

单件模式/享元模式 解决性能问题

### 重构技法

* 静态 -> 动态
* 早绑定 -> 晚绑定
* 继承 -> 组合
* 编译时依赖 -> 运行时依赖
* 紧耦合 -> 松耦合

技法以及原则相同，互相之间往往是相通的

### 从封装变化的角度对模式分类

* 组件协作
* 对象性能
* 单一职责
* 对象创建
* 接口隔离


下列模式，在现在可能不能满足了，有点过时了，或者在语言进化的过程中
* Builder 
* Mediator 
* Memento (现代语言，序列化会更容易和不易出错，所以也过时了)
* Iterator（C++等语言，模板泛型的支持内置了）
* Chain Of Responsibility 
* Visitor （脆弱，不能轻易使用）
* Command(C++ Functor 语言级别就支持了) 
* Interpreter（OOP不适用了，有专门的解析器）

>  把模式UML图，class名改为A/B/C,方法名改为F1()/F2()/...，忘掉模式的名字

C++中，继承和组合，性能差不多（内存模型类似）
但是组合的是对象，不是对象指针，那么，还是一个紧耦合。
如果放的是组合是通过指针来关联，则可以泛化，松耦合。
通过指针指向多态对象，来拥抱变化，是松耦合基础。


### 一个目标

关注变化点和稳定点

### 什么时候不用模式

* 代码可读性很差时 (最基础的代码质量)
* 需求理解还很浅时 
* 变化没有显现时 
* 不是系统的关键依赖点 
* 项目没有复用价值时 
* 项目将要发布时 

例如，不是很常用的外包软件，没有复用价值时，就没有必要用设计模式

### 经验之谈

* 不要为了模式而模式
* 关注抽象类 & 接口
* 理清变化点和稳定点
* 审视依赖关系
* 要有Framework 和 Application 的区隔思维
* 良好的设计是演化的结果(不是一步到位)
 
### 设计模式成长之路

* “手中无剑，心中无剑”：见模式而不知
* “手中有剑，心中无剑”: 可以识别模式，作为应用开发人员使用模式
* “手中有剑，心中有剑”: 作为框架开发人员为应用设计某些模式
* “手中无剑，心中有剑”: 忘掉模式，只有原则

