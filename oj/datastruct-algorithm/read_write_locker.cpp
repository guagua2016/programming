#include <condition_variable>
#include <mutex>

class rw_lock {
private:
    std::mutex mtx;
    std::condition_variable cv1; //block by a writer
    std::condition_variable cv2; //block by a reader
    int waiteForWrite;
    int waiteForRead;
    int reading;
    enum {
        RLOCK, WLOCK, NOLOCK
    };
    int state;
public:
    //first write.
    void r_lock() {
        std::unique_lock<std::mutex> lck(mtx);
        while (state == WLOCK || waiteForWrite != 0) {
            waiteForRead++;
            cv1.wait(lck);
        }
        reading++;
        state = RLOCK;
    }

    void r_unlock() {
        std::unique_lock<std::mutex> lck(mtx);
        reading--;
        if (reading == 0) {
            state = NOLOCK;
            cv2.notify_all();
        }
    }

    //request write lock
    void w_lock() {
        std::unique_lock<std::mutex> lck(mtx);
        while (state == RLOCK || state == WLOCK) {
            waiteForWrite++;
            cv2.wait(lck);
        }
        state = WLOCK;
    }

    void w_unlock() {
        std::unique_lock<std::mutex> lck(mtx);
        state = NOLOCK;
        cv1.notify_all();
    }

};