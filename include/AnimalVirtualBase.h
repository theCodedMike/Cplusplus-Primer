//
// Created by lixia on 2025/10/9.
//

#ifndef ANIMALVIRTUALBASE_H
#define ANIMALVIRTUALBASE_H
#include <iostream>
#include <string>
#include <utility>

class Endangered {
public:
    enum Status { critical, environment, improving };

    explicit Endangered(Status stat = improving)
        :animal_status(stat){}
    virtual ~Endangered() {
        std::cout << "Endangered::~Endangered" << std::endl;
    }
    virtual std::ostream &print(std::ostream&) const {
        return std::cout << "Endangered::print" << std::endl;
    }
    virtual void highlight() const {
        std::cout << "Endangered::highlight" << std::endl;
    }
    // ...
private:
    Status animal_status;
};

class ZooAnimal {
public:
    ZooAnimal() = default;
    ZooAnimal(std::string animal, const bool exhibit, std::string family)
        :nm(std::move(animal)), exhibit_stat(exhibit), fam_name(std::move(family)) {}
    virtual ~ZooAnimal() {
        std::cout << "ZooAnimal::~ZooAnimal" << std::endl;
    }
    virtual std::ostream & print(std::ostream&) const {
        return std::cout << "ZooAnimal::print" << std::endl;
    }
    virtual int population() const {
        std::cout << "ZooAnimal::population" << std::endl;
        return 0;
    }

    std::string name() const {
        return nm;
    }
    std::string family_name() const {
        return fam_name;
    }
    bool on_exhibit() const {
        return exhibit_stat;
    }
    //...
protected:
    std::string nm;
    bool exhibit_stat = false;
    std::string fam_name;
    //...
private:
};

class Raccoon : public virtual ZooAnimal {
public:
    Raccoon() = default;
    Raccoon(std::string name, const bool on_exhibit = true)
        : ZooAnimal(std::move(name), on_exhibit, "Raccoon"){ }

    virtual std::ostream & print(std::ostream&) const {
        return std::cout << "Raccoon::print" << std::endl;
    }
    bool pettable() const {
        return pettable_flag;
    }
    void pettable(const bool petval) {
        pettable_flag = petval;
    }
protected:
    bool pettable_flag = false;
};

class Bear : virtual public ZooAnimal {
public:
    enum DanceType {
        two_left_feet,
        macarena,
        fandango
    };

    Bear(std::string name, const bool on_exhibit = true)
        : ZooAnimal(std::move(name), on_exhibit, "Bear"){}
    virtual ~Bear() {
        std::out << "Bear::~Bear" << std::endl;
    }
    virtual std::ostream & print(std::ostream&) const {
        return std::cout << "Bear::print" << std::endl;
    }
    virtual std::string is_a() const {
        std::cout << "Bear::is_a" << std::endl;
        return "Bear";
    }
    int mumble(int) {
        std::cout << "Bear::mumble" << std::endl;
        return 0;
    }
    void dance(DanceType) const {
        std::cout << "Bear::dance" << std::endl;
    }
protected:
    Bear() : dance_flag(two_left_feet) {}
private:
    std::string name;
    DanceType dance_flag = two_left_feet;
};

class Panda : public Bear, public Raccoon, public Endangered {
public:
    Panda() = default;
    Panda(const std::string& name, const bool on_exhibit = true)
        : ZooAnimal(name, on_exhibit, "Panda"),
          Bear(name, on_exhibit),
          Raccoon(name, on_exhibit),
          Endangered(Endangered::critical),
          sleeping_flag(false) { }
    virtual std::ostream & print(std::ostream&) const {
        return std::cout << "Panda::print" << std::endl;
    }
    bool sleeping() const {
        return sleeping_flag;
    }
    void sleeping(bool newval) {
        sleeping_flag = newval;
    }
protected:
    bool sleeping_flag = false;
};


#endif //ANIMALVIRTUALBASE_H