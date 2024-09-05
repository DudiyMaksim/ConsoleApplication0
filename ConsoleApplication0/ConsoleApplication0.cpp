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
        cout << name << " ç " << countStrings << " ñòðóíàìè ãðàº ìåëîä³þ." << endl;
    }

    void adjustVolume() const override {
        cout << "Ðåãóëþâàííÿ ãó÷íîñò³ ñòðóííîãî ³íñòðóìåíòà: " << name << endl;
    }
};

class WindInstrument : public Instrument {
public:
    string typeOfAirVent;

    WindInstrument(string name, int year, string type) :Instrument(name, year), typeOfAirVent(type) {};

    void playSound() const override {
        cout << name << " ç îòâîðîì äëÿ âèäóâàííÿ: " << typeOfAirVent << " âèäàº çâóê." << endl;
    }

    void adjustVolume() const override {
        cout << "Ðåãóëþâàííÿ ãó÷íîñò³ äóõîâîãî ³íñòðóìåíòà : " << name << endl;
    }
};

class PercussionInstrument : public Instrument {
public:
    string typeOfImpactor;

    PercussionInstrument(string name, int year,string Impactor)
        : Instrument(name, year), typeOfImpactor(Impactor) {}

    void playSound() const override {
        cout << name << " ç óäàðíîþ ïîâåðõíåþ: " << typeOfImpactor << " âèäàº óäàð." << endl;
    }

    void adjustVolume() const override {
        cout << "Ðåãóëþâàííÿ ãó÷íîñò³ óäàðíîãî ³íñòðóìåíòà: " << name << endl;
    }
};
int main()
{
    setlocale(LC_ALL, "");
    Instrument* list[3];

    list[0] = new StringInstrument("Ã³òàðà", 1550, 6);
    list[1] = new WindInstrument("Ôëåéòà", 1700, "Ãóáíèé îòâ³ð");
    list[2] = new PercussionInstrument("Áàðàáàí", 2000, "Øê³ðÿíà ìåìáðàíà");

    for (int i = 0; i < 3; ++i) {
        list[i]->playSound();
        list[i]->adjustVolume();
        cout << endl;
    }
}
