#include "list.h"
#include <fstream>
list::list()
{
    tail = NULL;
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

    node* th = head;
    if(th)
    {
        cout<<"Link List: ";
         while(th->next)
        {
            cout<<th->data<<"->";
            th = th->next;
        }
        cout<<th->data<<endl;
    }
    else
        cout<<"link list is empty"<<endl;

}

void list::showtaildata()
{
    if(tail)
        cout<<"tail data: "<<tail->data<<endl;
    else
        cout<<"tail is NULL"<<endl;
}
void list::add(int x)
{
    node* th=head;
    if(th)
    {
        while(th->next)
        {
            th = th->next;
        }
        node * temp = new node;
        temp->data = dat;
        temp->next = NULL;
        th->next = temp;
        tail = temp;

    }
    else
    {
        head = new node;
        head->data = dat;
        head->next = NULL;
        tail = head;
    }
}
//Count the number of items in the list that are the same as the first node  and return the count.
//wrapper


