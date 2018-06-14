/**
 *@brief Node stores integer value and pointers 
         to the previous and next node
 */
class Node
{
    public:
        int value;
        Node* next;
        Node* previous;
        
        Node(int v = 0);
        ~Node();
};

/**
 *@brief List consisting of a collection of nodes 
         which together represent a sequence
 */
class List
{
    private:
        Node* first;
        Node* last;
        unsigned int count;
        
        bool is_out_of_list(unsigned int i) const;
        
        Node* get_node(unsigned int i) const;
         
        void add_to_end(int v);

        void add_to_start(int v); 

    public:
        /**
         *@brief List's default constructor,
         initializes all members with 0
         */
        List(); 

        /**
         *@brief Creates new node which initialized by given value,
         and initialize List with created node.
         @param value to init node
         */ 
        List(int v);

        /**
         *@brief List's default constructor
         */ 
        List(const List& l);
        
        /**
         *@brief Adds new node(initialized by second param) to the list
         by index, if index is > than count: index = count
         *@param index where will be added a new node
         *@param value to init new node
         *@return true - if a new node added successfuly,
         false - otherwise
         */
        bool add(unsigned int i, int v);

        /**
         *@brief Removes a node from list by index
         *@param index of element which will be remove
         *@return true if index is valid, false otherwise
         */
        bool remove(unsigned int i);

        /**
         *@brief Returns an first element index which value
         is equal to param, if doesn't exist returns -1
         *@param value to search element
         *@return -1 - if not found, index of the element otherwise 
         */
        int search_by_value(int v) const;

        /**
         *@brief Returns element value by index
         *@param element index
         *@return element value
         */
        int search_by_index(unsigned int i) const;

        /**
         *@brief set value of element by given index
         *@param index of element
         *@param new value of an element
         *@return false - if out of list, true otherwise
         */
        bool set_value(unsigned int i, int v);

        /**
         *@brief Returns List's size
         *@return list's size
         */
        int get_size() const;

        /**
         *@brief Prints the list 
         */
        void print() const;

        /**
         *@brief swap elements by given indexes
         *@param first element index
         *@param second element index
         *@return false - at least one of indexes is out of list
         */
        bool swap(unsigned int i, unsigned int j);

        /**
         *@brief Assingment operator for List type
          *@param List type element
          *@return returns an address of List type element
          */
         List& operator=(const List& l);

         /**
          *@brief Deletes all allocated memories
          */
         ~List();

};
