#pragma once
#ifndef IOPORTS_H
#define IOPORTS_H

#include <Neo.h>

// 8237 / DMA 0-3

#define DMA_0_START_ADDR	0x0000	// W
#define DMA_0_COUNT			0x0001	// W
#define DMA_1_START_ADDR	0x0002	// W
#define DMA_1_COUNT			0x0003	// W
#define DMA_2_START_ADDR	0x0004	// W
#define DMA_2_COUNT			0x0005	// W
#define DMA_3_START_ADDR	0x0006	// W
#define DMA_3_COUNT			0x0007	// W
#define DMA_1_STATUS		0x0008	// R
#define DMA_1_COMMAND		0x0008	//W
#define DMA_1_REQUEST		0x0009	// W
#define DMA_1_CHANNEL_MASK	0x000A	//RW
#define DMA_1_MODE			0x000B	// W
#define DMA_1_CLR_FLIPFLOP	0x000C	// W
#define DMA_1_INTERMEDIATE	0x000D	//R
#define DMA_1_MASTER_RESET	0x000D	// W
#define DMA_1_MASK_RESET	0x000E	// W
#define DMA_1_MULTI_MASK	0x000F	//RW

//PS/2 extended registers

#define PS2_E_FUNCTION		0x0018	// W
#define PS2_E_EXECUTE		0x001A	// W

// 8259 / PIC 1

#define PIC_MASTER_ICW1		0x0020	// W
#define PIC_MASTER_ICW2		0x0021 	// W
#define PIC_MASTER_ICW3		0x0021 	// W
#define PIC_MASTER_ICW4		0x0021 	// W
#define PIC_MASTER_INTR_MASK	0x0021	//RW
#define PIC_MASTER_OCW1		0x0020	//R 
#define PIC_MASTER_OCW2		0x0020	// W
#define PIC_MASTER_OCW3		0x0020	// W

// Chipset data

#define CHIPSET_INDEX		0x0022	// W
#define CHIPSET_DATA		0x0023	//RW

// Power management

#define PWR_MGMT_INDEX		0x0026	//W
#define PWR_MGMT_DATA		0x0027	//RW

// 8253/8254 / PIT

#define PIT_COUNTER_0		0x0040	//RW
#define PIT_COUNTER_1		0x0041	//RW
#define PIT_COUNTER_2		0x0042	//RW
#define PIT_CONTROL			0x0043	//RW
#define PIT_COUNTER_3		0x0044	//RW
#define PIT_CONTROL_3

// 8041/8042 / KBC

#define KEYB_COMMAND		0x0060	//RW
#define KBC_DATA			0x0060	//RW
#define KBC_COMMAND			0x0064	// W
#define	KBC_STATUS			0x0064	//R 

// ...

#define A20_GATE			0x0065	//RW

// CMOS

#define CMOS_RAM_INDEX		0x0070	// W
#define CMOS_DATA			0x0071	//RW	

//DMA Upper bytes

#define DMA_CH2_PAGE_ADDR	0x0081 	// W
#define DMA_CH3_PAGE_ADDR	0x0082 	// W
#define DMA_CH1_PAGE_ADDR	0x0083 	// W
#define DMA_CH0_PAGE_ADDR	0x0087 	// W
#define DMA_CH6_PAGE_ADDR	0x0089 	// W
#define DMA_CH7_PAGE_ADDR	0x008A 	// W
#define DMA_CH5_PAGE_ADDR	0x008B 	// W
#define DMA_CH4_PAGE_ADDR	0x008F 	// W

// 8259 / PIC 2

#define PIC_SLAVE_ICW1			0x00A0	// W
#define PIC_SLAVE_ICW2			0x00A1 	// W
#define PIC_SLAVE_ICW3			0x00A1 	// W
#define PIC_SLAVE_ICW4			0x00A1 	// W
#define PIC_SLAVE_INTR_MASK		0x00A1	//RW
#define PIC_SLAVE_OCW1			0x00A0	//R 
#define PIC_SLAVE_OCW2			0x00A0	// W
#define PIC_SLAVE_OCW3			0x00A0	// W

// 8237 / DMA 4-7

#define DMA_4_START_ADDR	0x00C0	// W
#define DMA_4_COUNT			0x00C2	// W
#define DMA_5_START_ADDR	0x00C4	// W
#define DMA_5_COUNT			0x00C6	// W
#define DMA_6_START_ADDR	0x00C8	// W
#define DMA_6_COUNT			0x00CA	// W
#define DMA_7_START_ADDR	0x00CC	// W
#define DMA_7_COUNT			0x00CE	// W
#define DMA_2_STATUS		0x0008	// R
#define DMA_2_COMMAND		0x0008	//W
#define DMA_2_REQUEST		0x0009	// W
#define DMA_2_CHANNEL_MASK	0x000A	//RW
#define DMA_2_MODE			0x000B	// W
#define DMA_2_CLR_FLIPFLOP	0x000C	// W
#define DMA_2_INTERMEDIATE	0x000D	//R
#define DMA_2_MASTER_RESET	0x000D	// W
#define DMA_2_MASK_RESET	0x000E	// W
#define DMA_2_MULTI_MASK	0x000F	//RW

#endif
