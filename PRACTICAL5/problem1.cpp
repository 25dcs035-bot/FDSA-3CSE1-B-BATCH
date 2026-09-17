#include <iostream>
#include <string>

using namespace std;


struct Node {
    string songName;
    Node* next;
    Node* prev;

    Node(string name) : 
    songName(name), 
    next(nullptr),
     prev(nullptr) {}
};

class Playlist {
private:
    Node* head;
    Node* tail;
    int count;

    public:
    Playlist(){
        head=nullptr;
        tail=nullptr;
        count=0;
    }
    void addfirst(string name){
        Node* newNode=new Node(name);
        if(head==nullptr){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
        count++;
        }
        void addlast(string name){
            Node* newNode=new Node(name);
            if(tail==nullptr){
                head=tail=newNode;
            }
            else{
                tail->next=newNode;
                newNode->prev=tail;
                tail=newNode;
            }
            count++;
        }
        void insertAfter(string targetSong, string newSong) {
        Node* curr = head;

        
        while (curr != nullptr && curr->songName != targetSong) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Song '" << targetSong << "' not found in playlist!\n";
            return;
        }

        Node* newNode = new Node(newSong);
        newNode->next = curr->next;
        newNode->prev = curr;

        if (curr->next != nullptr) {
            curr->next->prev = newNode;
        } else {
            tail = newNode; 
        }
        curr->next = newNode;

        count++;
    }
    void removeFirst() {
        if (head == nullptr) {
            cout << "Playlist is already empty!\n";
            return;
        }

        Node* temp = head;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        count--;
    }

        void display(){
           cout<<"Total songs: "<<count <<endl;
           Node* temp=head;
           while(temp!=nullptr){
            cout<<temp->songName ;
            if(temp->next!=nullptr){
                cout<<"<->";
                
            }
            temp=temp->next;
        }
            cout<<endl;
        }
    };

        int main(){
            Playlist p;
            p.addfirst("TU JO MILA ");
            p.addlast("BYE");
            p.addfirst("Pal Pal");
            p.display();
            p.insertAfter(" BOOM SHAKA ", "TU HAI KAHAN");
             p.display();
             p.removeFirst();
             p.display();
            return 0;
        }

