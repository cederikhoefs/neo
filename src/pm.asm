global switchPM

switchPM:
    mov eax, cr0 
    or al, 1     ; setze PE (Protection Enable) bit in CR0 (Control Register 0)
    mov cr0, eax
    ret
