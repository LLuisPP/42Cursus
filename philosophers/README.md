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
[**`inception`**](https://github.com/LLuisPP/42Cursus/tree/main/inception)<br>
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
    <td colspan="4" align="center">🍽️ philosophers 🍽️</td>
  </tr>
  <tr>
    <td align="center">Project</td>
    <td align="center">Bonus</td>
    <td rowspan="2" align="center"><a href="#"><img width="250" src="https://github.com/user-attachments/assets/d806db09-6f09-4b12-b7f9-f7618ee58326"></a></td>
  </tr>
  <tr>
    <td><a href="#"><img width="100" src="https://github.com/LLuisPP/42Cursus/assets/116104082/504507eb-65b0-4814-9525-a2c22100dab1"></a></td>
    <td><a href="#"><img width="100" src="https://github.com/LLuisPP/42Cursus/assets/116104082/0df7dd81-56fb-4929-a023-67c7386906dc"></a></td>
  </tr>
</table>

</div>
</div>

<div text-align="left">
  
`````
t_table
│
├── nbr_phs     (Número de filósofos)
├── t_to_die    (Tiempo de muerte por inanición)
├── t_to_eat    (Tiempo que tarda en comer)
├── t_to_sleep  (Tiempo que tarda en dormir)
├── meals_req   (Número de comidas necesarias)
├── feast_end   (Señal de final de la simulación)
├── start_t     (Tiempo de inicio de la simulación)
│
├── forks       (Array de mutexes para los tenedores)
│   ├── forks[0] → t_mutex (Mutex para el tenedor 1)
│   ├── forks[1] → t_mutex (Mutex para el tenedor 2)
│   ├── ... 
│   └── forks[nbr_phs-1] → t_mutex (Mutex para el tenedor n)
│
├── start_thds  (Mutex de sincronización inicial)
├── print_m     (Mutex de acceso a imprimir)
├── data_m      (Mutex de acceso a los datos comunes)
│
└── philos      (Array de estructuras de filósofos)
    ├── philos[0] → t_philo
    │   ├── id            → 1
    │   ├── meals_eaten   → 0 (Ejemplo inicial)
    │   ├── feeded        → 0 (Ejemplo inicial)
    │   ├── last_meal     → 0 (Ejemplo inicial)
    │   ├── l_fork        → t_mutex (Mutex para el tenedor izquierdo)
    │   ├── r_fork        → t_mutex (Mutex para el tenedor derecho)
    │   ├── table         → t_table (Apunta de regreso a la estructura `t_table`)
    │   └── thd           → pthread_t (ID del hilo del filósofo 1)
    │
    ├── philos[1] → t_philo
    │   ├── id            → 2
    │   ├── meals_eaten   → 0 (Ejemplo inicial)
    │   ├── feeded        → 0 (Ejemplo inicial)
    │   ├── last_meal     → 0 (Ejemplo inicial)
    │   ├── l_fork        → t_mutex (Mutex para el tenedor izquierdo)
    │   ├── r_fork        → t_mutex (Mutex para el tenedor derecho)
    │   ├── table         → t_table (Apunta de regreso a la estructura `t_table`)
    │   └── thd           → pthread_t (ID del hilo del filósofo 2)
    │
    ├── ... 
    │
    └── philos[nbr_phs-1] → t_philo
        ├── id            → n
        ├── meals_eaten   → 0 (Ejemplo inicial)
        ├── feeded        → 0 (Ejemplo inicial)
        ├── last_meal     → 0 (Ejemplo inicial)
        ├── l_fork        → t_mutex (Mutex para el tenedor izquierdo)
        ├── r_fork        → t_mutex (Mutex para el tenedor derecho)
        ├── table         → t_table (Apunta de regreso a la estructura `t_table`)
        └── thd           → pthread_t (ID del hilo del filósofo n)
`````

</div>
