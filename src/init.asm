global init

extern S1
;extern initialiseConstructors
extern _init
extern _fini
extern initialiseGDT
extern switchPM
extern initialiseIDT
extern initialiseSyscalls
extern initialiseExceptionHandlers
extern initialisePIC

FLAGS    equ 0
MAGIC    equ 0x1BADB002					; Magicnumber - Erkennungsmerkmal für GRUB
CHECKSUM equ -(MAGIC + FLAGS)			; Checksum

section multiboot
align 4

MultiBootHeader:

	dd MAGIC       				; Magic number
	dd FLAGS       				; Flags
	dd CHECKSUM    				; Checksum


section .text

init:

	mov  esp, 0x800000; 		
	push eax;         					; Multiboot-Magicnumber auf den Stack legen
 	push ebx;   

 	call _init;
	;call initialiseConstructors;
	call initialiseGDT;
	call switchPM;
	call initialiseIDT;

	call initialiseExceptionHandlers;
	call initialiseSyscalls;
	call initialisePIC;
 	call S1;

 	call _fini;
  
		       
stop:
jmp stop;	

