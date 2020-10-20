#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}
bool IntList::exists(int input) const
{
    /* Returns true if the integer passed in is contained within the IntList.
      Otherwise returns false.
   */
    if (head == nullptr)
    {
        return false;
    }
    if (input == head->data)
    {
        return true;
    }
    return exists(head->next, input);
}
bool IntList::exists(IntNode* nodes, int input) const
{
    /* Helper function that returns true if the integer passed in is contained within
     the IntNodes starting from the IntNode whose address is passed in.
     Otherwise returns false.
  */
    if (nodes == nullptr)
    {
        return false;
    } 
    if (input == nodes->data)
    {
        return true;
    }
    return exists(nodes->next, input);
}
ostream& operator<<(ostream& out, const IntList& list)
{
    /* Outputs to a single line all of the int values stored in the list, each separated by a space.
     This function does NOT output a newline or space at the end.
  */
    if (list.head != nullptr)
    {
        out << list.head->data;
        out << (list.head->next);
    }
    return out;
}
ostream& operator<<(ostream& out, IntNode* nodes)
{
    /* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
    if (nodes != nullptr)
    {
        out << ' '<< nodes->data;
        out << (nodes->next);
    }
    return out;
}