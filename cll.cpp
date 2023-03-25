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

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head; // make the new node point to itself
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head; // make the new node point to the head
    }
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

    int countnodes(){

        node*temp=head;
        int count=0;
        do{
            temp=temp->next;
            count++;
        }

        while(temp!=head);

        return count;
    }

    bool remove(int pos)
    {
         bool flag=false;
        if(pos>this->countnodes()){
            return flag;
        }
      
        node *temp = head;
        node *pre = head;
        if(head==NULL){
            return flag;
        }
        if (pos == 1)
        {
            head = temp->next;
            flag=true;
            return flag;
        }
        int count = 1;
        while (count != pos)
        {
            pre = temp;
            temp = temp->next;
            count++;
        }

        pre->next = temp->next;
        flag=true;
        return flag;
    }

    bool update(int pos, int data)
    {

        bool flag=false;
        if(pos>countnodes()){
            return flag;
        }
        node*temp=head;
        int count = 1;

        if (pos == 1)
        {
            temp->data=data;
            flag=true;
            return flag;
            
        }
       
        while (count != pos)
        {
            temp = temp->next;
            count++;          
        }
        temp->data=data;
        flag=true;
        return flag;

    }
   
};
int main()
{
    list l1;
    l1.insertatend(87);
    l1.insert(10);
    l1.insert(20);
    l1.insert(30);
    l1.insertatend(90);
    l1.insert(40);
    l1.display();
    cout << endl;
    if(l1.remove(80)==false){
        cout<<"---Invalid Node-----"<<endl;
    }
    l1.display();
    cout<<endl;
    if(l1.update(90,-99)==false){
        cout<<"----Invalid node-----"<<endl;
    };
    l1.display();
    cout<<endl;

    cout<<"Total nodes: "<<l1.countnodes()<<endl;
    return 0;
}