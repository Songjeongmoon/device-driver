#include <linux/module.h> // 모든 모듈에 필요
#include <linux/kernel.h> // KERN_INFO에 필요
#include <linux/init.h> // 매크로에 필요

MODULE_LICENSE("GPL");
static int hello3_data __initdata = 12345; 

static int __init hello_3_init(void) 
{ 
	printk(KERN_INFO "Hello world 3\n %d\n", hello3_data); 
	return 0;
} 

static void __exit hello_3_exit(void) 
{ 
	printk(KERN_INFO "Good Bye World 3\n"); 
} 

module_init(hello_3_init); 
module_exit(hello_3_exit);