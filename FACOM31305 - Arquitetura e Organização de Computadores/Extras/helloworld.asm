# hello world

.data # segmento da memoria para variaveis globais
	palavra: .asciiz "Hello world!" # espaco para a variavel que guarda a string em asciiz porque tem o terminador

.text # segmento da memoria para codigo
	li $v0, 4 # atribui ao reg v0 o valor 4 que configura a syscall para imprimir string na tela
	la $a0, palavra # coloca no reg a0 a variavel palavra
	syscall # chama a operação guardada no v0
	li $v0, 10 # atribui ao v0 o valor 10 que configura a syscall para encerrar o programa
	syscall # executa operação guardada no v0 