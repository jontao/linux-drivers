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
	{ 0x7eaf4053, "mii_ethtool_gset" },
	{ 0x5a34a45c, "__kmalloc" },
	{ 0x6a86e74c, "usbnet_resume" },
	{ 0x50978781, "usbnet_probe" },
	{ 0xf9e7dbc3, "usbnet_set_settings" },
	{ 0xd691cba2, "malloc_sizes" },
	{ 0x865e3dca, "netif_carrier_on" },
	{ 0x2264f7eb, "usbnet_disconnect" },
	{ 0xa667f32d, "generic_mii_ioctl" },
	{ 0xc39299b6, "usbnet_defer_kevent" },
	{ 0xf77cb70a, "netif_carrier_off" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x458cebe7, "usbnet_stop" },
	{ 0x3758301, "mutex_unlock" },
	{ 0xc01e3b23, "skb_trim" },
	{ 0xb71812b3, "usbnet_nway_reset" },
	{ 0x39bd22f9, "mii_nway_restart" },
	{ 0x8502d858, "dev_err" },
	{ 0xced66309, "usb_deregister" },
	{ 0xea147363, "printk" },
	{ 0xb530deb6, "usbnet_get_endpoints" },
	{ 0xb4390f9a, "mcount" },
	{ 0x3461b433, "usb_control_msg" },
	{ 0x69b00458, "usbnet_get_drvinfo" },
	{ 0xfee8a795, "mutex_lock" },
	{ 0x92ea4ae4, "crc32_le" },
	{ 0x62bb6ad, "usbnet_start_xmit" },
	{ 0x5da96b4b, "usbnet_suspend" },
	{ 0xd3c80841, "skb_pull" },
	{ 0x1615b190, "dev_kfree_skb_any" },
	{ 0xf35db3d1, "usbnet_get_settings" },
	{ 0xefe28451, "skb_copy_expand" },
	{ 0xc45dd153, "usb_submit_urb" },
	{ 0xe84dff8, "usbnet_tx_timeout" },
	{ 0x811465e6, "usbnet_open" },
	{ 0x624fcc4b, "mii_check_media" },
	{ 0xf6e1986f, "usbnet_get_msglevel" },
	{ 0x2044fa9e, "kmem_cache_alloc_trace" },
	{ 0xfaf98462, "bitrev32" },
	{ 0xeacec774, "eth_validate_addr" },
	{ 0x37a0cba, "kfree" },
	{ 0x236c8c64, "memcpy" },
	{ 0xf03e3d34, "usbnet_change_mtu" },
	{ 0x251ce55e, "usb_register_driver" },
	{ 0xa4526992, "mii_link_ok" },
	{ 0xe99d2a98, "eth_mac_addr" },
	{ 0x6d221ba3, "usb_free_urb" },
	{ 0x2005eef2, "usbnet_set_msglevel" },
	{ 0xf8cfbf13, "usb_alloc_urb" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=mii,usbnet";

MODULE_ALIAS("usb:v0FE6p9700d*dc*dsc*dp*ic*isc*ip*");

MODULE_INFO(srcversion, "86FE0FE4751CAE880CE9E54");

static const struct rheldata _rheldata __used
__attribute__((section(".rheldata"))) = {
	.rhel_major = 6,
	.rhel_minor = 8,
	.rhel_release = 641,
};
