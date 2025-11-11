<div align="center">

<div align="center">

<table>
  <tr>
    <td align="center"> circle 0 </td>
    <td align="center"> circle 1 </td>
    <td align="center"> circle 2 </td>
    <td align="center"> circle 3 </td>
    <td align="center"> circle 4 </td>
    <td align="center"> circle 5 </td>
    <td align="center"> circle 6 </td>
  </tr>
  <tr>
    <td>

[**`libft`**](https://github.com/LLuisPP/42Cursus/tree/main/libft)
    </td>
    <td>

  [**`born2beRoot`**](https://github.com/LLuisPP/42Cursus/tree/main/Born2beRoot)<br>
  [**`ft_printf`**](https://github.com/LLuisPP/42Cursus/tree/main/ft_printf)<br>
  [**`get_next_line`**](https://github.com/LLuisPP/42Cursus/tree/main/get_next_line)
    </td>
    <td>

[**`push_swap`**](https://github.com/LLuisPP/42Cursus/tree/main/push_swap)<br>
[**`fractol`**](https://github.com/LLuisPP/42Cursus/tree/main/fractol)<br>
[**`pipex`**](https://github.com/LLuisPP/42Cursus/tree/main/pipex)
    </td>
    <td>

[**`philosophers`**](https://github.com/LLuisPP/42Cursus/tree/main/philosophers)<br>
[**`minishell`**](https://github.com/LLuisPP/42Cursus/tree/main/minishell)
    </td>
    <td>

[**`netpractice`**](https://github.com/LLuisPP/42Cursus/tree/main/netpractice)<br>
[**`cub3D`**](https://github.com/LLuisPP/42Cursus/tree/main/cub3D)<br>
[**`cpp0-4`**](https://github.com/LLuisPP/42Cursus/tree/main/cpp0-4)
    </td>
    <td>

[**`ft_irc`**]()<br>
[**`inception`**]()<br>
[**`cpp5-9`**]()
    </td>
    <td>

[**`trascendence`**]()<br>
    </td>
  </tr>
  <tr>
    <td></td>
    <td></td>
    <td>
      
[**`rank02`**](https://github.com/LLuisPP/42-Exams/tree/main/rank02)</td>
<td>
      
[**`rank03`**](https://github.com/LLuisPP/42-Exams-rank03)</td>
<td>
      
[**`rank04`**](https://github.com/LLuisPP/42-exams-rank04)</td>
<td>
      
[**`rank05`**]()</td>
<td>
  
[**`rank06`**]()</td>
  </tr>
</table>

</div>

<div align="center">
<table>
  <tr>
    <td colspan="5" align="center">🏗️ C++ 0-4 🏗️</td>
  </tr>
  <tr>
    <td align="center">Project</td>
    <td align="center">Bonus</td>
    <td rowspan="2" align="center"><a href="#"><img width="250" src="https://github.com/user-attachments/assets/ced4f304-ad57-4c2c-94e9-e2e253ba1454"></a></td>
  </tr>
  <tr>
    <td><a href="#"><img width="95" src="https://github.com/user-attachments/assets/862ed238-2624-453a-a5cd-c3a8ce3617d3"></a></td>
    <td><a href="#"><img width="100" src="https://github.com/LLuisPP/42Cursus/assets/116104082/0df7dd81-56fb-4929-a023-67c7386906dc"></a></td>
  </tr>
</table>

</div>

<div>

| Module | Main target | Concepts to achieve | Evaluation keys |
| :- | - | - | - |
| **CPP00** | C++ <br> First contact | - Basic syntax (namespace `std`)  <br>- I/O (`std::cout`, `std::cin`)  <br>- Class, methods & atributes  <br>- Makefile & compilation  <br>- Structure `.hpp/.cpp` | Project strcture C++98, <br>basic encapsulation, <br>cpp compile warnings, <br>naming & style norms. | 

<div align="center">
  
```mermaid
classDiagram
    class PhoneBook {
        -Contact contacts[8]
        +addContact()
        +searchContact()
    }

    class Contact {
        -string firstName
        -string lastName
        -string nickname
        -string phoneNumber
        -string darkestSecret
        +getters()
    }

    class Account {
        +makeDeposit()
        +makeWithdrawal()
        +displayStatus()
    }

    PhoneBook *-- Contact

```
</div> 

</div>


<div align="center">
  

</div>

| Module | Main target | Concepts to achieve | Evaluation keys |
| :- | - | - | - |
| **CPP01** | Memory management and object composition | - Constructors / destructors  <br>- `new` / `delete` stack/heap diferencies <br>- Pointers and referencies <br>- Class composition (`HumanA`, `Weapon`, etc.)  <br>- Methodos `const`| Object life cycle, ownership, passing by reference, memory leaks, interrelated objects behavior |

<div align="center">
  
```mermaid
classDiagram
    class Zombie {
        -string name
        +announce()
    }

    class Weapon {
        -string type
        +getType() const
        +setType(string)
    }

    class HumanA {
        -string name
        -Weapon& weapon
        +attack()
    }

    class HumanB {
        -string name
        -Weapon* weapon
        +setWeapon(Weapon)
        +attack()
    }

    class Harl {
        +complain(string)
    }

    HumanA --> Weapon
    HumanB --> Weapon


```

| Module | Main target | Concepts to achieve | Evaluation keys |
| :- | - | - | - |
| **CPP02** | Numerical types and overload operators | - Overload (`operator+ - * /`, `operator==`...)  <br>- Copy constructor & `operator=` (Rule of 3)  <br>- Members `const` y `static`  <br>- Encapsulation |  Correct operator implementation, comprehension of copy/assign, const-correctness, encapsulation |

<div align="center">
  
```mermaid
classDiagram
    class Fixed {
        -int _value
        -static const int _fractionalBits = 8
        +getRawBits() const
        +setRawBits(int)
        +toInt() const
        +toFloat() const
        +operator+(Fixed)
        +operator-(Fixed)
        +operator*(Fixed)
        +operator/(Fixed)
        +operator++()
        +operator--()
        +static min()
        +static max()
    }

    class Point {
        -const Fixed x
        -const Fixed y
        +getX() const
        +getY() const
    }

    Point *-- Fixed


```
</div>

| Module | Main target | Concepts to achieve | Evaluation keys |
| :- | - | - | - |
| **CPP03** | Inerhit and specialization | - Simple inerhit (`: public`)  <br>- Reuse of base codigo <br>- Methods overwrite <br>- Base constructir calls <br>- Different class behavior | Class hierarchy comprehension, behavior specialization, ctor/dtor chain, base-derivate distinction |


<div align="center">
  
```mermaid
classDiagram
    class ClapTrap {
        -string name
        -int hitPoints
        -int energyPoints
        -int attackDamage
        +attack(string)
        +takeDamage(uint)
        +beRepaired(uint)
    }

    class ScavTrap {
        +guardGate()
    }

    class FragTrap {
        +highFivesGuys()
    }

    class DiamondTrap {
        -string name
        +whoAmI()
    }

    ClapTrap <|-- ScavTrap
    ClapTrap <|-- FragTrap
    ScavTrap <|-- DiamondTrap
    FragTrap <|-- DiamondTrap


```
</div>
</div>

| Module | Main target | Concepts to achieve | Evaluation keys |
| :- | - | - | - |
| **CPP04** | Polimorfism and abstract classes | - **Virtual** functions and **dynamic overwrite**  <br>- Virtual destructores <br>- Abstract clases (`= 0`)  <br>- Composition (`Brain` in ex01) & deep copy  <br>- **Interfaces and clone()** (ex03) | `Animal`, `Dog`, `Cat`, `Brain` (ex00–ex02) <br>`AMateria`, `Ice`, `Cure`, `ICharacter`, `MateriaSource` (ex03) | Real polimorfism in C++ (execution time), abstraction, dynamic memory management, deep copy, interface implementation |


<div align="center">
  
```mermaid
classDiagram
    class Animal {
        #string type
        +getType() const
        +makeSound()*
    }

    class Dog {
        +makeSound()
    }

    class Cat {
        +makeSound()
    }

    class WrongAnimal {
        +makeSound()
    }

    class WrongCat {
        +makeSound()
    }

    class Brain {
        -string ideas[100]
    }

    class AMateria {
        #string _type
        +getType() const
        +clone()* 
        +use(ICharacter)
    }

    class Ice {
        +clone()
        +use(ICharacter)
    }

    class Cure {
        +clone()
        +use(ICharacter)
    }

    class ICharacter {
        <<interface>>
        +getName() const
        +equip(AMateria*)
        +unequip(int)
        +use(int, ICharacter)
    }

    class Character {
        -string name
        -AMateria* inventory[4]
    }

    class IMateriaSource {
        <<interface>>
        +learnMateria(AMateria*)
        +createMateria(string)
    }

    class MateriaSource {
        -AMateria* learned[4]
    }

    Animal <|-- Dog
    Animal <|-- Cat
    WrongAnimal <|-- WrongCat
    Dog *-- Brain
    Cat *-- Brain

    AMateria <|-- Ice
    AMateria <|-- Cure

    ICharacter <|.. Character
    Character o-- AMateria

    IMateriaSource <|.. MateriaSource
    MateriaSource o-- AMateria


```
</div>
