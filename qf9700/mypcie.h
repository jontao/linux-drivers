#ifndef __MYPCIE_H__
#define __MYPCIE_H__


/* Definitions for interface M0_AXI_LITE */
#define XPAR_M0_AXI_LITE_BASEADDR 0x43C00000
#define XPAR_M0_AXI_LITE_HIGHADDR 0x43C0FFFF


/* Definitions for interface M1_AXI_LITE */
#define XPAR_M1_AXI_LITE_BASEADDR 0x43C10000
#define XPAR_M1_AXI_LITE_HIGHADDR 0x43C1FFFF


/* Definitions for interface M2_AXI_LITE */
#define XPAR_M2_AXI_LITE_BASEADDR 0x43C20000
#define XPAR_M2_AXI_LITE_HIGHADDR 0x43C2FFFF


/* Definitions for interface M3_AXI_LITE */
#define XPAR_M3_AXI_LITE_BASEADDR 0x43C30000
#define XPAR_M3_AXI_LITE_HIGHADDR 0x43C3FFFF

/* Definitions for interface M5_AXI_LITE */
#define XPAR_M4_AXI_LITE_BASEADDR 0x43C40000
#define XPAR_M4_AXI_LITE_HIGHADDR 0x43C4FFFF

/* Definitions for interface M5_AXI_LITE */
#define XPAR_M5_AXI_LITE_BASEADDR 0x43C50000
#define XPAR_M5_AXI_LITE_HIGHADDR 0x43C5FFFF

/* Definitions for interface M5_AXI_LITE */
#define XPAR_M6_AXI_LITE_BASEADDR 0x43C60000
#define XPAR_M6_AXI_LITE_HIGHADDR 0x43C6FFFF

/* Definitions for interface M5_AXI_LITE */
#define XPAR_M7_AXI_LITE_BASEADDR 0x43C70000
#define XPAR_M7_AXI_LITE_HIGHADDR 0x43C7FFFF

/* Definitions for Fabric interrupts connected to ps7_scugic_0 */
#define XPAR_FABRIC_SYSTEM_EXT_INT0_INTR 61
#define XPAR_FABRIC_SYSTEM_EXT_INT1_INTR 62
#define XPAR_FABRIC_SYSTEM_EXT_INT2_INTR 63
#define XPAR_FABRIC_SYSTEM_EXT_INT3_INTR 64
#define XPAR_FABRIC_SYSTEM_EXT_INT4_INTR 65
#define XPAR_FABRIC_SYSTEM_EXT_INT5_INTR 66
#define XPAR_FABRIC_SYSTEM_EXT_INT6_INTR 67
#define XPAR_FABRIC_SYSTEM_EXT_INT7_INTR 68
#define XPAR_FABRIC_SYSTEM_EXT_INT8_INTR 69
#define XPAR_FABRIC_SYSTEM_EXT_INT9_INTR 70
#define XPAR_FABRIC_SYSTEM_EXT_INT10_INTR 71
#define XPAR_FABRIC_SYSTEM_EXT_INT11_INTR 72
#define XPAR_FABRIC_SYSTEM_EXT_INT12_INTR 73
#define XPAR_FABRIC_SYSTEM_EXT_INT13_INTR 74
#define XPAR_FABRIC_SYSTEM_EXT_INT14_INTR 75
#define XPAR_FABRIC_SYSTEM_EXT_INT15_INTR 76


/*Definitions  macro  for offset*/
#define M5_BUFFER_ADDR        0x20000000
#define OFFSET                0x10000
#define INT_ADDR              0X0
#define STAT_ADDR             0X04
#define SRC_ADDR              0X18
#define DST_ADDR              0X20
#define SIZE_ADDR             0X28
#define SRC_BDY               0X30
#define DST_BDY               0X34
#define DEC_ADDR              0x18
#define BAND_ADDR			  0x1c
#define SECOND_ADDR           0X0
#define MINUTE_ADDR           0X4
#define HOUR_ADDR             0X8
#define MODE_ADDR             0X10
#define RST_ADDR              0X14


/*
	m0 is adc write channel   写数据zynq到fpga
	m1 is adc read channel    CDMA enhance,读数据,fpga到zynq
	m2 share memory read channel 读数据,fpga到zynq
	m3 is system config ,配置模式和时间

	m5 is adc read channel
	m7 is adc read channel
*/

struct mem_config{
	unsigned int enumtype;
	unsigned int second;
	unsigned int minutes;
	unsigned int hour;
	unsigned int mode;
	unsigned int flag68;
	unsigned int flag61;
	unsigned int flag62;
	unsigned int flag63;
	unsigned int flag64;
	unsigned int flag67;
	unsigned int channel;//通道
	unsigned int band; //带宽
	unsigned int dec;//抽取率
	unsigned long reg_addr;
	unsigned int reg_value;
	char *buff;/*读写buff*/
	unsigned long buff_len;/*buff长度*/
	unsigned int fpga_staraddr;
	unsigned int fpga_endaddr;/*边界地址*/
};

#define MYPCIE_IOCTL_MAGIC		'x'		//定义幻数
#define MYPCIE_IOCTL_MAX_NR		15		//定义命令的最大值
#define CONFIG_TIME  _IOWR(MYPCIE_IOCTL_MAGIC, 1, struct mem_config)
#define CONFIG_MODE  _IOWR(MYPCIE_IOCTL_MAGIC, 2, struct mem_config)
#define READ_TIME  _IOWR(MYPCIE_IOCTL_MAGIC, 3, struct mem_config)
#define READ_MODE  _IOWR(MYPCIE_IOCTL_MAGIC, 4, struct mem_config)
#define CONFIG_RESET  _IOWR(MYPCIE_IOCTL_MAGIC, 5, struct mem_config)
#define WRITE_DATA_M0  _IOWR(MYPCIE_IOCTL_MAGIC, 6, struct mem_config)
#define READ_DATA_ENHANCE_M1  _IOWR(MYPCIE_IOCTL_MAGIC, 7, struct mem_config)
#define READ_DATA_M2  _IOWR(MYPCIE_IOCTL_MAGIC, 8, struct mem_config)
#define SWITCH_BAND  _IOWR(MYPCIE_IOCTL_MAGIC, 9, struct mem_config)
#define CONFIG_DEC  _IOWR(MYPCIE_IOCTL_MAGIC, 10, struct mem_config)
#define WRITE_REG  _IOWR(MYPCIE_IOCTL_MAGIC, 11, struct mem_config)
#define READ_REG  _IOWR(MYPCIE_IOCTL_MAGIC, 12, struct mem_config)
#define WRITE_IRQ  _IOWR(MYPCIE_IOCTL_MAGIC, 13, struct mem_config)
#define READ_IRQ  _IOWR(MYPCIE_IOCTL_MAGIC, 14, struct mem_config)
#define READ_DATA_M1  _IOWR(MYPCIE_IOCTL_MAGIC, 15, struct mem_config)
#endif

