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
    <td colspan="5" align="center">🌐 netpractice 🌐</td>
  </tr>
  <tr>
    <td align="center">Project</td>
    <td align="center">Bonus</td>
    <td rowspan="2" align="center"><a href="#"><img width="250" src=""></a></td>
  </tr>
  <tr>
    <td><a href="#"><img width="95" src="https://github.com/user-attachments/assets/862ed238-2624-453a-a5cd-c3a8ce3617d3"></a></td>
    <td><a href="#"><img width="100" src="https://github.com/LLuisPP/42Cursus/assets/116104082/0df7dd81-56fb-4929-a023-67c7386906dc"></a></td>
  </tr>
</table>

</div>

<div align=center>

|CIDR|Hosts|Mask|Calculations<br>(brcst+net)|Possible subnets|Subnet size|Valid IPs range<br> without brc/net|
|---|---|---|---|---|---|---|
|`/30`| `255.255.255.252` | `2` <br>hosts| MASK<br> 256 - 252 = 4 - 2 = `2` <br>CIDR<br> 32 - 30 = 2 <br>2^2 = 4 - 2 = `2` |30 - 24 = 6 <br> 2^6 = `64`|4 IPs|network: `192.168.1.0`<br>`192.168.1.1`<br>`192.168.1.2`<br>broadcast: `192.168.1.3`|
|`/29`| `255.255.255.248` | `6` <br>hosts| MASK<br> 256 - 248 = 8 - 2 = `6` <br>CIDR<br> 32 - 29 = 3 <br>2^3 = 8 - 2 = `6` |29 - 24 = 5 <br> 2^5 = `32`|8 IPs|network: `192.168.1.0`<br>`192.168.1.1`<br>`192.168.1.6`<br>broadcast: `192.168.1.7`|
|`/28`| `255.255.255.240` | `14` <br>hosts| MASK<br> 256 - 240 = 16 - 2 = `14` <br>CIDR<br> 32 - 28 = 4 <br>2^4 = 16 - 2 = `14` |28 - 24 = 4 <br> 2^4 = `16`|16 IPs|network: `192.168.1.0`<br>`192.168.1.1`<br>`192.168.1.14`<br>broadcast: `192.168.1.15`|
|`/27`| `255.255.255.224` | `30` <br>hosts| MASK<br> 256 - 224 = 32 - 2 = `30` <br>CIDR<br> 32 - 27 = 5 <br>2^5 = 32 - 2 = `30` |27 - 24 = 3 <br> 2^3 = `8`|32 IPs|network: `192.168.1.0`<br>`192.168.1.1`<br>`192.168.1.30`<br>broadcast: `192.168.1.31`|
|`/26`| `255.255.255.192` | `62` <br>hosts| MASK<br> 256 - 192 = 64 - 2 = `62` <br>CIDR<br> 32 - 26 = 6 <br>2^6 = 64 - 2 = `62` |26 - 24 = 2 <br> 2^2 = `4`|64 IPs|network: `192.168.1.0`<br>`192.168.1.1`<br>`192.168.1.62`<br>broadcast: `192.168.1.63`|
|`/25`| `255.255.255.128` | `126` <br>hosts| MASK<br> 256 - 128 = 128 - 2 = `126` <br>CIDR<br> 32 - 25 = 7 <br>2^7 = 128 - 2 = `126` |25 - 24 = 1 <br> 2^1 = `2`|128 IPs|network: `192.168.1.0`<br>`192.168.1.1`<br>`192.168.1.126`<br>broadcast: `192.168.1.127`|
|`/24`| `255.255.255.0` | `254` <br>hosts| MASK<br> 256 - 0 = 256 - 2 = `254` <br>CIDR<br> 32 - 24 = 8 <br>2^8 = 256 - 2 = `254` |24 - 24 = 0 <br> 2^0 = `1`|256 IPs|network: `192.168.1.0`<br>`192.168.1.1`<br>`192.168.1.254`<br>broadcast: `192.168.1.255`|




</div>


