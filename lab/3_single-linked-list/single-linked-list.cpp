#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

struct node {
    //bagian data 
    char data;
    //pointer ke node selanjutnya
    struct node* next;
};
typedef struct node node;
node* head, * tail;

void AddLast(char item) { // Add Node After Tail
    struct node* pNew;
    pNew = (node*)malloc(sizeof(node));
    pNew->data = item;
    if (head == NULL) {
        head = pNew;
    }
    else {
        tail->next = pNew;
    }
    tail = pNew;
}

void AddFirst(char item) { // AddNodeBeforeHead
    struct node* pNew;
    pNew = (node*)malloc(sizeof(node));
    pNew->data = item;
    if (head == NULL) {
        tail = pNew;
    }
    else {
        pNew->next = head;
    }
    head = pNew;
}

//penyisipan
void AddAt(int index, char item) {
    struct node* pNew;
    pNew = (node*)malloc(sizeof(node));
    pNew->data = item;

    if (index == 0) {
        pNew->next = head;
        tail->next = pNew;
        head = pNew;
        return;
    }

    node* temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            cout << "Index tidak mencukupi" << endl;
            return;
        }
    }

    pNew->next = temp->next;
    temp->next = pNew;
}

//hapus awal
void RemoveFirst() {
    if (head == nullptr) {
        cout << "List kosong" << endl;
    }
    else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }
}

//hapus akhir
void RemoveLast() {
    if (head == nullptr) {
        cout << "List kosong" << endl;
    }
    else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        node* temp = tail;
        tail->next = head;
        delete temp;
    }
}

//hapus di indeks
void RemoveAt(int index) {
    if (head == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    if (index == 0) {
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        return;
    }

    node* temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
        if (temp == tail) {
            cout << "Index tidak mencukupi" << endl;
            return;
        }
    }

    if (temp->next == tail) {
        delete tail;
        tail = temp;
        tail->next = head;
    }
    else {
        node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }
}

//pencarian
node* FindNode(char item) {
    node* pCurrent = head;
    while (pCurrent != NULL && pCurrent->data != item) {
        pCurrent = pCurrent->next;
    }
    return pCurrent;
}

//pengaksesan
char GetNodeData(int index) {
    int count = 0;
    node* pCurrent = head;
    while (pCurrent != NULL && count != index) {
        pCurrent = pCurrent->next;
        count++;
    }
    if (pCurrent == NULL) {
        return '\0'; // Return Null Character if Node Not Found
    }
    return pCurrent->data;
}

//method pertama

// int main()
// {
//     head = tail = NULL;
//     AddFirst('A');
//     cout << "head : " << head->data << endl;
//     cout << "tail : " << tail->data << endl;
//     AddFirst('B');
//     cout << "head : " << head->data << endl;
//     cout << "tail : " << tail->data << endl;
//     AddFirst('C');
//     cout << "head : " << head->data << endl;
//     cout << "tail : " << tail->data << endl;
//     AddFirst('D');
//     cout << "head : " << head->data << endl;
//     cout << "tail : " << tail->data << endl;
    
//     return EXIT_SUCCESS;
// }

// method kedua

int main()
{
    head=tail=NULL;
    AddLast ('A');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;
    AddLast ('B');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;
    AddLast ('C');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;
    AddLast ('D');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;

    AddAt(0, 'E');
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    RemoveFirst();
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    
    return EXIT_SUCCESS;
}
