#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <list.hpp>


class Queue: private List
{
	public:
	
	    /**
		 * @brief default constructor
		 */
		Queue();
		
		/**
		 * @brief overloaded constructor
		 * @detail creates a stack with one element that has the 
		 *	    given value
		 */
		Queue(int);
		
		/**
		 * @brief adds the given element to the queue
		 * @param int the value
		 * @return void
		 */
		bool push(int);
		
		/**
		 * @brief removes the first element of the queue and returns
		 *	    the value
		 *@return returnes the value of the last elemenet if exists,
		 *	    INT_MAX otherwise
		 */
		int pop();
		
		/**
		 * @brief deletes all the memebers of the queue
		 * return void;
		 */
		 bool clear();
		
		/**
		 * @brief returnes the fisrt element of the queue;
		 * @return returnes the first element of the queue if exists
		 *	    INT_MAX otherwise
		 */
		int front() const;
		
		/**
		 * @brief returnes the last element of the queue;
		 * @return returnes the last element of the queue if exists
		 *	    INT_MAX otherwise
		 */
		int back() const;
		
		/**
		 * @brief returnes the size of the queue;
		 * @return returnes the size of the queue
		 */
		int get_size() const;
		
		/**
		 * @brief checks if the queue is empty
		 * @return true if the queue is empty, false otherwise
		 */
		bool is_empty() const;
		
		/**
		 * @brief prints the queue
		 */
		void print() const;
};

#endif
