# 继承关系的内存布局分析

以下几张图，对`Test_Circle`函数做了内存布局分析，说明了子类和父类的内存布局关系，以及`operator new`的分配地址过程。

!(堆内存分配及赋值过程)[堆内存分配及赋值过程.png]
!(堆内存分配及赋值过程-2-验证new分配的地址)[堆内存分配及赋值过程-2-验证new分配的地址.png]
!(memery-layout-for-classes)[memery-layout-for-classes.png]
