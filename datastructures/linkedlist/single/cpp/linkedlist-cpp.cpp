#include "linkedlist-cpp.hpp"
#include <iostream>

IntSLList::~IntSLList() {
  for (IntSLLNode *p; !isEmpty();) {
    p = head->next;
    delete head;
    head = p;
  }
}

void IntSLList::addToHead(int el) {
  head = new IntSLLNode(el, head);
  if (tail == 0) {
    tail = head;
  }
}

void IntSLList::addToTail(int el) {
  if (tail != 0) {
    tail->next = new IntSLLNode(el);
    tail = tail->next;
  } else
    head = tail = new IntSLLNode(el);
}

int IntSLList::deleteFromHead() {
  int el = head->info;
  IntSLLNode *tmp = head;
  if (head == tail)
    head = tail = 0;
  else
    head = head->next;
  delete tmp;
  return el;
}

int IntSLList::deleteFromTail() {
  int el = tail->info;
  if (head == tail) {
    delete head;
    head = tail = 0;
  } else {
    IntSLLNode *tmp;
    for (tmp = head; tmp->next != tail; tmp = tmp->next)
      ;
    delete tail;

    tail = tmp;
    tail->next = 0;
  }
  return el;
}

void IntSLList::deleteNode(int el) {
  if (head != 0) {
    if (head == tail && el == head->info) {
      delete head;
      head = tail = 0;
    } else if (el == head->info) {
      IntSLLNode *tmp = head;
      head = head->next;
      delete tmp;
    } else {
      IntSLLNode *pred, *tmp;
      for (pred = head, tmp = head->next; tmp != 0 && !(tmp->info == el);
           pred = pred->next, tmp = tmp->next)
        ;
      if (tmp != 0) {
        pred->next = tmp->next;
        if (tmp == tail)
          tail = pred;
        delete tmp;
      }
    }
  }
}

bool IntSLList::isInList(int el) const {
  IntSLLNode *tmp;
  for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next)
    ;
  return tmp != 0;
}

void IntSLList::printList() {
  IntSLLNode *tmp = head;
  while (tmp != NULL) {
    std::cout << tmp->info << std::endl;
    tmp = tmp->next;
  }
}

int main() {
  IntSLList *list = new IntSLList();
  list->addToHead(1);
  list->addToHead(0);
  list->addToTail(2);
  list->addToTail(3);
  list->addToTail(4);
  int shifted = list->deleteFromHead();
  int popped = list->deleteFromTail();
  list->deleteNode(2);
  list->printList();
  return 0;
}