#include "Node.h"

template <class T>
void MySwap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

template <class Iterator, class Comparator>
void MySort(Iterator begin, Iterator end, Comparator cmp)
{
    for (Iterator p = begin; p != end; ++p)
        for (Iterator t = begin; t != p; ++t)
            if (cmp(*t, *p))
                MySwap(*t, *p);
}

template <class T, class Comparator>
class PriorityQueue
{
public:
    PriorityQueue() : _head(NULL), _tail(NULL) {}
    ~PriorityQueue() { delete _head; }
    
	/*Inner Class Iterator*/
    class Iterator
    {
    public:
        Iterator(Node<T>* p) : _p(p) {}

	public:
        Iterator& operator ++ (int)
        {
            if (_p)
                _p = _p->next();
            return *this;
        }

        Iterator& operator ++ ()
        {
            if (_p)
                _p = _p->next();
            return *this;
        }

        bool operator != (const Iterator& it) const { return _p != it._p; }
        
        T& operator * () const
        {
            if (!_p || !(_p->data()))
                throw "Null Pointer Exception";

			return *(_p->data());
        }

    private:
        Node<T>* _p;
    };

    void enqueue(const T& item)
    {
        Node<T>* newNode = new Node<T>(new T(item));
        if (!_head)
            _head = newNode;
        else
            _tail->setNext(newNode);

        _tail = newNode;
        
        // The queue may not be ordered by now, sort it.
        MySort(begin(), end(), Comparator());
    }

    void dequeue(void)
    {
        if (isEmpty())
            throw "Empty Queue Exception";

        Node<T>* temp = _head;
        _head = _head->next();
        temp->setNext(NULL);

        delete temp;
    }

    bool isEmpty() const { return !_head; }
    
    const T& top (void) const
    {
        if (isEmpty())
            throw "Empty Queue Exception";

        return *(_head->data());
    }
    
    Iterator begin() const { return _head; }
    Iterator end() const { return _tail->next(); }

private:
    Node<T>* _head;
    Node<T>* _tail;
};