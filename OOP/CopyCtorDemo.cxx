// Type your code here, or load an example.
#include <memory>
#include <string>
#include <iostream>

class Car
{
    public:
    virtual std::string getCarType() = 0;
    virtual ~Car() = default;
};

class PetrolCar : public Car
{
    public:
    PetrolCar() = default;
    virtual ~PetrolCar() = default;
    PetrolCar& operator =(const PetrolCar& anotherCar) noexcept
    {
        if(this != &anotherCar)
        {
            std::cout << "Copy assignment operator called\n";
            this->m_model = anotherCar.m_model;
        }

        return *this;
    }

    PetrolCar(const PetrolCar& anotherCar) noexcept
    {
        std::cout << "Copy ctor called\n";
        this->m_model = anotherCar.m_model;
    }

    PetrolCar& operator =(PetrolCar&& anotherCar) noexcept
    {
        if(this != &anotherCar)
        {
            this->m_model = std::move(anotherCar.m_model);
        }

        return *this;
    }

    PetrolCar(PetrolCar&& anotherCar) noexcept
    {
        this->m_model = std::move(anotherCar.m_model);
    }

    private:
    std::string getCarType() final
    {
        return "Petrol car\n";
    }

    std::string m_model;
};

class ECar : public Car
{
    public:
    virtual ~ECar() = default;

    private:
    std::string getCarType() final
    {
        return "Electric car\n";
    }
};

int main()
{
    PetrolCar car;
    std::unique_ptr<PetrolCar> car2 = std::make_unique<PetrolCar>(car); // calls Copy Constructor
    PetrolCar car3;
    car3 = car3; // calls Copy Assignment Operator

    return 0;
}
