
## golang
1. golang中的new和make区别？
2. golang中的defer？调用时机？调用顺序？预计算值？
3. golang中的匿名函数？闭包？闭包延时绑定问题？用闭包写fibonacci数列？
4. golang中的GMP调度？
5. golang中的内存管理？对比C++中的内存管理？堆、栈和逃逸分析？多级内存管理？垃圾回收？

2. go怎么做goroutine之间的同步？channel、sync.mutex、sync.WaitGroup、context，锁怎么实现，用了什么cpu指令?
3. 协程交替执行,使其能顺序输出1-20的自然数
4. 生产者消费者模式多个生产者多个消费者
5. 如何优雅的关闭channel？https://www.jianshu.com/p/d24dfbb33781
6. channel关闭后读操作会发生什么？写操作会发生什么？
7. golang中的main函数和init函数？
8. golang中的错误处理方式？error，nil，panic，recover？
9. golang http 连接复用是怎么回事？resp.Body.Close()
10. golang defer？
11. golang map 和 sync.map?
12. reflect.DeepEqual()
13. golang 单元测试，mock，性能分析？
14. golang 接口对象断言？
15. golang 内存管理和垃圾回收？？
16. golang goroutine 调度？
17. golang mysql？
18. golang kafka?
19. golang 中的指针和unsafe包？
20. golang 中reflect的理解？
21. golang sync.pool和连接池


## C++

## 计算机基础

## 数据库/Kafka/Cache
1. golang 与 mysql

## 网络
1. TCP keepalive 和 http keep-alive 是怎么回事？ 心跳，连接复用

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

---
title: 计算机基础之golang知识
categories:
- Golang
---


## 一、计算机基础
1. 大文件排序？内存不够的情况下，使用归并排序
2. 网络编程中的http keep-alive，tcp keepalive 和 TIME_WAIT是怎么回事？Time_WAIT有什么作用？
	- https://www.cnblogs.com/yjf512/p/5354055.html
	- http://www.nowamagic.net/academy/detail/23350375
	- https://zhuanlan.zhihu.com/p/40013724
