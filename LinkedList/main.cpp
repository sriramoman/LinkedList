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

struct LinkedList{
    LinkedList* nextNode;
    string data;
};

class singlylist{
    private:
    LinkedList* head;
    LinkedList* tail;
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
            LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
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
            LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
            newNode->data=data;
            tail->nextNode=newNode;
            tail=newNode;
            tail->nextNode=NULL;
            ++count;
        }
        else{
            LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
            newNode->data=data;
            if (position==0) {
                newNode->nextNode=head;
                head=newNode;
                return;
            }
            else {
                LinkedList* iter=head;
                for (int i=0; i<position; i++) {
                    iter=iter->nextNode;
                }
                LinkedList* tmp=iter;
                iter->nextNode=newNode;
                newNode->nextNode=tmp->nextNode;
            }
        }
    }
    void display(int position){
        if (position>count) {
            cout<<"error: Out of bounds"<<endl;
            return;
        }
        int iter=0;LinkedList *lIter=this->head;
        while (iter<position) {
            lIter=lIter->nextNode;
            iter++;
        }
        cout<<lIter->data<<endl;
        lIter=NULL;
    }
    void display(){
        for (LinkedList *lIter=this->head; lIter!=NULL; lIter=lIter->nextNode) {
            cout<<lIter->data<<(lIter->nextNode!=NULL?",":"\n");
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    singlylist objSinglyList;
    objSinglyList.insert("World", 0);
    objSinglyList.insert("Hello", 0);
    objSinglyList.insert("Sriram", objSinglyList.size());
    objSinglyList.display(0);
    objSinglyList.display(1);
    objSinglyList.display(2);
    objSinglyList.display(3);
    objSinglyList.display();
    return 0;
}
