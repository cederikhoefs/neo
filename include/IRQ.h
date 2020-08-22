#pragma once
#ifndef IRQ_H
#define IRQ_H

#define IRQ(n) (1 << n)

#define IRQ_PIT   		IRQ(0)
#define IRQ_PS2_1 		IRQ(1)
#define IRQ_PIC_SLAVE	IRQ(2)
#define IRQ_RS232_2_4	IRQ(3)
#define IRQ_RS232_1_3	IRQ(4)
#define IRQ_LPT_2		IRQ(5)
#define IRQ_FLOPPY		IRQ(6)
#define IRQ_LPT1		IRQ(7)
#define IRQ_SPURIOUS_1	IRQ(7)
#define IRQ_RTC			IRQ(8)

#define IRQ_ATA_4		IRQ(10)
#define IRQ_ATA_3		IRQ(11)
#define IRQ_PS2_2		IRQ(12)
#define IRQ_FPU			IRQ(13)
#define IRQ_ATA_1		IRQ(14)
#define IRQ_ATA_2		IRQ(15)
#define IRQ_SPURIOUS_2	IRQ(15)

#endif
