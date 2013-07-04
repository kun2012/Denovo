.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
li $v0, 4
la $a0, _prompt
syscall
li $v0, 5
syscall
jr $ra

write:
li $v0, 1
syscall
li $v0, 4
la $a0, _ret
syscall
move $v0, $0
jr $ra

main:
move $fp, $sp
addi $sp, $sp, -400
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
move $t0, $v0
addi $sp, $sp, -4
li $t1, 0
label1:
blt $t1, $t0, label2
j label3
label2:
addi $sp, $sp, -4
li $s7, 4
mul $t2, $t1, $s7
addi $sp, $sp, -4
lw $t4, -400($fp)
addi $t4, $fp, -400
add $t3, $t2, $t4
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
move $t5, $v0
sw $t5, 0($t3)
addi $t1, $t1, 1
j label1
label3:
label4:
li $s7, 0
bgt $t1, $s7, label5
j label6
label5:
addi $t1, $t1, -1
addi $sp, $sp, -4
li $s7, 4
mul $t6, $t1, $s7
addi $sp, $sp, -4
addi $t4, $fp, -400
add $t7, $t6, $t4
addi $sp, $sp, -4
lw $t8, 0($t7)
addi $sp, $sp, -4
sw $ra, 0($sp)
move $a0, $t8
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
j label4
label6:
li $v0, 0
jr $ra
