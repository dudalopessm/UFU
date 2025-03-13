	.data
string:	.space 30

	.text
main:
	li 	$v0, 8
    	la 	$a0, string 			# leitura da string
    	li 	$a1, 20
    	syscall

    	li 	$t0, 0

loop:

    	lb 	$t1, string($t0) 		# carrega primeiro caracter da string
    	beq 	$t1, 0, fim 			# se caracter for nulo, string acabou, fim do processo
    
    	blt 	$t1, 'A', minu 			# usa tabela ASCII pra ver se caracter ja é minúsculo, intervalo entre A e Z
    	bgt 	$t1, 'Z', minu 			# usa tabela ASCII pra ver se caracter já é minúsculo, intervalo entre A e Z
    
    	add	$t1, $t1, 32 			# adiciona 32 para transformar o caracter em minúsculo
    	sb 	$t1, string($t0)

minu: 
    	addi 	$t0, $t0, 1 			# incrementa t0 para passar pro próximo caracter
    	j 	loop 				# volta pro loop

fim:
    	li 	$v0, 4
    	la 	$a0, string 			# imprimir string toda minúscula
    	syscall

    	li 	$v0, 10 			# finalizar programa
    	syscall