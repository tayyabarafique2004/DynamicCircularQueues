#include<iostream>
using namespace std;
class CircularQueue
{
private:
	int front;
	int rear;
	int* items;
	int size;
public:
	CircularQueue(int s)
	{
		size = s;
		front = -1;
		rear = -1;
		items = new int[size];
	}
	bool enqueue(int element)
	{
		if ((front == 0 && rear == size-1 )|| (front == rear +1))//to check whether queue is full
		{
			cout << "Queue is full"<<endl;
			return false;
		}
		else if (front == -1)// first element to push
		{
			front = rear = 0;
			items[rear] = element;
		}
		else if (rear == size - 1 && front != 0)//to maintain cyclic nature
		{
			rear = 0;
			items[rear] = element;
		}
		else//normal flow
		{
			rear++;
			items[rear] = element;
		}
		return true;
	}
	int dequeue()
	{
		if (front == -1)// to  check queue is empty
		{
			cout << "Queue is Empty"<<endl;
			return -1;

		}
		int ans = items[front];
		items[front] = -1;
	    if (front == rear)// single element is present remove that element by intiliazing front and rear to -1
		{
			front = rear = -1; 
			return ans;

		}
		if (front == size - 1)//to maintain cyclic nature 
		{
			front = 0; 
	    }
		
		 else
		 {
			 front++;
		 }
		return ans;
	}

	~CircularQueue() {
		delete[] items; 
	}
	
};


int main()
{
	int size;
	cout << "Enter a positive integer for size of Queue: " << endl;
	while (!(cin >> size))
	{
		cout << "Error: Enter a valid input: " << endl;
		cin.clear();
		cin.ignore(123, '\n');
	}
	
	CircularQueue Q(size);

	Q.enqueue(12);
	Q.enqueue(12);
	Q.enqueue(12);
	Q.enqueue(12);
	Q.enqueue(12);
	cout << "dequeued: " << Q.dequeue()<<endl;
	cout << "dequeued: " << Q.dequeue() << endl;
	cout << "dequeued: " << Q.dequeue() << endl;
	Q.enqueue(12);
	Q.enqueue(12);
	Q.enqueue(12);
	Q.enqueue(12);
	Q.enqueue(12);
	Q.enqueue(12);
	Q.enqueue(12);
	Q.enqueue(12);
	Q.enqueue(12);



	return 0;
}