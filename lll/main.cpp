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
    int result= object.remove_last_2_Count_total();
    object.display();
    object.showtaildata();
    cout<<"result "<<result<<endl;
    //displayll(result);
    /*
    node * evenll;
    cout<<"before"<<&evenll<<endl;
    evenll = NULL;
    cout<<"after"<<&evenll<<endl;
    object.copyeven2(evenll);
    node * temp = evenll;
    while(temp)
    {
        cout<<"data: "<<temp->data<<endl;
        temp = temp->next;
    }
    */
    //cout<<evenll->data;


    //PLEASE PUT YOUR CODE HERE to call the function assigned

//Count the number of items in the list that are the same as the first node  and return the count.
//wrapper
//int count=0;
/*
count = object.count_same_as_1st_node();
cout << "the number of nodes matches with 1st node's data is : " << count <<endl;
count = object.count_same_as_last();
cout << "the number of nodes matches with last node's data is : " << count <<endl;
count = object.count_greater_than4();
cout << "the number of nodes that is greater than 4 is : " << count <<endl;
count = object.remove_1st_replace_last_count_total();
cout << "number of nodes : " << count << endl;
*/
//count = object.remove_last_2_Count_total_2();
//cout<< "number of 2 in the list : " <<count <<endl;

   // object.display();  //displays the LLL again!


    return 0;
}
