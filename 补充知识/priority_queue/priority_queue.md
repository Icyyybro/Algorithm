# priority\_queue

# 1. 用途

`priority_queue` 是一种用于维护一个优先级队列的 STL 容器。根据比较函数的不同可以模拟大顶堆和小顶堆。

# 2. 参数

第一个参数为元素类型，例如：pair\<int, int>

第二个参数表示底层数据结构使用什么来存储元素，例如：vector\<pair\<int, int>>

第三个参数是自定义的比较器，用来决定排序规则，例如：

```c++
//小顶堆
    class mycomparison {
    public:
        bool operator()(pair<int, int> lhs, pair<int, int> rhs) {
            return lhs.second < rhs.second;
        }
    };
```

这里的mycomparison重写了operator函数，使类的实例可以像函数一样被调用，例如：

```c++
mycomparison cmp;
std::pair<int, int> p1 = {1, 2}, p2 = {2, 3};
bool result = cmp(p1, p2); // 调用 operator() 方法

```

通常情况下，我们自定义一个类，并重写operator方法，将这个自定义类作为priority\_queue的第三个参数。
