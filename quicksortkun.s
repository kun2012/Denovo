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
label1:
label2:
label3:
label4:
label5:
label6:
Quicksortkunquicksort1:
label7:
label8:
label9:
label10:
label12:
label13:
label14:
label15:
label16:
label17:
label18:
label19:
label11:
