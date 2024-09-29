# Projeto MIPS

## Descrição
Este projeto implementa um simulador de um processador MIPS em C. O simulador é capaz de executar um conjunto de instruções MIPS, permitindo a análise e depuração de programas escritos para esta arquitetura. 

### Funcionalidades
- **Execução de Instruções**: Suporta um conjunto básico de instruções MIPS, incluindo operações aritméticas, lógicas, de controle de fluxo e de memória.
- **Depuração**: Permite a visualização do estado dos registradores e da memória após a execução de cada instrução.
- **Carregamento de Programas**: Aceita arquivos de entrada contendo código MIPS para execução.

### Estrutura do Código
O código está organizado da seguinte forma:
- **main.c**: Ponto de entrada do programa. Gerencia a inicialização e o loop principal de execução.
- **cpu.c**: Implementa a lógica do processador, incluindo a execução de instruções.
- **memory.c**: Gerencia a memória do simulador.
- **instructions.c**: Define as instruções suportadas e suas implementações.

### Exemplo de Uso
Para usar o simulador, forneça um arquivo de entrada contendo o código MIPS a ser executado. Por exemplo:

```sh
./simulador entrada.mips
