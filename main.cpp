//
//  main.cpp
//  UML ДЗ 1 Strategy
//
//  Created by Павел on 30.03.2023.
//

#include <iostream>
 
// Класс груза
class Cargo {
public:
Cargo(std::string cargoType) : _cargoType(cargoType) {}
std::string getCargoType() {
return _cargoType;
}
private:
std::string _cargoType;
    
};

// Класс грузовика
class Truck {
public:
Truck(std::string truckType) : _truckType(truckType) {}
std::string getTruckType() {
return _truckType;
}
private:
std::string _truckType;
};



// Абстрактный класс для стратегий обработки груза
class CargoProcessingStrategy {
public:
virtual void processCargo(Cargo cargo) = 0;
};

// Конкретная стратегия обработки груза для склада типа "Холодильник"
class ColdStorageProcessingStrategy : public CargoProcessingStrategy {
public:
void processCargo(Cargo cargo) override {
    std::cout<<"Груз будет обработан на складе типа Холодильник"<<std::endl;
}
};

// Конкретная стратегия обработки груза для склада типа "Оптовый"
class WholesaleStorageProcessingStrategy : public CargoProcessingStrategy {
public:
void processCargo(Cargo cargo) override {
    std::cout<<"Груз будет обработан на складе типа Оптовый"<<std::endl;
}
};
// Класс контекста, который выбирает нужную стратегию обработки груза
class CargoProcessor {
public:
CargoProcessor(CargoProcessingStrategy* strategy) : strategy(strategy) {}
void setStrategy(CargoProcessingStrategy* strategy) {
this->strategy = strategy;
}
void processCargo(Cargo cargo) {
strategy->processCargo(cargo);
}
private:
CargoProcessingStrategy* strategy;
};


// паттерн Стратегия для обработки груза на складе

int main(int argc, const char * argv[]) {
    std::string cargo_name, truck_name;
    int N;
    
    std::cout<< "Введите товар для перевозки автотранспортом на склад-> ";
    std::cin>>cargo_name;
    std::cout<< "Введите '1' для перевозки замороженных продуктов, или нажмите любую клавишу -> ";
    std::cin>>N;
    if(N==1){
    truck_name ="Рефрижератор";
    std::cout<<"Для перевозки "<<cargo_name<< " будет использован Рефрижиратор"<<std::endl;
    }else{
        std::cout<<"Для перевозки "<<cargo_name<< " будет использована Бортовая тент"<<std::endl;
    }
    Cargo cargo(cargo_name);
    Truck truck(truck_name);
    CargoProcessingStrategy* strategy;
    if (truck.getTruckType() == "Рефрижератор") {
        strategy = new ColdStorageProcessingStrategy();
    } else {
        strategy = new WholesaleStorageProcessingStrategy();
    }

    CargoProcessor cargoProcessor(strategy);
    cargoProcessor.processCargo(cargo);

   
    
    
    return 0;
}
