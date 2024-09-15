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

<table>
  <tr>
    <td colspan="4" align="center">📦 minishell 📦</td>
  </tr>
  <tr>
    <td align="center">Project</td>
    <td align="center">Bonus</td>
    <td rowspan="2" align="center"><img width="300" src="https://github.com/user-attachments/assets/74b0d02f-4192-4ff0-a341-1a8bf7f8d9bd"></td>
  </tr>
  <tr>
    <td><img width="92" src="https://github.com/user-attachments/assets/23788390-25b9-4723-80a6-a41e72e66eac"></td>
    <td><img width="100" src="https://github.com/LLuisPP/42Cursus/assets/116104082/0df7dd81-56fb-4929-a023-67c7386906dc"></td>
  </tr>
</table>

</div>

# Minishell

Este proyecto consiste en recrear una versión simplificada del funcionamiento de la terminal y el lenguaje de bash.<br>
<h2>👽Space🛸shell team members</h2>

<div align="center">
  
<table>
  <tr>
    <td align="center" width="260">Lauriane González</td>
    <td align="center" width="260">Luis Prieto</td>
  </tr>
  <tr>
    <td align="center"><br><img width="150" src="https://github.com/user-attachments/assets/2e57f619-5dd7-4a7c-8f43-2a05d8d82722" /><br><br></td>
    <td align="center"><br><img width="150" src="https://github.com/user-attachments/assets/e9a907a4-e31e-458f-a8c5-823420e87756" /><br><br></td>
  </tr>
    <td align="center">Desarrolladora</td>
    <td align="center">Desarrollador</td>
  </tr>
  <tr>
    <td align="center">42 login: lauriago</td>
    <td align="center">42 login: lprieto-</td>
  </tr>
</table>

</div>

# Description and requirements

<h3 weight="bold">The proyect consists in develop a bash shell like program.</h3>

- It must be written using <b>C</b> and had to be compiled with <b>Makefile</b>.
  - Shell has to behave as original GNU shell, and it can't crash.

<em>Requirements</em> table:

<div align="center">
<table>
  <tr>
    <td align="center" width="100">Language</td>
    <td align="center">Builtins</td>
    <td align="center" width="550">Functions allowed</td>
  </tr>
  <tr>
    <td align="center"><img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="70" height="70"/><br><br><img src="https://github.com/user-attachments/assets/bd668d04-50d1-496a-beb6-2190b1fe9241" alt="makefile" width="50" height="60"/><br>Makefile<br>
    </td>
    <td align="center" width="100">• echo <br> • cd <br> • pwd <br> • export <br> • unset <br> • env <br> • exit <br> </td>
    <td align="left" width="330"><br>
      • readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay <br>
      • add_history, printf, malloc, free, write, access, open, read, close, fork<br>
      • wait, waitpid, wait3, wait4signal, sigaction, sigemptyset, sigaddset, kill<br>
      • exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe<br>
      • opendir, readdir, closedir, strerror, perror, isatty, ttyname, ttyslot<br>
      • ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum<br>
      • tgetstr, tgoto, tputs<br><br>
      <br>
      </td>
  </tr>
</table>
</div>
<br>

# Initial approach and proposal

<h3 weight="bold">Main loop workflow chart for a comand input:</h3>

<img align="center" src="https://github.com/user-attachments/assets/d1577d14-d5cb-4d15-a416-b1d55b44ad54"></img>

# Organization

<h3 weight="bold">Task schedule distribution</h3>

<div align="center">

<table>
  <tr>
    <th>Week</th>
    <th>Member 🅰️</th>
    <th>Member 🅱️</th>
    <th>📍 Milestones 📅</th>
  </tr>
  <tr>
    <td align="center">1</td>
    <td>- Estructs ✅<br>- Bucle in con readline ✅<br>- Configurar entorno ❌</td>
    <td>- Estudiar señales ⭕<br>- Gestión de señales ⭕<br>- Escribir tests básicos ⭕</td>
    <td>Milestone 1:<br>- Entrada de comando ✅<br>- Manejo simple señales ⭕</td>
  </tr>
  <tr>
    <td align="center">2</td>
    <td>- Entrada con tokenizer ❌<br>- Implementar tokenizador ⭕<br>- Tests tokenizador ❌</td>
    <td>- Documentar data y funct ❌<br>- Implementar parser ⭕<br>- Tests para parser ⭕</td>
    <td>Milestone 2:<br>- Tokenización y parsing ❌<br>- Integración inicial ❌</td>
  </tr>
  <tr>
    <td align="center">3</td>
    <td>- Implementar built ins ⭕<br>- Gestionar add_history ✅<br>- Tests history / builts ❌</td>
    <td>- Exec cmds externos ❌<br>- Manejar errores básicos ⭕<br>- Tests history / builts ❌</td>
    <td>Milestone 3:<br>- Cmds int y ext ❌<br>- Historial funcional ✅</td>
  </tr>
  <tr>
    <td align="center">4</td>
    <td>- Redirects E/S (`>`, `<`) ❌<br>- Redirect errors ❌<br>- Documentar data y funct ❌</td>
    <td>- Exec cmds ext con pipes ❌<br>- Tests pipes ❌<br>- Opt memoria leaks-frees ❌</td>
    <td>Milestone 4:<br>- Redirect pipes y funct ❌</td>
  </tr>
  <tr>
    <td align="center">5</td>
    <td>- Manejo advanced señales ❌<br>- Env vars getenv ❌<br>- Tests env/signs/funct ❌</td>
    <td>- Code optimize leak-free ❌<br>- Error handling strerror ❌<br>- Error handle p/strerror ❌</td>
    <td>Milestone 5:<br>- Advcd sig, vars env ❌<br>- Código optimizado ❌</td>
  </tr>
  <tr>
    <td align="center">6</td>
    <td>- Integrar funcionalidades<br>- Pruebas exhaustivas<br>- Documentar proyecto final</td>
    <td>- Rendimiento y optimización<br>- Verificar Makefile y exec</td>
    <td>Milestone 6:<br>- testeado y document<br>- norminette, norma</td>
  </tr>
</table>
</div>
