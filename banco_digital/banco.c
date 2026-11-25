#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include "meuBanco.h"

Banco banco;

int id_contas = 1000;
int num_clientes = 0;


// Menu inicial do sistema
void menuInicial(void)
{
    int menu;

    do
    {
        printf("\n=====|Menu do Banco|=====\n");

        // Verificacoes feitas sempre que o menu inicial e acessado.
        saldoAlerta();

        printf("\n1 - Cadastrar cliente\n2 - Adicionar conta\n3 - Efetuar transacao\n");
        printf("4 - Consultar historico\n5 - Efetuar sorteio\n6 - Comprar titulo\n7 - Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &menu) != 1)
            return;

        switch (menu)
        {
            case 1:
                menuCadCliente();
                break;

            case 2:
                menuConta();
                break;

            case 3:
                menuTrans();
                break;

            case 4:
                menuHistorico();
                break;

            case 5:
                realizarSorteio();
                break;

            case 6:
                comprarTitulo();
                break;

            case 7:
                printf("Retornando ao inicio.\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (menu != 7);
}


// Cadastro de clientes
void menuCadCliente(void)
{
    char nome_cad[20];

    if (num_clientes >= MAX_CLIENTES)
    {
        printf("Limite de clientes atingido!\n");
        return;
    }

    printf("\n=====|Cadastrar Cliente|=====\n");
    printf("Digite o nome do cliente: ");
    scanf(" %19[^\n]", nome_cad);

    cadCliente(nome_cad);

    printf("Cliente cadastrado!\nCliente: %s\nID: %d\n", nome_cad, id_contas);

    num_clientes++;
    id_contas++;
    banco.quantidadeClientes++;
}


void cadCliente(char nome_c[])
{
    strcpy(banco.clientes[num_clientes].nome, nome_c);
    banco.clientes[num_clientes].id = id_contas;
    banco.clientes[num_clientes].quantidadeContas = 0;
    banco.clientes[num_clientes].possuiEmprestimo = 0;
    banco.clientes[num_clientes].possuiTitulo = 0;
    banco.clientes[num_clientes].quantidadeTransacoes = 0;
}


// Registro de contas
void menuConta(void)
{
    int id_reg;
    int escolha_conta;
    int indice = -1;

    printf("\n=====|Registrar Conta|=====\n");
    printf("Digite o ID de um cliente: ");
    if (scanf("%d", &id_reg) != 1)
        return;

    for (int i = 0; i < num_clientes; i++)
    {
        if (banco.clientes[i].id == id_reg)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("Este cliente nao existe!\n");
        return;
    }

    if (banco.clientes[indice].quantidadeContas >= MAX_CONTAS)
    {
        printf("Este cliente ja possui a quantidade maxima de contas!\n");
        return;
    }

    printf("Cliente: %s\n", banco.clientes[indice].nome);
    printf("1 - Corrente\n2 - Salario\n3 - Poupanca\n");
    printf("Digite o tipo de conta: ");
    if (scanf("%d", &escolha_conta) != 1)
        return;

    if (escolha_conta < 1 || escolha_conta > 3)
    {
        printf("Tipo de conta invalido!\n");
        return;
    }

    for (int j = 0; j < banco.clientes[indice].quantidadeContas; j++)
    {
        int tipo_atual = banco.clientes[indice].contas[j].tipo;

        if (tipo_atual == escolha_conta)
        {
            printf("Este tipo de conta ja existe para este cliente!\n");
            return;
        }

        if ((tipo_atual == 1 && escolha_conta == 2) ||
            (tipo_atual == 2 && escolha_conta == 1))
        {
            printf("Nao e possivel ter conta corrente e salario ao mesmo tempo!\n");
            return;
        }
    }

    addConta(escolha_conta, id_reg);
    banco.clientes[indice].quantidadeContas++;
    printf("Conta criada: %04d-%02d | Saldo: R$ 0.00\n", id_reg, escolha_conta);
}


void addConta(int tipo_con, int num_con)
{
    int id_cliente = num_con - 1000;
    int quant = banco.clientes[id_cliente].quantidadeContas;

    banco.clientes[id_cliente].contas[quant].tipo = tipo_con;
    banco.clientes[id_cliente].contas[quant].numero = (num_con * 100) + tipo_con;
    banco.clientes[id_cliente].contas[quant].saldo = 0.00f;
}


// Transacoes: o usuario escolhe a conta antes da operacao
void menuTrans(void)
{
    int id_trans;
    int num_conta;
    int opcao;
    int indice = -1;
    int indice_conta = -1;

    printf("\n=====|Transacoes|=====\n");
    printf("Digite o ID do cliente: ");
    if (scanf("%d", &id_trans) != 1)
        return;

    for (int i = 0; i < num_clientes; i++)
    {
        if (banco.clientes[i].id == id_trans)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("Este cliente nao existe!\n");
        return;
    }

    printf("Contas de %s:\n", banco.clientes[indice].nome);
    for (int j = 0; j < banco.clientes[indice].quantidadeContas; j++)
    {
        printf("%04d-%02d | Saldo: R$ %.2f\n",
               banco.clientes[indice].id,
               banco.clientes[indice].contas[j].tipo,
               banco.clientes[indice].contas[j].saldo);
    }

    printf("Digite o numero da conta (exemplo: 100001 para 1000-01): ");
    if (scanf("%d", &num_conta) != 1)
        return;

    for (int j = 0; j < banco.clientes[indice].quantidadeContas; j++)
    {
        if (banco.clientes[indice].contas[j].numero == num_conta)
        {
            indice_conta = j;
            break;
        }
    }

    if (indice_conta == -1)
    {
        printf("Esta conta nao existe para este cliente!\n");
        return;
    }

    printf("\n1 - Saque\n2 - Deposito\n3 - Emprestimo\n");
    printf("Escolha: ");
    if (scanf("%d", &opcao) != 1)
        return;

    switch (opcao)
    {
        case 1:
            saque(indice, indice_conta);
            break;

        case 2:
            deposito(indice, indice_conta);
            break;

        case 3:
            emprestimo(indice, indice_conta);
            break;

        default:
            printf("Transacao invalida!\n");
    }
}


void deposito(int cliente, int conta)
{
    float valor;

    printf("Valor do deposito: R$ ");
    if (scanf("%f", &valor) != 1)
        return;

    if (valor <= 0)
    {
        printf("O valor precisa ser positivo!\n");
        return;
    }

    banco.clientes[cliente].contas[conta].saldo += valor;
    registrarTransacao(cliente, 2, valor, banco.clientes[cliente].contas[conta].tipo);
    printf("Deposito realizado! Saldo: R$ %.2f\n", banco.clientes[cliente].contas[conta].saldo);
}


void saque(int cliente, int conta)
{
    float valor;

    printf("Valor do saque: R$ ");
    if (scanf("%f", &valor) != 1)
        return;

    if (valor <= 0)
    {
        printf("O valor precisa ser positivo!\n");
        return;
    }

    // Permite saldo negativo somente na conta corrente.
    if (banco.clientes[cliente].contas[conta].tipo != 1 &&
        valor > banco.clientes[cliente].contas[conta].saldo)
    {
        printf("Saldo insuficiente!\n");
        return;
    }

    banco.clientes[cliente].contas[conta].saldo -= valor;
    registrarTransacao(cliente, 1, valor, banco.clientes[cliente].contas[conta].tipo);
    printf("Saque realizado! Saldo: R$ %.2f\n", banco.clientes[cliente].contas[conta].saldo);
}


// Verifica os requisitos e concede no maximo um emprestimo por cliente
void emprestimo(int cliente, int conta)
{
    int corrente = 0;
    int poupanca = 0;
    float saldo_total = 0;
    float saldo_poupanca = 0;
    float limite;
    float valor;

    if (banco.clientes[cliente].contas[conta].tipo != 1)
    {
        printf("O emprestimo deve ser solicitado pela conta corrente!\n");
        return;
    }

    if (banco.clientes[cliente].possuiEmprestimo)
    {
        printf("Este cliente ja possui um emprestimo!\n");
        return;
    }

    for (int j = 0; j < banco.clientes[cliente].quantidadeContas; j++)
    {
        int tipo = banco.clientes[cliente].contas[j].tipo;
        float saldo = banco.clientes[cliente].contas[j].saldo;

        saldo_total += saldo;

        if (tipo == 1)
            corrente = 1;

        if (tipo == 3)
        {
            poupanca = 1;
            saldo_poupanca = saldo;
        }
    }

    if (!corrente || !poupanca || saldo_poupanca <= 0 || saldo_total <= 0)
    {
        printf("Cliente nao atende aos requisitos para emprestimo!\n");
        return;
    }

    limite = saldo_total * 10 * 0.25f;

    printf("Limite disponivel: R$ %.2f\n", limite);
    printf("Valor solicitado: R$ ");
    if (scanf("%f", &valor) != 1)
        return;

    if (valor <= 0 || valor > limite)
    {
        printf("Valor invalido ou acima do limite!\n");
        return;
    }

    banco.clientes[cliente].contas[conta].saldo += valor;
    banco.clientes[cliente].possuiEmprestimo = 1;
    registrarTransacao(cliente, 3, valor, banco.clientes[cliente].contas[conta].tipo);

    printf("Emprestimo concedido! Novo saldo: R$ %.2f\n",
           banco.clientes[cliente].contas[conta].saldo);
}


// Procura clientes aptos a emprestimo em todas as contas
void emprestimoCheck(void)
{
    for (int i = 0; i < num_clientes; i++)
    {
        int corrente = 0;
        int poupanca = 0;
        float saldo_poupanca = 0;
        float saldo_total = 0;

        for (int j = 0; j < banco.clientes[i].quantidadeContas; j++)
        {
            int tipo = banco.clientes[i].contas[j].tipo;
            float saldo = banco.clientes[i].contas[j].saldo;

            saldo_total += saldo;

            if (tipo == 1)
                corrente = 1;

            if (tipo == 3)
            {
                poupanca = 1;
                saldo_poupanca = saldo;
            }
        }

        if (corrente && poupanca && saldo_poupanca > 0 && saldo_total > 0 &&
            !banco.clientes[i].possuiEmprestimo)
        {
            printf("%s | ID %d | Limite: R$ %.2f\n",
                   banco.clientes[i].nome, banco.clientes[i].id,
                   saldo_total * 10 * 0.25f);
        }
    }
}


// Procura clientes com conta salario e saldo para titulo
void TituloCheck(void)
{
    for (int i = 0; i < num_clientes; i++)
    {
        for (int j = 0; j < banco.clientes[i].quantidadeContas; j++)
        {
            if (banco.clientes[i].contas[j].tipo == 2 &&
                banco.clientes[i].contas[j].saldo >= 1000 &&
                banco.clientes[i].contas[j].saldo <= 1500 &&
                !banco.clientes[i].possuiTitulo)
            {
                printf("%s | ID %d | Saldo salario: R$ %.2f\n",
                       banco.clientes[i].nome, banco.clientes[i].id,
                       banco.clientes[i].contas[j].saldo);
                }
        }
    }
}


// Verifica saldos negativos nas contas correntes
void saldoAlerta(void)
{
    for (int i = 0; i < num_clientes; i++)
    {
        for (int j = 0; j < banco.clientes[i].quantidadeContas; j++)
        {
            if (banco.clientes[i].contas[j].tipo == 1 &&
                banco.clientes[i].contas[j].saldo < 0)
            {
                printf("\nALERTA: %s (ID %d) possui saldo negativo na conta corrente: R$ %.2f\n",
                       banco.clientes[i].nome, banco.clientes[i].id,
                       banco.clientes[i].contas[j].saldo);
            }
        }
    }
}


// Armazena as cinco transacoes mais recentes de cada cliente.
// Colunas: [tipo de operacao, valor, tipo de conta].
void registrarTransacao(int cliente, int tipo, float valor, int tipoConta)
{
    int posicao = banco.clientes[cliente].quantidadeTransacoes;

    if (posicao == MAX_TRANSACOES)
    {
        for (int i = 0; i < MAX_TRANSACOES - 1; i++)
        {
            for (int j = 0; j < 3; j++)
                banco.clientes[cliente].historicoCliente[i][j] =
                    banco.clientes[cliente].historicoCliente[i + 1][j];
        }
        posicao = MAX_TRANSACOES - 1;
    }
    else
        banco.clientes[cliente].quantidadeTransacoes++;

    banco.clientes[cliente].historicoCliente[posicao][0] = tipo;
    banco.clientes[cliente].historicoCliente[posicao][1] = valor;
    banco.clientes[cliente].historicoCliente[posicao][2] = tipoConta;
}


void menuHistorico(void)
{
    int escolha;

    printf("\n=====|Historico|=====\n");
    printf("1 - Historico de um cliente\n2 - Historico geral do banco\n3 - Voltar\nEscolha: ");
    if (scanf("%d", &escolha) != 1)
        return;

    switch (escolha)
    {
        case 1: historicoCliente(); break;
        case 2: historicoGeral(); break;
        case 3: break;
        default: printf("Opcao invalida!\n");
    }
}


void historicoCliente(void)
{
    int id, indice = -1;
    const char *operacoes[] = {"", "Saque", "Deposito", "Emprestimo", "Compra de titulo"};
    const char *contas[] = {"", "Corrente", "Salario", "Poupanca"};

    printf("Digite o ID do cliente: ");
    if (scanf("%d", &id) != 1)
        return;

    for (int i = 0; i < num_clientes; i++)
    {
        if (banco.clientes[i].id == id)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("Cliente nao encontrado!\n");
        return;
    }

    printf("\n== Ultimas transacoes de %s ==\n", banco.clientes[indice].nome);
    if (banco.clientes[indice].quantidadeTransacoes == 0)
        printf("Nenhuma transacao registrada.\n");

    for (int i = 0; i < banco.clientes[indice].quantidadeTransacoes; i++)
    {
        int tipo = (int)banco.clientes[indice].historicoCliente[i][0];
        float valor = banco.clientes[indice].historicoCliente[i][1];
        int tipoConta = (int)banco.clientes[indice].historicoCliente[i][2];

        printf("%d - %s | Valor: R$ %.2f | Conta: %s (%04d-%02d)\n",
               i + 1, operacoes[tipo], valor, contas[tipoConta], id, tipoConta);
    }
}


// Mesmo criterio do alerta, mas somente para contas salario e usado no relatorio.
void saldoCheck(void)
{
    printf("\n== Clientes com Saldo Negativo na Conta Salario ==\n");

    for (int i = 0; i < num_clientes; i++)
    {
        for (int j = 0; j < banco.clientes[i].quantidadeContas; j++)
        {
            if (banco.clientes[i].contas[j].tipo == 2 &&
                banco.clientes[i].contas[j].saldo < 0)
            {
                printf("%s | %04d-%02d | R$ %.2f\n",
                       banco.clientes[i].nome, banco.clientes[i].id,
                       banco.clientes[i].contas[j].tipo,
                       banco.clientes[i].contas[j].saldo);
            }
        }
    }
}


void sorteioCheck(void)
{
    printf("\n== Clientes Contemplados no Sorteio ==\n");

    if (banco.quantidadeEventos == 0)
    {
        printf("Nenhum sorteio realizado.\n");
        return;
    }

    for (int i = 0; i < banco.quantidadeEventos; i++)
        printf("%s\n", banco.historico[i]);
}


void historicoGeral(void)
{
    float saldo_total = 0;

    for (int i = 0; i < num_clientes; i++)
        for (int j = 0; j < banco.clientes[i].quantidadeContas; j++)
            saldo_total += banco.clientes[i].contas[j].saldo;

    printf("\n== Saldo Total do Banco ==\n");
    printf("%d clientes | R$ %.2f\n", num_clientes, saldo_total);

    printf("\n== Clientes Aptos a Emprestimos ==\n");
    emprestimoCheck();

    saldoCheck();

    printf("\n== Clientes Aptos a Compra de Titulos ==\n");
    TituloCheck();

    sorteioCheck();
}


// Compra por ID, independente da conta selecionada anteriormente.
// O enunciado nao informa preco do titulo; registra somente a aquisicao.
void comprarTitulo(void)
{
    int id, indice = -1;

    printf("Digite o ID do cliente que deseja comprar o titulo: ");
    if (scanf("%d", &id) != 1)
        return;

    for (int i = 0; i < num_clientes; i++)
    {
        if (banco.clientes[i].id == id)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("Cliente nao encontrado!\n");
        return;
    }

    if (banco.clientes[indice].possuiTitulo)
    {
        printf("Este cliente ja possui um titulo!\n");
        return;
    }

    for (int j = 0; j < banco.clientes[indice].quantidadeContas; j++)
    {
        if (banco.clientes[indice].contas[j].tipo == 2 &&
            banco.clientes[indice].contas[j].saldo >= 1000 &&
            banco.clientes[indice].contas[j].saldo <= 1500)
        {
            banco.clientes[indice].possuiTitulo = 1;
            registrarTransacao(indice, 4, 0, 2);
            printf("Titulo de capitalizacao adquirido por %s!\n",
                   banco.clientes[indice].nome);
            return;
        }
    }

    printf("Cliente precisa de conta salario com saldo entre R$ 1000 e R$ 1500.\n");
}


// Soma de Fibonacci: F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2).
// O indice usa os dois ultimos digitos da parte inteira do saldo.
// Para evitar estouro de uint64_t, indices acima de 92 sao limitados a 92.
uint64_t fibonacci(int n)
{
    uint64_t anterior = 0, atual = 1, proximo;

    for (int i = 0; i < n; i++)
    {
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }

    return anterior;
}


// Soma modular sem multiplicacao que possa estourar uint64_t.
static uint64_t somaModular(uint64_t a, uint64_t b, uint64_t modulo)
{
    if (a >= modulo - b)
        return a - (modulo - b);
    return a + b;
}


static uint64_t multiplicacaoModular(uint64_t a, uint64_t b, uint64_t modulo)
{
    uint64_t resultado = 0;
    a %= modulo;

    while (b > 0)
    {
        if (b % 2 == 1)
            resultado = somaModular(resultado, a, modulo);

        b /= 2;
        if (b > 0)
            a = somaModular(a, a, modulo);
    }

    return resultado;
}


static uint64_t potenciaModular(uint64_t base, uint64_t expoente, uint64_t modulo)
{
    uint64_t resultado = 1;
    base %= modulo;

    while (expoente > 0)
    {
        if (expoente % 2 == 1)
            resultado = multiplicacaoModular(resultado, base, modulo);

        expoente /= 2;
        if (expoente > 0)
            base = multiplicacaoModular(base, base, modulo);
    }

    return resultado;
}


// Teste deterministico de primalidade para inteiros de 64 bits.
int numeroPrimo(uint64_t numero)
{
    const uint64_t bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    uint64_t d;
    int s = 0;

    if (numero < 2)
        return 0;

    if (numero == 2 || numero == 3)
        return 1;

    if (numero % 2 == 0)
        return 0;

    d = numero - 1;
    while (d % 2 == 0)
    {
        d /= 2;
        s++;
    }

    for (int i = 0; i < 7; i++)
    {
        uint64_t a = bases[i] % numero;
        uint64_t x;
        int passou = 0;

        if (a == 0)
            continue;

        x = potenciaModular(a, d, numero);
        if (x == 1 || x == numero - 1)
            continue;

        for (int j = 1; j < s; j++)
        {
            x = multiplicacaoModular(x, x, numero);
            if (x == numero - 1)
            {
                passou = 1;
                break;
            }
        }

        if (!passou)
            return 0;
    }

    return 1;
}


void realizarSorteio(void)
{
    int participantes[5], ordem[5], usado[5] = {0};
    uint64_t resultados[5];
    double saldos[5];
    int quantidadeTitulos = 0;

    if (num_clientes < 5)
    {
        printf("Sao necessarios pelo menos cinco clientes cadastrados.\n");
        return;
    }

    for (int i = 0; i < num_clientes; i++)
        if (banco.clientes[i].possuiTitulo)
            quantidadeTitulos++;

    if (quantidadeTitulos < 5)
    {
        printf("Sao necessarios pelo menos cinco clientes com titulos.\n");
        return;
    }

    printf("\n=====|Sorteio|=====\n");
    printf("Informe cinco IDs diferentes de clientes com titulo.\n");

    for (int i = 0; i < 5; i++)
    {
        int id, indice = -1;
        printf("ID do participante %d: ", i + 1);
        if (scanf("%d", &id) != 1)
            return;

        for (int j = 0; j < num_clientes; j++)
            if (banco.clientes[j].id == id)
                indice = j;

        if (indice == -1 || !banco.clientes[indice].possuiTitulo)
        {
            printf("Cliente inexistente ou sem titulo. Sorteio cancelado.\n");
            return;
        }

        for (int j = 0; j < i; j++)
            if (participantes[j] == indice)
            {
                printf("IDs repetidos. Sorteio cancelado.\n");
                return;
            }

        participantes[i] = indice;
    }

    for (int i = 0; i < 5; i++)
    {
        int indice = participantes[i];
        long long inteiro;
        int posicao;
        saldos[i] = 0;

        for (int j = 0; j < banco.clientes[indice].quantidadeContas; j++)
            saldos[i] += banco.clientes[indice].contas[j].saldo;

        // Saldos negativos usam o valor absoluto para obter a posicao.
        inteiro = (long long)fabs(saldos[i]);
        posicao = (int)(inteiro % 100);
        if (posicao > 92)
            posicao = 92;

        resultados[i] = fibonacci(posicao);
        printf("%s | Saldo R$ %.2f | F(%d) = %llu\n",
               banco.clientes[indice].nome, saldos[i], posicao,
               (unsigned long long)resultados[i]);
    }

    // Primeiro lugar: maior resultado par.
    // Segundo lugar: maior resultado primo ainda nao selecionado.
    // Terceiro ao quinto: demais resultados em ordem decrescente.
    for (int pos = 0; pos < 5; pos++)
    {
        int melhor = -1;

        for (int i = 0; i < 5; i++)
        {
            if (usado[i])
                continue;
            if (pos == 0 && resultados[i] % 2 != 0)
                continue;
            if (pos == 1 && !numeroPrimo(resultados[i]))
                continue;
            if (melhor == -1 || resultados[i] > resultados[melhor])
                melhor = i;
        }

        if (melhor == -1)
        {
            // Sem candidato ao criterio: preenche com o maior restante.
            for (int i = 0; i < 5; i++)
                if (!usado[i] && (melhor == -1 || resultados[i] > resultados[melhor]))
                    melhor = i;
        }

        ordem[pos] = melhor;
        usado[melhor] = 1;
    }

    printf("\n== Classificacao do Sorteio ==\n");
    for (int i = 0; i < 5; i++)
    {
        int participante = ordem[i];
        int cliente = participantes[participante];
        printf("%do lugar: %s | Fibonacci: %llu\n", i + 1,
               banco.clientes[cliente].nome,
               (unsigned long long)resultados[participante]);
    }

    int vencedor = participantes[ordem[0]];
    uint64_t premio = resultados[ordem[0]];

    if (banco.clientes[vencedor].quantidadeContas == 0)
    {
        printf("Vencedor sem conta. Premio nao concedido.\n");
        return;
    }

    // O saldo e float; um premio gigantesco perderia precisao monetaria.
    if (premio > 1000000000ULL)
    {
        printf("Premio acima do limite monetario seguro (R$ 1 bilhao).\n");
        printf("Classificacao exibida, mas deposito cancelado.\n");
        return;
    }

    banco.clientes[vencedor].contas[0].saldo += (float)premio;
    registrarTransacao(vencedor, 5, (float)premio,
                      banco.clientes[vencedor].contas[0].tipo);

    printf("Premio de R$ %llu depositado na primeira conta de %s.\n",
           (unsigned long long)premio, banco.clientes[vencedor].nome);

    if (banco.quantidadeEventos < MAX_HISTORICO)
    {
        for (int i = 0; i < 5 && banco.quantidadeEventos < MAX_HISTORICO; i++)
        {
            int cliente = participantes[ordem[i]];
            snprintf(banco.historico[banco.quantidadeEventos], 120,
                     "%do | %s | ID %d | Fibonacci %llu | Premio R$ %llu",
                     i + 1, banco.clientes[cliente].nome,
                     banco.clientes[cliente].id,
                     (unsigned long long)resultados[ordem[i]],
                     (unsigned long long)(i == 0 ? premio : 0));
            banco.quantidadeEventos++;
        }
    }
}
