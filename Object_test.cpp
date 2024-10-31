/*

Short explenation of how Object Oriented Programming (Oop) is working inside c++ language

This chaotic explenation was done to help me understand:

    - Classes and objects
    - Access modifiers
    - Constructors
    - Encapsulation
    - Abstraction
    - Inheritance 
    - Polymorphism

Propably only I will understand the mess inside this file

*/

#include <iostream>

using std::string;

class AbstractEmployee  //Abstract class or contract
{
    virtual void AskForPromotion() = 0; // virtual/abstract function
};



class Employee: AbstractEmployee // Class is an object
{
       

    private:

       // <- encapsulation 
    string Company;
    int Age;

    protected:
    string Name; 

    public:
    // string Name;
    // string Company;
    // int Age;

    void setName(string name) // <- encapsulation 
    {
        Name = name; // setter
    }

    string getName()
    {
        return Name; // getter
    }

    void setCompany(string company)
    {
        Company = company;
    }

    string getCompany()
    {
        return Company;
    }

    void setAge(int age)
    {
        // validation rule

        if(age >= 18)
        {
            Age = age;
        }
        
    }

    int getAge()
    {
        return Age;
    }

    void IntroduceYoutself() // in class you can create a function to display information of the class.
    {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

    // constructor
    // construcotr is working simillarly as a prototype in C (initialize the value of object) (as I understand it right now)
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
  
  
    void AskForPromotion()
    {
        if(Age > 30)
        {
            std::cout << Name << " got promoted!" << std::endl;
        }
        else
        {
            std::cout << Name << " sorry, no promotion for you." << std::endl;
        }
    }


  virtual void Work()   // polimorphism example
    {
        std::cout << Name << " is checking email, task backlog, performing tasks..." << std::endl;

    }


};



class Developer : public Employee
{
private:
    /* data */
public:
string prog_language;

Developer(string name, string company, int age, string language)
    : Employee(name, company, age)
{
    prog_language = language;
}

    void FixBub()
    {
        std::cout << getName() << " fixed bug using " << prog_language << std::endl;
    }
    void Work()   // polimorphism example
    {
        std::cout << Name << " is writing " << prog_language << " code " << std::endl;

    }



};

class Teacher : public Employee
{   
    public:
    string Subject;

    void PrepareLesson()
    {
        std::cout << getName() << " is preparing lesson on " << Subject << std::endl;
    }
    Teacher (string name, string company, int age, string subject)
        : Employee(name, company, age)
    {
        Subject = subject;
    }

    void Work()   // polimorphism example
    {
        std::cout << Name << " is teaching " << Subject << std::endl;

    }
};



int main()
{
    Employee employee1 = Employee("Mikolaj", "YT-Quel", 25); // This is how we pass arguments to the constructor located in class. 

    // emplyee1.Name = "Mikolaj";
    // emplyee1.Company = "YT-Quel";   
    // emplyee1.Age = 25;

    employee1.IntroduceYoutself();

    Employee employee2 = Employee("Jon", "Amazon", 33);

    // employee2.Name = "Jon";
    // employee2.Company = "Amazon";
    // employee2.Age = 33;

    employee2.IntroduceYoutself();


    employee1.setAge(15);
    std::cout<<employee1.getName()<<" is "<<employee1.getAge()<< " years old"<<std::endl;



    employee1.AskForPromotion();
    employee2.AskForPromotion();



    Developer dev = Developer("Mikolaj", "YT-Quel", 25, "C");
    dev.FixBub();

    dev.AskForPromotion();

    Teacher teacher = Teacher("Jack", "Cool School", 35, "History");
    teacher.PrepareLesson();

    teacher.AskForPromotion();

    // dev.Work();
    // teacher.Work();

    /*
    The most common use of polymorphism is when a parent class reference
    is used to refere to a child class object
    */

   Employee *emp1 = &dev; //  polymorphismm
   Employee *emp2 = &teacher;

   emp1 -> Work();
   emp2 -> Work();
}

