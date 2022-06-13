struct Queue *modifyQueue(struct Queue *queue, int n, int k) {
    stack<int> s;
    for (int i = 0; i<k; i++){
        int temp = front(queue);
        dequeue(queue);
        s.push(temp);
    }
    
    while(!s.empty()){
        int temp = s.top();
        enqueue(queue, temp);
        s.pop();
    }
    
    int t = queue->size - k;
    
    while(t--){
        int val = front(q);
        dequeue(queue);
        enqueue(queue, val);
    }
    return queue;
}