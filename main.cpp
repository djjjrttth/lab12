#include <iostream>
#include <vector>
#include <string>
using namespace std;

//структура задачи
struct Task{
    int id;
    string name;
    string priority;
};

// класс итератора 
class Iterator{
    vector<Task>::iterator it; //объявление переменной it, которая является итератором для std::vector<Task>
    public:
        Iterator(vector<Task>::iterator begin): it(begin) {} //инициализация
        Task& operator* () { return *it; } // перегрузка разыменовывания
        Task& operator++(int){ return *it++;} // перегрузка инкремента
        bool operator!= (const Iterator& other){ return it != other.it;} // перегрузка !=
        //функция фильтрации, принимает на вход вспомогательный итератор, который указывает до какого момента итерироваться
        // и key - сам фильтр
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