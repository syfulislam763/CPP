#include <iostream>


//Circular Queue
template<class t> class CircularQueue{
    private:
        long long int length = 0;
        long long int front = -1;
        long long int rear = -1;
        t *queue = NULL;
    public:
        CircularQueue(long long int len){
            this->length = len;
            this->queue = new (std::nothrow) t[len];
            if(!this->queue){
                std::cout << "Failed to allocate memory\n";
            }
        }
        ~CircularQueue(){
            delete[] this->queue;
        }
        void enqueue(t data){
            if(this->isFull()){
                std::cout << "Queue is full\n";
                return;
            }
            if((this->rear+1 < this->length) && !this->queue[this->rear+1]){
                this->queue[++this->rear] = data;
            }else if((this->rear+1 >= this->length) && !this->queue[this->rear+1]){
                this->rear = -1;
                this->queue[++this->rear] = data;
            }
        }
        bool isEmpty(){
            if((this->rear == -1 && this->front == -1) || 
                (this->rear == this->front && !this->queue[this->rear] && !this->queue[this->front])
            ){
                return 1;
            }else{
                return 0;
            }
        };
        bool isFull(){
            if((this->rear != -1 && this->front != -1) && this->rear == this->front && (this->queue[this->front] && this->queue[this->rear]) || (this->front == -1 && this->rear >= this->length-1)){
                return 1;
            }else{
                return 0;
            }
        };
        t dequeue(){
            t temp = '\0';
            if(this->isEmpty()){
                std::cout << "Queue is empty\n";
                return temp;
            }
            if(this->front+1 < this->length){
                temp = this->queue[++this->front];
                this->queue[this->front] = '\0';
                return temp;
            }else{
                this->front = -1;
                if(this->front < this->rear){
                    temp = this->queue[++this->front];
                    this->queue[this->front] = '\0';
                    return temp;
                }
            }
            return temp;
        }
        void display(){
            if(this->isEmpty()){
                std::cout << "There is nothing to display\n";
                return;
            }
            if(this->front < this->rear){
                for(int i = this->front+1; i <= this->rear; i++){
                    std::cout << this->queue[i] << " ";
                }
                std::cout << "\n";
            }else{
                int i = this->front+1;
                for(; i < this->length; i++){
                    std::cout << this->queue[i] << " ";
                }
                i = -1;
                for(; i < this->rear; i++){
                    std::cout << this->queue[i+1] << " ";
                }
                
                std::cout << std::endl;
            }
        }
        
        
};

int main(){

    CircularQueue<int> container(5);
    container.enqueue(5*1);
    container.enqueue(5*2);
    container.enqueue(5*3);
    container.enqueue(5*4);
    container.enqueue(5*5);
    //container.enqueue(5*6);
    // container.dequeue();
    // container.enqueue(5*6);
    // container.dequeue();
    // container.enqueue(5*7);
    // container.dequeue();
    // container.dequeue();
    // container.dequeue();
    // container.dequeue();
    // container.dequeue();


    container.display();
    

    return 0;
}