#include<iostream>
using namespace std;

class Flower
{
    private:
        string name;
        int pedals;
        int price;
    public:
        Flower();
        Flower(string name, int pedals, int price)
        {
            this->name = name;
            this->pedals = pedals;
            this->price = price;
        }
        void setName(string name) {this->name = name;}
        void setPedals(int pedals) {this->pedals = pedals;}
        void setPrice(int price) {this->price = price;}
        string getName() {return name;}
        int getPedals() {return pedals;}
        int setPrice() {return price;}
        friend ostream& operator<<(ostream& os, Flower& f);
};

ostream& operator<<(ostream& os, Flower& f)
{
    os << f.name << endl << f.pedals << endl << f.price << endl;
    return os;
}

int main()
{
    Flower f("Rose", 5, 15);
    cout << f;
    return 0;
}