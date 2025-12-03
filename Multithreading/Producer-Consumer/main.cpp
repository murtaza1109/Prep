#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
int max_buffer_size = 5;


struct Node {
    int data;
    Node *next;

    Node(int data_) : data(data_), next(nullptr) {}
};

class List {

public:
    List() : head(nullptr) , tail(nullptr) , m_size(0)
    {

    }
    ~List()
    {

    }
    void push(Node *newNode)
    {
        if(!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        ++m_size;
    }

    int front()
    {
        if(!head)
        {
            throw std::runtime_error("front() on empty list");
        }
        return head->data;
    }

    void pop()
    {
        if(!head) return;

        Node* old = head;

        head = head->next;

        if(!head) tail = nullptr;

        delete old;
        --m_size;
    }

    int size()
    {
        return m_size;
    }

    bool empty()
    {
        return (m_size == 0);
    }

private:
    Node* head;
    Node* tail;
    int m_size;
};

List myList;

void producer()
{
    int value = 0;
    while(true)
    {
        unique_lock<mutex> lock(mtx);


        cv.wait(lock,[]{return myList.size()<max_buffer_size;});
        myList.push(new Node(value));
        cout << "Produced data " << value << endl;

        value++;

        lock.unlock();
        cv.notify_all();
        this_thread::sleep_for(chrono::milliseconds(5000));
    }
}

void consumer()
{
    while(true)
    {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock,[]{return !myList.empty();});
        int value = myList.front();
        myList.pop();

        cout << "Consumed data " << value << endl;

        lock.unlock();
        cv.notify_all();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main()
{
    thread p(producer);
    thread c(consumer);

    p.join();
    c.join();

    return 0;
}
