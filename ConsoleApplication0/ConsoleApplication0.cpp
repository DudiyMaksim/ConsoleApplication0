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
        cout << name << " � " << countStrings << " �������� ��� ������." << endl;
    }

    void adjustVolume() const override {
        cout << "����������� ������� ��������� �����������: " << name << endl;
    }
};

class WindInstrument : public Instrument {
public:
    string typeOfAirVent;

    WindInstrument(string name, int year, string type) :Instrument(name, year), typeOfAirVent(type) {};

    void playSound() const override {
        cout << name << " � ������� ��� ���������: " << typeOfAirVent << " ���� ����." << endl;
    }

    void adjustVolume() const override {
        cout << "����������� ������� �������� ����������� : " << name << endl;
    }
};

class PercussionInstrument : public Instrument {
public:
    string typeOfImpactor;

    PercussionInstrument(string name, int year,string Impactor)
        : Instrument(name, year), typeOfImpactor(Impactor) {}

    void playSound() const override {
        cout << name << " � ������� ���������: " << typeOfImpactor << " ���� ����." << endl;
    }

    void adjustVolume() const override {
        cout << "����������� ������� �������� �����������: " << name << endl;
    }
};
int main()
{
    setlocale(LC_ALL, "");
    Instrument* list[3];

    list[0] = new StringInstrument("ó����", 1550, 6);
    list[1] = new WindInstrument("������", 1700, "������ ����");
    list[2] = new PercussionInstrument("�������", 2000, "������ ��������");

    for (int i = 0; i < 3; ++i) {
        list[i]->playSound();
        list[i]->adjustVolume();
        std::cout << std::endl;
    }
}
