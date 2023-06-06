#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Song Jeongmoon");

static short int myshort = 1;
static int myint = 420;
static long int mylong = 9999;
static char *mystring = "ABCD";
static int myintArray[2] = { -1, -1 };
static int arr_argc = 0;

/* 
 - module_param(foo, int, 0000) 
 - 첫 번째 매개변수는 매개변수 이름입니다. 
 - 두 번째 매개변수는 데이터 유형입니다.
 - 마지막 인수 는 나중에 sysfs(0이 아닌 경우)의 매개변수를 노출하기 위한 권한 비트입니다. 
 */

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "A integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long integer");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");

/* 
 - module_param_array(name, type, num, perm); 
 - 첫 번째 매개변수는 매개변수(이 경우 배열)의 이름입니다.
 - 두 번째 매개변수는 배열 요소의 데이터 유형입니다.
 - 세 번째 인수는 모듈 로드 시 사용자가 초기화한 배열 요소의 수를 저장할 변수에 대한 포인터입니다. 
 - 네 번째 인수는 권한입니다. 비트
 */ 
module_param_array(myintArray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintArray, "An array of integers");

static int __init hello_5_init(void)
{
	int i;
	printk(KERN_INFO "Hello, world 5\n=============\n");
	printk(KERN_INFO "myshort is a short integer: %hd\n", myshort);
	printk(KERN_INFO "myint is an integer: %d\n", myint);
	printk(KERN_INFO "mylong is a long integer: %ld\n", mylong);
	printk(KERN_INFO "mystring is a string: %s\n", mystring);
	for (i = 0; i < (sizeof myintArray / sizeof (int)); i++)
	{
		printk(KERN_INFO "myintArray[%d] = %d\n", i, myintArray[i]);
	}
	printk(KERN_INFO "got %d arguments for myintArray.\n", arr_argc);
    printk("=============\n");
	return 0;
}

static void __exit hello_5_exit(void)
{
	printk(KERN_INFO "Goodbye, world 5\n");
}

module_init(hello_5_init);
module_exit(hello_5_exit);