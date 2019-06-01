#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
  
}

void StudentRoll::insertAtTail(const Student &s) {
  if (head == NULL) {
      head = tail = new Node;
      head->s = new Student(s);
      head->next = NULL;
  } else {
  	tail->next = new Node;
	tail = tail->next;
	tail->s = new Student(s);
	tail->next= NULL;
  }
}

std::string StudentRoll::toString() const {
  std::string temp;
  Node *n = head;
  while (n) {
	  if(!temp.empty())
		  temp += ",";
	  temp += n->s->toString();
	  n = n->next;
  }
  return "[" + temp + "]";
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  Node *n = orig.head;
  if (!n) {
	  head = tail = NULL;
	  return;
  }

  head = new Node;
  Node *t = head;
  t->s = new Student(n->s->getName(), n->s->getPerm());
  while (n->next) {
	t->next = new Node;
	t = t->next;
	n = n->next;
	t->s = new Student(n->s->getName(), n->s->getPerm());
  }
  tail = t;
  tail->next = NULL;
}

StudentRoll::~StudentRoll() {
  Node *n = head;
  while (n) {
	  Node *temp = n->next;
	  delete n->s;
	  delete n;
	  n = temp;
  }
  head = tail = NULL;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

    if (&right == this) 
          return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
    if (head)
	  delete head;

    Node *n = right.head;
    if (!n) {
          head = tail = NULL;
          return (*this);
    }
    head = new Node;
    Node *t = head;
    t->s = new Student(n->s->getName(), n->s->getPerm()) ;
    while (n->next) {
 	 t->next = new Node;
         t = t->next;
	 n = n->next;
	 t->s = new Student(n->s->getName(), n->s->getPerm());
    }
  tail = t;
  tail->next = NULL;

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





