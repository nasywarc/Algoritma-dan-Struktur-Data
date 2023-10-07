#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

struct node {
    //bagian data 
    char data;
    //pointer ke node selanjutnya
    struct node* next;
    struct node* prev;
};
typedef struct node node;
node* head, * tail;

void AddFirst(char item) { // AddNodeBeforeHead
    node* pNew;
    pNew = new node;
    pNew->data = item;
    pNew->prev = nullptr;
    if (head == nullptr) {
        tail = pNew;
        tail->next = nullptr;
    }
    else {
        pNew->next = head;
        head->prev = pNew;
    }
    head = pNew;
}

void AddLast(char item) { // Add Node After Tail
    node* pNew;
    pNew = new node;
    pNew->data = item;
    pNew->next = nullptr;
    if (head == nullptr) {
        head = pNew;
        head->prev = nullptr;
    }
    else {
        tail->next = pNew;
        pNew->prev = tail;
    }
    tail = pNew;
}

void AddAt(char item, int index) { // Add Node At Index
    if (index == 0)
    {
        AddFirst(item);
        return;
    }
    node* _node = head;
    while (index-- > 0 && _node->next != nullptr)
        _node = _node->next;
    node* pNew = new node;
    pNew->data = item;
    pNew->prev = _node->prev;
    pNew->next = _node;
    _node->prev->next = pNew;
    _node->prev = pNew;

}

void RemoveFirst() {
    if (head == nullptr && head != nullptr) {
        delete head;
        head = tail = nullptr;
    }
    else if (head != nullptr) {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
}

void RemoveLast() {
    if (head == tail && head != nullptr) {
        delete head;
        head = tail = nullptr;
    }
    else if (head != nullptr) {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
}

void RemoveAt(int index) {
    if (head == nullptr) return;
    if (index == 0)
    {
        RemoveAt(index);
        return;
    }
    node* _node = head;
    while (index-- > 0 && _node->next != nullptr)
        _node = _node->next;
    if (_node == tail)
    {
        RemoveLast();
        return;
    }
    node* del = _node;
    del->next->prev = del->prev;
    del->prev->next = del->next;
    del->next = del->prev = nullptr;
    delete del;
}

int index(char item) {
    if (head == nullptr) 
        return -1;

        int i = 0;
        node* _node = head;
        while (_node != nullptr) {
            if (_node->data == item)
                break;
            _node = _node->next;
            i++;
        }
        if (_node == nullptr) 
            return -1;
}

int backLast(char item)
{
    if (head == nullptr)
        return -1;
    int i = -1;
    node* _node = head;
    for (size_t j = 0; _node != nullptr; j++)
    {
        if (_node->data == item)
            i = j;
        _node = _node->next;
    }
    return i;
}

int* indexOf(char item)
{
    if (head == nullptr)
        return {};
    int* index = (int*)malloc(0);
    int count = 0;
    node* _node = head;
    for (size_t j = 0; _node != nullptr; j++)
    {
        if (_node->data == item)
        {
            index = (int*)realloc(index, ++count * sizeof(int));
            index[count - 1] = j;
        }
        _node = _node->next;
    }
    index = (int*)realloc(index, count + 1 * sizeof(int));
    index[count] = -1;
    return index;
}

node* GetFirst()
{
    return head;
}

node* GetLast()
{
    return tail;
}


void delList()
{
    if (head == nullptr)
        return;
    while (head->next != nullptr)
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
    delete head;
    head = tail = nullptr;
}

void printList()
{
    if (head == nullptr)
    {
        cout << "head : " << head << endl;
        cout << "tail : " << tail << endl;
        return;
    }
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    cout << "list : ";
    node* _node = head;
    cout << _node->data << " ";
    while ((_node = _node->next) != nullptr)
        cout << _node->data << " ";
    cout << endl << endl;
}


int main () {

    AddFirst('O');
    AddFirst('G');
    AddFirst('L');
    AddFirst('A');
    printList();

    AddLast('R');
    AddLast('T');
    AddLast('A');
    AddLast(' ');
    AddLast('D');
    AddLast('S');
    printList();

    AddAt('I', 5);
    printList();

    AddAt('M', 7);
    printList();

    RemoveLast();
    RemoveLast();
    RemoveLast();
    printList();

    AddLast(' ');
    AddLast('S');
    AddLast('D');
    printList();


    //getch();    
    return EXIT_SUCCESS;
}
