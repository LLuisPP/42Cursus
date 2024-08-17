<div align="center">

<table>
  <tr>
    <th align="center"><a href="https://github.com/LLuisPP/42Cursus/tree/main/"> <img width="30" align="center" src="https://github.com/user-attachments/assets/ac216672-a141-48be-bc53-ae13dd35c799"></a></th>
    <td align="center"> circle 0 </td>
    <td align="center"> circle 1 </td>
    <td align="center"> circle 2 </td>
    <td align="center"> circle 3 </td>
    <td align="center"> circle 4 </td>
  </tr>
  <tr>
    <td align="center">pjcts</td>
    <td align="center">

[**`libft`**](https://github.com/LLuisPP/42Cursus/tree/main/libft)
    </td>
    <td align="left">

  [**`born2beRoot`**](https://github.com/LLuisPP/42Cursus/tree/main/Born2beRoot)<br>
  [**`ft_printf`**](https://github.com/LLuisPP/42Cursus/tree/main/ft_printf)<br>
  [**`get_next_line`**](https://github.com/LLuisPP/42Cursus/tree/main/get_next_line)
    </td>
    <td align="left">

[**`push_swap`**](https://github.com/LLuisPP/42Cursus/tree/main/push_swap)<br>
[**`fractol`**](https://github.com/LLuisPP/42Cursus/tree/main/fractol)<br>
[**`pipex`**](https://github.com/LLuisPP/42Cursus/tree/main/pipex)
    </td>
    <td align="left">

[**`philosophers`**](https://github.com/LLuisPP/42Cursus/tree/main/philosophers)<br>
[**`minishell`**](https://github.com/LLuisPP/42Cursus/tree/main/minishell)
    </td>
    <td align="left">

[**`netpractice`**]()<br>
[**`miniRT`**]()<br>
[**`cpp`**]()
    </td>
  </tr>
  <tr>
    <td align="center">exam</td>
    <td></td>
    <td></td>
    <td>
      
[**`rank02`**](https://github.com/LLuisPP/42-Exams/tree/main/rank02)</td>
    <td>
[**`rank03`**](https://github.com/LLuisPP/42-Exams-rank03)</td>
  <td>
    
[**`rank04`**](https://github.com/LLuisPP/42-exams-rank04)</td>
  </tr>
</table>

<div align="center">

<table>
  <tr>
    <td colspan="4" align="center">🍽️ philosophers 🍽️</td>
  </tr>
  <tr>
    <td align="center">Project</td>
    <td align="center">Bonus</td>
    <td rowspan="2" align="center"><img width="250" src="https://github.com/LLuisPP/42Cursus/assets/116104082/cb26ac18-6328-40ec-a147-3ad71afa5e5c"></td>
  </tr>
  <tr>
    <td><img width="100" src="https://github.com/LLuisPP/42Cursus/assets/116104082/0df7dd81-56fb-4929-a023-67c7386906dc"></td>
    <td><img width="100" src="https://github.com/LLuisPP/42Cursus/assets/116104082/0df7dd81-56fb-4929-a023-67c7386906dc"></td>
  </tr>
</table>

</div>

```
t_table
│
├── nbr_phs  (Número de filósofos)
│
├── thds  (Array de identificadores de hilos)
│   ├── thds[0] → pthread_t (ID del hilo para el filósofo 1)
│   ├── thds[1] → pthread_t (ID del hilo para el filósofo 2)
│   ├── ... 
│   └── thds[nbr_phs-1] → pthread_t (ID del hilo para el filósofo n)
│
├── forks  (Array de mutexes para los tenedores)
│   ├── forks[0] → t_mutex (Mutex para el tenedor 1)
│   ├── forks[1] → t_mutex (Mutex para el tenedor 2)
│   ├── ... 
│   └── forks[nbr_phs-1] → t_mutex (Mutex para el tenedor n)
│
└── philos  (Array de estructuras de filósofos)
    ├── philos[0] → t_philo
    │   ├── id → 1
    │   └── table → t_table (Apunta de regreso a la estructura `t_table`)
    │
    ├── philos[1] → t_philo
    │   ├── id → 2
    │   └── table → t_table (Apunta de regreso a la estructura `t_table`)
    │
    ├── ... 
    │
    └── philos[nbr_phs-1] → t_philo
        ├── id → n
        └── table → t_table (Apunta de regreso a la estructura `t_table`)
```

</div>
