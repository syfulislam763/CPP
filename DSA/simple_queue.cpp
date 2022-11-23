#include <iostream>


//Linear queue
template<class t> class Queue {
    private:
        long long int length = 0;
        t *queue = NULL;
        long long int front = 0;
        long long int rear = -1;
    public:
        Queue(long long int len){
            this->length = len;
            this->queue = new (std::nothrow) t[len];
            if(!(this->queue)){
                std::cout << "Memory is failed to allocate\n";
            }
        };
        ~Queue(){
            delete[] this->queue;
        };

        void enqueue(t data){
            if(this->isFull()){
                std::cout << "Queue is full\n";
                return;
            }
            this->queue[++this->rear] = data;
        }

        t dequeue(){
            if(this->isEmpty()){
                std::cout << "Queue is empty\n";
                return '\0';
            }
            t temp = this->queue[this->front];
            this->queue[this->front] = '\0';
            this->front++;

            return temp;
        }

        void display(){
            if(this->isEmpty()){
                std::cout << "There is nothing to display\n";
                return;
            }
            for(int i = this->front; i <= this->rear; i++){
                std::cout << this->queue[i] << " ";
            }
            
            std::cout << "\n";
        }
        bool isEmpty(){
            if(this->front <= 0 && this->rear < 0){
                return 1;
            }else if(this->front > this->rear){
                return 1;
            }else{
                return 0;
            }
        }
        bool isFull(){
            if(this->rear+1 > this->length-1){
                return 1;
            }else{
                return 0;
            }
        }
        void test(){
            for(int i = 0; i < this->length; i++){
                std::cout << this->queue[i] << " ";
            }
            std::cout << "\n";
        }
};


int main(){

    Queue<int> container(3);

    container.enqueue(5);
    container.enqueue(10);
    container.enqueue(15);
    container.dequeue();
    container.dequeue();
    container.dequeue();
    container.dequeue();
    container.enqueue(100);
    container.display();
    // container.dequeue();
    // int a = container.dequeue();
    // container.display();
    // container.test();

    return 0;
}