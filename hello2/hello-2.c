#include <linux/module.h> // 모든 모듈에 필요
#include <linux/kernel.h> // KERN_INFO에 필요
#include <linux/init.h> // 매크로에 필요

MODULE_LICENSE("GPL");

static int __init hello_2_init(void){
    printk(KERN_INFO "Hello, world 2\n");
    return 0;
}

static void __exit hello_2_exit(void)
{
    printk(KERN_INFO "Good Bye World 2\n");
}

module_init(hello_2_init);
module_exit(hello_2_exit);