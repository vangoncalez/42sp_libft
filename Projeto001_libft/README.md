# Libft (Arquivo em desenvolvimento)
O objetivo desse projeto foi montar uma biblioteca pessoal, reescrevendo os códigos propostos e compilando-os com o auxílio de um Makefile.
<br/>
<br/>
<br/>

# Makefile
## Criação do Makefile
1. O que é e para que serve?

    Um makefile é um arquivo especial, contendo comandos shell que informam ao sistema o que você deseja executar. Na maioria das vezes são comandos para compilar, recompilar, criar ou apagar arquivos, automatizando algumas tarefas. O arquivo Makefile não possui extensão, devendo ser nomeado apenas como *Makefile*. O arquivo é lido por um utilitário chamado Make.

1. Estrutura

    A Estrutura do Makefile é baseada em 3 pontos:<br>

       alvo: pré-requisitos
         instruções

    * Alvo: geralmente é o nome de uma ação, como por exemplo: *clean*. Ou ainda, o nome de um arquivo executável ou grupo de arquivos.

    * Pré-requisitos: geralmente são os alvos que devem ser executados antes da execução do alvo em questão.

    * Instruções: lista de instruções, regras ou comandos que o sistema deve executar (sempre identado com um *\<tab\>*).

1. Como o make lê o arquivo Makefile

    Por padrão, o utilitário make inicia no primeiro alvo (desconsiderando os alvos iniciados por '.').
    E então o make compara a hora de modificação
    do arquivo do alvo com os horários de modificação dos arquivos de dependência (pré-requisitos).
    <br>Qualquer arquivo de dependência que
    tem um horário de modificação mais recente que o arquivo do alvo, o forçará a ser recriado.

1. Alvos padrões:

    Existem vários alvos padrões descritos no manual. Vou citar dois deles aqui:

    * *all*: geralmente o destino padrão, onde colocamos instruções para executar todo o programa.
    * *clean*: é o destino onde colocamos instruções para apagar todos os arquivos criados na compilação. No caso do projeto Libft da 42, coloquei para apagar todos os arquivos '.o' criados pelo sistema, mas não o arquivo '.a' gerado.
    Caso seja necessário acessar um alvo específico, basta digitar: make nome_do_alvo.
    Mais informações sobre alvos padrões no [Manual da GNU](https://www.gnu.org/software/make/manual/html_node/Standard-Targets.html#Standard-Targets):

1. Variáveis:

    As variáveis podem ser definidas através do '=', conforme o exemplo:

        NOME_DA_VARIAVEL = VALOR_DA_VARIAVEL

    Para acessá-la, podemos utilizar:

        ${NOME_DA_VARIAVEL}

## Explicação detalhada do Makefile da Libft
Defini uma variável chamada NAME, cujo valor é nome do arquivo compilado da biblioteca:

    NAME	= libft.a

Em seguida, atribuí a uma variável, todos os arquivos fontes (SRCS - Sources). Apenas para manter organizado, incluí um por linha com o auxílio da \ . Mas pode deixar na mesma linha separado por espaços:

    SRCS	=	ft_atoi.c \
		ft_bzero.c \
        ...

Em seguida defini uma variável chamada OBJS, que obtém os arquivos terminados em .c que estão na variável SRCS e cria os arquivos .o

    OBJS	= ${SRCS:.c=.o}

A variável CC é para definir qual compilador será usado, neste caso o clang.

    CC		= clang

Para a variável CFLAGS, atribuí as Flags usadas na compilação.

    CFLAGS	= -Wall -Wextra -Werror -g

Esta instrução abaixo, apesar de ser o primeiro alvo, não será lido, porque é regra de sufixo. Segundo o manual, essa é a maneira mais antiquada de fazer isso, mas segue nesse makefile de qualquer maneira. Regra de sufixo, neste caso .c.o significa que ambos os arquivos terminados em .c e .o obedecerão às regras. (...)

    .c.o:
        ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

O primeiro alvo do meu arquivo makefile, é o nome de uma variável, ou seja, é como se eu estivesse atribuindo ao alvo, o nome de libft.a, cujos pré-requisitos são os arquivos obtidos na variável OBJS. E em seguida a instrução para a criação do arquivo libft.a com os arquivos que estão em OBJS. O comando 'ar' cria o arquivo. '-rcs' são as opções replace, create e sort. Que basicamente seria, o 'r' substiuti o arquivo se já tiver sido criado, o 'c' cria, caso não tenha sido criado e o 's' faz um index dos arquivos inseridos.

    ${NAME}:	${OBJS}
                ar -rcs ${NAME} ${OBJS}

Instrução para executar todo o código.

    all:		${NAME}

Instrução para apagar os arquivos .o

    clean:
        rm -f ${OBJS}

Instrução para apagar o arquivo .a

    fclean: clean
        rm -f ${NAME}

Instrução para apagar os arquivos .c,  .o e em seguida executar tudo novamente.

    re: fclean all

Este alvo, criei para executar os meus testes. Não é necessário entregar junto com o projeto.

    test: all
        ${CC} ../main/main.c  -L. -lft -o ../main/teste
        ./../main/teste

O alvo .PHONY serve para indicar os chamados alvos falsos. O phony é usado, se por ventura existir um arquivo chamado clean, por exemplo, para que este não seja executado no lugar das instruções.

    .PHONY: all, clean, fclean, re


<br/>
<br/>
<br/>


# Funções (incompleta... a finalizar)

## ft_atoi

Protótipo | int	ft_atoi(char *str)
:------------ | :-------------
Descrição | A função ft_atoi converte uma string em um número inteiro (tipo int).


