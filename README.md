# projeto_compressor_de_imagens
Trabalho - Projeto de Compressor de Imagens em Linguagem C | Professor Daniel | Ciências da Computação

# Projeto de Compressor de Imagens em Linguagem C | Prof° Daniel Ferreira

## 🚀 Começando

Com este guia, você poderá preparar o projeto no seu computador, fazer a compilação, rodar tanto o codificador quanto o decodificador, e testar a linha de compressão inteira.

Para saber como usar, consulte a parte que fala sobre a Implantação.

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
gcc Decodificador.c -o dec

```  


## ⚙️ Executando os testes 


### 🚀 Executando Codificador
```
./cod <imagem_entrada.pgm> <bitstream.dp> <taxadeCompressão> 
``` 

### 🚀 Executando Decodificador

``` 
./dec <bitstream.dp> <imagem_saida.pgm> 
``` 

## 📦 Implantação

1. Codificador
2. Decodificador
3. Imagem PGM imagem_entrada.pgm
