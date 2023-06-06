#include <linux/module.h> // 모든 모듈에 필요
#include <linux/kernel.h> // KERN_INFO에 필요
#include <linux/init.h> // 매크로에 필요

#define DRIVER_AUTHOR "Song Jeongmoon"
#define DRIVER_DESC "practice, hello-4"

MODULE_LICENSE("GPL"); 

static int __init init_hello_4(void){
	printk(KERN_INFO "Hello, world 4\n"); 
	return 0;
}

static void __exit cleanup_hello_4(void){
	printk(KERN_INFO "Good Bye World 4\n"); 
}

module_init(init_hello_4);
module_exit(cleanup_hello_4);

// 또는 다음과 같이 정의합니다.
MODULE_AUTHOR(DRIVER_AUTHOR); //누가 이 모듈을 작성했습니까?
MODULE_DESCRIPTION(DRIVER_DESC); //이 모듈이 하는 일