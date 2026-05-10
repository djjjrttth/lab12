#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;


struct Task{
    int id;
    string name;
    string priority;
};



class Iterator{
    vector<Task>::iterator it;
    vector<Task>::iterator end;
    
    function<bool(Task&)> key;

    void move_next(){
        while (it != end && !key(*it)){
            it++;
        }
    }
    public:
        Iterator(vector<Task>::iterator begin, vector<Task>::iterator end, function<bool(Task&)> key) : it(begin), end(end), key(key){
            move_next();
        }
    
        Task& operator* () {
            return *it;
        }
        Iterator& operator++(int){
            it++;
            move_next();
            return *this;
        }
        bool operator!= (Iterator& other) {
            return it != other.it;
        } 

        
};

int main(){
    

    vector<Task> tasks;
    Task t1;
    t1.id = 1;
    t1.name = "t1";
    t1.priority = "high";
    Task t2;
    t2.id = 2;
    t2.name = "t2";
    t2.priority = "low";
    Task t3;
    t3.id = 3;
    t3.name = "t3";
    t3.priority = "high";
    tasks.push_back(t1);
    tasks.push_back(t2);
    tasks.push_back(t3);


    auto key = [](Task& t) {return t.priority == "high";};
    
    Iterator start(tasks.begin(), tasks.end(), key);
    Iterator finish(tasks.end(), tasks.end(), key);
    
    while (start != finish){
        cout << (*start).id << " " << (*start).name << " " << (*start).priority << endl;
        start++;
    }

    auto key2 = [](Task& t) {return t.id%2 == 0;};
    
    Iterator start1(tasks.begin(), tasks.end(), key2);
    Iterator finish1(tasks.end(), tasks.end(), key2);
    std::cout << std::endl;
    while (start1 != finish1){
        cout << (*start1).id << " " << (*start1).name << " " << (*start1).priority << endl;
        start1++;
    }
    return 0;
}