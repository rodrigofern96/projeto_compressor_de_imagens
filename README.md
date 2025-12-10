# projeto_compressor_de_imagens
Trabalho - Projeto de Compressor de Imagens em Linguagem C | Professor Daniel | Ciências da Computação

# Projeto de Compressor de Imagens em Linguagem C | Prof° Daniel Ferreira

Um parágrafo da descrição do projeto vai aqui

## 🚀 Começando

Essas instruções permitirão que você obtenha uma cópia do projeto em operação na sua máquina local para fins de desenvolvimento e teste.

Consulte **[Implantação](#-implanta%C3%A7%C3%A3o)** para saber como implantar o projeto.

### 📋 Pré-requisitos

1. Compilador GCC (Usado no Projeto)
2. Terminal Linux ou Powershell
3. Arquivos de imagens .PGM
4. Ferramentas para visualização de imagens (GIMP)

### 🔧 Instalação Inicial

1. Clonar o repositório no Terminal para instalar o repositório Git
2. cd projeto_compressor_de_imagens

### 🔧 Compilando Codificador
1. Acessar o repositório /CodPreOrdem no Terminal
2. No terminal, copiar e colar o seguinte comando:
```   
gcc compressorFunctions.c main.c PGMReaderFunctions.c -o cod
```

### 🔧 Compilando Decodificador
1. Acessar o repositório /DecPreOrdem no Terminal
2. No terminal, copiar e colar o seguinte comando:
```
3. gcc Decodificador.c -o dec

```  


## ⚙️ Executando os testes 

### 🚀 Executando Codificador
```
./cod <imagem_entrada.pgm> <bitstream.dp> <taxadeCompressão> 
``` 

## 🚀 Executando Decodificador

``` 
./dec <bitstream.dp> <imagem_saida.pgm> 
``` 

### 🔩 Analise os testes de ponta a ponta

Explique que eles verificam esses testes e porquê.

```
Dar exemplos
```

### ⌨️ E testes de estilo de codificação

Explique que eles verificam esses testes e porquê.

```
Dar exemplos
```

## 📦 Implantação

Adicione notas adicionais sobre como implantar isso em um sistema ativo

## 🎁 Expressões de gratidão

* Conte a outras pessoas sobre este projeto 📢;
* Convide alguém da equipe para uma cerveja 🍺;
* Um agradecimento publicamente 🫂;
* etc.
