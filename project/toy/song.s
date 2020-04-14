	.arch msp430g2553
	.p2align 1,0

	.data
state:
	.word 1
	
	.text
jt:
	.word default		
	.word case1		
	.word case2
	.word case3
	.word case4
	.word case5
	.word case6
	.word case7
	.word case8
	.word case9
	.word case10
	.word case11
	.word case12
	.word case13
	.word case14
	
	
	.global song
song:
	cmp #15, &state
	jhs default
	
	mov &state, r12
	add r12, r12
	mov jt(12), r0

case1:	mov #2093, r12
	call #buzzer_set_period
	add #1, state
	jmp default
	
case2:	mov #2093, r12
	call #buzzer_set_period
	add #1, state
	jmp default

case3:	mov #1396, r12
	call #buzzer_set_period
	add #1, state
	jmp default

case4:	mov #1396, r12
	call #buzzer_set_period
	add #1, state
	jmp default

case5:	mov #1318, r12
	call #buzzer_set_period
	add #1, state
	jmp default

case6:	mov #1318, r12
	call #buzzer_set_period
	add #1, state
	jmp default

case7:	mov #1396, r12
	call #buzzer_set_period
	add #1, state
	jmp default

case8:	mov #1567, r12
	call #buzzer_set_period 
	add #1, state
	jmp default

case9:	mov #1576, r12
	call #buzzer_set_period 
	add #1, state
	jmp default

case10:	mov #1760, r12
	call #buzzer_set_period  
	add #1, state
	jmp default

case11:	mov #1760, r12
	call #buzzer_set_period 
	add #1, state
	jmp default

case12:	mov #1975, r12
	call #buzzer_set_period 
	add #1, state
	jmp default

case13:	mov #1975, r12
	call #buzzer_set_period
	add #1, state
	jmp default

case14:	mov #2093, r12
	call #buzzer_set_period
	add #1, state
	jmp default

default:
	pop r0
