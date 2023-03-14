# KeyLogger:

## Project Info 📝:

- Date 📅 → Março de 2023
- Collaborators 🧑🏻‍💻 → RiseGhost
- Languages 💻 → C and Python

Este projeto consiste num simples KeyLogger consiga guarda num ficheiro as informações necessárias sobre as teclas pressionadas pelo utilizador e que ao mesmo tempo consiga enviar essas informações para outra maquina conectada na mesma rede local através do protocolo **UDP**.

## Code Implementation 💻:

A implementação deste projeto foi divida nos seguinte ficheiros:

### Keyloger.c:

É o ficheiro principal do projeto. Foi implementado em C e é o responsável por fazer a captação da tecla pressionada pelo utilizador assim como a hora em que foi pressionada.

### server.py:

Ficheiro escrito em python que é responsável por inicializar o “servidor” que irá receber o conteúdo do cliente e mostrar na tela e guardá-lo num ficheiro txt.

### client.py:

Ficheiro escrito em python responsável por enviar para o servido o output da função escrita em C responsável por fazer a captação de teclas.

### UDP:

A conexão UDP foi feita em Python e o computador tenta sempre se conectar ao PC que têm o hostname definido no ficheiros de Python.

```python
import socket
hostname = "TheoGeometric" #Colocar nome do PC que ira ser o servidor
localIP = socket.gethostbyname(hostname)
```

Neste caso o código em Python vai obter o IP do PC com o hostname = “TheoGeometric” e vai tentar fazer a conexão a este servidor. **Isto garante que mesmo que algum dos PCs mude de IP ou mude de rede se consiga conectar ao servidor pois o hostname vai se permanecer constante.**

### Ficheiro de registro de teclas pressionadas:

São criados dois ficheiro de registro de teclas. Um no PC que esta a rodar o keylogger e o outro no PC se esta a receber as informações.

Ficheiro no PC que esta a rodar o keylogger:

![](https://user-images.githubusercontent.com/91985039/225072960-fced596d-b0db-4b78-baf8-93e38ce3ebc9.jpg)

Ficheiro no PC que esta a receber as informações:

![](https://user-images.githubusercontent.com/91985039/225072964-e62af660-3732-43e4-bf99-68f7f896eb78.jpg)

## Link Python to C:

A vinculação em C e Python foi feita compilando o código de C com o seguinte comando:

```bash
gcc -fPIC -shared -o Keyloger.so Keyloger.c
```

E depois importando o ficheiro resultante para o código de python da seguinte maneira:
```Python
import ctypes
clibery = ctypes.CDLL("C:/Users/jomig/OneDrive/Ambiente de Trabalho/JNI/keyloger.so")
func = clibery.KeyPress #Nome da função escrita em C que se pretende executar
func.restype = ctypes.c_char_p #Tipo de return que a função dá
func() #execute func 
```
