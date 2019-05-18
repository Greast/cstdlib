/*! \file */

#ifndef _C_STD_LIB_QUEUE_H_
#define _C_STD_LIB_QUEUE_H_

#include "std.h"

/*!
\brief Queue struct for Queus.

This struct allows for the usage of queues. It cannot support dequeue operations, as the internal list is as singly linked list.
*/
struct queue{
  struct list *first, //!< This pointer, points to the first element of the queue.
  **last; //!< This pointer, points to the next pointer, of the last element. Should the last element be NULL, it will pointer to the first pointer instead.
};

/*!
\fn int queue_push(struct queue ** queue, void * value)
\brief Pushes a new element into the queue.

This function, pushes a new element, into the back of the queue. Should the given queue be NULL, then the function will create a new queue
\param queue The queue, which is extended with the new value.
\param value The value which is added to the queue.
*/
int queue_push(struct queue ** queue, void * value);

/*!
\fn void * queue_pop(struct queue * queue)
\brief This function, removes the first element from the queue, and returns it. Should queue be empty, the function returns NULL.

\param queue The queue from which the value is remove from.
*/
void * queue_pop(struct queue * queue);

/*!
\fn int queue_merge(struct queue ** lhs, struct queue * rhs)
\brief Merge the right-hand side to the left-hand side.

\param lhs The queue, which is extended.
\param the The queue with which to extend the left-hand side.
*/
int queue_merge(struct queue ** lhs, struct queue * rhs);

#endif /* end of include guard: _C_STD_LIB_QUEUE_H_ */
