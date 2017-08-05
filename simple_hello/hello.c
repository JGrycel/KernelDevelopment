/*
 * Test Linux Kernal Module from Derek Molloy
 */

#include <linux/init.h>		// Macros
#include <linux/module.h>	// For loading LKM into kernel
#include <linux/kernel.h>	// Kernel definitions

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jacob Grycel");
MODULE_DESCRIPTION("Test driver for BBB");
MODULE_VERSION("0.1");

static char *name = "jake";	// LKM argument
module_param(name, charp, S_IRUGO); // charp=char ptr, S_IRUGO=readonly
MODULE_PARM_DESC(name, "The name to display in /var/log/kern.log");

/*
 * static = only visible in this src
 * __init = for a built-in driver, Not LKM, 
 * 	    this only runs during initialization
 * 	    and that memory for function is freed after running once
 *			PRETTY COOL!!!!!
 */
static int __init helloBBB_init(void){
	printk(KERN_INFO "Hi %s, this LKM works\n", name);
	// Level is KERN_INFO (not critical)
	return 0;
}

/*
 *  __exit = only runs once on exit if built-in driver, not LKM
 */
static void __exit helloBBB_exit(void){
	printk(KERN_INFO "Exiting program, %s\n", name);
}

/*
 * LKM must call initialization and end functions
 */
module_init(helloBBB_init);
module_exit(helloBBB_exit);
