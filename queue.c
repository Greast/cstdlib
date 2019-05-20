#include "queue.h"
#include "std.h"

__attribute__((nonnull(1)))
int queue_push(struct queue ** queue, void * value){
  if(!*queue){
    *queue = malloc(sizeof(**queue));
    (*queue) -> first = NULL;
    (*queue) -> last = &(*queue) -> first;
  }
  const int ret = list_add((*queue) -> last, value);
  (*queue) -> last = &(*(*queue) -> last)->next;
  return ret;
}

__attribute__((nonnull(1)))
void *queue_pop(struct queue * queue){
  void * ret = list_remove(&queue->first, 0);
  if(!queue->first){
    queue -> last = &queue -> first;
  }
  return ret;
}

int queue_merge(struct queue ** lhs, struct queue * rhs){
  if(!*lhs){
    *lhs = malloc(sizeof(**lhs));
    (*lhs) -> first = NULL;
  }
  (*(*lhs) -> last) -> next = rhs->first;
  return 0;
}
