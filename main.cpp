#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task{
    int id;
    string name;
    string priority;
};

class Iterator{
    vector<Task>::iterator it;
    public:
        Iterator(vector<Task>::iterator begin): it(begin) {}
        Task& operator* () { return *it; }
        Task& operator++(int){ return *it++;}
        bool operator!= (const Iterator& other){ return it != other.it;}
        template <typename T>
        std::vector<Task> filter(Iterator end, T key){
            std::vector<Task> filtered;
            while (it != end.it){
                if (key(*it))
                    filtered.push_back(*it);
                it++;
            }
            return filtered;
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

    Iterator it(tasks.begin());
    Iterator end(tasks.end());

    std::vector<Task> result = it.filter(end, [](Task t){return t.priority == "high";});
    for (auto i: result){
        std::cout << i.id << " " << i.name << " " << i.priority << endl;
    }
    return 0;
}