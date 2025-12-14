#ifndef BUFFER_H
#define BUFFER_H

#include<atomic>
#include<vector>

template <typename T>
class Buffer {
    public:
        Buffer(size_t capacity) : buffer_(capacity), c_capacity_(capacity), head_(0), tail_(0) {}

        bool push(const T& data) {
            size_t head = head_.load(std::memory_order_relaxed);
            size_t next_head = (head + 1) % c_capacity_;

            if (next_head == tail_.load(std::memory_order_acquire)) {
                return false; // buffer is full (at capacity)
            }
            buffer_[head] = data;
            head_.store(next_head, std::memory_order_release);
            return true;
        }
        bool pop(T& data) {
            size_t tail = tail_.load(std::memory_order_relaxed);
            
            if (tail == head_.load(std::memory_order_acquire)) {
                return false; // buffer is empty
            }
            data = buffer_[tail];
            tail_.store((tail + 1) % c_capacity_, std::memory_order_release);
            return true;
        }

    private:
    std::vector<T> buffer_;
    const size_t c_capacity_;
    std::atomic<size_t> head_;
    std::atomic<size_t> tail_;
};

#endif // BUFFER_H