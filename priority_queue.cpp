#include <iostream>
#include <string>
#include <limits>
#include <vector>
using namespace std;


//
// CLASS:  NODE 
//

    class Node{
      public:
        int value = 0;           // our node holds an integer
        Node *next = nullptr;    // our node has a pointer to the next Node

        Node(int i){             // contructor for our Node class
          value = i;                // store a copy of argument "i" in "value"
          next = nullptr;           // be sure next Node is null
        }
    }; // end class definition for Node


//
// CLASS:  MAX PRIORITY QUEUE
//


class MaxPriorityQueueLinkedList{
  private:
    Node *head = nullptr;
    int currentSize = 0; // # of items in the heap, also next avaialble stack position

  public:
    MaxPriorityQueueLinkedList(){ // constructor
      //cout << "Created new Max Priority Queue." << endl;
      currentSize = 0;
      head = nullptr;
    }


  //
  // PUSH - push a new Node instance into the Priority Queue
  //

    void push(int i){

      Node *temp = new Node(i); // create a node with i as the value
      temp->next = head; 
      head = temp; 
      currentSize++;
      // TODO: write your implementation of push here
      // don't forget to manage the "currentSize" value
      
    } // end push()

  //
  // POP - remove an existing Node instance with the largest value from the Priority Queue
  //

    int pop(){ // remove the Node with the largest value from the PQ
      if(isEmpty())
        return -1;
  
    Node * next = head;
    Node * beforeLargest = nullptr;
    Node * largestValue = next;
     
    while(next->next != nullptr){
        if(largestValue->value < next->next->value)
        {
          largestValue = next->next;
          beforeLargest = next;
        }
        next = next->next;
    }

    int val = largestValue->value;
    if(beforeLargest == nullptr)
    {
      head = head->next;
    }else{
      beforeLargest->next = largestValue->next; 
      delete largestValue;
    }
    currentSize--;
    return val;
      // TODO: 
      // Write your implementation of pop here
      // You will need to search the queue rooted at "head" to find the largest value
      // Don't forget to manage the "currentSize" value when you pop the Node
      // Don't forget to return -1 if your queue is empty
      // Otherwise you must return the value of the item you just popped (don't return the Node)
      // Don't forget to delete the Node you pop before returning, like:
      //      Node *temp;   // declaration of a pointer to the node that you be deleting
      //      delete temp;  // deletes the Node pointed to by "temp"
      //      
       
      //return largestValue->value;    // TODO: you must change this
    } // end pop()

 //
 // IS EMPTY
 //

    bool isEmpty(){
      // TODO:
      // Return true if the queue is empty, else false
      if(head == nullptr)
        return true;
      return false; 
      // TODO: you must change this! :)
    }

 //
 // GET SIZE
 //

    int getSize(){
      // Return the current size of the Max Priority Queue (how many nodes does it have?)
      return currentSize;  // TODO: you must change this! :)
    }

  //
  // PRINT QUEUE
  //

    void print(){

      if (isEmpty()){
        cout << "printQueue(): Max Prirority Queue is empty" << endl;
        return;
      }

      cout << "print(Current Size: " << currentSize << "): ";

      Node * next = head;
      while(next != nullptr){
          cout << next->value << ", ";
          next = next->next;
      }
      cout << endl;
    } // end print()


};  // end definition of MAX PRIORITY QUEUE CLASS


