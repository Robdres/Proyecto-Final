//
//  ArrayList.hpp
//  997_Tarea02
//
//  Created by Daniel Riofrio on 22/11/20.
//

#ifndef ArrayList_hpp
#define ArrayList_hpp

#include "Exceptions.hpp"

template <class T>
class NodeD
{
private:
    T value;
    NodeD* next{nullptr};
    NodeD* prev{nullptr};
public:
    NodeD(T val):value(val){ }
    void setValue(T value){
        this->value=value;
    }
    T getValue(){
        return value;
    }
    void setNextNode(NodeD* next){
        this->next= next;
    }
    NodeD* getNextNode(){
        return next;
    }
    void setPrevNode(NodeD* prev){
        this->prev= prev;
    }
    NodeD* getPrevNode(){
        return this->prev;
    }
};

template <class T>
class ArrayList
{
private:
    unsigned int size{0};
    NodeD<T>* first{nullptr};
    NodeD<T>* last{nullptr};
public:
    void add(T val){
        NodeD<T> * node = new NodeD<T>(val);
        if(size==0){
            first = node;
            last = node;
        } else {
            node->setPrevNode(last);
            last->setNextNode(node);
            last = node;
        }
        size++;
    }
        
    unsigned int getSize(){
        return this->size;
    }
        
    void deleteAt(unsigned int index){
        if(size == 0){
            throw EmptyArrayList();
        }else{
            if(index+1 <= size){
                NodeD<T> *node = first;
                for(int i=0; i!=index; i++){
                    node = node->getNextNode();
                }
                NodeD<T> *to_replace = node;
                NodeD<T> *prev = node->getPrevNode();
                NodeD<T> *next = node->getNextNode();
                if(prev == nullptr or next == nullptr){
                    if(prev == nullptr and next != nullptr){
                        first = next;
                    }else if (next == nullptr and prev != nullptr){
                        last = prev;
                    }else{
                        first = nullptr;
                        last = nullptr;
                    }
                    delete to_replace;
                }else{
                    next->setPrevNode(prev);
                    prev->setNextNode(next);
                    delete to_replace;
                }
                size--;
            }else{
                throw IndexOutOfBounds();
            }
        }
    }
    
    void addAt(T value, unsigned int index){
        if(size == 0){
            throw IndexOutOfBounds();
        }else{
            if(index+1 <= size){
                NodeD<T> *new_node = new NodeD<T>(value);
                
                NodeD<T> *current = first;
                for(int i=0; i!=index; i++){
                    current = current->getNextNode();
                }
                NodeD<T> *prev = current->getPrevNode();
                NodeD<T> *next = current->getNextNode();
                if(prev == nullptr or next == nullptr){
                    if(prev == nullptr and next != nullptr){
                        first = new_node;
                        new_node->setNextNode(current);
                        current->setPrevNode(new_node);
                    }else if (next == nullptr and prev != nullptr){
                        new_node->setNextNode(last);
                        new_node->setPrevNode(prev);
                        prev->setNextNode(new_node);
                        current->setPrevNode(new_node);
                    }
                }else{
                    new_node->setNextNode(current);
                    new_node->setPrevNode(prev);
                    prev->setNextNode(new_node);
                    current->setPrevNode(new_node);
                }
                size++;
            }else{
                throw IndexOutOfBounds();
            }
        }
    }
    
    T operator[](unsigned int index){
        if(size == 0){
            throw EmptyArrayList();
        }else{
            if(index+1 <= size){
                NodeD<T> *node = first;
                for(int i=0; i!=index; i++){
                    node = node->getNextNode();
                }
                return node->getValue();
            }else{
                throw IndexOutOfBounds();
            }
        }
    }
        
};


#endif /* ArrayList_hpp */
