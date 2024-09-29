#include <stdio.h>
#include <ctype.h>
#include <string.h>

int acessarRegistradores(char *codigo, int *registradores)
{
    if (strcmp(codigo, "$zero") == 0)
    {
        return 0;
    }
    else if (strcmp(codigo, "$at") == 0)
    {
        return 1;
    }
    else if (strcmp(codigo, "$v0") == 0)
    {
        return 2;
    }
    else if (strcmp(codigo, "$v1") == 0)
    {
        return 3;
    }
    else if (strcmp(codigo, "$a0") == 0)
    {
        return 4;
    }
    else if (strcmp(codigo, "$a1") == 0)
    {
        return 5;
    }
    else if (strcmp(codigo, "$a2") == 0)
    {
        return 6;
    }
    else if (strcmp(codigo, "$a3") == 0)
    {
        return 7;
    }
    else if (strcmp(codigo, "$t0") == 0)
    {
        return 8;
    }
    else if (strcmp(codigo, "$t1") == 0)
    {
        return 9;
    }
    else if (strcmp(codigo, "$t2") == 0)
    {
        return 10;
    }
    else if (strcmp(codigo, "$t3") == 0)
    {
        return 11;
    }
    else if (strcmp(codigo, "$t4") == 0)
    {
        return 12;
    }
    else if (strcmp(codigo, "$t5") == 0)
    {
        return 13;
    }
    else if (strcmp(codigo, "$t6") == 0)
    {
        return 14;
    }
    else if (strcmp(codigo, "$t7") == 0)
    {
        return 15;
    }
    else if (strcmp(codigo, "$s0") == 0)
    {
        return 16;
    }
    else if (strcmp(codigo, "$s1") == 0)
    {
        return 17;
    }
    else if (strcmp(codigo, "$s2") == 0)
    {
        return 18;
    }
    else if (strcmp(codigo, "$s3") == 0)
    {
        return 19;
    }
    else if (strcmp(codigo, "$s4") == 0)
    {
        return 20;
    }
    else if (strcmp(codigo, "$s5") == 0)
    {
        return 21;
    }
    else if (strcmp(codigo, "$s6") == 0)
    {
        return 22;
    }
    else if (strcmp(codigo, "$s7") == 0)
    {
        return 23;
    }
    else if (strcmp(codigo, "$t8") == 0)
    {
        return 24;
    }
    else if (strcmp(codigo, "$t9") == 0)
    {
        return 25;
    }
    else if (strcmp(codigo, "$k0") == 0)
    {
        return 26;
    }
    else if (strcmp(codigo, "$k1") == 0)
    {
        return 27;
    }
    else if (strcmp(codigo, "$gp") == 0)
    {
        return 28;
    }
    else if (strcmp(codigo, "$sp") == 0)
    {
        return 29;
    }
    else if (strcmp(codigo, "$fp") == 0)
    {
        return 30;
    }
    else if (strcmp(codigo, "$ra") == 0)
    {
        return 31;
    }
    else
    {
        printf("Registrador inexistente\n");
        return -1;
    }
}

void tipoI(int opcode, int rs, int rt, int label)
{
    printf("\nOPCODE: %d", opcode);
    printf("\nRS: %d", rs);
    printf("\nRT: %d", rt);
    printf("\nEndereco Imediato: %d", label);
}

void tipoR(int opcode, int rs, int rt, int rd, int shamt, int funct)
{
    printf("\nOPCODE: %d", opcode);
    printf("\nRS: %d", rs);
    printf("\nRT: %d", rt);
    printf("\nRD: %d", rd);
    printf("\nSHAMT: %d", shamt);
    printf("\nFUNCT: %d", funct);
}

void tipoJ(int opcode, int label)
{
    printf("\nOPCODE: %d", opcode);
    printf("\nEndereco: %d", label);
}

int convertLabelToDecimal(long long int pc, char label[])
{
    int decimalValue = 0;
    int length = strlen(label);

    for (int i = 0; i < length; i++)
    {
        decimalValue = decimalValue * 10 + (label[i] - '0');
    }

    pc = decimalValue;

    return pc;
}

void etapasProcessador()
{
    printf("\nEtapa de Busca (FETCH): Buscando a instrucao na memoria. Incrementando o Contador de Programa (PC) para apontar para a proxima instrucao");

    printf("\nEtapa de Decodificacao (DECODE): Decodificando a instrucao obtida na etapa de busca.\nIdentificando os campos da instrucao, como opcode, registradores de origem (rs e rt) e registrador de destino (rd)");

    printf("\nEtapa de execucao (EXECUTE): Executando a instrucao ADD.\nRealizando a operacao de adicao dos valores nos registradores especificados (rs e rt) e armazenando o resultado sem sinal no registrador de destino (rd)");

    printf("\nAtualizacao do Contador de Programa (UPDATE PC): \nAtualizando o Contador de Programa (PC) para apontar para a proxima instrucao. \nPreparando o processador para a execucao da proxima instrucao\n");
}

void toLower(char *operacao)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        operacao[i] = tolower(operacao[i]);
    }
}

void descobreReg(char *registrador)
{
    if (strcmp(registrador, "$s0") == 0 || strcmp(registrador, "$s1") == 0 || strcmp(registrador, "$s2") == 0 || strcmp(registrador, "$s3") == 0 || strcmp(registrador, "$s4") == 0 || strcmp(registrador, "$s5") == 0 || strcmp(registrador, "$s6") == 0 || strcmp(registrador, "$s7") == 0)
    {
        printf("\nRegistradores salvos usados para armazenar valores que precisam ser preservados durante a chamada de funcoes. \nRegistrador: %s", registrador);
    }
    else if (strcmp(registrador, "$t0") == 0 || strcmp(registrador, "$t1") == 0 || strcmp(registrador, "$t2") == 0 || strcmp(registrador, "$t3") == 0 || strcmp(registrador, "$t4") == 0 || strcmp(registrador, "$t5") == 0 || strcmp(registrador, "$t6") == 0 || strcmp(registrador, "$t7") == 0 || strcmp(registrador, "$t8") == 0 || strcmp(registrador, "$t9") == 0)
    {
        printf("\nRegistradores temporarios usados para armazenamento temporario. \nRegistrador: %s", registrador);
    }
    else
    {
        printf("O Registrador informado e diferente de $t0-$t9 e $s0-$s7");
    }
}

