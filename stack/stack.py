# Stack DSA implementation using lists in Python

# Stack class
class Stack:
    # Create an empty stack at the beginning
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
        print(f'The pushed element: {element}')

    # Pop the top element from the stack
    def pop_element(self):
        # Check if the stack is empty
        if (self.is_empty()):
            print('The stack is empty!')
            return
        # otherwise pop the top element
        return self.stack.pop()


if __name__ == '__main__':
    # Instantiate the stack class by creating a new object
    st = Stack()
    st.push_element(5)
    st.push_element(50)
    st.push_element(60)
    st.push_element(70)
    st.push_element(80)
    print(st.stack)
    print(st.pop_element())
    print(st.pop_element())
    print(st.pop_element())
    print(st.pop_element())
    print(st.pop_element())
    print(st.pop_element())
    print(st.stack)
