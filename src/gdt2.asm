global updateSegments;

updateSegments:        ;Reload segment registers for GDT load

    mov ax, 0x10;
    mov es, ax;
    mov ds, ax;
    mov fs ,ax;
    mov gs, ax;
    mov ss, ax;
    mov esp, ebp;
    pop ebp;
    jmp 0x08:flush2;
flush2:
    ret;

