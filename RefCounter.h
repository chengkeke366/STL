//
// Created by ChengKeKe on 2022/4/17.
//
#ifndef STL_REFCOUNTER_H
#define STL_REFCOUNTER_H

#include <atomic>

class RefCounter {
public:
    enum RefCountStatus{
        kDroppedLastRef,//丢失最后一个引用
        kOtherRefsRemained,//还有其他引用
    };
    void AddRef(){
        //Add完成后，其他线程才能读
        m_ref_count.fetch_add(1, std::memory_order_relaxed);
    }
    RefCountStatus DecRef(){
        //应该确保-1完成，其他线程才能读
        m_ref_count.fetch_sub(1, std::memory_order_acq_rel)-1;
    }

private:
    std::atomic<int> m_ref_count;
};


#endif //STL_REFCOUNTER_H
