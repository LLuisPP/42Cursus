<div align="center">

<table>
  <tr>
    <th align="center"><a href="https://github.com/LLuisPP/42Cursus/tree/main/"> <img width="30" align="center" src="https://github.com/user-attachments/assets/ac216672-a141-48be-bc53-ae13dd35c799"></a></th>
    <td align="center"> circle 0 </td>
    <td align="center"> circle 1 </td>
    <td align="center"> circle 2 </td>
    <td align="center"> circle 3 </td>
    <td align="center"> circle 4 </td>
    <td align="center"> circle 5 </td>
    <td align="center"> circle 6 </td>
  </tr>
  <tr>
    <td>pjcts</td>
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

[**`netpractice`**]()<br>
[**`miniRT`**]()<br>
[**`cpp`**]()
    </td>
    <td>

[**`ft_irc`**]()<br>
[**`inception`**]()<br>
[**`cpp`**]()
    </td>
    <td>

[**`trascendence`**]()<br>
    </td>
  </tr>
  <tr>
    <td>exam</td>
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

# Minishell

This project involves recreating a simplified version of how the terminal works and the Bash command interpreter.<br>
<h2>👽Space🛸shell team members</h2>

<div align="center">
  
<table>
  <td rowspan="5">
    <a href="https://github.com/Leegon8/minishell"><img width="200" align="center" src="https://github.com/user-attachments/assets/a13492f8-ed80-4d05-996c-9752a4427a32"></a><br><a href="https://github.com/Leegon8/minishell"><img width="200" align="center" src="https://github.com/user-attachments/assets/2d7e0e6c-d78b-41d2-9207-996469406a5d"></a>
  </td>
  <tr>
    <td align="center" width="260">Lauriane González</td>
    <td align="center" width="260">Luis Prieto</td>
  </tr>
  <tr>
    <td align="center"><br> <a href="https://github.com/Leegon8/minishell"><img width="150" src="https://github.com/user-attachments/assets/2e57f619-5dd7-4a7c-8f43-2a05d8d82722" /></a><br><br></td>
    <td align="center"><br> <a href="https://github.com/LLuisPP/42Cursus/tree/main/minishell"><img width="150" src="https://github.com/user-attachments/assets/e9a907a4-e31e-458f-a8c5-823420e87756" /></a><br><br></td>
  </tr>
    <td align="center">Developer</td>
    <td align="center">Developer</td>
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
      • Your own libft and any other functions you've programmed<br>
      <br>
      </td>
  </tr>
</table>
</div>
<br>

# Initial approach and proposal

<h3 weight="bold">Main loop workflow chart for a comand input:</h3>

<img align="center" src="https://github.com/user-attachments/assets/bc4bc3be-dc4b-4e01-93bd-907208ab52fc"></img>

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
    <td>- Structs ✅<br>- Loop in with readline ✅<br>- Set up environment ⭕✅</td>
    <td>- Study signals ⭕<br>- Signal handling ⭕<br>- Write basic tests ⭕✅</td>
    <td>Milestone 1:<br>- Command input ✅<br>- Basic signal handling ⭕✅</td>
  </tr>
  <tr>
    <td align="center">2</td>
    <td>- Tokenizer input ⭕✅<br>- Implement tokenizer ⭕✅<br>- Tokenizer tests ⭕✅</td>
    <td>- Document data and functions ⭕<br>- Implement parser ⭕<br>- Parser tests ⭕</td>
    <td>Milestone 2:<br>- Tokenization and parsing ⭕<br>- Initial integration ❌</td>
  </tr>
  <tr>
    <td align="center">3</td>
    <td>- Implement built-ins ⭕✅<br>- Manage add_history ✅<br>- Built-ins tests ❌</td>
    <td>- Execute external cmds ❌<br>- Handle basic errors ⭕<br>- Built-ins tests ❌</td>
    <td>Milestone 3:<br>- Internal and external cmds ❌<br>- Functional history ✅</td>
  </tr>
  <tr>
    <td align="center">4</td> <td>- I/O redirects (`>`, `<`) ❌<br>- Redirect errors ❌<br>- Document data and functions ❌</td>
    <td>- Exec external cmds with pipes ❌<br>- Pipe tests ❌<br>- Optimize memory leaks-frees ❌</td>
    <td>Milestone 4:<br>- Redirects, pipes, and functions ❌</td>
  </tr>
    <tr> <td align="center">5</td>
      <td>- Advanced signal handling ❌<br>- Env vars getenv ❌<br>- Tests for env/signals/functions ❌</td>
      <td>- Optimize code leak-free ❌<br>- Error handling strerror ❌<br>- Error handling p/strerror ❌</td>
      <td>Milestone 5:<br>- Advanced signals, env vars ❌<br>- Optimized code ❌</td>
    </tr>
    <tr>
      <td align="center">6</td>
      <td>- Integrate functionalities<br>- Exhaustive testing<br>- Document final project</td>
      <td>- Performance and optimization<br>- Verify Makefile and exec</td>
      <td>Milestone 6:<br>- Tested and documented<br>- Norminette, standards</td>
    </tr>
  </table>

</div>
