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

Factfact:
addi $sp, $sp, -4
move $t0, $a0
addi $sp, $sp, -4
move $t1, $a1
addi $sp, $sp, -4
sw $ra, 0($sp)
move $a0, $t0
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
li $s7, 1
beq $t0, $s7, label1
j label2
label1:
addi $sp, $fp, -4
move $v0, $t0
jr $ra
j label3
label2:
addi $sp, $sp, -4
addi $t2, $t0, -1
move $a0, $t2
move $a1, $t1
addi $sp, $sp, -4
sw $fp, 0($sp)
move $fp, $sp
addi $sp, $sp, -4
sw $ra, 0($sp)
jal Factfact
lw $ra, 0($sp)
addi $sp, $sp, 4
lw $fp, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
move $t3, $v0
addi $sp, $sp, -4
mul $t4, $t0, $t3
addi $sp, $fp, -4
move $v0, $t4
jr $ra
label3:
main:
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
move $t5, $v0
li $s7, 1
bgt $t5, $s7, label4
j label5
label4:
move $a0, $t5
addi $sp, $sp, -4
move $a1, $t6
addi $sp, $sp, -4
sw $fp, 0($sp)
move $fp, $sp
addi $sp, $sp, -4
sw $ra, 0($sp)
jal Factfact
lw $ra, 0($sp)
addi $sp, $sp, 4
lw $fp, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
move $t7, $v0
j label6
label5:
li $t7, 1
label6:
addi $sp, $sp, -4
sw $ra, 0($sp)
move $a0, $t7
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
li $v0, 0
jr $ra
