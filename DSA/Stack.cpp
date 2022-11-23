#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//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

template<class Type, class Len> class Stack{
    private:
        Len length = 0;
        Len index = -1;
        Type *stack = NULL;
    public:
        Stack (Len size = 100) {
            this->length = size;
            this->stack = new (std::nothrow) Type[length];
            if(!(this->stack)){
                std::cout << "Failed to allocate memory!\n";
            }
        };
        ~Stack(){
            delete [] this->stack;
        }

        void push(Type data){
            if(this->isFull()){
                std::cout << "Stack overflow\n";
                return;
            }
            this->stack[++index] = data;
        }
        Type pop(){
            if(this->isEmpty()){
                std::cout << "Stack underflow\n";
                return '\0';
            }
            Type t = this->stack[this->index];
            this->stack[index] = '\0';
            this->index--;
            return t;
        };
        bool isEmpty(){
            if(this->index < 0){
                return 1;
            }else{
                return 0;
            }
        };
        bool isFull(){
            if(this->index+1 <= (this->length-1)){
                return 0;
            }else{
                return 1;
            }
        };
        Type peek(Len i){
            if(i >= 0 && i < this->length){
                return this->stack[i];
            }else{
                return '\0';
            }
        }
        Len count(){
            return this->index + 1;
        };
        void change(Type data, Len i){
            if(i>=0 && i < this->length){
                this->stack[i] = data;
                if(this->index<i && i < this->length){
                    this->index = i;
                }
            }

        };
        void display(){
            if(this->isEmpty()){
                std::cout << "Nothing to display\n";
                return;
            }
            for(int i = 0; i <= this->index ; i++){
                std::cout << this->stack[i] << " ";
            }
            std::cout << std::endl;
        };
        
};



int main(){

    // Stack<std::string, int> container(100);
    // container.push("brazil");
    // container.push("argentina");
    // container.push("france");
    // container.display();
    // std::string a = container.pop();
    // container.display();
    // std::cout << a << std::endl;

    Stack<int, int> container(10);
    container.push(10);
    container.push(20);
    container.push(30);
    container.push(30);
    container.change(50, 7);
    container.display();
    std::cout << "Value = " << container.peek(3) << std::endl;
    std::cout << "Size: " << container.count() << std::endl;
    // container.pop();
    // container.pop();
    // container.pop();
    // int a = container.pop();
    //container.display();

    //std::cout << a << std::endl;

    return 0;
}