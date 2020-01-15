/*
    Runtime: 32 ms
    Memory Usage: 16.4 MB
*/

class MyCircularQueue {
private:
    int size, start, end;
    vector<int>q;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q.resize(k);
        size = k;
        start = end = -1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if( isFull() )
            return false;
        
        if(start == -1)
            ++start;
        ++end;
        end = end == size ? 0 : end;
        q[end] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if( isEmpty() )
            return false;
        
        if(end == start)
            end = start = -1;
        else
        {
            ++start;
            start = start == size ? 0 : start;
        }
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(start == -1)
            return -1;
        return q[start];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        // cout << "end" << end << endl;
        if(end == -1)
            return -1;
        return q[end];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(start == -1)
            return true;
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        // cout << "isFull" << endl;
        if(start == (end+1)%size)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */