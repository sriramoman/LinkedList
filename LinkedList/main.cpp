//
//  main.cpp
//  LinkedList
//
//  Created by Sriram Vellangallor Subramanian on 1/17/16.
//  Copyright © 2016 Sriram Vellangallor Subramanian. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace::std;

class LinkedListModel{
public:
    LinkedListModel* nextNode;
    char* data;
//TODO: Migrate from char* to std::string
    virtual int size()=0;
    virtual void insert(char* data,int position)=0;
    virtual void insert(char* data)=0;
    virtual void display(int position)=0;
    virtual void display()=0;
};

class DoublyLinkedListModel:public LinkedListModel{
public:
    LinkedListModel* prevNode;
};

class singlylist:protected LinkedListModel{
    private:
    LinkedListModel* head;
    LinkedListModel* tail;
    int count;
    public:
    singlylist(){
        head=NULL;
        count=0;
    }
    int size(){
        return count;
    }
    void insert(char* data,int position){
        if (head==NULL && position==0) {
            LinkedListModel* newNode = (LinkedListModel*)malloc(sizeof(LinkedListModel));
            newNode->data=strdup(data);
            head=tail=newNode;
            tail->nextNode=NULL;
            ++count;
            return;
        }
        if (position>count) {
            cout<<"Insertion not possible"<<endl;
            return;
        }
        else if (position==count){
            //Save time in iterating
            LinkedListModel* newNode = (LinkedListModel*)malloc(sizeof(LinkedListModel));
            newNode->data=strdup(data);
            tail->nextNode=newNode;
            tail=newNode;
            tail->nextNode=NULL;
            ++count;
        }
        else{
            LinkedListModel* newNode = (LinkedListModel*)malloc(sizeof(LinkedListModel));
            newNode->data=strdup(data);
            if (position==0) {
                newNode->nextNode=head;
                head=newNode;
                return;
            }
            else {
                LinkedListModel* iter=head;
                for (int i=0; i<position; i++) {
                    iter=iter->nextNode;
                }
                LinkedListModel* tmp=iter;
                iter->nextNode=newNode;
                newNode->nextNode=tmp->nextNode;
            }
        }
    }
    void insert(char* data){
        this->insert(data, 0);
    }
    void display(int position){
        if (position>count) {
            cout<<"error: Out of bounds"<<endl;
            return;
        }
        int iter=0;LinkedListModel *lIter=this->head;
        while (iter<position) {
            lIter=lIter->nextNode;
            iter++;
        }
        cout<<lIter->data<<endl;
        lIter=NULL;
    }
    void display(){
        for (LinkedListModel *lIter=this->head; lIter!=NULL; lIter=lIter->nextNode) {
            cout<<lIter->data<<(lIter->nextNode!=NULL?",":"\n");
        }
    }
};

/*
class doublylist:protected DoublyLinkedListModel{
private:
    LinkedListModel* head;
    LinkedListModel* tail;
    int count;
public:
    doublylist(){
        head=NULL;
        count=0;
    }
    int size(){
        return count;
    }
    void insert(string data,int position){
        if (head==NULL && position==0) {
            DoublyLinkedListModel* newNode = (DoublyLinkedListModel*)malloc(sizeof(DoublyLinkedListModel));
            newNode->data=data;
            head=tail=newNode;
            tail->nextNode=NULL;
            ++count;
            return;
        }
        if (position>count) {
            cout<<"Insertion not possible"<<endl;
            return;
        }
        else if (position==count){
            //Save time in iterating
            DoublyLinkedListModel* newNode = (DoublyLinkedListModel*)malloc(sizeof(DoublyLinkedListModel));
            newNode->data=data;
            tail->nextNode=newNode;
            tail=newNode;
            tail->nextNode=NULL;
            ++count;
        }
        else{
            DoublyLinkedListModel* newNode = (DoublyLinkedListModel*)malloc(sizeof(DoublyLinkedListModel));
            newNode->data=data;
            if (position==0) {
                newNode->nextNode=head;
                head=newNode;
                return;
            }
            else {
                LinkedListModel* iter=head;
                for (int i=0; i<position; i++) {
                    iter=iter->nextNode;
                }
                LinkedListModel* tmp=iter;
                iter->nextNode=newNode;
                newNode->nextNode=tmp->nextNode;
            }
        }
    }
    void insert(string data){
        this->insert(data, 0);
    }
    void display(int position){
        if (position>count) {
            cout<<"error: Out of bounds"<<endl;
            return;
        }
        int iter=0;LinkedListModel *lIter=this->head;
        while (iter<position) {
            lIter=lIter->nextNode;
            iter++;
        }
        cout<<lIter->data<<endl;
        lIter=NULL;
    }
    void display(){
        for (LinkedListModel *lIter=this->head; lIter!=NULL; lIter=lIter->nextNode) {
            cout<<lIter->data<<(lIter->nextNode!=NULL?",":"\n");
        }
    }
};
*/

int main(int argc, const char * argv[]) {
    // insert code here...
    singlylist objSinglyList;
    objSinglyList.insert((char*)"World");
    objSinglyList.insert((char*)"Hello");
    objSinglyList.insert((char*)"Sriram", objSinglyList.size());
    objSinglyList.display(0);
    objSinglyList.display(1);
    objSinglyList.display(2);
    objSinglyList.display(3);
    objSinglyList.display();
    return 0;
}
