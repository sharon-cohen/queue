#pragma once

template <class T>
class Node
{
public:
    Node()			: _next(NULL),_data(NULL) {}
    Node(T* data)	: _data(data), _next(NULL) {}
    ~Node()			{ delete _data; delete _next; }

public:
    Node<T>*	next() const { return _next; }
    T*			data() const { return _data; }
    void		setNext(Node<T>* next) { _next = next; }
    void		setData(T* data) { _data = data; }

private:
    Node<T>*	_next;
    T*			_data;
};