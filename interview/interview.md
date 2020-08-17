
## golang
1. go的new和make区别
2. go怎么做goroutine之间的同步？channel、sync.mutex、sync.WaitGroup的锁怎么实现，用了什么cpu指令?
3. 协程交替执行,使其能顺序输出1-20的自然数
4. 生产者消费者模式多个生产者多个消费者
5. 如何优雅的关闭channel？https://www.jianshu.com/p/d24dfbb33781
6. channel关闭后读操作会发生什么？写操作会发生什么？
7. golang中的main函数和init函数？
8. golang中的错误处理方式？error，nil，panic，recover？
9. 


## C++

## 计算机基础

## 数据库/Kafka/Cache

## 网络

## 操作系统


大文件排序？内存不够的情况下，使用归并排序
网络编程中的http keep-alive，tcp keepalive 和 TIME_WAIT是怎么回事？Time_WAIT有什么作用？
https://www.cnblogs.com/yjf512/p/5354055.html
http://www.nowamagic.net/academy/detail/23350375
https://zhuanlan.zhihu.com/p/40013724
孤儿进程和僵尸进程？
死锁的条件
二、golang语言基本特性

channe关闭后，读操作会怎么样？如何优雅的关闭channel？
golang中的main和init函数？
golang中的defer、panic和recover和错误处理方式？
golang中的select关键字？
goalng中的struct可以进行比较吗？了解reflect.DeepEqual吗？
golang中的set实现？map[interface{}]struct{}
goalng中的生产者消费者模式？
golang中的context包的用途？
golang的编译过程？
golang闭包的概念？
golang中可以对只运行一次的函数定义为匿名函数，匿名函数对外部变量使用的是引用
将匿名函数赋值为一个变量，该变量就称为一个闭包，为闭包对外层词法域变量是引用的。

package main

import (
	"fmt"
)

func main() {

	x := 1
	f := func() int {
		x++
		return x
	}

	fmt.Println(f())
	fmt.Println(f())
}
golang 逃逸分析。go在一定程度消除了堆和栈的区别，因为go在编译的时候进行逃逸分析，来决定一个对象放栈上还是放堆上，不逃逸的对象放栈上，可能逃逸的放堆上

三、高级主题
2.1. golang中的协程调度？
2.2. golang中的context包？
https://juejin.im/post/5a6873fef265da3e317e55b6
https://www.flysnow.org/2017/05/12/go-in-action-go-context.html

2.3 主协程如何等待其余协程完再操作？协程同步的三种方式？
2.4.golang网络编程点点滴滴？
https://colobu.com/2014/12/02/go-socket-programming-TCP/
2.4.1 client如何实现长连接？


go的调度模型
go的锁如何实现，用了什么cpu指令
go的runtime如何实现

看过sql的连接池实现吗，没有
最近学什么新技术？c++简单网络库
二面

c++的map和go的map的区别（红黑树和hashtable）
ctx包了解吗？有什么用？
go什么情况下会发生内存泄漏？（他说ctx没有cancel的时候，这个真不知道）
怎么实现协程完美退出？
智力题：1000瓶酒中有1瓶毒酒，10只老鼠，7天后毒性才发作，第8天要卖了，怎么求那瓶毒酒？
简单dp题，n*n矩阵从左上角到右下角有多少种走法（只限往下和往右走）
HR面

瞎扯
映客直播
映客是京东开奖那段时间投的补招，他们公司用的golang也挺多，可惜也是北京，薪水比京东好一点

一面

面经丢失
二面

实习项目
用channel实现定时器？（实际上是两个协程同步）
channel的实现？不了解
go为什么高并发好？讲了go的调度模型
git回滚
看什么书，怎么学习
redis的zset用什么实现，除了跳跃表
操作系统内存管理？进程通讯，为什么共享存储区效率最高
http的状态码
tcp和udp
udp的头部
http和tcp的关系
三面

怎么看一本书？
如果团队有一个人的任务做不完，你也很忙，你会怎么做？
Ucloud
Ucloud是做服务器的，跟七牛云很像，但Ucloud主要是C++，七牛云主要是golang。一面完说通过，约二面，后面说那周深圳的总监没空，调下周，后面没消息，估计凉凉了

一面

实现一个hashmap，解决hash冲突的方法，解决hash倾斜的方法
c++的模板跟go的interface的区别
怎么理解go的interface
100亿个数选top5，小根堆
字节跳动
头条很早就笔试了，A了一道多，刚好赶上补招，给面试，拖了几周担心拖不了就面试了，面试中也有一些不会的，不过三面后加hr微信问过没过，hr说过了，第二天跟我联系，然后就担心没有部门捞（头条三面通过要有部门要才有offer），第二天就谈薪资收到offer了

一面

go代码运行结果（闭包函数）
git和svn区别，模型
唯一订单号问题，并发量高的话怎么解决
hash表设计要注意什么问题
数组和为n的数组对
最大连续子数组和
redis容灾，备份，扩容
跳跃表，为什么使用跳跃表而不使用红黑树
二面

输入url后涉及什么
tcp怎么找到哪个套接字
ipc方式，共享存储区原理
进程虚拟空间布局
进程状态转换
线程的栈在哪里分配
多个线程读，一个线程写一个int32会不会有问题，int64呢（这里面试官后来说了要看数据总线的位数，32位的话写int32没问题，int64就有问题）
判断二叉树是否为满二叉树
lru实现
一个大整数（字符串形式表示的），移动字符求比它大的数中最小的
三面

MVC优点
点赞系统设计
资源 ：
博客
legendtkl：这个大佬写的博客挺有深度，主要也是go，可以看看
基础知识CyC2018：一些面试的基础知识
书籍
高性能mysql
redis设计与实现
Linux/UNIX系统编程手册
Linux高性能服务器编程
UNIX网络编程
UNIX环境高级编程
编程之法：面试和算法心得
剑指offer
图解http（简洁易懂）
TCP/IP详解
