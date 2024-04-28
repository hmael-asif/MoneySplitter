#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

#define sizeOfStack 1000

//integer type stack
class intstack{
    int top;
    int* arr;
    
    public:
    intstack(){
        top=-1;
        arr=new int[sizeOfStack];
    }
    
    void push(int x){
        if(top==sizeOfStack-1){
            cout<<"stack overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    
    int pop(){
        if(top==-1){
            cout<<"stack underflow"<<endl;
            return -1;
        }
        
        int temp=arr[top];
        top--;
        return temp;
    }
    
    int peek(){
        return arr[top];
    }
    
    bool isEmpty(){
        return top==-1;
    }
    
    bool isFull(){
        return top==sizeOfStack-1;
    }
    
    void display(){
        int i=top;
        while(i!=-1){
            cout<<arr[i]<<" ";
            i--;
        }
        cout<<endl;
    }
    
};

//string type stack: used for viewing already expenses
//string concatenation so sentences were pushed into stack of who u paid what amount for what event
class StringStack {
    int top;
    string* arr;

public:
    StringStack() {
        top = -1;
        arr = new string[sizeOfStack];
    }

    void push(const string& str) {
        if (top == sizeOfStack - 1) {
            cout << "stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = str;
    }

    string pop() {
        if (top == -1) {
            cout << "stack underflow" << endl;
            return "";
        }

        string temp = arr[top];
        top--;
        return temp;
    }

    string peek() const {
        return (top != -1) ? arr[top] : "";
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == sizeOfStack - 1;
    }

    void display() const {
        int i = top;
        while (i != -1) {
            cout << arr[i] << " ";
            i--;
        }
        cout << endl;
    }

    ~StringStack() {
        delete[] arr;
    }
};


class strNode{
    public:
    string data;
    strNode* next;

    strNode(){
        data="";
        next=NULL;
    }

    strNode(string Data){
        data=Data;
        next=NULL;
    }
};

class strLL{
    public:
    strNode *head;

    strLL(){
        head=NULL;
    }
    bool empty(){
        return head==NULL;
    }

    void insertHead(string x){ //O(1)
        strNode* temp=new strNode(x);

        if(head==NULL){
            head=temp;
            return;
        }

        temp->next=head;
        head=temp;
        
    }

    void insertTail(string x){ //O(n)
        strNode* temp=new strNode(x);

        if(head==NULL){
            head=temp;
            return;
        }

        strNode* trav=head;

        while(trav->next!=NULL){
            trav=trav->next;
        }

        trav->next=temp;

    }

    void insertAfterArb(string x, string after){ //O(n)
        strNode* temp=new strNode(x);

        if(head==NULL){
            head=temp;
            return;
        }

        strNode* trav=head;

        while(trav->data!=after){
            trav=trav->next;
        }

        temp->next=trav->next;
        trav->next=temp;



    }

    void insertBeforeArb(string x,string before){ //O(n)
        strNode* temp=new strNode(x);

        if(head==NULL){
            head=temp;
            return;
        }

        strNode* trav=head;
        strNode* pred=new strNode;

        while(trav->data!=before){
            pred=trav;
            trav=trav->next;
        }

        pred->next=temp;
        temp->next=trav;
    }

    void delHead(){ //O(1)
        if(head==NULL){
            return;
        }

        if(head->next==NULL){
            head=NULL;
            return;
        }

        strNode* temp=head;
        head=head->next;
        delete temp;

    }

    void delTail(){ //O(n)
        strNode* trav=head;

        while(trav->next->next!=NULL){
            trav=trav->next;
        }

        strNode* temp=new strNode;
        temp=trav->next;
        trav->next=NULL;
        delete temp;
    }

    void delArb(string strToDel){
        strNode* trav=head;
        strNode* trav2=new strNode;

        while(trav->data!=strToDel && trav->next!=NULL){
            trav2=trav;
            trav=trav->next;
        }

        if(trav->data==strToDel){
        trav2->next=trav->next;
        strNode* temp=trav;

        delete temp; }
        

    }
    
    int search(string x){
        strNode* trav=head;
        int count=0;

        while(trav!=NULL){
            if(trav->data==x){
                return count;
            }
            trav=trav->next;
            count++;
        }

        return -1;
    }


    void display(){ //O(n)
        strNode* trav=head;

        while(trav!=NULL){
            cout<<trav->data<<" ";
            trav=trav->next;
        }

        cout<<endl;
    }

    

};

class intNode{
    public:
    int data;
    intNode* next;

    intNode(){
        data=0;
        next=NULL;
    }

    intNode(int Data){
        data=Data;
        next=NULL;
    }
};

class intLL{
    public:
    intNode *head;

    intLL(){
        head=NULL;
    }

    bool empty(){
        return head==NULL;
    }

    void insertHead(int x){ //O(1)
        intNode* temp=new intNode(x);

        if(head==NULL){
            head=temp;
            return;
        }

        temp->next=head;
        head=temp;
        
    }

    void insertTail(int x){ //O(n)
        intNode* temp=new intNode(x);

        if(head==NULL){
            head=temp;
            return;
        }

        intNode* trav=head;

        while(trav->next!=NULL){
            trav=trav->next;
        }

        trav->next=temp;

    }

    void insertAfterArb(int x, int after){ //O(n)
        intNode* temp=new intNode(x);

        if(head==NULL){
            head=temp;
            return;
        }

        intNode* trav=head;

        while(trav->data!=after){
            trav=trav->next;
        }

        temp->next=trav->next;
        trav->next=temp;



    }

    void insertBeforeArb(int x,int before){ //O(n)
        intNode* temp=new intNode(x);

        if(head==NULL){
            head=temp;
            return;
        }

        intNode* trav=head;
        intNode* pred=new intNode;

        while(trav->data!=before){
            pred=trav;
            trav=trav->next;
        }

        pred->next=temp;
        temp->next=trav;
    }

    void delHead(){ //O(1)
        if(head==NULL){
            return;
        }

        if(head->next==NULL){
            head=NULL;
            return;
        }

        intNode* temp=head;
        head=head->next;
        delete temp;

    }

    void delTail(){ //O(n)
        intNode* trav=head;

        while(trav->next->next!=NULL){
            trav=trav->next;
        }

        intNode* temp=new intNode;
        temp=trav->next;
        trav->next=NULL;
        delete temp;
    }

    void delArb(int numToDel){
        intNode* trav=head;
        intNode* trav2=new intNode;

        while(trav->data!=numToDel && trav->next!=NULL){
            trav2=trav;
            trav=trav->next;
        }

        if(trav->data==numToDel){
        trav2->next=trav->next;
        intNode* temp=trav;

        delete temp; }
        

    }
    
    int search(int x){
        intNode* trav=head;
        int count=0;

        while(trav!=NULL){
            if(trav->data==x){
                return count;
            }
            trav=trav->next;
            count++;
        }

        return -1;
    }


    void display(){ //O(n)
        intNode* trav=head;

        while(trav!=NULL){
            cout<<trav->data<<" ";
            trav=trav->next;
        }

        cout<<endl;
    }

    

};

class queue {
    int front;
    int rear;
    int *arr;

public:
    queue() {
        front = -1;
        rear = -1;
        arr = new int[sizeOfStack];
    }

    void Enqueue(int x) {
        if (rear == sizeOfStack - 1) {
            cout << "Queue overflow" << endl;
            return;
        }
        if (front == -1){
            front = 0;}
        rear++;
        arr[rear] = x;
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow" << endl;
            return -1;
        }

        if(front==rear){
            int temp=arr[rear];
            front=-1;
            rear=-1;
            return temp;
        }

        int temp = arr[front];
        front++;
        return temp;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    int peek() {
        if (front == -1 || front > rear) {
            cout << "No elements" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "No elements" << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int size() {
        if (front == -1 || front > rear)
            return 0;
        return (rear - front + 1);
    }
};

class strQueue {
    int front;
    int rear;
    string *arr;

public:
    strQueue() {
        front = -1;
        rear = -1;
        arr = new string[sizeOfStack];
    }

    void Enqueue(string x) {
        if (rear == sizeOfStack - 1) {
            cout << "Queue overflow" << endl;
            return;
        }
        if (front == -1){
            front = 0;}
        rear++;
        arr[rear] = x;
    }

    string dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow" << endl;
            return "";
        }

        if(front==rear){
            string temp=arr[rear];
            front=-1;
            rear=-1;
            return temp;
        }

        string temp = arr[front];
        front++;
        return temp;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    string peek() {
        if (front == -1 || front > rear) {
            cout << "No elements" << endl;
            return "";
        }
        return arr[front];
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "No elements" << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int size() {
        if (front == -1 || front > rear)
            return 0;
        return (rear - front + 1);
    }
};


class NodeOfStrArrays {
public:
    string* arr;
    NodeOfStrArrays* next;

    NodeOfStrArrays(int arraySize) : next(nullptr) {
        arr = new string[arraySize];
    }

    ~NodeOfStrArrays() {
        delete[] arr;
    }
};

class LLofStringArrays {
public:
    NodeOfStrArrays* head;

    LLofStringArrays() : head(nullptr) {}

    // Function to add an array of strings at the end
    void addEnd(const string* strings, int arraySize) {
        NodeOfStrArrays* newNodeOfStrArrays = new NodeOfStrArrays(arraySize);
        for (int i = 0; i < arraySize; ++i) {
            newNodeOfStrArrays->arr[i] = strings[i];
        }

        if (head == nullptr) {
            head = newNodeOfStrArrays;
        } else {
            NodeOfStrArrays* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNodeOfStrArrays;
        }
    }

    // Function to delete the array of strings at the end
    void deleteEnd() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            NodeOfStrArrays* current = head;
            NodeOfStrArrays* prev = nullptr;

            while (current->next != nullptr) {
                prev = current;
                current = current->next;
            }

            delete current;
            prev->next = nullptr;
        }
    }

    // Function to delete the array of strings at a specific index
    void deleteAtIndex(int index) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (index == 0) {
            NodeOfStrArrays* temp = head;
            head = head->next;
            delete temp;
        } else {
            NodeOfStrArrays* current = head;
            NodeOfStrArrays* prev = nullptr;
            int i = 0;

            while (i < index && current->next != nullptr) {
                prev = current;
                current = current->next;
                i++;
            }

            if (i == index) {
                prev->next = current->next;
                delete current;
            } else {
                cout << "Index out of bounds. Cannot delete." << endl;
            }
        }
    }

    // Function to check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Function to display all arrays of strings in the list
    void display() {
        NodeOfStrArrays* current = head;

        while (current != nullptr) {
            for (int i = 0; i < 5; ++i) {  // Assuming a fixed array size of 3 for demonstration
                cout << current->arr[i] << " ";
            }
            cout << endl;
            current = current->next;
        }
    }

    ~LLofStringArrays() {
        while (head != nullptr) {
            NodeOfStrArrays* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


class UserInfo {
    string phoneNum;
    string password;
    string name;
    string userName;

    int totalOwed; 
    int totalOwes;
    int budgetLimit;

    intLL singleOwes; //owes has the money u owe others
    intLL groupOwes;
    intLL singleOwed; //owed has the money others owe u
    intLL groupOwed;

    LLofStringArrays groupNames;
    LLofStringArrays groupAmounts;
    strLL groupEvents;//cuz event for every grp of person is same thats why string of ll 
    //int istrah ka bana ke usmain save krdo
    //aik user by default user 1 ho
    //total owes+=1

    strLL namesSingleOwes; 
    strLL namesSingleOwed;

    strLL eventSingleNameOwes;
    strLL eventSingleNameOwed;


    StringStack paid;  //for marked off as paid 


public:
    UserInfo(){
        budgetLimit=100000000;
        totalOwed=0;
        totalOwes=0;

    }
    
    strQueue remindOwes; //queues for reminders.: sentence push w event, name and amt w string concat
    strQueue remindOwed;
    
    void setPhoneNum(string pn){
        int digits=pn.length();

        if(digits==11 || digits==12){
            phoneNum=pn;
        }
        else{
            cout<<"Invalid number. Number must be 11 or 12 digits long. "<<endl;
            cout<<"re-enter number: ";
            cin>>pn;
            setPhoneNum(pn);
        }
    }

    void setName(string Name) {
        name = Name;
    }

    void setPassword(string pass) {
        password = pass;
    }

    void setUserName(string un) {
        userName = un;
    }
    
    void setBudgetLimit(int b){
        budgetLimit=b;
    }

    string getUserName(){
        return userName;
    }

    void modify(){
        cout<<"What would you like to modify? \n(1)Name \n(2)Username \n(3)Password \n(4)Phone number"<<endl;
        int choice;
        cin>>choice;

        if(choice==1){
            cout<<"Enter your new name: ";
            string n;
            cin>>n;
            name=n;
        }

        else if(choice==2){
            cout<<"Enter your new username: ";
            string un;
            cin>>un;
            userName=un;
        }

        else if(choice==3){
            cout<<"Enter your old password: ";
            string pw;
            cin>>pw;
            if(pw!=password){
                cout<<"Password entered is incorrect. You cannot change the new password. ";
                return;
            }
            
            cout<<"Enter new password: "<<endl;
            cin>>pw;
            password=pw;

        }

        else if(choice==4){
            string n;
            cout<<"Enter new phone number ";
            cin>>n;
            setPhoneNum(n);
        }
    }
   
    void Display_Account_Details(){
        cout<<"Name: "<<name<<endl;
        cout<<"Phone number: "<<phoneNum<<endl;
        cout<<"Username: "<<userName<<endl;
        cout<<"Password: "<<password<<endl;
    }

    bool validateLogin(string enteredUsername, string enteredPassword) {
        return (enteredUsername == userName && enteredPassword == password);
    }

    void splitWithOnePerson(){
        cout<<"splitting between 2 people: "<<endl;
        cout<<"choose an option: "<<endl;
        cout<< "(1) Friend1 paid and friend2 owes the full amount to friend1 (you) \n(2) Friend2 paid and friend1 owes the full amount to friend2 \n";
        cout<<"(3) Friend1 paid and after splitting equally, friend2 owes half the amount to friend1 \n(4) Friend2 paid and after splitting equally, friend1 owes half the amount to friend2 \n(5) exit " <<endl;

        int choice;
        cin>>choice;

        while(choice!=5){
            cout<<"enter event name: ";
            string ev;
            cin>>ev;

            if(choice==1 || choice==3){
                eventSingleNameOwed.insertTail(ev);
            }
            else if(choice==2 || choice==4){
                eventSingleNameOwes.insertTail(ev);
            }
            else{
                cout<<"Invalid input"<<endl;
                return;
            }

            int amt;

            bool validInput = false;

    // Continuously prompt until valid input is provided
            while (!validInput) {
                validInput = true;
                cout << "What was the total amount? ";
                string input;
                cin >> input;

                // Convert input to integer
                for (char c : input) {
                    if (!isdigit(c)) {
                        validInput = false;
                        break;
                    }
                }

                if (validInput) {
                    amt = stoi(input);
                    
                    // Check if the entered amount is negative
                    if (amt < 0) {
                        validInput = false;
                    }
                }

                if (!validInput) {
                    cout << "Invalid input. Please enter a valid non-negative integer." << endl;
                }
    }

            if(amt>budgetLimit){
                        cout<<"You are exceeding your budget limit."<<endl;
                        cout<<"Would you like to continue anyways? (1)Yes (2)No";
                        int choices;
                        cin>>choices;
                        if(choices==2){
                           cout<<"Good job! Returning back now."<<endl;
                           return; 
                        }
                    }



            

            cout<<"what is the name of ur friend? ";
            string name;
            cin>>name;

            

        //namesSingleOwes; 
    
            
        if(choice==1){
            cout<<name<< " owes you "<<amt<<endl;
            string r=name+" owes you " + to_string(amt); //str conc
            remindOwed.Enqueue(r);  //sentences in reminders
            singleOwed.insertTail(amt);
            namesSingleOwed.insertTail(name);
            totalOwed+=amt;

        }

        else if(choice==2){
            cout<<"You owe "<< name<<" "<<amt<<endl;
            string r="You owe "+name+" "+to_string(amt);
            remindOwes.Enqueue(r);
            singleOwes.insertTail(amt);
            namesSingleOwes.insertTail(name);
            totalOwes+=amt;
        }

        else if(choice==3){
            cout<<name<< " owes you "<<amt/2<<endl;
            string r=name+" owes you " + to_string(amt/2);
            remindOwed.Enqueue(r);
            singleOwed.insertTail(amt/2);
            namesSingleOwed.insertTail(name);
            totalOwed+=amt/2;
        }
        else if(choice==4){
            cout<<"you owe "<< name<<" "<<amt/2<<endl; 
            string r="You owe "+name+" "+to_string(amt/2);
            remindOwes.Enqueue(r);
            singleOwes.insertTail(amt/2);
            namesSingleOwes.insertTail(name);
            totalOwes+=amt/2;
        }
        else if(choice==5){
            cout<<"Good bye"<<endl;
            break;
        }
        else{
            cout<<"invalid choice";
        }

        cout<<"choose an option: "<<endl;
        cout<< "(1) Friend1 paid and friend2 owes the full amount to friend1 \n(2) Friend2 paid and friend1 owes the full amount to friend2 \n";
        cout<<"(3) Friend1 paid and after splitting equally, friend2 owes half the amount to friend1 \n(4) Friend2 paid and after splitting equally, friend1 owes half the amount to friend2 \n(5) exit " <<endl;

        
        cin>>choice;
        
     }


    }

    void splitWithGroup(){
        int c;
        cout<<"How would u like to split between multiple people? \n(1) equally: so that everyone pays the same amount in the end\n(2) by percentages: so that everyone pays their specified percentages in the end \n(3) by amount: so that everyone pays as much as u specify ";
        cin>>c;

        cout<<"Enter the event name: ";
        string ev;
        cin>>ev;
        groupEvents.insertTail(ev);

        
        cout << "How many people paid, including you? (10 people max) " ;
        int people;
        cin >> people;
        if(people>10){
            cout<<"Sorry! We do not support more than 10 people at the time. "<<endl;
            return;
        }

        cout << "Enter total amount: ";
        int amt;
        cin >> amt;

        if(amt>budgetLimit){
            cout<<"You are exceeding your budget limit. "<<endl;
            cout<<"Would you like to continue anyways? (1)Yes (2)No "<<endl;
            int choosing;
            cin>>choosing;
            if(choosing==2){
                cout<<"Good job! Going back now..."<<endl;
                return;
            }
        }

        int apprAmt=amt/people; //300/3

        intLL groupOwesOrOwed; //1 or 0 or 2 wala
        intLL tempAmts;

        string names[people];
        //save string wali statements aik LL main, of who owes who how much, phir wo cout krwalo
        string groupAmts[people]; //will be using string concatenation 
        

        if(c==1){
            cout<<"You are the 1st person. "<<endl;
            cout<<"Enter the amount you paid. ";
            int money;
            cin>>money;
            tempAmts.insertTail(money);
            names[0]=name;
            
            for(int i=1;i<people;i++){
                cout<<"Enter person "<<i+1<<"'s name: ";
                string s;
                cin>>s;
                names[i]=s;
                cout<<"Enter person "<<i+1<<"'s amount: ";
                int m;
                cin>>m;
                tempAmts.insertTail(m);
                
                
            }

            groupNames.addEnd(names,people);

            cout<<"Appropriate amount for everyone: "<<apprAmt<<endl; 


            intNode* trav=tempAmts.head;

                while(trav!=NULL ){
                    //if u paid lesser than u should have: that means u owe others money
                    //1 used to show that u owe others money
                    if(trav->data<apprAmt){
                        trav->data=-(apprAmt-(trav->data)); //becomes negative of itself
                        groupOwesOrOwed.insertTail(1);
                    }

                    //2: shows that others owe u money
                    else if((trav->data)>apprAmt){
                        trav->data=trav->data-apprAmt;
                        groupOwesOrOwed.insertTail(2);

                    }
                    else{ //0 shows that u paid the exact appropriate amt
                        trav->data=0;
                        groupOwesOrOwed.insertTail(0);
                        //already paid appr amt so not involved in further calc, is owed and owes nothing 
                    }
                    trav=trav->next;
                }

                trav = tempAmts.head;
                intNode* trav2 = groupOwesOrOwed.head;

                        //dry run:
                /*trav=arr.head;
                for(int i=0;i<people;i++){
                    cout<<trav->data<<" ";
                    trav=trav->next;
                }
                cout<<endl;
                trav2=owesOrOwed.head;
                for(int i=0;i<people;i++){
                    cout<<trav2->data<<" ";
                    trav2=trav2->next;
                }
                cout<<endl; */

                int index=0;

                trav=tempAmts.head; //arr[i]
                trav2=groupOwesOrOwed.head; //owesOrOwed[i]

                int i=0;
                while(trav!=NULL){
                    if (trav2->data==1){ //owes others, -ve vals
                        intNode* trav3=tempAmts.head; //jth loop  arr[j]
                        intNode* trav4=groupOwesOrOwed.head; //jth loop owesOrOwed[j]
                        int j=0;
                        
                        while(trav3!=NULL){
                            if(trav4->data==2){ //+ve vals
                            
                                if((-(trav->data))>(trav3->data)){
                                    cout<<names[i]<<" owes "<<names[j]<<" "<<trav3->data<<endl;
                                    groupAmts[index]=names[i]+" owes " + names[j]+" " + to_string(trav3->data);
                                    index++;

                                    if(i==0){
                                        totalOwes+=trav3->data;
                                    }
                                    if(j==0){
                                        totalOwed+=trav3->data;
                                    }
                                    
                                    trav->data+=trav3->data;
                                    trav3->data=0;
                                    trav4->data=0;
                                }
                                else if((trav3->data)>(-(trav->data))){
                                    cout<<names[i]<<" owes "<<names[j]<<" "<<-trav->data<<endl;
                                    groupAmts[index]=names[i]+" owes " + names[j]+" " + to_string(-trav->data);
                                    index++;
                                    if(i==0){
                                        totalOwes+=trav3->data;
                                    }
                                    if(j==0){
                                        totalOwed+=trav3->data;
                                    }
                                    trav->data=0;
                                    trav2->data=0;
                                    trav3->data+=trav->data;
                                }

                                
                                else if(trav3->data==-(trav->data)){
                                    if(trav3->data>0){
                                    cout<<names[i]<<" owes "<<names[j]<<" "<<trav3->data<<endl;
                                    groupAmts[index]=names[i]+" owes " + names[j]+" " + to_string(trav3->data);
                                    index++;
                                    if(i==0){
                                        totalOwes+=trav3->data;
                                    }
                                    if(j==0){
                                        totalOwed+=trav3->data;
                                    }
                                    trav->data=0;
                                    trav3->data=0;
                                    trav4->data=0;
                                    trav2->data=0;
                                        }   
                                        }
                            }
                        trav3=trav3->next;
                        trav4=trav4->next;
                        j++;
                        } 
                    }

                    
                    else if(trav2->data==0){
                        //cout<<i+1<<"th person paid the appr amt"<<endl;
                    }

                    trav=trav->next;
                    trav2=trav2->next;

                i++;
                }

                

                /*cout<<"Where, "<<endl;
                for(int i=0;i<people;i++){
                    cout<<names[i]<<" is person "<<i+1<<endl;
                } */

            //dry run
            /*int n=-2;
            cout<<-n<<endl;*/

           /* cout<<"Dry run: "<<endl;
            for(int i=0;i<people;i++){
                cout<<groupAmts[i]<<endl;
            }
               */ 

            groupAmounts.addEnd(groupAmts,people);

            /*cout<<"dry run: "<<endl;
            NodeOfStrArrays* trav123=groupAmounts.head;
            while(trav123!=NULL){
                //int size=sizeof(trav123->arr)/sizeof(string);
                //int size=index;
                for(int i=0;i<3;i++){
                    cout<<trav123->arr[i]<<endl;
                }
                trav123=trav123->next;
            } 
*/
                }

        
    else if(c==2){
        intLL percen;
        cout<<"You are the first person"<<endl;
        names[0]=name;
        cout<<"Enter the percentage that you should have paid: ";
        int mon;
        cin>>mon;
        percen.insertTail(mon);
        cout<<"Enter the amount that you paid: ";
        int mon2;
        cin>>mon2;
        tempAmts.insertTail(mon2);

        for(int i=1;i<people;i++){
            cout<<"Enter "<<i+1<<"'s name: ";
            string s;
            cin>>s;
            names[i]=s;

            cout<<"Enter the percentage that person "<<i+1<<" should pay: ";
            int m;
            cin>>m;
            percen.insertTail(m);
            
            cout<<"Enter the amount paid by person "<<i+1<<": ";
            int ss;
            cin>>ss;
            tempAmts.insertTail(ss);
            
            }

            groupNames.addEnd(names,people);
        
        /*cout<<"Everyone should pay: "<<apprAmt<<endl; */
        intNode* trav=percen.head;
        intNode* trav2=tempAmts.head; //shows amounts that 

        for(int i=0;i<people;i++){
            double res=static_cast<double> (amt)*((trav->data))/(100);
            cout<<"Person "<<i+1<<" should pay "<<res<<endl;


            trav2->data=trav2->data-res;
            trav2=trav2->next;
            trav=trav->next;
        }

        //arr.display();

        trav2=tempAmts.head;

        for(int i=0;i<people;i++){
            if(trav2->data<0){
                groupOwesOrOwed.insertTail(1);
            }
            else if(trav2->data>0){
                groupOwesOrOwed.insertTail(2);
            }
            else{
                groupOwesOrOwed.insertTail(0);
            }
            trav2=trav2->next;
        }

        //owesOrOwed.display();

         trav=tempAmts.head; //arr[i]
    trav2=groupOwesOrOwed.head; //owesOrOwed[i]

    int index=0;
    int i=0;
    while(trav!=NULL){
        if (trav2->data==1){ //owes others, -ve vals
            intNode* trav3=tempAmts.head; //jth loop  arr[j]
            intNode* trav4=groupOwesOrOwed.head; //jth loop owesOrOwed[j]
            int j=0;
            
            while(trav3!=NULL){
                if(trav4->data==2){ //+ve vals
                
                    if((-(trav->data))>(trav3->data)){
                        cout<<names[i]<<" owes "<<names[j]<<" "<<trav3->data<<endl;
                        groupAmts[index]=names[i]+" owes "+names[j]+" "+ to_string(trav3->data);
                        index++;

                        if(i==0){
                                        totalOwes+=trav3->data;
                                    }
                        if(j==0){
                                        totalOwed+=trav3->data;
                                    }

                        trav->data+=trav3->data;
                        trav3->data=0;
                        trav4->data=0;
                    }
                    else if((trav3->data)>(-(trav->data))){
                        
                        cout<<names[i]<<" owes "<<names[j]<<" "<<-trav->data<<endl;
                                    
                        groupAmts[index]=names[i]+" owes " + names[j]+" " + to_string(-trav->data);
                        index++;
                                    if(i==0){
                                        totalOwes+=trav3->data;
                                    }
                                    if(j==0){
                                        totalOwed+=trav3->data;
                                    }
                                    trav->data=0;
                                    trav2->data=0;
                                    trav3->data+=trav->data;
                    }

                    
                    else if(trav3->data==-(trav->data)){
                                    if(trav3->data>0){
                                    cout<<names[i]<<" owes "<<names[j]<<" "<<trav3->data<<endl;
                                    groupAmts[index]=names[i]+" owes " + names[j]+" " + to_string(trav3->data);
                                    index++;
                                    if(i==0){
                                        totalOwes+=trav3->data;
                                    }
                                    if(j==0){
                                        totalOwed+=trav3->data;
                                    }
                                    trav->data=0;
                                    trav3->data=0;
                                    trav4->data=0;
                                    trav2->data=0;

                        
                              }   
                               }
                }
            trav3=trav3->next;
            trav4=trav4->next;
            j++;
            } 
        }

        
        else if(trav2->data==0){
            //cout<<i+1<<"th person paid the appr amt"<<endl;
        }

        trav=trav->next;
        trav2=trav2->next;

    i++;
    }
                  groupAmounts.addEnd(groupAmts,people);


        /*int k=1;
        strNode* travNames=names.head;

        cout<<"Where, "<<endl;
        while(travNames!=NULL){
            cout<<travNames->data<<" is person "<<k<<endl;
            travNames=travNames->next;
            k++;
        } */
    }

    else if(c==3){
        intLL shouldPay;

        cout<<"You are the first person"<<endl;
        names[0]=name;
        
        cout<<"Enter the amount that you paid: ";
        int mon2;
        cin>>mon2;
        tempAmts.insertTail(mon2);

        cout<<"Enter the amount that you should have paid: ";
        int mon;
        cin>>mon;
        shouldPay.insertTail(mon);

         for(int i=1;i<people;i++){
            cout<<"Enter person "<<i+1<<"'s name: ";
            string s;
            cin>>s;
            names[i]=s;
            cout<<"Enter the amount person "<<i+1<<" should pay: ";
            int m;
            cin>>m;
            shouldPay.insertTail(m);
            
            
            cout<<"Enter the amount paid by person "<<i+1<<": ";
            int ss;
            cin>>ss;
            tempAmts.insertTail(ss);
            
            }

            groupNames.addEnd(names,people);

        intNode* trav=shouldPay.head;
        intNode* trav2=tempAmts.head; //shows amounts that 

        for(int i=0;i<people;i++){
            cout<<"Person "<<i+1<<" should pay "<<trav->data<<endl;
            trav2->data=(trav2->data)-(trav->data);
            trav2=trav2->next;
            trav=trav->next;

        }

        //arr.display();

    trav2=tempAmts.head;

        for(int i=0;i<people;i++){
            if(trav2->data<0){
                groupOwesOrOwed.insertTail(1);
            }
            else if(trav2->data>0){
                groupOwesOrOwed.insertTail(2);
            }
            else{
                groupOwesOrOwed.insertTail(0);
            }
            trav2=trav2->next;
        }

        groupOwesOrOwed.display();

         trav=tempAmts.head; //arr[i]
    trav2=groupOwesOrOwed.head; //owesOrOwed[i]

    int i=0;
    int index=0;
    while(trav!=NULL){
        if (trav2->data==1){ //owes others, -ve vals
            intNode* trav3=tempAmts.head; //jth loop  arr[j]
            intNode* trav4=groupOwesOrOwed.head; //jth loop owesOrOwed[j]
            int j=0;
            
            while(trav3!=NULL){
                if(trav4->data==2){ //+ve vals
                
                    if((-(trav->data))>(trav3->data)){
                        cout<<names[i]<<" owes "<<names[j]<<" "<<trav3->data<<endl;
                                    groupAmts[index]=names[i]+" owes " + names[j]+" " + to_string(trav3->data);
                                    index++;

                                    if(i==0){
                                        totalOwes+=trav3->data;
                                    }
                                    if(j==0){
                                        totalOwed+=trav3->data;
                                    }
                                    
                                    trav->data+=trav3->data;
                                    trav3->data=0;
                                    trav4->data=0;
                    }
                    else if((trav3->data)>(-(trav->data))){
                       cout<<names[i]<<" owes "<<names[j]<<" "<<-trav->data<<endl;
                                    groupAmts[index]=names[i]+" owes " + names[j]+" " + to_string(-trav->data);
                                    index++;
                                    if(i==0){
                                        totalOwes+=trav3->data;
                                    }
                                    if(j==0){
                                        totalOwed+=trav3->data;
                                    }
                                    trav->data=0;
                                    trav2->data=0;
                                    trav3->data+=trav->data;
                    }

                    
                    else if(trav3->data==-(trav->data)){
                        if(trav3->data>0){
                                    cout<<names[i]<<" owes "<<names[j]<<" "<<trav3->data<<endl;
                                    groupAmts[index]=names[i]+" owes " + names[j]+" " + to_string(trav3->data);
                                    index++;
                                    if(i==0){
                                        totalOwes+=trav3->data;
                                    }
                                    if(j==0){
                                        totalOwed+=trav3->data;
                                    }
                                    trav->data=0;
                                    trav3->data=0;
                                    trav4->data=0;
                                    trav2->data=0;
                                        }   
                               }
                }
            trav3=trav3->next;
            trav4=trav4->next;
            j++;
            } 
        }

        
        else if(trav2->data==0){
            //cout<<i+1<<"th person paid the appr amt"<<endl;
        }

        trav=trav->next;
        trav2=trav2->next;

    i++;
    }
     groupAmounts.addEnd(groupAmts,people);

    }

    else{
        cout<<"Invalid choice. "<<endl;
        return;
    }
        

    }
    

    void displayGroupExpenses(){
         strNode* trav=groupEvents.head;
         if(trav==NULL){
            cout<<"There are no group expenses to be viewed. "<<endl;
            return;
         }
        cout<<"In total, you owe others: "<<totalOwes<<endl;
        cout<<"In total, others owe you: "<<totalOwed<<endl;

       
        NodeOfStrArrays* trav123=groupAmounts.head;

        

        while(trav!=NULL){
            cout<<"For the event: "<<trav->data<<endl;
            //NodeOfStrArrays* trav2=groupAmounts.head;
            
                //int size=sizeof(trav123->arr)/sizeof(string);
                //int size=index;
                for(int i=0;i<3;i++){
                    cout<<trav123->arr[i]<<endl;
                }

                
            trav123=trav123->next;
            trav=trav->next;
            


        }

    }
    

    void markOffOwesAsPaid(string eventName){ //event name, amount 
        strNode* trav=eventSingleNameOwes.head;
        
        strNode* trav2=namesSingleOwes.head;
        intNode* trav3=singleOwes.head;
        while(trav!=NULL ){
            if(trav->data==eventName){

                string paying="Event: "+eventName+", where you owed ";
                trav=trav->next;
                eventSingleNameOwes.delArb(eventName);
                paying+=trav2->data+" "+ to_string(trav3->data);
                string toDel=trav2->data;
                trav2=trav2->next;
                namesSingleOwes.delArb(toDel);
                int toDelete=trav3->data;
                trav3=trav3->next;
                totalOwes-=toDelete;
                singleOwes.delArb(toDelete);

                paid.push(paying);





            }
            else{
            trav=trav->next;
            trav2=trav2->next;
            trav3=trav3->next; }

            remindOwes.dequeue();
        }
    }

    void markOffOwedAsPaid(string eventName){
        strNode* trav=eventSingleNameOwed.head;
        strNode* trav2=namesSingleOwed.head;
        intNode* trav3=singleOwed.head;
        while(trav!=NULL ){
            if(trav->data==eventName){

                string paying="Event: "+eventName+", where " ;
                trav=trav->next;
                eventSingleNameOwed.delArb(eventName);
                paying+=trav2->data+" owed you "+ to_string(trav3->data);
                string toDel=trav2->data;
                trav2=trav2->next;
                namesSingleOwed.delArb(toDel);
                int toDelete=trav3->data;
                trav3=trav3->next;
                totalOwes-=toDelete;
                singleOwed.delArb(toDelete);

                paid.push(paying);





            }
            else{
            trav=trav->next;
            trav2=trav2->next;
            trav3=trav3->next; }
            
            remindOwed.dequeue();
        }
    }

    void viewPaidExpenses(){
        paid.display();
    }


    //helper swap function
    intNode* swap(intNode* pt1,intNode* pt2){
        intNode* temp=pt2->next;
        pt2->next=pt1;
        pt1->next=temp;
        return pt2;

    }
    
    
    bool noSingleExpenses(){
        return (eventSingleNameOwes.head==NULL) && (eventSingleNameOwed.head==NULL);
    }


    void displaySingleExpenses(){
        if(eventSingleNameOwes.head==NULL && eventSingleNameOwed.head==NULL){
            cout<<"There are no single expenses to be displayed"<<endl;
            return;
        }
        cout<<"Summary of ur activity: "<<endl;
        cout<<"What order would u like to view your list in? (1)latest first (2)oldest first (3)lowest price first (4)highest price first"<<endl;
        int choose;
        cin>>choose;

        if (choose==1){  //use of stacks
            stack <string> tempEvents;
    strNode* trav4=eventSingleNameOwes.head;
    while(trav4!=NULL){
        tempEvents.push(trav4->data );
        trav4=trav4->next;
    }
     cout<<"in total you owe others: "<<totalOwes<<"Rs"<<endl;

    //copying owes amts to stack
     stack <int> tempOwes;
     intNode* trav2=singleOwes.head;

     while(trav2!=NULL){
        tempOwes.push(trav2->data);
        trav2=trav2->next;

     }

    //copying names to stack
     stack <string> tempNameOwes;
     strNode* trav3=namesSingleOwes.head;
     while(trav3!=NULL){
        tempNameOwes.push(trav3->data);
        trav3=trav3->next;
     }

     while(!tempOwes.empty()){
        cout<<"u owe "<<tempNameOwes.top()<<" "<<tempOwes.top()<<"Rs for: "<<tempEvents.top()<<endl;
        
        tempOwes.pop();
        tempEvents.pop();
        tempNameOwes.pop();
     }

     //cout<<"check owes stack: "<<owes.top()<<endl; original stays unmodified
    stack <string> tempOwedEvents;
    strNode* trav5=eventSingleNameOwed.head;
    while(trav5!=NULL){
        tempOwedEvents.push(trav5->data );
        trav5=trav5->next;
    }
     cout<<"in total, others owe u: "<<totalOwed<<"Rs"<<endl;
     stack <int> tempOwed;
     intNode* trav7=singleOwed.head;

     while(trav7!=NULL){
        tempOwed.push(trav7->data);
        trav7=trav7->next;
     }

    stack <string> tempNamesOwed;
    strNode* trav8=namesSingleOwed.head;
     while(trav8!=NULL){
        tempNamesOwed.push(trav8->data);
        trav8=trav8->next;
     }

     while(!tempOwed.empty()){
        cout<<tempNamesOwed.top()<<" owes u "<<tempOwed.top()<<" rs for: "<<tempOwedEvents.top()<<endl;
        tempOwed.pop();
        tempNamesOwed.pop();
        tempOwedEvents.pop();

     }


        }

        else if(choose==2){ //implement using LL: 
            strNode* trav=this->eventSingleNameOwes.head;

            cout<<"In total, you owe others: "<<totalOwes<<"rs"<<endl;

            intNode* trav2=singleOwes.head;
            strNode* trav3=namesSingleOwes.head;

            while(trav2!=NULL){
                cout<<"You owe "<<trav3->data<<" "<<trav2->data<<" for "<<trav->data<<endl;
                trav3=trav3->next;
                trav=trav->next;
                trav2=trav2->next;
            }
            cout<<endl;

            cout<<"In total, others owe u: "<<totalOwed<<"Rs"<<endl;

            trav2=singleOwed.head;
            trav3=namesSingleOwed.head;
            trav=this->eventSingleNameOwed.head;

            while(trav2!=NULL){
                cout<<trav3->data<<" owes you "<<trav2->data<<"Rs for: "<<trav->data<<endl;
                trav3=trav3->next;
                trav=trav->next;
                trav2=trav2->next;
            }

            cout<<endl;
        }
        
        else if(choose==3){ //bubble sort
            //create temp LL, shift values to it, sort it
            //usay associated names aur events ko bhi manage krna hoga
            //up til now, was relying heavily on having same pos
            //so agar kahin pe prices shift krrahay ho, usi ke saath udhar hee names & events bhi swap krdo
            cout<<"In total, you owe others: "<<totalOwes<<endl;
            
            int len=0;
            

            intNode* trav=singleOwes.head;
            while(trav!=NULL){
                len++;
                trav=trav->next;
            }

            int* tempOwes=new int[len];
            string* tempNamesOwes=new string[len];
            string* tempEventsOwes=new string[len];
            trav=singleOwes.head;

            strNode* trav2=namesSingleOwes.head;
            strNode* trav3=eventSingleNameOwes.head;

            //copying LL data into arrays
            for(int i=0;i<len;i++){
                tempOwes[i]=trav->data;
                trav=trav->next;
                tempNamesOwes[i]=trav2->data;
                trav2=trav2->next;
                tempEventsOwes[i]=trav3->data;
                trav3=trav3->next;

            }

            //sorting array:
            for(int i=0;i<len;i++){
                for(int j=0;j<len-i;j++){
                    if(tempOwes[j]>tempOwes[j+1]){
                        int temp=tempOwes[j];
                        tempOwes[j]=tempOwes[j+1];
                        tempOwes[j+1]=temp;

                        string temp2=tempNamesOwes[j];
                        tempNamesOwes[j]=tempNamesOwes[j+1];
                        tempNamesOwes[j+1]=temp2;

                        string temp3=tempEventsOwes[j];
                        tempEventsOwes[j]=tempEventsOwes[j+1];
                        tempEventsOwes[j+1]=temp3;
                            }
                }
            }

            for(int i=0;i<len;i++){
                cout<<"You owe "<<tempNamesOwes[i]<<" "<<tempOwes[i]<<" for "<<tempEventsOwes[i]<<endl;
            }

            cout<<endl;
            cout<<"In total, others owe you: "<<totalOwed<<endl;

            int owedLen=0;

            intNode* trav4=singleOwed.head;
            while(trav4!=NULL){
                owedLen++;
                trav4=trav4->next;
            }

            int* tempOwed=new int[owedLen];
            string* tempNamesOwed=new string[owedLen];
            string* tempEventsOwed=new string[owedLen];
            trav4=singleOwed.head;

            strNode* trav5=namesSingleOwed.head;
            strNode* trav6=eventSingleNameOwed.head;

            //copying LL data into arrays
            for(int i=0;i<owedLen;i++){
                tempOwed[i]=trav4->data;
                trav4=trav4->next;
                tempNamesOwed[i]=trav5->data;
                trav5=trav5->next;
                tempEventsOwed[i]=trav6->data;
                trav6=trav6->next;

            }

            cout<<"original: "<<endl;
            for(int i=0;i<len;i++){
                cout<<tempOwed[i]<<" ";
            }cout<<endl; 

             //sorting array:
            for(int i=0;i<owedLen;i++){
                for(int j=0;j<owedLen-i;j++){
                    if(tempOwed[j]>tempOwed[j+1]){
                        int temp4=tempOwed[j];
                        tempOwed[j]=tempOwed[j+1];
                        tempOwed[j+1]=temp4;

                        string temp5=tempNamesOwed[j];
                        tempNamesOwed[j]=tempNamesOwed[j+1];
                        tempNamesOwed[j+1]=temp5;

                        string temp6=tempEventsOwed[j];
                        tempEventsOwed[j]=tempEventsOwed[j+1];
                        tempEventsOwed[j+1]=temp6;
                            }
                }
            }

            cout<<"sorted: "<<endl;
            for(int i=0;i<owedLen;i++){cout<<tempOwed[i]<<" ";}cout<<endl; 

            for(int i=0;i<owedLen;i++){
                cout<<tempNamesOwed[i]<<" owes you "<<tempOwed[i]<<" for "<<tempEventsOwed[i]<<endl;
            }


         } 

        else if(choose==4){ //bubble sort
            cout<<"In total, you owe others: "<<totalOwes<<endl;
            
            int len3=0;
            

            intNode* travv=singleOwes.head;
            while(travv!=NULL){
                len3++;
                travv=travv->next;
            }

            int* tempOwes1=new int[len3];
            string* tempNamesOwes1=new string[len3];
            string* tempEventsOwes1=new string[len3];
            travv=singleOwes.head;

            strNode* trav22=namesSingleOwes.head;
            strNode* trav33=eventSingleNameOwes.head;

            //copying LL data into arrays
            for(int i=0;i<len3;i++){
                tempOwes1[i]=travv->data;
                travv=travv->next;
                tempNamesOwes1[i]=trav22->data;
                trav22=trav22->next;
                tempEventsOwes1[i]=trav33->data;
                trav33=trav33->next;

            }

           


            //sorting array:
            for(int i=0;i<len3;i++){
                for(int j=0;j<len3-i-1;j++){
                    if(tempOwes1[j]>tempOwes1[j+1]){
                        int temp=tempOwes1[j];
                        tempOwes1[j]=tempOwes1[j+1];
                        tempOwes1[j+1]=temp;

                        string temp2=tempNamesOwes1[j];
                        tempNamesOwes1[j]=tempNamesOwes1[j+1];
                        tempNamesOwes1[j+1]=temp2;

                        string temp3=tempEventsOwes1[j];
                        tempEventsOwes1[j]=tempEventsOwes1[j+1];
                        tempEventsOwes1[j+1]=temp3;
                            }
                }
            }

           

            //for(int i=len3-1;i>0;i--){
            for(int i=len3-1;i>=0;i--){
                if (i >= 0) {
                    cout<<"You owe "<<tempNamesOwes1[i]<<" "<<tempOwes1[i]<<" for "<<tempEventsOwes1[i]<<endl;
            } }

            //cout<<"len "<<len3<<endl;

            //cout<<"original: "<<endl;
            for(int i=0;i<len3;i++){
                //cout<<tempOwes1[i]<<" ";
            }
            cout<<endl;

            //cout<<"reverse: "<<endl;
            for(int i=len3-1;i>=0;i--){
                if (i >= 0) {
                //cout<<tempOwes1[i]<<" ";
            } }
            cout<<endl; 


            

            cout<<endl;
            cout<<"In total, others owe you: "<<totalOwed<<endl;

            int owedLen3=0;

            intNode* trav44=singleOwed.head;
            while(trav44!=NULL){
                owedLen3++;
                trav44=trav44->next;
            }

            int* tempOwed1=new int[owedLen3];
            string* tempNamesOwed1=new string[owedLen3];
            string* tempEventsOwed1=new string[owedLen3];
            intNode* trav444=singleOwed.head;

            strNode* trav55=namesSingleOwed.head;
            strNode* trav66=eventSingleNameOwed.head;

            //copying LL data into arrays
            for(int i=0;i<owedLen3;i++){
                tempOwed1[i]=trav444->data;
                trav444=trav444->next;
                tempNamesOwed1[i]=trav55->data;
                trav55=trav55->next;
                tempEventsOwed1[i]=trav66->data;
                trav66=trav66->next;

            }

            //cout<<"original arr: before sorting: "<<endl;
            for(int i=0;i<owedLen3;i++){
                //cout<<tempOwed1[i]<<" ";
            }
            cout<<endl;

             //sorting array:
            for(int i=0;i<owedLen3;i++){
                for(int j=0;j<owedLen3-i-1;j++){
                    if(tempOwed1[j]>tempOwed1[j+1]){
                        int temp4=tempOwed1[j];
                        tempOwed1[j]=tempOwed1[j+1];
                        tempOwed1[j+1]=temp4;

                        string temp5=tempNamesOwed1[j];
                        tempNamesOwed1[j]=tempNamesOwed1[j+1];
                        tempNamesOwed1[j+1]=temp5;

                        string temp6=tempEventsOwed1[j];
                        tempEventsOwed1[j]=tempEventsOwed1[j+1];
                        tempEventsOwed1[j+1]=temp6;
                            }
                }
            }

            for(int i=len3-1;i>=0;i--){
                if (i >= 0) {
                                    //for(int i=0;i<owedLen3;i++){
                cout<<tempNamesOwed1[i]<<" owes you "<<tempOwed1[i]<<" for "<<tempEventsOwed1[i]<<endl;
            } }

        }
        
        
        else{
            cout<<"invalid choice. exiting..."<<endl;
            return;
        } 
        } 

    void charity(){
        cout<<"Welcome to Charity?"<<endl;
        int pickk=0;

        
        cout<<"Would you like to also donate a certain percentage to charity for every other expense you have? (1)Yes (2)No";
        cin>>pickk;

        
        if(pickk==1){
            cout<<"What percentage would you like to donate to charity?";
            int percentageChar;
        cin >> percentageChar;


        intLL temporary; //temp LL, uske andar sari owes walay elements move krwaye
        intNode* n1=singleOwes.head;

        while(n1!=NULL){
            temporary.insertTail(n1->data);
            n1=n1->next;
        }


        intNode* n2=temporary.head;



        while(n2!=NULL){
            int charityAmount = (n2->data * percentageChar) / 100;
            singleOwes.insertTail(charityAmount);
            namesSingleOwes.insertTail("Charity");
            eventSingleNameOwes.insertTail("Charity");
            n2=n2->next;
        }

        }

       

   /* intNode* trav80000 = singleOwes.head;

        cout << "Before loop" << endl;

        while (trav80000->next != NULL) {
            int charityAmount = (trav80000->data * percentageChar) / 100;
            singleOwes.insertTail(charityAmount);

            // Insert corresponding data into other lists
            string s="Charity";
            eventSingleNameOwes.insertTail(s);
            namesSingleOwes.insertTail(s);
            // Move to the next node
            trav80000 = trav80000->next;
        }

        cout << "After loop" << endl;

        cout << "Done donating to charity." << endl;
        return; } */
    
    else if (pickk == 2) {
        cout << "Maybe next time then..." << endl;
        return;
    } else {
        cout << "Invalid choice" << endl;
        return;
    }
}

};

/*
void moneyDividing(int people,int sum){
    int choice;
    cout<<"How would you like to split the money? (by amount(1) \nby percentages(2) \nby splitting the money equally between all the parties involved? (3))";
    cin>>choice;

    int moneySections[people];
    string names[people];

    if(choice==1){
        for(int i=0;i<people;i++){
            cout<<"Who would you like to split the money with? ";
            cin>>names[i];
            cout<<"Enter the amount paid by "<<names[i];
            cin>>moneySections[i];
            cout<<endl;
        }
    }

    else if(choice==2){
        for(int i=0;i<people;i++){
            cout<<"Who would you like to split the money with? ";
            cin>>names[i]; 
            cout<<"Enter the percentage paid by "<<names[i];
            int p;
            cin>>p;
            moneySections[i]=sum*(p/100);
        }
    }

}
*/

//user type node and linked list codes: (to store accounts)
class Node {
    public:
    UserInfo* user;
    Node* next;

    Node(UserInfo* newUser) {
        user = newUser;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void addUser(UserInfo* newUser) {
        Node* newNode = new Node(newUser);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    UserInfo* searchUser(string userName) {
        Node* current = head;
        while (current != nullptr) {
            if (current->user->getUserName() == userName) { //works like node->data accessing except the datatype is from the user class, not int (so we match that)
                return current->user;
            }
            current = current->next;
        }
        return nullptr;
    }

    void deleteUser(UserInfo* userToDelete) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->user != userToDelete) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "User not found." << endl;
            return;
        }

        if (current == head) {
            head = head->next;
        }
        else {
            prev->next = current->next;
        }

        delete current->user;
        delete current;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp->user;
            delete temp;
        }
    }
};

UserInfo* newAcc() {
    UserInfo* u1 = new UserInfo();

    string name;
    cout << "Enter your name: " << endl;
    cin.ignore();
    getline(cin, name);
    u1->setName(name);
    cout << endl; 

    string phoneNumber;
    cout << "Enter your phone number: " << endl;
    cin >> phoneNumber;
    u1->setPhoneNum(phoneNumber);
    cout << endl; 

    

    cout << "Enter your user name: " << endl;
    string userName;
    cin >> userName;
    u1->setUserName(userName);
    cout << endl;

    cout << "Enter your password: " << endl;
    string password;
    cin >> password;
    u1->setPassword(password);

    cout << "Your account has been created.\n You may now proceed to login to explore the functionalities of MoneySplitter" << endl;
    return u1;
}

void userMenu(UserInfo* u1){
    //modify details like password, username etc
    //add expense
    cout<<endl;
    cout<<"Welcome to your account!! "<<endl<<endl;
    int choice;

    if(!u1->remindOwed.isEmpty() || !u1->remindOwes.isEmpty()) {
        cout<<"Reminders: "<<endl;
        if(!u1->remindOwed.isEmpty()){
        cout<<u1->remindOwed.peek()<<endl;}
        if(!u1->remindOwes.isEmpty()){
        cout<<u1->remindOwes.peek()<<endl; }
    }
    cout<<endl;

    cout<<"What would you like to do? "<<endl;
    cout<<"(1) Modify account details"<<endl;
    cout<<"(2) Display account details "<<endl;
    cout<<"(3) Add an expense to be splitted with one person"<<endl;
    cout<<"(4) Add an expense to be splitted with a group "<<endl;
    cout<<"(5) Set a budget limit"<<endl; 
    cout<<"(6) View history"<<endl;  //single + group combined kardo
    cout<<"(7) View expenses that have been split with a single person"<<endl;
    cout<<"(8) View the expenses that have been split with a group"<<endl;
    cout<<"(9) Charity "<<endl; //left
    cout<<"(10) Log out"<<endl;
    cout<<"(11) Mark off an expense as paid"<<endl; 
    cout<<"(12) View expenses that have been paid"<<endl;

    //use of queues for normal reminders
    
    
    cin>>choice;

    if(choice==1){
        u1->modify();
    }
    else if(choice==2){
        u1->Display_Account_Details();
    }

    else if(choice==3){
        u1->splitWithOnePerson();
    }

    else if(choice==4){
        u1->splitWithGroup();
    }

    else if(choice==7){
        u1->displaySingleExpenses();
    }

    else if(choice==8){
        u1->displayGroupExpenses();
    }
    
    else if(choice==9){
        u1->charity();
    }

    else if(choice==10){
        cout<<"Logging out..."<<endl;
        return;
    }
    else if(choice==6){
        u1->displaySingleExpenses();
        cout<<endl;
        u1->displayGroupExpenses();

    }

    else if(choice==5){
        cout<<"At what amount would you be like to be reminded that you are exceeding your budget? ";
        int bL;
        cin>>bL;
        u1->setBudgetLimit(bL);

    }

    else if(choice==11){
        if(u1->noSingleExpenses()){
            cout<<"There are no expenses to be marked off as paid. Please add an expense first. "<<endl;
            
        }

        else{
        cout<<"You can mark off one of the following expenses as paid: "<<endl;
        u1->displaySingleExpenses();
        cout<<"Which event would you like to mark off as paid? "<<endl;
        string paidEvent;
        cin>>paidEvent;
        cout<<"Is it an event that you owe others (1) or others owe you? (2)";
        int pick;
        cin>>pick;

        if(pick==1){
            u1->markOffOwesAsPaid(paidEvent);
            cout<<paidEvent<<" has been marked off as paid."<<endl;
        }

        else if(pick==2){
            u1->markOffOwedAsPaid(paidEvent);
            cout<<paidEvent<<" has been marked off as paid."<<endl;
        } }


        
        
    }

    else if(choice==12){
        u1->viewPaidExpenses();
    }

    if(choice!=10){
        userMenu(u1); }


}

int main() {
    LinkedList userList;

    cout << "Welcome to the money splitter!!" << endl;
    int option = 0;

    while (option != 4) {
        cout << "What would you like to do today? " << endl;
        cout << "(1) Create new account \n(2) Login into your account \n(3) Delete account \n(4) Close MoneySplitter" << endl;
        cin >> option;

        if (option == 1) {
            UserInfo* newUser = newAcc();
            userList.addUser(newUser);
        }
        else if (option == 2) {
            string enteredUsername, enteredPassword;
            cout << "Enter your username: ";
            cin >> enteredUsername;
            cout << "Enter your password: ";
            cin >> enteredPassword;

            UserInfo* user = userList.searchUser(enteredUsername);
            if (user != nullptr && user->validateLogin(enteredUsername, enteredPassword)) {
                cout << "Login successful!" << endl;
                userMenu(user);
                // Add functionalities for logged-in users
                // Display menu again after successful login
                 // Continue to display menu options
            }
            else {
                cout << "Invalid username or password. Please try again." << endl;
            }
            //break;
        }
        else if (option == 3) {
            string enteredUsername, enteredPassword;
            cout << "Enter your username: ";
            cin >> enteredUsername;
            cout << "Enter your password: ";
            cin >> enteredPassword;

             UserInfo* user = userList.searchUser(enteredUsername);
            if (user != nullptr && user->validateLogin(enteredUsername, enteredPassword)) {
                userList.deleteUser(user);
                cout<<"User has been deleted. "<<endl;
             } 
            else {
                cout << "Invalid username or password. Please try again. \nPlease make sure your account actually exists by logging in first. " << endl;
            }
        }

        else if(option==4){
            cout << "Thanks for using MoneySplitter!" << endl;
            break;

        }
        else if (option != 4) {
            cout << "Invalid choice. Choose again. " << endl;
        }
    }

    return 0;
}

