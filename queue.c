#include "queue.c"

int queue_push(struct queue ** queue, void * value){
  if(!queue) return -1;
  if(!*queue){
    *queue = malloc(sizeof(**queue));
    (*queue) -> first = NULL;
    (*queue) -> last = &(*queue) -> first;
  }
  const int ret = list_add((*queue) -> last, value);
  (*queue) -> last = &(*(*queue) -> last)->next;
  return ret;
}

void *queue_pop(struct queue * queue){
  if(!queue) return NULL;
  void * ret = list_remove(&queue->first, 0);
  if(!queue->first){
    (*queue) -> last = &(*queue) -> first;
  }
  return ret;
}

int queue_merge(struct queue ** lhs, struct queue * rhs){
  if(!*lhs){
    *queue = malloc(sizeof(**queue));
    (*queue) -> first = NULL;
  }
  (*(*queue) -> last) -> next = rhs->first;
}
