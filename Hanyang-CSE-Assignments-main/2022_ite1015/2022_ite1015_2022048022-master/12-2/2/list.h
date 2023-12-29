#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

template <class T>
class Node
{
    public:
        T data;
        Node<T>* next;
};

template<class T>
class List{
private:
    Node<T> *head;
public:
    List() : head(NULL) {}
    ~List(){
        Node<T>* cur = head;
        while(cur != NULL){
            Node<T>* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
    List(T* arr, int n_nodes){
        head = new Node<T>;
        head->data = arr[0];
        head->next = NULL;

        Node<T>* n = head;
        for(int i=1; i<n_nodes; i++){
            Node<T> *nn = new Node<T>;
            nn->data = arr[i];
            nn->next = NULL;
            n->next = nn;
            n = n->next;
        }
    }
    void insert_at(int idx, const T& data){
        Node<T>*cur = head;
        Node<T>*tmp;
        int cursor = 0;
        while(cursor<idx){
            cursor++;
            tmp = cur;
            cur = cur->next;
        }
        Node<T>* ins = new Node<T>;
        ins->data = data;
        if(cur == head){
            ins->next = cur;
            head = ins;
        }
        else{
            tmp->next = ins;
            ins->next=cur;
        }
    }
    void remove_at(int idx){
        Node<T>*cur = head;
        Node<T>*tmp;
        int cursor = 0;
        while(cursor<idx){
            cursor++;
            tmp = cur;
            cur = cur->next;
        }
        if(cur == head){
            head = cur->next;
            delete cur;
        }
        else{
            tmp->next = cur->next;
            delete cur;
        }
    }
    void pop_back(){
        Node<T>*cur = head;
        Node<T>*tmp;
        while(cur->next != NULL){
            tmp = cur;
            cur = cur->next;
        }
        if(cur == head){
            delete cur;
            head = NULL;
        }
        else{
            delete cur;
            tmp->next = NULL;
        }
    }
    void push_back(const T& val){
        Node<T>* nn = new Node<T>;
        nn->data = val;
        nn->next = NULL;

        if(head==NULL){
            head = nn;
            return;
        }

        Node<T>*cur = head;
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = nn;
    }
    void pop_front(){
        Node<T>* cur = head;
        Node<T>* newhead = head->next;
        if(newhead!=NULL){
            delete cur;
            head = newhead;
        }
        else{
            delete cur;
            head = NULL;
        }
    }
    void push_front(const T& val){
        Node<T>* nn = new Node<T>;
        nn->data = val;
        nn->next = head;

        head = nn;
    }
    size_t size(){
        size_t cnt = 0;
        Node<T>* cur = head;
        while(cur!=NULL){
            cur = cur->next;
            cnt++;
        }
        return cnt;
    }
    T getdata(int idx){
        int cursor = 0;
        Node<T>* cur = head;
        while(cursor<idx){
            cur = cur->next;
            cursor++;
        }
        return cur->data;
    }
    friend ostream& operator<<(ostream& out, List& rhs){
        Node<T>*cur = rhs.head;
        while(cur != NULL){
            if(cur->next != NULL) out << cur->data << ',';
            else out << cur->data;
            cur = cur->next;
        }
        return out;
    }
};


