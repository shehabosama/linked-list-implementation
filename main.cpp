#include <iostream>
#include <inttypes.h>
using namespace std;


template<class positionType , class keyType , class dataType >
class List{

public:
    List();
    ~List();
    bool listIsEmpty();
    bool curIsEmpty();
    void advance();
    void toFirst();
    void toEnd();
    void toSpecificPosition(const positionType&);
    bool atFirst();
    bool atEnd();
    int listSize();
    void inserNode(const keyType&, const dataType&);
    void insertFirst(const keyType&, const dataType&);
    void insertAfter( const positionType& , const keyType& , const dataType&);
    void insertEnd(const keyType& , const dataType&);
    void insertBefore(const positionType& ,const keyType& , const dataType&);
    void deleteNode();
    void deleteFirst();
    void deleteEnd();
    void makeListEmpty();
    void print_list();
    void updateData(const dataType&);
    void retrieveData(dataType&) const;
    void orderInsert();
    bool search(const keyType&);
    void traverse();


private:
    class node{
public:
    keyType key;
    dataType data;
    node *next;
    };
void display(node n);
    typedef node *NodePointer;
    NodePointer head , cursor , prev;

};
template<class positionType , class keyType , class dataType>
bool List<positionType,keyType ,dataType>::curIsEmpty(){
return (cursor==NULL);
}
template<class positionType,class keyType , class dataType>
List<positionType,keyType ,dataType>::List(){
head = nullptr;
cursor = nullptr;
prev = nullptr;
}

template<class positionType,class keyType , class dataType>
List< positionType,keyType ,  dataType>::~List(){
makeListEmpty();
}
template<class positionType,class keyType , class dataType>
void List<positionType,keyType , dataType>::makeListEmpty(){
    NodePointer q = head ,next ;
    while(q !=NULL){
            next = q->next;
            delete q;
            q=next;
    }
    delete head;
    head=NULL;
}
template<class positionType, class keyType , class dataType>
void List<positionType,keyType,dataType>::toSpecificPosition(const positionType&pos){
    toFirst();
    while (!listIsEmpty()&&!curIsEmpty()) {
          //   cursor->data << " ";
             if(cursor->key == pos){
                break;
             }
        advance();
}
}

template<class positionType,class keyType , class dataType>
void List<positionType,keyType,dataType>::insertBefore(const positionType&pos ,const keyType&k , const dataType&d){
    toSpecificPosition(pos);
    if(atFirst())
        insertFirst(k,d);
        else{
        NodePointer pNew;
        pNew = new node;
        pNew->data = d;
        pNew->key = k;
        pNew->next = cursor;
        prev->next = pNew;
        }
}

template<class positionType,class keyType , class dataType>
void List<positionType,keyType,dataType>::insertAfter(const positionType&pos ,const keyType&k , const dataType&d){
    toSpecificPosition(pos);
    NodePointer pNew;
    pNew = new node;
    pNew->data = d;
    pNew->key = k;
    pNew->next =cursor->next;
    cursor->next = pNew;

}
template<class positionType,class keyType , class dataType>
void List<positionType,keyType,dataType>::insertFirst(const keyType&k , const dataType&d){
    NodePointer pNew;
    pNew = new node;
    pNew->data = d;
    pNew->key = k;
    pNew->next = head;
    head = pNew;
}
template<class positionType,class keyType , class dataType>
void List<positionType,keyType,dataType>::insertEnd(const keyType&k , const dataType&d){
 toEnd();
        NodePointer pNew;
        pNew = new node;
        pNew->key = k;
        pNew->data = d;
        pNew->next=NULL;
        cursor->next=pNew;
}
template<class positionType,class keyType , class dataType>
void List<positionType,keyType,dataType>::deleteNode(){
  deleteEnd();
}
template<class positionType,class keyType , class dataType>
void List<positionType,keyType,dataType>::deleteFirst(){
toFirst();
NodePointer pDel;
pDel =head;
head = head->next;
delete pDel;
}
template<class positionType,class keyType , class dataType>
void List<positionType,keyType,dataType>::deleteEnd(){
    toEnd();
    NodePointer pDel;
    pDel = cursor;
    cursor= prev;
    prev->next =NULL;
    delete pDel;
}
template<class positionType,class keyType , class dataType>
void List<positionType,keyType,dataType>::inserNode(const keyType&k , const dataType&d){

    if(head == NULL ){
     insertFirst(k , d);
    }else{
     insertEnd(k,d);
    }
}

template<class positionType,class keyType , class dataType>
void List<positionType, keyType ,  dataType>::toFirst(){
    cursor=head;
}
template<class positionType,class keyType , class dataType>
void List<positionType, keyType ,  dataType>::advance(){
prev=cursor;
cursor = cursor->next;
}

template<class positionType,class keyType , class dataType>
bool List< positionType,keyType ,  dataType>::atFirst(){
    return (cursor==head);
}
template<class positionType,class keyType , class dataType>
bool List< positionType,keyType ,  dataType>::atEnd(){
    return (cursor->next == NULL);
}
template<class positionType,class keyType , class dataType>
bool List< positionType,keyType ,  dataType>::listIsEmpty(){
return (head==NULL);
}

template<class positionType,class keyType , class dataType>
void List< positionType,keyType ,  dataType>::toEnd(){
    toFirst();
    if(!listIsEmpty()){
        while(cursor->next !=  NULL){
          advance();
        }
    }
}

template<class positionType,class keyType , class dataType>
int List< positionType,keyType ,  dataType>::listSize(){

    NodePointer q;
    q=head;
    int count=0;
    while(q!=NULL){
        count++;
        q=q->next;
    }
    return count;
}

template<class positionType,class keyType , class dataType>
void List< positionType,keyType ,  dataType>::print_list() {
    cout << "\nPrinting new list..." << endl;
    toFirst();
    while (!listIsEmpty()&&!curIsEmpty()) {
            cout << cursor->data << " ";
        advance();
}
}
int main()
{
    List<int , int , string > list;
    list.inserNode(1,"shehab");
    list.inserNode(2,"osama");
    list.inserNode(3,"fathi");
    list.inserNode(4,"abdelazez");
    list.inserNode(5,"abdelglel");
    list.print_list();
    list.insertAfter(3,6,"Abo radi");
    list.insertBefore(2,7,"joo");
    list.print_list();
    list.deleteEnd();
    list.deleteEnd();
    list.print_list();
    list.deleteFirst();
    list.deleteFirst();
    list.print_list();
    list.makeListEmpty();
    list.print_list();
    list.inserNode(1,"shehab");
    list.inserNode(2,"osama");
    list.print_list();
    return 0;
}
