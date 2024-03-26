/* Queue DSA implementation using linked lists in JavaScript */

/* Node class */
class Node {
    // Constructor
    constructor(data) {
        this.data = data;
        this.next = null;
    } 
}

/* Queue class */
class Queue {
    // Constructor
    constructor() {
        this.front = null;
        this.rear = null;
    }
    /* Methods */

    // Enqueue
    enqueue(data) {
        // Create a new node for the queue
        let newNode = new Node(data);
        // Check if the queue is empty, assign the new node to front and rear
        if (!this.front) {
            this.front = this.rear = newNode;
            return;
        }
        // Point the new node to null since it's going to be inserted at the back of the queue
        newNode.next = null;
        // Shift the front pointer to the new node
        this.rear.next = newNode;
        this.rear = newNode;

    }
    // Dequeue
    dequeue() {
        // If the queue is empty, return
        if (!this.front) {
            console.log(`The queue is empty!`);
            return;
        }
        // otherwise, shift the front pointer to the next node and delete the previous node
        let temp;
        temp = this.front;
        this.front = this.front.next;
        temp = null;
        // If fron is equal to null, reset the queue
        if (!this.front) {
            this.front = this.rear = null;
        }
    }
    // Print the queue
    printQueue() {
        // Traverse the whole queue starting at the beginning and print values of every node on each iteration
        let temp = this.front;
        while (temp) {
            console.log(temp.data);
            temp = temp.next;
        }
    }
}

// Instantiate the queue class
let q = new Queue();
q.enqueue(5);
q.enqueue(10);
q.enqueue(25);
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
q.printQueue();

