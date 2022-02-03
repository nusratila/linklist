#include "list.h"
#include <fstream>
//reverse lll
list::list()
{
    rear = NULL;
    head = NULL;
}
list::~list()
{

}
void list::build()
{
    string line;
    ifstream spellfile("ll.txt");
    int num;
    int dat = 0;
    if(spellfile.is_open())
    {
        while(getline(spellfile,line))
        {
            num++;
            try
            {

                dat=stoi(line);
                //cout<<dat<<endl;
                //add data here
                add(dat);
            }
            catch(invalid_argument const &e)
            {
                cout<<"string to i failed\n";
            }
        }

        spellfile.close();
    }
    else
        cout<<"can not open spell file"<<endl;

}
void list::display()
{
    if(!rear)
    {
        cout<<"NULL CL"<<endl;
    }
    else
    {
        display(rear->next);
    }
    cout<<endl;
    return;
}
void list::display(node*& rear)
{
    cout<<rear->data<<"->";
    if(rear!=this->rear)
    {
        display(rear->next);
    }
}
void list::show_head_tail()
{
    if(head)
        cout<<"head: "<<head->data<<endl;
    else
        cout<<"rear:NULL"<<endl;
    if(rear)
        cout<<"rear: "<<rear->data<<endl;
    else
        cout<<"rear:NULL"<<endl;
}
void list::add(int x)
{
    if(!rear)
    {
        rear = new node;
        rear->data = x;
        rear->next = rear;
    }
    else
    {
        add2(rear->next,x);
    }
}

//adding in the begining : no change in rear
void list::add(node*& rear, int x)
{
    if(rear==this->rear)
    {
        node* t= new node;
        t->data = x;
        t->next = rear->next;
        rear->next = t;
    }
    else
    {
        add(rear->next,x);
    }
    return;
}
void list::add2(node*& rear, int x)
{
    if(rear==this->rear)
    {
        node* t= new node;
        t->data = x;
        t->next = rear->next;
        rear->next = t;

        this->rear = t;
    }
    else
    {
        add2(rear->next,x);
    }
    return;
}
//Count the number of items in the list that are the same as the first node  and return the count.
//wrapper
//########################

void list::deletelast()
{
    if(rear)
        if(rear==rear->next)
        {
            delete rear;
            rear = NULL;
        }
        else
            deletelast(rear->next);

    return;
}
void list::deletelast(node*& rear)
{
    if(rear->next==this->rear)
    {
        node* t = rear->next;
        rear->next = rear->next->next;
        this->rear = rear;
        delete t;
        t=NULL;
    }
    else
        deletelast(rear->next);
    return;
}
void list::deleteeveryother()
{
    if((!rear)||(rear==rear->next))
        return;
    else
        deleteeveryother(rear->next,0);
}
void list::deleteeveryother(node*&rear,int c)
{
    c++;
    if(rear->next==this->rear)
    {
        if(c%2==1)
            cout<<rear->next->data<<" final c: "<<c<<endl;
    }
    else
    {
        deleteeveryother(rear->next,c);
        if(c%2==1)
        {
            cout<<rear->next->data<<" c: "<<c<<endl;
        }

    }
}

void list::deletelast2()
{
    bool deleted = false;
    if(rear)
        deletelast2(rear->next,deleted);
    if(!deleted)
    {
        if(rear->next->data==2)
        {
            node * t = rear->next;
            rear->next=rear->next->next;
            delete t;
            t = NULL;

        }
    }
    return;
}

void list::deletelast2(node*& rear,bool &deleted)
{
    if(this->rear == rear->next)
    {
        cout<<"lastnode: " <<rear->data<<endl;
        if((rear->next->data==2)&&(!deleted))
        {
            cout<<"delete : "<<rear->next->data<<endl;
            node* temp = rear->next;
            rear->next=rear->next->next;
            delete temp;
            temp = NULL;
            this->rear=rear;
            deleted = true;
        }

    }
    else
    {
        deletelast2(rear->next,deleted);
        //cout<<"othernode: " <<rear->data<<endl;

        if((rear->next->data==2)&&(!deleted))
        {
            cout<<"delete : "<<rear->next->data<<endl;
            node* temp = rear->next;
            rear->next=rear->next->next;
            delete temp;
            temp = NULL;
            deleted = true;
        }
    }

    return ;
}
void list::copytocl(list & destlist)
{
    //node* destrear = NULL;
    if(!rear)
        return;

    if(rear->next)
    {
        destlist.rear = new node;
        destlist.rear->data = rear->data;
        destlist.rear ->next = NULL;
    }
    copytocl( rear ->next,destlist.rear,destlist.rear);
    return;
}

void list::copytocl(node* &src,node *&dest,node* dstrear)
{

    if(rear==src)
        dest->next=dstrear;
    else
    {
        dest->next=new node;
        dest->next->data = src->data;
        dest->next->next = NULL;
        copytocl(src->next,dest->next,dstrear);
    }
    return;
}

//Remove all nodes after the last ‘2’ and return the number of nodes removed. Do this in a single traversal.
int list :: remove_all_after_last2()
{
    int res = 0 ;
    bool removed= false;
    if(!rear)
        return 0;

    if(rear->data==2)
    {
        cout<<" rear data 2 nothing to delete"<<endl;
        return 0;
    }
    else if(rear->next == rear)
    {
        cout<<"only one item"<<endl;
        return 0;
    }
    else
    {
        res = remove_all_after_last2(rear->next,removed);
    }


    /*
    cout<<"res: "<<res<<endl;
    node*& temp_rear = rear->next;
    cout<<rear->data<<endl;
    node* t = temp_rear->next;
    node*& tr2= temp_rear->next->next;

    if(this->rear==tr2)
    {
        node* t = this->rear->next;
        cout<<"deleting "<<tr2->data<<endl;
        delete this->rear;
        this->rear = NULL;
        tr2 = t;
    }
    this->rear = t;
    */
    return 0;
}

int list :: remove_all_after_last2(node * &rear, bool&  isdeleted)
{
    node *t ;
    if(rear->data==2)
        isdeleted = true;
    int res = 0 ;
    if(this->rear == rear )
    {
        if(isdeleted)
        {
            this->rear = NULL;
            t = rear;
            rear = rear->next;

            delete t;
            t = NULL;
        }
        return 0;

    }

    res = remove_all_after_last2(rear->next,isdeleted);
    if(!this->rear)
        this->rear = rear;
    if(rear->data==2)
        isdeleted = false;
    if(isdeleted)
        {
            this->rear = NULL;
            t = rear;
            rear = rear->next;
            t->next = NULL;
            delete t;
            t = NULL;
        }
    return res;
}
