/**
 * printk(KERN_INFO "Message: %s\n", arg);
 * where KERN_INFO is the log level (note that it’s concatenated to the format string, 
 * the log level is not a separate argument). The available log levels are:
 *  Name            String      Alias function
 *  KERN_EMERG      “0”         pr_emerg()
 *  KERN_ALERT      “1”         pr_alert()
 *  KERN_CRIT       “2”         pr_crit()
 *  KERN_ERR        “3”         pr_err()
 *  KERN_WARNING    “4”         pr_warn()
 *  KERN_NOTICE     “5”         pr_notice()
 *  KERN_INFO       “6”         pr_info()
 *  KERN_DEBUG      “7”         pr_debug() and pr_devel() if DEBUG is defined
 *  KERN_DEFAULT    “”
 *  KERN_CONT       “c”         pr_cont()
 * source:https://docs.kernel.org/core-api/printk-basics.html
 * 
 * 
 */





#include<linux/module.h>
#include<linux/init.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Log level to chec kernel module");
static const char *module_name = "log_levels";

static int __init my_init(void){
    printk(KERN_INFO "%s: hello Kenel\n",module_name);
    printk(KERN_ALERT "%s: This is an alert\n",module_name);
    printk(KERN_WARNING "%s: This is a warning\n",module_name);
    printk(KERN_NOTICE "%s: This is a notice\n",module_name);
    printk(KERN_ERR "%s: This is an error\n",module_name);
    printk(KERN_EMERG "%s: This is an emergency\n",module_name);
    printk(KERN_DEBUG "%s: This is a debug\n",module_name);
    return 0;
}

static void __exit my_exit(void){
    pr_info("%s: Good Bye Kenel\n",module_name);
    pr_alert("%s: This is an alert on exit\n",module_name);
    pr_warn("%s: This is a warning on exit\n",module_name);
    pr_notice("%s: This is a notice on exit\n",module_name);
    pr_err("%s: This is an error on exit\n",module_name);
    pr_emerg("%s: This is an emergency on exit\n",module_name);
    pr_debug("%s: This is a debug on exit\n",module_name);
}

module_init(my_init);
module_exit(my_exit);
