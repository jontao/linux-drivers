/*************************************************************************
	> File Name: test.c
	> Author: jonta
	> Mail: jonta@foxmail.com 
	> Created Time: Thu 27 Apr 2017 06:36:30 PM CST
 ************************************************************************/

#include <linux/miscdevice.h>
#include <linux/delay.h>
#include <asm/irq.h>
//#include <mach/regs-gpio.h>
//#include <mach/hardware.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <linux/ioctl.h>
#include <linux/cdev.h>
#include <linux/string.h>
#include <linux/list.h>
#include <linux/pci.h>
#include <asm/uaccess.h>
#include <asm/atomic.h>
#include <asm/unistd.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/uaccess.h>
#define TIMER_MAJOR 0
#define TIMER_MINOR 0
dev_t timer_dev_t;//设备号
dev_t timer_dev_major=TIMER_MAJOR;
dev_t timer_dev_minor=TIMER_MINOR;
static struct class  *timer_drv_class;   //自动注册驱动主设备  
static struct device *timer_drv_dev;  
struct TIMER_DEV
{
  struct cdev cdev;
  atomic_t count;
  struct timer_list timer_list;

};
struct TIMER_DEV* timer_dev;

static void evaluation_function()
{
	mdelay(100);
}

//---------timer interrupt function----------------
static void timer_function(unsigned long data)
{
	unsigned long jif_buf=0;
	mod_timer(&(timer_dev->timer_list),jiffies+HZ);//reset time
	printk("current jiffies(系统当前中断次数)= %1d,\
\ 程序执行次数=%d\n",jif_buf=jiffies,timer_dev->count);
	printk("程序运行中...\n");
	evaluation_function();
	printk("current jiffies(系统当前中断次数)= %1d,\
\ 程序执行次数=%d\n",jiffies,timer_dev->count);
	printk("程序运行耗时: %dms\n\n",jiffies-jif_buf);
	atomic_inc(&(timer_dev->count));
}
//--------timer release function--------------------
static int timer_release(struct inode* inode, struct file* filp)
{
	del_timer_sync(&(timer_dev->timer_list));
	return 0;
}

//----------------file open function-----------------
static int timer_open(struct inode* inode,struct file* filp)
{
	init_timer(&(timer_dev->timer_list));//初始化定时器
	timer_dev->timer_list.function=timer_function;//设置定时器处理函数
	timer_dev->timer_list.expires=jiffies+30*HZ;//处理函数30s后运行
	add_timer(&timer_dev->timer_list);//添加定时器
	atomic_set(&(timer_dev->count),0);
	return 0;
}
//--------------------------------------

//----------------timer_read function---------------
static int timer_read(struct file* filp,char __user *buf,size_t count,loff_t* f_pos)
{

 unsigned int counter=atomic_read(&(timer_dev->count));
if(copy_to_user(buf,(unsigned int*)&counter,sizeof(unsigned int)))
  {
   printk("copy to user error\n");
   goto out;
  }
return (sizeof(unsigned int));
out:
return (-EFAULT);

}

static int timer_ioctl(struct file* filp, unsigned int cmd, unsigned long args)
{
	void __user *app_arg = (void __user *)args;	
	printk("ioctl ok\n");
	return 0;
}

struct file_operations timer_ops={
.owner=THIS_MODULE,
.open=timer_open,
.read=timer_read,
.release=timer_release,
.unlocked_ioctl = timer_ioctl,
};
static int __init timer_init(void)
{
 int ret;
 
 if(TIMER_MAJOR)//主设备号大于0，静态申请设备号
	{
	timer_dev_t=MKDEV(TIMER_MAJOR,TIMER_MINOR);
	ret=register_chrdev_region(TIMER_MAJOR,1,"timer_d");//first,count,name
	timer_drv_class = class_create(THIS_MODULE, "timer_d");
	timer_drv_dev = device_create(timer_drv_class, NULL, MKDEV(ret, 0), NULL, "timer_d");
	printk("register successed \n");
	}
 else
	{
	ret=alloc_chrdev_region(&timer_dev_t,0,1,"time_dev");
	timer_dev_major=MAJOR(timer_dev_t);
	timer_drv_class = class_create(THIS_MODULE, "timer_dev");
	timer_drv_dev = device_create(timer_drv_class, NULL, MKDEV(timer_dev_major, 0), NULL, "timer_dev");
	}
	if(ret<0)
	{
	printk("can't get major %d\n",timer_dev_major);
	return ret;
	}

	timer_dev=kmalloc(sizeof(struct TIMER_DEV),GFP_KERNEL);
	memset(timer_dev,0,sizeof(struct TIMER_DEV));
	cdev_init(&(timer_dev->cdev),&timer_ops);
	cdev_add(&(timer_dev->cdev),timer_dev_t,1);
	printk("init timer_dev success\n");
	return 0;


}
static void __exit timer_exit(void)
{
	kfree(timer_dev);
	cdev_del(&(timer_dev->cdev));
	unregister_chrdev_region(MKDEV(timer_dev_major,0),1);
	device_unregister(timer_drv_dev);
	device_destroy(timer_drv_class,MKDEV(timer_dev_major,0));
	class_destroy(timer_drv_class);
}
module_init(timer_init);
module_exit(timer_exit);
MODULE_LICENSE("GPL");
