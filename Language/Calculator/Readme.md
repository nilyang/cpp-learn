## Calculator

## <a name="index"/> Ŀ¼

* [�����б�](#question)
* [��⼰���н��](#workresult)


<a name="question"/>
### 1. �����б�

> �����и������� Calculator ����Ҫ����int, long, float, 
> double����ֵ���͡���ģ��ʵ��GetLimit()���������ÿ�����͵���ֵ������LIMIT������int��������100��
> long��������1000��float��������999.99��double��������888.8888888�ȵȡ�


```C++
 //����ģ��ģ������������� VS2015 C4305����������ת�����ȶ�ʧ������
 //����������ֵ��Ĭ����double����Ҫ��ʾָ��Ϊ0.1`F` 
 //e.g.
 double d = 1.0; //Ĭ��`double`������ָ��
 float  f = 1.0F;//����ָ��`F`��������
 long   l = 100L;//Ĭ��`int`����Ҫָ��`L`
 int    i = 100;

 //���⣬�����Ҫָ���������������Ҫ����<iomanip>��׼��ͷ�ļ���ʹ��std::fixed���̶��������
 
 std::cout << std::fixed ;
 Calculator<float> CalFloat;
 std::cout << "float limit: " << std::setprecision(CalFloat.getPrecision()) 
                              << CalFloat.GetLimit() << std::endl;
 

```

<a name="workresult"/>
### 2.���⼰���н��

������VS2015�±���ͨ��

![GetLimit-Result](GetLimit-Result.png)