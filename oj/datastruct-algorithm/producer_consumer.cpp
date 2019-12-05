/* Hello World program */

#include <iostream>

#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <functional>

//几个要求
//1、多线程生产者、多线程消费者
//2、当队列超过>100时，生产者停止生产，队列<20，消费者停止消费
//3、适当加一些print来验证你的程序，不然整个程序跑起来，你是不知道程序是什么情况的


std::queue<int> q;
std::mutex m;
std::condition_variable cv1; //for 100;
std::condition_variable cv2; //for 20;

void produce(int x){
    std::unique_lock<std::mutex> lck(m);
    
    //cycle check.
    while(q.size()>100){
        cv1.wait(lck);
    }
    q.push(x);
    std::cout << "produce:" << x << std::endl;
    if(q.size()>=20) cv2.notify_all();
}

void consume(){
    std::unique_lock<std::mutex> lck(m);
    while(q.size()<20) cv2.wait(lck);

    std::cout << "consume:" << q.front() << std::endl;
    q.pop();
    if(q.size()<100) cv1.notify_all();
}


int main()
{
    std::thread producers[200];
    for(int i=0;i<200;i++){
        producers[i]=std::thread(produce,i);
    }

    std::thread consumers[200];
    for(int i=0;i<200;i++){
        consumers[i] = std::thread(consume);
    }

    for(auto& p : producers){
        p.join();
    }
    for(auto& c : consumers){
        c.join();
    }

    //std::cout << "Hello World!";
    return 0;
}