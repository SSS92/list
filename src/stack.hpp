#ifndef STACK_HPP
#define STACK_HPP
#include <list.hpp>

class Stack: private List
{
    public:
        
        /**
         * @brief default constructor
         */
        Stack();
      
        /**
         * @brief overloaded constructor
         * @detail creates a stack with one element that has the given
         *	    value
         */
        Stack(int v);

        /**
         * @brief deletes the element on the top of the stack
         * @return int value of the element that has been deleted
         */
        int pop();

        /**
         * @brief add an element with value v to the top of the stack
         */
        bool push(int v);

        /**
         * @brief returns the value of the element on the top of the
         *	    stack wthout deleting it
         * @return int value of the element on the top, if the element
         *	    exists, INT_MAX otherwise
         */
        int peek (unsigned int i) const;

        /**
         * @brief checks if the stack is empty
         * @return true if stack is empty, false otherwise
         */
        bool is_empty() const;

        /**
         * @brief removes all elements from the stack
         * @return true of operation was sccessful, false otherwise
         */
        bool clear();
        
        /**
         * @brief print the stack
         */
        void print() const;
};

#endif
