# ANTI-VÍRUS

<p>
<a href="#sobre">Sobre</a> °
<a href="#tecnologias">Tecnologias</a> °
<a href="#Códigos">Códigos</a> °
<a href="VIdeoEXplicação">Vídeo de explicação</a>°
<a href="Funções">Funções</a> °
</p>



# Sobre
<h2>Esse projeto é um simples Anti-Vírus de arquivos .exe e .bat, que você ao colocar uma pasta, ele filtra para você esses arquivos,esse projeto, foi feito por mim (Ramon) e pela minha dupla (Matheus), fizemos esse projeto em 1 semana, e estamos orgulhosos do resultado, esse projeto foi usados algumas tecnologias que viram a seguir, e os comandos para o projeto estarão logo abaixo, só uma observação, caso você queira rodar o proejto em sua máquina, será necessário baixar o app MinGW, ele ira compilar o arquivo em C para ser executavel, então caso queira testa-ló em sua máquina, está ciente do que é necessário. <h2>

# Tecnologias
<h2>Nesse projeto foram usadas as seguintes tecnologias: </h2>

- [C](https://www.ibm.com/docs/pt/i/7.2?topic=languages-c-c)
- [Node.js](https://nodejs.org/en)
- HTML
- CSS

# Códigos
Para que o código rode sem problemas, primeiro é necessário instalar o Express, com o código abaixo, após isso você precisara baixar o: [MinGW](https://www.mingw-w64.org/downloads/). Após a intalação, você pode fazer o segundo código.

```bash
#Instalação do Express
npm install express

#Transformar o arquivo C em executável
gcc search_files.c -o search_files.exe

#Rodar o projeto na porta 3400
node server.js

#Basta você entrar agora no link http://localhost:3400
```
# Video de Explicação
<video width="640" height="360" controls>
  <source src="./video/VIDEO.wmv" type="video/x-ms-wmv">
  Seu navegador não suporta o formato de vídeo.
</video>

# Funções

- [X] Interface Gráfica
- [X] Comando de filtragem
- [] Sistema de Deletar arquivo