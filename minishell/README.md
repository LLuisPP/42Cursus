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
    <td colspan="4" align="center">📦 minishell 📦</td>
  </tr>
  <tr>
    <td align="center">Project</td>
    <td align="center">Bonus</td>
    <td rowspan="2" align="center"><img width="300" src="https://github.com/user-attachments/assets/eeb9a92d-d3ee-4c0f-8d49-609c2f6da845"></td>
  </tr>
  <tr>
    <td><img width="92" src="https://github.com/user-attachments/assets/23788390-25b9-4723-80a6-a41e72e66eac"></td>
    <td><img width="100" src="https://github.com/LLuisPP/42Cursus/assets/116104082/0df7dd81-56fb-4929-a023-67c7386906dc"></td>
  </tr>
</table>

</div>

</div>
<div align="left">

```
1. Inicio
   |
   v
2. Leer Entrada del Usuario (Comando)
   |
   v
3. Parsear Comando
   |
   +--> ¿Contiene operadores (|, >, <, &)? ---> Sí
   |      |                                       |
   |      v                                       |
   |   Dividir en subcomandos                     |
   |   (Tokenización)                             |
   |      |                                       |
   |      v                                       |
   |   Identificar operadores                     |
   |      |                                       |
   |      v                                       |
   |   Preparar para redirección o tuberías       |
   |      |                                       |
   |      v                                       |
   +--> No<-- Ejecutar subcomandos en orden ----> |
          |                                       |
          v                                       v
4. Identificar Comando Interno (cd, exit, history) o Externo
   |
   +--> Comando Interno (Ejecutar directamente)  
   |      |  
   |      v  
   |   Actualizar el entorno o estado del shell
   |      |
   |      v
   +--> Comando Externo (Fork y Exec)
   |      |
   |      v
5. Crear Proceso Hijo (Fork)
   |      |
   |      v
6. Ejecutar Comando en el Proceso Hijo (Exec)
   |      |
   |      v
7. Redirigir Entrada/Salida si es necesario
   |      |
   |      v
8. Esperar a que el Proceso Hijo Termine (Wait)
   |      |
   |      v
9. Procesar el Resultado o Error del Comando
   |
   v
10. Mostrar Output al Usuario
   |
   v
11. ¿Actualizar Historial?
   |
   +--> Sí (Guardar en memoria o archivo)
   |      |
   |      v
   +--> No
          |
          v
12. Vuelve a esperar un nuevo comando
   |
   v
13. Fin

```

</div>
