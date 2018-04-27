#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <initializer_list>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class FList {
public:
    
    Node<T>* first;
     Node<T>* last;
      auto empty_()   -> bool
    {
        if (first)
            return false;
        return true;
    }
    auto getlength()  ->size_t
    {
        if (empty_()) return 0;
         int i = 0;
          Node<T>* working = first;
           for (;working->next!=nullptr;i++, working=working->next);
            return i+1;
    }
    auto getf() const -> Node<T>* {return this->first;};
    auto getf_v()const -> T& {
        if (this->first == nullptr) {
            throw logic_error("Exception");
        }else 
            return this->first->data;
        
    };
    auto getl_v()const -> T& {return this->first->data;};
     auto getl() const -> Node<T>* {return this->last;};
      auto setf(Node<T> * a) ->void {first = a;}
       auto setl(Node<T> * a) ->void {last = a;}
        FList(Node<T> *node_): first{ node_} {}
          FList() : first{ nullptr }, last{nullptr} {}
    ~FList() {
        for (Node<T>* temp = first; temp != nullptr; temp = temp->next) {
            delete temp;
        }
    }
    
    
};

template <typename T>

class Queue{
private:
    FList<T>* list;
public:
    
    Queue<T>() {
        list = new FList<T>;
    }
    Queue(Queue const & other) {
        list = new FList<T>;
        for (Node<T> * temp = other.list->first; temp != nullptr; temp = temp->next) {
            this->push(temp->data);
        }
    }
    Queue(std::initializer_list<T> list_){
        list = new FList<T>;
        for (auto& item : list_)
            this->push(item);
    }
    
    auto swap(Queue& q) -> void {
        Node<T>* first1 = list->first;
         Node<T>* last1 = list->last;
         list->first = q.list->first;
          list->last = q.list->last;
           q.list->first = first1;
            q.list->last = last1;
    }
    
    auto empty() -> bool{return list->empty_();}
    auto size() const -> size_t{return list->getlength();}
    auto push(T val) -> void{
        if (empty()) {
            list->first = new Node<T>{};
              list->first->next = nullptr;
               list->first->data = val;
                list->last = list->first;
        }
        else {
            list->last->next = new Node<T>;
              list->last = list->last->next;
               list->last->data = val;
                list->last->next = nullptr;
        }
    }
    auto pop() -> void{
        if (list->first == nullptr) return; //уже пуст
        if (list->first->next == nullptr){
            delete list->first;
            list->first = nullptr;
            return;
        }
        Node<T>* temp = list->first;
        list->first = list->first->next;
        delete temp;
        return;
    }
    auto front() const ->T& {
        if (list->first == nullptr) {
            throw logic_error("empty");
        }
        else
            return list->first->data;
    }
    auto back() const -> T&{
        if (list->last == nullptr) {
            throw logic_error("empty");
        }
        else
            return list->last->data;
    }
    
    friend auto operator<<(std::ostream& out, Queue<T>& q)->std::ostream&
    {
        for (Node<T> * tmp = q.list->first; tmp != nullptr; tmp = tmp->next) {
            out << tmp->data;
            if (tmp->next != nullptr) {
                out << "->";
            }
            }
            return out;
            }
            friend auto operator >> (std::istream& in, Queue<T>& q)->std::istream& {
                T push_value;
                in >> push_value;
                q.push(push_value);
                return in;
            }
            auto operator==(const Queue& q)->bool {
                if (this->size() != q.size())
                    return false;
                else {
                    Node<T>* p_this = list->first;
                    Node<T>* p = q.list->first;
                    while (!(p_this==nullptr||p==nullptr))
                    {
                        if (p->data != p_this->data)
                            return false;
                        p_this = p_this->next;
                        p = p->next;
                    }
                    return true;
                }
            }
        };
        
        
        
#endif /* Queue_hpp */