//
// TEST ME - this routine will test your program and grade your submission
//

  void testMe() {

    MaxPriorityQueueLinkedList mpq; // create an instance of a Max Priority Queue

    int totalScore = 0;

    cout << "------------------------------" << endl;
    cout << "        TESTING HW" << endl;
    cout << "------------------------------" << endl;



    bool isEmptyOk = true;     // ismEmpty() working: 5 points
    bool getSizeOk = true;     // getSize() working: 5 points

    if (!mpq.isEmpty()) {
      cout << "testMe() ERROR: isEmpty() returned false on a new Priority Queue, when it should have returned true." << endl; 
      isEmptyOk = false;
    }

    mpq.push(1);

    if (mpq.isEmpty()) {
      cout << "testMe() ERROR: isEmpty() returned true on a Priority Queue with one pushed item, when it should have returned false." << endl; 
      isEmptyOk = false;
    }

    mpq.push(2);

    if (mpq.getSize() != 2) {
      cout << "testMe() ERROR: getSize() did not return a value of 2 for a Priority Queue with two pushed items." << endl; 
      getSizeOk = false;
    }

    mpq.pop(); // now we should have 1 item

    if (mpq.getSize() != 1) {
      cout << "testMe() ERROR: getSize() did not return a value of 1 for a Priority Queue with one item after a pop." << endl; 
      getSizeOk = false;
    }

    mpq.pop(); // now we should have zero items

    if (mpq.getSize() != 0) {
      cout << "testMe() ERROR: getSize() did not return a value of 0 for a Priority Queue with zero items after a pop." << endl; 
      getSizeOk = false;
    }

    if (!mpq.isEmpty()) {
      cout << "testMe() ERROR: isEmpty() did not return a value of true for a Priority Queue with zero items after a pop." << endl; 
      isEmptyOk = false;
    }


    if (isEmptyOk) {
      cout << "testMe() isEmpty() looks good.  +5 points" << endl; 
      totalScore += 5;
    }

    if (getSizeOk) {
      cout << "testMe() getSize() looks good.  +5 points" << endl; 
      totalScore += 5;
    }


    //
    // TEST POP A
    //

    cout << "testMe() Pop Test A: Testing push(1), pop() with new queue..." << endl;

    {
      MaxPriorityQueueLinkedList mpq; // create an instance of a Max Priority Queue
      mpq.push(1); 
      int num = mpq.pop();

      if (num != 1){
        cout << "testMe() testMe() ERROR: pop() did not return a value of 1 after a push(1)." << endl; 
        //exit(-1);
      }
      else {
        cout << "         Pop Test A: looks good.  +10 of 10 possible points" << endl;
        totalScore += 10; // push/pop working for simple test
      }
    }



    //
    // TEST POP B
    //

    {
      cout << "testMe() Pop Test B: Testing push(1), push(2),pop() with new queue..." << endl;
      MaxPriorityQueueLinkedList mpq; // create an instance of a Max Priority Queue
      mpq.push(1); 
      mpq.push(2);
      int num = mpq.pop();
      if (num != 2){
        cout << "testMe() ERROR: pop() did not return a value of 2 after a push(1), push(2), pop()." << endl; 
         cout << "         Pop Test B failed.  0 of 10 possible points" << endl;
      }
      else {
        cout << "         Pop Test B: looks good.  +10 of 10 possible points" << endl;
        totalScore +=10; // push/pop working for simple test
      }

    }

    //
    // TEST POP C
    //

    {
      cout << "testMe() Pop Test C: Testing pop() on empty queue == -1..." << endl;
      MaxPriorityQueueLinkedList mpq; // create an instance of a Max Priority Queue

      int num = mpq.pop();
      if (num != -1){
        cout << "testMe() ERROR: pop() did not return a value of -1 on an empty queue" << endl; 
         cout << "         Pop Test C failed.  0 of 5 possible points" << endl;
      }
      else {
        cout << "         Pop Test C: looks good.  +5 of 5 possible points" << endl;
        totalScore +=5; // push/pop working for simple test
      }

    }

    //
    // TEST PUSH N / POP N
    //

    {

      cout << "testMe() Push N/Pop N: Testing N pushes and N pops with new queue..." << endl;
      MaxPriorityQueueLinkedList mpq; // create an instance of a Max Priority Queue
      bool finishedOk = true;
      int maxCount = 10;
      for(int i=0; i<maxCount; i++) mpq.push(i); // load up a bunch of values
      for(int i=0; i<maxCount; i++) {
        if (mpq.isEmpty()){
          cout << "         ERROR: isEmpty() returned true too soon. " << endl;
          finishedOk = false;
          break;
        }
        mpq.pop();
      }

      if (finishedOk) {
          cout << "         Push N/Pop N looks good.  +10 of 10 possible points" << endl;
          totalScore += 10;
      }
      else
         cout << "         Push N/Pop N failed.  0 of 10 possible points" << endl;

    }

    //
    // STRESS TEST
    //
    
    {
        int maxCount = 1000;
        cout << "testMe() Stress test: Pushing and Popping randomly " << maxCount << "  times..." << endl;
        MaxPriorityQueueLinkedList mpq; // create an instance of a Max Priority Queue
    
      // random push/pop test
      srand(time(NULL));
      //vector<int> v; // a vector of integers

      int myCount = 0;
      for(int i=0; i<maxCount; i++){
        int rnum = rand()%maxCount*2-maxCount; // goes from approx -maxCount to maxCount
        if (rnum<0){ // pop a value
          int returnValue = mpq.pop();
          if (returnValue >=0)
            myCount--; // decrement our counter; else it was already empty
        }
        else { // push a avlue
           mpq.push(rnum); // push the random value
           myCount++; // increment our counter
        }
      }

      if (myCount != mpq.getSize()) {
        cout << "         ERROR: test count " << myCount << " does not match mpq getSize() of " << mpq.getSize() << endl;
         cout << "         Stress Test failed.  0 of 10 possible points" << endl;
      }
      else {
        totalScore += 10; // stress test ok
        cout << "         Stress Test looks good.  +10 of 10 possible points" << endl;
      }
    }

    //
    // SORT TEST
    //

    {
      int maxCount = 1000;
      cout << "testMe() Sort test: Pushing " << maxCount << "  times, then popping " << maxCount << " times.. should produce a descending sorted list... " << endl;
      MaxPriorityQueueLinkedList mpq; // create an instance of a Max Priority Queue
    
      bool isDescending = true;


      // random push/pop test
      srand(time(NULL));
      vector<int> v; // a vector of integers
      int myCount = 0;
      for(int i=0; i<maxCount; i++){
        int rnum = rand()%maxCount; // goes from approx 0 to maxCount-1
        mpq.push(rnum); // push the random value
        myCount++; // increment our counter
        if (myCount != mpq.getSize())
          isDescending = false;
      }


      int lastValue = INT32_MAX; // big positive value
      cout << "         checking descending... " << endl;

      for(int i=0; i<maxCount; i++){
        int popValue = mpq.pop();
        if (popValue < 0) {
          cout << "         Error: sort test failed... ran out of values to pop" << endl;
          bool isDescending = false;
          break;
        }

        if (popValue > lastValue){
          cout <<          "Error: sort test failed... " << lastValue << " should be >= " << popValue << endl;
          bool isDescending = false; // values are not being returned from largest to smallest
          break;
        }
        lastValue = popValue; // save for next loop iteration
      }

      if (!isDescending) {
        cout << "         Error: sort test failed... Your pop() does not appear to be removing values  " << endl;
        cout << "         Sort Test failed.  0 of 25 possible points" << endl;
      }
      else {
        totalScore += 25;
        cout << "         Sort Test Looks good.  +25 of 25 possible points" << endl;
      }

        cout << "         Done with sort test" << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "testMe()  DONE! Your preliminary score is: " << totalScore << " out of 80 points" << endl;
    cout << "-----------------------------------------------------------" << endl;



  } // end testMe()


//
// Get an integer from input (until success)
// (this function does a bit of extra work to avoid input errors)
//

    int getIntegerInput(){
      int num; 
      cin>>num;     // try to get an integer

      while(true) { // keep trying until we get a good integer
        if(cin.fail()) { // that was not an integer
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
          cout<<"That's not an integer - please try again: ";
          cin>>num;
        }

        if(!cin.fail())  // else if we got the integer, break out of the loop
          break;
      }
      return num; // return the input integer

    } // end getIntegerInput()

//
// MAIN
//


int main() {
  std::cout << "HW Starter: Max Priority Queue using a Linked List\n";
  cout << "Enter any positive number to push it, or enter a negative value to pop the max value (then hit return) " << endl;

 // test mode below - uncomment when you want to see your grade

      testMe();          // TODO: uncomment this when you are ready to test

 // interactive mode below
 
  MaxPriorityQueueLinkedList mpq; // create an instance of a Max Priority Queue

  // "mpq" is the instance of our Max Priority Queue
  // now we can fill or empty it by pushing and popping

  while( true ){ // loop forever

    int num;
    cout << "Enter an integer value: ";
    num = getIntegerInput(); // get an integer from input until success

    if (num < 0 ){
      if (!mpq.isEmpty())
        cout << "Popped " << mpq.pop() << endl; // pop the max value from the mp queue
      else
        cout << "Sorry - Max Priority Queue is empty. Please push a positive value first." << endl;
    }
    else
     mpq.push(num); // push num into the max priority queue

    mpq.print(); // print contents of the max priority queue

  }
}

