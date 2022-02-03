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
    //list object2;
    object.build();    //builds a LLL
    object.display();  //displays the LLL
    //object2.display();
    //object.deleteeveryother();
    //object.display();
    //object.copytocl(object2);
    //object2.display();
    object.remove_all_after_last2();
    object.display();
    return 0;
}
