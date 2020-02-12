#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
  public:
  Queue();
  ~Queue();
  /* implement copy constructor, assignment, destructor if needed */
  void queue_test(int n);
  void enqueue(float value);
  float dequeue();

  private:
  float *_data;
  int size;
  int _head;
  int _tail;
  bool IsFull();
  bool IsEmpty();
  /* declare your data */
};


#endif
