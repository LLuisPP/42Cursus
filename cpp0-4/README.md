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

| Módulo    | Objetivo principal                                 | Conceptos nuevos que enseña                                                                                                                                                                                   | Ejercicios / Clases principales                                                                                 | Qué se evalúa                                                                                                                      |
| :-------- | :------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | :-------------------------------------------------------------------------------------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------- |
| **CPP00** | Primer contacto con C++                            | - Sintaxis básica (namespace `std`)  <br>- I/O (`std::cout`, `std::cin`)  <br>- Clases, métodos y atributos  <br>- Makefile y compilación  <br>- Estructura `.hpp/.cpp`                                       | `megaphone.cpp`, `PhoneBook` (`Contact`), etc.                                                                  | Estructura de proyecto en C++98, encapsulación básica, compilar sin warnings, naming y normas de estilo.                           |
| **CPP01** | Gestión de memoria y composición de objetos        | - Constructores / destructores  <br>- `new` / `delete` y diferencias stack/heap  <br>- Punteros y referencias  <br>- Composición de clases (`HumanA`, `Weapon`, etc.)  <br>- Métodos `const`                  | `Zombie`, `ZombieHorde`, `Weapon`, `HumanA/B`, `Harl`                                                           | Ciclo de vida de los objetos, ownership, paso por referencia, fugas de memoria, comportamiento de objetos interrelacionados.       |
| **CPP02** | Tipos numéricos propios y sobrecarga de operadores | - Sobrecarga (`operator+ - * /`, `operator==`...)  <br>- Copy constructor y `operator=` (Regla de 3)  <br>- Miembros `const` y `static`  <br>- Encapsulación fina                                             | Clase `Fixed` (número de punto fijo)                                                                            | Correcta implementación de operadores, comprensión de copia/asignación, const-correctness, encapsulación.                          |
| **CPP03** | Herencia y especialización                         | - Herencia simple (`: public`)  <br>- Reutilización de código base  <br>- Sobrescritura de métodos  <br>- Llamadas a constructores base  <br>- Comportamiento distinto por clase                              | `ClapTrap` (base) → `ScavTrap` (ex01) → `FragTrap` (ex02)                                                       | Comprensión de jerarquías de clases, especialización de comportamiento, encadenado ctor/dtor, distinción base-derivada.            |
| **CPP04** | Polimorfismo y clases abstractas                   | - Funciones **virtuales** y **sobrescritura dinámica**  <br>- Destructores virtuales  <br>- Clases abstractas (`= 0`)  <br>- Composición (`Brain` en ex01) y deep copy  <br>- **Interfaces y clone()** (ex03) | `Animal`, `Dog`, `Cat`, `Brain` (ex00–ex02) <br>`AMateria`, `Ice`, `Cure`, `ICharacter`, `MateriaSource` (ex03) | Polimorfismo real en C++ (tiempo de ejecución), abstracción, gestión de memoria dinámica, deep copy, implementación de interfaces. |

</div>