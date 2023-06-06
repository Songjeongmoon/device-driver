#include <linux/module.h> // 모든 모듈에 필요
#include <linux/kernel.h> // KERN_INFO에 필요 


MODULE_LICENSE("GPL");

int init_module(void){
	printk("Hello world 1.\n");
	return 0;
	// 0이 아닌 반환은 init_module이 실패했음을 의미합니다. 모듈을 로드할 수 없습니다.
}

void cleanup_module(void){
	printk("Good bye world 1.\n");
}