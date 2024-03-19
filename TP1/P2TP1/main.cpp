#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Queue.h"
#include "Stack.h"
#include "List.h"

template<typename T, typename Y>
concept insertable = requires (T x, Y y) {
    x.insert(y);
};

void seedRand();
int getRandomQuantity();
Queue<float>* createQueue(int quantity);
Stack<float>* createStack(int quantity);
List<float>* generateList(Queue<float>* queue, Stack<float>* stack);
void showList(List<float>* list);

int main()
{
    seedRand();

    int queueQuantity = getRandomQuantity();
    int stackQuantity = getRandomQuantity();

    Queue<float>* queue = createQueue(queueQuantity);
    Stack<float>* stack = createStack(stackQuantity);

    List<float>* list = generateList(queue, stack);

    showList(list);

    delete queue;
    delete stack;
    delete list;
}

void seedRand() {
    srand(time(nullptr));
}

int getRandomQuantity() {
    return 5 + (rand() % 5);
}

float getRandomNumber() {
    // Los hago hasta centenas para que no sean tantos
    return static_cast<float>((rand() % 10000)) / 100.0f;
}

Queue<float>* createQueue(int quantity) {
    std::cout << "CREANDO QUEUE" << std::endl;

    Queue<float>* queue = new Queue<float>();

    for (int i = 0; i < quantity; i++) {
        float randomNumber = getRandomNumber();
        std::cout << "QUEUEING: " << randomNumber << std::endl;

        queue->enqueue(randomNumber);
    }

    std::cout << std::endl;
    return queue;
}

Stack<float>* createStack(int quantity) {
    std::cout << "CREANDO STACK" << std::endl;
    Stack<float>* stack = new Stack<float>();

    for (int i = 0; i < quantity; i++) {
        float randomNumber = getRandomNumber();
        std::cout << "PUSHING: " << randomNumber << std::endl;

        stack->push(randomNumber);
    }

    std::cout << std::endl;
    return stack;
}

void setNumberOrderedInList(List<float>* list, float number) {
    for (int i = 0; i < list->getCount(); i++) {
        if (list->at(i) > number) {
            list->insert(number, i);
            return;
        }
    }
    list->insert(number, list->getCount());
}

List<float>* generateList(Queue<float>* queue, Stack<float>* stack) {
    List<float>* list = new List<float>();
    int queueCount = queue->getCount();
    int stackCount = stack->getCount();

    for (int i = 0; i < queueCount; i++) {
        setNumberOrderedInList(list, queue->dequeue());
    }

    for (int i = 0; i < stackCount; i++) {
        setNumberOrderedInList(list, stack->pop());
    }

    return list;
};

void showList(List<float>* list) {
    std::cout << "LISTA: " << std::endl;

    for (int i = 0; i < list->getCount(); i++) {
        std::cout << list->at(i) << std::endl;
    }
}
