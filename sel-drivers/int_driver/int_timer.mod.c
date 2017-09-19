#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x14522340, "module_layout" },
	{ 0x42e80c19, "cdev_del" },
	{ 0xc45a9f63, "cdev_init" },
	{ 0xd691cba2, "malloc_sizes" },
	{ 0x7edc1537, "device_destroy" },
	{ 0x6a9f26c9, "init_timer_key" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0x7d11c268, "jiffies" },
	{ 0xe83fea1, "del_timer_sync" },
	{ 0xea147363, "printk" },
	{ 0x85f8a266, "copy_to_user" },
	{ 0xb4390f9a, "mcount" },
	{ 0x2d2cf7d, "device_create" },
	{ 0x45450063, "mod_timer" },
	{ 0x46085e4f, "add_timer" },
	{ 0xa6d1bdca, "cdev_add" },
	{ 0x2044fa9e, "kmem_cache_alloc_trace" },
	{ 0x37a0cba, "kfree" },
	{ 0xe06bb002, "class_destroy" },
	{ 0xef98c923, "device_unregister" },
	{ 0xa2654165, "__class_create" },
	{ 0x29537c9e, "alloc_chrdev_region" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "6FBB6E531356979B6FB1562");

static const struct rheldata _rheldata __used
__attribute__((section(".rheldata"))) = {
	.rhel_major = 6,
	.rhel_minor = 8,
	.rhel_release = 641,
};
