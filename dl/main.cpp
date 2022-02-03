#include "list.h"

void displayll(node* h)
{

    if(h)
    {
        cout<<h->data<<"-";
        displayll(h->next);
    }
}

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL
    object.showtaildata();
    return 0;
}
