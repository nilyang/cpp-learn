### Rectangle 类实现

打印了构造及析构过程
###
```C++
{
  //默认构造
	Rectangle r1;
	Rectangle r2(r1);
	//构造，拷贝构造
	std::cout << "r1 : "<<r1 << "\nr2: " << r2;

	//构造赋值
	Rectangle r3(400, 300, 500, 300);
	r1 = r3;
	std::cout << "r1:" << r1 << "\nr3: " << r3;

	//堆内存分配，拷贝构造
	Rectangle *pr4 = new Rectangle(r3);
	std::cout << "pr4: " << pr4 << "\nr4: " << *pr4;

	delete pr4;
	std::cout << "destructed pr4:" << pr4 << "\n";
}
```
下面的图，可以清楚看到构造及析构过程，delete释放堆空间之后，pr4指向不明地址，不可以*pr4操作，只能打印地址看看:P。
![附带执行结果图片截图](http://1taomi.oss-cn-hangzhou.aliyuncs.com/tech-blog/Rectangle2.png)
