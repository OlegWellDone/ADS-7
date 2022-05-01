// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T value;
    ITEM * next;
  };
  ITEM * head;
 public:
  TPQueue() : head(nullptr) { }
  void push(const T&);
  T pop();//вывод типа данных Т
};

struct SYM {
  char ch;
  int prior;
};

template <typename T>
void TPQueue <T> :: push(const T&) {
  if (!head) {
    head = new ITEM;
    head -> value = value;
    head -> next = nullptr;
   //присваивание следующему элементу нуля, чтобы существовала ссылка на следующий будущий элемент
  } else if (value.prior > head -> value.prior) {
   //случай если полученный приоритет выше чем приоритет который у элемента головы
    ITEM * temp = new ITEM;
    temp -> value = value;
    temp -> next = head;
    head = temp;
  } else {
    ITEM * prop = head;
    while (prop -> hext) {
      if (value.prior > prop -> next -> value.prior) {
        ITEM * temp = new ITEM;
        temp -> value = value;
        temp -> next = prop -> next;
        prop -> next = temp;
        return;
      }
      prop = prop -> next;
    }
    prop -> next = new ITEM;
    prop -> next -> value = value;
    prop -> next -> next = nullptr;
  }
}

template <typename T>
T TPQueue <T> :: pop() {
  if (head) {
    ITEM * temp = head -> next;
    delete head;
    head = temp;
    return value;
  } else {
    throw std :: string("!pusto");
  }
}
#endif  // INCLUDE_TPQUEUE_H_
