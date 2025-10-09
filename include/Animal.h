//
// Created by lixia on 2025/10/9.
//

#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <utility>

class Endangered {
public:
    virtual ~Endangered() {
        std::cout << "Endangered destructor" << std::endl;
    }
    virtual std::ostream& print() const {
        return std::cout << "Endangered::print" << std::endl;
    }
    virtual void highlight() const {
        std::cout << "Endangered::highlight" << std::endl;
    }
    virtual double max_weight() const {
        std::cout << "Endangered::max_weight" << std::endl;
        return 0;
    }
};

class ZooAnimal {
public:
    ZooAnimal() = default;
    ZooAnimal(std::string animal, const bool exhibit, std::string family)
        : nm(std::move(animal)), exhibit_stat(exhibit), fam_name(std::move(family)) {}
    virtual ~ZooAnimal() {
        std::cout << "Animal destructor" << std::endl;
    }
    virtual std::ostream& print() const {
        return std::cout << "Animal::print" << std::endl;
    }
    virtual int population() const {
        std::cout << "Animal::population" << std::endl;
        return 0;
    }
    virtual double max_weight() const {
        std::cout << "Animal::max_weight" << std::endl;
        return 0;
    }

    [[nodiscard]] std::string name() const {
        return nm;
    }
    [[nodiscard]] std::string family_name() const {
        return fam_name;
    }
    [[nodiscard]] bool on_exhibit() const {
        return exhibit_stat;
    }
protected:
    std::string nm;
    bool exhibit_stat = false;
    std::string fam_name;
private:
    //
};

using DanceType = unsigned;
constexpr DanceType two_left_feet = 0;
constexpr DanceType Astaire = 1;
constexpr DanceType Rogers = 42;
class Bear : public ZooAnimal {
public:
    Bear() = default;
    Bear(std::string name, const bool on_exhibit = true, std::string family = "Bear")
        : ZooAnimal(std::move(name), on_exhibit, std::move(family)), dance_type(two_left_feet) {}

    virtual std::ostream & print() const {
        return std::cout << "Bear::print" << std::endl;
    }
    virtual int toes() const {
        std::cout << "Bear::toes" << std::endl;
        return 0;
    }
    int mumble(int) {
        std::cout << "Bear::mumble" << std::endl;
        return 0;
    }
    void dance(DanceType) const {
        std::cout << "Bear::dance" << std::endl;
    }
    virtual ~Bear() {
        std::cout << "Bear destructor" << std::endl;
    }

private:
    DanceType dance_type = Rogers;
};


class Panda final : public Bear, public Endangered {
public:
    Panda() = default;
    Panda(std::string name, bool on_exhibit = true);
    virtual ~Panda() {
        std::cout << "Panda destructor" << std::endl;
    }
    virtual std::ostream& print() const {
        return std::cout << "Panda::print" << std::endl;
    }
    void highlight() const override {
        std::cout << "Panda::highlight" << std::endl;
    }
    virtual int toes() {
        std::cout << "Panda::toes" << std::endl;
        return 0;
    }
    virtual void cuddle() {
        std::cout << "Panda::cuddle" << std::endl;
    }

    virtual double max_weight() const;
};

inline Panda::Panda(std::string name, const bool on_exhibit)
    :Bear(std::move(name), on_exhibit, "Panda"){ }

inline double Panda::max_weight() const {
    return std::max(ZooAnimal::max_weight(), Endangered::max_weight());
}

class PolarBear final : public Bear {

};
#endif //ANIMAL_H