int li(long long int pc, int *registradores)
{
    char rDestino[4], escolha[3];
    int valor, opcode = 15;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira valor imediato: ");
    scanf("%d", &valor);

    registradores[r1] = valor;

    printf("\nA instrucao realizada foi LI, utilizando %s como registrador de destino e %d como valor imediato", rDestino, valor);
    printf("\n");

    printf("\nO valor de %d foi salvo em %s.", registradores[r1], rDestino);
    printf("\n");

    pc += 4;

    printf("\nO seu pc foi aumentado em 4, o atual valor do pc e %lld", pc);
    printf("\n");
    tipoI(opcode, r1, 0, valor);
    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int add(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], rOrigem2[4], escolha[3];
    int opcode = 0, funct = 32;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores); // retorna posição do registrador no vetor de registradores
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores); // retorna posição do registrador no vetor de registradores
    if (r2 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r3 = acessarRegistradores(rOrigem2, registradores); // retorna posição do registrador no vetor de registradores
    if (r3 < 0)
        return pc;

    registradores[r1] = registradores[r2] + registradores[r3]; // realiza a operacao

    printf("\nA instrucao realizada foi ADD, utilizando %s como registrador de destino, %s como primeiro registrador de origem e %s como segundo operador de origem", rDestino, rOrigem1, rOrigem2);
    printf("\n");
    printf("\nO valor de %d foi salvo em %s. (%s: %d + %s: %d)", registradores[r1], rDestino, rOrigem1, registradores[r2], rOrigem2, registradores[r3]);

    pc += 4;
    printf("\n");
    printf("\nO seu pc foi aumentado em 4, o atual valor do pc e %lld", pc);
    printf("\n");
    printf("\nOs registradores informados tem a funcionalidade de: ");

    descobreReg(rDestino);

    descobreReg(rOrigem1);

    descobreReg(rOrigem2);
    printf("\n");

    tipoR(opcode, r2, r3, r1, 0, funct);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int addi(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], escolha[3];
    int literal, opcode = 8;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    printf("Insira valor literal: ");
    scanf("%d", &literal);

    registradores[r1] = registradores[r2] + literal;

    printf("\nA instrucao realizada foi ADDI, utilizando %s como registrador de destino, %s como primeiro registrador de origem e %d como valor literal da operacao", rDestino, rOrigem1, literal);
    printf("\n");

    printf("\nO valor de %d foi salvo em %s. (%s: %d + literal: %d)", registradores[r1], rDestino, rOrigem1, registradores[r2] - literal, literal);
    printf("\n");

    pc += 4;

    printf("\nO pc foi atualizado, o atual valor e %lld", pc);
    printf("\n");

    printf("\nOs registradores informados tem a funcionalidade de: ");
    printf("\n");

    descobreReg(rDestino);

    descobreReg(rOrigem1);

    tipoI(opcode, r1, r2, literal);

    printf("\n");
    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int addu(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], rOrigem2[4], escolha[3];
    int resultado = 0, opcode = 0, funct = 33;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r3 = acessarRegistradores(rOrigem2, registradores);
    if (r3 < 0)
        return pc;

    resultado = registradores[r2] + registradores[r3];

    if (resultado < 0)
    {
        resultado = resultado * -1;
    }

    registradores[r1] = resultado;

    printf("\nA instrucao realizada foi ADDU, utilizando %s como registrador de destino, %s como primeiro registrador de origem e %s como segundo operador de origem", rDestino, rOrigem1, rOrigem2);
    printf("\n");

    printf("\nO valor de %d foi salvo em %s. (%s: %d + %s: %d)", registradores[r1], rDestino, rOrigem1, registradores[r2], rOrigem2, registradores[r3]);
    printf("\n");

    pc += 4;

    printf("\nO seu pc foi aumentado em 4, o atual valor do pc e %lld", pc);
    printf("\n");

    printf("\nOs registradores informados tem a funcionalidade de: ");
    printf("\n");

    descobreReg(rDestino);

    descobreReg(rOrigem1);

    descobreReg(rOrigem2);

    printf("\n");

    tipoR(opcode, r2, r3, r1, 0, funct);
    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int sub(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], rOrigem2[4], escolha[3];
    int opcode = 0, funct = 34;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores); // retorna posição do registrador no vetor de registradores
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores); // retorna posição do registrador no vetor de registradores
    if (r2 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r3 = acessarRegistradores(rOrigem2, registradores); // retorna posição do registrador no vetor de registradores
    if (r3 < 0)
        return pc;

    registradores[r1] = registradores[r2] - registradores[r3];

    printf("\nA instrucao realizada foi SUB, utilizando %s como registrador de destino, %s como primeiro registrador de origem e %s como segundo operador de origem", rDestino, rOrigem1, rOrigem2);
    printf("\n");
    printf("\nO valor de %d foi salvo em %s. (%s: %d - %s: %d)", registradores[r1], rDestino, rOrigem1, registradores[r2], rOrigem2, registradores[r3]);

    pc += 4;
    printf("\n");
    printf("\nO seu pc foi aumentado em 4, o atual valor do pc e %lld", pc);
    printf("\n");
    printf("\nOs registradores informados tem a funcionalidade de: ");

    descobreReg(rDestino);

    descobreReg(rOrigem1);

    descobreReg(rOrigem2);

    tipoR(opcode, r2, r3, r1, 0, funct);
    printf("\n");
    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int subu(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], rOrigem2[4], escolha[3];
    int resultado = 0, opcode = 0, funct = 35;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores); // retorna posição do registrador no vetor de registradores
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores); // retorna posição do registrador no vetor de registradores
    if (r2 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r3 = acessarRegistradores(rOrigem2, registradores); // retorna posição do registrador no vetor de registradores
    if (r3 < 0)
        return pc;

    resultado = registradores[r2] - registradores[r3]; // realiza a operacao

    if (resultado < 0)
    {
        resultado = resultado * -1;
    }

    registradores[r1] = resultado;

    printf("\nA instrucao realizada foi SUBU, utilizando %s como registrador de destino, %s como primeiro registrador de origem e %s como segundo operador de origem", rDestino, rOrigem1, rOrigem2);
    printf("\n");

    printf("\nO valor de %d foi salvo em %s. (%s: %d - %s: %d)", registradores[r1], rDestino, rOrigem1, registradores[r2], rOrigem2, registradores[r3]);
    printf("\n");

    pc += 4;

    printf("\nO seu pc foi aumentado em 4, o atual valor do pc e %lld", pc);
    printf("\n");

    printf("\nOs registradores informados tem a funcionalidade de: ");
    printf("\n");

    descobreReg(rDestino);

    descobreReg(rOrigem1);

    descobreReg(rOrigem2);

    printf("\n");

    tipoR(opcode, r2, r3, r1, 0, funct);
    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int mul(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], rOrigem2[4], escolha[3];
    int opcode = 28;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores); // retorna posição do registrador no vetor de registradores
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores); // retorna posição do registrador no vetor de registradores
    if (r2 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r3 = acessarRegistradores(rOrigem2, registradores); // retorna posição do registrador no vetor de registradores
    if (r3 < 0)
        return pc;

    registradores[r1] = registradores[r2] * registradores[r3]; // realiza a operacao

    printf("\nA instrucao realizada foi MUL, utilizando %s como registrador de destino, %s como primeiro registrador de origem e %s como segundo operador de origem", rDestino, rOrigem1, rOrigem2);
    printf("\n");

    printf("\nO valor de %d foi salvo em %s. (%s: %d * %s: %d)", registradores[r1], rDestino, rOrigem1, registradores[r2], rOrigem2, registradores[r3]);
    printf("\n");

    pc += 4;

    printf("\nO seu pc foi aumentado em 4, o atual valor do pc e %lld", pc);
    printf("\n");

    printf("\nOs registradores informados tem a funcionalidade de: ");
    printf("\n");

    descobreReg(rDestino);

    descobreReg(rOrigem1);

    descobreReg(rOrigem2);

    printf("\n");
    tipoR(opcode, r2, r3, r1, 0, 0);
    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int mulo(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], rOrigem2[4], opcode[] = "Opcode: 000000", escolha[3];

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r3 = acessarRegistradores(rOrigem2, registradores);
    if (r3 < 0)
        return pc;

    registradores[r1] = registradores[r2] * registradores[r3];

    printf("\nA instrucao realizada foi MULO, utilizando %s como registrador de destino, %s como primeiro registrador de origem e %s como segundo operador de origem", rDestino, rOrigem1, rOrigem2);
    printf("\n");

    printf("\nO valor de %d foi salvo em %s. (%s: %d * %s: %d)", registradores[r1], rDestino, rOrigem1, registradores[r2], rOrigem2, registradores[r3]);
    printf("\n");

    pc += 4;

    printf("\nO seu pc foi aumentado em 4, o atual valor do pc e %lld", pc);
    printf("\n");

    printf("\nOs registradores informados tem a funcionalidade de: ");
    printf("\n");

    descobreReg(rDestino);

    descobreReg(rOrigem1);

    descobreReg(rOrigem2);

    printf("\n");
    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int mulou(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], rOrigem2[4], opcode[] = "Opcode: 000000", escolha[3];
    int resultado = 0;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores); // retorna posição do registrador no vetor de registradores
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores); // retorna posição do registrador no vetor de registradores
    if (r2 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r3 = acessarRegistradores(rOrigem2, registradores); // retorna posição do registrador no vetor de registradores
    if (r3 < 0)
        return pc;

    resultado = registradores[r2] * registradores[r3]; // realiza a operacao

    if (resultado < 0)
    {
        resultado = resultado * -1;
    }

    registradores[r1] = resultado;

    printf("\nA instrucao realizada foi MULOU, utilizando %s como registrador de destino, %s como primeiro registrador de origem e %s como segundo operador de origem", rDestino, rOrigem1, rOrigem2);
    printf("\n");

    printf("\nO valor de %d foi salvo em %s. (%s: %d * %s: %d)", registradores[r1], rDestino, rOrigem1, registradores[r2], rOrigem2, registradores[r3]);
    printf("\n");

    pc += 4;

    printf("\nO seu pc foi aumentado em 4, o atual valor do pc e %lld", pc);
    printf("\n");

    printf("\nOs registradores informados tem a funcionalidade de: ");
    printf("\n");

    descobreReg(rDestino);

    descobreReg(rOrigem1);

    descobreReg(rOrigem2);

    printf("\n");
    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int div(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], rOrigem2[4], escolha[3];
    int opcode = 26;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r3 = acessarRegistradores(rOrigem2, registradores);
    if (r3 < 0)
        return pc;

    printf("\nA instrucao realizada foi DIV, utilizando %s como registrador de destino, %s como primeiro registrador de origem e %s como segundo operador de origem", rDestino, rOrigem1, rOrigem2);

    pc += 4;

    printf("\nO seu pc foi aumentado em 4, o atual valor do pc e %lld", pc);

    printf("\nOs registradores informados tem a funcionalidade de: ");

    descobreReg(rDestino);

    descobreReg(rOrigem1);

    descobreReg(rOrigem2);

    tipoR(opcode, r2, r3, r1, 0, 0);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int divu(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], rOrigem2[4], escolha[3];
    int resultado = 0, opcode = 27;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r3 = acessarRegistradores(rOrigem2, registradores);
    if (r3 < 0)
        return pc;

    printf("\nA instrucao realizada foi DIVU, utilizando %s como registrador de destino, %s como primeiro registrador de origem e %s como segundo operador de origem", rDestino, rOrigem1, rOrigem2);

    pc += 4;

    printf("\nO seu pc foi aumentado em 4, o atual valor do pc e %lld", pc);

    printf("\nOs registradores informados tem a funcionalidade de: ");

    descobreReg(rDestino);

    descobreReg(rOrigem1);

    descobreReg(rOrigem2);

    tipoR(opcode, r2, r3, r1, 0, 0);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int rem(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], rOrigem2[4], escolha[3];
    int opcode = 26;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r3 = acessarRegistradores(rOrigem2, registradores);
    if (r3 < 0)
        return pc;

    printf("\nA instrucao realizada foi RES, utilizando %s como registrador de destino, %s como primeiro registrador de origem e %s como segundo operador de origem", rDestino, rOrigem1, rOrigem2);

    pc += 4;

    printf("\nO seu pc foi aumentado em 4, o atual valor do pc e %lld", pc);

    printf("\nOs registradores informados tem a funcionalidade de: ");

    descobreReg(rDestino);

    descobreReg(rOrigem1);

    descobreReg(rOrigem2);

    tipoR(opcode, r2, r3, r1, 0, 0);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int remu(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], rOrigem2[4], escolha[3];
    int resultado = 0, opcode = 0, funct = 18;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r3 = acessarRegistradores(rOrigem2, registradores);
    if (r3 < 0)
        return pc;

    printf("\nA instrucao realizada foi REMU, utilizando %s como registrador de destino, %s como primeiro registrador de origem e %s como segundo operador de origem", rDestino, rOrigem1, rOrigem2);

    pc += 4;

    printf("\nO seu pc foi aumentado em 4, o atual valor do pc e %lld", pc);

    printf("\nOs registradores informados tem a funcionalidade de: ");

    descobreReg(rDestino);

    descobreReg(rOrigem1);

    descobreReg(rOrigem2);

    if (resultado < 0)
    {
        resultado = resultado * -1;
    }

    tipoR(opcode, r3, r2, r1, 0, funct);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int move(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], escolha[3];
    int opcode = 35;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o registrador de origem: ");
    scanf("%s", rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    registradores[r1] = registradores[r2];

    printf("\nA instrucao realizada foi MOVE, utilizando %s como registrador de destino e %s como primeiro registrador de origem ", rDestino, rOrigem1);

    pc += 4;

    printf("\nO seu pc foi aumentado em 4, o atual valor do pc e %lld", pc);

    printf("\nOs registradores informados tem a funcionalidade de: ");

    descobreReg(rDestino);

    descobreReg(rOrigem1);

    tipoI(opcode, r1, r2, 0);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int b(long long int pc)
{
    char label[15], escolha[3];
    int opcode = 4;

    printf("Informe label: ");
    scanf("%s", label);
    printf("\nA instrucao realizada foi BRANCH, utilizando a label informada: %s ", label);
    pc = convertLabelToDecimal(pc, label);
    printf("\nO seu pc foi atualizado, o atual valor e %lld.", pc);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    int label1 = convertLabelToDecimal(pc, label);
    tipoJ(opcode, label1);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int j(long long int pc)
{
    char label[15], escolha[3];
    int opcode = 4;

    printf("Informe label: ");
    scanf("%s", label);
    printf("\nA instrucao realizada foi JUMP, utilizando a label informada: %s ", label);
    pc = convertLabelToDecimal(pc, label);
    printf("\nO seu pc foi atualizado, o atual valor e %lld.", pc);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    int label1 = convertLabelToDecimal(pc, label);
    tipoJ(opcode, label1);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int jr(long long int pc, int *registradores)
{
    char escolha[3], rDestino[4];
    int opcode = 0;

    printf("Informe o registrador: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("\nA instrucao realizada foi JR, utilizando o registrador informado: %s ", rDestino);
    pc = registradores[r1];
    printf("\nO seu pc foi atualizado, o atual valor e %lld.", pc);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    tipoJ(opcode, registradores[r1]);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int beq(long long int pc, int *registradores)
{
    char escolha[3], rOrigem1[4], rOrigem2[4], label[26];
    int opcode = 4;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r1 = acessarRegistradores(rOrigem1, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r2 = acessarRegistradores(rOrigem2, registradores);
    if (r2 < 0)
        return pc;

    printf("Informe Label: ");
    scanf("%s", label);

    printf("A instrucao realizada foi BRANCH IF EQUAL, na qual compara o valor do registrador %s (Valor: %d) com o valor do registrador %s (Valor: %d) para ver se sao iguais!", rOrigem1, registradores[r1], rOrigem2, registradores[r2]);

    if (registradores[r1] == registradores[r2])
    {
        printf("\nEssa afirmacao e verdadeira, portanto houve um salto para a label: %s!", label);
        pc = convertLabelToDecimal(pc, label);
        printf("\nO seu pc foi atualizado, o atual valor e %lld.", pc);
        int label1 = convertLabelToDecimal(pc, label);
        tipoI(opcode, r1, r2, label1);
    }
    else
    {
        printf("\nEssa afirmacao e falsa, portanto nao houve um salto para a label: %s, e o PC nao foi atualizado!", label);
        printf("\nValor de PC: %lld", pc);
        int label1 = convertLabelToDecimal(pc, label);
        tipoI(opcode, r1, r2, label1);
    }

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int blt(long long int pc, int *registradores)
{
    char escolha[3], rOrigem1[4], rOrigem2[4], label[26];
    int opcode = 1;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r1 = acessarRegistradores(rOrigem1, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r2 = acessarRegistradores(rOrigem2, registradores);
    if (r2 < 0)
        return pc;

    printf("Informe Label: ");
    scanf("%s", label);

    printf("A instrucao realizada foi BRANCH IF LESS THAN, na qual compara o valor do registrador %s (Valor: %d) com o valor do registrador %s (Valor: %d), para ver se e menor!", rOrigem1, registradores[r1], rOrigem2, registradores[r2]);

    if (registradores[r1] < registradores[r2])
    {
        printf("\nEssa afirmacao e verdadeira, portanto houve um salto para a label: %s!", label);
        pc = convertLabelToDecimal(pc, label);
        printf("\nO seu pc foi atualizado, o atual valor e %lld.", pc);
        int label1 = convertLabelToDecimal(pc, label);
        tipoI(opcode, r1, r2, label1);
    }
    else
    {
        printf("\nEssa afirmacao e falsa, portanto nao houve um salto para a label: %s, e o PC nao foi atualizado!", label);
        printf("\nValor de PC: %lld", pc);
        int label1 = convertLabelToDecimal(pc, label);
        tipoI(opcode, r1, r2, label1);
    }

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int ble(long long int pc, int *registradores)
{
    char escolha[3], rOrigem1[4], rOrigem2[4], label[26];
    int opcode = 6;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r1 = acessarRegistradores(rOrigem1, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r2 = acessarRegistradores(rOrigem2, registradores);
    if (r2 < 0)
        return pc;

    printf("Informe Label: ");
    scanf("%s", label);

    printf("A instrucao realizada foi BRANCH IF LESS OR EQUAL, na qual compara o valor do registrador %s (Valor: %d) com o valor do registrador %s (Valor: %d), para ver se e menor ou igual!", rOrigem1, registradores[r1], rOrigem2, registradores[r2]);

    if (registradores[r1] <= registradores[r2])
    {
        printf("\nEssa afirmacao e verdadeira, portanto houve um salto para a label: %s!", label);
        pc = convertLabelToDecimal(pc, label);
        printf("\nO seu pc foi atualizado, o atual valor e %lld.", pc);
        int label1 = convertLabelToDecimal(pc, label);
        tipoI(opcode, r1, r2, label1);
    }
    else
    {
        printf("\nEssa afirmacao e falsa, portanto nao houve um salto para a label: %s, e o PC nao foi atualizado!", label);
        printf("\nValor de PC: %lld", pc);
        int label1 = convertLabelToDecimal(pc, label);
        tipoI(opcode, r1, r2, label1);
    }

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int bgt(long long int pc, int *registradores)
{
    char escolha[3], rOrigem1[4], rOrigem2[4], label[26];
    int opcode = 7;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r1 = acessarRegistradores(rOrigem1, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r2 = acessarRegistradores(rOrigem2, registradores);
    if (r2 < 0)
        return pc;

    printf("Informe Label: ");
    scanf("%s", label);

    printf("A instrucao realizada foi BRANCH IF GREATER THAN, na qual compara o valor do registrador %s (Valor: %d) com o valor do registrador %s (Valor: %d), para ver se e maior!", rOrigem1, registradores[r1], rOrigem2, registradores[r2]);

    if (registradores[r1] > registradores[r2])
    {
        printf("\nEssa afirmacao e verdadeira, portanto houve um salto para a label: %s!", label);
        pc = convertLabelToDecimal(pc, label);
        printf("\nO seu pc foi atualizado, o atual valor e %lld.", pc);
        int label1 = convertLabelToDecimal(pc, label);
        tipoI(opcode, r1, r2, label1);
    }
    else
    {
        printf("\nEssa afirmacao e falsa, portanto nao houve um salto para a label: %s, e o PC nao foi atualizado!", label);
        printf("\nValor de PC: %lld", pc);
        int label1 = convertLabelToDecimal(pc, label);
        tipoI(opcode, r1, r2, label1);
    }

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int bge(long long int pc, int *registradores)
{
    char escolha[3], rOrigem1[4], rOrigem2[4], label[26];
    int opcode = 5;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r1 = acessarRegistradores(rOrigem1, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r2 = acessarRegistradores(rOrigem2, registradores);
    if (r2 < 0)
        return pc;

    printf("Informe Label: ");
    scanf("%s", label);

    printf("A instrucao realizada foi BRANCH IF GREATER OR EQUAL, na qual compara o valor do registrador %s (Valor: %d) com o valor do registrador %s (Valor: %d), para ver se e menor!", rOrigem1, registradores[r1], rOrigem2, registradores[r2]);

    if (registradores[r1] >= registradores[r2])
    {
        printf("\nEssa afirmacao e verdadeira, portanto houve um salto para a label: %s!", label);
        pc = convertLabelToDecimal(pc, label);
        printf("\nO seu pc foi atualizado, o atual valor e %lld.", pc);
        int label1 = convertLabelToDecimal(pc, label);
        tipoI(opcode, r1, r2, label1);
    }
    else
    {
        printf("\nEssa afirmacao e falsa, portanto nao houve um salto para a label: %s, e o PC nao foi atualizado!", label);
        printf("\nValor de PC: %lld", pc);
        int label1 = convertLabelToDecimal(pc, label);
        tipoI(opcode, r1, r2, label1);
    }

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int bne(long long int pc, int *registradores)
{
    char escolha[3], rOrigem1[4], rOrigem2[4], label[26];
    int opcode = 5;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r1 = acessarRegistradores(rOrigem1, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r2 = acessarRegistradores(rOrigem2, registradores);
    if (r2 < 0)
        return pc;

    printf("Informe Label: ");
    scanf("%s", label);

    printf("A instrucao realizada foi BRANCH IF NOT EQUAL, na qual compara o valor do registrador %s (Valor: %d) com o valor do registrador %s (Valor: %d), para ver se e diferente", rOrigem1, registradores[r1], rOrigem2, registradores[r2]);

    if (registradores[r1] != registradores[r2])
    {
        printf("\nEssa afirmacao e verdadeira, portanto houve um salto para a label: %s!", label);
        convertLabelToDecimal(pc, label);
        pc = printf("\nO seu pc foi atualizado, o atual valor e %lld.", pc);
        int label1 = convertLabelToDecimal(pc, label);
        tipoI(opcode, r1, r2, label1);
    }
    else
    {
        printf("\nEssa afirmacao e falsa, portanto nao houve um salto para a label: %s, e o PC nao foi atualizado!", label);
        printf("\nValor de PC: %lld", pc);
        int label1 = convertLabelToDecimal(pc, label);
        tipoI(opcode, r1, r2, label1);
    }

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int jal(long long int pc, int *registradores)
{
    char escolha[3], label[26];
    int opcode = 3;

    printf("Informe label: ");
    scanf("%s", label);

    printf("\nA instrucao realizada foi JAL, utilizando a label informada: %s ", label);
    convertLabelToDecimal(pc, label);
    printf("\nO seu pc foi atualizado, o atual valor e %lld.", pc);
    int r1 = acessarRegistradores("$ra", registradores);
    if (r1 < 0)
        return pc;
    registradores[r1] = pc;
    printf("\nO valor de PC foi armazenado em %d: %d", r1, registradores[r1]);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);
    int label1 = convertLabelToDecimal(pc, label);
    tipoJ(opcode, label1);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int and (long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], rOrigem2[4], escolha[3];
    int opcode = 0, funct = 36;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r3 = acessarRegistradores(rOrigem2, registradores);
    if (r3 < 0)
        return pc;

    printf("\nA instrucao realizada foi AND, que comparou o registrador %s (Valor: %d) e o registrador %s (Valor: %d), e armazenou o resultado em %s!", rOrigem1, registradores[r2], rOrigem2, registradores[r3], rDestino);

    if (registradores[r2] == registradores[r3])
    {
        registradores[r1] = 1;
        printf("\nO registrador %s e igual ao registrador %s, portanto o registrador %s recebeu o valor: %d", rOrigem1, rOrigem2, rDestino, registradores[r1]);
    }
    else
    {
        registradores[r1] = 0;
        printf("\nO registrador %s nao e igual ao registrador %s, portanto o registrador %s recebeu o valor: %d", rOrigem1, rOrigem2, rDestino, registradores[r1]);
    }

    pc += 4;
    printf("\nO seu pc foi atualizado, o atual valor e %lld.", pc);

    tipoR(opcode, r2, r3, r1, 0, funct);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);
    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int andi(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], escolha[3];
    int literal, opcode = 12;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    printf("Informe o literal: ");
    scanf("%d", &literal);

    printf("\nA instrucao realizada foi ANDI, que comparou o registrador %s (Valor: %d) e o literal: %d, e armazenou o resultado em %s!", rOrigem1, registradores[r2], literal, rDestino);

    if (literal == registradores[r2])
    {
        registradores[r1] = 1;
        printf("\nO registrador %s e igual ao literal: %d, portanto o registrador %s recebeu o valor: %d", rOrigem1, literal, rDestino, registradores[r1]);
    }
    else
    {
        registradores[r1] = 0;
        printf("\nO registrador %s nao e igual ao literal: %d, portanto o registrador %s recebeu o valor: %d", rOrigem1, literal, rDestino, registradores[r1]);
    }

    pc += 4;

    printf("\nO seu pc foi atualizado, o atual valor e %lld.", pc);

    tipoI(opcode, r1, r2, literal);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int negu(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], escolha[3];
    int opcode = 0, funct = 35;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    registradores[r1] = 0 - registradores[r2];

    printf("\nA instrução realizada foi NEGU, quue negou o valor contido no registrador %s (Valor: %d) e armazenou no registrador %s!", rOrigem1, registradores[r2], rDestino);
    printf("\nValor de %s: %d", rDestino, registradores[r1]);

    pc += 4;
    printf("\nO seu pc foi atualizado, o atual valor e %lld", pc);

    tipoR(opcode, r2, 0, r1, 0, funct);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int nor(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], rOrigem2[4], escolha[3];
    int opcode = 39;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r3 = acessarRegistradores(rOrigem2, registradores);
    if (r3 < 0)
        return pc;

    printf("\nA instrucao realizada foi NOR, onde comparou o registrador %s e o registrador %s e armazenou o resultado em %s.", rOrigem1, rOrigem2, rDestino);

    registradores[r1] = ~(registradores[r2] | registradores[r3]);

    printf("\nValor de %s: %d", rDestino, registradores[r1]);

    pc += 4;
    printf("\nO seu pc foi atualizado, o atual valor e %lld", pc);

    tipoR(opcode, r2, r3, r1, 0, 0);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int not(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], escolha[3];
    int opcode = 39;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    printf("\nA instrucao realizada foi NOT, onde negou os bits do valor contido em %s (Valor: %d), e armazenou o resultado em %s.", rOrigem1, registradores[r2], rDestino);

    registradores[r1] = ~(registradores[r2]);

    printf("\nValor de %s: %d", rDestino, registradores[r1]);

    pc += 4;
    printf("\nO seu pc foi atualizado, o atual valor e %lld", pc);

    tipoR(opcode, 0, r2, r1, 0, 0);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int or (long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], rOrigem2[4], escolha[3];
    int opcode = 0, funct = 37;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r3 = acessarRegistradores(rOrigem2, registradores);
    if (r3 < 0)
        return pc;

    printf("\nA instrucao realizada foi OR, onde comparou o registrador %s e o registrador %s e armazenou o resultado em %s.", rOrigem1, rOrigem2, rDestino);

    registradores[r1] = registradores[r2] | registradores[r3];

    printf("\nValor de %s: %d", rDestino, registradores[r1]);

    pc += 4;
    printf("\nO seu pc foi atualizado, o atual valor e %lld", pc);
    tipoR(opcode, r2, r3, r1, 0, funct);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int ori(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], escolha[3];
    int literal, opcode = 13;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    printf("Informe o valor literal: ");
    scanf("%d", &literal);

    printf("\nA instrucao realizada foi ORI, onde comparou o registrador %s com o literal %d e armazenou o resultado em %s.", rOrigem1, literal, rDestino);

    registradores[r1] = registradores[r2] | literal;

    printf("\nValor de %s: %d", rDestino, registradores[r1]);

    pc += 4;
    printf("\nO seu pc foi atualizado, o atual valor e %lld", pc);
    tipoI(opcode, r1, r2, literal);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int xor (long long int pc, int *registradores) {
    char rDestino[4], rOrigem1[4], rOrigem2[4], escolha[3];
    int opcode = 0, funct = 38;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r3 = acessarRegistradores(rOrigem2, registradores);
    if (r3 < 0)
        return pc;

    printf("\nA instrucao realizada foi XOR, que comparou o registrador %s (Valor: %d) e o registrador %s (Valor: %d), e armazenou o resultado em %s!", rOrigem1, registradores[r2], rOrigem2, registradores[r3], rDestino);

    if (registradores[r2] != registradores[r3])
    {
        registradores[r1] = 1;
        printf("\nO registrador %s nao e igual ao registrador %s, portanto o registrador %s recebeu o valor: %d", rOrigem1, rOrigem2, rDestino, registradores[r1]);
    }
    else
    {
        registradores[r1] = 0;
        printf("\nO registrador %s e igual ao registrador %s, portanto o registrador %s recebeu o valor: %d", rOrigem1, rOrigem2, rDestino, registradores[r1]);
    }

    pc += 4;
    printf("\nO seu pc foi atualizado, o atual valor e %lld.", pc);
    tipoR(opcode, r2, r3, r1, 0, funct);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

    int xori(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], escolha[3];
    int literal, opcode = 14;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    printf("Informe o literal: ");
    scanf("%d", &literal);

    printf("\nA instrucao realizada foi XORI, que comparou o registrador %s (Valor: %d) e o literal: %d, e armazenou o resultado em %s!", rOrigem1, registradores[r2], literal, rDestino);

    if (registradores[r2] != literal)
    {
        registradores[r1] = 1;
        printf("\nO registrador %s nao e igual ao literal %d, portanto o registrador %s recebeu o valor: %d", rOrigem1, literal, rDestino, registradores[r1]);
    }
    else
    {
        registradores[r1] = 0;
        printf("\nO registrador %s e igual ao literal %d, portanto o registrador %s recebeu o valor: %d", rOrigem1, literal, rDestino, registradores[r1]);
    }

    pc += 4;
    printf("\nO seu pc foi atualizado, o atual valor e %lld.", pc);
    tipoI(opcode, r1, r2, literal);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int lw(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], escolha[3];
    int opcode = 35;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o registrador de origem: ");
    scanf("%s", rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    registradores[r1] = registradores[r2];

    printf("\nA instrucao realizada foi LOAD WORD, utilizando %s como registrador de destino e %s como primeiro registrador de origem ", rDestino, rOrigem1);

    pc += 4;

    printf("\nO seu pc foi aumentado em 4, o atual valor do pc e %lld", pc);

    printf("\nOs registradores informados tem a funcionalidade de: ");

    descobreReg(rDestino);

    descobreReg(rOrigem1);

    tipoI(opcode, r1, r2, 0);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int sw(long long int pc, int *registradores)
{
    char rDestino[4], rOrigem1[4], escolha[3];
    int opcode = 43;

    printf("Insira o registrador de destino: ");
    scanf("%s", rDestino);

    toLower(rDestino);

    int r1 = acessarRegistradores(rDestino, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o registrador de origem: ");
    scanf("%s", rOrigem1);

    int r2 = acessarRegistradores(rOrigem1, registradores);
    if (r2 < 0)
        return pc;

    registradores[r2] = registradores[r1];

    printf("\nA instrucao realizada foi LOAD WORD, utilizando %s como registrador de destino e %s como primeiro registrador de origem ", rDestino, rOrigem1);

    pc += 4;

    printf("\nO seu pc foi aumentado em 4, o atual valor do pc e %lld", pc);

    printf("\nOs registradores informados tem a funcionalidade de: ");

    descobreReg(rDestino);

    descobreReg(rOrigem1);

    tipoI(opcode, r1, r2, 0);

    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO): ");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int mult(long long int pc, int *registradores)
{
    char rOrigem2[4], rOrigem1[4], escolha[3];
    long long int valor = 0;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r1 = acessarRegistradores(rOrigem1, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r2 = acessarRegistradores(rOrigem2, registradores);
    if (r2 < 0)
        return pc;

    if ((unsigned long long)registradores[r1] > 0xFFFFFFFFFFFFFFFF / registradores[r2])
    {
        printf("Overflow detectado na multiplicação.\n");
        return pc;
    }

    valor = (long long int)registradores[r1] * registradores[r2];

    printf("%lld", valor);

    pc += 4;

    int hi = acessarRegistradores("hi", registradores);
    registradores[hi] = (unsigned int)(valor >> 32);
    int lo = acessarRegistradores("lo", registradores);
    registradores[lo] = (unsigned int)(valor & 0xFFFFFFFF);

    printf("\nA instrução realizada foi MULT, utilizando %s como primeiro registrador de origem e %s como segundo registrador de origem", rOrigem1, rOrigem2);
    printf("\n");

    printf("\nO valor da multiplicação de %s[%d] e %s[%d] foi armazenado nos registradores especiais HI e LO.", rOrigem1, registradores[r1], rOrigem2, registradores[r2]);
    printf("\n");

    printf("\nO seu pc foi aumentado em 4, o atual valor do pc é %d", pc);
    printf("\n");
    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO: )");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int multu(long long int pc, int *registradores)
{
    char rOrigem2[4], rOrigem1[4], escolha[3], rHi[] = "hi", rLo[] = "lo";
    long long int valor = 0;

    printf("Insira o primeiro registrador de origem: ");
    scanf("%s", rOrigem1);

    toLower(rOrigem1);

    int r1 = acessarRegistradores(rOrigem1, registradores);
    if (r1 < 0)
        return pc;

    printf("Insira o segundo registrador de origem: ");
    scanf("%s", rOrigem2);

    toLower(rOrigem2);

    int r2 = acessarRegistradores(rOrigem2, registradores);
    if (r2 < 0)
        return pc;

    if (registradores[r1] < 0)
    {
        registradores[r1] = -registradores[r1];
    }

    else if (registradores[r2] < 0)
    {
        registradores[r2] = -registradores[r2];
    }

    valor = (long long int)registradores[r1] * registradores[r2];

    printf("%lld", valor);

    int hi = acessarRegistradores(rHi, registradores);
    registradores[hi] = (unsigned int)(valor >> 32);
    int lo = acessarRegistradores(rLo, registradores);
    registradores[lo] = (unsigned int)(valor & 0xFFFFFFFF);

    printf("\nA instrução realizada foi MULT, utilizando %s como primeiro registrador de origem e %s como segundo registrador de origem", rOrigem1, rOrigem2);
    printf("\n");

    printf("\nO valor da multiplicação de %s[%d] e %s[%d] foi armazenado nos registradores especiais HI e LO.", rOrigem1, registradores[r1], rOrigem2, registradores[r2]);
    printf("\n");

    pc += 4;

    printf("\nO seu pc foi aumentado em 4, o atual valor do pc é %lld", pc);
    printf("\n");
    printf("\nDeseja ver etapas realizadas pelo processador? (SIM/NAO: )");
    scanf("%s", escolha);

    toLower(escolha);

    if (strcmp(escolha, "sim") == 0)
    {
        etapasProcessador();
    }

    return pc;
}

int verificaOperacao(char *operacao, int pc, int *registradores)
{
    if (strcmp(operacao, "li") == 0)
    {
        pc = li(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "add") == 0)
    {
        pc = add(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "addi") == 0)
    {
        pc = addi(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "beq") == 0)
    {
        pc = beq(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "blt") == 0)
    {
        pc = blt(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "ble") == 0)
    {
        pc = ble(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "bgt") == 0)
    {
        pc = bgt(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "bge") == 0)
    {
        pc = bge(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "bne") == 0)
    {
        pc = bne(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "b") == 0)
    {
        pc = b(pc);
        return pc;
    }
    else if (strcmp(operacao, "j") == 0)
    {
        pc = j(pc);
        return pc;
    }
    else if (strcmp(operacao, "jr") == 0)
    {
        pc = jr(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "addu") == 0)
    {
        pc = addu(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "sub") == 0)
    {
        pc = sub(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "subu") == 0)
    {
        pc = subu(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "mul") == 0)
    {
        pc = mul(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "jr") == 0)
    {
        pc = jal(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "and") == 0)
    {
        pc = and(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "andi") == 0)
    {
        pc = andi(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "negu") == 0)
    {
        pc = negu(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "nor") == 0)
    {
        pc = nor(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "not") == 0)
    {
        pc = not(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "or") == 0)
    {
        pc = or (pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "ori") == 0)
    {
        pc = ori(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "xor") == 0)
    {
        pc = xor(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "xori") == 0)
    {
        pc = xori(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "lw") == 0)
    {
        pc = lw(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "sw") == 0)
    {
        pc = sw(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "mult") == 0)
    {
        pc = mult(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "multu") == 0)
    {
        pc = multu(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "div") == 0)
    {
        pc = div(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "divu") == 0)
    {
        pc = divu(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "rem") == 0)
    {
        pc = rem(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "remu") == 0)
    {
        pc = remu(pc, registradores);
        return pc;
    }
    else if (strcmp(operacao, "move") == 0)
    {
        pc = move(pc, registradores);
        return pc;
    }
    else
        printf("Operacao desconhecida\n");
}

int main()
{
    char operacao[4];
    int pc = 0;
    int registradores[32] = {0};

    for (;;)
    {
        printf("Insira a operacao que deseja realizar OU \"sair\" para encerrar o programa: ");
        scanf("%s", operacao);

        toLower(operacao);
        if (strcmp(operacao, "sair") == 0)
            break;
        pc = verificaOperacao(operacao, pc, registradores);
    }

    return 0;
}
