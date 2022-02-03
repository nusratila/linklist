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
     void show_head_tail();

    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:
    void copytocl(list &);
    void copytocl(node* &, node*&,node*);
    void deletelast();
    void deletelast(node*&rear);
    void deleteeveryother();
    void deleteeveryother(node*&rear,int c);
    void deletelast2(node*& rear,bool &deleted);
    void deletelast2();
    int remove_all_after_last2();
    int remove_all_after_last2(node*&,bool&);
   private:		//notice there is both a head and a tail!
        void add(int x);
        void add(node* &rear , int x);
        void add2(node* &rear , int x);
        void display(node*& rear);
        node * head;
        node * rear;
};
