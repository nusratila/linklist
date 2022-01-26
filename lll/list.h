//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;   //some questions are a char * data;
    node * next;
};


class list
{
   public:
   //These functions                                                                                       are already written for you
     list();			//supplied
     ~list();			//supplied
     void build();     		//supplied
     void display();  		//supplied
     void showtaildata();

    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:

    int count_same_as_1st_node();
    int count_same_as_1st_node(node*& head, int value,int &count);

    int count_same_as_last();
    int count_same_as_last(node * &head,int &count,int &value);

    int count_greater_than4();
    int count_greater_than4(node * &head,int &count);

    int remove_1st_replace_last_count_total();
    int remove_1st_replace_last_count_total(node * &head, int & count);
    int remove_last_2_Count_total();
    int remove_last_2_Count_total(node * & head, bool & delete2);
    int remove_last_2_Count_total_2();
    int remove_last_2_Count_total_2(node * & head, int & count, bool & is_found);


    node * copyeven();
    node * copyeven(node* &head);

    void copyeven2(node*&);
    void copyeven2(node*&,node*&);
    node* copyeven3();
    void copyeven3(node*&,node*&,node*&);
   private:		//notice there is both a head and a tail!
      node * head;
      node * tail;
};
