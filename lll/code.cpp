#include "list.h"
#include <fstream>
list::list()
{
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

//Count the number of items in the list that are the same as the first node  and return the count.
//wrapper
int list :: count_same_as_1st_node()
{
    if(!head)
        return 0;

    int value = head->data;
    int count = 1;

    return count_same_as_1st_node(head->next,value,count);
}

int list ::count_same_as_1st_node(node * &head, int value,int &count)
{
    if(!head)
        return count;

    if(head->data == value)
        ++count;
    return count_same_as_1st_node(head->next,value,count);

}



//Count  the  number  of  items  in  the  list  that  are  the  same  as  the  last  node  and return the count.
int list :: count_same_as_last()
{
    if(!head)
        return 0;
    int value;
    int count = 1;

    return count_same_as_last(head,count,value);
}

int list :: count_same_as_last(node * &head,int &count,int &value)
{
    if(!head->next)
        return count;
    value =  head->next->data;
    count_same_as_last(head->next,count,value);
    if(head->data == value)
        ++count;
    return count;


}







//Count the number of items in the list that are greater than ‘4’ and return the count.

int list :: count_greater_than4()
{
    if(!head)
        return 0;

    int count=0;

    return count_greater_than4(head,count);
}

int list :: count_greater_than4(node * &head,int &count)
{
    if(!head)
        return count;
    if(head->data > 4)
        ++count;
    return count_greater_than4(head->next,count);

}




//Display  all  of  the  unique  data  that  exists  in the  data  structure  and  return  the sum of all unique items.

//Remove the first node and place it at the end of the list; return the number of items in the list.
int list :: remove_1st_replace_last_count_total()
{
    if(!head)
        return 0;
    if(!head->next)
        return 1;

   tail->next = head;
   head = head->next;
   tail = tail->next;
   tail->next = NULL;

   int count = 0;
   return remove_1st_replace_last_count_total(head,count);
}

int list :: remove_1st_replace_last_count_total(node * &head, int & count)
{
    if(!head)
        return count;
    ++count;
    return remove_1st_replace_last_count_total(head->next,count);
}




//Remove the last ‘2’ and return the total number of 2’s in the list. Do this is only a single traversal.
int list :: remove_last_2_Count_total_2()
{
    if(!head)
        return 0;



    int count = 0;
    bool delete2 = false;
    //node * previous;
    return remove_last_2_Count_total_2(head,count,delete2);
}


int list :: remove_last_2_Count_total_2(node * & head, int & count, bool & delete2)
{
    if(!head)
        return count;
    else if(!head->next)
    {
        if(head->data==2)
        {
            delete head;
            head=NULL;
            delete2 = true;
        }
        return count;

    }
    else
    {
        if(head->data == 2)
        ++count;
        remove_last_2_Count_total_2(head->next,count,delete2);

    }
//    if(head->next->next)
  //      remove_last_2_Count_total_2(head->next,count,delete2);

    if(head->next->data == 2 && (!delete2))
    {
        node * temp = head->next;
        cout<<"deleting : "<<head->next->data<<endl;
        cout<<"prev: "<<head->data<<endl;
        //previous->next = head;
        head->next= head->next->next;
        delete temp;
        temp = NULL;
        //count = count - 1;
        delete2 = true;
    }
    return count;
}

int list :: remove_last_2_Count_total()
{
    if(!head)
        return 0;
    bool delete2 = false;
    //node * previous;
    return remove_last_2_Count_total(head,delete2);
}


int list :: remove_last_2_Count_total(node * & head, bool & delete2)
{
    int count =0;
    tail = NULL;

    if(!head->next)
    {
        if(head->data==2)
        {
            delete head;
            head=NULL;
            delete2 = true;
        }
        else
        {
            tail = head;
        }
        return 0;
    }
    else
    {
        tail = head;
    }

    if(head->data == 2)
        count=1;
    count+=remove_last_2_Count_total(head->next,delete2);

    if(head->data == 2 && (!delete2))
    {

        node * temp = head;
        head= head->next;
        delete temp;
        temp = NULL;
        count = count - 1;
        delete2 = true;
    }
    return count;
}

node * list ::copyeven()
{
    node * evenll;
    if(head)
    {
        evenll = copyeven(head);
    }
    return evenll;
}
node* list ::copyeven( node* &head)
{
    node* evenll =NULL;
    if(!head)
        return NULL;

    evenll = copyeven(head->next);
    if(head->data %2 == 0)
    {
        if(evenll)
        {
            node * temp = evenll;
            while(temp->next)
            {
                temp = temp->next;
            }
            temp->next = new node;
            temp->next->data = head->data;
            temp->next->next = NULL;
        }
        else
        {
            evenll = new node;
            evenll->data = head->data;
            evenll->next = NULL;
        }

    }
    return evenll;
}

void list::copyeven2(node*& evenll)
{
    if(!head)
        return ;
    copyeven2(evenll,head);

}
void list::copyeven2(node*& evenll,node*& head)
{
    if(!head)
        return ;
    if(head->data%2==0)
    {
        if(evenll)
        {
            node* temp = evenll;
            while(temp->next)
            {
                temp = temp->next;
            }
            temp->next = new node;
            temp->next->data = head->data;
            temp->next->next = NULL;

        }
        else
        {
            evenll = new node;
            evenll->data = head->data;
            evenll->next = NULL;
        }
    }

    copyeven2(evenll,head->next);
}
node* list:: copyeven3()
{
    node * result =NULL;
    node * temp = NULL;
    if(!head)
        return result;
    copyeven3(head,result,temp);
    return result;
}
void list:: copyeven3(node*&head,node*&result,node*&temp)
{
     if(!head)
        return ;
    if(head->data%2==0)
    {
        if(result)
        {

            temp->next = new node;
            temp = temp->next;
            temp->data = head->data;
            temp->next = NULL;

        }
        else
        {
            result = new node;
            result->data = head->data;
            result->next = NULL;
            temp = result;
        }
    }

    copyeven3(head->next,result,temp);
    return;
}

int list::print_unique_data()
{
    if(!head)
        return 0;
    print_unique_data(head);
}


int list::print_unique_data(node *& head)
{
    if(!head)
        return 0;
    //int countdata = 0;
    int data = head->data;
    int countdata  = find_unique(data);
  //  if(countdata==1)
//        cout<<"unique: "<<head->data<<endl;
    cout<<"this data "<<head->data<<" occurs "<<countdata<< " times\n";

    print_unique_data(head->next);

}
int list::find_unique(int data)
{
    return find_unique(data,head);
}

int list::find_unique(int  data, node * & head)
{
    int countdata = 0 ;
    if(!head)
        return 0;
    if(head->data == data)
        countdata++;
    countdata+=find_unique(data,head->next);
    return countdata;

}

