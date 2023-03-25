#include <iostream>
using namespace std;
class node
{
    int data;
    node *next;

public:
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    friend class list;
};

class list
{
    node *head;

public:
    list()
    {
        this->head = NULL;
    }

    void insert(int data)
    {
        node *newnode = new node(data);

        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
        }

        else
        {
            node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }
    }

    void insertatend(int data)
    {
        node *newnode = new node(data);

        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    void display()
    {
        node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }

    void remove(int pos)
    {

        node *temp = head;
        node *pre = head;
        if (pos == 1)
        {
            head = temp->next;
        }
        int count = 1;
        while (count != pos)
        {
            pre = temp;
            temp = temp->next;
            count++;
        }

        pre->next = temp->next;
    }

    void update(int pos, int data)
    {
        node*temp=head;
        int count = 1;

        if (pos == 1)
        {
            temp->data=data;
            
        }
       
        while (count != pos)
        {
            temp = temp->next;
            count++;          
        }
        temp->data=data;
    }
};
int main()
{
    list l1;
    l1.insert(10);
    l1.insert(20);
    l1.insert(30);
    l1.insertatend(90);
    l1.insert(40);
    l1.display();
    cout << endl;
    l1.remove(5);
    l1.display();
    cout<<endl;
    l1.update(2,-99);
    l1.display();
    cout<<endl;
    return 0;
}