3. [孤儿进程和僵尸进程？](https://monkeysayhi.github.io/2018/12/05/%E6%B5%85%E8%B0%88Linux%E5%83%B5%E5%B0%B8%E8%BF%9B%E7%A8%8B%E4%B8%8E%E5%AD%A4%E5%84%BF%E8%BF%9B%E7%A8%8B/)
4. 死锁的条件


## 二、golang语言基本特性
1. make和new的区别？
2. 协程交替执行,使其能顺序输出1-20的自然数？
3. channe关闭后，读操作会怎么样？如何优雅的关闭channel？
4. golang中的main和init函数？
5. [golang中的defer、panic和recover和错误处理方式？](https://wxquare.github.io/2019/03/06/golang_error_handling/)
6. golang中的select关键字？
7. goalng中的struct可以进行比较吗？了解reflect.DeepEqual吗？
8. golang中的set实现？map[interface{}]struct{}
9. goalng中的生产者消费者模式？
10. golang中的context包的用途？
11. golang的编译过程？
12. golang闭包的概念？
13. golang中可以对只运行一次的函数定义为匿名函数，匿名函数对外部变量使用的是引用
14. 将匿名函数赋值为一个变量，该变量就称为一个闭包，为闭包对外层词法域变量是引用的。
```
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

```
15. golang 逃逸分析。go在一定程度消除了堆和栈的区别，因为go在编译的时候进行逃逸分析，来决定一个对象放栈上还是放堆上，不逃逸的对象放栈上，可能逃逸的放堆上



## 三、高级主题
### 2.1. golang中的协程调度？
 
### 2.2. golang中的context包？
https://juejin.im/post/5a6873fef265da3e317e55b6  
https://www.flysnow.org/2017/05/12/go-in-action-go-context.html  

### 2.3 主协程如何等待其余协程完再操作？协程同步的三种方式？

### 2.4.golang网络编程点点滴滴？
	https://colobu.com/2014/12/02/go-socket-programming-TCP/
#### 2.4.1 client如何实现长连接？


---
title: golang 标准库学习
categories:
- Golang
---


[https://books.studygolang.com/The-Golang-Standard-Library-by-Example/chapter06/06.2.html](https://books.studygolang.com/The-Golang-Standard-Library-by-Example/chapter06/06.2.html)


[golang文件读写三种方式——bufio，ioutil和os.create](https://www.cnblogs.com/bonelee/p/6893398.html)



[https://golangcaff.com/articles/110/two-schemes-for-reading-golang-super-large-files](https://golangcaff.com/articles/110/two-schemes-for-reading-golang-super-large-files)


https://zhuanlan.zhihu.com/p/27050761（golang面试题）
[golang中的runtime包教程](golang中的runtime包教程)

[在腾讯的八年，我的职业思考](https://baijiahao.baidu.com/s?id=1607037562668810273&wfr=spider&for=pc)



1.os包、io、io/ioutil、bufio、path
https://my.oschina.net/solate/blog/719702 文件操作概览
https://my.oschina.net/xinxingegeya/blog/724490 文件读 
https://my.oschina.net/xinxingegeya/blog/725105 文件写
文件操作
目录操作
path操作
IO缓冲
[[译]Go文件操作大全](https://colobu.com/2016/10/12/go-file-operations/)

2.path、path/filepath  
filepath包的功能和path包类似，但是对于不同操作系统提供了更好的支持。filepath包能够自动的根据不同的操作系统文件路径进行转换，所以如果你有跨平台的需求，你需要使用filepath。

    package main
    
    import (
    	"fmt"
    	"path"
    	// "path/filepath"
    )
    
    func main() {
    	fmt.Println(path.Ext("/a/b/c/bar.css"))
    	fmt.Println(path.Base("/a/b/c/"))
    	fmt.Println(path.Dir("/a/b/c"))
    	fmt.Println(path.Clean("/a/b/.."))
    	fmt.Println(path.Join("a/b", "c"))
    	fmt.Println(path.Match("a*/b", "a/c/b"))
    	fmt.Println(path.Split("static/myfile.css"))
    }


3.time包学习 日期和时间  
[https://juejin.im/post/5ae32a8651882567105f7dd3](https://juejin.im/post/5ae32a8651882567105f7dd3)  
- 2006-01-02 15:04:05  
- 获取时间点、格式化为某种格式  
- 时间转为为字符串  
- 字符串转为时间类型
- 时间类型转时间戳
- 时间段Duration,3*time.Second,time.Hour
- Ticker类型和Timer类型

    package main
    
    import (
    	"fmt"
    	"sync"
    	"time"
    )
    
    func main() {
    	fmt.Println(time.Now())
    
    	//strimg to time
    	t, err := time.Parse("2006-01-02 15:04:05", "2018-04-23 12:24:51")
    	if err == nil {
    		fmt.Println(t)
    	}
    
    	t, err = time.ParseInLocation("2006-01-02 15:04:05", "2018-04-23 12:24:51", time.Local)
    	if err == nil {
    		fmt.Println(t)
    	}
    
    	//get time and conver to string
    	fmt.Println(time.Now().Format("2006-01-02 15:04:05"))
    
    	//time type to unix stamp
    	fmt.Println(t.Unix())
    
    	time.Sleep(3 * time.Second)
    	time.Sleep(time.Second * 1)
    	time.Sleep(time.Duration(1) * time.Second)
    	// time.Sleep(1 * time.Hour)
    
    	tp, err := time.ParseDuration("1.5s")
    	if err == nil {
    		fmt.Println(tp)
    	}
    
    	//compare time
    	fmt.Println(time.Now().After(t))
    
    	var wg sync.WaitGroup
    	wg.Add(2)
    	//NewTimer 创建一个 Timer，它会在最少过去时间段 d 后到期，向其自身的 C 字段发送当时的时间
    	timer1 := time.NewTimer(2 * time.Second)
    
    	//NewTicker 返回一个新的 Ticker，该 Ticker 包含一个通道字段，并会每隔时间段 d 就向该通道发送当时的时间。它会调
    	//整时间间隔或者丢弃 tick 信息以适应反应慢的接收者。如果d <= 0会触发panic。关闭该 Ticker 可
    	//以释放相关资源。
    	ticker1 := time.NewTicker(2 * time.Second)
    
    	go func(t *time.Ticker) {
    		defer wg.Done()
    		for {
    			<-t.C
    			fmt.Println("get ticker1", time.Now().Format("2006-01-02 15:04:05"))
    		}
    	}(ticker1)
    
    	go func(t *time.Timer) {
    		defer wg.Done()
    		for {
    			<-t.C
    			fmt.Println("get timer", time.Now().Format("2006-01-02 15:04:05"))
    			//Reset 使 t 重新开始计时，（本方法返回后再）等待时间段 d 过去后到期。如果调用时t
    			//还在等待中会返回真；如果 t已经到期或者被停止了会返回假。
    			t.Reset(2 * time.Second)
    		}
    	}(timer1)
    
    	wg.Wait()
    }



4.unsafe包学习 

 
golang指针学习
https://studygolang.com/articles/10953

https://www.jianshu.com/p/c394436ec9e5?utm_campaign=maleskine&utm_content=note&utm_medium=seo_notes&utm_source=recommendation  

https://juejin.im/entry/5829548bd203090054000ab6
- 普通指针  
- unsafe.Pointer (*int) 是int指针类型的一个别名 
- uintptr  
- 出于安全原因，Golang不允许以下之间的直接转换：
- 两个不同指针类型的值，例如 int64和 float64。
- 指针类型和uintptr的值。
- 但是借助unsafe.Pointer，我们可以打破Go类型和内存安全性，并使上面的转换成为可能。这怎么可能发生？让我们阅读unsafe包文档中列出的规则：
- 
- 任何类型的指针值都可以转换为unsafe.Pointer。
- unsafe.Pointer可以转换为任何类型的指针值。
- uintptr可以转换为unsafe.Pointer。
- unsafe.Pointer可以转换为uintptr



5.golang bytes












