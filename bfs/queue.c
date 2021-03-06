    #include "queue.h"

p_queue newQueue(int queueSize)
{
    p_queue queue = malloc(sizeof(Queue));
    if (queue == NULL)
        exit(1);

    queue->list = calloc(queueSize, sizeof(p_node));
    if (queue->list == NULL)
        exit(1);
    
    queue->n = queueSize;
    queue->size = 0;
    queue->begin = 0;
    queue->end = 0;

    return queue;
}


void push(p_queue queue, p_node item)
{
    queue->list[queue->end] = item;
    queue->end = (queue->end + 1) % queue->n;
    queue->size++;
}


p_node pop(p_queue queue)
{
    p_node item = queue->list[queue->begin];
    queue->begin = (queue->begin + 1) %  queue->n;
    queue->size--;
    
    return item;
}


int isEmpty(p_queue queue)
{
    if (queue->size == 0)
        return 1;
    
    return 0;
}


void removeQueue(p_queue queue)
{
    for (int i = 0; i < queue->size; i++) {
        if (queue->list[i] == NULL)
            free(queue->list[i]);
    }
    free(queue->list);
    free(queue);
}

