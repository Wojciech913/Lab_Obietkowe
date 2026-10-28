#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
class Car {
    private:
        std::string make;
        std::string model;
        int year;
        int currentyear;
    public:
        Car(std::string make, std::string model, int year, int currentyear = 2026)
        {
            this->make = make;
            this->model = model;
            this->year = year;
            this->currentyear = currentyear;
        }
        ~Car() {};
        void displayinfo()
        {
            std::cout<<make<<std::endl;
            std::cout<<model<<std::endl;
            std::cout<<year<<std::endl;
            std::cout<<currentyear<<std::endl;
        }
        int getCarAge()
		{
        	return currentyear - year;
		}
		bool isSameCar(Car otherCar)
		{
			if (this->year==otherCar.year && this->model==otherCar.model && this->make==otherCar.make)
			return true;
			else
			return false;
		}
};
class Parrot {
private:
    std::vector<std::string> phrases;
public:
    Parrot(std::string initialPhrase) {
        phrases.push_back(initialPhrase);
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }
    void setPhrase(std::string newPhrase) {
        if (!phrases.empty()) {
            phrases[0] = newPhrase;
        } else {
            phrases.push_back(newPhrase);
        }
    }
    void addPhrase(std::string phrase) {
        phrases.push_back(phrase);
    }
    void say(int repetitions = 1) const {
        if (phrases.empty()) {
            std::cout << "The Phoenix is silent.." << std::endl;
            return;
        }
        int randomIndex = std::rand() % phrases.size();
        std::string chosenPhrase = phrases[randomIndex];
        for (int i = 0; i < repetitions; ++i) {
            std::cout << chosenPhrase << " ";
        }
        std::cout << std::endl;
    }
};
class tablica{
    private:
        int* tab;
        int rozmiar;
    public:
        tablica(int wielkosc = 10)
        {
        	rozmiar = wielkosc;
            tab = new int[wielkosc];
            for (int i = 0;i < wielkosc;i++)
            {
            	tab[i] = 0;
			}
        }
        ~tablica() {
        	delete[] tab;
        	std::cout<<"Tablica o wielkosci "<<rozmiar<<" zostala pokonana"<<std::endl;
 		}
};
class samochod {
    private:
        std::string make;
        std::string model;
        int rokProdukcji;
    public:
        samochod(std::string make = "Toyota(chyba)", std::string model = "Corrola(prawdobodobnie)", int rokProdukcji = 1999)
        {
            this->make = make;
            this->model = model;
            this->rokProdukcji = rokProdukcji;
        }
		~samochod() {
			std::cout<<"Deskruktor wywolany dla "<<make<<" "<<model<<std::endl;
		}
};
int main()
{
	int wybor;
	std::cout<<"wybierz zadanie wpisujac jego numer";
	std::cin>>wybor;
	switch (wybor) {
		case 1:
			{
			Car MineCar("Toyota", "Corolla", 1999);
    		Car HisCar("Toyota", "Corolla", 1999);
    		Car HerCar("Toyota", "Camry", 2024, 2027);
    		MineCar.displayinfo();
    		HerCar.displayinfo();
    		std::cout<<MineCar.getCarAge()<<std::endl;
    		std::cout<<MineCar.isSameCar(HisCar);
			break;
			}
		case 2:
		{
			Parrot ArmosTheUnyieldingPhoenix("Die!");
    		std::cout<<"Fraza poczatkowa:"<<std::endl;
    		ArmosTheUnyieldingPhoenix.say();
    		ArmosTheUnyieldingPhoenix.setPhrase("Greetings!");
    		std::cout<<"Po zmianie frazy:"<<std::endl;
    		ArmosTheUnyieldingPhoenix.say();
    		std::cout<<"Powtorzenie 3 razy:"<<std::endl;
    		ArmosTheUnyieldingPhoenix.say(3);
    		ArmosTheUnyieldingPhoenix.addPhrase("I'll purify them!");
    		ArmosTheUnyieldingPhoenix.addPhrase("Purge them in flames!");    
    		std::cout<<"Losowe frazy z bazy danych:"<<std::endl;
    		for (int i = 0; i < 4; ++i) {
        		std::cout<<i + 1<<": ";
        		ArmosTheUnyieldingPhoenix.say(2); 
    		}
			break;
		}
		case 3:
		{
			samochod MineSamochod;
    		samochod HisSamochod("Toyota(napewno)", "Corrola(bez dwoch zdan)", 2022);
			break;
		}
		case 4:
		{
			tablica MineTablica;
    		tablica HisTablica(5);
			break;
		}
		default:
		{
			std::cout<<"Nie wybrales zadania";
			break;
		}
	}
	return 0;
}

