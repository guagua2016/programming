 [Uber Go Style Guide](https://github.com/uber-go/guide) 
## 1. Goroutine如何同步？
 - channel
 - sync.WaitGroup
 - sync.Mutext,sync.RWMutext
 - 全局唯一性操作sync.Once，并发环境下的单例模式的实现
## 2. context的使用
  - https://draveness.me/golang/docs/part3-runtime/ch06-concurrency/golang-context/
  
## 3. channel的使用
 - 不带缓冲和带缓冲的channel
 - select 与 channel
 - channel的关闭
2. 空结构体struct{}
