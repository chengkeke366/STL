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
        //该线程 AddRef前后的读写操作不进行限制
        m_ref_count.fetch_add(1, std::memory_order_relaxed);
    }
    RefCountStatus DecRef(){
        int refcout = m_ref_count.fetch_sub(1, std::memory_order_acq_rel)-1;
        return refcout == 0 ? RefCountStatus::kDroppedLastRef
                            :RefCountStatus::kOtherRefsRemained;
    }

private:
    std::atomic<int> m_ref_count;
};


#endif //STL_REFCOUNTER_H
