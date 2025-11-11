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
    <td colspan="4" align="center">🧩 inception 🧩</td>
  </tr>
  <tr>
    <td align="center">Project</td>
    <td align="center">Bonus</td>
    <td rowspan="2" align="center"><a href="#"><img width="250" src=""></a></td>
  </tr>
  <tr>
    <td><a href="#"><img width="100" src="https://github.com/user-attachments/assets/cad19f8d-3b88-4ff6-b7bc-6c1608833a38"></a></td>
    <td><a href="#"><img width="100" src="https://github.com/LLuisPP/42Cursus/assets/116104082/0df7dd81-56fb-4929-a023-67c7386906dc"></a></td>
  </tr>
</table>

</div>
</div>

<div text-align="left">

```mermaid

flowchart LR
    A[Cliente<br/>lprieto-.42.fr] --> NGINX[NGINX<br/>443/TLS]

    NGINX --> WP[WordPress<br/>php-fpm]
    WP --> DB[MariaDB]

    subgraph inception[docker network: inception]
        NGINX
        WP
        DB
    end

    WP --- VWP[( /home/lprieto-/data/wordpress )]
    DB --- VDB[( /home/lprieto-/data/mariadb )]

    ENV[(srcs/.env)] --> WP
    ENV --> DB



```
  
</div>


