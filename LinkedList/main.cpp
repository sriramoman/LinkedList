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
    string data;
//TODO: Make this Abstract class:
//    virtual int size()=0;
//    void insert(string data,int position);
//    void insert(string data);
//    void display(int position);
//    void display();
};

class DoublyLinkedListModel:LinkedListModel{
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
    void insert(string data,int position){
        if (head==NULL && position==0) {
            LinkedListModel* newNode = (LinkedListModel*)malloc(sizeof(LinkedListModel));
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
            LinkedListModel* newNode = (LinkedListModel*)malloc(sizeof(LinkedListModel));
            newNode->data=data;
            tail->nextNode=newNode;
            tail=newNode;
            tail->nextNode=NULL;
            ++count;
        }
        else{
            LinkedListModel* newNode = (LinkedListModel*)malloc(sizeof(LinkedListModel));
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

class doublylist:protected DoublyLinkedListModel{
};

int main(int argc, const char * argv[]) {
    // insert code here...
    singlylist objSinglyList;
    objSinglyList.insert("World");
    objSinglyList.insert("Hello");
    objSinglyList.insert("Sriram", objSinglyList.size());
    objSinglyList.display(0);
    objSinglyList.display(1);
    objSinglyList.display(2);
    objSinglyList.display(3);
    objSinglyList.display();
    return 0;
}
