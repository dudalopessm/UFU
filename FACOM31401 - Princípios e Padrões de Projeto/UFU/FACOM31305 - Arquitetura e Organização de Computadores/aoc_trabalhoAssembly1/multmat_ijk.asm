.data
    A: .float 0:262144  # A[512][512]
    B: .float 0:262144  # B[512][512]
    C: .float 0:262144  # C[512][512], guardará os resultados
    lin: .word 512
    col: .word 512
    const_1: .double 1.0
    msg1: .asciiz "Iniciando preenchimento...\n"
    msg2: .asciiz "Inserção em A e B concluída\n"
    msg3: .asciiz "Iniciando processo de multiplicação...\n"
    msg4: .asciiz "Multiplicacao concluida!"

.text
# main, chama função para preencher matrizes e multiplicações
# ------------------------------------------------------------------------------ #
main:
    # imprimindo mensagem de início
    la $a0, msg1
    li $v0, 4
    syscall
    # declaração de parâmetros - linhas e colunas, serão usados nas 3 funções
    lw $t0, lin  # $t0 = linhas
    lw $t1, col # $t1 = colunas 
    # chama função para preencher as matrizes A e B
    jal preenchimento
    # imprimindo mensagem de quando acaba de preencher
    la $a0, msg2
    li $v0, 4
    syscall
    # imprimindo mensagem para marcar o inicio da multiplicação
    la $a0, msg3
    li $v0, 4
    syscall
    # chama funções para multiplicar - mm é ijk e mm2 é ikj, executadas separadamente na resolução
    jal mm
    jal mm2
    # imprimindo mensagem para marcar o final da multiplicação
    li $v0, 4
    la $a0, msg4
    syscall
    # fim
    li $v0, 10
    syscall

# ------------------------------------------------------------------------------ #
# preenchimento das matrizes A e B
# ------------------------------------------------------------------------------ #
preenchimento:    
    move $s0, $zero  # i = 0
    move $s1, $zero  # j = 0
    li $t2, 1 # carrega 1 para $t2
    l.s $f1, const_1 # $f1 = constante 1
    add.s $f0, $f0, $f1 # $f0 += 1, no caso é o valor
loop1_m1: 
    mul $s2, $s0, $t1 # $s2 = i*colunas
    add $s2, $s2, $s1  # (i*colunas)+j
    sll $s2, $s2, 2  # ((i*colunas)+j)*4
    s.s $f0, A($s2)  # A[i][j] = valor
    s.s $f0, B($s2)  # B[i][j] = valor
    add.s $f0, $f0, $f1 # valor += 1
    addi $s1, $s1, 1  # j++
    bne $s1, $t1, loop1_m1  #  if(j != colunas) então volta pro loop, se não, continua
    move $s1, $zero  # faz com que j volte para a primeira coluna da próxima linha
    addi $s0, $s0, 1  # i++
    bne $s0, $t0, loop1_m1  # if(i != linhas) então volta pro loop, se não, continua sequencial
    jr $ra

# ------------------------------------------------------------------------------ #
# ijk
# ------------------------------------------------------------------------------ #
mm:
    move $s0, $zero # $s0 = i = 0

loop_1:
    bge $s0, $t1, end # if (i >= colunas) desvia para end
    move $s1, $zero  # $s1 = j = 0

loop_2:
    bge $s1, $t1, incrementoI # if (j >= colunas) desvia para o incremento de i (i++)
    move $s2, $zero  # $s2 = k = 0
    li $t3, 0 
    mtc1 $t3, $f1 # $f1 = soma = 0 ($f1)

loop_3:
    bge $s2, $t1, insereC # if (k >= colunas) desvia para a inserção da soma em C[i][j]
    # offset A
    mul $s3, $s0, $t1  # $s3 = i*colunas
    add $s3, $s3, $s2 # $s3 = (i*N)+k
    sll $s3, $s3, 2  # $s3 = ((i*N)+k)*4
    # offset B
    mul $s4, $s2, $t1  # $s4 = k*colunas
    add $s4, $s4, $s1  # $s4 = (k*N)+j
    sll $s4, $s4, 2  # $s4 = ((k*N)+j)*4
    
    l.s $f2, A($s3)
    l.s $f3, B($s4)
    
    # cálculo da soma
    mul.s $f6, $f2, $f3  # $f6 = A[i][k]*B[k][j]
    add.s $f1, $f1, $f6  # $f1(soma) += (A[i][k]*B[k][j])
    addi $s2, $s2, 1  # k++
    blt $s2, $t0, loop_3 # if (k < colunas) volta para o loop de k
    
    # C[i][j] = soma + (A[i][k]*B[k][j])
insereC:
    # offset C    
    mul $s5, $s0, $t1  # $s5 = i*N
    add $s5, $s5, $s1  # $s5 = (i*N)+j
    sll $s5, $s5, 2  # $s5 = ((i*N)+j)*4
    s.s $f1, C($s5)  # C[i][j] = soma = soma + (A[i][k]*B[k][j]) 
    
incrementoJ:    
    addi $s1, $s1, 1  # j++
    j loop_2 # volta para o loop de j
    
incrementoI:    
    addi $s0, $s0, 1  # i++
    j loop_1 # volta para o loop de i
    
end:
    jr $ra  # retorna da função mm

# ------------------------------------------------------------------------------ #
# ikj
# ------------------------------------------------------------------------------ #
mm2:
    move $s0, $zero # $s0 = i = 0

loop_1.2:
    bge $s0, $t1, end2 # if (i >= colunas)vai para o final de ikj
    move $s2, $zero # $s2 = k = 0

loop_2.2:
    bge $s2, $t1, incrementoI2 # if (k >= colunas)vai para o incremento de i
    move $s1, $zero # $s1 = j = 0
    li $t7, 0
    mtc1 $t7, $f0 # $f0 = soma = 0

loop_3.2:
    bge $s1, $t1, adicionaC # if (j >= colunas)vai para a inserção da soma em C
    # offset A
    mul $s3, $s0, $t1  # $s3 = i*N
    add $s3, $s3, $s2  # $s3 = (i*N)+k
    sll $s3, $s3, 2  # $s3 = ((i*N)+k)*4
    # offset B
    mul $s4, $s2, $t1 # $s4 = k * N
    add $s4, $s4, $s1  # $s4 = k * N + j
    sll $s4, $s4, 2    # $s4 = (k * N + j) * 4
    l.s $f2, A($s3)
    l.s $f4, B($s4)
    # cálculo da soma
    mul.s $f6, $f2, $f4   #$f6 = A[i][k]*B[k][j]
    add.s $f0, $f0, $f6   # $f0 += (A[i][k]*B[k][j]) 
    addi $s1, $s1, 1 # j++
    blt $s1, $t0, loop_3.2 # if (j < colunas) volta para o loop de j
    # C[i][j] = soma + (A[i][k] * B[k][j])
adicionaC:    
    mul $s5, $s0, $t1  # $s5 = i*N
    add $s5, $s5, $s1  # $s5 = (i*N)+j
    sll $s5, $s5, 2  # $s5 ((i*N)+j)*4
    s.s $f0, C($s5) # C[i][j] = soma
    
incrementoK2:
    addi $s2, $s2, 1 # k++
    j loop_2.2 # volta para o loop de k
    
incrementoI2:
    addi $s0, $s0, 1 # i++
    j loop_1.2 # volta para o loop de i
    
end2:
    jr $ra  # Retorna da função mm2
# ------------------------------------------------------------------------------ #
