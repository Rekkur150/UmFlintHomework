prtStr macro string
	lea dx, string	;calculate the address of string
	mov ah, 9		;9 = print string
	int 21h
endm

prtChar macro string
	mov dl, string
	add dl, "0"
	mov ah, 2
	int 21h
endm

prtChars macro x
	;See if its less than
	mov bl, 10
	mov al, x
	cmp al, bl		;j must come directly after
	jl prtOnes		;jl jump is less than, jle jump if less than or equal, je jump if equal

	;Turn the product into the correct ascii characters
	mov ax, 0 ;Clear out ax
	mov al,x ;Move to Al because mul multiples al by whatever
	mov dl, 10 ;Div 10
	div dl ;Divides al by dl, the quotent is stored in al, the remainder is in dl
	mov bl, al
	prtChar al
	mov ax, 0
	mov al, bl
	mov dl, 10
	mul dl	;Multiples the tenDigit by the quotent
	mov dl, x
	sub dl, al ;subtracts all the 10's place from the product, to give single digits
	mov al, dl

	prtOnes:
		prtChar al
endm

readChar macro x
	mov ah,1
	int 21h
	sub al, '0'
	mov x, al
endm

readChars macro x
	readChar bl
	mov ax, 0
	mov al, bl
	mov dl, 10
	mul dl
	mov bl, al

	readChar x
	mov dl, x
	add dl, bl
	mov x, dl
endm

scrClear macro
	mov ax,2
	int 10h
endm

scrColor macro color
	mov ah, 6		;Scroll up screen
	mov al, 0		;Entire screen
	mov cx, 0		;top left corner of the screen
	mov dx, 184fh	;screen dize DH(24) and DL(79) set 80x@5 screen
	mov bh, color;
	int 10h			;Bois Interrupt
endm

return macro
	mov ah, 4ch
	int 21h
endm
