#include <iostream>
using namespace std;

class Instrument {
protected:
    string name;
    int year;
public:
    Instrument(string name, int year) : name{ name }, year{ year } {};

    virtual void playSound() const = 0;

    virtual void adjustVolume() const = 0;
};

class StringInstrument : public Instrument {
public:
    int countStrings;
    
    StringInstrument(string name, int year, int strings) : Instrument(name, year), countStrings(strings) {};

    void playSound() const override {
        cout << name << " з " << countStrings << " струнами грає мелодію." << endl;
    }

    void adjustVolume() const override {
        cout << "Регулювання гучності струнного інструмента: " << name << endl;
    }
};

class WindInstrument : public Instrument {
public:
    string typeOfAirVent;

    WindInstrument(string name, int year, string type) :Instrument(name, year), typeOfAirVent(type) {};

    void playSound() const override {
        cout << name << " з отвором для видування: " << typeOfAirVent << " видає звук." << endl;
    }

    void adjustVolume() const override {
        cout << "Регулювання гучності духового інструмента : " << name << endl;
    }
};

class PercussionInstrument : public Instrument {
public:
    string typeOfImpactor;

    PercussionInstrument(string name, int year,string Impactor)
        : Instrument(name, year), typeOfImpactor(Impactor) {}

    void playSound() const override {
        cout << name << " з ударною поверхнею: " << typeOfImpactor << " видає удар." << endl;
    }

    void adjustVolume() const override {
        cout << "Регулювання гучності ударного інструмента: " << name << endl;
    }
};
int main()
{
    setlocale(LC_ALL, "");
    Instrument* list[3];

    list[0] = new StringInstrument("Гітара", 1550, 6);
    list[1] = new WindInstrument("Флейта", 1700, "Губний отвір");
    list[2] = new PercussionInstrument("Барабан", 2000, "Шкіряна мембрана");

    for (int i = 0; i < 3; ++i) {
        list[i]->playSound();
        list[i]->adjustVolume();
        std::cout << std::endl;
    }
}
