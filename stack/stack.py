# Implementation of the stack DSA in Python using lists

class Stack:
    stack = []

    # Methods

    # Check if the stack is empty
    def is_empty(self):
        if len(self.stack) == 0:
            return True
        else:
            return False

    # Push a new element onto the stack
    def push_element(self, element):
        self.stack.append(element)
        print(f'The pushed element {element}')

    # Pop from the stack
    def pop_element(self):
        # Check if the stack is empty
        if (self.is_empty()):
            print('The stack is empty')
            return
        return self.stack.pop()


if __name__ == '__main__':
    # Instantiate the stack class
    s = Stack()
    s.push_element(50)
    s.push_element(60)
    s.push_element(80)
    s.push_element(90)
    print(s.stack)
    print(s.pop_element())
    print(s.pop_element())
    print(s.pop_element())
    print(s.pop_element())
    print(s.pop_element())
    print(s.stack)
